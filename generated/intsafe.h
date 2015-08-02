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
    HRESULT name(_In_ type_src operand, _Out_ type_dest * result) \
    __MINGW_INTSAFE_BODY(add, operand, 0)

#define __MINGW_INTSAFE_MATH(name, type, operation) \
    HRESULT name(_In_ type x, _In_ type y, _Out_ type * result) \
    __MINGW_INTSAFE_BODY(operation, x, y)

__MINGW_INTSAFE_CONV(UShortToUChar, USHORT, UCHAR)
__MINGW_INTSAFE_CONV(UShortToShort, USHORT, SHORT)
__MINGW_INTSAFE_CONV(ShortToUChar, SHORT, UCHAR)
__MINGW_INTSAFE_CONV(ShortToUShort, SHORT, USHORT)
__MINGW_INTSAFE_CONV(UIntToUChar, UINT, UCHAR)
__MINGW_INTSAFE_CONV(UIntToUShort, UINT, USHORT)
__MINGW_INTSAFE_CONV(UIntToShort, UINT, SHORT)
__MINGW_INTSAFE_CONV(UIntToInt, UINT, INT)
__MINGW_INTSAFE_CONV(UIntToLong, UINT, LONG)
__MINGW_INTSAFE_CONV(UIntToIntPtr, UINT, INT_PTR)
__MINGW_INTSAFE_CONV(UIntToLongPtr, UINT, LONG_PTR)
__MINGW_INTSAFE_CONV(ULongToUChar, ULONG, UCHAR)
__MINGW_INTSAFE_CONV(ULongToUShort, ULONG, USHORT)
__MINGW_INTSAFE_CONV(ULongToShort, ULONG, SHORT)
__MINGW_INTSAFE_CONV(ULongToUInt, ULONG, UINT)
__MINGW_INTSAFE_CONV(ULongToInt, ULONG, INT)
__MINGW_INTSAFE_CONV(ULongToLong, ULONG, LONG)
__MINGW_INTSAFE_CONV(ULongToUIntPtr, ULONG, UINT_PTR)
__MINGW_INTSAFE_CONV(ULongToIntPtr, ULONG, INT_PTR)
__MINGW_INTSAFE_CONV(ULongToLongPtr, ULONG, LONG_PTR)
__MINGW_INTSAFE_CONV(IntToUChar, INT, UCHAR)
__MINGW_INTSAFE_CONV(IntToUShort, INT, USHORT)
__MINGW_INTSAFE_CONV(IntToShort, INT, SHORT)
__MINGW_INTSAFE_CONV(IntToUInt, INT, UINT)
__MINGW_INTSAFE_CONV(IntToULong, INT, ULONG)
__MINGW_INTSAFE_CONV(IntToUIntPtr, INT, UINT_PTR)
__MINGW_INTSAFE_CONV(IntToULongPtr, INT, ULONG_PTR)
__MINGW_INTSAFE_CONV(IntToULongLong, INT, ULONGLONG)
__MINGW_INTSAFE_CONV(LongToUChar, LONG, UCHAR)
__MINGW_INTSAFE_CONV(LongToUShort, LONG, USHORT)
__MINGW_INTSAFE_CONV(LongToShort, LONG, SHORT)
__MINGW_INTSAFE_CONV(LongToUInt, LONG, UINT)
__MINGW_INTSAFE_CONV(LongToULong, LONG, ULONG)
__MINGW_INTSAFE_CONV(LongToInt, LONG, INT)
__MINGW_INTSAFE_CONV(LongToUIntPtr, LONG, UINT_PTR)
__MINGW_INTSAFE_CONV(LongToULongPtr, LONG, ULONG_PTR)
__MINGW_INTSAFE_CONV(LongToIntPtr, LONG, INT_PTR)
__MINGW_INTSAFE_CONV(LongToULongLong, LONG, ULONGLONG)
__MINGW_INTSAFE_CONV(UIntPtrToUInt, UINT_PTR, UINT)
__MINGW_INTSAFE_CONV(UIntPtrToULong, UINT_PTR, ULONG)
__MINGW_INTSAFE_CONV(UIntPtrToInt, UINT_PTR, INT)
__MINGW_INTSAFE_CONV(UIntPtrToLong, UINT_PTR, LONG)
__MINGW_INTSAFE_CONV(UIntPtrToIntPtr, UINT_PTR, INT_PTR)
__MINGW_INTSAFE_CONV(UIntPtrToLongPtr, UINT_PTR, LONG_PTR)
__MINGW_INTSAFE_CONV(UIntPtrToInt64, UINT_PTR, INT64)
__MINGW_INTSAFE_CONV(ULongPtrToUInt, ULONG_PTR, UINT)
__MINGW_INTSAFE_CONV(ULongPtrToULong, ULONG_PTR, ULONG)
__MINGW_INTSAFE_CONV(ULongPtrToInt, ULONG_PTR, INT)
__MINGW_INTSAFE_CONV(ULongPtrToLong, ULONG_PTR, LONG)
__MINGW_INTSAFE_CONV(ULongPtrToUIntPtr, ULONG_PTR, UINT_PTR)
__MINGW_INTSAFE_CONV(ULongPtrToIntPtr, ULONG_PTR, INT_PTR)
__MINGW_INTSAFE_CONV(ULongPtrToLongPtr, ULONG_PTR, LONG_PTR)
__MINGW_INTSAFE_CONV(ULongPtrToInt64, ULONG_PTR, INT64)
__MINGW_INTSAFE_CONV(IntPtrToUInt, INT_PTR, UINT)
__MINGW_INTSAFE_CONV(IntPtrToULong, INT_PTR, ULONG)
__MINGW_INTSAFE_CONV(IntPtrToInt, INT_PTR, INT)
__MINGW_INTSAFE_CONV(IntPtrToLong, INT_PTR, LONG)
__MINGW_INTSAFE_CONV(IntPtrToUIntPtr, INT_PTR, UINT_PTR)
__MINGW_INTSAFE_CONV(IntPtrToULongPtr, INT_PTR, ULONG_PTR)
__MINGW_INTSAFE_CONV(IntPtrToULongLong, INT_PTR, ULONGLONG)
__MINGW_INTSAFE_CONV(LongPtrToUInt, LONG_PTR, UINT)
__MINGW_INTSAFE_CONV(LongPtrToULong, LONG_PTR, ULONG)
__MINGW_INTSAFE_CONV(LongPtrToInt, LONG_PTR, INT)
__MINGW_INTSAFE_CONV(LongPtrToLong, LONG_PTR, LONG)
__MINGW_INTSAFE_CONV(LongPtrToUIntPtr, LONG_PTR, UINT_PTR)
__MINGW_INTSAFE_CONV(LongPtrToULongPtr, LONG_PTR, ULONG_PTR)
__MINGW_INTSAFE_CONV(LongPtrToIntPtr, LONG_PTR, INT_PTR)
__MINGW_INTSAFE_CONV(LongPtrToULongLong, LONG_PTR, ULONGLONG)
__MINGW_INTSAFE_CONV(ULongLongToUInt, ULONGLONG, UINT)
__MINGW_INTSAFE_CONV(ULongLongToULong, ULONGLONG, ULONG)
__MINGW_INTSAFE_CONV(ULongLongToInt, ULONGLONG, INT)
__MINGW_INTSAFE_CONV(ULongLongToLong, ULONGLONG, LONG)
__MINGW_INTSAFE_CONV(ULongLongToUIntPtr, ULONGLONG, UINT_PTR)
__MINGW_INTSAFE_CONV(ULongLongToULongPtr, ULONGLONG, ULONG_PTR)
__MINGW_INTSAFE_CONV(ULongLongToIntPtr, ULONGLONG, INT_PTR)
__MINGW_INTSAFE_CONV(ULongLongToLongPtr, ULONGLONG, LONG_PTR)
__MINGW_INTSAFE_CONV(ULongLongToInt64, ULONGLONG, INT64)
__MINGW_INTSAFE_CONV(Int64ToUInt, INT64, UINT)
__MINGW_INTSAFE_CONV(Int64ToULong, INT64, ULONG)
__MINGW_INTSAFE_CONV(Int64ToInt, INT64, INT)
__MINGW_INTSAFE_CONV(Int64ToLong, INT64, LONG)
__MINGW_INTSAFE_CONV(Int64ToUIntPtr, INT64, UINT_PTR)
__MINGW_INTSAFE_CONV(Int64ToULongPtr, INT64, ULONG_PTR)
__MINGW_INTSAFE_CONV(Int64ToIntPtr, INT64, INT_PTR)
__MINGW_INTSAFE_CONV(Int64ToLongPtr, INT64, LONG_PTR)
__MINGW_INTSAFE_CONV(Int64ToULongLong, INT64, ULONGLONG)

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

