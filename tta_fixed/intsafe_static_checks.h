/*
 * intsafe_static_checks.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_INTSAFE_STATIC_CHECKS_H_INCLUDED
#define __MINGW_INTSAFE_STATIC_CHECKS_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#include "intsafe_common.h"

// Do not warn about unused local typedefs in this header because
// they are used to implement static assertions.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"

/**
 * @def __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
 * Defined if some standard constant macro is not defined.
 * @internal
 */
/* integral constant macros' existence check */
#ifndef INT8_C
#   error "INT8_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef INT16_C
#   error "INT16_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef INT32_C
#   error "INT32_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef INT64_C
#   error "INT64_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef UINT8_C
#   error "UINT8_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef UINT16_C
#   error "UINT16_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef UINT32_C
#   error "UINT32_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

#ifndef UINT64_C
#   error "UINT64_C not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS 1
#   endif
#endif

/**
 * @def __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
 * Defined if some standard limit macro is not defined.
 * @internal
 */
/* limit macros' existence check */
#ifndef INT8_MAX
#   error "INT8_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT8_MIN
#   error "INT8_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT16_MAX
#   error "INT16_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT16_MIN
#   error "INT16_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT32_MAX
#   error "INT32_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT32_MIN
#   error "INT32_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT64_MAX
#   error "INT64_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INT64_MIN
#   error "INT64_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INTPTR_MAX
#   error "INTPTR_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef INTPTR_MIN
#   error "INTPTR_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef PTRDIFF_MAX
#   error "PTRDIFF_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef PTRDIFF_MIN
#   error "PTRDIFF_MIN not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef UINT8_MAX
#   error "UINT8_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef UINT16_MAX
#   error "UINT16_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef UINT32_MAX
#   error "UINT32_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef UINT64_MAX
#   error "UINT64_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef SIZE_MAX
#   error "SIZE_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

#ifndef UINTPTR_MAX
#   error "UINTPTR_MAX not defined"
#   ifndef __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS
#       define __MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS 1
#   endif
#endif

/**
 * @def __MINGW_INTSAFE_MISSING_CHAR_BIT
 * This macro is defined if CHAR_BIT is not defined in C++.
 * @internal
 */
#ifdef __cplusplus
#   ifndef CHAR_BIT
#       error "CHAR_BIT not defined"
#       ifndef __MINGW_INTSAFE_MISSING_CHAR_BIT
#           define __MINGW_INTSAFE_MISSING_CHAR_BIT 1
#       endif
#   endif
#endif

#if !defined(__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_CHAR_BIT)

#   ifdef __cplusplus
extern "C" {
#   endif

/* integral type check */
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(int8_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(int16_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(int32_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(int64_t);

__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(uint8_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(uint16_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(uint32_t);
__MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(uint64_t);

/* size check */
#   ifdef __cplusplus
/* In C++, sizeof returns the size of the given type
 * with respect to the size of type char.
 */
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int8_t) * CHAR_BIT == 8,
    int8_t_is_8bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int16_t) * CHAR_BIT == 16,
    int16_t_is_16bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int32_t) * CHAR_BIT == 32,
    int32_t_is_32bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int64_t) * CHAR_BIT == 64,
    int64_t_is_64bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint8_t) * CHAR_BIT == 8,
    uint8_t_is_8bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint16_t) * CHAR_BIT == 16,
    uint16_t_is_16bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint32_t) * CHAR_BIT == 32,
    uint32_t_is_32bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int64_t) * CHAR_BIT == 64,
    uint64_t_is_64bit_integral_type
);
#   else
/* In C, sizeof returns the size of the given type in bytes. */
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int8_t) == 1,
    int8_t_is_8bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int16_t) == 2,
    int16_t_is_16bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int32_t) == 4,
    int32_t_is_32bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(int64_t) == 8,
    int64_t_is_64bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint8_t) == 1,
    uint8_t_is_8bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint16_t) == 2,
    uint16_t_is_16bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint32_t) == 4,
    uint32_t_is_32bit_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    sizeof(uint64_t) == 8,
    uint64_t_is_64bit_integral_type
);
#   endif

