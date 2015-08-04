/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#pragma once

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#include <wtypesbase.h>
#include <specstrings.h>

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216)

#ifndef S_OK
#define S_OK ((HRESULT)0)
#endif

/** The builtins we use were added in GCC 5. */
#if __GNUC__ >= 5

#ifndef __MINGW_INTSAFE_API
#define __MINGW_INTSAFE_API FORCEINLINE
#endif

#ifndef __MINGW_INTSAFE_CHAR_API
#define __MINGW_INTSAFE_CHAR_API __MINGW_INTSAFE_API
#endif

#define __MINGW_INTSAFE_BODY(operation, x, y) \
{ \
  if (__builtin_##operation##_overflow(x, y, result)) \
  { \
      *result = 0; \
      return INTSAFE_E_ARITHMETIC_OVERFLOW; \
  } \
  return S_OK; \
}

#define __MINGW_INTSAFE_CONV(name, type_src, type_dest) \
    HRESULT name(type_src operand, type_dest * result) \
    __MINGW_INTSAFE_BODY(add, operand, 0)

#define __MINGW_INTSAFE_MATH(name, type, operation) \
    HRESULT name(type x, type y, type * result) \
    __MINGW_INTSAFE_BODY(operation, x, y)
