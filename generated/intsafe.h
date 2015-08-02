/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 * This file was auto-generated from https://github.com/DavidEGrayson/intsafe
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

#pragma once

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#include <stdint.h>
#include <wtypesbase.h>
#include <limits.h>
#include <sal.h>
#include <specstrings.h>

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216)

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
C_ASSERT(1 == sizeof(UINT8));
C_ASSERT(1 == sizeof(BYTE));
C_ASSERT(1 == sizeof(INT8));

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
C_ASSERT(sizeof(void *) == sizeof(ULONG_PTR));
C_ASSERT(sizeof(void *) == sizeof(DWORD_PTR));
C_ASSERT(sizeof(void *) == sizeof(INT_PTR));
C_ASSERT(sizeof(void *) == sizeof(ptrdiff_t));
C_ASSERT(sizeof(void *) == sizeof(LONG_PTR));
C_ASSERT(sizeof(void *) == sizeof(SSIZE_T));

C_ASSERT(8 == sizeof(ULONGLONG));
C_ASSERT(8 == sizeof(INT64));
C_ASSERT(8 == sizeof(LONGLONG));

#ifdef __CHAR_UNSIGNED__
C_ASSERT((char)-1 > 0);
#else
C_ASSERT((char)-1 < 0);
#endif
C_ASSERT((INT8)-1 < 0);
C_ASSERT((SHORT)-1 < 0);
C_ASSERT((INT)-1 < 0);
C_ASSERT((LONG)-1 < 0);
C_ASSERT((INT_PTR)-1 < 0);
C_ASSERT((ptrdiff_t)-1 < 0);
C_ASSERT((LONG_PTR)-1 < 0);
C_ASSERT((SSIZE_T)-1 < 0);
C_ASSERT((INT64)-1 < 0);
C_ASSERT((LONGLONG)-1 < 0);
C_ASSERT((UCHAR)-1 > 0);
C_ASSERT((UINT8)-1 > 0);
C_ASSERT((BYTE)-1 > 0);
C_ASSERT((USHORT)-1 > 0);
C_ASSERT((WORD)-1 > 0);
C_ASSERT((UINT)-1 > 0);
C_ASSERT((ULONG)-1 > 0);
C_ASSERT((DWORD)-1 > 0);
C_ASSERT((UINT_PTR)-1 > 0);
C_ASSERT((size_t)-1 > 0);
C_ASSERT((ULONG_PTR)-1 > 0);
C_ASSERT((DWORD_PTR)-1 > 0);
C_ASSERT((ULONGLONG)-1 > 0);

#ifdef __CHAR_UNSIGNED__
C_ASSERT(CHAR_MIN == 0);
C_ASSERT(CHAR_MAX == UINT8_MAX);
#else
C_ASSERT(CHAR_MIN == INT8_MIN);
C_ASSERT(CHAR_MAX == INT8_MAX);
#endif
C_ASSERT(UCHAR_MAX == UINT8_MAX);
C_ASSERT(SHRT_MAX == INT16_MAX);
C_ASSERT(SHRT_MIN == INT16_MIN);
C_ASSERT(UINT_MAX == UINT32_MAX);
C_ASSERT(ULONG_MAX == UINT32_MAX);
C_ASSERT(INT_MAX == INT32_MAX);
C_ASSERT(INT_MIN == INT32_MIN);
C_ASSERT(LONG_MAX == INT32_MAX);
C_ASSERT(LONG_MIN == INT32_MIN);
C_ASSERT(SIZE_MAX == UINTPTR_MAX);
C_ASSERT(PTRDIFF_MAX == INTPTR_MAX);
C_ASSERT(PTRDIFF_MIN == INTPTR_MIN);
C_ASSERT(SSIZE_MAX == INTPTR_MAX);
C_ASSERT(ULLONG_MAX == UINT64_MAX);
C_ASSERT(_I64_MAX == INT64_MAX);
C_ASSERT(_I64_MIN == INT64_MIN);
C_ASSERT(LLONG_MAX == INT64_MAX);
C_ASSERT(LLONG_MIN == INT64_MIN);

#ifndef __cplusplus
C_ASSERT(__builtin_types_compatible_p(UCHAR, UINT8));
C_ASSERT(__builtin_types_compatible_p(UCHAR, BYTE));
C_ASSERT(__builtin_types_compatible_p(USHORT, WORD));
C_ASSERT(__builtin_types_compatible_p(ULONG, DWORD));
C_ASSERT(__builtin_types_compatible_p(UINT_PTR, size_t));
C_ASSERT(__builtin_types_compatible_p(ULONG_PTR, DWORD_PTR));
C_ASSERT(__builtin_types_compatible_p(INT_PTR, ptrdiff_t));
C_ASSERT(__builtin_types_compatible_p(LONG_PTR, SSIZE_T));
C_ASSERT(__builtin_types_compatible_p(INT64, LONGLONG));
#endif

