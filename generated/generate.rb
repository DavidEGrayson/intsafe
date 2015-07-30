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
  cenv.puts "#pragma once"
end

CEnv.write_file('intsafe.h') do |cenv|
  write_top(cenv)
  write_todos_for_missing_functions(cenv)
end
