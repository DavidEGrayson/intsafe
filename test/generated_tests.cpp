#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

#define INITIAL_VALUE 78

TEST_CASE("DWORD is the same as uint32_t")
{
    REQUIRE(sizeof(DWORD) == 4);
    DWORD x = 0;
    REQUIRE((DWORD)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<DWORD>::value);
}

TEST_CASE("DWORD_PTR is the same as uint64_t")
{
    REQUIRE(sizeof(DWORD_PTR) == 8);
    DWORD_PTR x = 0;
    REQUIRE((DWORD_PTR)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<DWORD_PTR>::value);
}

TEST_CASE("INT is the same as int32_t")
{
    REQUIRE(sizeof(INT) == 4);
    INT x = 0;
    REQUIRE((INT)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<INT>::value);
}

TEST_CASE("INT64 is the same as int64_t")
{
    REQUIRE(sizeof(INT64) == 8);
    INT64 x = 0;
    REQUIRE((INT64)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<INT64>::value);
}

TEST_CASE("INT_PTR is the same as int64_t")
{
    REQUIRE(sizeof(INT_PTR) == 8);
    INT_PTR x = 0;
    REQUIRE((INT_PTR)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<INT_PTR>::value);
}

TEST_CASE("LONG is the same as int32_t")
{
    REQUIRE(sizeof(LONG) == 4);
    LONG x = 0;
    REQUIRE((LONG)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<LONG>::value);
}

TEST_CASE("LONG_PTR is the same as int64_t")
{
    REQUIRE(sizeof(LONG_PTR) == 8);
    LONG_PTR x = 0;
    REQUIRE((LONG_PTR)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<LONG_PTR>::value);
}

TEST_CASE("ptrdiff_t is the same as int64_t")
{
    REQUIRE(sizeof(ptrdiff_t) == 8);
    ptrdiff_t x = 0;
    REQUIRE((ptrdiff_t)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<ptrdiff_t>::value);
}

TEST_CASE("SSIZE_T is the same as int64_t")
{
    REQUIRE(sizeof(SSIZE_T) == 8);
    SSIZE_T x = 0;
    REQUIRE((SSIZE_T)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<SSIZE_T>::value);
}

TEST_CASE("UINT is the same as uint32_t")
{
    REQUIRE(sizeof(UINT) == 4);
    UINT x = 0;
    REQUIRE((UINT)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<UINT>::value);
}

TEST_CASE("UINT_PTR is the same as uint64_t")
{
    REQUIRE(sizeof(UINT_PTR) == 8);
    UINT_PTR x = 0;
    REQUIRE((UINT_PTR)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<UINT_PTR>::value);
}

TEST_CASE("ULONG is the same as uint32_t")
{
    REQUIRE(sizeof(ULONG) == 4);
    ULONG x = 0;
    REQUIRE((ULONG)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<ULONG>::value);
}

TEST_CASE("BYTE is the same as uint8_t")
{
    REQUIRE(sizeof(BYTE) == 1);
    BYTE x = 0;
    REQUIRE((BYTE)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<BYTE>::value);
}

TEST_CASE("CHAR is the same as int8_t")
{
    REQUIRE(sizeof(CHAR) == 1);
    CHAR x = 0;
    REQUIRE((CHAR)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<CHAR>::value);
}

TEST_CASE("SHORT is the same as int16_t")
{
    REQUIRE(sizeof(SHORT) == 2);
    SHORT x = 0;
    REQUIRE((SHORT)(x - 1) < x);
    REQUIRE_FALSE(std::is_pointer<SHORT>::value);
}

TEST_CASE("UCHAR is the same as uint8_t")
{
    REQUIRE(sizeof(UCHAR) == 1);
    UCHAR x = 0;
    REQUIRE((UCHAR)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<UCHAR>::value);
}

TEST_CASE("USHORT is the same as uint16_t")
{
    REQUIRE(sizeof(USHORT) == 2);
    USHORT x = 0;
    REQUIRE((USHORT)(x - 1) > x);
    REQUIRE_FALSE(std::is_pointer<USHORT>::value);
}

TEST_CASE("DWordToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToInt), HRESULT (*)(_In_ DWORD, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToInt(0x80000000, &out));
    }

}

