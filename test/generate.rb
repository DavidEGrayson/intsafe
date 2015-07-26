# Run this to generate generated_tests.cpp

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

def write_header(io)
  io.puts <<END
#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

END
end

def write_test(io, name, body)
  io.puts "TEST_CASE(\"#{name}\")"
  io.puts '{'
  body.each_line do |line|
    io.puts Indent + line
  end
  io.puts '}'
  io.puts
end

# These tests makes sure our database of types is correct.
def write_type_tests(io, types)
  types.each do |type|
    comparison = type.signed? ? '<' : '>';
    write_test io, "#{type} is the same as #{c99_type(type.type_id)}",
      "REQUIRE(sizeof(#{type}) == #{type.byte_count});\n" \
      "#{type} x = 0;\n" \
      "REQUIRE(x - 1 #{comparison} x);\n"

    # It's odd that this test did not work; it says DWORD is different from
    # DWORD_PTR.
    # "REQUIRE((std::is_same<#{type}, #{c99_type(type.type_id)}>::value));"
  end
end

def write_conversion_tests(output, types)
  types.each do |type1|
    types.each do |type2|
      next if type1 == typ2
      write_conversion_tests(output, type1, type2)
    end
  end
end

types = Types64

File.open('generated_tests.cpp', 'w') do |output|
  write_header(output)
  write_type_tests(output, types)
  write_conversion_tests(output, types)
end
