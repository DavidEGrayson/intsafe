#include <intsafe.h>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("should include specstrings.h")
{
    #ifndef __specstrings
    REQUIRE(0);
    #endif
}