TEST_CASE("DWordToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToIntPtr), HRESULT (*)(_In_ DWORD, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToIntPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToLong), HRESULT (*)(_In_ DWORD, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToLong(0x80000000, &out));
    }

}

TEST_CASE("DWordToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToLongPtr), HRESULT (*)(_In_ DWORD, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToLongPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToPtrdiffT), HRESULT (*)(_In_ DWORD, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToPtrdiffT(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToSSIZET), HRESULT (*)(_In_ DWORD, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToSSIZET(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToUInt), HRESULT (*)(_In_ DWORD, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToUIntPtr), HRESULT (*)(_In_ DWORD, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToUIntPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("DWordToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToByte), HRESULT (*)(_In_ DWORD, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToByte(0x100, &out));
    }

}

TEST_CASE("DWordToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToChar), HRESULT (*)(_In_ DWORD, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToChar(0x80, &out));
    }

}

TEST_CASE("DWordToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToShort), HRESULT (*)(_In_ DWORD, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToShort(0x8000, &out));
    }

}

TEST_CASE("DWordToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToUChar), HRESULT (*)(_In_ DWORD, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToUChar(0x100, &out));
    }

}

TEST_CASE("DWordToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordToUShort), HRESULT (*)(_In_ DWORD, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordToUShort(0xffff, &out));
        REQUIRE(out == 0xffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordToUShort(0x10000, &out));
    }

}

TEST_CASE("DWordPtrToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToDWord(0x100000000, &out));
    }

}

TEST_CASE("DWordPtrToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToInt(0x80000000, &out));
    }

}

TEST_CASE("DWordPtrToInt64")
{
    INT64 out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToInt64), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT64 *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToInt64(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToInt64(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToInt64(0x8000000000000000, &out));
    }

}

TEST_CASE("DWordPtrToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToIntPtr(0x8000000000000000, &out));
    }

}

TEST_CASE("DWordPtrToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToLong), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToLong(0x80000000, &out));
    }

}

TEST_CASE("DWordPtrToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToLongPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToLongPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToLongPtr(0x8000000000000000, &out));
    }

}

TEST_CASE("DWordPtrToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToPtrdiffT), HRESULT (*)(_In_ DWORD_PTR, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToPtrdiffT(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToPtrdiffT(0x8000000000000000, &out));
    }

}

TEST_CASE("DWordPtrToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToSSIZET), HRESULT (*)(_In_ DWORD_PTR, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToSSIZET(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToSSIZET(0x8000000000000000, &out));
    }

}

TEST_CASE("DWordPtrToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToUInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToUInt(0x100000000, &out));
    }

}

TEST_CASE("DWordPtrToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToUIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToUIntPtr(0xffffffffffffffff, &out));
        REQUIRE(out == 0xffffffffffffffff);
    }

}

TEST_CASE("DWordPtrToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&DWordPtrToULong), HRESULT (*)(_In_ DWORD_PTR, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(DWordPtrToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(DWordPtrToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == DWordPtrToULong(0x100000000, &out));
    }

}

TEST_CASE("IntToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToDWord), HRESULT (*)(_In_ INT, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToDWord(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToDWord(-0x1LL, &out));
    }

}

TEST_CASE("IntToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToDWordPtr), HRESULT (*)(_In_ INT, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToDWordPtr(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("IntToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToUInt), HRESULT (*)(_In_ INT, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToUInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUInt(-0x1LL, &out));
    }

}

TEST_CASE("IntToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToUIntPtr), HRESULT (*)(_In_ INT, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToUIntPtr(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("IntToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToULong), HRESULT (*)(_In_ INT, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToULong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToULong(-0x1LL, &out));
    }

}

TEST_CASE("IntToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToByte), HRESULT (*)(_In_ INT, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToByte(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToByte(-0x1LL, &out));
    }

}

TEST_CASE("IntToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToChar), HRESULT (*)(_In_ INT, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(IntToChar(-0x80LL, &out));
        REQUIRE(out == -0x80LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToChar(0x80, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToChar(-0x81LL, &out));
    }

}

TEST_CASE("IntToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToShort), HRESULT (*)(_In_ INT, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(IntToShort(-0x8000LL, &out));
        REQUIRE(out == -0x8000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToShort(0x8000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToShort(-0x8001LL, &out));
    }

}

