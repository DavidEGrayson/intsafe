#include <intsafe.h>
#include <wtypesbase.h>
#include <catch.hpp>

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
    SECTION("has the right type")
    {
        REQUIRE((std::is_same<decltype(DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value));
    }

}

