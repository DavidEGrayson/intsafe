/*
 * intsafe_mscompat.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_INTSAFE_MSCOMPAT_H_INCLUDED
#define __MINGW_INTSAFE_MSCOMPAT_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#include "intsafe_8.h"
#include "intsafe_16.h"
#include "intsafe_32.h"
#include "intsafe_64.h"
#include "intsafe_intptr_t.h"
#include "intsafe_uintptr_t.h"
#include "intsafe_ptrdiff_t.h"
#include "intsafe_size_t.h"

/* Make sure this header is available only if applicable */
#if !defined(__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_CHAR_BIT) && \
    (defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T) || \
        defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T)) && \
    (defined(__MINGW_INTSAFE_SIZE_T_IS_UINT32_T) || \
        defined(__MINGW_INTSAFE_SIZE_T_IS_UINT64_T)) && \
    (defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T) || \
        defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)) && \
    (defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T) || \
        defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T))

#	ifdef __cplusplus
extern "C" {
#	endif

/* It is a good idea to put #include <windows.h> before #include <intsafe.h>
 * to check all windows.h integral typedefs. Otherwise, only platform dependent
 * integral types are checked. This is fairly good but there's a potential
 * problem if MS changes those typedefs. Please, see intsafe_static_checks.h
 * for more details about compile-time test suites for these types.
 */
#	if !defined(_INC_WINDOWS) && /* mingw-w64 SDK */ \
        !defined(_WINDOWS_) && /* mingw-w64 SDK */ \
        !defined(_WINDOWS_H) /* mingw.org/Cygwin SDKs */

/* Common windows.h typedefs are hard-coded to platform dependent types
 * using macros if windows.h is not included before intsafe.h header. As of
 * this writting (2010), all of these definitions are correct but some of them
 * might be changed in the future to adapt changes on windows.h side. Please
 * read comments in intsafe_static_checks.h for rationale for avoiding inclusion
 * of windows.h header.
 *
 * You should not be worried about namespace pollution since all of macros
 * will be #undef later.
 */
#       define __MINGW_INTSAFE_MSCOMPAT_UNDEF_COMMON_WINDOWS_H_TYPEDEFS 1

#       if defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T)
#           define DWORD_PTR unsigned long long
#           define UINT_PTR unsigned long long

#       elif defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T)
#           define DWORD_PTR unsigned long
#           define UINT_PTR unsigned int

#       else
/* intsafe_static_checks.h produces compile errors */
#       endif

#       if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
#           define LONG_PTR long long
#           define INT_PTR long long

#       elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
#           define LONG_PTR long
#           define INT_PTR int

#       else
/* intsafe_static_checks.h produces compile errors */
#       endif

#       define ULONG_PTR DWORD_PTR
#       define SIZE_T ULONG_PTR
#       define SSIZE_T LONG_PTR
#       define ULONGLONG unsigned long long
#       define INT64 long long
#       define DWORD unsigned long
#       define ULONG unsigned long
#       define UINT unsigned int
#       define LONG long
#       define INT int
#       define USHORT unsigned short
#       define WORD USHORT
#       define SHORT short
#       define BYTE unsigned char
#       define UCHAR BYTE
#       define CHAR char

#   endif /* !_INC_WINDOWS_ &&
        !_WINDOWS_ &&
        !_WINDOWS_H */

#   define __MINGW_INTSAFE_CONV_MAPPING(MsFn, MsT0, MsT1, MgwFn, MgwT0, MgwT1) \
    __MINGW_INTSAFEAPI \
    MsFn(MsT0 src, MsT1* dest) \
    { \
        return __MINGW_INTSAFE_PREPARE_PREFIX(MgwFn)( \
            (MgwT0)(src), (MgwT1*)(dest) \
        ); \
    }

#   define __MINGW_INTSAFE_MATH_MAPPING(MsFn, MsT, MgwFn, MgwT) \
    __MINGW_INTSAFEAPI \
    MsFn(MsT op1, MsT op2, MsT* result) \
    { \
        return __MINGW_INTSAFE_PREPARE_PREFIX(MgwFn)( \
            (MgwT)(op1), (MgwT)(op2), (MgwT*)(result) \
        ); \
    }

/**
 * @defgroup ConversionFunction Safe Conversion Functions For Integral Types
 * Set of functions designed to provide type conversions and perform validity
 * checks, and to do so with minimal impact on performance.
 */
/* DWordPtrTo* => UIntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToDWord, DWORD_PTR, DWORD,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToInt, DWORD_PTR, INT,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToInt64, DWORD_PTR, INT64,
    UIntPtrTToInt64, uintptr_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToIntPtr, DWORD_PTR, INT_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToLong, DWORD_PTR, LONG,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToLongPtr, DWORD_PTR, LONG_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToPtrdiffT, DWORD_PTR, ptrdiff_t,
    UIntPtrTToPtrdiffT, uintptr_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToSSIZET, DWORD_PTR, SSIZE_T,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToUInt, DWORD_PTR, UINT,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToUIntPtr, DWORD_PTR, UINT_PTR,
    UIntPtrTToUIntPtrT, uintptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordPtrToULong, DWORD_PTR, ULONG,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

/* DWordTo* => UInt32To* */
__MINGW_INTSAFE_CONV_MAPPING(
    DWordToByte, DWORD, BYTE,
    UInt32ToUInt8, uint32_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    DWordToChar, DWORD, CHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    DWordToChar, DWORD, CHAR,
    UInt32ToInt8, uint32_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToInt, DWORD, INT,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToIntPtr, DWORD, INT_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToLong, DWORD, LONG,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToLongPtr, DWORD, LONG_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToPtrdiffT, DWORD, ptrdiff_t,
    UInt32ToPtrdiffT, uint32_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToShort, DWORD, SHORT,
    UInt32ToInt16, uint32_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToSSIZET, DWORD, SSIZE_T,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToUChar, DWORD, UCHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToUInt, DWORD, UINT,
    UInt32ToUInt32, uint32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToUIntPtr, DWORD, UINT_PTR,
    UInt32ToUIntPtrT, uint32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToUShort, DWORD, USHORT,
    UInt32ToUInt16, uint32_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    DWordToWord, DWORD, WORD,
    UInt32ToUInt16, uint32_t, uint16_t
)

/* Int64To* */
__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToDWord, INT64, DWORD,
    Int64ToUInt32, int64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToDWordPtr, INT64, DWORD_PTR,
    Int64ToUIntPtrT, int64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToInt, INT64, INT,
    Int64ToInt32, int64_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToIntPtr, INT64, INT_PTR,
    Int64ToIntPtrT, int64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToLong, INT64, LONG,
    Int64ToInt32, int64_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToLongPtr, INT64, LONG_PTR,
    Int64ToIntPtrT, int64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToPtrdiffT, INT64, ptrdiff_t,
    Int64ToPtrdiffT, int64_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToSizeT, INT64, size_t,
    Int64ToSizeT, int64_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToSIZET, INT64, SIZE_T,
    Int64ToUIntPtrT, int64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToSSIZET, INT64, SSIZE_T,
    Int64ToIntPtrT, int64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToUInt, INT64, UINT,
    Int64ToUInt32, int64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToUIntPtr, INT64, UINT_PTR,
    Int64ToUIntPtrT, int64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToULong, INT64, ULONG,
    Int64ToUInt32, int64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToULongLong, INT64, ULONGLONG,
    Int64ToUInt64, int64_t, uint64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    Int64ToULongPtr, INT64, ULONG_PTR,
    Int64ToUIntPtrT, int64_t, uintptr_t
)