TEST_CASE("IntToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToUChar), HRESULT (*)(_In_ INT, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUChar(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUChar(-0x1LL, &out));
    }

}

TEST_CASE("IntToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntToUShort), HRESULT (*)(_In_ INT, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntToUShort(0xffff, &out));
        REQUIRE(out == 0xffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUShort(0x10000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntToUShort(-0x1LL, &out));
    }

}

TEST_CASE("Int64ToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToDWord), HRESULT (*)(_In_ INT64, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToDWord(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToDWord(-0x1LL, &out));
    }

}

TEST_CASE("Int64ToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToDWordPtr), HRESULT (*)(_In_ INT64, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToDWordPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("Int64ToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToInt), HRESULT (*)(_In_ INT64, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToInt(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToInt(-0x80000001LL, &out));
    }

}

TEST_CASE("Int64ToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToIntPtr), HRESULT (*)(_In_ INT64, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToIntPtr(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("Int64ToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToLong), HRESULT (*)(_In_ INT64, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToLong(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToLong(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToLong(-0x80000001LL, &out));
    }

}

TEST_CASE("Int64ToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToLongPtr), HRESULT (*)(_In_ INT64, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToLongPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToLongPtr(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("Int64ToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToPtrdiffT), HRESULT (*)(_In_ INT64, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToPtrdiffT(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToPtrdiffT(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("Int64ToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToSSIZET), HRESULT (*)(_In_ INT64, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToSSIZET(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(Int64ToSSIZET(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("Int64ToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToUInt), HRESULT (*)(_In_ INT64, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToUInt(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToUInt(-0x1LL, &out));
    }

}

TEST_CASE("Int64ToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToUIntPtr), HRESULT (*)(_In_ INT64, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToUIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("Int64ToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&Int64ToULong), HRESULT (*)(_In_ INT64, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(Int64ToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(Int64ToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToULong(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == Int64ToULong(-0x1LL, &out));
    }

}

TEST_CASE("IntPtrToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToDWord), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToDWord(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToDWord(-0x1LL, &out));
    }

}

TEST_CASE("IntPtrToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToDWordPtr), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToDWordPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("IntPtrToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToInt), HRESULT (*)(_In_ INT_PTR, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(IntPtrToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToInt(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToInt(-0x80000001LL, &out));
    }

}

TEST_CASE("IntPtrToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToLong), HRESULT (*)(_In_ INT_PTR, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(IntPtrToLong(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToLong(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToLong(-0x80000001LL, &out));
    }

}

TEST_CASE("IntPtrToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToUInt), HRESULT (*)(_In_ INT_PTR, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToUInt(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToUInt(-0x1LL, &out));
    }

}

TEST_CASE("IntPtrToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToUIntPtr), HRESULT (*)(_In_ INT_PTR, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToUIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("IntPtrToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&IntPtrToULong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(IntPtrToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(IntPtrToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToULong(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == IntPtrToULong(-0x1LL, &out));
    }

}

TEST_CASE("LongToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToDWord), HRESULT (*)(_In_ LONG, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToDWord(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToDWord(-0x1LL, &out));
    }

}

TEST_CASE("LongToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToDWordPtr), HRESULT (*)(_In_ LONG, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToDWordPtr(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("LongToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToInt), HRESULT (*)(_In_ LONG, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

}

TEST_CASE("LongToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToIntPtr), HRESULT (*)(_In_ LONG, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToIntPtr(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongToIntPtr(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

}

TEST_CASE("LongToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToPtrdiffT), HRESULT (*)(_In_ LONG, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToPtrdiffT(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongToPtrdiffT(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

}

TEST_CASE("LongToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToUInt), HRESULT (*)(_In_ LONG, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToUInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUInt(-0x1LL, &out));
    }

}

TEST_CASE("LongToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToUIntPtr), HRESULT (*)(_In_ LONG, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToUIntPtr(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("LongToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToULong), HRESULT (*)(_In_ LONG, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToULong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToULong(-0x1LL, &out));
    }

}

