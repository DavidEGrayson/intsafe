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


C_ASSERT(1 == sizeof(CHAR));
C_ASSERT(1 == sizeof(UCHAR));
C_ASSERT(1 == sizeof(BYTE));

C_ASSERT(2 == sizeof(USHORT));
C_ASSERT(2 == sizeof(WORD));
C_ASSERT(2 == sizeof(SHORT));

C_ASSERT(4 == sizeof(UINT));
C_ASSERT(4 == sizeof(ULONG));
C_ASSERT(4 == sizeof(DWORD));
C_ASSERT(4 == sizeof(INT));
C_ASSERT(4 == sizeof(LONG));

C_ASSERT(sizeof(void *) == 4 || sizeof(void *) == 8);
C_ASSERT(sizeof(void *) == sizeof(UINT_PTR));
C_ASSERT(sizeof(void *) == sizeof(size_t));
C_ASSERT(sizeof(void *) == sizeof(DWORD_PTR));
C_ASSERT(sizeof(void *) == sizeof(ULONG_PTR));
C_ASSERT(sizeof(void *) == sizeof(INT_PTR));
C_ASSERT(sizeof(void *) == sizeof(ptrdiff_t));
C_ASSERT(sizeof(void *) == sizeof(SSIZE_T));
C_ASSERT(sizeof(void *) == sizeof(LONG_PTR));

C_ASSERT(8 == sizeof(ULONGLONG));
C_ASSERT(8 == sizeof(INT64));

#ifdef __CHAR_UNSIGNED__
C_ASSERT((char)-1 > 0);
#else
C_ASSERT((char)-1 < 0);
#endif
C_ASSERT((SHORT)-1 < 0);
C_ASSERT((INT)-1 < 0);
C_ASSERT((LONG)-1 < 0);
C_ASSERT((INT_PTR)-1 < 0);
C_ASSERT((ptrdiff_t)-1 < 0);
C_ASSERT((SSIZE_T)-1 < 0);
C_ASSERT((LONG_PTR)-1 < 0);
C_ASSERT((INT64)-1 < 0);
C_ASSERT((UCHAR)-1 > 0);
C_ASSERT((BYTE)-1 > 0);
C_ASSERT((USHORT)-1 > 0);
C_ASSERT((WORD)-1 > 0);
C_ASSERT((UINT)-1 > 0);
C_ASSERT((ULONG)-1 > 0);
C_ASSERT((DWORD)-1 > 0);
C_ASSERT((UINT_PTR)-1 > 0);
C_ASSERT((size_t)-1 > 0);
C_ASSERT((DWORD_PTR)-1 > 0);
C_ASSERT((ULONG_PTR)-1 > 0);
C_ASSERT((ULONGLONG)-1 > 0);

C_ASSERT(UINT8_MAX == UCHAR_MAX);
C_ASSERT(UINT16_MAX == USHRT_MAX);
C_ASSERT(INT16_MAX == SHRT_MAX);
C_ASSERT(INT16_MIN == SHRT_MIN);
C_ASSERT(UINT32_MAX == UINT_MAX);
C_ASSERT(UINT32_MAX == ULONG_MAX);
C_ASSERT(INT32_MAX == INT_MAX);
C_ASSERT(INT32_MIN == INT_MIN);
C_ASSERT(INT32_MAX == LONG_MAX);
C_ASSERT(INT32_MIN == LONG_MIN);
C_ASSERT(UINTPTR_MAX == SIZE_MAX);
C_ASSERT(INTPTR_MAX == PTRDIFF_MAX);
C_ASSERT(INTPTR_MIN == PTRDIFF_MIN);
C_ASSERT(INTPTR_MAX == SSIZE_MAX);
C_ASSERT(INTPTR_MIN == SSIZE_MIN);
C_ASSERT(INTPTR_MIN == SSIZE_MIN);
C_ASSERT(UINT64_MAX == ULLONG_MAX);
C_ASSERT(INT64_MAX == _I64_MAX);
C_ASSERT(INT64_MIN == _I64_MIN);

