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

C_ASSERT(UCHAR_MAX == UINT8_MAX);
C_ASSERT(USHRT_MAX == UINT16_MAX);
C_ASSERT(SHRT_MAX == INT16_MAX);
C_ASSERT(SHRT_MIN == INT16_MIN);
C_ASSERT(SHRT_MIN == -SHRT_MAX - 1);
C_ASSERT(UINT_MAX == UINT32_MAX);
C_ASSERT(ULONG_MAX == UINT32_MAX);
C_ASSERT(INT_MAX == INT32_MAX);
C_ASSERT(INT_MIN == INT32_MIN);
C_ASSERT(INT_MIN == -INT_MAX - 1);
C_ASSERT(LONG_MAX == INT32_MAX);
C_ASSERT(LONG_MIN == INT32_MIN);
C_ASSERT(LONG_MIN == -LONG_MAX - 1);
C_ASSERT(SIZE_MAX == UINTPTR_MAX);
C_ASSERT(INTPTR_MIN == -INTPTR_MAX - 1);
C_ASSERT(PTRDIFF_MAX == INTPTR_MAX);
C_ASSERT(PTRDIFF_MIN == INTPTR_MIN);
C_ASSERT(PTRDIFF_MIN == -PTRDIFF_MAX - 1);
C_ASSERT(SSIZE_MAX == INTPTR_MAX);
C_ASSERT(INTPTR_MIN == -SSIZE_MAX - 1);
C_ASSERT(INTPTR_MIN == -INTPTR_MAX - 1);
C_ASSERT(ULLONG_MAX == UINT64_MAX);
C_ASSERT(_I64_MAX == INT64_MAX);
C_ASSERT(_I64_MIN == INT64_MIN);
C_ASSERT(_I64_MIN == -_I64_MAX - 1);

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

__MINGW_INTSAFE_API HRESULT UIntToSSIZET(_In_ UINT operand, _Out_ SSIZE_T * result)
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

__MINGW_INTSAFE_API HRESULT ULongToUShort(_In_ ULONG operand, _Out_ USHORT * result)
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

__MINGW_INTSAFE_API HRESULT ULongToSSIZET(_In_ ULONG operand, _Out_ SSIZE_T * result)
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

__MINGW_INTSAFE_API HRESULT IntToULong(_In_ INT operand, _Out_ ULONG * result)
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

__MINGW_INTSAFE_API HRESULT IntToDWordPtr(_In_ INT operand, _Out_ DWORD_PTR * result)
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

__MINGW_INTSAFE_API HRESULT LongToUShort(_In_ LONG operand, _Out_ USHORT * result)
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

