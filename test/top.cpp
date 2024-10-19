#include "intsafe.h"
#include <wtypesbase.h>

#if __cplusplus
#include <type_traits>
#endif

#define INITIAL_VALUE 78

static void error(const char * format, ...) __attribute__((format (printf, 1, 2)));
