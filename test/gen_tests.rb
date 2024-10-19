# Run this to generate generated_tests.cpp
#
# Environment variations to be aware of:
#   language: C or C++
#   architecture: win32 or win64
#   char type: signed or unsigned (-funsigned-char)

require 'set'

Dir.chdir(File.dirname(__FILE__))

IntsafeCode = File.read('intsafe.h')

# FuncInfo holds info about all the functions that could potentially exist and
# the metadata defining what they do so we can know how to test them.
#
# FuncInfo keys are function names as symbols
# FuncInfo values are hashes with these keys:
#   :name               => Symbol
#   :operation          => :add, :mult, :sub, or :convert
#   :type_src           => Symbol
#   :type_dest          => Symbol
#   :defined_by_msft    => true if found in function_names.txt
#   :defined_by_intsafe => true if found in intsafe.h
FuncInfo = {}

# TypeInfo keys are integer type names (as written in C/C++ variable
# declarations).
# TypeInfo values are hashes with these keys:
#   :name               => Symbol
#   :camel_name         => Symbol
#   :concrete           => CNumberType (changes depending on which system
#                          we are currently targeting)
TypeInfo = {}

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
  concrete_types = [
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
    CNumberType['UINT32', 'UInt32', 4],        # new

    CNumberType['INT', 'Int', -4],
    CNumberType['LONG', 'Long', -4],
    CNumberType['INT32', 'Int32', -4],         # new
    CNumberType['LONG32', 'Long32', -4],       # new

    CNumberType['ULONGLONG', 'ULongLong', 8],
    CNumberType['ULONG64', 'ULong64', 8],      # new
    CNumberType['UINT64', 'UInt64', 8],        # new
    CNumberType['DWORD64', 'DWord64', 8],      # new
    CNumberType['DWORDLONG', 'DWordLong', 8],  # new

    CNumberType['INT64', 'Int64', -8],
    CNumberType['LONGLONG', 'LongLong', -8],
    CNumberType['LONG64', 'Long64', -8],       # new

    CNumberType['UINT_PTR', 'UIntPtr', pointer_size],
    CNumberType['size_t', 'SizeT', pointer_size],
    CNumberType['DWORD_PTR', 'DWordPtr', pointer_size],
    CNumberType['ULONG_PTR', 'ULongPtr', pointer_size],
    CNumberType['SIZE_T', 'SIZET', pointer_size],   # new

    CNumberType['INT_PTR', 'IntPtr', -pointer_size],
    CNumberType['LONG_PTR', 'LongPtr', -pointer_size],
    CNumberType['ptrdiff_t', 'PtrdiffT', -pointer_size],
    CNumberType['SSIZE_T', 'SSIZET', -pointer_size],
  ]

  TypeInfo.clear
  concrete_types.each do |ctype|
    name = ctype.name.to_sym
    TypeInfo[name] = {
      name: name,
      camel_name: ctype.camel_name.to_sym,
    }
    TypeInfo[name][:concrete] = ctype unless pointer_size == 0
  end

  nil
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
  io.puts "static void #{name}(void)"
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
def write_type_tests(io)
  collect_tests(io, 'run_type_tests') do |tc|
    TypeInfo.each_value do |t|
      type = t.fetch(:concrete)
      comparison = type.signed? ? '<' : '>';
      tc << write_test(io, "test_type_#{type}") do |test|

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

def write_check_overflow_output(io, func_name)
  type_dest = FuncInfo.fetch(func_name.to_sym).fetch(:type_dest)
  ctype_dest = TypeInfo.fetch(type_dest).fetch(:concrete)
  # This is pretty arbitrary, but it's how the Microsoft header behaves (TODO: right?)
  if ctype_dest.name == 'UCHAR' || ctype_dest.name == 'CHAR' && !ctype_dest.signed?
    desired = '0'
  else
    desired = "(#{type_dest})-1"
  end

  io.puts "if (out != #{desired})"
  io.puts_indent %Q{error("#{func_name} gave wrong overflow output");}
end

