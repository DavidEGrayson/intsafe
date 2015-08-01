/* This file was auto-generated from https://github.com/DavidEGrayson/intsafe
 *
 * This file is an implementation of Microsoft's intsafe.h header, which
 * provides inline functions for safe integer conversions and math operations:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693
 */

/* This file is free and unencumbered software released into the
 * public domain. */

#pragma once

#include <stdint.h>
#include <wtypesbase.h>
#include <limits.h>
#include <sal.h>

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)

#ifndef S_OK
#define S_OK ((HRESULT)0)
#endif

/* This should probably be in limits.h. */
#ifndef SSIZE_MIN
#ifdef _WIN64
#define SSIZE_MIN _I64_MIN
#else
#define SSIZE_MIN INT_MIN
#endif
#endif

#ifndef __MINGW_INTSAFE_API
#define __MINGW_INTSAFE_API inline
#endif

#ifndef __MINGW_INTSAFE_CHAR_API
#define __MINGW_INTSAFE_CHAR_API __MINGW_INTSAFE_API
#endif
