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
#undef INT8_MIN
#undef INT16_MIN
#undef INT_MIN
#undef INT_MAX
#undef UINT_MAX
#undef LONG_MIN
#undef LONG_MAX
#undef ULONG_MAX
#include "intsafe.h"

#elif INCLUDE_STYLE == 1
// Make sure intsafe.h can go first without errors.
// Also include the compiler's headers, which override some range macros from intsafe.h
#include "intsafe.h"
#if __cplusplus
#include <type_traits>
#endif
#include <limits.h>
#include <stdint.h>

#endif

#define INITIAL_VALUE 78

size_t error_count;

static void error(const char * format, ...) __attribute__((format (printf, 1, 2)));

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
