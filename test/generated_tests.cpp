#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

#define INITIAL_VALUE 78

TEST_CASE("DWORD is the same as uint32_t")
{
    REQUIRE(sizeof(DWORD) == 4);
    DWORD x = 0;
    REQUIRE(x - 1 > x);
}

TEST_CASE("DWORD_PTR is the same as uint64_t")
{
    REQUIRE(sizeof(DWORD_PTR) == 8);
    DWORD_PTR x = 0;
    REQUIRE(x - 1 > x);
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

