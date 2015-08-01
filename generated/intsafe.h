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

__MINGW_INTSAFE_API HRESULT LongToDWordPtr(_In_ LONG operand, _Out_ DWORD_PTR * result)
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

__MINGW_INTSAFE_CHAR_API HRESULT UShortToChar(_In_ USHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > __MINGW_INTSAFE_CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT WordToChar(_In_ WORD operand, _Out_ CHAR * result)
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

__MINGW_INTSAFE_CHAR_API HRESULT DWordToChar(_In_ DWORD operand, _Out_ CHAR * result)
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

#define UShortToByte UShortToUChar
#define WordToUChar UShortToUChar
#define WordToByte UShortToUChar
#define WordToShort UShortToShort
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

/* TODO: add 159 missing functions */
