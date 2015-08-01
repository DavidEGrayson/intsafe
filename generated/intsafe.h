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
    #if USHRT_MAX > UCHAR_MAX
    if (operand > (USHORT)UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortToShort(_In_ USHORT operand, _Out_ SHORT * result)
{
    *result = 0;
    #if USHRT_MAX > SHRT_MAX
    if (operand > (USHORT)SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortToUChar(_In_ SHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    #if SHRT_MAX > UCHAR_MAX
    if (operand > (SHORT)UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
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
    #if UINT_MAX > UCHAR_MAX
    if (operand > (UINT)UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToUShort(_In_ UINT operand, _Out_ USHORT * result)
{
    *result = 0;
    #if UINT_MAX > USHRT_MAX
    if (operand > (UINT)USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToShort(_In_ UINT operand, _Out_ SHORT * result)
{
    *result = 0;
    #if UINT_MAX > SHRT_MAX
    if (operand > (UINT)SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToInt(_In_ UINT operand, _Out_ INT * result)
{
    *result = 0;
    #if UINT_MAX > INT_MAX
    if (operand > (UINT)INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToSSIZET(_In_ UINT operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    #if UINT_MAX > SSIZE_MAX
    if (operand > (UINT)SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUChar(_In_ INT operand, _Out_ UCHAR * result)
{
    *result = 0;
    #if INT_MAX > UCHAR_MAX
    if (operand > (INT)UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUShort(_In_ INT operand, _Out_ USHORT * result)
{
    *result = 0;
    #if INT_MAX > USHRT_MAX
    if (operand > (INT)USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToShort(_In_ INT operand, _Out_ SHORT * result)
{
    *result = 0;
    #if INT_MAX > SHRT_MAX
    if (operand > (INT)SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
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
    #if ULLONG_MAX > UINT_MAX
    if (operand > (ULONGLONG)UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToInt(_In_ ULONGLONG operand, _Out_ INT * result)
{
    *result = 0;
    #if ULLONG_MAX > INT_MAX
    if (operand > (ULONGLONG)INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToInt64(_In_ ULONGLONG operand, _Out_ INT64 * result)
{
    *result = 0;
    #if ULLONG_MAX > _I64_MAX
    if (operand > (ULONGLONG)_I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToSizeT(_In_ ULONGLONG operand, _Out_ size_t * result)
{
    *result = 0;
    #if ULLONG_MAX > SIZE_MAX
    if (operand > (ULONGLONG)SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToSSIZET(_In_ ULONGLONG operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    #if ULLONG_MAX > SSIZE_MAX
    if (operand > (ULONGLONG)SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToUInt(_In_ INT64 operand, _Out_ UINT * result)
{
    *result = 0;
    #if _I64_MAX > UINT_MAX
    if (operand > (INT64)UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToInt(_In_ INT64 operand, _Out_ INT * result)
{
    *result = 0;
    #if _I64_MAX > INT_MAX
    if (operand > (INT64)INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
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
    if (operand > (INT64)SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToSSIZET(_In_ INT64 operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    #if _I64_MAX > SSIZE_MAX
    if (operand > (INT64)SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < SSIZE_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToUInt(_In_ size_t operand, _Out_ UINT * result)
{
    *result = 0;
    #if SIZE_MAX > UINT_MAX
    if (operand > (size_t)UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToInt(_In_ size_t operand, _Out_ INT * result)
{
    *result = 0;
    #if SIZE_MAX > INT_MAX
    if (operand > (size_t)INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToInt64(_In_ size_t operand, _Out_ INT64 * result)
{
    *result = 0;
    #if SIZE_MAX > _I64_MAX
    if (operand > (size_t)_I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToSSIZET(_In_ size_t operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    #if SIZE_MAX > SSIZE_MAX
    if (operand > (size_t)SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToUInt(_In_ SSIZE_T operand, _Out_ UINT * result)
{
    *result = 0;
    #if SSIZE_MAX > UINT_MAX
    if (operand > (SSIZE_T)UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToInt(_In_ SSIZE_T operand, _Out_ INT * result)
{
    *result = 0;
    #if SSIZE_MAX > INT_MAX
    if (operand > (SSIZE_T)INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
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

/* TODO: add 253 missing functions */
