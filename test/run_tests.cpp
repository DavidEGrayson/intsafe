#define ENABLE_INTSAFE_SIGNED_FUNCTIONS

#if INCLUDE_STYLE == 0
// Include intsafe.h last and expose all its conditional macro definitions.
#include <limits.h>
#include <stdint.h>
#if __cplusplus
#include <type_traits>
#endif
#include <winapifamily.h>
#include <wtypesbase.h>
#include <specstrings.h>
#include <intsafe_under_test.h>

#elif INCLUDE_STYLE == 1
// Make sure intsafe.h can go first without errors,
// and that the headers provide definitions that pass our test.
#include <intsafe_under_test.h>
#if __cplusplus
#include <type_traits>
#endif
#include <limits.h>
#include <stdint.h>
#include <cfgmgr32.h>

#endif

#if __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

#define INITIAL_VALUE 78

size_t error_count;

static void error(const char * format, ...)
#if __GNUC__
__attribute__((format(printf, 1, 2)))
#endif
;

#if defined(__GNUC__)

// Strict type-checking for GCC and Clang.
#ifdef __cplusplus
#define TYPE_MATCHES(v, t) (std::is_same<decltype(v), t>::value)
#else
#define TYPE_MATCHES(v, t) (_Generic((v), t: 1, default: 0))
#endif

#else

// Weaker type checking for MSVC because the types for UINT8_MAX etc. from
// Microsoft's intsafe.h are not int.  Also MSVC doesn't have _Generic.
#ifdef __cplusplus
#define TYPE_MATCHES(v, t) (std::is_same<decltype((v) + 0), t>::value)
#else
#define TYPE_MATCHES(v, t) 1
#endif

#endif

#include "generated.cpp"

int main(void)
{
    run_all_tests();
    return error_count != 0;
}

#include <stdarg.h>
#include <stdio.h>
void error(const char * format, ...)
{
    error_count++;
    va_list ap;
    va_start(ap, format);
    fprintf(stderr, "error: ");
    vfprintf(stderr, format, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}
