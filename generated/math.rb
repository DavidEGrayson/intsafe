def add_function_name(type)
  "#{type.camel_name}Add__"
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

def write_add_function(type)

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
    write_add_function(type)
    # TODO: write_sub_function(type)
    # TODO: write_mult_function(type)
  end
end
