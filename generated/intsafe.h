/* This file is free and unencumbered software released into the
 * public domain. */

/* This file is an implementation of Microsoft's intsafe.h header, which
 * provides inline functions for safe integer conversions and math operations:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693
 *
 * It was mostly auto-generated using a script that can be found at:
 *
 *     https://github.com/DavidEGrayson/intsafe
 */

#pragma once

#include <wtypesbase.h>
#include <limits.h>
#include <sal.h>

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

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)

__MINGW_INTSAFE_API HRESULT UShortToUChar(_In_ USHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortToShort(_In_ USHORT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortToUChar(_In_ SHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortToUShort(_In_ SHORT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToUChar(_In_ UINT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToUShort(_In_ UINT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToShort(_In_ UINT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToInt(_In_ UINT operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToSSIZET(_In_ UINT operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUChar(_In_ INT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUShort(_In_ INT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToShort(_In_ INT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUInt(_In_ INT operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToULongLong(_In_ INT operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToSizeT(_In_ INT operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToUInt(_In_ ULONGLONG operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToInt(_In_ ULONGLONG operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToInt64(_In_ ULONGLONG operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToSizeT(_In_ ULONGLONG operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToSSIZET(_In_ ULONGLONG operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToUInt(_In_ INT64 operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToInt(_In_ INT64 operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToULongLong(_In_ INT64 operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToSizeT(_In_ INT64 operand, _Out_ size_t * result)
{
    *result = 0;
    #if _I64_MAX > SIZE_MAX
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToSSIZET(_In_ INT64 operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SSIZE_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToUInt(_In_ size_t operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToInt(_In_ size_t operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToInt64(_In_ size_t operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToSSIZET(_In_ size_t operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToUInt(_In_ SSIZE_T operand, _Out_ UINT * result)
{
    *result = 0;
    #if SSIZE_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToInt(_In_ SSIZE_T operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToSizeT(_In_ SSIZE_T operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

#if INT_MAX > SIZE_MAX
#error assumed no INT is too large to be represented as a size_t
#endif

#if INT_MAX > UINT_MAX
#error assumed no INT is too large to be represented as a UINT
#endif

#if INT_MAX > ULLONG_MAX
#error assumed no INT is too large to be represented as a ULONGLONG
#endif

#if SHRT_MAX > USHRT_MAX
#error assumed no SHORT is too large to be represented as a USHORT
#endif

#if SSIZE_MAX > SIZE_MAX
#error assumed no SSIZE_T is too large to be represented as a size_t
#endif

#if _I64_MAX > ULLONG_MAX
#error assumed no INT64 is too large to be represented as a ULONGLONG
#endif
/* TODO: add 253 missing functions */