TEST_CASE("LongToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToByte), HRESULT (*)(_In_ LONG, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToByte(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToByte(-0x1LL, &out));
    }

}

TEST_CASE("LongToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToChar), HRESULT (*)(_In_ LONG, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongToChar(-0x80LL, &out));
        REQUIRE(out == -0x80LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToChar(0x80, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToChar(-0x81LL, &out));
    }

}

TEST_CASE("LongToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToShort), HRESULT (*)(_In_ LONG, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongToShort(-0x8000LL, &out));
        REQUIRE(out == -0x8000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToShort(0x8000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToShort(-0x8001LL, &out));
    }

}

TEST_CASE("LongToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToUChar), HRESULT (*)(_In_ LONG, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUChar(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUChar(-0x1LL, &out));
    }

}

TEST_CASE("LongToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongToUShort), HRESULT (*)(_In_ LONG, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongToUShort(0xffff, &out));
        REQUIRE(out == 0xffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUShort(0x10000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongToUShort(-0x1LL, &out));
    }

}

TEST_CASE("LongPtrToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToDWord), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToDWord(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToDWord(-0x1LL, &out));
    }

}

TEST_CASE("LongPtrToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToDWordPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToDWordPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("LongPtrToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToInt), HRESULT (*)(_In_ LONG_PTR, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongPtrToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToInt(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToInt(-0x80000001LL, &out));
    }

}

TEST_CASE("LongPtrToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongPtrToIntPtr(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("LongPtrToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToLong), HRESULT (*)(_In_ LONG_PTR, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(LongPtrToLong(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToLong(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToLong(-0x80000001LL, &out));
    }

}

TEST_CASE("LongPtrToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToUInt), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToUInt(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToUInt(-0x1LL, &out));
    }

}

TEST_CASE("LongPtrToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToUIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToUIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("LongPtrToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&LongPtrToULong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(LongPtrToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(LongPtrToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToULong(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == LongPtrToULong(-0x1LL, &out));
    }

}

TEST_CASE("PtrdiffTToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToDWord), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToDWord(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToDWord(-0x1LL, &out));
    }

}

TEST_CASE("PtrdiffTToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToDWordPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToDWordPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("PtrdiffTToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(PtrdiffTToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToInt(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToInt(-0x80000001LL, &out));
    }

}

TEST_CASE("PtrdiffTToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToLong), HRESULT (*)(_In_ ptrdiff_t, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(PtrdiffTToLong(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToLong(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToLong(-0x80000001LL, &out));
    }

}

TEST_CASE("PtrdiffTToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToUInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToUInt(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToUInt(-0x1LL, &out));
    }

}

TEST_CASE("PtrdiffTToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToUIntPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToUIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("PtrdiffTToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&PtrdiffTToULong), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(PtrdiffTToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(PtrdiffTToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToULong(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == PtrdiffTToULong(-0x1LL, &out));
    }

}

TEST_CASE("SSIZETToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToDWord), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToDWord(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToDWord(-0x1LL, &out));
    }

}

TEST_CASE("SSIZETToDWordPtr")
{
    DWORD_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToDWordPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToDWordPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToDWordPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToDWordPtr(-0x1LL, &out));
    }

}

TEST_CASE("SSIZETToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToInt), HRESULT (*)(_In_ SSIZE_T, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(SSIZETToInt(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToInt(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToInt(-0x80000001LL, &out));
    }

}

TEST_CASE("SSIZETToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(SSIZETToIntPtr(-0x8000000000000000LL, &out));
        REQUIRE(out == -0x8000000000000000LL);
    }

}

TEST_CASE("SSIZETToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToLong), HRESULT (*)(_In_ SSIZE_T, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(SSIZETToLong(-0x80000000LL, &out));
        REQUIRE(out == -0x80000000LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToLong(0x80000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToLong(-0x80000001LL, &out));
    }

}

TEST_CASE("SSIZETToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToUInt), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToUInt(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToUInt(-0x1LL, &out));
    }

}

TEST_CASE("SSIZETToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToUIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToUIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToUIntPtr(-0x1LL, &out));
    }

}