/* IntPtrTo* => IntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToDWord, INT_PTR, DWORD,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToDWordPtr, INT_PTR, DWORD_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToInt, INT_PTR, INT,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToLong, INT_PTR, LONG,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToSizeT, INT_PTR, size_t,
    IntPtrTToSizeT, intptr_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToSIZET, INT_PTR, SIZE_T,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToUInt, INT_PTR, UINT,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToUIntPtr, INT_PTR, UINT_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToULong, INT_PTR, ULONG,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToULongLong, INT_PTR, ULONGLONG,
    IntPtrTToUInt64, intptr_t, uint64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntPtrToULongPtr, INT_PTR, ULONG_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

/* IntTo* => Int32To* */
__MINGW_INTSAFE_CONV_MAPPING(
    IntToByte, INT, BYTE,
    Int32ToUInt8, int32_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    IntToChar, INT, CHAR,
    Int32ToUInt8, int32_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    IntToChar, INT, CHAR,
    Int32ToInt8, int32_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    IntToDWord, INT, DWORD,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToDWordPtr, INT, DWORD_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToShort, INT, SHORT,
    Int32ToInt16, int32_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToSizeT, INT, size_t,
    Int32ToSizeT, int32_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToSIZET, INT, SIZE_T,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToUChar, INT, UCHAR,
    Int32ToUInt8, int32_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToUInt, INT, UINT,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToUIntPtr, INT, UINT_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToULong, INT, ULONG,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToULongLong, INT, ULONGLONG,
    Int32ToUInt64, int32_t, uint64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToULongPtr, INT, ULONG_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToUShort, INT, USHORT,
    Int32ToUInt16, int32_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    IntToWord, INT, WORD,
    Int32ToUInt16, int32_t, uint16_t
)

