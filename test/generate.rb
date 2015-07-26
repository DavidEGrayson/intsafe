# Run this to generate generated_tests.cpp

Dir.chdir(File.dirname(__FILE__))

FunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)
TestedFunctions = []

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


Types64 = [
  CNumberType['DWORD', 'DWord', 4],
  CNumberType['DWORD_PTR', 'DWordPtr', 8],
  CNumberType['INT', 'Int', -4],
  CNumberType['INT64', 'Int64', -8],
]

Indent = "    "

class IndentedIO
  def initialize(io)
    @io = io
  end

  def puts(*args)
    @io.print Indent unless args.empty?
    @io.puts *args
  end

  def print(*args)
    @io.print *args
  end
end

def write_header(io)
  io.puts <<END
#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

#define INITIAL_VALUE 78

END
end

def write_test(io, name)
  io.puts "TEST_CASE(\"#{name}\")"
  io.puts '{'
  yield IndentedIO.new(io)
  io.puts '}'
  io.puts
end

def write_section(io, name)
  io.puts "SECTION(\"#{name}\")"
  io.puts '{'
  yield IndentedIO.new(io)
  io.puts '}'
  io.puts
end

# These tests makes sure our database of types is correct.
def write_type_tests(io, types)
  types.each do |type|
    comparison = type.signed? ? '<' : '>';
    write_test io, "#{type} is the same as #{type.c99_name}" do |test|
      test.puts "REQUIRE(sizeof(#{type}) == #{type.byte_count});"
      test.puts "#{type} x = 0;"
      test.puts "REQUIRE(x - 1 #{comparison} x);"

      # It's odd that this test did not work; it says DWORD is different from
      # DWORD_PTR.
      # "REQUIRE((std::is_same<#{type}, #{type.c99_name)}>::value));"
    end
  end
end

def nice_num_str(num)
  case
  when num.is_a?(String) then num
  when num < 0 then '-' + nice_num_str(-num) + 'LL'
  else '%#x' % num
  end
end

def write_require_conversion(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "REQUIRE_FALSE(#{func_name}(#{num_str}, &out));"
  io.puts "REQUIRE(out == #{num_str});"
end

def write_require_conversion_error(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == #{func_name}(#{num_str}, &out));"
end

def write_conversion_test(output, type_src, type_dest)
  func_name = type_src.camel_name + 'To' + type_dest.camel_name

  if !FunctionNames.include?(func_name)
    # Someone could theoretically write this conversion function, but
    # for whatever reason Microsoft chose not to.
    return
  end

  max = [type_src.max, type_dest.max].min
  min = [type_src.min, type_dest.min].max

  write_test(output, func_name) do |test|
    test.puts "#{type_dest} out = INITIAL_VALUE;"
    test.puts

    write_section(test, "has the right type") do |section|
      type_signature = "HRESULT (*)(_In_ #{type_src.name}, _Out_ #{type_dest} *)"
      section.puts "REQUIRE((std::is_same<decltype(&#{func_name}), #{type_signature}>::value));"
    end

    write_section(test, "converts 0 to 0") do |section|
      write_require_conversion(section, func_name, 0)
    end

    write_section(test, "converts the maximum value") do |section|
      write_require_conversion(section, func_name, max)
    end

    write_section(test, "converts the minimum value") do |section|
      write_require_conversion(section, func_name, min)
    end if min != 0

    write_section(test, "rejects maximum value + 1") do |section|
      write_require_conversion_error(section, func_name, type_dest.max + 1);
    end if type_src.max > type_dest.max

    write_section(test, "rejects minimum value - 1") do |section|
      write_require_conversion_error(section, func_name, type_dest.min - 1);
    end if type_src.min < type_dest.min
  end

  TestedFunctions << func_name
end

def write_conversion_tests(output, types)
  types.each do |type1|
    types.each do |type2|
      next if type1 == type2
      write_conversion_test(output, type1, type2)
    end
  end
end

types = Types64

File.open('generated_tests.cpp', 'w') do |output|
  write_header(output)
  write_type_tests(output, types)
  write_conversion_tests(output, types)
end

untested_functions = FunctionNames - TestedFunctions
if untested_functions.size > 0
  puts "warning: #{untested_functions.size} functions do not have tests yet"
  puts "  for example: #{untested_functions.first}"
end
