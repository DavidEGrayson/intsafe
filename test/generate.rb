# Run this to generate generated_tests.cpp
#
# Environment variations to be aware of:
#   language: C or C++
#   architecture: win32 or win64
#   char type: signed or unsigned (-funsigned-char)

require 'set'

Dir.chdir(File.dirname(__FILE__))

VER = ENV.fetch('VER')
FunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)
MissingFunctions = []
TestedFunctions = []

def function_testable?(func_name)
  if !FunctionNames.include?(func_name)
    # This function is not in the Microsoft documentation.
    return false
  end

  if MissingFunctions.include?(func_name)
    # The implementation we are tested does not have this function.
    return false
  end

  true
end

class CNumberType < Struct.new(:name, :camel_name, :type_id)
  def byte_count
    type_id.abs
  end

  def signed?
    type_id < 0
  end

  def unsigned?
    !signed?
  end

  def to_s
    name
  end

  def c99_name
    str = ''
    str << 'u' if type_id >= 0
    str << "int#{type_id.abs * 8}_t"
  end

  def max
    if signed?
      (1 << (byte_count * 8 - 1)) - 1
    else
      (1 << (byte_count * 8)) - 1
    end
  end

  def min
    if signed?
      -(1 << (byte_count * 8 - 1))
    else
      0
    end
  end
end

def generate_types(pointer_size, char_signed)
  char_type = char_signed ? -1 : 1
  [
    CNumberType['UCHAR', 'UChar', 1],
    CNumberType['UINT8', 'UInt8', 1],
    CNumberType['BYTE', 'Byte', 1],
    CNumberType['CHAR', 'Char', char_type],
    CNumberType['INT8', 'Int8', -1],
    CNumberType['UINT16', 'UInt16', 2],
    CNumberType['USHORT', 'UShort', 2],
    CNumberType['WORD', 'Word', 2],
    CNumberType['INT16', 'Int16', -2],
    CNumberType['SHORT', 'Short', -2],
    CNumberType['UINT', 'UInt', 4],
    CNumberType['ULONG', 'ULong', 4],
    CNumberType['DWORD', 'DWord', 4],
    CNumberType['INT', 'Int', -4],
    CNumberType['LONG', 'Long', -4],
    CNumberType['ULONGLONG', 'ULongLong', 8],
    CNumberType['INT64', 'Int64', -8],
    CNumberType['LONGLONG', 'LongLong', -8],
    CNumberType['UINT_PTR', 'UIntPtr', pointer_size],
    CNumberType['size_t', 'SizeT', pointer_size],
    CNumberType['DWORD_PTR', 'DWordPtr', pointer_size],
    CNumberType['ULONG_PTR', 'ULongPtr', pointer_size],
    CNumberType['INT_PTR', 'IntPtr', -pointer_size],
    CNumberType['LONG_PTR', 'LongPtr', -pointer_size],
    CNumberType['ptrdiff_t', 'PtrdiffT', -pointer_size],
    CNumberType['SSIZE_T', 'SSIZET', -pointer_size],
  ]
end

Indent = "    "

class IndentedIO
  def initialize(io)
    @io = io
  end

  def puts(*args)
    @io.print Indent unless args.empty?
    @io.puts *args
  end

  def puts_indent(*args)
    IndentedIO.new(self).puts(*args)
  end

  def print(*args)
    @io.print *args
  end
end

def write_bracketed_section(io)
  io.puts '{'
  yield IndentedIO.new(io)
  io.puts '}'
  io.puts
end

def write_static_void_func(io, name, &block)
  io.puts "static void #{name}()"
  write_bracketed_section(io, &block)
  name
end

def write_test(io, name, &block)
  write_static_void_func(io, name, &block)
end

def write_section(io, comment = nil, &block)
  io.puts "// " + comment if comment
  write_bracketed_section(io, &block)
end

def collect_tests(io, name)
  tc = []
  yield tc

  write_static_void_func(io, name) do |io|
    tc.compact.each do |test_name|
      io.puts "#{test_name}();"
    end
  end
end