/* LongPtrTo* => IntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToDWord, LONG_PTR, DWORD,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToDWordPtr, LONG_PTR, DWORD_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToInt, LONG_PTR, INT,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToIntPtr, LONG_PTR, INT_PTR,
    IntPtrTToIntPtrT, intptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToLong, LONG_PTR, LONG,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToSizeT, LONG_PTR, size_t,
    IntPtrTToSizeT, intptr_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToSIZET, LONG_PTR, SIZE_T,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToUInt, LONG_PTR, UINT,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToUIntPtr, LONG_PTR, UINT_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToULong, LONG_PTR, ULONG,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToULongLong, LONG_PTR, ULONGLONG,
    IntPtrTToUInt64, intptr_t, uint64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongPtrToULongPtr, LONG_PTR, ULONG_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

/* LongTo* => Int32To* */
__MINGW_INTSAFE_CONV_MAPPING(
    LongToByte, LONG, BYTE,
    Int32ToUInt8, int32_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    LongToChar, LONG, CHAR,
    Int32ToUInt8, int32_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    LongToChar, LONG, CHAR,
    Int32ToInt8, int32_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    LongToDWord, LONG, DWORD,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToDWordPtr, LONG, DWORD_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToInt, LONG, INT,
    Int32ToInt32, int32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToIntPtr, LONG, INT_PTR,
    Int32ToIntPtrT, int32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToPtrdiffT, LONG, ptrdiff_t,
    Int32ToPtrdiffT, int32_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToShort, LONG, SHORT,
    Int32ToInt16, int32_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToSizeT, LONG, size_t,
    Int32ToSizeT, int32_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToSIZET, LONG, SIZE_T,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToUChar, LONG, UCHAR,
    Int32ToUInt8, int32_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToUInt, LONG, UINT,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToUIntPtr, LONG, UINT_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToULong, LONG, ULONG,
    Int32ToUInt32, int32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToULongLong, LONG, ULONGLONG,
    Int32ToUInt64, int32_t, uint64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToULongPtr, LONG, ULONG_PTR,
    Int32ToUIntPtrT, int32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToUShort, LONG, USHORT,
    Int32ToUInt16, int32_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    LongToWord, LONG, WORD,
    Int32ToUInt16, int32_t, uint16_t
)

/* PtrdiffTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToDWord, ptrdiff_t, DWORD,
    PtrdiffTToUInt32, ptrdiff_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToDWordPtr, ptrdiff_t, DWORD_PTR,
    PtrdiffTToUIntPtrT, ptrdiff_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToInt, ptrdiff_t, INT,
    PtrdiffTToInt32, ptrdiff_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToLong, ptrdiff_t, LONG,
    PtrdiffTToInt32, ptrdiff_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToSizeT, ptrdiff_t, size_t,
    PtrdiffTToSizeT, ptrdiff_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToSIZET, ptrdiff_t, SIZE_T,
    PtrdiffTToUIntPtrT, ptrdiff_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToUInt, ptrdiff_t, UINT,
    PtrdiffTToUInt32, ptrdiff_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToUIntPtr, ptrdiff_t, UINT_PTR,
    PtrdiffTToUIntPtrT, ptrdiff_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToULong, ptrdiff_t, ULONG,
    PtrdiffTToUInt32, ptrdiff_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    PtrdiffTToULongPtr, ptrdiff_t, ULONG_PTR,
    PtrdiffTToUIntPtrT, ptrdiff_t, uintptr_t
)

/* ShortTo* => Int16To* */
__MINGW_INTSAFE_CONV_MAPPING(
    ShortToByte, SHORT, BYTE,
    Int16ToUInt8, int16_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    ShortToChar, SHORT, CHAR,
    Int16ToUInt8, int16_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    ShortToChar, SHORT, CHAR,
    Int16ToInt8, int16_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    ShortToUChar, SHORT, UCHAR,
    Int16ToUInt8, int16_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ShortToUShort, SHORT, USHORT,
    Int16ToUInt16, int16_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ShortToWord, SHORT, WORD,
    Int16ToUInt16, int16_t, uint16_t
)

/* SizeTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToDWord, size_t, DWORD,
    SizeTToUInt32, size_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToInt, size_t, INT,
    SizeTToInt32, size_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToInt64, size_t, INT64,
    SizeTToInt64, size_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToIntPtr, size_t, INT_PTR,
    SizeTToIntPtrT, size_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToLong, size_t, LONG,
    SizeTToInt32, size_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToLongPtr, size_t, LONG_PTR,
    SizeTToIntPtrT, size_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToPtrdiffT, size_t, ptrdiff_t,
    SizeTToPtrdiffT, size_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToSSIZET, size_t, SSIZE_T,
    SizeTToIntPtrT, size_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToUInt, size_t, UINT,
    SizeTToUInt32, size_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SizeTToULong, size_t, ULONG,
    SizeTToUInt32, size_t, uint32_t
)

/* SIZETTo* => UIntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToDWord, SIZE_T, DWORD,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToInt, SIZE_T, INT,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToInt64, SIZE_T, INT64,
    UIntPtrTToInt64, uintptr_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToIntPtr, SIZE_T, INT_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToLong, SIZE_T, LONG,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToLongPtr, SIZE_T, LONG_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToPtrdiffT, SIZE_T, ptrdiff_t,
    UIntPtrTToPtrdiffT, uintptr_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToSSIZET, SIZE_T, SSIZE_T,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToUInt, SIZE_T, UINT,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SIZETToULong, SIZE_T, ULONG,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

/* SSIZETTo* => IntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToDWord, SSIZE_T, DWORD,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToDWordPtr, SSIZE_T, DWORD_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToInt, SSIZE_T, INT,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToIntPtr, SSIZE_T, INT_PTR,
    IntPtrTToIntPtrT, intptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToLong, SSIZE_T, LONG,
    IntPtrTToInt32, intptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToSizeT, SSIZE_T, size_t,
    IntPtrTToSizeT, intptr_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToSIZET, SSIZE_T, SIZE_T,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToUInt, SSIZE_T, UINT,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToUIntPtr, SSIZE_T, UINT_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToULong, SSIZE_T, ULONG,
    IntPtrTToUInt32, intptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    SSIZETToULongPtr, SSIZE_T, ULONG_PTR,
    IntPtrTToUIntPtrT, intptr_t, uintptr_t
)

/* UIntPtrTo* => UIntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToDWord, UINT_PTR, DWORD,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToInt, UINT_PTR, INT,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToInt64, UINT_PTR, INT64,
    UIntPtrTToInt64, uintptr_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToIntPtr, UINT_PTR, INT_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToLong, UINT_PTR, LONG,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToLongPtr, UINT_PTR, LONG_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToSSIZET, UINT_PTR, SSIZE_T,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToUInt, UINT_PTR, UINT,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntPtrToULong, UINT_PTR, ULONG,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

/* UIntTo* => UInt32To* */
__MINGW_INTSAFE_CONV_MAPPING(
    UIntToByte, UINT, BYTE,
    UInt32ToUInt8, uint32_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    UIntToChar, UINT, CHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    UIntToChar, UINT, CHAR,
    UInt32ToInt8, uint32_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToInt, UINT, INT,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToIntPtr, UINT, INT_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToLong, UINT, LONG,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToLongPtr, UINT, LONG_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToPtrdiffT, UINT, ptrdiff_t,
    UInt32ToPtrdiffT, uint32_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToShort, UINT, SHORT,
    UInt32ToInt16, uint32_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToSSIZET, UINT, SSIZE_T,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToUChar, UINT, UCHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToUShort, UINT, USHORT,
    UInt32ToUInt16, uint32_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UIntToWord, UINT, WORD,
    UInt32ToUInt16, uint32_t, uint16_t
)