/* signed-ness check */
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_SIGNED(int8_t),
    int8_t_is_signed_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_SIGNED(int16_t),
    int16_t_is_signed_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_SIGNED(int32_t),
    int32_t_is_signed_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_SIGNED(int64_t),
    int64_t_is_signed_integral_type
);

/* unsigned-ness check */
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_UNSIGNED(uint8_t),
    uint8_t_is_unsigned_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_UNSIGNED(uint16_t),
    uint16_t_is_unsigned_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_UNSIGNED(uint32_t),
    uint32_t_is_unsigned_integral_type
);
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_UNSIGNED(uint64_t),
    uint64_t_is_unsigned_integral_type
);

/* standard macros usability check */
__MINGW_INTSAFE_STATIC_ASSERT(
    INT8_MAX == INT8_C(127) &&
    INT8_MIN == -INT8_C(127) - 1,
    INT8_MAX_and_INT8_MIN_and_INT8_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    INT16_MAX == INT16_C(32767) &&
    INT16_MIN == -INT16_C(32767) - 1,
    INT16_MAX_and_INT16_MIN_and_INT16_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    INT32_MAX == INT32_C(2147483647) &&
    INT32_MIN == -INT32_C(2147483647) - 1,
    INT32_MAX_and_INT32_MIN_and_INT32_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    INT64_MAX == INT64_C(9223372036854775807) &&
    INT64_MIN == -INT64_C(9223372036854775807) - 1,
    INT64_MAX_and_INT64_MIN_and_INT64_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    UINT8_MAX == UINT8_C(255),
    UINT8_MAX_and_UINT8_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    UINT16_MAX == UINT16_C(65535),
    UINT16_MAX_and_UINT16_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    UINT32_MAX == UINT32_C(0xFFFFFFFF),
    UINT32_MAX_and_UINT32_C_must_be_set_correctly
);
__MINGW_INTSAFE_STATIC_ASSERT(
    UINT64_MAX == UINT64_C(0xFFFFFFFFFFFFFFFF),
    UINT64_MAX_and_UINT64_C_must_be_set_correctly
);

/* size_t check */
/**
 * @def __MINGW_INTSAFE_SIZE_T_IS_UINT64_T
 * This macro is defined if size_t is uint64_t.
 * @internal
 */

/**
 * @def __MINGW_INTSAFE_SIZE_T_IS_UINT32_T
 * This macro is defined if size_t is uint32_t.
 * @internal
 */
#   if SIZE_MAX == UINT64_MAX
#       define __MINGW_INTSAFE_SIZE_T_IS_UINT64_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(size_t, uint64_t),
    size_t_must_be_compatible_with_uint64_t
);
#   elif SIZE_MAX == UINT32_MAX
#       define __MINGW_INTSAFE_SIZE_T_IS_UINT32_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(size_t, uint32_t),
    size_t_must_be_compatible_with_uint32_t
);
#   else
#       error "size_t is neither uint32_t nor uint64_t, or"
#       error "SIZE_MAX has wrong value, or"
#       error "UINT64_MAX has wrong value, or"
#       error "UINT32_MAX has wrong value."
#   endif

/* ptrdiff_t check */
/**
 * @def __MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T
 * This macro is defined if ptrdiff_t is int64_t.
 * @internal
 */

/**
 * @def __MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T
 * This macro is defined if ptrdiff_t is int32_t.
 * @internal
 */
#   if (PTRDIFF_MAX == INT64_MAX) && \
        (PTRDIFF_MIN == INT64_MIN)
#       define __MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(ptrdiff_t, int64_t),
    ptrdiff_t_must_be_compatible_with_int64_t
);
#   elif (PTRDIFF_MAX == INT32_MAX) && \
        (PTRDIFF_MIN == INT32_MIN)
