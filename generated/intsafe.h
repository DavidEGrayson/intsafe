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

#include <ntdef.h>
#include <limits.h>

/* This should probably be in limits.h. */
#ifndef SSIZE_MIN
#ifdef _WIN64
#define SSIZE_MIN _I64_MIN
#else
#define SSIZE_MIN INT_MIN
#endif
#endif

#define __MINGW_INTSAFE_API inline HRESULT

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)
__MINGW_INTSAFE_API __mingw_intsafe_UChartoUChar(_In_ UCHAR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoInt8(_In_ UCHAR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoByte(_In_ UCHAR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoUShort(_In_ UCHAR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoWord(_In_ UCHAR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoShort(_In_ UCHAR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoUInt(_In_ UCHAR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoULong(_In_ UCHAR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoDWord(_In_ UCHAR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoInt(_In_ UCHAR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoLong(_In_ UCHAR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoULongLong(_In_ UCHAR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoInt64(_In_ UCHAR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoUIntPtr(_In_ UCHAR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoSizeT(_In_ UCHAR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoDWordPtr(_In_ UCHAR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoULongPtr(_In_ UCHAR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoIntPtr(_In_ UCHAR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoLongPtr(_In_ UCHAR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoPtrdiffT(_In_ UCHAR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UChartoSSIZET(_In_ UCHAR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toUChar(_In_ INT8 operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toInt8(_In_ INT8 operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toByte(_In_ INT8 operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toUShort(_In_ INT8 operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toWord(_In_ INT8 operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toShort(_In_ INT8 operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toUInt(_In_ INT8 operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toULong(_In_ INT8 operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toDWord(_In_ INT8 operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toInt(_In_ INT8 operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toLong(_In_ INT8 operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toULongLong(_In_ INT8 operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toInt64(_In_ INT8 operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toUIntPtr(_In_ INT8 operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toSizeT(_In_ INT8 operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toDWordPtr(_In_ INT8 operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toULongPtr(_In_ INT8 operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toIntPtr(_In_ INT8 operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toLongPtr(_In_ INT8 operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toPtrdiffT(_In_ INT8 operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int8toSSIZET(_In_ INT8 operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoUChar(_In_ BYTE operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoInt8(_In_ BYTE operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoByte(_In_ BYTE operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoUShort(_In_ BYTE operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoWord(_In_ BYTE operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoShort(_In_ BYTE operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoUInt(_In_ BYTE operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoULong(_In_ BYTE operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoDWord(_In_ BYTE operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoInt(_In_ BYTE operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoLong(_In_ BYTE operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoULongLong(_In_ BYTE operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoInt64(_In_ BYTE operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoUIntPtr(_In_ BYTE operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoSizeT(_In_ BYTE operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoDWordPtr(_In_ BYTE operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoULongPtr(_In_ BYTE operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoIntPtr(_In_ BYTE operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoLongPtr(_In_ BYTE operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoPtrdiffT(_In_ BYTE operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_BytetoSSIZET(_In_ BYTE operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoUChar(_In_ USHORT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoInt8(_In_ USHORT operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoByte(_In_ USHORT operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoUShort(_In_ USHORT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoWord(_In_ USHORT operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoShort(_In_ USHORT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoUInt(_In_ USHORT operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoULong(_In_ USHORT operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoDWord(_In_ USHORT operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoInt(_In_ USHORT operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoLong(_In_ USHORT operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoULongLong(_In_ USHORT operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoInt64(_In_ USHORT operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoUIntPtr(_In_ USHORT operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoSizeT(_In_ USHORT operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoDWordPtr(_In_ USHORT operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoULongPtr(_In_ USHORT operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoIntPtr(_In_ USHORT operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoLongPtr(_In_ USHORT operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoPtrdiffT(_In_ USHORT operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UShorttoSSIZET(_In_ USHORT operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoUChar(_In_ WORD operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoInt8(_In_ WORD operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoByte(_In_ WORD operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoUShort(_In_ WORD operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoWord(_In_ WORD operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoShort(_In_ WORD operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoUInt(_In_ WORD operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoULong(_In_ WORD operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoDWord(_In_ WORD operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoInt(_In_ WORD operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoLong(_In_ WORD operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoULongLong(_In_ WORD operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoInt64(_In_ WORD operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoUIntPtr(_In_ WORD operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoSizeT(_In_ WORD operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoDWordPtr(_In_ WORD operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoULongPtr(_In_ WORD operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoIntPtr(_In_ WORD operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoLongPtr(_In_ WORD operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoPtrdiffT(_In_ WORD operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_WordtoSSIZET(_In_ WORD operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoUChar(_In_ SHORT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoInt8(_In_ SHORT operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoByte(_In_ SHORT operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoUShort(_In_ SHORT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoWord(_In_ SHORT operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoShort(_In_ SHORT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoUInt(_In_ SHORT operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoULong(_In_ SHORT operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoDWord(_In_ SHORT operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoInt(_In_ SHORT operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoLong(_In_ SHORT operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoULongLong(_In_ SHORT operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoInt64(_In_ SHORT operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoUIntPtr(_In_ SHORT operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoSizeT(_In_ SHORT operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoDWordPtr(_In_ SHORT operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoULongPtr(_In_ SHORT operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoIntPtr(_In_ SHORT operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoLongPtr(_In_ SHORT operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoPtrdiffT(_In_ SHORT operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ShorttoSSIZET(_In_ SHORT operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoUChar(_In_ UINT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoInt8(_In_ UINT operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoByte(_In_ UINT operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoUShort(_In_ UINT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoWord(_In_ UINT operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoShort(_In_ UINT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoUInt(_In_ UINT operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoULong(_In_ UINT operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoDWord(_In_ UINT operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoInt(_In_ UINT operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoLong(_In_ UINT operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoULongLong(_In_ UINT operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoInt64(_In_ UINT operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoUIntPtr(_In_ UINT operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoSizeT(_In_ UINT operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoDWordPtr(_In_ UINT operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoULongPtr(_In_ UINT operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoIntPtr(_In_ UINT operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoLongPtr(_In_ UINT operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoPtrdiffT(_In_ UINT operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UInttoSSIZET(_In_ UINT operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoUChar(_In_ ULONG operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoInt8(_In_ ULONG operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoByte(_In_ ULONG operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoUShort(_In_ ULONG operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoWord(_In_ ULONG operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoShort(_In_ ULONG operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoUInt(_In_ ULONG operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoULong(_In_ ULONG operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoDWord(_In_ ULONG operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoInt(_In_ ULONG operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoLong(_In_ ULONG operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoULongLong(_In_ ULONG operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoInt64(_In_ ULONG operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoUIntPtr(_In_ ULONG operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoSizeT(_In_ ULONG operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoDWordPtr(_In_ ULONG operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoULongPtr(_In_ ULONG operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoIntPtr(_In_ ULONG operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoLongPtr(_In_ ULONG operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoPtrdiffT(_In_ ULONG operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongtoSSIZET(_In_ ULONG operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoUChar(_In_ DWORD operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoInt8(_In_ DWORD operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoByte(_In_ DWORD operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoUShort(_In_ DWORD operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoWord(_In_ DWORD operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoShort(_In_ DWORD operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoUInt(_In_ DWORD operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoULong(_In_ DWORD operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoDWord(_In_ DWORD operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoInt(_In_ DWORD operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoLong(_In_ DWORD operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoULongLong(_In_ DWORD operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoInt64(_In_ DWORD operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoUIntPtr(_In_ DWORD operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoSizeT(_In_ DWORD operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoDWordPtr(_In_ DWORD operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoULongPtr(_In_ DWORD operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoIntPtr(_In_ DWORD operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoLongPtr(_In_ DWORD operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoPtrdiffT(_In_ DWORD operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordtoSSIZET(_In_ DWORD operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoUChar(_In_ INT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoInt8(_In_ INT operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoByte(_In_ INT operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoUShort(_In_ INT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoWord(_In_ INT operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoShort(_In_ INT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoUInt(_In_ INT operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoULong(_In_ INT operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoDWord(_In_ INT operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoInt(_In_ INT operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoLong(_In_ INT operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoULongLong(_In_ INT operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoInt64(_In_ INT operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoUIntPtr(_In_ INT operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoSizeT(_In_ INT operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoDWordPtr(_In_ INT operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoULongPtr(_In_ INT operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoIntPtr(_In_ INT operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoLongPtr(_In_ INT operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoPtrdiffT(_In_ INT operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_InttoSSIZET(_In_ INT operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoUChar(_In_ LONG operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoInt8(_In_ LONG operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoByte(_In_ LONG operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoUShort(_In_ LONG operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoWord(_In_ LONG operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoShort(_In_ LONG operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoUInt(_In_ LONG operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoULong(_In_ LONG operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoDWord(_In_ LONG operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoInt(_In_ LONG operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoLong(_In_ LONG operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoULongLong(_In_ LONG operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoInt64(_In_ LONG operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoUIntPtr(_In_ LONG operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoSizeT(_In_ LONG operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoDWordPtr(_In_ LONG operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoULongPtr(_In_ LONG operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoIntPtr(_In_ LONG operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoLongPtr(_In_ LONG operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoPtrdiffT(_In_ LONG operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongtoSSIZET(_In_ LONG operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoUChar(_In_ ULONGLONG operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoInt8(_In_ ULONGLONG operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoByte(_In_ ULONGLONG operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoUShort(_In_ ULONGLONG operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoWord(_In_ ULONGLONG operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoShort(_In_ ULONGLONG operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoUInt(_In_ ULONGLONG operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoULong(_In_ ULONGLONG operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoDWord(_In_ ULONGLONG operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoInt(_In_ ULONGLONG operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoLong(_In_ ULONGLONG operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoULongLong(_In_ ULONGLONG operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoInt64(_In_ ULONGLONG operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoUIntPtr(_In_ ULONGLONG operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoSizeT(_In_ ULONGLONG operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoDWordPtr(_In_ ULONGLONG operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoULongPtr(_In_ ULONGLONG operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoIntPtr(_In_ ULONGLONG operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoLongPtr(_In_ ULONGLONG operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoPtrdiffT(_In_ ULONGLONG operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongLongtoSSIZET(_In_ ULONGLONG operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toUChar(_In_ INT64 operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toInt8(_In_ INT64 operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toByte(_In_ INT64 operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toUShort(_In_ INT64 operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toWord(_In_ INT64 operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toShort(_In_ INT64 operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toUInt(_In_ INT64 operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toULong(_In_ INT64 operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toDWord(_In_ INT64 operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toInt(_In_ INT64 operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toLong(_In_ INT64 operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toULongLong(_In_ INT64 operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toInt64(_In_ INT64 operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toUIntPtr(_In_ INT64 operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toSizeT(_In_ INT64 operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toDWordPtr(_In_ INT64 operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toULongPtr(_In_ INT64 operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toIntPtr(_In_ INT64 operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toLongPtr(_In_ INT64 operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toPtrdiffT(_In_ INT64 operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_Int64toSSIZET(_In_ INT64 operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoUChar(_In_ UINT_PTR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoInt8(_In_ UINT_PTR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoByte(_In_ UINT_PTR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoUShort(_In_ UINT_PTR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoWord(_In_ UINT_PTR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoShort(_In_ UINT_PTR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoUInt(_In_ UINT_PTR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoULong(_In_ UINT_PTR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoDWord(_In_ UINT_PTR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoInt(_In_ UINT_PTR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoLong(_In_ UINT_PTR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoULongLong(_In_ UINT_PTR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoInt64(_In_ UINT_PTR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoUIntPtr(_In_ UINT_PTR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoSizeT(_In_ UINT_PTR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoDWordPtr(_In_ UINT_PTR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoULongPtr(_In_ UINT_PTR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoIntPtr(_In_ UINT_PTR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoLongPtr(_In_ UINT_PTR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoPtrdiffT(_In_ UINT_PTR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_UIntPtrtoSSIZET(_In_ UINT_PTR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoUChar(_In_ SIZE_T operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoInt8(_In_ SIZE_T operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoByte(_In_ SIZE_T operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoUShort(_In_ SIZE_T operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoWord(_In_ SIZE_T operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoShort(_In_ SIZE_T operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoUInt(_In_ SIZE_T operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoULong(_In_ SIZE_T operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoDWord(_In_ SIZE_T operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoInt(_In_ SIZE_T operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoLong(_In_ SIZE_T operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoULongLong(_In_ SIZE_T operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoInt64(_In_ SIZE_T operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoUIntPtr(_In_ SIZE_T operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoSizeT(_In_ SIZE_T operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoDWordPtr(_In_ SIZE_T operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoULongPtr(_In_ SIZE_T operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoIntPtr(_In_ SIZE_T operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoLongPtr(_In_ SIZE_T operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoPtrdiffT(_In_ SIZE_T operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SizeTtoSSIZET(_In_ SIZE_T operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoUChar(_In_ DWORD_PTR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoInt8(_In_ DWORD_PTR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoByte(_In_ DWORD_PTR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoUShort(_In_ DWORD_PTR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoWord(_In_ DWORD_PTR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoShort(_In_ DWORD_PTR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoUInt(_In_ DWORD_PTR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoULong(_In_ DWORD_PTR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoDWord(_In_ DWORD_PTR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoInt(_In_ DWORD_PTR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoLong(_In_ DWORD_PTR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoULongLong(_In_ DWORD_PTR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoInt64(_In_ DWORD_PTR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoUIntPtr(_In_ DWORD_PTR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoSizeT(_In_ DWORD_PTR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoDWordPtr(_In_ DWORD_PTR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoULongPtr(_In_ DWORD_PTR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoIntPtr(_In_ DWORD_PTR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoLongPtr(_In_ DWORD_PTR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoPtrdiffT(_In_ DWORD_PTR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_DWordPtrtoSSIZET(_In_ DWORD_PTR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoUChar(_In_ ULONG_PTR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoInt8(_In_ ULONG_PTR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoByte(_In_ ULONG_PTR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoUShort(_In_ ULONG_PTR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoWord(_In_ ULONG_PTR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoShort(_In_ ULONG_PTR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoUInt(_In_ ULONG_PTR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoULong(_In_ ULONG_PTR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoDWord(_In_ ULONG_PTR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoInt(_In_ ULONG_PTR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoLong(_In_ ULONG_PTR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoULongLong(_In_ ULONG_PTR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoInt64(_In_ ULONG_PTR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoUIntPtr(_In_ ULONG_PTR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoSizeT(_In_ ULONG_PTR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoDWordPtr(_In_ ULONG_PTR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoULongPtr(_In_ ULONG_PTR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoIntPtr(_In_ ULONG_PTR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoLongPtr(_In_ ULONG_PTR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoPtrdiffT(_In_ ULONG_PTR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_ULongPtrtoSSIZET(_In_ ULONG_PTR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoUChar(_In_ INT_PTR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoInt8(_In_ INT_PTR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoByte(_In_ INT_PTR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoUShort(_In_ INT_PTR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoWord(_In_ INT_PTR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoShort(_In_ INT_PTR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoUInt(_In_ INT_PTR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoULong(_In_ INT_PTR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoDWord(_In_ INT_PTR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoInt(_In_ INT_PTR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoLong(_In_ INT_PTR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoULongLong(_In_ INT_PTR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoInt64(_In_ INT_PTR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoUIntPtr(_In_ INT_PTR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoSizeT(_In_ INT_PTR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoDWordPtr(_In_ INT_PTR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoULongPtr(_In_ INT_PTR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoIntPtr(_In_ INT_PTR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoLongPtr(_In_ INT_PTR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoPtrdiffT(_In_ INT_PTR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_IntPtrtoSSIZET(_In_ INT_PTR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoUChar(_In_ LONG_PTR operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoInt8(_In_ LONG_PTR operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoByte(_In_ LONG_PTR operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoUShort(_In_ LONG_PTR operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoWord(_In_ LONG_PTR operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoShort(_In_ LONG_PTR operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoUInt(_In_ LONG_PTR operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoULong(_In_ LONG_PTR operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoDWord(_In_ LONG_PTR operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoInt(_In_ LONG_PTR operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoLong(_In_ LONG_PTR operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoULongLong(_In_ LONG_PTR operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoInt64(_In_ LONG_PTR operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoUIntPtr(_In_ LONG_PTR operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoSizeT(_In_ LONG_PTR operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoDWordPtr(_In_ LONG_PTR operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoULongPtr(_In_ LONG_PTR operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoIntPtr(_In_ LONG_PTR operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoLongPtr(_In_ LONG_PTR operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoPtrdiffT(_In_ LONG_PTR operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_LongPtrtoSSIZET(_In_ LONG_PTR operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoUChar(_In_ ptrdiff_t operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoInt8(_In_ ptrdiff_t operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoByte(_In_ ptrdiff_t operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoUShort(_In_ ptrdiff_t operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoWord(_In_ ptrdiff_t operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoShort(_In_ ptrdiff_t operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoUInt(_In_ ptrdiff_t operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoULong(_In_ ptrdiff_t operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoDWord(_In_ ptrdiff_t operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoInt(_In_ ptrdiff_t operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoLong(_In_ ptrdiff_t operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoULongLong(_In_ ptrdiff_t operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoInt64(_In_ ptrdiff_t operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoUIntPtr(_In_ ptrdiff_t operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoSizeT(_In_ ptrdiff_t operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoDWordPtr(_In_ ptrdiff_t operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoULongPtr(_In_ ptrdiff_t operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoIntPtr(_In_ ptrdiff_t operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoLongPtr(_In_ ptrdiff_t operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoPtrdiffT(_In_ ptrdiff_t operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_PtrdiffTtoSSIZET(_In_ ptrdiff_t operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoUChar(_In_ SSIZE_T operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoInt8(_In_ SSIZE_T operand, _Out_ INT8 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoByte(_In_ SSIZE_T operand, _Out_ BYTE * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoUShort(_In_ SSIZE_T operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoWord(_In_ SSIZE_T operand, _Out_ WORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoShort(_In_ SSIZE_T operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoUInt(_In_ SSIZE_T operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoULong(_In_ SSIZE_T operand, _Out_ ULONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoDWord(_In_ SSIZE_T operand, _Out_ DWORD * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoInt(_In_ SSIZE_T operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoLong(_In_ SSIZE_T operand, _Out_ LONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoULongLong(_In_ SSIZE_T operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoInt64(_In_ SSIZE_T operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoUIntPtr(_In_ SSIZE_T operand, _Out_ UINT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoSizeT(_In_ SSIZE_T operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoDWordPtr(_In_ SSIZE_T operand, _Out_ DWORD_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoULongPtr(_In_ SSIZE_T operand, _Out_ ULONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoIntPtr(_In_ SSIZE_T operand, _Out_ INT_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoLongPtr(_In_ SSIZE_T operand, _Out_ LONG_PTR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoPtrdiffT(_In_ SSIZE_T operand, _Out_ ptrdiff_t * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}
__MINGW_INTSAFE_API __mingw_intsafe_SSIZETtoSSIZET(_In_ SSIZE_T operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

/* TODO: add 253 missing functions */