__MINGW_INTSAFE_CONV(UShortToChar, USHORT, CHAR)
__MINGW_INTSAFE_CONV(ShortToChar, SHORT, CHAR)
__MINGW_INTSAFE_CONV(UIntToChar, UINT, CHAR)
__MINGW_INTSAFE_CONV(ULongToChar, ULONG, CHAR)
__MINGW_INTSAFE_CONV(IntToChar, INT, CHAR)
__MINGW_INTSAFE_CONV(LongToChar, LONG, CHAR)

__MINGW_INTSAFE_MATH(UInt8Add, UINT8, add)
__MINGW_INTSAFE_MATH(Int8Add, INT8, add)
__MINGW_INTSAFE_MATH(UShortAdd, USHORT, add)
__MINGW_INTSAFE_MATH(ShortAdd, SHORT, add)
__MINGW_INTSAFE_MATH(UIntAdd, UINT, add)
__MINGW_INTSAFE_MATH(ULongAdd, ULONG, add)
__MINGW_INTSAFE_MATH(IntAdd, INT, add)
__MINGW_INTSAFE_MATH(LongAdd, LONG, add)
__MINGW_INTSAFE_MATH(UIntPtrAdd, UINT_PTR, add)
__MINGW_INTSAFE_MATH(ULongPtrAdd, ULONG_PTR, add)
__MINGW_INTSAFE_MATH(IntPtrAdd, INT_PTR, add)
__MINGW_INTSAFE_MATH(LongPtrAdd, LONG_PTR, add)
__MINGW_INTSAFE_MATH(ULongLongAdd, ULONGLONG, add)
__MINGW_INTSAFE_MATH(LongLongAdd, LONGLONG, add)
__MINGW_INTSAFE_MATH(UInt8Sub, UINT8, sub)
__MINGW_INTSAFE_MATH(Int8Sub, INT8, sub)
__MINGW_INTSAFE_MATH(UShortSub, USHORT, sub)
__MINGW_INTSAFE_MATH(ShortSub, SHORT, sub)
__MINGW_INTSAFE_MATH(UIntSub, UINT, sub)
__MINGW_INTSAFE_MATH(ULongSub, ULONG, sub)
__MINGW_INTSAFE_MATH(IntSub, INT, sub)
__MINGW_INTSAFE_MATH(LongSub, LONG, sub)
__MINGW_INTSAFE_MATH(UIntPtrSub, UINT_PTR, sub)
__MINGW_INTSAFE_MATH(ULongPtrSub, ULONG_PTR, sub)
__MINGW_INTSAFE_MATH(IntPtrSub, INT_PTR, sub)
__MINGW_INTSAFE_MATH(LongPtrSub, LONG_PTR, sub)
__MINGW_INTSAFE_MATH(ULongLongSub, ULONGLONG, sub)
__MINGW_INTSAFE_MATH(LongLongSub, LONGLONG, sub)
__MINGW_INTSAFE_MATH(UInt8Mult, UINT8, mul)
__MINGW_INTSAFE_MATH(Int8Mult, INT8, mul)
__MINGW_INTSAFE_MATH(UShortMult, USHORT, mul)
__MINGW_INTSAFE_MATH(ShortMult, SHORT, mul)
__MINGW_INTSAFE_MATH(UIntMult, UINT, mul)
__MINGW_INTSAFE_MATH(ULongMult, ULONG, mul)
__MINGW_INTSAFE_MATH(IntMult, INT, mul)
__MINGW_INTSAFE_MATH(LongMult, LONG, mul)
__MINGW_INTSAFE_MATH(UIntPtrMult, UINT_PTR, mul)
__MINGW_INTSAFE_MATH(ULongPtrMult, ULONG_PTR, mul)
__MINGW_INTSAFE_MATH(IntPtrMult, INT_PTR, mul)
__MINGW_INTSAFE_MATH(LongPtrMult, LONG_PTR, mul)
__MINGW_INTSAFE_MATH(ULongLongMult, ULONGLONG, mul)
__MINGW_INTSAFE_MATH(LongLongMult, LONGLONG, mul)

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
