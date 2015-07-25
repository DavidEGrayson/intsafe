/*
 * intsafe_common.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 */
#ifndef __MINGW_INTSAFE_COMMON_H_INCLUDED
#define __MINGW_INTSAFE_COMMON_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#ifndef __STDC_LIMIT_MACROS
#   define __MINGW_INTSAFE_UNDEF__STDC_LIMIT_MACROS
#   define __STDC_LIMIT_MACROS 1
#endif

#ifndef __STDC_CONSTANT_MACROS
#   define __MINGW_INTSAFE_UNDEF__STDC_CONSTANT_MACROS
#   define __STDC_CONSTANT_MACROS 1
#endif

#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include "intsafe_strict_mode.h"
#include "intsafe_integer_traits.h"

#ifdef __MINGW_INTSAFE_UNDEF__STDC_LIMIT_MACROS
#   undef __STDC_LIMIT_MACROS
#   undef __MINGW_INTSAFE_UNDEF__STDC_LIMIT_MACROS
#endif

#ifdef __MINGW_INTSAFE_UNDEF__STDC_CONSTANT_MACROS
#   undef __STDC_CONSTANT_MACROS
#   undef __MINGW_INTSAFE_UNDEF__STDC_CONSTANT_MACROS
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @typedef HRESULT
 * The type of return values of intsafe.h functions.
 */
#ifndef _HRESULT_DEFINED
#   define _HRESULT_DEFINED
typedef long HRESULT;
#endif

/**
 * @def S_OK
 * The value returns from intsafe.h functions if successful (borrowed
 * from strsafe.h).
 */
#ifndef S_OK
#   define S_OK ((HRESULT)0x00000000L)
#endif

/**
 * @def INTSAFE_E_ARITHMETIC_OVERFLOW
 * The value returns from intsafe.h functions if conversion causes a truncation
 * of the original value.
 */
#ifndef INTSAFE_E_ARITHMETIC_OVERFLOW
/*
 * Google gives me this link:
 *   http://social.msdn.microsoft.com/Forums/en/windowssdk/thread/
 *   d622e124-a08e-46f6-8fbc-b058b619ead9
 *
 * which says that INTSAFE_E_ARITHMETIC_OVERFLOW is also set to ((HRESULT) -1)
 * in comutil.h header.
 *
 * FIXME: which value is correct ?
 */
#   define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)
#endif

#if 0
/**
 * @def INTSAFE_E_INVALID_ARGUMENT
 * The value returns from intsafe.h functions if users pass a NULL pointer to
 * them.
 * @warning This is not a standard macro in intsafe.h header, and therefore may
 * cause naming collision if define it.
 */
#   ifndef INTSAFE_E_INVALID_PARAMETER
#       define INTSAFE_E_INVALID_PARAMETER ((HRESULT)0x80070057L)
#   endif
#endif

/**
 * @def SUCCEEDED
 * A facility which provides a generic test for success on any status value.
 * Non-negative numbers indicate success. This tool can be used to check the
 * return value of intsafe.h functions.
 * @sa FAILED
 */
#ifndef SUCCEEDED
#   define SUCCEEDED(status) ((HRESULT)(status) >= 0)
#endif

/**
 * @def FAILED
 * A facility which provides a generic test for failure on any status value.
 * Negative numbers indicate failure. This tool can be used to check the return
 * value of intsafe.h functions.
 * @sa SUCCEEDED
 */
#ifndef FAILED
#   define FAILED(status) ((HRESULT)(status) < 0)
#endif

/**
 * @def __MINGW_INTSAFE_ENABLE_STRICT_MODE
 * This macro is useful when users want to treat suspicious warnings, e.g
 * warning: conversion to X from Y may change the sign of the result, as errors
 * since it helps them to identify security problems in their code.
 * @note Currently, it works for GCC >= 4.2 and is not defined by default.
 * Please read comments in @file intsafe_strict_mode.h for more details.
 */

/**
 * @def __MINGW_INTSAFE_WARN_UNUSED_RESULT
 * This decorator causes a warning if the return value is ignored. This is
 * useful for intsafe.h functions because not checking the return value is a
 * security problem.
 * @note Currently, it works for GCC >= 4.1
 * @internal
 */
#if __MINGW_GNUC_PREREQ(4, 1)
#   define __MINGW_INTSAFE_WARN_UNUSED_RESULT \
    __attribute__((warn_unused_result))
#else
#   define __MINGW_INTSAFE_WARN_UNUSED_RESULT
#endif

/**
 * @def __MINGW_INTSAFE_WARN_NULL_POINTER
 * This decorator causes a warning if user passes NULL to intsafe.h
 * functions, which expect nonnull pointers.
 * @note Currently, it works for GCC >= 3.3
 * @internal
 */
#if __MINGW_GNUC_PREREQ(3, 3)
#   define __MINGW_INTSAFE_WARN_NULL_POINTER __attribute__((nonnull))
#else
#   define __MINGW_INTSAFE_WARN_NULL_POINTER /* __declspec(nonnull) */
#endif

/**
 * @def __MINGW_INTSAFE_DEPRECATED
 * This decorator causes a warning when a function or a type that marked with
 * it gets called/used somewhere.
 * @param msg a warning message.
 * @internal
 */
#if __MINGW_GNUC_PREREQ(4, 5)
#   define __MINGW_INTSAFE_DEPRECATED(msg) __declspec(deprecated(msg))
#elif __MINGW_GNUC_PREREQ(3, 1)
#   define __MINGW_INTSAFE_DEPRECATED(msg) __declspec(deprecated)
#else
#   define __MINGW_INTSAFE_DEPRECATED(msg) /* __declspec(deprecated(msg)) */
#endif