def write_require_conversion_error(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "if(INTSAFE_E_ARITHMETIC_OVERFLOW != #{func_name}(#{num_str}, &out))"
  io.puts_indent %Q{error("#{func_name} did not overflow when given #{num_str}");}
  write_check_overflow_output(io, func_name)
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

def write_conversion_test(io, func)
  func_name = func.fetch(:name)
  type_src = TypeInfo.fetch(func.fetch(:type_src)).fetch(:concrete)
  type_dest = TypeInfo.fetch(func.fetch(:type_dest)).fetch(:concrete)

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
      write_require_conversion_error(test, func_name, type_dest.min - 1)
    end
  end
end

def write_conversion_tests(io)
  collect_tests(io, 'run_conversion_tests') do |tc|
    FuncInfo.each_value do |func|
      next if func.fetch(:operation) != :convert
      next if !func.fetch(:defined_by_intsafe)
      tc << write_conversion_test(io, func)
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
  write_check_overflow_output(io, func_name)
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
  write_test(io, "test_#{func_name}") do |test|
    test.puts "#{type} out;"
    test.puts

    write_type_checker test, func_name, "HRESULT",
      "_In_ #{type}, _In_ #{type}, _Out_ #{type} *"

    yield test
  end
end

def write_addition_test(io, func_name)
  type_name = FuncInfo.fetch(func_name).fetch(:type_dest)
  type = TypeInfo.fetch(type_name).fetch(:concrete)

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

def write_subtraction_test(io, func_name)
  type_name = FuncInfo.fetch(func_name).fetch(:type_dest)
  type = TypeInfo.fetch(type_name).fetch(:concrete)

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

def write_multiplication_test(io, func_name)
  type_name = FuncInfo.fetch(func_name).fetch(:type_dest)
  type = TypeInfo.fetch(type_name).fetch(:concrete)

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

def write_math_tests(io)
  collect_tests(io, 'run_math_tests') do |tc|
    FuncInfo.each_value do |func|
      next if !func.fetch(:defined_by_intsafe)
      op = func.fetch(:operation)
      if op == :add
        tc << write_addition_test(io, func.fetch(:name))
      elsif op == :sub
        tc << write_subtraction_test(io, func.fetch(:name))
      elsif op == :mult
        tc << write_multiplication_test(io, func.fetch(:name))
      end
    end
  end
end

def write_tests(io)
  collect_tests(io, 'run_all_tests') do |tc|
    tc << write_type_tests(io)
    tc << write_conversion_tests(io)
    tc << write_math_tests(io)
  end
end

def find_redefinitions
  if !IntsafeCode.include?('__MINGW_INTSAFE')
    # We don't understand the coding of this header enough to find redifintions.
    return
  end

  line_number = 0
  defs = Set.new
  redefs = Set.new
  filtered_lines = []
  IntsafeCode.each_line do |line|
    line_number += 1
    reject_line = false
    if (line.match(/#define ([0-9A-Za-z_]+)\b/) \
      || line.match(/API.+\b__MINGW_INTSAFE_[A-Z_]+\(([0-9A-Za-z_]+),/)) \
      && !$1.start_with?('_') \
      && !['S_OK', 'INTSAFE_E_ARITHMETIC_OVERFLOW'].include?($1)
      name = $1
      if defs.include?(name)
        puts "Function #{name} gets redefined on line #{line_number}!"
        redefs << name
        reject_line = true
      else
        defs << name
        if !FuncInfo[name.to_sym]
          puts "warning: intsafe.h defines something we don't know how to test: #{name}"
        end
      end
    end
    filtered_lines << line unless reject_line
  end
  return if redefs.empty?
  puts "Found #{redefs.size} function redefinitions!"

  File.open("filtered.h", "wb") do |file|
    filtered_lines.each do |line|
      file.puts line
    end
  end

  puts "Wrote a new version to filtered.h."
  puts "Please review and then do: mv filtered.h intsafe.h"
  exit 1
end

def init_func_info
  generate_types(0, false)

  TypeInfo.each_value do |type_src|
    TypeInfo.each_value do |type_dest|
      next if type_src == type_dest
      name = "#{type_src.fetch(:camel_name)}To#{type_dest.fetch(:camel_name)}".to_sym
      FuncInfo[name] = {
        name: name,
        operation: :convert,
        type_src: type_src.fetch(:name),
        type_dest: type_dest.fetch(:name),
      }
    end
  end

  TypeInfo.each_value do |type|
    type_name = type.fetch(:name)
    add_sym = "#{type.fetch(:camel_name)}Add".to_sym
    sub_sym = "#{type.fetch(:camel_name)}Sub".to_sym
    mult_sym = "#{type.fetch(:camel_name)}Mult".to_sym
    FuncInfo[add_sym] = {
      name: add_sym,
      operation: :add,
      type_dest: type_name,
    }
    FuncInfo[sub_sym] = {
      name: sub_sym,
      operation: :sub,
      type_dest: type_name,
    }
    FuncInfo[mult_sym] = {
      name: mult_sym,
      operation: :mult,
      type_dest: type_name,
    }
  end

  matches = IntsafeCode.scan(/\b[0-9A-Za-z_]+\b/)
  intsafe_names = Set.new(matches)
  msft_func_names = Set.new(File.readlines('../function_names.txt').map(&:strip).reject(&:empty?))

  FuncInfo.each_value do |func|
    name = func.fetch(:name).to_s
    func[:defined_by_intsafe] = intsafe_names.include?(name)
    func[:defined_by_msft] = msft_func_names.include?(name)

    if func.fetch(:defined_by_msft) && !func.fetch(:defined_by_intsafe)
      puts "warning: missing function will not be tested: #{name}"
    end

    if !func.fetch(:defined_by_msft) && func.fetch(:defined_by_intsafe)
      puts "warning: intsafe.h has extra function: #{name}"
    end
  end
end

init_func_info

find_redefinitions

File.open('generated.cpp', 'w') do |output|
  output.puts "#ifdef _WIN64"

  output.puts "#ifdef __CHAR_UNSIGNED__"
  generate_types(8, false)
  write_tests output
  output.puts "#else /* __CHAR_UNSIGNED__ */"
  generate_types(8, true)
  write_tests output
  output.puts "#endif /* __CHAR_UNSIGNED__ else */"

  output.puts "#else /* _WIN64 */"

  output.puts "#ifdef __CHAR_UNSIGNED__"
  generate_types(4, false)
  write_tests output
  output.puts "#else /* __CHAR_UNSIGNED__ */"
  generate_types(4, true)
  write_tests output
  output.puts "#endif /* __CHAR_UNSIGNED__ else */"

  output.puts "#endif /* _WIN64 else */"
end