__MINGW_INTSAFE_API HRESULT
UShortToUChar(_In_ USHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UShortToShort(_In_ USHORT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ShortToUChar(_In_ SHORT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ShortToUShort(_In_ SHORT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToUChar(_In_ UINT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToUShort(_In_ UINT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > UINT16_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToShort(_In_ UINT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToInt(_In_ UINT operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToLong(_In_ UINT operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToIntPtr(_In_ UINT operand, _Out_ INT_PTR * result)
{
    *result = 0;
    #if UINT_MAX > INTPTR_MAX
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntToLongPtr(_In_ UINT operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    #if UINT_MAX > INTPTR_MAX
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToUChar(_In_ ULONG operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToUShort(_In_ ULONG operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > UINT16_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToShort(_In_ ULONG operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToUInt(_In_ ULONG operand, _Out_ UINT * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToInt(_In_ ULONG operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToLong(_In_ ULONG operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToUIntPtr(_In_ ULONG operand, _Out_ UINT_PTR * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToIntPtr(_In_ ULONG operand, _Out_ INT_PTR * result)
{
    *result = 0;
    #if ULONG_MAX > INTPTR_MAX
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongToLongPtr(_In_ ULONG operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    #if ULONG_MAX > INTPTR_MAX
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToUChar(_In_ INT operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToUShort(_In_ INT operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > UINT16_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToShort(_In_ INT operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToUInt(_In_ INT operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToULong(_In_ INT operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToUIntPtr(_In_ INT operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToULongPtr(_In_ INT operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntToULongLong(_In_ INT operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToUChar(_In_ LONG operand, _Out_ UCHAR * result)
{
    *result = 0;
    if (operand > UCHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToUShort(_In_ LONG operand, _Out_ USHORT * result)
{
    *result = 0;
    if (operand > UINT16_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToShort(_In_ LONG operand, _Out_ SHORT * result)
{
    *result = 0;
    if (operand > SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToUInt(_In_ LONG operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToULong(_In_ LONG operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToInt(_In_ LONG operand, _Out_ INT * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToUIntPtr(_In_ LONG operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToULongPtr(_In_ LONG operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToIntPtr(_In_ LONG operand, _Out_ INT_PTR * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongToULongLong(_In_ LONG operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToUInt(_In_ UINT_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToULong(_In_ UINT_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToInt(_In_ UINT_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToLong(_In_ UINT_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToIntPtr(_In_ UINT_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToLongPtr(_In_ UINT_PTR operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrToInt64(_In_ UINT_PTR operand, _Out_ INT64 * result)
{
    *result = 0;
    #if UINTPTR_MAX > _I64_MAX
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToUInt(_In_ ULONG_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToULong(_In_ ULONG_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToInt(_In_ ULONG_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToLong(_In_ ULONG_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToUIntPtr(_In_ ULONG_PTR operand, _Out_ UINT_PTR * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToIntPtr(_In_ ULONG_PTR operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToLongPtr(_In_ ULONG_PTR operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrToInt64(_In_ ULONG_PTR operand, _Out_ INT64 * result)
{
    *result = 0;
    #if UINTPTR_MAX > _I64_MAX
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToUInt(_In_ INT_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    #if INTPTR_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToULong(_In_ INT_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    #if INTPTR_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToInt(_In_ INT_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToLong(_In_ INT_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToUIntPtr(_In_ INT_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToULongPtr(_In_ INT_PTR operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrToULongLong(_In_ INT_PTR operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToUInt(_In_ LONG_PTR operand, _Out_ UINT * result)
{
    *result = 0;
    #if INTPTR_MAX > UINT_MAX
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToULong(_In_ LONG_PTR operand, _Out_ ULONG * result)
{
    *result = 0;
    #if INTPTR_MAX > ULONG_MAX
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToInt(_In_ LONG_PTR operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToLong(_In_ LONG_PTR operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToUIntPtr(_In_ LONG_PTR operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToULongPtr(_In_ LONG_PTR operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToIntPtr(_In_ LONG_PTR operand, _Out_ INT_PTR * result)
{
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrToULongLong(_In_ LONG_PTR operand, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToUInt(_In_ ULONGLONG operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToULong(_In_ ULONGLONG operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToInt(_In_ ULONGLONG operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToLong(_In_ ULONGLONG operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToUIntPtr(_In_ ULONGLONG operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToULongPtr(_In_ ULONGLONG operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToIntPtr(_In_ ULONGLONG operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToLongPtr(_In_ ULONGLONG operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongToInt64(_In_ ULONGLONG operand, _Out_ INT64 * result)
{
    *result = 0;
    if (operand > _I64_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToUInt(_In_ INT64 operand, _Out_ UINT * result)
{
    *result = 0;
    if (operand > UINT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToULong(_In_ INT64 operand, _Out_ ULONG * result)
{
    *result = 0;
    if (operand > ULONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToInt(_In_ INT64 operand, _Out_ INT * result)
{
    *result = 0;
    if (operand > INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToLong(_In_ INT64 operand, _Out_ LONG * result)
{
    *result = 0;
    if (operand > LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToUIntPtr(_In_ INT64 operand, _Out_ UINT_PTR * result)
{
    *result = 0;
    #if _I64_MAX > UINTPTR_MAX
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToULongPtr(_In_ INT64 operand, _Out_ ULONG_PTR * result)
{
    *result = 0;
    #if _I64_MAX > UINTPTR_MAX
    if (operand > UINTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    #endif
    if (operand < 0) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToIntPtr(_In_ INT64 operand, _Out_ INT_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToLongPtr(_In_ INT64 operand, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (operand > INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int64ToULongLong(_In_ INT64 operand, _Out_ ULONGLONG * result)
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

__MINGW_INTSAFE_CHAR_API HRESULT
UShortToChar(_In_ USHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT
ShortToChar(_In_ SHORT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT
UIntToChar(_In_ UINT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT
ULongToChar(_In_ ULONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT
IntToChar(_In_ INT operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_CHAR_API HRESULT
LongToChar(_In_ LONG operand, _Out_ CHAR * result)
{
    *result = 0;
    if (operand > CHAR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (operand < CHAR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = operand;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UInt8Add(_In_ UINT8 x, _In_ UINT8 y, _Out_ UINT8 * result)
{
    *result = 0;
    if (y > UINT8_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int8Add(_In_ INT8 x, _In_ INT8 y, _Out_ INT8 * result)
{
    *result = 0;
    if (x > 0 && y > INT8_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INT8_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UShortAdd(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > UINT16_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ShortAdd(_In_ SHORT x, _In_ SHORT y, _Out_ SHORT * result)
{
    *result = 0;
    if (x > 0 && y > SHRT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < SHRT_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntAdd(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > UINT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongAdd(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > ULONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntAdd(_In_ INT x, _In_ INT y, _Out_ INT * result)
{
    *result = 0;
    if (x > 0 && y > INT_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INT_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongAdd(_In_ LONG x, _In_ LONG y, _Out_ LONG * result)
{
    *result = 0;
    if (x > 0 && y > LONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < LONG_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrAdd(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > UINTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrAdd(_In_ ULONG_PTR x, _In_ ULONG_PTR y, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (y > UINTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrAdd(_In_ INT_PTR x, _In_ INT_PTR y, _Out_ INT_PTR * result)
{
    *result = 0;
    if (x > 0 && y > INTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INTPTR_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrAdd(_In_ LONG_PTR x, _In_ LONG_PTR y, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (x > 0 && y > INTPTR_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < INTPTR_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongAdd(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > ULLONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongLongAdd(_In_ LONGLONG x, _In_ LONGLONG y, _Out_ LONGLONG * result)
{
    *result = 0;
    if (x > 0 && y > LLONG_MAX - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < LLONG_MIN - x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x + y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UInt8Sub(_In_ UINT8 x, _In_ UINT8 y, _Out_ UINT8 * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int8Sub(_In_ INT8 x, _In_ INT8 y, _Out_ INT8 * result)
{
    *result = 0;
    if (x >= 0 && y < x - INT8_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INT8_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UShortSub(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ShortSub(_In_ SHORT x, _In_ SHORT y, _Out_ SHORT * result)
{
    *result = 0;
    if (x >= 0 && y < x - SHRT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - SHRT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntSub(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongSub(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntSub(_In_ INT x, _In_ INT y, _Out_ INT * result)
{
    *result = 0;
    if (x >= 0 && y < x - INT_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INT_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongSub(_In_ LONG x, _In_ LONG y, _Out_ LONG * result)
{
    *result = 0;
    if (x >= 0 && y < x - LONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - LONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrSub(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrSub(_In_ ULONG_PTR x, _In_ ULONG_PTR y, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrSub(_In_ INT_PTR x, _In_ INT_PTR y, _Out_ INT_PTR * result)
{
    *result = 0;
    if (x >= 0 && y < x - INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrSub(_In_ LONG_PTR x, _In_ LONG_PTR y, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (x >= 0 && y < x - INTPTR_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - INTPTR_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongSub(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongLongSub(_In_ LONGLONG x, _In_ LONGLONG y, _Out_ LONGLONG * result)
{
    *result = 0;
    if (x >= 0 && y < x - LLONG_MAX) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > x - LLONG_MIN) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x - y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UInt8Mult(_In_ UINT8 x, _In_ UINT8 y, _Out_ UINT8 * result)
{
    *result = 0;
    if (y > 0 && x > UINT8_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
Int8Mult(_In_ INT8 x, _In_ INT8 y, _Out_ INT8 * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > INT8_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < INT8_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < INT8_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= INT8_MIN || y <= INT8_MIN || -x > INT8_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UShortMult(_In_ USHORT x, _In_ USHORT y, _Out_ USHORT * result)
{
    *result = 0;
    if (y > 0 && x > UINT16_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ShortMult(_In_ SHORT x, _In_ SHORT y, _Out_ SHORT * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > SHRT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < SHRT_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < SHRT_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= SHRT_MIN || y <= SHRT_MIN || -x > SHRT_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntMult(_In_ UINT x, _In_ UINT y, _Out_ UINT * result)
{
    *result = 0;
    if (y > 0 && x > UINT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongMult(_In_ ULONG x, _In_ ULONG y, _Out_ ULONG * result)
{
    *result = 0;
    if (y > 0 && x > ULONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntMult(_In_ INT x, _In_ INT y, _Out_ INT * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > INT_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < INT_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < INT_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= INT_MIN || y <= INT_MIN || -x > INT_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongMult(_In_ LONG x, _In_ LONG y, _Out_ LONG * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > LONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < LONG_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < LONG_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= LONG_MIN || y <= LONG_MIN || -x > LONG_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
UIntPtrMult(_In_ UINT_PTR x, _In_ UINT_PTR y, _Out_ UINT_PTR * result)
{
    *result = 0;
    if (y > 0 && x > UINTPTR_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongPtrMult(_In_ ULONG_PTR x, _In_ ULONG_PTR y, _Out_ ULONG_PTR * result)
{
    *result = 0;
    if (y > 0 && x > UINTPTR_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
IntPtrMult(_In_ INT_PTR x, _In_ INT_PTR y, _Out_ INT_PTR * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > INTPTR_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < INTPTR_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < INTPTR_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= INTPTR_MIN || y <= INTPTR_MIN || -x > INTPTR_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongPtrMult(_In_ LONG_PTR x, _In_ LONG_PTR y, _Out_ LONG_PTR * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > INTPTR_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < INTPTR_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < INTPTR_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= INTPTR_MIN || y <= INTPTR_MIN || -x > INTPTR_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
ULongLongMult(_In_ ULONGLONG x, _In_ ULONGLONG y, _Out_ ULONGLONG * result)
{
    *result = 0;
    if (y > 0 && x > ULLONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    *result = x * y;
    return S_OK;
}

__MINGW_INTSAFE_API HRESULT
LongLongMult(_In_ LONGLONG x, _In_ LONGLONG y, _Out_ LONGLONG * result)
{
    *result = 0;
    if (x > 0 && y > 0 && x > LLONG_MAX / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y > 0 && x < LLONG_MIN / y) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x > 0 && y < 0 && y < LLONG_MIN / x) return INTSAFE_E_ARITHMETIC_OVERFLOW;
    if (x < 0 && y < 0 && (x <= LLONG_MIN || y <= LLONG_MIN || -x > LLONG_MAX / -y))
        return INTSAFE_E_ARITHMETIC_OVERFLOW;
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
#define UIntToSSIZET UIntToLongPtr
#define ULongToByte ULongToUChar
#define ULongToWord ULongToUShort
#define ULongToPtrdiffT ULongToIntPtr
#define ULongToSSIZET ULongToLongPtr
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
#define DWordToLongPtr ULongToLongPtr
#define DWordToSSIZET ULongToLongPtr
#define DWordToChar ULongToChar
#define IntToByte IntToUChar
#define IntToWord IntToUShort
#define IntToDWord IntToULong
#define IntToSizeT IntToUIntPtr
#define IntToDWordPtr IntToULongPtr
#define LongToByte LongToUChar
#define LongToWord LongToUShort
#define LongToDWord LongToULong
#define LongToSizeT LongToUIntPtr
#define LongToDWordPtr LongToULongPtr
#define LongToPtrdiffT LongToIntPtr
#define UIntPtrToDWord UIntPtrToULong
#define UIntPtrToSSIZET UIntPtrToLongPtr
#define SizeTToUInt UIntPtrToUInt
#define SizeTToULong UIntPtrToULong
#define SizeTToDWord UIntPtrToULong
#define SizeTToInt UIntPtrToInt
#define SizeTToLong UIntPtrToLong
#define SizeTToIntPtr UIntPtrToIntPtr
#define SizeTToPtrdiffT UIntPtrToIntPtr
#define SizeTToLongPtr UIntPtrToLongPtr
#define SizeTToSSIZET UIntPtrToLongPtr
#define SizeTToInt64 UIntPtrToInt64
#define ULongPtrToDWord ULongPtrToULong
#define ULongPtrToPtrdiffT ULongPtrToIntPtr
#define ULongPtrToSSIZET ULongPtrToLongPtr
#define DWordPtrToUInt ULongPtrToUInt
#define DWordPtrToULong ULongPtrToULong
#define DWordPtrToDWord ULongPtrToULong
#define DWordPtrToInt ULongPtrToInt
#define DWordPtrToLong ULongPtrToLong
#define DWordPtrToUIntPtr ULongPtrToUIntPtr
#define DWordPtrToIntPtr ULongPtrToIntPtr
#define DWordPtrToPtrdiffT ULongPtrToIntPtr
#define DWordPtrToLongPtr ULongPtrToLongPtr
#define DWordPtrToSSIZET ULongPtrToLongPtr
#define DWordPtrToInt64 ULongPtrToInt64
#define IntPtrToDWord IntPtrToULong
#define IntPtrToSizeT IntPtrToUIntPtr
#define IntPtrToDWordPtr IntPtrToULongPtr
#define PtrdiffTToUInt IntPtrToUInt
#define PtrdiffTToULong IntPtrToULong
#define PtrdiffTToDWord IntPtrToULong
#define PtrdiffTToInt IntPtrToInt
#define PtrdiffTToLong IntPtrToLong
#define PtrdiffTToUIntPtr IntPtrToUIntPtr
#define PtrdiffTToSizeT IntPtrToUIntPtr
#define PtrdiffTToULongPtr IntPtrToULongPtr
#define PtrdiffTToDWordPtr IntPtrToULongPtr
#define LongPtrToDWord LongPtrToULong
#define LongPtrToSizeT LongPtrToUIntPtr
#define LongPtrToDWordPtr LongPtrToULongPtr
#define SSIZETToUInt LongPtrToUInt
#define SSIZETToULong LongPtrToULong
#define SSIZETToDWord LongPtrToULong
#define SSIZETToInt LongPtrToInt
#define SSIZETToLong LongPtrToLong
#define SSIZETToUIntPtr LongPtrToUIntPtr
#define SSIZETToSizeT LongPtrToUIntPtr
#define SSIZETToULongPtr LongPtrToULongPtr
#define SSIZETToDWordPtr LongPtrToULongPtr
#define SSIZETToIntPtr LongPtrToIntPtr
#define ULongLongToDWord ULongLongToULong
#define ULongLongToSizeT ULongLongToUIntPtr
#define ULongLongToDWordPtr ULongLongToULongPtr
#define ULongLongToPtrdiffT ULongLongToIntPtr
#define ULongLongToSSIZET ULongLongToLongPtr
#define Int64ToDWord Int64ToULong
#define Int64ToSizeT Int64ToUIntPtr
#define Int64ToDWordPtr Int64ToULongPtr
#define Int64ToPtrdiffT Int64ToIntPtr
#define Int64ToSSIZET Int64ToLongPtr
#define WordAdd UShortAdd
#define WordSub UShortSub
#define WordMult UShortMult
#define DWordAdd ULongAdd
#define DWordSub ULongSub
#define DWordMult ULongMult
#define SizeTAdd UIntPtrAdd
#define SizeTSub UIntPtrSub
#define SizeTMult UIntPtrMult
#define DWordPtrAdd ULongPtrAdd
#define DWordPtrSub ULongPtrSub
#define DWordPtrMult ULongPtrMult
#define PtrdiffTAdd IntPtrAdd
#define PtrdiffTSub IntPtrSub
#define PtrdiffTMult IntPtrMult
#define SSIZETAdd LongPtrAdd
#define SSIZETSub LongPtrSub
#define SSIZETMult LongPtrMult

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