/* ULongLongTo* => UInt64To* */
__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToDWord, ULONGLONG, DWORD,
    UInt64ToUInt32, uint64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToDWordPtr, ULONGLONG, DWORD_PTR,
    UInt64ToUIntPtrT, uint64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToInt, ULONGLONG, INT,
    UInt64ToInt32, uint64_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToInt64, ULONGLONG, INT64,
    UInt64ToInt64, uint64_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToIntPtr, ULONGLONG, INT_PTR,
    UInt64ToIntPtrT, uint64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToLong, ULONGLONG, LONG,
    UInt64ToInt32, uint64_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToLongPtr, ULONGLONG, LONG_PTR,
    UInt64ToIntPtrT, uint64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToPtrdiffT, ULONGLONG, ptrdiff_t,
    UInt64ToPtrdiffT, uint64_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToSizeT, ULONGLONG, size_t,
    UInt64ToSizeT, uint64_t, size_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToSIZET, ULONGLONG, SIZE_T,
    UInt64ToUIntPtrT, uint64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToSSIZET, ULONGLONG, SSIZE_T,
    UInt64ToIntPtrT, uint64_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToUInt, ULONGLONG, UINT,
    UInt64ToUInt32, uint64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToUIntPtr, ULONGLONG, UINT_PTR,
    UInt64ToUIntPtrT, uint64_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToULong, ULONGLONG, ULONG,
    UInt64ToUInt32, uint64_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongLongToULongPtr, ULONGLONG, ULONG_PTR,
    UInt64ToUIntPtrT, uint64_t, uintptr_t
)

/* ULongPtrTo* => UIntPtrTTo* */
__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToDWord, ULONG_PTR, DWORD,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToInt, ULONG_PTR, INT,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToInt64, ULONG_PTR, INT64,
    UIntPtrTToInt64, uintptr_t, int64_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToIntPtr, ULONG_PTR, INT_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToLong, ULONG_PTR, LONG,
    UIntPtrTToInt32, uintptr_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToLongPtr, ULONG_PTR, LONG_PTR,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToPtrdiffT, ULONG_PTR, ptrdiff_t,
    UIntPtrTToPtrdiffT, uintptr_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToSSIZET, ULONG_PTR, SSIZE_T,
    UIntPtrTToIntPtrT, uintptr_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToUInt, ULONG_PTR, UINT,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToUIntPtr, ULONG_PTR, UINT_PTR,
    UIntPtrTToUIntPtrT, uintptr_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongPtrToULong, ULONG_PTR, ULONG,
    UIntPtrTToUInt32, uintptr_t, uint32_t
)