# These tests makes sure our database of types is correct.
def write_type_tests(io, types)
  collect_tests(io, 'tests_types') do |tc|
    types.each do |type|
      comparison = type.signed? ? '<' : '>';
      tc << write_test(io, "test_#{type}_eq_#{type.c99_name}") do |test|

        # Check the size of the type.
        test.puts "if(sizeof(#{type}) != #{type.byte_count})"
        test.puts_indent %Q{error("#{type} is actually %d bytes", (int)sizeof(#{type}));}

        # Check the signedness of the type.
        test.puts "#{type} x = 0;"
        test.puts "if(!((#{type})(x - 1) #{comparison} x))"
        test.puts_indent %Q{error("#{type} sign check failed");}

        # Do additional checks if possible.
        test.puts "#ifdef __cplusplus"
        test.puts "if(std::is_pointer<#{type}>::value)"
        test.puts_indent %Q{error("#{type} is a pointer");}
        #test.puts "#else"
        #test.puts "if(!__builtin_types_compatible_p(#{type}, #{type.c99_name}))"
        #test.puts_indent %Q{error("#{type} is not compatible with #{type.c99_name}");}
        test.puts "#endif"
      end
    end
  end
end

def nice_num_str(num)
  case
  when num.is_a?(String) then num
  when num < 0 then '(-' + nice_num_str(-num - 1) + 'll - 1)'
  else '%#x' % num
  end
end

def write_require_conversion(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "out = INITIAL_VALUE;"
  io.puts "if(#{func_name}(#{num_str}, &out) != 0)"
  io.puts_indent %Q{error("#{func_name} failed to convert #{num_str}");}
  io.puts "if(out != #{num_str})"
  io.puts_indent %Q{error("#{func_name} changed #{num_str} to something else.");}
  io.puts
end

def write_require_conversion_error(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "if(INTSAFE_E_ARITHMETIC_OVERFLOW != #{func_name}(#{num_str}, &out))"
  io.puts_indent %Q{error("#{func_name} did not overflow when given #{num_str}");}
  io.puts
end

def write_type_checker(io, func_name, return_type, arg_types)
  write_section(io, "has the right type") do |sec|
    sec.puts "#{return_type} (*tmp)(#{arg_types}) __attribute__((unused)) = &#{func_name};"
    sec.puts "#ifdef __cplusplus"
    type_signature = "#{return_type} (*)(#{arg_types})"
    sec.puts "if(!std::is_same<decltype(&#{func_name}), #{type_signature}>::value)"
    sec.puts_indent %Q{error("#{func_name} does not have the right signature");}
    sec.puts "#endif"
  end
end

def write_conversion_test(io, type_src, type_dest)
  func_name = type_src.camel_name + 'To' + type_dest.camel_name

  return nil if !function_testable?(func_name)
  TestedFunctions << func_name

  max = [type_src.max, type_dest.max].min
  min = [type_src.min, type_dest.min].max

  write_test(io, "test_#{func_name}") do |test|
    test.puts "#{type_dest} out;"

    write_type_checker test, func_name, "HRESULT",
      "_In_ #{type_src.name}, _Out_ #{type_dest} *"

    write_require_conversion(test, func_name, 0)
    write_require_conversion(test, func_name, max)
    write_require_conversion(test, func_name, min) if min != 0

    if type_src.max > type_dest.max
      write_require_conversion_error(test, func_name, type_dest.max + 1)
    end

    if type_src.min < type_dest.min
      write_require_conversion_error(test, func_name, type_dest.min - 1);
    end
  end
end

def write_conversion_tests(io, types)
  collect_tests(io, 'tests_conversions') do |tc|
    types.each do |type1|
      types.each do |type2|
        next if type1 == type2
        tc << write_conversion_test(io, type1, type2)
      end
    end
  end
end

def write_require_binop(io, func_name, num1, num2, result)
  num1_str = nice_num_str(num1)
  num2_str = nice_num_str(num2)
  result_str = nice_num_str(result)
  io.puts "out = INITIAL_VALUE;"
  io.puts "if (#{func_name}(#{num1_str}, #{num2_str}, &out))"
  io.puts_indent %Q{error("#{func_name} gave error when given #{num1_str}, #{num2_str}.");}
  io.puts "if (out != #{result_str})"
  io.puts_indent %Q{error("#{func_name} gave incorrect result when given #{num1_str}, #{num2_str}.");}
  io.puts
end

def write_require_binop_error(io, func_name, num1, num2)
  num1_str = nice_num_str(num1)
  num2_str = nice_num_str(num2)
  io.puts "if (#{func_name}(#{num1_str}, #{num2_str}, &out) != INTSAFE_E_ARITHMETIC_OVERFLOW)"
  io.puts_indent %Q{error("#{func_name} did not overflow given #{num1_str}, #{num2_str}.");}
  io.puts
end

def write_require_binop_error_both_ways(io, func_name, num1, num2)
  write_require_binop_error(io, func_name, num1, num2)
  write_require_binop_error(io, func_name, num2, num1) if num1 != num2
end

def write_require_binop_both_ways(io, func_name, num1, num2, result)
  write_require_binop(io, func_name, num1, num2, result)
  write_require_binop(io, func_name, num2, num1, result) if num1 != num2
end

def write_require_addition(io, func_name, num1, num2)
  sum = num1 + num2
  write_require_binop_both_ways(io, func_name, num1, num2, sum)
end

def write_require_addition_error(io, func_name, num1, num2)
  write_require_binop_error_both_ways(io, func_name, num1, num2)
end

def write_require_multiplication(io, func_name, num1, num2)
  product = num1 * num2
  write_require_binop_both_ways(io, func_name, num1, num2, product)
end

def write_require_multiplication_error(io, func_name, num1, num2)
  write_require_binop_error_both_ways(io, func_name, num1, num2)
end

def write_require_subtraction(io, func_name, num1, num2)
  result = num1 - num2
  write_require_binop(io, func_name, num1, num2, result)
end

def write_require_subtraction_error(io, func_name, num1, num2)
  write_require_binop_error(io, func_name, num1, num2)
end

def write_binop_test(io, type, func_name)
  return nil if !function_testable?(func_name)
  TestedFunctions << func_name

  write_test(io, "test_#{func_name}") do |test|
    test.puts "#{type} out;"
    test.puts

    write_type_checker test, func_name, "HRESULT",
      "_In_ #{type}, _In_ #{type}, _Out_ #{type} *"

    yield test
  end
end

def write_addition_test(io, type)
  func_name = "#{type.camel_name}Add"

  write_binop_test(io, type, func_name) do |test|
    write_require_addition(test, func_name, 0, 0)
    write_require_addition(test, func_name, 1, 3)
    write_require_addition(test, func_name, 0, type.max)
    write_require_addition_error(test, func_name, 1, type.max)
    write_require_addition_error(test, func_name, type.max, type.max)

    if type.signed?
      write_require_addition(test, func_name, 0, type.min)
      write_require_addition(test, func_name, -1, -3)
      write_require_addition_error(test, func_name, -1, type.min)
      write_require_addition_error(test, func_name, -1, type.min)
      write_require_addition_error(test, func_name, type.min, type.min)
    end
  end
end

def write_subtraction_test(io, type)
  func_name = "#{type.camel_name}Sub"
  write_binop_test(io, type, func_name) do |test|
    if type.unsigned?
      # Lower left
      write_require_subtraction(test, func_name, 0, 0)
      write_require_subtraction_error(test, func_name, 0, 1)
      write_require_subtraction(test, func_name, 1, 1)

      # Lower right
      write_require_subtraction(test, func_name, type.max, 0)

      # Upper left
      write_require_subtraction_error(test, func_name, 0, type.max)

      # Upper right
      write_require_subtraction(test, func_name, type.max, type.max)
      write_require_subtraction_error(test, func_name, type.max - 1, type.max)
    else
      # Center
      write_require_subtraction(test, func_name, 0, 0)
      write_require_subtraction(test, func_name, 5, 10)
      write_require_subtraction(test, func_name, 5, -10)
      write_require_subtraction(test, func_name, -5, -10)
      write_require_subtraction(test, func_name, -5, 10)

      # Upper left corner
      write_require_subtraction_error(test, func_name, type.min, type.max)

      # Lower right corner
      write_require_subtraction_error(test, func_name, type.max, type.min)

      # Upper right corner
      write_require_subtraction(test, func_name, type.max, type.max)

      # Lower left corner
      write_require_subtraction(test, func_name, type.min, type.min)

      # Left
      write_require_subtraction(test, func_name, type.min, 0)
      write_require_subtraction_error(test, func_name, type.min, 1)

      # Right
      write_require_subtraction(test, func_name, type.max, 0)
      write_require_subtraction_error(test, func_name, type.max, -1)

      # Top
      write_require_subtraction(test, func_name, -1, type.max)
      write_require_subtraction_error(test, func_name, -2, type.max)

      # Bottom
      write_require_subtraction(test, func_name, -1, type.min)
      write_require_subtraction_error(test, func_name, 0, type.min)
    end
  end
end

def write_multiplication_test(io, type)
  func_name = "#{type.camel_name}Mult"

  write_binop_test(io, type, func_name) do |test|
    write_require_multiplication(test, func_name, 0, 0)
    write_require_multiplication(test, func_name, 0, 1)
    write_require_multiplication(test, func_name, 1, 1)
    write_require_multiplication(test, func_name, 1, 3)
    write_require_multiplication(test, func_name, 3, 3)

    write_require_multiplication(test, func_name, 0, type.max)
    write_require_multiplication(test, func_name, 1, type.max)
    write_require_multiplication_error(test, func_name, 2, type.max)

    write_require_multiplication(test, func_name, 10, type.max / 10)
    write_require_multiplication_error(test, func_name, 10, type.max / 10 + 1)
    write_require_multiplication_error(test, func_name, 11, type.max / 10)

    write_require_multiplication_error(test, func_name, type.max, type.max)

    if type.signed?
      write_require_multiplication(test, func_name, -1, type.max)
      write_require_multiplication_error(test, func_name, -2, type.max)

      write_require_multiplication(test, func_name, 1, type.min)
      write_require_multiplication(test, func_name, -1, type.min + 1)
      write_require_multiplication_error(test, func_name, -2, type.min + 1)
      write_require_multiplication_error(test, func_name, -1, type.min)

      write_require_multiplication_error(test, func_name, type.min, type.min)
      write_require_multiplication_error(test, func_name, type.min, type.max)

      write_require_multiplication(test, func_name, 10, -(-type.min / 10))
      write_require_multiplication_error(test, func_name, 10, -(-type.min / 10) - 1)
      write_require_multiplication_error(test, func_name, 11, -(-type.min / 10))

      write_require_multiplication(test, func_name, -10, (-type.min / 10))
      write_require_multiplication_error(test, func_name, -10, (-type.min / 10) + 1)
      write_require_multiplication_error(test, func_name, -11, (-type.min / 10))

      write_require_multiplication(test, func_name, -10, -(type.max / 10))
      write_require_multiplication_error(test, func_name, -10, -(type.max / 10) - 1)
      write_require_multiplication_error(test, func_name, -11, -(type.max / 10))
    end
  end
end

def write_math_tests(io, types)
  collect_tests(io, 'tests_math') do |tc|
    types.each do |type|
      tc << write_addition_test(io, type)
      tc << write_subtraction_test(io, type)
      tc << write_multiplication_test(io, type)
    end
  end
end

def write_missing_function_test(io)
  return nil if MissingFunctions.empty?
  write_test(io, "test_missing_functions") do |test|
    test.puts %Q{error("#{MissingFunctions.size} functions are missing and will not be tested");}
  end
end

def write_tests(io, types)
  collect_tests(io, 'tests_auto') do |tc|
    tc << write_missing_function_test(io)
    tc << write_type_tests(io, types)
    tc << write_conversion_tests(io, types)
    tc << write_math_tests(io, types)
  end
end

def find_missing_functions
  raise if MissingFunctions != []
  intsafe_code = File.read("../#{VER}/intsafe.h")
  matches = intsafe_code.scan(/\b[0-9A-Za-z_]+\b/)
  intsafe_names = Set.new(matches)
  FunctionNames.each do |name|
    if !intsafe_names.include?(name)
      MissingFunctions << name
    end
  end
  if MissingFunctions.size > 0
    puts "warning: #{MissingFunctions.size} functions are missing and tests were not generated for them"
  end
end

find_missing_functions
exit 2

File.open('generated_tests.cpp', 'w') do |output|
  output.puts File.read('test.cpp')
  output.puts

  output.puts "#ifdef _WIN64"

  output.puts "#ifdef __CHAR_UNSIGNED__"
  write_tests output, generate_types(8, false)
  output.puts "#else /* __CHAR_UNSIGNED__ */"
  write_tests output, generate_types(8, true)
  output.puts "#endif /* __CHAR_UNSIGNED__ else */"

  output.puts "#else /* _WIN64 */"

  output.puts "#ifdef __CHAR_UNSIGNED__"
  write_tests output, generate_types(4, false)
  output.puts "#else /* __CHAR_UNSIGNED__ */"
  write_tests output, generate_types(4, true)
  output.puts "#endif /* __CHAR_UNSIGNED__ else */"

  output.puts "#endif /* _WIN64 else */"

  output.puts File.read('test_bottom.cpp')
end

untested_functions = FunctionNames - TestedFunctions - MissingFunctions
if untested_functions.size > 0
  puts "warning: #{untested_functions.size} functions do not have tests yet, " \
    "for example: #{untested_functions.first}"
end
