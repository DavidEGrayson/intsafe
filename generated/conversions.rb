def conversion_function_name(type1, type2)
  "#{type1.camel_name}To#{type2.camel_name}"
end

def calculate_conversion_function_alias(type1, type2)
  api_func_name = conversion_function_name(type1, type2)
  return [] if !ApiFunctionNames.include?(api_func_name)
  EquivalentTypes.for_type(type1).each do |et1|
    EquivalentTypes.for_type(type2).each do |et2|
      equivalent_func_name = conversion_function_name(et1, et2)
      next if !ApiFunctionNames.include?(equivalent_func_name)

      # equivalent_func_name is the preferred name for the set of
      # functions equivalent to api_func_name.

      if equivalent_func_name == api_func_name
        # The function we are considering already has the best
        # possible name, don't define it as an alias.
        return []
      else
        # The function we are looking at should be defined as an alias.
        return [api_func_name, equivalent_func_name]
      end
    end
  end
  return []
end

def calculate_conversion_function_aliases
  aliases = {}
  types = Types + [SignedCharType]
  types.each do |type1|
    types.each do |type2|
      api_name, real_name = calculate_conversion_function_alias(type1, type2)
      aliases[api_name] = real_name if real_name
    end
  end
  aliases
end

def upper_check_needed(type_src, type_dest)
  case
  when type_dest.more_bytes_than?(type_src)
    # On every system we care about, the destination type has more
    # bytes, so skip the comparison.
    false

  when type_dest.unsigned? && type_dest.as_many_bytes_as?(type_src)
    # We shouldn't need an upper comparison because the destination
    # type is unsigned and guaranteed to have at least as many bytes
    # as the source type.
    false

  when type_src.signed? == type_dest.signed? && type_dest.as_many_bytes_as?(type_src)
    # If the two types have equal signs and the destination is big
    # enough, we can skip the comparison.
    false

  else
    true
  end
end

# Yields zero or more C environments to the caller where we definitely
# need to do an upper bound check because it is possible that a value
# of type type_src is too big to be represented in type_dest.  We
# generate such environments either using ifdefs or our knowledge of
# the possibilities incarnations that each type has.
def cenv_where_upper_check_needed(cenv, type_src, type_dest)
  return if !upper_check_needed(type_src, type_dest)

  case
  when type_src.type_id == -PointerSizeDummy && type_dest.type_id == 4
    # On 64-bit systems, we need to do an upper check because signed
    # pointers can be bigger than unsigned ints.
    #
    # On 32-bit systems we don't need to do the check, and the code
    # for the check would behave incorrectly because it would convert
    # the upper boudn (UINT_MAX) from an unsigned int to a signed int,
    # as described in Section 6.3.1.8 of the C99.
    #
    # Therefore, we need an ifdef to only do the check when needed.
    # Another possibility is a cast, but an #if.
    ifcheck = true

  when type_src.type_id == -8 && type_dest.type_id == PointerSizeDummy
    # On 32-bit systems, an upper check is needed.
    #
    # On 64-bit systems, no upper check is necessary because a signed
    # int64_t can never too large to be represented in a size_t
    # (uint64_t).  Also, the check would produce bad code because
    # of Section 6.3.1.8 of C99.  Therefore, we need an #if.
    ifcheck = true

  when type_src.type_id == 4 && type_dest.type_id == -PointerSizeDummy
    # On 32-bit systems, an upper check is needed.
    #
    # On 64-bit systems, clang whines about having a comparison that
    # is always false.  Therefore we need an #if.
    ifcheck = true

  when type_src.type_id == PointerSizeDummy && type_dest.type_id == -8
    # On 64-bit systems, an upper check is needed.
    #
    # On 32-bit systems, clang whines about having a comparison that
    # is always false.  Therefore we need an #if.
    ifcheck = true
  end

  cenv.puts "#if #{type_src.max_str} > #{type_dest.max_str}" if ifcheck
  yield cenv
  cenv.puts "#endif" if ifcheck
end

def lower_check_needed(type_src, type_dest)
  case
  when type_src.unsigned?
    # The source is unsigned, so it can't be less than 0, so it will
    # never be too small.
    false
  when type_src.signed? && type_dest.signed? && type_dest.as_many_bytes_as?(type_src)
    # It is a signed-to-signed conversion and the destination will
    # always be big enough.
    false
  else
    true
  end
