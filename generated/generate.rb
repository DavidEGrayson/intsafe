# The license for this file and all files in this directory is:
LICENSE = <<END
/* This file is free and unencumbered software released into the
 * public domain. */
END

INFO = <<END
/* This file is an implementation of Microsoft's intsafe.h header, which
 * provides inline functions for safe integer conversions and math operations:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693
 *
 * It was mostly auto-generated using a script that can be found at:
 *
 *     https://github.com/DavidEGrayson/intsafe
 */
END

require 'stringio'

Dir.chdir(File.dirname(__FILE__))
ApiFunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)
GeneratedFunctions = []

Indent = '    '

class CEnv
  attr_reader :io
  attr_accessor :indent_level

  def self.write_file(filename)
    File.open(filename, 'w') do |file|
      yield new(file)
    end
  end

  def initialize(io = StringIO.new)
    @io = io
    self.indent_level = 0
  end

  def puts(*args)
    @io.print Indent * indent_level unless args.empty?
    @io.puts *args
  end

  def puts_indent(*args)
    self.indent_level += 1
    puts *args
    self.indent_level -= 1
  end

  def puts_comment(str)
    str.strip.lines.each_with_index do |line, index|
      @io.print Indent * indent_level
      @io.print '/* ' if index == 0
      @io.print line
    end
    @io.puts ' */'
  end

  # compile-time assert
  def puts_ct_assert(expr)
    puts "C_ASSERT(#{expr});"
  end
end

class CNumberType < Struct.new(:name, :camel_name, :type_id, :max_str, :min_str)
  def signed?
    type_id < 0
  end

  def unsigned?
    !signed?
  end

  def to_s
    name
  end

  # Returns true if this type is always going to have at least as many
  # bytes as another type on all systems we care about.  If you use
  # this fact, you should probably emit an assumption to test it.
  def as_many_bytes_as?(other)
    type_id.abs >= other.type_id.abs  # TODO: use possible_byte_sizes
  end

  # Returns true if this type is always guaranteed to have more bytes
  # than another.
  def more_bytes_than?(other)
    possible_byte_sizes.min > other.possible_byte_sizes.max
  end

  def possible_byte_sizes
    if type_id.abs == PointerSizeDummy
      # This is a pointer-sized type, so it could have 4 or 8 bytes.
      return [4, 8]
    end

    # This type always has the same number of bytes.
    [type_id.abs]
  end
end

# Dummy value that can be used inside a type ID to indicate that this
# type actually is 64-bit on WIN64 and 32-bit elsewhere.
# This value can be negated for signed types.
PointerSizeDummy = 7

SignedCharType = CNumberType['CHAR', 'Char', -1, 'SCHAR_MAX', 'SCHAR_MIN']
UnsignedCharType = CNumberType['CHAR', 'Char', 1, 'UCHAR_MAX', 0]

