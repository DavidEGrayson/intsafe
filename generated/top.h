/* This file was auto-generated from https://github.com/DavidEGrayson/intsafe
 *
 * This file is an implementation of Microsoft's intsafe.h header, which
 * provides inline functions for safe integer conversions and math operations:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693
 *
 * The full list of math functions is only available here:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521701
 */

/* This file is free and unencumbered software released into the
 * public domain. */

#pragma once

#include <stdint.h>
#include <wtypesbase.h>
#include <limits.h>
#include <sal.h>

/* TODO: This logic should be moved to limits.h
 * so we can use CHAR_MIN/CHAR_MAX. */
#ifdef __CHAR_UNSIGNED__
#define __MINGW_INTSAFE_CHAR_MIN 0
#define __MINGW_INTSAFE_CHAR_MAX 0xff
#else
#define __MINGW_INTSAFE_CHAR_MIN -0x80
#define __MINGW_INTSAFE_CHAR_MAX 0x7f
#endif

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)

#ifndef S_OK
#define S_OK ((HRESULT)0)
#endif

#ifndef __MINGW_INTSAFE_API
#define __MINGW_INTSAFE_API inline
#endif

#ifndef __MINGW_INTSAFE_CHAR_API
#define __MINGW_INTSAFE_CHAR_API __MINGW_INTSAFE_API
#endif
