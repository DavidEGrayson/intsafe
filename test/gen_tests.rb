#!/usr/bin/env ruby

# Run this to generate generated_tests.cpp
#
# Environment variations to be aware of:
#   language: C or C++
#   architecture: win32 or win64
#   char type: signed or unsigned (-funsigned-char)

require 'set'

Dir.chdir(File.dirname(__FILE__))

# Define a CType class which is a very convenient way to hold types, and we'll use it everywhere.
class CType
  attr_reader :name, :camel_name, :essence

  def initialize(name, camel_name, essence)
    @name = name.to_sym
    @camel_name = camel_name.to_sym
    @essence = essence
  end

  def to_s
    @name.to_s
  end

  def inspect
    "CType(:#{@name})"
  end

  def byte_count(cenv)
    case @essence
    when :pointer, :pointer_signed
      cenv.fetch(:pointer_size)
    when :char
      1
    else
      @essence.abs
    end
  end

  def signed?(cenv)
    case @essence
    when :pointer
      false
    when :pointer_signed
      true
    when :char
      cenv.fetch(:char_signed) && true
    else
      @essence < 0
    end
  end

  def always_signed?
    signed?({ char_signed: false })
  end

  def max(cenv)
    if signed?(cenv)
      (1 << (byte_count(cenv) * 8 - 1)) - 1
    else
      (1 << (byte_count(cenv) * 8)) - 1
    end
  end

  def min(cenv)
    if signed?(cenv)
      -(1 << (byte_count(cenv) * 8 - 1))
    else
      0
    end
  end
end

CTypeTable = {
  UCHAR: CType.new(:UCHAR, :UChar, 1),
  UINT8: CType.new(:UINT8, :UInt8, 1),
  BYTE: CType.new(:BYTE, :Byte, 1),

  CHAR: CType.new(:CHAR, :Char, :char),

  INT8: CType.new(:INT8, :Int8, -1),

  UINT16: CType.new(:UINT16, :UInt16, 2),
  USHORT: CType.new(:USHORT, :UShort, 2),
  WORD: CType.new(:WORD, :Word, 2),

  INT16: CType.new(:INT16, :Int16, -2),
  SHORT: CType.new(:SHORT, :Short, -2),

  UINT: CType.new(:UINT, :UInt, 4),
  ULONG: CType.new(:ULONG, :ULong, 4),
  DWORD: CType.new(:DWORD, :DWord, 4),
  UINT32: CType.new(:UINT32, :UInt32, 4),

  INT: CType.new(:INT, :Int, -4),
  LONG: CType.new(:LONG, :Long, -4),
  INT32: CType.new(:INT32, :Int32, -4),
  LONG32: CType.new(:LONG32, :Long32, -4),

  ULONGLONG: CType.new(:ULONGLONG, :ULongLong, 8),
  ULONG64: CType.new(:ULONG64, :ULong64, 8),
  UINT64: CType.new(:UINT64, :UInt64, 8),
  DWORD64: CType.new(:DWORD64, :DWord64, 8),
  DWORDLONG: CType.new(:DWORDLONG, :DWordLong, 8),

  INT64: CType.new(:INT64, :Int64, -8),
  LONGLONG: CType.new(:LONGLONG, :LongLong, -8),
  LONG64: CType.new(:LONG64, :Long64, -8),

  #INT128: CType.new(:INT128, :Int128, -16),
  #UINT128: CType.new(:UINT128, :UInt128, 16),

  UINT_PTR: CType.new(:UINT_PTR, :UIntPtr, :pointer),
  size_t: CType.new(:size_t, :SizeT, :pointer),
  DWORD_PTR: CType.new(:DWORD_PTR, :DWordPtr, :pointer),
  ULONG_PTR: CType.new(:ULONG_PTR, :ULongPtr, :pointer),
  SIZE_T: CType.new(:SIZE_T, :SIZET, :pointer),

  INT_PTR: CType.new(:INT_PTR, :IntPtr, :pointer_signed),
  LONG_PTR: CType.new(:LONG_PTR, :LongPtr, :pointer_signed),
  ptrdiff_t: CType.new(:ptrdiff_t, :PtrdiffT, :pointer_signed),
  SSIZE_T: CType.new(:SSIZE_T, :SSIZET, :pointer_signed),
}

def CType(name)
  CTypeTable.fetch(name.to_sym)
end