TEST_CASE("SSIZETToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&SSIZETToULong), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(SSIZETToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(SSIZETToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToULong(0x100000000, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == SSIZETToULong(-0x1LL, &out));
    }

}

TEST_CASE("UIntToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToInt), HRESULT (*)(_In_ UINT, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToInt(0x80000000, &out));
    }

}

TEST_CASE("UIntToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToIntPtr), HRESULT (*)(_In_ UINT, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToIntPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("UIntToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToLong), HRESULT (*)(_In_ UINT, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToLong(0x80000000, &out));
    }

}

TEST_CASE("UIntToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToLongPtr), HRESULT (*)(_In_ UINT, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToLongPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("UIntToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToPtrdiffT), HRESULT (*)(_In_ UINT, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToPtrdiffT(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("UIntToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToSSIZET), HRESULT (*)(_In_ UINT, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToSSIZET(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("UIntToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToByte), HRESULT (*)(_In_ UINT, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToByte(0x100, &out));
    }

}

TEST_CASE("UIntToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToChar), HRESULT (*)(_In_ UINT, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToChar(0x80, &out));
    }

}

TEST_CASE("UIntToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToShort), HRESULT (*)(_In_ UINT, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToShort(0x8000, &out));
    }

}

TEST_CASE("UIntToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToUChar), HRESULT (*)(_In_ UINT, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToUChar(0x100, &out));
    }

}

TEST_CASE("UIntToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntToUShort), HRESULT (*)(_In_ UINT, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntToUShort(0xffff, &out));
        REQUIRE(out == 0xffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntToUShort(0x10000, &out));
    }

}

TEST_CASE("UIntPtrToDWord")
{
    DWORD out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToDWord), HRESULT (*)(_In_ UINT_PTR, _Out_ DWORD *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToDWord(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToDWord(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToDWord(0x100000000, &out));
    }

}

TEST_CASE("UIntPtrToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToInt), HRESULT (*)(_In_ UINT_PTR, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToInt(0x80000000, &out));
    }

}

TEST_CASE("UIntPtrToInt64")
{
    INT64 out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToInt64), HRESULT (*)(_In_ UINT_PTR, _Out_ INT64 *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToInt64(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToInt64(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToInt64(0x8000000000000000, &out));
    }

}

TEST_CASE("UIntPtrToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToIntPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToIntPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToIntPtr(0x8000000000000000, &out));
    }

}

TEST_CASE("UIntPtrToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToLong), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToLong(0x80000000, &out));
    }

}

TEST_CASE("UIntPtrToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToLongPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToLongPtr(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToLongPtr(0x8000000000000000, &out));
    }

}

TEST_CASE("UIntPtrToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToSSIZET), HRESULT (*)(_In_ UINT_PTR, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToSSIZET(0x7fffffffffffffff, &out));
        REQUIRE(out == 0x7fffffffffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToSSIZET(0x8000000000000000, &out));
    }

}

TEST_CASE("UIntPtrToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToUInt), HRESULT (*)(_In_ UINT_PTR, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToUInt(0x100000000, &out));
    }

}

TEST_CASE("UIntPtrToULong")
{
    ULONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UIntPtrToULong), HRESULT (*)(_In_ UINT_PTR, _Out_ ULONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UIntPtrToULong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UIntPtrToULong(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UIntPtrToULong(0x100000000, &out));
    }

}

TEST_CASE("ULongToInt")
{
    INT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToInt), HRESULT (*)(_In_ ULONG, _Out_ INT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToInt(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToInt(0x80000000, &out));
    }

}

TEST_CASE("ULongToIntPtr")
{
    INT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToIntPtr), HRESULT (*)(_In_ ULONG, _Out_ INT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToIntPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToLong")
{
    LONG out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToLong), HRESULT (*)(_In_ ULONG, _Out_ LONG *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToLong(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToLong(0x7fffffff, &out));
        REQUIRE(out == 0x7fffffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToLong(0x80000000, &out));
    }

}

