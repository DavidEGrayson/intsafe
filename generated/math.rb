def add_function_name(type)
  "#{type.camel_name}Add"
end

def sub_function_name(type)
  "#{type.camel_name}Sub"
end

def mult_function_name(type)
  "#{type.camel_name}Mult"
end

def math_function_names(type)
  [add_function_name(type), sub_function_name(type), mult_function_name(type)]
end

def write_add_function(cenv, type)
  func_name = add_function_name(type)
  return if !function_body_needed?(func_name)

  if USE_GCC_BUILTINS
    GeneratedFunctions << func_name
    cenv.puts "__MINGW_INTSAFE_API __MINGW_INTSAFE_MATH(#{func_name}, #{type}, add)"
    return
  end

  args = "_In_ #{type} x, _In_ #{type} y, _Out_ #{type} * result"
  write_function(cenv, func_name, args) do |cenv|
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

def write_sub_function(cenv, type)
  func_name = sub_function_name(type)
  return if !function_body_needed?(func_name)

  if USE_GCC_BUILTINS
    GeneratedFunctions << func_name
    cenv.puts "__MINGW_INTSAFE_API __MINGW_INTSAFE_MATH(#{func_name}, #{type}, sub)"
    return
  end

  args = "_In_ #{type} x, _In_ #{type} y, _Out_ #{type} * result"
  write_function(cenv, func_name, args) do |cenv|
    if USE_GCC_BUILTINS
      write_builtin(cenv, :sub)
    else
      cenv.puts "*result = 0;"
      if type.signed?
        too_big = "x >= 0 && y < x - #{type.max_str}"
        too_small = "x < 0 && y > x - #{type.min_str}"
      else
        too_big = nil
        too_small = "y > x"
      end
      cenv.puts "if (#{too_big}) return INTSAFE_E_ARITHMETIC_OVERFLOW;" if too_big
      cenv.puts "if (#{too_small}) return INTSAFE_E_ARITHMETIC_OVERFLOW;" if too_small
      cenv.puts "*result = x - y;"
    end
    cenv.puts "return S_OK;"
  end
end

def write_mult_function(cenv, type)
  func_name = mult_function_name(type)
  return if !function_body_needed?(func_name)

  if USE_GCC_BUILTINS
    GeneratedFunctions << func_name
    cenv.puts "__MINGW_INTSAFE_API __MINGW_INTSAFE_MATH(#{func_name}, #{type}, mul)"
    return
  end

  args = "_In_ #{type} x, _In_ #{type} y, _Out_ #{type} * result"
  write_function(cenv, func_name, args) do |cenv|
    if USE_GCC_BUILTINS
      write_builtin(cenv, :mul)
    else
      cenv.puts "*result = 0;"
      conds = []
      if type.unsigned?
        # With unsigned types in C, max/y is the biggest number q such that q*y <= max.
        # Therefore, q*y is fine but (q + 1) * y would overflow.
        conds << "y > 0 && x > #{type.max_str} / y"
      else
        # Similar logic applies for the four signed multiplication cases.
        conds << "x > 0 && y > 0 && x > #{type.max_str} / y"
        conds << "x < 0 && y > 0 && x < #{type.min_str} / y"
        conds << "x > 0 && y < 0 && y < #{type.min_str} / x"
        conds << "x < 0 && y < 0 && x < #{type.max_str} / y"
      end

      conds.each do |cond|
        cenv.puts "if (#{cond}) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
      end
      cenv.puts "*result = x * y;"
    end
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
      next if !ApiFunctionNames.include?(real_func_name)
      aliases[api_func_name] = real_func_name
    end
  end
  aliases
end

def write_math_functions(cenv)
  Types.each do |type|
    write_add_function(cenv, type)
  end

  cenv.puts if USE_GCC_BUILTINS

  Types.each do |type|
    write_sub_function(cenv, type)
  end

  cenv.puts if USE_GCC_BUILTINS

  Types.each do |type|
    write_mult_function(cenv, type)
  end

end