# FeatureInfo holds info about all the intsafe.h features that could potentially exist and
# the metadata defining what they do so we can know how to test them.
#
# FeatureInfo keys are function names as symbols
# FeatureInfo values are hashes with these keys:
#   :name               => Symbol
#   :operation          => :add, :mult, :sub, :convert, :min, :max
#   :type_src           => CType or not set if not applicable
#   :type_dest          => CType
#   :test               => true if we should generate tests for it
FeatureInfo = {}

Indent = "    "

class IndentedIO
  def initialize(io, indent='')
    @io = io
    @indent = indent
  end

  def indented
    tmp = dup
    tmp.indent += Indent
    tmp
  end

  def puts(*args)
    @io.print @indent unless args.empty?
    @io.puts *args
  end

  def puts_indent(*args)
    indented.puts(*args)
  end

  def print(*args)
    @io.print *args
  end

  attr_accessor :cenv
  attr_accessor :indent
end

def write_bracketed_section(io)
  io.puts '{'
  yield io.indented
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

# These tests make sure our database of types is correct.
def write_type_tests(io)
  CTypeTable.each_value do |type|
    comparison = type.signed?(io.cenv) ? '<' : '>';
    write_test(io, "test_type_#{type}") do |test|

      # Check the size of the type.
      test.puts "if (sizeof(#{type}) != #{type.byte_count(io.cenv)})"
      test.puts_indent %Q{error("#{type} is actually %d bytes", (int)sizeof(#{type.name}));}

      # Check the signedness of the type.
      test.puts "#{type} x = 0;"
      test.puts "if (!((#{type})(x - 1) #{comparison} x))"
      test.puts_indent %Q{error("#{type} sign check failed");}

      # Do additional checks if possible.
      test.puts "#ifdef __cplusplus"
      test.puts "if (std::is_pointer<#{type}>::value)"
      test.puts_indent %Q{error("#{type} is a pointer");}
      test.puts "#endif"
    end
  end
end

def cpp_num_str(num)
  if num >= (1 << 63)
    num.to_s + "U"
  elsif num <= -(1 << 63)
    "-#{0x7FFF_FFFF_FFFF_FFFF} - #{-num - 0x7FFF_FFFF_FFFF_FFFF}"
  else
    num.to_s
  end
end

def nice_num_str(num)
  case
  when num.is_a?(String) then num
  when num == 0 then '0'
  when num > 0 then '%#x' % num
  when num >= -0x7FFF_FFFF then '-%#x' % -num
  when num >= -0x7FFF_FFFF_FFFF_FFFF then '-%#xll' % -num
  else '(-' + nice_num_str(-num - 1) + 'll - 1)'
  end
end

def write_require_conversion(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "out = INITIAL_VALUE;"
  io.puts "if (#{func_name}(#{num_str}, &out) != 0)"
  io.puts_indent %Q{error("#{func_name} failed to convert #{num_str}");}
  io.puts "if (out != #{num_str})"
  io.puts_indent %Q{error("#{func_name} changed #{num_str} to something else.");}
  io.puts
end

def write_check_overflow_output(io, func_name)
  type_dest = FeatureInfo.fetch(func_name.to_sym).fetch(:type_dest)
  # This is pretty arbitrary, but it's how the Microsoft header behaves
  if type_dest.name == :UCHAR || type_dest.name == :CHAR && !type_dest.signed?(io.cenv)
    desired = '0'
  else
    desired = "(#{type_dest})-1"
  end
  io.puts "if (out != #{desired})"
  io.puts_indent %Q{error("#{func_name} gave wrong overflow output");}
end

def write_require_conversion_error(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "if (INTSAFE_E_ARITHMETIC_OVERFLOW != #{func_name}(#{num_str}, &out))"
  io.puts_indent %Q{error("#{func_name} did not overflow when given #{num_str}");}
  write_check_overflow_output(io, func_name)
  io.puts
end

def write_type_checker(io, func_name, return_type, arg_types)
  write_section(io, "has the right type") do |sec|
    sec.puts "#{return_type} (*tmp)(#{arg_types}) UNUSED = &#{func_name};"
    sec.puts "#ifdef __cplusplus"
    type_signature = "#{return_type} (*)(#{arg_types})"
    sec.puts "if (!std::is_same<decltype(&#{func_name}), #{type_signature}>::value)"
    sec.puts_indent %Q{error("#{func_name} does not have the right signature");}
    sec.puts "#endif"
  end
end

def write_conversion_test(io, func)
  func_name = func.fetch(:name)
  type_src = func.fetch(:type_src)
  type_dest = func.fetch(:type_dest)

  src_min = type_src.min(io.cenv)
  src_max = type_src.max(io.cenv)
  dest_min = type_dest.min(io.cenv)
  dest_max = type_dest.max(io.cenv)
  max = [src_max, dest_max].min
  min = [src_min, dest_min].max

  write_test(io, "test_#{func_name}") do |io2|
    io2.puts "#{type_dest} out;"

    write_type_checker io2, func_name, "HRESULT",
      "_In_ #{type_src.name}, _Out_ #{type_dest} *"

    write_require_conversion(io2, func_name, 0)
    write_require_conversion(io2, func_name, max)
    write_require_conversion(io2, func_name, min) if min != 0

    if src_max > dest_max
      write_require_conversion_error(io2, func_name, dest_max + 1)
    end

    if src_min < dest_min
      write_require_conversion_error(io2, func_name, dest_min - 1)
    end
  end
end

def write_conversion_tests(io)
  FeatureInfo.each_value do |feature|
    next unless feature.fetch(:test) && feature.fetch(:operation) == :convert
    write_conversion_test(io, feature)
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
  type = FeatureInfo.fetch(func_name).fetch(:type_dest)
  min = type.min(io.cenv)
  max = type.max(io.cenv)
  write_binop_test(io, type, func_name) do |test|
    write_require_addition(test, func_name, 0, 0)
    write_require_addition(test, func_name, 1, 3)
    write_require_addition(test, func_name, 0, max)
    write_require_addition_error(test, func_name, 1, max)
    write_require_addition_error(test, func_name, max, max)
    if min < 0
      write_require_addition(test, func_name, 0, min)
      write_require_addition(test, func_name, -1, -3)
      write_require_addition_error(test, func_name, -1, min)
      write_require_addition_error(test, func_name, -1, min)
      write_require_addition_error(test, func_name, min, min)
    end
  end
end

def write_subtraction_test(io, func_name)
  type = FeatureInfo.fetch(func_name).fetch(:type_dest)
  min = type.min(io.cenv)
  max = type.max(io.cenv)
  write_binop_test(io, type, func_name) do |test|
    if min == 0
      # Lower left
      write_require_subtraction(test, func_name, 0, 0)
      write_require_subtraction_error(test, func_name, 0, 1)
      write_require_subtraction(test, func_name, 1, 1)

      # Lower right
      write_require_subtraction(test, func_name, max, 0)

      # Upper left
      write_require_subtraction_error(test, func_name, 0, max)

      # Upper right
      write_require_subtraction(test, func_name, max, max)
      write_require_subtraction_error(test, func_name, max - 1, max)
    else
      # Center
      write_require_subtraction(test, func_name, 0, 0)
      write_require_subtraction(test, func_name, 5, 10)
      write_require_subtraction(test, func_name, 5, -10)
      write_require_subtraction(test, func_name, -5, -10)
      write_require_subtraction(test, func_name, -5, 10)

      # Upper left corner
      write_require_subtraction_error(test, func_name, min, max)

      # Lower right corner
      write_require_subtraction_error(test, func_name, max, min)

      # Upper right corner
      write_require_subtraction(test, func_name, max, max)

      # Lower left corner
      write_require_subtraction(test, func_name, min, min)

      # Left
      write_require_subtraction(test, func_name, min, 0)
      write_require_subtraction_error(test, func_name, min, 1)

      # Right
      write_require_subtraction(test, func_name, max, 0)
      write_require_subtraction_error(test, func_name, max, -1)

      # Top
      write_require_subtraction(test, func_name, -1, max)
      write_require_subtraction_error(test, func_name, -2, max)

      # Bottom
      write_require_subtraction(test, func_name, -1, min)
      write_require_subtraction_error(test, func_name, 0, min)
    end
  end
end

def write_multiplication_test(io, func_name)
  type = FeatureInfo.fetch(func_name).fetch(:type_dest)
  min = type.min(io.cenv)
  max = type.max(io.cenv)
  write_binop_test(io, type, func_name) do |test|
    write_require_multiplication(test, func_name, 0, 0)
    write_require_multiplication(test, func_name, 0, 1)
    write_require_multiplication(test, func_name, 1, 1)
    write_require_multiplication(test, func_name, 1, 3)
    write_require_multiplication(test, func_name, 3, 3)

    write_require_multiplication(test, func_name, 0, max)
    write_require_multiplication(test, func_name, 1, max)
    write_require_multiplication_error(test, func_name, 2, max)

    write_require_multiplication(test, func_name, 10, max / 10)
    write_require_multiplication_error(test, func_name, 10, max / 10 + 1)
    write_require_multiplication_error(test, func_name, 11, max / 10)

    write_require_multiplication_error(test, func_name, max, max)

    if min < 0
      write_require_multiplication(test, func_name, -1, max)
      write_require_multiplication_error(test, func_name, -2, max)

      write_require_multiplication(test, func_name, 1, min)
      write_require_multiplication(test, func_name, -1, min + 1)
      write_require_multiplication_error(test, func_name, -2, min + 1)
      write_require_multiplication_error(test, func_name, -1, min)

      write_require_multiplication_error(test, func_name, min, min)
      write_require_multiplication_error(test, func_name, min, max)

      write_require_multiplication(test, func_name, 10, -(-min / 10))
      write_require_multiplication_error(test, func_name, 10, -(-min / 10) - 1)
      write_require_multiplication_error(test, func_name, 11, -(-min / 10))

      write_require_multiplication(test, func_name, -10, (-min / 10))
      write_require_multiplication_error(test, func_name, -10, (-min / 10) + 1)
      write_require_multiplication_error(test, func_name, -11, (-min / 10))

      write_require_multiplication(test, func_name, -10, -(max / 10))
      write_require_multiplication_error(test, func_name, -10, -(max / 10) - 1)
      write_require_multiplication_error(test, func_name, -11, -(max / 10))
    end
  end
end

def write_math_tests(io)
  FeatureInfo.each do |name, feature|
    next unless feature.fetch(:test)
    op = feature.fetch(:operation)
    if op == :add
      write_addition_test(io, name)
    elsif op == :sub
      write_subtraction_test(io, name)
    elsif op == :mult
      write_multiplication_test(io, name)
    end
  end
end

def write_range_macro_test(io, macro_name)
  macro_info = FeatureInfo.fetch(macro_name.to_sym)
  type1 = macro_info.fetch(:type_dest)
  expected_value = macro_info.fetch(:operation) == :max ? type1.max(io.cenv) : type1.min(io.cenv)
  type2 = type1.byte_count(io.cenv) < 4 ? CType(:INT) : type1
  write_test(io, "test_#{macro_name}") do |test|
    test.puts "#if #{macro_name} != #{cpp_num_str(expected_value)}"
    test.puts %Q{error("#{macro_name} has wrong preprocessor value");}
    extra_tests = [ "#{macro_name} == 0" ]
    if expected_value > -0x8000_0000_0000_0000
      extra_tests << "#{macro_name} == #{cpp_num_str(expected_value - 1)}"
    end
    if expected_value < 0xFFFF_FFFF_FFFF_FFFF
      extra_tests << "#{macro_name} == #{cpp_num_str(expected_value + 1)}"
    end
    test.puts "#elif " + extra_tests.join(" || ")
    test.puts %Q{error("#{macro_name} test confuses the preprocessor");}
    test.puts "#endif"
    test.puts "#{type2.name} expected = #{nice_num_str(expected_value)};"
    test.puts "if (#{macro_name} != expected)"
    test.puts_indent %Q{error("#{macro_name} has wrong value");}
    test.puts "#ifdef __cplusplus"
    test.puts "if (!std::is_same<decltype(#{macro_name} + 0), #{type2.name}>::value)"
    test.puts "#elif defined(__GNUC__)"
    test.puts "if (!_Generic(#{macro_name}, #{type2.name}: 1, default: 0))"
    test.puts "#else"
    test.puts "if (0)"
    test.puts "#endif"
    test.puts_indent %Q{error("#{macro_name} has wrong type");}
  end
end

def write_range_macro_tests(io)
  FeatureInfo.each_value do |feature|
    next unless feature.fetch(:test) && [:min, :max].include?(feature.fetch(:operation))
    write_range_macro_test(io, feature.fetch(:name))
  end
end

def write_tests(io)
  write_type_tests(io)
  write_conversion_tests(io)
  write_math_tests(io)
  write_range_macro_tests(io)
end

def find_redefinitions(intsafe_code)
  if !intsafe_code.include?('__MINGW_INTSAFE')
    # We don't understand the coding of this header enough to find redifintions.
    return
  end

  line_number = 0
  defs = Set.new
  redefs = Set.new
  filtered_lines = []
  intsafe_code.each_line do |line|
    line_number += 1
    reject_line = false
    if (line.match(/#define ([0-9A-Za-z_]+)\b/) \
      || line.match(/API.+\b__MINGW_INTSAFE_[A-Z_]+\(([0-9A-Za-z_]+),/)) \
      && !$1.start_with?('_') \
      && !['S_OK', 'INTSAFE_E_ARITHMETIC_OVERFLOW'].include?($1) \
      && !$1.end_with?('_MIN') \
      && !$1.end_with?('_MAX')
      name = $1
      if defs.include?(name)
        puts "Function #{name} gets redefined on line #{line_number}!"
        redefs << name
        reject_line = true
      else
        defs << name
        feature = FeatureInfo[name.to_sym]
        if feature
          raise 'assertion failed' if !feature.fetch(:test)
        else
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

def init_feature_info(intsafe_code)
  CTypeTable.each_value do |type|
    type_name = type.name
    type_name = '_SIZE_T' if type_name == :SIZE_T
    [:min, :max].each do |operation|
      next if operation == :min && !type.always_signed?
      name = "#{type_name.upcase}_#{operation.to_s.upcase}".to_sym
      FeatureInfo[name] = { name: name, operation: operation, type_dest: type }
    end
  end

  CTypeTable.each_value do |type_src|
    CTypeTable.each_value do |type_dest|
      next if type_src == type_dest
      name = "#{type_src.camel_name}To#{type_dest.camel_name}".to_sym
      FeatureInfo[name] = {
        name: name,
        operation: :convert,
        type_src: type_src,
        type_dest: type_dest,
      }
    end
  end

  CTypeTable.each_value do |type|
    add_sym = "#{type.camel_name}Add".to_sym
    sub_sym = "#{type.camel_name}Sub".to_sym
    mult_sym = "#{type.camel_name}Mult".to_sym
    FeatureInfo[add_sym] = {
      name: add_sym,
      operation: :add,
      type_dest: type,
    }
    FeatureInfo[sub_sym] = {
      name: sub_sym,
      operation: :sub,
      type_dest: type,
    }
    FeatureInfo[mult_sym] = {
      name: mult_sym,
      operation: :mult,
      type_dest: type,
    }
  end

  intsafe_names = Set.new(intsafe_code.scan(/\b[0-9A-Za-z_]+\b/))
  msft_feature_names = Set.new(File.readlines('../feature_names.txt').map(&:strip).reject(&:empty?))

  msft_feature_names.each do |name|
    next if FeatureInfo.has_key?(name.to_sym)
    puts "warning: unrecognized name in feature_names.txt: #{name}"
  end

  FeatureInfo.each_value do |feature|
    name = feature.fetch(:name).to_s
    in_ours = intsafe_names.include?(name)
    in_msft = msft_feature_names.include?(name)
    feature[:test] = in_ours
    if in_msft && !in_ours
      puts "warning: missing function will not be tested: #{name}"
    end
    if !in_msft && in_ours
      puts "warning: intsafe.h has extra function: #{name}"
    end
  end
end

intsafe_code = File.read('intsafe.h')
init_feature_info(intsafe_code)
find_redefinitions(intsafe_code)

File.open('generated.cpp', 'w') do |io|
  io = IndentedIO.new(io)

  io.puts "#ifdef _WIN64"

  io.puts "#ifdef __CHAR_UNSIGNED__"
  io.cenv = { pointer_size: 8, char_signed: false }
  write_tests io
  io.puts "#else /* __CHAR_UNSIGNED__ */"
  io.cenv = { pointer_size: 8, char_signed: true }
  write_tests io
  io.puts "#endif /* __CHAR_UNSIGNED__ else */"

  io.puts "#else /* _WIN64 */"

  io.puts "#ifdef __CHAR_UNSIGNED__"
  io.cenv = { pointer_size: 4, char_signed: false }
  write_tests io
  io.puts "#else /* __CHAR_UNSIGNED__ */"
  io.cenv = { pointer_size: 4, char_signed: true }
  write_tests io
  io.puts "#endif /* __CHAR_UNSIGNED__ else */"

  io.puts "#endif /* _WIN64 else */"

  write_static_void_func(io, "run_all_tests") do |io|
    CTypeTable.each_value do |type|
      io.puts "test_type_#{type}();"
    end
    FeatureInfo.each_value do |feature|
      next unless feature.fetch(:test)
      name = feature.fetch(:name)
      io.puts "test_#{name}();"
    end
  end
end
