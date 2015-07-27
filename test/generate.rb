# Run this to generate generated_tests.cpp
#
# Environment variations to be aware of:
#   language: C or C++
#   architecture: win32 or win64
#   char type: signed or unsigned (-funsigned-char)

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

def generate_types(pointer_size, char_signed)
  char_type = char_signed ? -1 : 1
  [
    CNumberType['UCHAR', 'UChar', 1],
    CNumberType['BYTE', 'Byte', 1],
    CNumberType['CHAR', 'Char', char_type],
    CNumberType['USHORT', 'UShort', 2],
    CNumberType['WORD', 'Word', 2],
    CNumberType['SHORT', 'Short', -2],
    CNumberType['UINT', 'UInt', 4],
    CNumberType['ULONG', 'ULong', 4],
    CNumberType['DWORD', 'DWord', 4],
    CNumberType['INT', 'Int', -4],
    CNumberType['LONG', 'Long', -4],
    CNumberType['ULONGLONG', 'ULongLong', 8],
    CNumberType['INT64', 'Int64', -8],
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
end

def write_require_conversion_error(io, func_name, num)
  num_str = nice_num_str(num)
  io.puts "if(INTSAFE_E_ARITHMETIC_OVERFLOW != #{func_name}(#{num_str}, &out))"
  io.puts_indent %Q{error("#{func_name} did not overflow when given #{num_str}");}
end

def write_conversion_test(io, type_src, type_dest)
  func_name = type_src.camel_name + 'To' + type_dest.camel_name

  if !FunctionNames.include?(func_name)
    # Someone could theoretically write this conversion function, but
    # for whatever reason Microsoft chose not to.
    return nil
  end

  max = [type_src.max, type_dest.max].min
  min = [type_src.min, type_dest.min].max

  output_def = "#{type_dest} out;"

  TestedFunctions << func_name
  write_test(io, "test_#{func_name}") do |test|
    test.puts output_def

    write_section(test, "Make sure it has the right type.") do |sec|
      sec.puts "HRESULT (*tmp)(_In_ #{type_src.name}, _Out_ #{type_dest} *) __attribute__ ((unused)) = &#{func_name};"
      sec.puts "#ifdef __cplusplus"
      type_signature = "HRESULT (*)(_In_ #{type_src.name}, _Out_ #{type_dest} *)"
      sec.puts "if(!std::is_same<decltype(&#{func_name}), #{type_signature}>::value)"
      sec.puts_indent %Q{error("#{func_name} does not have the right signature");}
      sec.puts "#endif"
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

def write_tests(io, types)
  collect_tests(io, 'tests_auto') do |tc|
    tc << write_type_tests(io, types)
    tc << write_conversion_tests(io, types)
  end
end

File.open('generated_tests.cpp', 'w') do |output|
  output.puts File.read('test.cpp')

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

untested_functions = FunctionNames - TestedFunctions
if untested_functions.size > 0
  puts "warning: #{untested_functions.size} functions do not have tests yet, " \
    "for example: #{untested_functions.first}"
end