/* ULongTo* => UInt32To* */
__MINGW_INTSAFE_CONV_MAPPING(
    ULongToByte, ULONG, BYTE,
    UInt32ToUInt8, uint32_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    ULongToChar, ULONG, CHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    ULongToChar, ULONG, CHAR,
    UInt32ToInt8, uint32_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToInt, ULONG, INT,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToIntPtr, ULONG, INT_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToLong, ULONG, LONG,
    UInt32ToInt32, uint32_t, int32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToLongPtr, ULONG, LONG_PTR,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToPtrdiffT, ULONG, ptrdiff_t,
    UInt32ToPtrdiffT, uint32_t, ptrdiff_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToShort, ULONG, SHORT,
    UInt32ToInt16, uint32_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToSSIZET, ULONG, SSIZE_T,
    UInt32ToIntPtrT, uint32_t, intptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToUChar, ULONG, UCHAR,
    UInt32ToUInt8, uint32_t, uint8_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToUInt, ULONG, UINT,
    UInt32ToUInt32, uint32_t, uint32_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToUIntPtr, ULONG, UINT_PTR,
    UInt32ToUIntPtrT, uint32_t, uintptr_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToUShort, ULONG, USHORT,
    UInt32ToUInt16, uint32_t, uint16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    ULongToWord, ULONG, WORD,
    UInt32ToUInt16, uint32_t, uint16_t
)

/* UShortTo* => UInt16To* */
__MINGW_INTSAFE_CONV_MAPPING(
    UShortToByte, USHORT, BYTE,
    UInt16ToUInt8, uint16_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    UShortToChar, USHORT, CHAR,
    UInt16ToUInt8, uint16_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    UShortToChar, USHORT, CHAR,
    UInt16ToInt8, uint16_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    UShortToShort, USHORT, SHORT,
    UInt16ToInt16, uint16_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    UShortToUChar, USHORT, UCHAR,
    UInt16ToUInt8, uint16_t, uint8_t
)

/* WordTo* => UInt16* */
__MINGW_INTSAFE_CONV_MAPPING(
    WordToByte, USHORT, BYTE,
    UInt16ToUInt8, uint16_t, uint8_t
)

#   if defined(CHAR_MIN) && CHAR_MIN == 0
__MINGW_INTSAFE_CONV_MAPPING(
    WordToChar, USHORT, CHAR,
    UInt16ToUInt8, uint16_t, uint8_t
)
#   else
__MINGW_INTSAFE_CONV_MAPPING(
    WordToChar, USHORT, CHAR,
    UInt16ToInt8, uint16_t, int8_t
)
#   endif

__MINGW_INTSAFE_CONV_MAPPING(
    WordToShort, USHORT, SHORT,
    UInt16ToInt16, uint16_t, int16_t
)

__MINGW_INTSAFE_CONV_MAPPING(
    WordToUChar, USHORT, UCHAR,
    UInt16ToUInt8, uint16_t, uint8_t
)

/**
 * @defgroup MathFunctions Safe Math Functions For Integral Types
 * Set of functions designed to provide arithmetic operations and perform
 * validity checks, and to do so with minimal impact on performance.
 *
 * Supported operations:
 * - Addition
 * - Multiplication
 * - Subtraction
 */

/* DWord* */
__MINGW_INTSAFE_MATH_MAPPING(
    DWordAdd, DWORD,
    UInt32Add, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    DWordMult, DWORD,
    UInt32Mult, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    DWordSub, DWORD,
    UInt32Sub, uint32_t
)

/* DWordPtr* */
__MINGW_INTSAFE_MATH_MAPPING(
    DWordPtrAdd, DWORD_PTR,
    UIntPtrTAdd, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    DWordPtrMult, DWORD_PTR,
    UIntPtrTMult, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    DWordPtrSub, DWORD_PTR,
    UIntPtrTSub, uintptr_t
)

/* SizeT* */
__MINGW_INTSAFE_MATH_MAPPING(
    SizeTAdd, size_t,
    SizeTAdd, size_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    SizeTMult, size_t,
    SizeTMult, size_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    SizeTSub, size_t,
    SizeTSub, size_t
)