#       define __MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(ptrdiff_t, int32_t),
    ptrdiff_t_must_be_compatible_with_int32_t
);
#   else
#       error "ptrdiff_t is neither int32_t nor int64_t, or"
#       error "PTRDIFF_MAX and PTRDIFF_MIN have wrong values, or"
#       error "UINT64_MAX and UINT64_MIN have wrong values, or"
#       error "UINT32_MAX and UINT32_MIN have wrong values."
#   endif

/* intptr_t check */
/**
 * @def __MINGW_INTSAFE_INTPTR_T_IS_INT64_T
 * This macro is defined if intptr_t is int64_t.
 * @internal
 */

/**
 * @def __MINGW_INTSAFE_INTPTR_T_IS_INT32_T
 * This macro is defined if intptr_t is int32_t.
 * @internal
 */
#   if (INTPTR_MAX == INT64_MAX) && \
        (INTPTR_MIN == INT64_MIN)
#       define __MINGW_INTSAFE_INTPTR_T_IS_INT64_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(intptr_t, int64_t),
    intptr_t_must_be_compatible_with_int64_t
);
#   elif (INTPTR_MAX == INT32_MAX) && \
        (INTPTR_MIN == INT32_MIN)
#       define __MINGW_INTSAFE_INTPTR_T_IS_INT32_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(intptr_t, int32_t),
    intptr_t_must_be_compatible_with_int32_t
);
#   else
#       error "intptr_t is neither int32_t nor int64_t, or"
#       error "INTPTR_MAX and INTPTR_MIN have wrong values, or"
#       error "INT64_MAX and INT64_MIN have wrong values, or"
#       error "INT32_MAX and INT32_MIN have wrong values."
#   endif

/* uintptr_t check */
/**
 * @def __MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T
 * This macro is defined if uintptr_t is uint64_t.
 * @internal
 */

/**
 * @def __MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T
 * This macro is defined if uintptr_t is uint32_t.
 * @internal
 */
#   if (UINTPTR_MAX == UINT64_MAX)
#       define __MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(uintptr_t, uint64_t),
    uintptr_t_must_be_compatible_with_uint64_t
);
#   elif (UINTPTR_MAX == UINT32_MAX)
#       define __MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T 1
__MINGW_INTSAFE_STATIC_ASSERT(
    __MINGW_INTSAFE_IS_COMPATIBLE(uintptr_t, uint32_t),
    uintptr_t_must_be_compatible_with_uint32_t
);
#   else
#       error "uintptr_t is neither uint64_t nor uint32_t, or"
#       error "UINTPTR_MAX has wrong value, or"
#       error "UINT64_MAX has wrong value, or"
#       error "UINT32_MAX has wrong value."
#   endif

/**
 * @def __MINGW_INTSAFE_RUN_PLATFORM_DEPENDENT_INTEGRAL_TYPES_TESTSUITE
 * A facility for determining whether the test suite for platform dependent
 * integral types should be run.
 * @note Only Win32/Win64 platforms are supported.
 * @internal
 */

/**
 * @def __MINGW_INTSAFE_RUN_WINDOWS_H_INTEGRAL_TYPEDEFS_TESTSUITE
 * A factility for determining whether the test suite for windows.h header's
 * integral typedefs should be run.
 * @note This test suite runs if and only if:
 * - "#include <windows.h>" comes before "#include <intsafe.h>".
 * - Target platform is Win32 or Win64.
 * @internal
 */

/* windows.h's guard:
 * _INC_WINDOWS = mingw-w64 SDK
 * _WINDOWS_ = mingw-w64 SDK
 * _WINDOWS_H = mingw.org SDK / Cygwin SDK
 * ? = Wine SDK
 * ? = MS PSDK
 * ? = ? SDK
 */
