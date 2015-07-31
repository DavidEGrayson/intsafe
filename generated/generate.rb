# The license for this file and the header it generates is:
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

Dir.chdir(File.dirname(__FILE__))
ApiFunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)
GeneratedFunctions = []

class CEnv
  def self.write_file(filename)
    File.open(filename, 'w') do |file|
      yield new(file)
    end
  end

  def initialize(io)
    @io = io
  end

  def puts(*args)
    @io.puts *args
  end
end

class CNumberType < Struct.new(:name, :camel_name, :type_id, :min_str, :max_str)
  def signed?
    type_id < 0
  end

  def unsigned?
    !signed?
  end

  def to_s
    name
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
  CNumberType['SIZE_T', 'SizeT', PointerSizeDummy, 'SIZE_MAX', 0],
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
  'UINT_PTR' => 'SIZE_T',
  'DWORD_PTR' => 'SIZE_T',
  'ULONG_PTR' => 'SIZE_T',
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
  'SIZE_T',
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
  cenv.puts "__MINGW_INTSAFE_API #{func_name}(#{args})"
  cenv.puts '{'
  yield cenv
  cenv.puts '}'
  cenv.puts
end

def write_conversion_function(cenv, type_src, type_dest)
  func_name = conversion_function_name(type_src, type_dest)
  args = "_In_ #{type_src} operand, _Out_ #{type_dest} * result"
  write_function(cenv, func_name, args) do |cenv|
    cenv.puts "*result = 0;"
    cenv.puts "return INTSAFE_E_ARITHMETIC_OVERFLOW;"
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

CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_functions(cenv)
  write_todos_for_missing_functions(cenv)
end
