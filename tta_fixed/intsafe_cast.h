/*
 * intsafe_cast.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_INTSAFE_CAST_H_INCLUDED
#define __MINGW_INTSAFE_CAST_H_INCLUDED

#ifndef __GNUC__
#   error "This header requires a GCC-compatible compiler"
#endif

/* All headers include this file. */
#include <_mingw.h>

#include "intsafe_8.h"
#include "intsafe_16.h"
#include "intsafe_32.h"
#include "intsafe_64.h"

#if !defined(__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_CHAR_BIT)

#   ifdef __cplusplus
extern "C" {
#   endif

#   define __MINGW_INTSAFE_IDTINT8 0
#   define __MINGW_INTSAFE_IDTUINT8 1
#   define __MINGW_INTSAFE_IDTINT16 2
#   define __MINGW_INTSAFE_IDTUINT16 3
#   define __MINGW_INTSAFE_IDTINT32 4
#   define __MINGW_INTSAFE_IDTUINT32 5
#   define __MINGW_INTSAFE_IDTINT64 6
#   define __MINGW_INTSAFE_IDTUINT64 7
#   define __MINGW_ISCAST_DECL(X) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_PREPARE_PREFIX(X)
#   define __MINGW_ISCAST_CALL(X) \
    __MINGW_INTSAFE_PREPARE_PREFIX(X)

/**
 * @def __MINGW_INTSAFE_TYPEID
 * A facility for retrieving the type id of a given integral type.
 * @param T an integral type.
 * @return the id of the given type on success, -1 otherwise.
 * @internal
 */
#   define __MINGW_INTSAFE_TYPEID(T) ( \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, int8_t) ? 0 /* IDTINT8 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, uint8_t) ? 1 /* IDTUINT8 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, int16_t) ? 2 /* IDTINT16 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, uint16_t) ? 3 /* IDTUIN16 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, int32_t) ? 4 /* IDTINT32 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, uint32_t) ? 5 /* IDTUINT32 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, int64_t) ? 6 /* IDTINT64 */ : \
        (__MINGW_INTSAFE_IS_COMPATIBLE(T, uint64_t) ? 7 /* IDTUINT64 */ : \
            -1 /* UNDEFINED */)))))))) \
    )

/**
 * @def __MINGW_INTSAFE_CAST
 * A generic cast for converting a value of an integral type to a value of
 * another integral type. It's like a safe version of C++ static_cast<> but
 * designed to work for C. However, in C++, you SHOULD use alternatives like
 * <b>boost::numeric_cast<></b>, or .NET <b>safe_cast<></b> instead.
 * @param SRC the "source" variable that holds the value to be converted.
 * @param DEST the "destination" variable that holds the converted value.
 * @return S_OK on success, INTSAFE_E_ARITHMETIC_OVERFLOW otherwise.
 * @note
 * - It works with INTEGRAL TYPES and GCC only (due to the use of
 * GCC extensions - typeof operator & compound statement "({ .. })").
 * - SRC and DEST may be function calls without causing side-effects of calling
 * a function twice. Thanks to GCC's typeof operator to help us avoid these.
 * - Compiler does not issue a warning or error if you do not use the return
 * value of @def __MINGW_INTSAFE_CAST.
 * @par Example
 * This is a small code snippet to demonstrate the usage of @def
 * __MINGW_INTSAFE_CAST. Here we assume Foo & Bar are two integral types.
 * @code
 * Foo foo = value1;
 * Bar bar = value2;
 * if (__MINGW_INTSAFE_CAST(foo, bar) == S_OK)
 *     // bar holds value1
 *     printf("Casting from Foo to Bar completed successfully");
 * else
 *     printf("Overflow/Underflow");
 *
 * // assume func() is a function declared somewhere
 * if (__MINGW_INTSAFE_CAST(func(), foo) == S_OK)
 *     printf("foo now is holding the value returning from func");
 * @endcode
 */
#	define __MINGW_INTSAFE_CAST(SRC, DEST) ({ \
        typedef __typeof__(SRC) __MINGW_INTSAFE_CAST_src_t; \
        typedef __typeof__(DEST) __MINGW_INTSAFE_CAST_dest_t; \
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT( \
            __MINGW_INTSAFE_CAST_src_t \
        ); \
        __MINGW_INTSAFE_NON_INTEGRAL_TYPE_STATIC_ASSERT( \
            __MINGW_INTSAFE_CAST_dest_t \
        ); \
        HRESULT __MINGW_INTSAFE_CAST_retval = S_OK; \
        __MINGW_INTSAFE_CAST_src_t __MINGW_INTSAFE_CAST_src = (SRC); \
        if (__MINGW_INTSAFE_IS_DIRECT_CAST(__MINGW_INTSAFE_CAST_src_t, \
            __MINGW_INTSAFE_CAST_dest_t)) \
            DEST = (__MINGW_INTSAFE_CAST_dest_t)(__MINGW_INTSAFE_CAST_src); \
        else \
            __MINGW_INTSAFE_CAST_retval = \
            __MINGW_INTSAFE_PREPARE_PREFIX(OtherToOther) ( \
                &__MINGW_INTSAFE_CAST_src, \
                __MINGW_INTSAFE_TYPEID(__MINGW_INTSAFE_CAST_src_t), \
                &DEST, \
                __MINGW_INTSAFE_TYPEID(__MINGW_INTSAFE_CAST_dest_t) \
            ); \
        __MINGW_INTSAFE_CAST_retval; \
    })