#   if defined(_WIN32)
#       define __MINGW_INTSAFE_RUN_PLATFORM_DEPENDENT_INTEGRAL_TYPES_TESTSUITE 1
#       if defined(_INC_WINDOWS) || /* mingw-w64 SDK */ \
            defined(_WINDOWS_) || /* mingw-w64 SDK */ \
            defined(_WINDOWS_H) /* mingw.org/Cygwin SDKs */
#           define __MINGW_INTSAFE_RUN_WINDOWS_H_INTEGRAL_TYPEDEFS_TESTSUITE 1
#       endif
#   endif

/* Determine whether X has expected size and [un]signed-ness on Win32/64 */
#	if defined(__MINGW_INTSAFE_RUN_PLATFORM_DEPENDENT_INTEGRAL_TYPES_TESTSUITE)

#       define __MINGW_INTSAFE_MASTER_TESTSUITE(X) \
        __MINGW_INTSAFE_DEPRECATED(X) \
        __MINGW_INTSAFEAPI_INLINE void \
        __MINGW_INTSAFEAPI_ALWAYS_INLINE \
        __MINGW_INTSAFE_platform_dependent_integral_types_testsuite(void)

#       define __MINGW_INTSAFE_TESTSUITE(X) /**/

#       define __MINGW_INTSAFE_TESTCASE(PlatformDependent_T, Std_T) \
        __MINGW_INTSAFE_STATIC_ASSERT( \
            __MINGW_INTSAFE_IS_COMPATIBLE(PlatformDependent_T, Std_T), \
            __MINGW_INTSAFE_JOIN( \
                PlatformDependent_T, \
                __MINGW_INTSAFE_JOIN( \
                    _must_be_compatible_with_, \
                    Std_T \
                ) \
            ) \
        )

/* There should not be any failure here */
__MINGW_INTSAFE_MASTER_TESTSUITE("Platform Dependent Integral Types")
{
    __MINGW_INTSAFE_TESTSUITE("Signed Integral Types")
    {
        /* local typedefs to deal with the space character */
        typedef signed char signed_char;
        typedef long long long_long;
        __MINGW_INTSAFE_TESTCASE(signed_char, int8_t);
#       if !defined(CHAR_MIN) || (defined(CHAR_MIN) && CHAR_MIN < 0)
        __MINGW_INTSAFE_TESTCASE(char, int8_t);
#       endif
        __MINGW_INTSAFE_TESTCASE(short, int16_t);
        __MINGW_INTSAFE_TESTCASE(int, int32_t);
        __MINGW_INTSAFE_TESTCASE(long, int32_t);
        __MINGW_INTSAFE_TESTCASE(long_long, int64_t);
    }

    __MINGW_INTSAFE_TESTSUITE("Unsigned Integral Types")
    {
        /* local typedefs to deal with the space character */
        typedef unsigned char unsigned_char;
        typedef unsigned short unsigned_short;
        typedef unsigned long unsigned_long;
        typedef unsigned int unsigned_int;
        typedef unsigned long long unsigned_long_long;
        typedef void * pointer_type;
        __MINGW_INTSAFE_TESTCASE(unsigned_char, uint8_t);
#       if defined(CHAR_MIN) && CHAR_MIN == 0
        __MINGW_INTSAFE_TESTCASE(char, uint8_t);
#       endif
        __MINGW_INTSAFE_TESTCASE(unsigned_short, uint16_t);
        __MINGW_INTSAFE_TESTCASE(wchar_t, uint16_t);
        __MINGW_INTSAFE_TESTCASE(unsigned_int, uint32_t);
        __MINGW_INTSAFE_TESTCASE(unsigned_long, uint32_t);
        __MINGW_INTSAFE_TESTCASE(unsigned_long_long, uint64_t);
        __MINGW_INTSAFE_TESTCASE(pointer_type, uintptr_t);
    }
}

