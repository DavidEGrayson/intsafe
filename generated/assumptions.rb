def write_size_assumptions(cenv)
  cenv.puts_ct_assert "1 == sizeof(CHAR)"

  Types.chunk { |s| s.type_id.abs }.each do |size, types|
    if size == PointerSizeDummy
      cenv.puts_ct_assert "sizeof(void *) == 4 || sizeof(void *) == 8"
    end

    types.each do |type|
      size_str = type.type_id.abs.to_s
      size_str = 'sizeof(void *)' if size == PointerSizeDummy
      cenv.puts_ct_assert "#{size_str} == sizeof(#{type})"
    end

    cenv.puts
  end
end

def write_sign_assumptions(cenv)
  cenv.puts "#ifdef __CHAR_UNSIGNED__"
  cenv.puts_ct_assert "(char)-1 > 0"
  cenv.puts "#else"
  cenv.puts_ct_assert "(char)-1 < 0"
  cenv.puts "#endif"

  types_grouped_by_signedness = Types.sort_by { |t| [t.signed? ? 0 : 1, Types.index(t)] }
  types_grouped_by_signedness.each do |type|
    if type.signed?
      cenv.puts_ct_assert "(#{type})-1 < 0"
    else
      cenv.puts_ct_assert "(#{type})-1 > 0"
    end
  end
  cenv.puts
end

def write_limit_assumptions(cenv)
  cenv.puts "#ifdef __CHAR_UNSIGNED__"
  cenv.puts_ct_assert "CHAR_MIN == 0"
  cenv.puts_ct_assert "CHAR_MAX == UINT8_MAX"
  cenv.puts "#else"
  cenv.puts_ct_assert "CHAR_MIN == INT8_MIN"
  cenv.puts_ct_assert "CHAR_MAX == INT8_MAX"
  cenv.puts "#endif"

  tested = []
  Types.each do |type|
    bits = type.type_id.abs * 8
    bits = 'PTR' if bits == PointerSizeDummy * 8
    std_max_name = (type.signed? ? '' : 'U') + "INT#{bits}_MAX"
    std_min_name = (type.signed? ? '' : 'U') + "INT#{bits}_MIN"

    if type.max_str != '_' && !tested.include?(type.max_str)
      tested << type.max_str
      unless std_max_name == type.max_str
        cenv.puts_ct_assert "#{type.max_str} == #{std_max_name}"
      end
    end

    if type.min_str != '_' && type.min_str != 0 && !tested.include?(type.min_str)
      tested << type.max_str
      unless std_min_name == type.min_str
        cenv.puts_ct_assert "#{type.min_str} == #{std_min_name}"
      end

      # We don't really need to assert this; GCC only supports two's
      # complement types according to the section about integers in
      # the manual.
      # cenv.puts_ct_assert "#{type.min_str} == -#{type.max_str} - 1"
    end
  end
  cenv.puts
end

def write_compatibility_assumptions(cenv)
  cenv.puts "#ifndef __cplusplus"
  EquivalentTypes.each do |types|
    types[1...types.size].each do |type|
      cenv.puts_ct_assert "__builtin_types_compatible_p(#{types[0]}, #{type})"
    end
  end
  cenv.puts "#endif"
  cenv.puts
end

def write_type_assumptions(cenv)
  write_size_assumptions(cenv)
  write_sign_assumptions(cenv)
  write_limit_assumptions(cenv)
  write_compatibility_assumptions(cenv)
end
