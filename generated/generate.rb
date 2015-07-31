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
FunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)
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

[
  CNumberType['UCHAR', 'UChar', 1, 'UCHAR_MAX', 0],
  CNumberType['signed char', 'Int8', char_type, 'SCHAR_MAX', 'SCHAR_MIN'],  # special type
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
  CNumberType['UINT_PTR', 'UIntPtr', pointer_size, 'SIZE_MAX', 0],
  CNumberType['size_t', 'SizeT', pointer_size, 'SIZE_MAX', 0],
  CNumberType['DWORD_PTR', 'DWordPtr', pointer_size, 'SIZE_MAX', 0],
  CNumberType['ULONG_PTR', 'ULongPtr', pointer_size, 'SIZE_MAX', 0],
  CNumberType['INT_PTR', 'IntPtr', -pointer_size, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['LONG_PTR', 'LongPtr', -pointer_size, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['ptrdiff_t', 'PtrdiffT', -pointer_size, 'SSIZE_MAX', 'SSIZE_MIN'],
  CNumberType['SSIZE_T', 'SSIZET', -pointer_size, 'SSIZE_MAX', 'SSIZE_MIN'],
]

def write_todos_for_missing_functions(cenv)
  missing = FunctionNames - GeneratedFunctions
  return if missing.empty?
  cenv.puts "/* TODO: add #{missing.size} missing functions */"
end

def write_top(cenv)
  cenv.puts LICENSE
  cenv.puts
  cenv.puts INFO
  cenv.puts
  cenv.puts '#pragma once'
  cenv.puts
  cenv.puts '#include <ntdef.h>'
  cenv.puts '#include <limits.h>'
  cenv.puts
  cenv.puts '/* This should probably be in limits.h. */'
  cenv.puts '#ifndef SSIZE_MIN'
  cenv.puts '#ifdef _WIN64'
  cenv.puts '#define SSIZE_MIN _I64_MIN'
  cenv.puts '#else'
  cenv.puts '#define SSIZE_MIN INT_MIN'
  cenv.puts '#endif'
  cenv.puts '#endif'
  cenv.puts
  cenv.puts "#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)"
end

CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_todos_for_missing_functions(cenv)
end