#       undef __MINGW_INTSAFE_TESTCASE
#       undef __MINGW_INTSAFE_TESTSUITE
#       undef __MINGW_INTSAFE_MASTER_TESTSUITE
#       undef __MINGW_INTSAFE_RUN_PLATFORM_DEPENDENT_INTEGRAL_TYPES_TESTSUITE

#   endif /* __MINGW_INTSAFE_RUN_PLATFORM_DEPENDENT_INTEGRAL_TYPES_TESTSUITE */

/* Checking Win32 typedefs if windows.h is available, i.e #include <windows.h>
 * comes before #include <intsafe.h>.
 *
 * We avoid including windows.h in intsafe*.h since:
 *
 * - It's a huge header which may slow down compilation.
 * - It has a lot of shitty things like min, max, BOOL, IN, OUT, etc. which
 * pollute the global namespace, and may cause problems with other headers.
 * Even MFC requires including windows.h through the proxy afxwin.h header.
 * - windows.h even conflicts with other Win32 headers depending on the order
 * of inclusion.
 * - Including windows.h in a public or private header prevents users from
 * customizing / optimizing their inclusion of windows.h. This is because to
 * address the "windows.h" problem, MS developers provide several macros
 * which can be used to customizing "#include <windows.h>", e.g:
 * - WIN32_LEAN_AND_MEAN
 * - VC_EXTRALEAN
 * - NOMINMAX
 * - NOSERVICE
 * - NOGDI
 * - etc.
 * (not counting 3rd party macros supported by 3rd party PSDK)
 *
 * The problem here is that, if we define some of them then this will cause
 * problems for users who want to use everything provided by windows.h
 * header. But OTOH, if none of them are defined, then this will make
 * troubles for users who want to disable some stuffs coming from windows.h
 * since such things pollute the global namespace and/or cause naming
 * conflicts. Hence, this is more or less a lose-lose situation which we have
 * to avoid.
 *
 * For short, windows.h itself is already an issue, but including it in a
 * header, which can be used in client code, is even a bigger and
 * unable-to-solve issue, since there is no way to include it properly.
 *
 * In practice, putting "#include <windows.h>" in a header file is always the
 * source of compile errors, and therefore, we should always put
 * "#include <windows.h>" in source files (*.(c|cpp|cxx|cc)) only.
 */
#   if defined(__MINGW_INTSAFE_RUN_WINDOWS_H_INTEGRAL_TYPEDEFS_TESTSUITE)
/* We map MS functions, e.g MSXToMSY, to our own functions, e.g MinGWXToMinGWY,
 * instead of implementing MS functions directly and hard-codedly.
 *
 * This approach allows us not only to avoid including the problematic windows.h
 * but also to adapt any change MS makes on their side with relative ease.
 * For e.g, if MS changes Foo from 32bit integral type to 64bit one for some
 * reason, all we need to do to keep MS compatibility, is to map FooToXXXX
 * to Int64ToXXXX instead of the old Int32ToXXXX. And if MS removes or adds
 * XToY, then we will remove the corresponding mapping of XToY, or add a
 * new mapping for XToY in response. That's simple, easy, flexible and
 * extensible.
 *
 * By insisting on using standard exact-width integral types and
 * function-to-function mappings, we can keep our implementation independent
 * with MS implementation while not breaking MS compatibility. Thus, changes on
 * MS side do not affect anything on our side (except some mappings in
 * intsafe_mscompat.h may be removed or modified, or new ones may be added
 * to that header).
 *
 * Mapping DWordToByte to UInt32ToUInt8 is error-free if and only if DWORD and
 * BYTE are compatible with uint32_t and uint8_t respectively. Because of this,
 * we need to do some type compatibility tests.
 */
#       define __MINGW_INTSAFE_MASTER_TESTSUITE(X) \
        __MINGW_INTSAFE_DEPRECATED(X) \
        __MINGW_INTSAFEAPI_INLINE void \
        __MINGW_INTSAFEAPI_ALWAYS_INLINE \
        __MINGW_INTSAFE_mapping_w32int_to_stdint_testsuite(void)