end

# Yields zero or more C environments to the caller where we definitely
# need to do a lower bound check because it is possible that a value
# of type type_src is too big to be represented in type_dest.  We
# generate such environments either using ifdefs or our knowledge of
# the possibilities incarnations that each type has.
def cenv_where_lower_check_needed(cenv, type_src, type_dest)
  return if !lower_check_needed(type_src, type_dest)
  yield cenv
end

def write_conversion_function(cenv, type_src, type_dest)
  func_name = conversion_function_name(type_src, type_dest)
  return if !function_body_needed?(func_name)

  args = "_In_ #{type_src} operand, _Out_ #{type_dest} * result"

  if USE_GCC_BUILTINS
    GeneratedFunctions << func_name
    cenv.puts "__MINGW_INTSAFE_API __MINGW_INTSAFE_CONV(#{func_name}, #{type_src}, #{type_dest})"
    return
  end

  write_function(cenv, func_name, args) do |cenv|
    if upper_check_needed(type_src, type_dest) || lower_check_needed(type_src, type_dest)
      cenv.puts "*result = 0;"
    end
    cenv_where_upper_check_needed(cenv, type_src, type_dest) do |cenv|
      cenv.puts "if (operand > #{type_dest.max_str}) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    end
    cenv_where_lower_check_needed(cenv, type_src, type_dest) do |cenv|
      cenv.puts "if (operand < #{type_dest.min_str}) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    end
    cenv.puts "*result = operand;"
    cenv.puts "return S_OK;"
  end
end

def write_unsigned_char_aliases(cenv)
  char_type = UnsignedCharType
  cenv.puts_comment <<END
If CHAR is unsigned, use different symbol names.
This avoids the risk of linking to the wrong function when different
translation units with different types of chars are linked together.
END
  cenv.puts "#ifdef __CHAR_UNSIGNED__"
  Types.each do |type|
    api_name = conversion_function_name(type, char_type)
    if function_body_needed?(api_name)
      cenv.puts "#define #{api_name} __mingw_intsafe_uchar_#{api_name}"
    end
  end
  cenv.puts "#endif"
  cenv.puts
end

def write_conversion_to_char(cenv, type)
  func_name = "#{type.camel_name}ToChar"
  return if !function_body_needed?(func_name)

  if USE_GCC_BUILTINS
    GeneratedFunctions << func_name
    cenv.puts "__MINGW_INTSAFE_CHAR_API __MINGW_INTSAFE_CONV(#{func_name}, #{type}, CHAR)"
    return
  end

  ret = '__MINGW_INTSAFE_CHAR_API HRESULT'
  args = "_In_ #{type} operand, _Out_ CHAR * result"
  write_function(cenv, func_name, args, ret) do |cenv|
    cenv.puts "*result = 0;"
    cenv.puts "if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    if type.signed?
      cenv.puts "if (operand < CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    end
    cenv.puts "*result = operand;"
    cenv.puts "return S_OK;"
  end
end

# Write functions for converting from one type to another.
def write_conversion_functions(cenv)
  # To make the header shorter, we have a list of "main types" and we
  # only define functions for converting between those main types.
  # All the other functions are preprocessor macros pointing to a
  # conversion function that operates on "main types".

  types = Types + [SignedCharType]

  types.each do |type1|
    types.each do |type2|
      if type1.name == 'CHAR'
        # this function is not needed
      elsif type2.name == 'CHAR'
        write_conversion_to_char(cenv, type1)
      else
        write_conversion_function(cenv, type1, type2)
      end
    end
  end
  cenv.puts if USE_GCC_BUILTINS

end

def visualize_needed_conversions
  print '  '
  Types.each do |type2|
    print '%2d' % type2.type_id
  end
  puts
  Types.each do |type1|
    print '%2d' % type1.type_id
    Types.each do |type2|
      print ' '

      name = conversion_function_name(type1, type2)
      if ApiFunctionNames.include?(name)
        if FunctionAliases.include?(name)
          print 'o'
        else
          print 'X'
        end
      elsif type1 == type2
        print '='
      else
        print '.'
      end
    end
    puts
  end
end

