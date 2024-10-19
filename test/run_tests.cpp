#include "intsafe.h"
#include <wtypesbase.h>

#if __cplusplus
#include <type_traits>
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