#       define __MINGW_INTSAFE_TESTSUITE(X) /**/

#       define __MINGW_INTSAFE_TESTCASE(Win32_T, Std_T) \
        __MINGW_INTSAFE_STATIC_ASSERT( \
            __MINGW_INTSAFE_IS_COMPATIBLE(Win32_T, Std_T), \
            __MINGW_INTSAFE_JOIN( \
                Win32_T, \
                __MINGW_INTSAFE_JOIN( \
                    _must_be_compatible_with_, \
                    Std_T \
                ) \
            ) \
        )

/* There should not be any failure here */
__MINGW_INTSAFE_MASTER_TESTSUITE("Mapping Win32 Types To Standard Types")
{
    __MINGW_INTSAFE_TESTSUITE("8Bit Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(BOOLEAN);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(BYTE);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UCHAR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT8);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT8);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(CHAR);

        __MINGW_INTSAFE_TESTCASE(BOOLEAN, uint8_t);
        __MINGW_INTSAFE_TESTCASE(BYTE, uint8_t);
        __MINGW_INTSAFE_TESTCASE(UCHAR, uint8_t);
        __MINGW_INTSAFE_TESTCASE(UINT8, uint8_t);
        __MINGW_INTSAFE_TESTCASE(INT8, int8_t);
#       if defined(CHAR_MIN) && CHAR_MIN == 0
        __MINGW_INTSAFE_TESTCASE(CHAR, uint8_t);
#       else
        __MINGW_INTSAFE_TESTCASE(CHAR, int8_t);
#       endif
    }

    __MINGW_INTSAFE_TESTSUITE("16Bit Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ATOM);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(USHORT);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT16);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(WORD);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(SHORT);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT16);

        __MINGW_INTSAFE_TESTCASE(ATOM, uint16_t);
        __MINGW_INTSAFE_TESTCASE(USHORT, uint16_t);
        __MINGW_INTSAFE_TESTCASE(UINT16, uint16_t);
        __MINGW_INTSAFE_TESTCASE(WORD, uint16_t);
        __MINGW_INTSAFE_TESTCASE(SHORT, int16_t);
        __MINGW_INTSAFE_TESTCASE(INT16, int16_t);
    }

    __MINGW_INTSAFE_TESTSUITE("32Bit Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(COLORREF);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(DWORD);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(DWORD32);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ULONG);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ULONG32);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT32);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(BOOL);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LONG);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LONG32);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT32);

        __MINGW_INTSAFE_TESTCASE(COLORREF, uint32_t);
        __MINGW_INTSAFE_TESTCASE(DWORD, uint32_t);
        __MINGW_INTSAFE_TESTCASE(DWORD32, uint32_t);
        __MINGW_INTSAFE_TESTCASE(ULONG, uint32_t);
        __MINGW_INTSAFE_TESTCASE(ULONG32, uint32_t);
        __MINGW_INTSAFE_TESTCASE(UINT, uint32_t);
        __MINGW_INTSAFE_TESTCASE(UINT32, uint32_t);
        __MINGW_INTSAFE_TESTCASE(BOOL, int32_t);
        __MINGW_INTSAFE_TESTCASE(LONG, int32_t);
        __MINGW_INTSAFE_TESTCASE(LONG32, int32_t);
        __MINGW_INTSAFE_TESTCASE(INT, int32_t);
        __MINGW_INTSAFE_TESTCASE(INT32, int32_t);
    }

    __MINGW_INTSAFE_TESTSUITE("64Bit Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(DWORD64);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(DWORDLONG);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT64);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ULONGLONG);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ULONG64);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT64);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LONG64);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LONGLONG);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(USN);

        __MINGW_INTSAFE_TESTCASE(DWORD64, uint64_t);
        __MINGW_INTSAFE_TESTCASE(DWORDLONG, uint64_t);
        __MINGW_INTSAFE_TESTCASE(UINT64, uint64_t);
        __MINGW_INTSAFE_TESTCASE(ULONGLONG, uint64_t);
        __MINGW_INTSAFE_TESTCASE(ULONG64, uint64_t);
        __MINGW_INTSAFE_TESTCASE(INT64, int64_t);
        __MINGW_INTSAFE_TESTCASE(LONG64, int64_t);
        __MINGW_INTSAFE_TESTCASE(LONGLONG, int64_t);
        __MINGW_INTSAFE_TESTCASE(USN, int64_t);
    }

    __MINGW_INTSAFE_TESTSUITE("128Bit Integral Types")
    {
#       if __MINGW_GNUC_PREREQ (4, 6)
        /* currently, there' s nothing here */
        /* __MINGW_INTSAFE_TESTCASE(?, __int128) */
#       endif
    }

    __MINGW_INTSAFE_TESTSUITE("Pointer-Value-Holding Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(DWORD_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UINT_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(ULONG_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(WPARAM);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(UHALF_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(INT_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LONG_PTR);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(LPARAM);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(HALF_PTR);

        __MINGW_INTSAFE_TESTCASE(DWORD_PTR, uintptr_t);
        __MINGW_INTSAFE_TESTCASE(UINT_PTR, uintptr_t);
        __MINGW_INTSAFE_TESTCASE(ULONG_PTR, uintptr_t);
        __MINGW_INTSAFE_TESTCASE(WPARAM, uintptr_t);
#       if defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T)
        __MINGW_INTSAFE_TESTCASE(UHALF_PTR, uint32_t);
#       elif defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T)
        __MINGW_INTSAFE_TESTCASE(UHALF_PTR, uint16_t);
#       endif
        __MINGW_INTSAFE_TESTCASE(INT_PTR, intptr_t);
        __MINGW_INTSAFE_TESTCASE(LONG_PTR, intptr_t);
        __MINGW_INTSAFE_TESTCASE(LPARAM, intptr_t);
#       if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
        __MINGW_INTSAFE_TESTCASE(HALF_PTR, int32_t);
#       elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
        __MINGW_INTSAFE_TESTCASE(HALF_PTR, int16_t);
#       endif
    }

    __MINGW_INTSAFE_TESTSUITE("Object-Size-Holding Integral Types")
    {
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(SSIZE_T);
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(SIZE_T);

        __MINGW_INTSAFE_TESTCASE(SSIZE_T, intptr_t);
        __MINGW_INTSAFE_TESTCASE(SIZE_T, uintptr_t);
    }
}

