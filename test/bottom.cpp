int main()
{
    run_all_tests();
    return 0;
}

#include <stdarg.h>
#include <stdio.h>
void error(const char * format, ...)
{
    va_list ap;
    va_start(ap, format);
    fprintf(stderr, "error: ");
    vfprintf(stderr, format, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}
