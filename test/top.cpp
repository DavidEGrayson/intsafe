#include "intsafe.h"
#include <wtypesbase.h>

#if __cplusplus
#include <type_traits>
#endif

#define INITIAL_VALUE 78

static void error(const char * format, ...) __attribute__((format (printf, 1, 2)));

static void test_should_include_specstrings()
{
    #ifndef __specstrings
    error("intsafe.h did not include specstrings.h");
    #endif
}

static void test_arithmetic_overflow_value()
{
    // 0x80070216L is used in the coreclr implementation.
    if (INTSAFE_E_ARITHMETIC_OVERFLOW != (HRESULT)0x80070216L)
    {
        error("INTSAFE_E_ARITHMETIC_OVERFLOW value is wrong");
    }
}

static void tests_manual()
{
    test_arithmetic_overflow_value();
    test_should_include_specstrings();
}