__MINGW_ISCAST_DECL(Int8ToOther(void * src8, void * dest, int32_t destid))
{
    int8_t srcValue = *((int8_t*)src8);
    switch (destid) {
    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(Int8ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(Int8ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(Int8ToUInt32(srcValue, (uint32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT64:
        return __MINGW_ISCAST_CALL(Int8ToUInt64(srcValue, (uint64_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(Int16ToOther(void *src16, void * dest, int32_t destid))
{
    int16_t srcValue = *((int16_t*)src16);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(Int16ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(Int16ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(Int16ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(Int16ToUInt32(srcValue, (uint32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT64:
        return __MINGW_ISCAST_CALL(Int16ToUInt64(srcValue, (uint64_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(Int32ToOther(void *src32, void * dest, int32_t destid))
{
    int32_t srcValue = *((int32_t*)src32);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(Int32ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(Int32ToInt16(srcValue, (int16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(Int32ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(Int32ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(Int32ToUInt32(srcValue, (uint32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT64:
        return __MINGW_ISCAST_CALL(Int32ToUInt64(srcValue, (uint64_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(Int64ToOther(void *src64, void * dest, int32_t destid))
{
    int64_t srcValue = *((int64_t*)src64);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(Int64ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(Int64ToInt16(srcValue, (int16_t*)dest));

    case __MINGW_INTSAFE_IDTINT32:
        return __MINGW_ISCAST_CALL(Int64ToInt32(srcValue, (int32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(Int64ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(Int64ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(Int64ToUInt32(srcValue, (uint32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT64:
        return __MINGW_ISCAST_CALL(Int64ToUInt64(srcValue, (uint64_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(UInt8ToOther(void * srcu8, void* dest, int32_t destid))
{
    uint8_t srcValue = *((uint8_t*)srcu8);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(UInt8ToInt8(srcValue, (int8_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(UInt16ToOther(void * srcu16, void* dest, int32_t destid))
{
    uint16_t srcValue = *((uint16_t*)srcu16);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(UInt16ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(UInt16ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(UInt16ToInt16(srcValue, (int16_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(UInt32ToOther(void * srcu32, void* dest, int32_t destid))
{
    uint32_t srcValue = *((uint32_t*)srcu32);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(UInt32ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(UInt32ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(UInt32ToInt16(srcValue, (int16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(UInt32ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTINT32:
        return __MINGW_ISCAST_CALL(UInt32ToInt32(srcValue, (int32_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(UInt64ToOther(void * srcu64, void* dest, int32_t destid))
{
    uint64_t srcValue = *((uint64_t*)srcu64);
    switch (destid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(UInt64ToInt8(srcValue, (int8_t*)dest));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(UInt64ToUInt8(srcValue, (uint8_t*)dest));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(UInt64ToInt16(srcValue, (int16_t*)dest));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(UInt64ToUInt16(srcValue, (uint16_t*)dest));

    case __MINGW_INTSAFE_IDTINT32:
        return __MINGW_ISCAST_CALL(UInt64ToInt32(srcValue, (int32_t*)dest));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(UInt64ToUInt32(srcValue, (uint32_t*)dest));

    case __MINGW_INTSAFE_IDTINT64:
        return __MINGW_ISCAST_CALL(UInt64ToInt64(srcValue, (int64_t*)dest));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_ISCAST_DECL(OtherToOther(void *src, int32_t srcid, void *dest, int32_t destid))
{
    switch (srcid) {
    case __MINGW_INTSAFE_IDTINT8:
        return __MINGW_ISCAST_CALL(Int8ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTUINT8:
        return __MINGW_ISCAST_CALL(UInt8ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTINT16:
        return __MINGW_ISCAST_CALL(Int16ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTUINT16:
        return __MINGW_ISCAST_CALL(UInt16ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTINT32:
        return __MINGW_ISCAST_CALL(Int32ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTUINT32:
        return __MINGW_ISCAST_CALL(UInt32ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTINT64:
        return __MINGW_ISCAST_CALL(Int64ToOther(src, dest, destid));

    case __MINGW_INTSAFE_IDTUINT64:
        return __MINGW_ISCAST_CALL(UInt64ToOther(src, dest, destid));

    default:
        break;
    }
    return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

#   undef __MINGW_INTSAFE_IDTINT8
#   undef __MINGW_INTSAFE_IDTUINT8
#   undef __MINGW_INTSAFE_IDTINT16
#   undef __MINGW_INTSAFE_IDTUINT16
#   undef __MINGW_INTSAFE_IDTINT32
#   undef __MINGW_INTSAFE_IDTUINT32
#   undef __MINGW_INTSAFE_IDTINT64
#   undef __MINGW_INTSAFE_IDTUINT64
#   undef __MINGW_ISCAST_DECL
#   undef __MINGW_ISCAST_CALL

#   ifdef __cplusplus
}
#   endif

#endif /* !__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS &&
        !__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS &&
        !__MINGW_INTSAFE_MISSING_CHAR_BIT */

#endif /* __MINGW_INTSAFE_CAST_H_INCLUDED */
