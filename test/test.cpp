TEST_CASE("should include specstrings.h")
{
    #ifndef __specstrings
    REQUIRE(0);
    #endif
}

TEST_CASE("defines the right value for INTSAFE_E_ARITHMETIC_OVERFLOW")
{
    // 0x80070216L is used in the coreclr implementation.
    REQUIRE(INTSAFE_E_ARITHMETIC_OVERFLOW == 0x80070216L);
}