/* SIZET* */
__MINGW_INTSAFE_MATH_MAPPING(
    SIZETAdd, SIZE_T,
    UIntPtrTAdd, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    SIZETMult, SIZE_T,
    UIntPtrTMult, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    SIZETSub, SIZE_T,
    UIntPtrTSub, uintptr_t
)

/* UInt* */
__MINGW_INTSAFE_MATH_MAPPING(
    UIntAdd, UINT,
    UInt32Add, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UIntMult, UINT,
    UInt32Mult, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UIntSub, UINT,
    UInt32Sub, uint32_t
)

/* UIntPtr* */
__MINGW_INTSAFE_MATH_MAPPING(
    UIntPtrAdd, UINT_PTR,
    UIntPtrTAdd, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UIntPtrMult, UINT_PTR,
    UIntPtrTMult, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UIntPtrSub, UINT_PTR,
    UIntPtrTSub, uintptr_t
)

/* ULong* */
__MINGW_INTSAFE_MATH_MAPPING(
    ULongAdd, ULONG,
    UInt32Add, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongMult, ULONG,
    UInt32Mult, uint32_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongSub, ULONG,
    UInt32Sub, uint32_t
)

/* ULongLong* */
__MINGW_INTSAFE_MATH_MAPPING(
    ULongLongAdd, ULONGLONG,
    UInt64Add, uint64_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongLongMult, ULONGLONG,
    UInt64Mult, uint64_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongLongSub, ULONGLONG,
    UInt64Sub, uint64_t
)

/* ULongPtr* */
__MINGW_INTSAFE_MATH_MAPPING(
    ULongPtrAdd, ULONG_PTR,
    UIntPtrTAdd, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongPtrMult, ULONG_PTR,
    UIntPtrTMult, uintptr_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    ULongPtrSub, ULONG_PTR,
    UIntPtrTSub, uintptr_t
)

/* UShort* */
__MINGW_INTSAFE_MATH_MAPPING(
    UShortAdd, USHORT,
    UInt16Add, uint16_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UShortMult, USHORT,
    UInt16Mult, uint16_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    UShortSub, USHORT,
    UInt16Sub, uint16_t
)

/* Word* */
__MINGW_INTSAFE_MATH_MAPPING(
    WordAdd, WORD,
    UInt16Add, uint16_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    WordMult, WORD,
    UInt16Mult, uint16_t
)
__MINGW_INTSAFE_MATH_MAPPING(
    WordSub, WORD,
    UInt16Sub, uint16_t
)

/* clean up */
#   if defined(__MINGW_INTSAFE_MSCOMPAT_UNDEF_COMMON_WINDOWS_H_TYPEDEFS)
#       undef CHAR
#       undef UCHAR
#       undef BYTE
#       undef SHORT
#       undef WORD
#       undef USHORT
#       undef INT
#       undef LONG
#       undef UINT
#       undef ULONG
#       undef DWORD
#       undef INT64
#       undef ULONGLONG
#       undef SSIZE_T
#       undef SIZE_T
#       undef ULONG_PTR
#       undef INT_PTR
#       undef LONG_PTR
#       undef UINT_PTR
#       undef DWORD_PTR
#       undef __MINGW_INTSAFE_MSCOMPAT_UNDEF_COMMON_WINDOWS_H_TYPEDEFS
#   endif

#   undef __MINGW_INTSAFE_CONV_MAPPING
#   undef __MINGW_INTSAFE_MATH_MAPPING

#   ifdef __cplusplus
}
#   endif

#endif /* !__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS &&
        !__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS &&
        !__MINGW_INTSAFE_MISSING_CHAR_BIT &&
        (__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T ||
            __MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T) &&
        (__MINGW_INTSAFE_SIZE_T_IS_UINT32_T ||
            __MINGW_INTSAFE_SIZE_T_IS_UINT64_T) &&
        (__MINGW_INTSAFE_INTPTR_T_IS_INT32_T ||
            __MINGW_INTSAFE_INTPTR_T_IS_INT64_T) &&
        (__MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T ||
            __MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T) */

#endif /* __MINGW_INTSAFE_MSCOMPAT_H_INCLUDED */