TEST_CASE("ULongToLongPtr")
{
    LONG_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToLongPtr), HRESULT (*)(_In_ ULONG, _Out_ LONG_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToLongPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToLongPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToPtrdiffT")
{
    ptrdiff_t out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToPtrdiffT), HRESULT (*)(_In_ ULONG, _Out_ ptrdiff_t *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToPtrdiffT(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToPtrdiffT(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToSSIZET")
{
    SSIZE_T out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToSSIZET), HRESULT (*)(_In_ ULONG, _Out_ SSIZE_T *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToSSIZET(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToSSIZET(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToUInt")
{
    UINT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToUInt), HRESULT (*)(_In_ ULONG, _Out_ UINT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToUInt(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToUInt(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToUIntPtr")
{
    UINT_PTR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToUIntPtr), HRESULT (*)(_In_ ULONG, _Out_ UINT_PTR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToUIntPtr(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToUIntPtr(0xffffffff, &out));
        REQUIRE(out == 0xffffffff);
    }

}

TEST_CASE("ULongToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToByte), HRESULT (*)(_In_ ULONG, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToByte(0x100, &out));
    }

}

TEST_CASE("ULongToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToChar), HRESULT (*)(_In_ ULONG, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToChar(0x80, &out));
    }

}

TEST_CASE("ULongToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToShort), HRESULT (*)(_In_ ULONG, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToShort(0x8000, &out));
    }

}

TEST_CASE("ULongToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToUChar), HRESULT (*)(_In_ ULONG, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToUChar(0x100, &out));
    }

}

TEST_CASE("ULongToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ULongToUShort), HRESULT (*)(_In_ ULONG, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ULongToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ULongToUShort(0xffff, &out));
        REQUIRE(out == 0xffff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ULongToUShort(0x10000, &out));
    }

}

TEST_CASE("ShortToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ShortToByte), HRESULT (*)(_In_ SHORT, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ShortToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ShortToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToByte(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToByte(-0x1LL, &out));
    }

}

TEST_CASE("ShortToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ShortToChar), HRESULT (*)(_In_ SHORT, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ShortToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ShortToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("converts the minimum value")
    {
        REQUIRE_FALSE(ShortToChar(-0x80LL, &out));
        REQUIRE(out == -0x80LL);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToChar(0x80, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToChar(-0x81LL, &out));
    }

}

TEST_CASE("ShortToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ShortToUChar), HRESULT (*)(_In_ SHORT, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ShortToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ShortToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToUChar(0x100, &out));
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToUChar(-0x1LL, &out));
    }

}

TEST_CASE("ShortToUShort")
{
    USHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&ShortToUShort), HRESULT (*)(_In_ SHORT, _Out_ USHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(ShortToUShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(ShortToUShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("rejects minimum value - 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == ShortToUShort(-0x1LL, &out));
    }

}

TEST_CASE("UShortToByte")
{
    BYTE out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UShortToByte), HRESULT (*)(_In_ USHORT, _Out_ BYTE *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UShortToByte(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UShortToByte(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UShortToByte(0x100, &out));
    }

}

TEST_CASE("UShortToChar")
{
    CHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UShortToChar), HRESULT (*)(_In_ USHORT, _Out_ CHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UShortToChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UShortToChar(0x7f, &out));
        REQUIRE(out == 0x7f);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UShortToChar(0x80, &out));
    }

}

TEST_CASE("UShortToShort")
{
    SHORT out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UShortToShort), HRESULT (*)(_In_ USHORT, _Out_ SHORT *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UShortToShort(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UShortToShort(0x7fff, &out));
        REQUIRE(out == 0x7fff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UShortToShort(0x8000, &out));
    }

}

TEST_CASE("UShortToUChar")
{
    UCHAR out = INITIAL_VALUE;

    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(&UShortToUChar), HRESULT (*)(_In_ USHORT, _Out_ UCHAR *)>::value));
    }

    SECTION("converts 0 to 0")
    {
        REQUIRE_FALSE(UShortToUChar(0, &out));
        REQUIRE(out == 0);
    }

    SECTION("converts the maximum value")
    {
        REQUIRE_FALSE(UShortToUChar(0xff, &out));
        REQUIRE(out == 0xff);
    }

    SECTION("rejects maximum value + 1")
    {
        REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW  == UShortToUChar(0x100, &out));
    }

}