__MINGW_INTSAFE_API HRESULT LongToInt(_In_ LONG operand, _Out_ INT * result)
{
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

__MINGW_INTSAFE_API HRESULT LongToDWordPtr(_In_ LONG operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongToIntPtr(_In_ LONG operand, _Out_ INT_PTR * result)
{
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

__MINGW_INTSAFE_API HRESULT UIntPtrToInt64(_In_ UINT_PTR operand, _Out_ INT64 * result)
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

__MINGW_INTSAFE_API HRESULT DWordPtrToSSIZET(_In_ DWORD_PTR operand, _Out_ SSIZE_T * result)
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

__MINGW_INTSAFE_API HRESULT IntPtrToDWordPtr(_In_ INT_PTR operand, _Out_ DWORD_PTR * result)
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

__MINGW_INTSAFE_API HRESULT SSIZETToDWordPtr(_In_ SSIZE_T operand, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETToIntPtr(_In_ SSIZE_T operand, _Out_ INT_PTR * result)
{
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

__MINGW_INTSAFE_API HRESULT ULongLongToDWordPtr(_In_ ULONGLONG operand, _Out_ DWORD_PTR * result)
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

__MINGW_INTSAFE_API HRESULT ULongLongToSSIZET(_In_ ULONGLONG operand, _Out_ SSIZE_T * result)
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

__MINGW_INTSAFE_API HRESULT Int64ToIntPtr(_In_ INT64 operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT Int64ToSSIZET(_In_ INT64 operand, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (operand > SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
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

/* If CHAR is unsigned, use different symbol names.
The avoids the risk of linking to the wrong function when different
translation units with different types of chars are linked together. */
#ifdef __CHAR_UNSIGNED__
#define UShortToChar __mingw_intsafe_uchar_UShortToChar
#define ShortToChar __mingw_intsafe_uchar_ShortToChar
#define UIntToChar __mingw_intsafe_uchar_UIntToChar
#define ULongToChar __mingw_intsafe_uchar_ULongToChar
#define IntToChar __mingw_intsafe_uchar_IntToChar
#define LongToChar __mingw_intsafe_uchar_LongToChar
#endif

__MINGW_INTSAFE_CHAR_API HRESULT UShortToChar(_In_ USHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT ShortToChar(_In_ SHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT UIntToChar(_In_ UINT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT ULongToChar(_In_ ULONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT IntToChar(_In_ INT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT LongToChar(_In_ LONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < __MINGW_INTSAFE_CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortAdd(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > USHRT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortAdd(_In_ SHORT x, _In_ SHORT y, _Out_ SHORT * result)
{
    *result = 0;
    if (x > 0 && y > SHRT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < SHRT_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntAdd(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > UINT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongAdd(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > ULONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntAdd(_In_ INT x, _In_ INT y, _Out_ INT * result)
{
    *result = 0;
    if (x > 0 && y > INT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INT_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongAdd(_In_ LONG x, _In_ LONG y, _Out_ LONG * result)
{
    *result = 0;
    if (x > 0 && y > LONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < LONG_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrAdd(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > UINTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrAdd(_In_ DWORD_PTR x, _In_ DWORD_PTR y, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (y > SIZE_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrAdd(_In_ INT_PTR x, _In_ INT_PTR y, _Out_ INT_PTR * result)
{
    *result = 0;
    if (x > 0 && y > INTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INTPTR_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETAdd(_In_ SSIZE_T x, _In_ SSIZE_T y, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (x > 0 && y > SSIZE_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INTPTR_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongAdd(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > ULLONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortSub(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ShortSub(_In_ SHORT x, _In_ SHORT y, _Out_ SHORT * result)
{
    *result = 0;
    if (x >= 0 && y < x - SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntSub(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongSub(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntSub(_In_ INT x, _In_ INT y, _Out_ INT * result)
{
    *result = 0;
    if (x >= 0 && y < x - INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT LongSub(_In_ LONG x, _In_ LONG y, _Out_ LONG * result)
{
    *result = 0;
    if (x >= 0 && y < x - LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrSub(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrSub(_In_ DWORD_PTR x, _In_ DWORD_PTR y, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT IntPtrSub(_In_ INT_PTR x, _In_ INT_PTR y, _Out_ INT_PTR * result)
{
    *result = 0;
    if (x >= 0 && y < x - INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SSIZETSub(_In_ SSIZE_T x, _In_ SSIZE_T y, _Out_ SSIZE_T * result)
{
    *result = 0;
    if (x >= 0 && y < x - SSIZE_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongSub(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UShortMult(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > 0 && x > USHRT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT WordMult(_In_ WORD x, _In_ WORD y, _Out_ WORD * result)
{
    *result = 0;
    if (y > 0 && x > USHRT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntMult(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > 0 && x > UINT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongMult(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > 0 && x > ULONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordMult(_In_ DWORD x, _In_ DWORD y, _Out_ DWORD * result)
{
    *result = 0;
    if (y > 0 && x > ULONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT UIntPtrMult(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > 0 && x > UINTPTR_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT SizeTMult(_In_ size_t x, _In_ size_t y, _Out_ size_t * result)
{
    *result = 0;
    if (y > 0 && x > SIZE_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT DWordPtrMult(_In_ DWORD_PTR x, _In_ DWORD_PTR y, _Out_ DWORD_PTR * result)
{
    *result = 0;
    if (y > 0 && x > SIZE_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongPtrMult(_In_ ULONG_PTR x, _In_ ULONG_PTR y, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (y > 0 && x > SIZE_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT ULongLongMult(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > 0 && x > ULLONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

#define UShortToByte UShortToUChar
#define WordToUChar UShortToUChar
#define WordToByte UShortToUChar
#define WordToShort UShortToShort
#define WordToChar UShortToChar
#define ShortToByte ShortToUChar
#define ShortToWord ShortToUShort
#define UIntToByte UIntToUChar
#define UIntToWord UIntToUShort
#define UIntToPtrdiffT UIntToIntPtr
#define UIntToLongPtr UIntToSSIZET
#define ULongToByte ULongToUChar
#define ULongToWord ULongToUShort
#define ULongToPtrdiffT ULongToIntPtr
#define ULongToLongPtr ULongToSSIZET
#define DWordToUChar ULongToUChar
#define DWordToByte ULongToUChar
#define DWordToUShort ULongToUShort
#define DWordToWord ULongToUShort
#define DWordToShort ULongToShort
#define DWordToUInt ULongToUInt
#define DWordToInt ULongToInt
#define DWordToLong ULongToLong
#define DWordToUIntPtr ULongToUIntPtr
#define DWordToIntPtr ULongToIntPtr
#define DWordToPtrdiffT ULongToIntPtr
#define DWordToSSIZET ULongToSSIZET
#define DWordToLongPtr ULongToSSIZET
#define DWordToChar ULongToChar
#define IntToByte IntToUChar
#define IntToWord IntToUShort
#define IntToDWord IntToULong
#define IntToSizeT IntToUIntPtr
#define IntToULongPtr IntToDWordPtr
#define LongToByte LongToUChar
#define LongToWord LongToUShort
#define LongToDWord LongToULong
#define LongToSizeT LongToUIntPtr
#define LongToULongPtr LongToDWordPtr
#define LongToPtrdiffT LongToIntPtr
#define UIntPtrToDWord UIntPtrToULong
#define UIntPtrToLongPtr UIntPtrToSSIZET
#define SizeTToUInt UIntPtrToUInt
#define SizeTToULong UIntPtrToULong
#define SizeTToDWord UIntPtrToULong
#define SizeTToInt UIntPtrToInt
#define SizeTToLong UIntPtrToLong
#define SizeTToIntPtr UIntPtrToIntPtr
#define SizeTToPtrdiffT UIntPtrToIntPtr
#define SizeTToSSIZET UIntPtrToSSIZET
#define SizeTToLongPtr UIntPtrToSSIZET
#define SizeTToInt64 UIntPtrToInt64
#define DWordPtrToDWord DWordPtrToULong
#define DWordPtrToPtrdiffT DWordPtrToIntPtr
#define DWordPtrToLongPtr DWordPtrToSSIZET
#define ULongPtrToUInt DWordPtrToUInt
#define ULongPtrToULong DWordPtrToULong
#define ULongPtrToDWord DWordPtrToULong
#define ULongPtrToInt DWordPtrToInt
#define ULongPtrToLong DWordPtrToLong
#define ULongPtrToUIntPtr DWordPtrToUIntPtr
#define ULongPtrToIntPtr DWordPtrToIntPtr
#define ULongPtrToPtrdiffT DWordPtrToIntPtr
#define ULongPtrToSSIZET DWordPtrToSSIZET
#define ULongPtrToLongPtr DWordPtrToSSIZET
#define ULongPtrToInt64 DWordPtrToInt64
#define IntPtrToDWord IntPtrToULong
#define IntPtrToSizeT IntPtrToUIntPtr
#define IntPtrToULongPtr IntPtrToDWordPtr
#define PtrdiffTToUInt IntPtrToUInt
#define PtrdiffTToULong IntPtrToULong
#define PtrdiffTToDWord IntPtrToULong
#define PtrdiffTToInt IntPtrToInt
#define PtrdiffTToLong IntPtrToLong
#define PtrdiffTToUIntPtr IntPtrToUIntPtr
#define PtrdiffTToSizeT IntPtrToUIntPtr
#define PtrdiffTToDWordPtr IntPtrToDWordPtr
#define PtrdiffTToULongPtr IntPtrToDWordPtr
#define SSIZETToDWord SSIZETToULong
#define SSIZETToSizeT SSIZETToUIntPtr
#define SSIZETToULongPtr SSIZETToDWordPtr
#define LongPtrToUInt SSIZETToUInt
#define LongPtrToULong SSIZETToULong
#define LongPtrToDWord SSIZETToULong
#define LongPtrToInt SSIZETToInt
#define LongPtrToLong SSIZETToLong
#define LongPtrToUIntPtr SSIZETToUIntPtr
#define LongPtrToSizeT SSIZETToUIntPtr
#define LongPtrToDWordPtr SSIZETToDWordPtr
#define LongPtrToULongPtr SSIZETToDWordPtr
#define LongPtrToIntPtr SSIZETToIntPtr
#define ULongLongToDWord ULongLongToULong
#define ULongLongToSizeT ULongLongToUIntPtr
#define ULongLongToULongPtr ULongLongToDWordPtr
#define ULongLongToPtrdiffT ULongLongToIntPtr
#define ULongLongToLongPtr ULongLongToSSIZET
#define Int64ToDWord Int64ToULong
#define Int64ToSizeT Int64ToUIntPtr
#define Int64ToULongPtr Int64ToDWordPtr
#define Int64ToPtrdiffT Int64ToIntPtr
#define Int64ToLongPtr Int64ToSSIZET
#define WordAdd UShortAdd
#define WordSub UShortSub
#define DWordAdd ULongAdd
#define DWordSub ULongSub
#define SizeTAdd UIntPtrAdd
#define SizeTSub UIntPtrSub
#define ULongPtrAdd DWordPtrAdd
#define ULongPtrSub DWordPtrSub
#define PtrdiffTAdd IntPtrAdd
#define PtrdiffTSub IntPtrSub
#define LongPtrAdd SSIZETAdd
#define LongPtrSub SSIZETSub

/* TODO: add 16 missing functions */
