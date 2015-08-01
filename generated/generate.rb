# This file and the files in this directory are unencumbered software
# released into the public domain.

require 'stringio'
require_relative 'assumptions'
require_relative 'conversions'
require_relative 'math'

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
  CNumberType['SSIZE_T', 'SSIZET', -PointerSizeDummy, 'SSIZE_MAX', 'INTPTR_MIN'],
  CNumberType['LONG_PTR', 'LongPtr', -PointerSizeDummy, 'INTPTR_MAX', 'INTPTR_MIN'],
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

def EquivalentTypes.for_type(type)
  names = find { |ns| ns.include? type.name } or return [type]
  names.map { |n| TypesByName.fetch(n) }
end

def write_function_aliases(cenv)
  FunctionAliases.each do |api_func_name, real_name|
    if GeneratedFunctions.include? real_name
      GeneratedFunctions << api_func_name
      cenv.puts "#define #{api_func_name} #{real_name}"
    end
  end
  cenv.puts
end

def write_function(cenv, func_name, args, ret=nil)
  raise if !(ApiFunctionNames.include?(func_name) ||
             func_name.start_with?('__mingw_intsafe_'))
  ret ||= '__MINGW_INTSAFE_API HRESULT'
  cenv.puts "#{ret} #{func_name}(#{args})"
  cenv.puts '{'
  cenv.indent_level += 1
  yield cenv
  cenv.indent_level -= 1
  cenv.puts '}'
  cenv.puts
  GeneratedFunctions << func_name
end

def write_todos_for_missing_functions(cenv)
  missing = ApiFunctionNames - GeneratedFunctions
  return if missing.empty?
  cenv.puts "/* TODO: add #{missing.size} missing functions */"
end

def write_top(cenv)
  cenv.puts File.read('top.h')
  cenv.puts
end

def calculate_function_aliases
  aliases = {}
  aliases.merge! calculate_conversion_function_aliases
  aliases.merge! calculate_math_function_aliases
end

def write_functions(cenv)
  write_conversion_functions(cenv)
  write_math_functions(cenv)
end

def function_body_needed?(name)
  ApiFunctionNames.include?(name) && !FunctionAliases.include?(name)
end

FunctionAliases = calculate_function_aliases

# visualize_needed_conversions && abort

CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_type_assumptions(cenv)
  write_functions(cenv)
  write_function_aliases(cenv)
  write_todos_for_missing_functions(cenv)
end