Types = [
  CNumberType['UCHAR', 'UChar', 1, 'UCHAR_MAX', 0],
  CNumberType['BYTE', 'Byte', 1, 'UCHAR_MAX', 0],
  CNumberType['USHORT', 'UShort', 2, 'USHRT_MAX', 0],
  CNumberType['WORD', 'Word', 2, 'USHRT_MAX', 0],
  CNumberType['SHORT', 'Short', -2, 'SHRT_MAX', 'SHRT_MIN'],
  CNumberType['UINT', 'UInt', 4, 'UINT_MAX', 0],
  CNumberType['ULONG', 'ULong', 4, 'ULONG_MAX', 0],
  CNumberType['DWORD', 'DWord', 4, 'ULONG_MAX', 0],
  CNumberType['INT', 'Int', -4, 'INT_MAX', 'INT_MIN'],
  CNumberType['LONG', 'Long', -4, 'LONG_MAX', 'LONG_MIN'],
  CNumberType['UINT_PTR', 'UIntPtr', PointerSizeDummy, 'UINTPTR_MAX', 0],
  CNumberType['size_t', 'SizeT', PointerSizeDummy, 'SIZE_MAX', 0],  # not SIZE_T!
  CNumberType['DWORD_PTR', 'DWordPtr', PointerSizeDummy, 'SIZE_MAX', 0],
  CNumberType['ULONG_PTR', 'ULongPtr', PointerSizeDummy, 'SIZE_MAX', 0],
  CNumberType['INT_PTR', 'IntPtr', -PointerSizeDummy, 'INTPTR_MAX', 'INTPTR_MIN'],
  CNumberType['ptrdiff_t', 'PtrdiffT', -PointerSizeDummy, 'PTRDIFF_MAX', 'PTRDIFF_MIN'],
  CNumberType['SSIZE_T', 'SSIZET', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['LONG_PTR', 'LongPtr', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['ULONGLONG', 'ULongLong', 8, 'ULLONG_MAX', 0],
  CNumberType['INT64', 'Int64', -8, '_I64_MAX', '_I64_MIN'],
]

TypesByName = Types.each_with_object({}) { |type, h| h[type.name] = type }

EquivalentTypes = [
  %w(UCHAR BYTE),
  %w(USHORT WORD),
  %w(ULONG DWORD),
  %w(UINT_PTR size_t),
  %w(DWORD_PTR ULONG_PTR),
  %w(INT_PTR ptrdiff_t),
  %w(SSIZE_T LONG_PTR),
]

def write_size_assumptions(cenv)
  cenv.puts_ct_assert "1 == sizeof(CHAR)"

  Types.chunk { |s| s.type_id.abs }.each do |size, types|
    if size == PointerSizeDummy
      cenv.puts_ct_assert "sizeof(void *) == 4 || sizeof(void *) == 8"
    end

    types.each do |type|
      size_str = type.type_id.abs.to_s
      size_str = 'sizeof(void *)' if size == PointerSizeDummy
      cenv.puts_ct_assert "#{size_str} == sizeof(#{type})"
    end

    cenv.puts
  end
end

def write_sign_assumptions(cenv)
  cenv.puts "#ifdef __CHAR_UNSIGNED__"
  cenv.puts_ct_assert "(char)-1 > 0"
  cenv.puts "#else"
  cenv.puts_ct_assert "(char)-1 < 0"
  cenv.puts "#endif"

  types_grouped_by_signedness = Types.sort_by { |t| [t.signed? ? 0 : 1, Types.index(t)] }
  types_grouped_by_signedness.each do |type|
    if type.signed?
      cenv.puts_ct_assert "(#{type})-1 < 0"
    else
      cenv.puts_ct_assert "(#{type})-1 > 0"
    end
  end
  cenv.puts
end

def write_limit_assumptions(cenv)
  tested = []
  Types.each do |type|
    bits = type.type_id.abs * 8
    bits = 'PTR' if bits == PointerSizeDummy * 8
    std_max_name = (type.signed? ? '' : 'U') + "INT#{bits}_MAX"
    std_min_name = (type.signed? ? '' : 'U') + "INT#{bits}_MIN"

    if !tested.include?(type.max_str)
      tested << type.max_str
      unless std_max_name == type.max_str
        cenv.puts_ct_assert "#{std_max_name} == #{type.max_str}"
      end
    end

    if type.min_str != 0 && !tested.include?(type.min_str)
      tested << type.max_str
      unless std_min_name == type.min_str
        cenv.puts_ct_assert "#{std_min_name} == #{type.min_str}"
      end
    end
  end
  cenv.puts
end

def write_compatibility_assumptions(cenv)
  cenv.puts "#ifndef __cplusplus"
  EquivalentTypes.each do |types|
    types[1...types.size].each do |type|
      cenv.puts_ct_assert "__builtin_types_compatible_p(#{types[0]}, #{type})"
    end
  end
  cenv.puts "#endif"
  cenv.puts
end

def write_type_assumptions(cenv)
  write_size_assumptions(cenv)
  write_sign_assumptions(cenv)
  write_limit_assumptions(cenv)
  write_compatibility_assumptions(cenv)
end

def conversion_function_name(type1, type2)
  func_name = "#{type1.camel_name}To#{type2.camel_name}"
  if ApiFunctionNames.include?(func_name)
    func_name
  else
    '__mingw_intsafe_' + func_name
  end
end

def write_function(cenv, func_name, args)
  cenv.puts "__MINGW_INTSAFE_API HRESULT #{func_name}(#{args})"
  cenv.puts '{'
  cenv.indent_level += 1
  yield cenv
  cenv.indent_level -= 1
  cenv.puts '}'
  cenv.puts
end

# Yields zero or more C environments to the caller where we definitely
# need to do an upper bound check because it is possible that a value
# of type type_src is too big to be represented in type_dest.  We
# generate such environments either using ifdefs or our knowledge of
# the possibilities incarnations that each type has.
def cenv_where_upper_check_needed(cenv, type_src, type_dest)
  case
  when type_dest.more_bytes_than?(type_src)
    # On every system we care about, the destination type has more
    # bytes, so skip the comparison.

  when type_dest.unsigned? && type_dest.as_many_bytes_as?(type_src)
    # We shouldn't need an upper comparison because the destination
    # type is unsigned and guaranteed to have at least as many bytes
    # as the source type.

  when type_src.signed? == type_dest.signed? && type_dest.as_many_bytes_as?(type_src)
    # If the two types have equal signs and the destination is big
    # enough, we can skip the comparison.

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
    # Another possibility is a cast, but an ifdef is safer.
    cenv.puts "#if #{type_src.max_str} > #{type_dest.max_str}"
    yield cenv
    cenv.puts "#endif"

  when type_src.type_id == -8 && type_dest.type_id == PointerSizeDummy
    # On 32-bit systems, an upper check is needed.
    #
    # On 64-bit systems, no upper check is necessary because a signed
    # int64_t can never too large to be represented in a size_t
    # (uint64_t).  Also, the check would produce bad code because
    # of Section 6.3.1.8 of C99.  Therefore, we need an ifdef.
    cenv.puts "#if #{type_src.max_str} > #{type_dest.max_str}"
    yield cenv
    cenv.puts "#endif"

  else
    # Do the comparison.
    yield cenv
  end
end

# Yields zero or more C environments to the caller where we definitely
# need to do a lower bound check because it is possible that a value
# of type type_src is too big to be represented in type_dest.  We
# generate such environments either using ifdefs or our knowledge of
# the possibilities incarnations that each type has.
def cenv_where_lower_check_needed(cenv, type_src, type_dest)
  case
  when type_src.unsigned?
    # The source is unsigned, so it can't be less than 0, so it will
    # never be too small.
  when type_src.signed? && type_dest.signed? && type_dest.as_many_bytes_as?(type_src)
    # It is a signed-to-signed conversion and the destination will
    # always be big enough.
  else
    # Otherwise perform the check.
    yield cenv
  end
end

def write_conversion_function(cenv, type_src, type_dest)
  return if !conversion_function_needed?(type_src, type_dest)

  func_name = conversion_function_name(type_src, type_dest)
  args = "_In_ #{type_src} operand, _Out_ #{type_dest} * result"
  write_function(cenv, func_name, args) do |cenv|
    cenv.puts "*result = 0;"

    # Suppress this check if the source type is signed, the
    # destination type is unsigned, and the check is unnecessary.
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

def conversion_function_needed?(type1, type2)
  ApiFunctionNames.include?("#{type1.camel_name}To#{type2.camel_name}")
end

#def write_aliased_conversion_function(cenv, type1, type2)
#  cenv.puts "#define #{func_name} #{real_name}"
#end

def write_unsigned_char_aliases(cenv, char_type)
  cenv.puts_comment <<END
If CHAR is unsigned, use different symbol names.
The avoids the risk of linking to the wrong function when different
translation units with different types of chars are linked together.
END

  Types.each do |type|
    if conversion_function_needed?(type, char_type)
      api_name = conversion_function_name(type, char_type)
      symbol_name = "__mingw_intsafe_uchar_#{type.camel_name}To#{char_type.camel_name}"
      cenv.puts "#define #{api_name} #{symbol_name}"
    end
  end
  cenv.puts
end

def write_conversion_to_char(cenv, type)
  func_name = "#{type.camel_name}ToChar"
  return if !ApiFunctionNames.include?(func_name)
  args = "_In_ #{type} operand, _Out_ CHAR * result"
  write_function(cenv, func_name, args) do |cenv|
    cenv.puts "*result = 0;"
    cenv.puts "if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    if type.signed?
      cenv.puts "if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;"
    end
    cenv.puts "*result = operand;"
    cenv.puts "return S_OK;"
  end
end

def write_char_conversions(cenv)
  cenv.puts "#ifdef __CHAR_UNSIGNED__"
  write_unsigned_char_aliases(cenv, UnsignedCharType)
  cenv.puts_comment 'this logic should be moved to limits.h'
  cenv.puts "#define __MINGW_INTSAFE_CHAR_MIN 0"
  cenv.puts "#define __MINGW_INTSAFE_CHAR_MAX 0xff"
  cenv.puts "#else"
  cenv.puts "#define __MINGW_INTSAFE_CHAR_MIN -0x80"
  cenv.puts "#define __MINGW_INTSAFE_CHAR_MAX 0x7f"
  cenv.puts "#endif"
  cenv.puts

  Types.each do |type|
    write_conversion_to_char(cenv, type)
  end
end

# Write functions for converting from one type to another.
def write_conversion_functions(cenv)
  # To make the header shorter, we have a list of "main types" and we
  # only define functions for converting between those main types.
  # All the other functions are preprocessor macros pointing to a
  # conversion function that operates on "main types".

  Types.each do |type1|
    Types.each do |type2|
      next unless conversion_function_needed?(type1, type2)
      write_conversion_function(cenv, type1, type2)
    end
  end

  write_char_conversions(cenv)
end

def write_functions(cenv)
  write_conversion_functions(cenv)
end

def write_todos_for_missing_functions(cenv)
  missing = ApiFunctionNames - GeneratedFunctions
  return if missing.empty?
  cenv.puts "/* TODO: add #{missing.size} missing functions */"
end

def write_top(cenv)
  cenv.puts LICENSE
  cenv.puts
  cenv.puts INFO
  cenv.puts
  cenv.puts File.read('top.h')
  cenv.puts
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
      if conversion_function_needed?(type1, type2)
        print 'X'
      elsif type1 == type2
        print '='
      else
        print '.'
      end
    end
    puts
  end
end

CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_type_assumptions(cenv)
  write_functions(cenv)
  write_todos_for_missing_functions(cenv)
end