#       undef __MINGW_INTSAFE_MASTER_TESTSUITE
#       undef __MINGW_INTSAFE_TESTSUITE
#       undef __MINGW_INTSAFE_TESTCASE
#       undef __MINGW_INTSAFE_RUN_WINDOWS_H_INTEGRAL_TYPEDEFS_TESTSUITE

#   endif /* __MINGW_INTSAFE_RUN_WINDOWS_H_INTEGRAL_TYPEDEFS_TESTSUITE */

#   ifdef __cplusplus
}
#   endif

#else

#   error Some standard macros are not defined.
#   error This may result from:
#   error 1. Broken stdint.h header and/or limits.h header.
#   error If it is the case, please report this to
#   error "http://sourceforge.net/projects/mingw-w64".
#   error 2. __STDC_CONSTANT_MACROS and/or __STDC_LIMIT_MACROS not defined.
#   error If it is the case, you can opt to:
#   error - Compile your code with flags "-D__STDC_CONSTANT_MACROS" and
#   error "-D__STDC_LIMIT_MACROS".
#   error - Define them before including any header.
#   error to fix the problem. Thanks.

#endif /* !__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS &&
        !__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS &&
        !__MINGW_INTSAFE_MISSING_CHAR_BIT */

#pragma GCC diagnostic pop

#endif /* __MINGW_INTSAFE_STATIC_CHECKS_H_INCLUDED */
