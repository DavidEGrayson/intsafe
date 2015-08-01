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
    puts "/* #{str} */"
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


Types = [
  CNumberType['UCHAR', 'UChar', 1, 'UCHAR_MAX', 0],
  CNumberType['INT8', 'Int8', -1, 'SCHAR_MAX', 'SCHAR_MIN'],  # special type
  CNumberType['BYTE', 'Byte', 1, 'UCHAR_MAX', 0],
  CNumberType['USHORT', 'UShort', 2, 'USHRT_MAX', 0],
  CNumberType['WORD', 'Word', 2, 'USHRT_MAX', 0],
  CNumberType['SHORT', 'Short', -2, 'SHRT_MAX', 'SHRT_MIN'],
  CNumberType['UINT', 'UInt', 4, 'UINT_MAX', 0],
  CNumberType['ULONG', 'ULong', 4, 'ULONG_MAX', 0],
  CNumberType['DWORD', 'DWord', 4, 'ULONG_MAX', 0],
  CNumberType['INT', 'Int', -4, 'INT_MAX', 'INT_MIN'],
  CNumberType['LONG', 'Long', -4, 'LONG_MAX', 'LONG_MIN'],
  CNumberType['ULONGLONG', 'ULongLong', 8, 'ULLONG_MAX', 0],
  CNumberType['INT64', 'Int64', -8, '_I64_MAX', '_I64_MIN'],
  CNumberType['UINT_PTR', 'UIntPtr', PointerSizeDummy, 'SIZE_MAX', 0],
  CNumberType['size_t', 'SizeT', PointerSizeDummy, 'SIZE_MAX', 0],  # not SIZE_T!
  CNumberType['DWORD_PTR', 'DWordPtr', PointerSizeDummy, 'SIZE_MAX', 0],
  CNumberType['ULONG_PTR', 'ULongPtr', PointerSizeDummy, 'SIZE_MAX', 0],
  CNumberType['INT_PTR', 'IntPtr', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['LONG_PTR', 'LongPtr', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['ptrdiff_t', 'PtrdiffT', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['SSIZE_T', 'SSIZET', -PointerSizeDummy, 'SSIZE_MAX', 'SSIZE_MIN'],
]

TypesByName = Types.each_with_object({}) { |type, h| h[type.name] = type }

TypeAliases = {
  'BYTE' => 'UCHAR',
  'WORD' => 'USHORT',
  'ULONG' => 'UINT',  # I think this isn't true; fix it when the compiler complains
  'DWORD' => 'UINT',  # probably not true either
  'LONG'  => 'INT',   # probably not true either
  'UINT_PTR' => 'size_t',
  'DWORD_PTR' => 'size_t',
  'ULONG_PTR' => 'size_t',
  'INT_PTR' => 'SSIZE_T',
  'LONG_PTR' => 'SSIZE_T',
  'ptrdiff_t' => 'SSIZE_T',
}

MainTypes = [
  'UCHAR',
  'INT8',
  'USHORT',
  'SHORT',
  'UINT',
  'INT',
  'ULONGLONG',
  'INT64',
  'size_t',
  'SSIZE_T'
].map(&TypesByName.method(:fetch))

def conversion_function_name(type1, type2)
  func_name = "#{type1.camel_name}To#{type2.camel_name}"
  if ApiFunctionNames.include?(func_name)
    func_name
  else
    '__mingw_intsafe_' + func_name
  end
end

def conversion_function_needed?(type1, type2)
  if MainTypes.include?(type1) && MainTypes.include?(type2)
    if ApiFunctionNames.include?("#{type1.camel_name}To#{type2.camel_name}")
      return true
    end
  end
  return false
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

def assume
  cenv = CEnv.new
  yield cenv
  Assumptions << cenv.io.string
end

def assume_max_not_greater(type1, type2)
  assume do |cenv|
    cenv.puts "#if #{type1.max_str} > #{type2.max_str}"
    cenv.puts "#error assumed no #{type1} is too large to be represented as a #{type2}"
    cenv.puts "#endif"
  end
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
    # bytes, so skip the comparison but emit a preprocessor-checked
    # assumption.
    assume_max_not_greater(type_src, type_dest)
  when type_dest.unsigned? && type_dest.as_many_bytes_as?(type_src)
    # We shouldn't need an upper comparison because the destination
    # type is unsigned and guaranteed to have at least as many bytes
    # as the source type.  Explicitly record this assumption and test
    # it using the preprocessor.
    assume_max_not_greater(type_src, type_dest)
  when type_src.signed? == type_dest.signed? && type_dest.as_many_bytes_as?(type_src)
    # If the two types have equal signs and the destination is big
    # enough, we could skip the comparison.  This case never actually
    # comes up due to the cases above and the set of functions we
    # implement.
    raise 'comment above is wrong, this case did happen'
  when type_src.type_id == -PointerSizeDummy && type_dest.type_id == 4
    # On 64-bit systems, we need to do an upper check because signed
    # pointers can be bigger than unsigned ints.  On 32-bit systems we
    # don't need to do the check, and the code for the check would
    # behave incorrectly because it would convert the upper boudn
    # (UINT_MAX) from an unsigned int to a signed int, as described in
    # Section 6.3.1.8 of the C standard (Usual arithmetic
    # conversions).  Therefore we need an ifdef to only do the check
    # when needed.
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
    # We could skip the check if this case ever happened, but it does not.
    raise 'the comment above is wrong'
  else
    # Otherwise perform the check.
    yield cenv
  end
end

def write_conversion_function(cenv, type_src, type_dest)
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

def write_conversion_functions(cenv)
  Types.each do |type1|
    Types.each do |type2|
      next unless conversion_function_needed?(type1, type2)
      write_conversion_function(cenv, type1, type2)
    end
  end
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

Assumptions = []
Functions = CEnv.new
CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_functions(cenv)
  cenv.puts Assumptions.uniq.sort.join("\n")
  write_todos_for_missing_functions(cenv)
end
