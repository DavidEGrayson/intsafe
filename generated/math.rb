def add_function_name(type)
  "#{type.camel_name}Add"
end

def sub_function_name(type)
  "#{type.camel_name}Sub__" # TODO: fix
end

def mult_function_name(type)
  "#{type.camel_name}Mult__"  # TODO: fix
end

def math_function_names(type)
  [add_function_name(type), sub_function_name(type), mult_function_name(type)]
end

def write_add_function(cenv, type)
  func_name = add_function_name(type)
  return if !function_body_needed?(func_name)

  ret = '__MINGW_INTSAFE_API HRESULT'
  args = "_In_ #{type} x, _In_ #{type} y, _Out_ #{type} * result"
  write_function(cenv, func_name, args, ret) do |cenv|
    cenv.puts "*result = 0;"

    if type.signed?
      too_big = "x > 0 && y > #{type.max_str} - x"
      too_small = "x < 0 && y < #{type.min_str} - x"
    else
      too_big = "y > #{type.max_str} - x"
      too_small = nil
    end

    cenv.puts "if (#{too_big}) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    cenv.puts "if (#{too_small}) return INTSAFE_E_ARITHMETIC_OVERFLOW;" if too_small
    cenv.puts "*result = x + y;"
    cenv.puts "return S_OK;"
  end
end

def calculate_math_function_aliases
  aliases = {}
  Types.each do |type|
    et = EquivalentTypes.for_type(type).first
    next if et == type

    api_names = math_function_names(type)
    real_names = math_function_names(et)
    api_names.zip(real_names).each do |api_func_name, real_func_name|
      next if !ApiFunctionNames.include?(api_func_name)
      raise if !ApiFunctionNames.include?(real_func_name)
      aliases[api_func_name] = real_func_name
    end
  end
  aliases
end

def write_math_functions(cenv)
  Types.each do |type|
    write_add_function(cenv, type)
    # TODO: write_sub_function(type)
    # TODO: write_mult_function(type)
  end
end