#ifndef __cplusplus
C_ASSERT(__builtin_types_compatible_p(UCHAR, BYTE));
C_ASSERT(__builtin_types_compatible_p(USHORT, WORD));
C_ASSERT(__builtin_types_compatible_p(ULONG, DWORD));
C_ASSERT(__builtin_types_compatible_p(UINT_PTR, size_t));
C_ASSERT(__builtin_types_compatible_p(DWORD_PTR, ULONG_PTR));
C_ASSERT(__builtin_types_compatible_p(INT_PTR, ptrdiff_t));
C_ASSERT(__builtin_types_compatible_p(SSIZE_T, LONG_PTR));
#endif

__MINGW_INTSAFE_API HRESULT UShortToUChar(_In_ USHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortToByte(_In_ USHORT operand, _Out_ BYTE * result)
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

__MINGW_INTSAFE_API HRESULT WordToUChar(_In_ WORD operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT WordToByte(_In_ WORD operand, _Out_ BYTE * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT WordToShort(_In_ WORD operand, _Out_ SHORT * result)
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

__MINGW_INTSAFE_API HRESULT ShortToByte(_In_ SHORT operand, _Out_ BYTE * result)
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

__MINGW_INTSAFE_API HRESULT ShortToWord(_In_ SHORT operand, _Out_ WORD * result)
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

__MINGW_INTSAFE_API HRESULT UIntToByte(_In_ UINT operand, _Out_ BYTE * result)
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

__MINGW_INTSAFE_API HRESULT UIntToWord(_In_ UINT operand, _Out_ WORD * result)
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

__MINGW_INTSAFE_API HRESULT UIntToLong(_In_ UINT operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToIntPtr(_In_ UINT operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToPtrdiffT(_In_ UINT operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT UIntToLongPtr(_In_ UINT operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToUChar(_In_ ULONG operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToByte(_In_ ULONG operand, _Out_ BYTE * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToUShort(_In_ ULONG operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToWord(_In_ ULONG operand, _Out_ WORD * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToShort(_In_ ULONG operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToUInt(_In_ ULONG operand, _Out_ UINT * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToInt(_In_ ULONG operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToLong(_In_ ULONG operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToUIntPtr(_In_ ULONG operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToIntPtr(_In_ ULONG operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToPtrdiffT(_In_ ULONG operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToSSIZET(_In_ ULONG operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToLongPtr(_In_ ULONG operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToUChar(_In_ DWORD operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToByte(_In_ DWORD operand, _Out_ BYTE * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToUShort(_In_ DWORD operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToWord(_In_ DWORD operand, _Out_ WORD * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToShort(_In_ DWORD operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToUInt(_In_ DWORD operand, _Out_ UINT * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToInt(_In_ DWORD operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToLong(_In_ DWORD operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToUIntPtr(_In_ DWORD operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToIntPtr(_In_ DWORD operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToPtrdiffT(_In_ DWORD operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToSSIZET(_In_ DWORD operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToLongPtr(_In_ DWORD operand, _Out_ LONG_PTR * result)
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

__MINGW_INTSAFE_API HRESULT IntToByte(_In_ INT operand, _Out_ BYTE * result)
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

__MINGW_INTSAFE_API HRESULT IntToWord(_In_ INT operand, _Out_ WORD * result)
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

__MINGW_INTSAFE_API HRESULT IntToULong(_In_ INT operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToDWord(_In_ INT operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToUIntPtr(_In_ INT operand, _Out_ UINT_PTR * result)
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

__MINGW_INTSAFE_API HRESULT IntToDWordPtr(_In_ INT operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToULongPtr(_In_ INT operand, _Out_ ULONG_PTR * result)
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

__MINGW_INTSAFE_API HRESULT LongToUChar(_In_ LONG operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToByte(_In_ LONG operand, _Out_ BYTE * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToUShort(_In_ LONG operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToWord(_In_ LONG operand, _Out_ WORD * result)
{
    *result = 0;
    if (operand > USHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToShort(_In_ LONG operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToUInt(_In_ LONG operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToULong(_In_ LONG operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToDWord(_In_ LONG operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToInt(_In_ LONG operand, _Out_ INT * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToUIntPtr(_In_ LONG operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToSizeT(_In_ LONG operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToDWordPtr(_In_ LONG operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToULongPtr(_In_ LONG operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToIntPtr(_In_ LONG operand, _Out_ INT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToPtrdiffT(_In_ LONG operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToULongLong(_In_ LONG operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToUInt(_In_ UINT_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToULong(_In_ UINT_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToDWord(_In_ UINT_PTR operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToInt(_In_ UINT_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToLong(_In_ UINT_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToIntPtr(_In_ UINT_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToSSIZET(_In_ UINT_PTR operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToLongPtr(_In_ UINT_PTR operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrToInt64(_In_ UINT_PTR operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SizeTToULong(_In_ size_t operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToDWord(_In_ size_t operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SizeTToLong(_In_ size_t operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToIntPtr(_In_ size_t operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTToPtrdiffT(_In_ size_t operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SizeTToLongPtr(_In_ size_t operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT DWordPtrToUInt(_In_ DWORD_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToULong(_In_ DWORD_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToDWord(_In_ DWORD_PTR operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToInt(_In_ DWORD_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToLong(_In_ DWORD_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToUIntPtr(_In_ DWORD_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToIntPtr(_In_ DWORD_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToPtrdiffT(_In_ DWORD_PTR operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToSSIZET(_In_ DWORD_PTR operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToLongPtr(_In_ DWORD_PTR operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrToInt64(_In_ DWORD_PTR operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToUInt(_In_ ULONG_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToULong(_In_ ULONG_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToDWord(_In_ ULONG_PTR operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToInt(_In_ ULONG_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToLong(_In_ ULONG_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToUIntPtr(_In_ ULONG_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToIntPtr(_In_ ULONG_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToPtrdiffT(_In_ ULONG_PTR operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToSSIZET(_In_ ULONG_PTR operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToLongPtr(_In_ ULONG_PTR operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrToInt64(_In_ ULONG_PTR operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToUInt(_In_ INT_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    #if INTPTR_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToULong(_In_ INT_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    #if INTPTR_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToDWord(_In_ INT_PTR operand, _Out_ DWORD * result)
{
    *result = 0;
    #if INTPTR_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToInt(_In_ INT_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToLong(_In_ INT_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToUIntPtr(_In_ INT_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToSizeT(_In_ INT_PTR operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToDWordPtr(_In_ INT_PTR operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToULongPtr(_In_ INT_PTR operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrToULongLong(_In_ INT_PTR operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToUInt(_In_ ptrdiff_t operand, _Out_ UINT * result)
{
    *result = 0;
    #if PTRDIFF_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToULong(_In_ ptrdiff_t operand, _Out_ ULONG * result)
{
    *result = 0;
    #if PTRDIFF_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToDWord(_In_ ptrdiff_t operand, _Out_ DWORD * result)
{
    *result = 0;
    #if PTRDIFF_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToInt(_In_ ptrdiff_t operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToLong(_In_ ptrdiff_t operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToUIntPtr(_In_ ptrdiff_t operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToSizeT(_In_ ptrdiff_t operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToDWordPtr(_In_ ptrdiff_t operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT PtrdiffTToULongPtr(_In_ ptrdiff_t operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SSIZETToULong(_In_ SSIZE_T operand, _Out_ ULONG * result)
{
    *result = 0;
    #if SSIZE_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToDWord(_In_ SSIZE_T operand, _Out_ DWORD * result)
{
    *result = 0;
    #if SSIZE_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SSIZETToLong(_In_ SSIZE_T operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToUIntPtr(_In_ SSIZE_T operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT SSIZETToDWordPtr(_In_ SSIZE_T operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToULongPtr(_In_ SSIZE_T operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToIntPtr(_In_ SSIZE_T operand, _Out_ INT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToUInt(_In_ LONG_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    #if SSIZE_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToULong(_In_ LONG_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    #if SSIZE_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToDWord(_In_ LONG_PTR operand, _Out_ DWORD * result)
{
    *result = 0;
    #if SSIZE_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToInt(_In_ LONG_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToLong(_In_ LONG_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToUIntPtr(_In_ LONG_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToSizeT(_In_ LONG_PTR operand, _Out_ size_t * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToDWordPtr(_In_ LONG_PTR operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToULongPtr(_In_ LONG_PTR operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToIntPtr(_In_ LONG_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongPtrToULongLong(_In_ LONG_PTR operand, _Out_ ULONGLONG * result)
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

__MINGW_INTSAFE_API HRESULT ULongLongToULong(_In_ ULONGLONG operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToDWord(_In_ ULONGLONG operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT ULongLongToLong(_In_ ULONGLONG operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToUIntPtr(_In_ ULONGLONG operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT ULongLongToDWordPtr(_In_ ULONGLONG operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToULongPtr(_In_ ULONGLONG operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToIntPtr(_In_ ULONGLONG operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongToPtrdiffT(_In_ ULONGLONG operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT ULongLongToLongPtr(_In_ ULONGLONG operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT Int64ToUInt(_In_ INT64 operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToULong(_In_ INT64 operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToDWord(_In_ INT64 operand, _Out_ DWORD * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT Int64ToLong(_In_ INT64 operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToUIntPtr(_In_ INT64 operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    #if _I64_MAX > UINTPTR_MAX
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
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

__MINGW_INTSAFE_API HRESULT Int64ToDWordPtr(_In_ INT64 operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    #if _I64_MAX > SIZE_MAX
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToULongPtr(_In_ INT64 operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    #if _I64_MAX > SIZE_MAX
    if (operand > SIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToIntPtr(_In_ INT64 operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToPtrdiffT(_In_ INT64 operand, _Out_ ptrdiff_t * result)
{
    *result = 0;
    if (operand > PTRDIFF_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < PTRDIFF_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

__MINGW_INTSAFE_API HRESULT Int64ToLongPtr(_In_ INT64 operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SSIZE_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

#ifdef __CHAR_UNSIGNED__
/* If CHAR is unsigned, use different symbol names.
The avoids the risk of linking to the wrong function when different
translation units with different types of chars are linked together. */
#define UShortToChar __mingw_intsafe_uchar_UShortToChar
#define WordToChar __mingw_intsafe_uchar_WordToChar
#define ShortToChar __mingw_intsafe_uchar_ShortToChar
#define UIntToChar __mingw_intsafe_uchar_UIntToChar
#define ULongToChar __mingw_intsafe_uchar_ULongToChar
#define DWordToChar __mingw_intsafe_uchar_DWordToChar
#define IntToChar __mingw_intsafe_uchar_IntToChar
#define LongToChar __mingw_intsafe_uchar_LongToChar

/* this logic should be moved to limits.h */
#define __MINGW_INTSAFE_CHAR_MIN 0
#define __MINGW_INTSAFE_CHAR_MAX 0xff
#else
#define __MINGW_INTSAFE_CHAR_MIN -0x80
#define __MINGW_INTSAFE_CHAR_MAX 0x7f
#endif

__MINGW_INTSAFE_API HRESULT UShortToChar(_In_ USHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT WordToChar(_In_ WORD operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortToChar(_In_ SHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntToChar(_In_ UINT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongToChar(_In_ ULONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordToChar(_In_ DWORD operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntToChar(_In_ INT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToChar(_In_ LONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

/* TODO: add 253 missing functions */
