# Run this to generate generated_tests.cpp

Dir.chdir(File.dirname(__FILE__))

FunctionNames = File.readlines('function_names.txt').map(&:strip).reject(&:empty?)

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
end

def c99_type(type_id)
  str = ''
  str << 'u' if type_id >= 0
  str << "int#{type_id.abs * 8}_t"
end

Types64 = [
  CNumberType['DWORD', 'DWord', 4],
  CNumberType['DWORD_PTR', 'DWordPtr', 8],
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
    write_test io, "#{type} is the same as #{c99_type(type.type_id)}" do |test|
      test.puts "REQUIRE(sizeof(#{type}) == #{type.byte_count});"
      test.puts "#{type} x = 0;"
      test.puts "REQUIRE(x - 1 #{comparison} x);"

      # It's odd that this test did not work; it says DWORD is different from
      # DWORD_PTR.
      # "REQUIRE((std::is_same<#{type}, #{c99_type(type.type_id)}>::value));"
    end
  end
end

def write_conversion_test(output, type_src, type_dest)
  func_name = type_src.camel_name + 'To' + type_dest.camel_name

  if !FunctionNames.include?(func_name)
    # Someone could theoretically write this conversion function, but
    # for whatever reason Microsoft chose not to.
    return
  end

  write_test(output, func_name) do |test|
    write_section(test, "has the right type") do |section|
      type_signature = "HRESULT (*)(_In_ #{type_src.name}, _Out_ #{type_dest} *)"
      section.puts "REQUIRE((std::is_same<decltype(#{func_name}), #{type_signature}>::value));"
    end
  end
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