/**
 * @def __MINGW_INTSAFE_STRINGIZE
 * A facility for converting a given expression to a string.
 * @param expr an expression to be converted to a string.
 * @internal
 */
#define __MINGW_INTSAFE_STRINGIZE_IMPL(expr) #expr
#define __MINGW_INTSAFE_STRINGIZE(expr) __MINGW_INTSAFE_STRINGIZE_IMPL(expr)

/**
 * @def __MINGW_INTSAFE_JOIN
 * A facility for joining X with Y, even if X or Y itself is a macro.
 * The trick is borrowed from BOOST_JOIN's implementation,
 * which can be found in boost/config/suffix.hpp header.
 * @internal
 */
#define __MINGW_INTSAFE_JOIN(X, Y) __MINGW_INTSAFE_JOIN_IMPL(X, Y)
#define __MINGW_INTSAFE_JOIN_IMPL(X, Y) __MINGW_INTSAFE_JOIN_IMPL2(X, Y)
#define __MINGW_INTSAFE_JOIN_IMPL2(X, Y) X##Y

/**
 * @def __MINGW_INTSAFE_PREPARE_PREFIX
 * A facility for declaring intsafe.h functions with a proper prefix, which is
 * useful to zerotify the chance of naming collision.
 * @internal
 */
#define __MINGW_INTSAFE_PREPARE_PREFIX(X) \
    __MINGW_INTSAFE_JOIN(__mingw_intsafe_, X)

/**
 * @def __MINGW_INTSAFE_NULLPTR_ASSERT
 * A facility for causing a runtime assertion failure if user passes a NULL
 * pointer to an intsafe.h function. Ideally, intsafe.h functions should return
 * an error code, e.g E_INVALIDARG (0x80070057), in this case instead.
 * However, MSDN says that only S_OK and INTSAFE_E_ARITHMETIC_OVERFLOW
 * are valid return values.
 * @note We avoid using __func__, __FUNCTION__, __PRETTY_FUNCTION__ or
 * __FUNCSIG__ since neither of them are portable, and/or not contain function's
 * signature in C.
 * @internal
 */
#if 1
extern void _assert(const char* exp, const char* file, unsigned line);
extern
  __attribute__((__format__ (gnu_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__  format, ...);

#   define __MINGW_INTSAFE_NULLPTR_ASSERT(fn, ptr) \
    if (!ptr) { \
        char expr[512] = { 0 }; \
        __mingw_snprintf(expr, sizeof(expr),"in function \"%s\":" \
            " null pointer detected", fn); \
        _assert(expr, __FILE__, __LINE__); \
    }

#else
#   define __MINGW_INTSAFE_NULLPTR_ASSERT(fn, ptr) \
    if (!ptr) return INTSAFE_E_INVALID_PARAMETER;

#endif

/**
 * @def __MINGW_INTSAFE_STATIC_ASSERT
 * A macro which is equivalent to "assert" macro, but checking stuffs and
 * generating errors at compile time.
 * @param expr an expression to be checked.
 * @param msg an error message.
 * @internal
 */
#define __MINGW_INTSAFE_STATIC_ASSERT(expr, msg) \
    typedef char \
    __MINGW_INTSAFE_DEPRECATED("this type must not be used") \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_STATIC_ASSERTION_FAILED_, \
        msg \
    ) \
    [(expr) ? 1 : -1]


/**
 * @def __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT
 * A facility for causing a compile error if a given type is not integral,
 * e.g float or int*. The key here is that if T is not integral, then (T)(1)
 * is not an integral constant. Hence, this violates language rules since array
 * size must be an integral constant.
 * @param T a type to be checked.
 * @internal
 */
#define __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT(T) \
    typedef char \
    __MINGW_INTSAFE_DEPRECATED("this type must not be used") \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERTION_FAILED_, \
        __LINE__ \
    ) \
    [ (T)(1) ]

/**
 * @def __MINGW_INTSAFEAPI_ALWAYS_INLINE
 * This decorator makes a function inlined, even if optimization is turn off.
 * @note Currently, it works for GCC only.
 * @internal
 */
#if defined(__GNUC__)
#   define __MINGW_INTSAFEAPI_ALWAYS_INLINE __attribute__((always_inline))
#else
#   define __MINGW_INTSAFEAPI_ALWAYS_INLINE /* __declspec(always_inline) */
#endif

/**
 * @def __MINGW_INTSAFEAPI_INLINE
 * A facility for marking a function as inline.
 * @internal
 */
#if defined(__cplusplus)
#   define __MINGW_INTSAFEAPI_INLINE inline
#else
#   if defined(__GNUC__)
#       if defined(__GNUC_STDC_INLINE__)
#           define __MINGW_INTSAFEAPI_INLINE extern inline \
                __attribute__((gnu_inline))
#       else
#           define __MINGW_INTSAFEAPI_INLINE extern __inline__
#       endif
#   else
/* FIXME: __MINGW_INTSAFEAPI_INLINE for other compilers */
#       define __MINGW_INTSAFEAPI_INLINE static __inline
#   endif
#endif

/**
 * @def __MINGW_INTSAFEAPI
 * A facility for declaring intsafe.h functions with proper decorators.
 * @internal
 */
#define __MINGW_INTSAFEAPI \
    __MINGW_INTSAFEAPI_INLINE \
    __MINGW_INTSAFEAPI_ALWAYS_INLINE \
    HRESULT \
    __MINGW_INTSAFE_WARN_UNUSED_RESULT \
    __MINGW_INTSAFE_WARN_NULL_POINTER

#ifdef __cplusplus
}
#endif

#endif /* __MINGW_INTSAFE_COMMON_H_INCLUDED */
