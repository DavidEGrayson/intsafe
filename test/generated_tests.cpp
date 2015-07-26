#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

#define INITIAL_VALUE 78

TEST_CASE("DWORD is the same as uint32_t")
{
    REQUIRE(sizeof(DWORD) == 4);
    DWORD x = 0;
    REQUIRE(x - 1 > x);
    REQUIRE_FALSE(std::is_pointer<DWORD>::value);
}

TEST_CASE("DWORD_PTR is the same as uint64_t")
{
    REQUIRE(sizeof(DWORD_PTR) == 8);
    DWORD_PTR x = 0;
    REQUIRE(x - 1 > x);
    REQUIRE_FALSE(std::is_pointer<DWORD_PTR>::value);
}

TEST_CASE("INT is the same as int32_t")
{
    REQUIRE(sizeof(INT) == 4);
    INT x = 0;
    REQUIRE(x - 1 < x);
    REQUIRE_FALSE(std::is_pointer<INT>::value);
}

TEST_CASE("INT64 is the same as int64_t")
{
    REQUIRE(sizeof(INT64) == 8);
    INT64 x = 0;
    REQUIRE(x - 1 < x);
    REQUIRE_FALSE(std::is_pointer<INT64>::value);
}

TEST_CASE("INT_PTR is the same as int64_t")
{
    REQUIRE(sizeof(INT_PTR) == 8);
    INT_PTR x = 0;
    REQUIRE(x - 1 < x);
    REQUIRE_FALSE(std::is_pointer<INT_PTR>::value);
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

