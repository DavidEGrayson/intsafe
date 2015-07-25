/*
 * intsafe_32.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/**
 * Safe functions for 32bit integral types (uint32_t & int32_t)
 * @note
 * Each type has 8 conversion functions corresponding to 8 different ISOC types:
 * - [u]int8_t
 * - [u]int32_t
 * - [u]int32_t
 * - [u]int64_t
 *
 * In addition, other standard types:
 * - [u]intptr_t
 * - size_t
 * - ptrdiff_t
 * are also supported, though they're just typedefs of [u]int32_t or [u]int64_t.
 *
 * Each type also has 3 math functions: Add, Mult and Sub
 *
 * For a given type, some conversions are garbage, but they are still added
 * for completeness as well as function-to-function mapping.
 */
#ifndef __MINGW_INTSAFE_32_H_INCLUDED
#define __MINGW_INTSAFE_32_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#include "intsafe_common.h"
#include "intsafe_static_checks.h"

#if !defined(__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS) && \
    !defined(__MINGW_INTSAFE_MISSING_CHAR_BIT)

#   ifdef __cplusplus
extern "C" {
#   endif

/* int32_t counter parts */

#   define __MINGW_ISINT32_SUCCESS S_OK
#   define __MINGW_ISINT32_FAILURE INTSAFE_E_ARITHMETIC_OVERFLOW

#   define __MINGW_ISINT32_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
        ToType(int32_t src, Type* dest) \
    )

#   define __MINGW_ISINT32_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
        Op(int32_t op1, int32_t op2, int32_t* result) \
    )

#   define __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToType, Type) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
                ToType(int32_t, Type*) \
            ) \
        ), \
        dest \
    )

#   define __MINGW_ISINT32_MATH_NULLPTR_ASSERT(Op) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
                Op(int32_t, int32_t, int32_t*) \
            ) \
        ), \
        result \
    )

/* int32_t Conversion Functions */

__MINGW_ISINT32_CONV_DECL(ToInt8, int8_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToInt8, int8_t);
    if (INT8_MIN <= src && src <= INT8_MAX) {
        *dest = (int8_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToInt16, int16_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToInt16, int16_t);
    if (INT16_MIN <= src && src <= INT16_MAX) {
        *dest = (int16_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToInt32, int32_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToInt32, int32_t);
    *dest = (int32_t)src;
    return __MINGW_ISINT32_SUCCESS;
}

__MINGW_ISINT32_CONV_DECL(ToInt64, int64_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToInt64, int64_t);
    *dest = (int64_t)src;
    return __MINGW_ISINT32_SUCCESS;
}

__MINGW_ISINT32_CONV_DECL(ToUInt8, uint8_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToUInt8, uint8_t);
    if (0 <= src && src <= UINT8_MAX) {
        *dest = (uint8_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToUInt16, uint16_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToUInt16, uint16_t);
    if (0<= src && src <= UINT16_MAX) {
        *dest = (uint16_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToUInt32, uint32_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToUInt32, uint32_t);
    if (src >= 0) {
        *dest = (uint32_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToUInt64, uint64_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToUInt64, uint64_t);
    if (src >= 0) {
        *dest = (uint64_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToSizeT, size_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToSizeT, size_t);
    if (src >= 0) {
        *dest = (size_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_CONV_DECL(ToPtrdiffT, ptrdiff_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToPtrdiffT, ptrdiff_t);
    *dest = (ptrdiff_t)src;
    return __MINGW_ISINT32_SUCCESS;
}

__MINGW_ISINT32_CONV_DECL(ToIntPtrT, intptr_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToIntPtrT, intptr_t);
    *dest = (intptr_t)src;
    return __MINGW_ISINT32_SUCCESS;
}

__MINGW_ISINT32_CONV_DECL(ToUIntPtrT, uintptr_t)
{
    __MINGW_ISINT32_CONV_NULLPTR_ASSERT(ToUIntPtrT, uintptr_t);
    if (src >= 0) {
        *dest = (uintptr_t)src;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

/* int32_t Math Functions */

__MINGW_ISINT32_MATH_DECL(Add)
{
    __MINGW_ISINT32_MATH_NULLPTR_ASSERT(Add);
    int64_t tmp = (int64_t)((int64_t)(op1) + (int64_t)(op2));

    if (INT32_MIN <= tmp && tmp <= INT32_MAX) {
        *result = (int32_t)tmp;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_MATH_DECL(Mult)
{
    __MINGW_ISINT32_MATH_NULLPTR_ASSERT(Mult);
    int64_t tmp = (int64_t)((int64_t)(op1) * (int64_t)(op2));

    if (INT32_MIN <= tmp && tmp <= INT32_MAX) {
        *result = (int32_t)tmp;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

__MINGW_ISINT32_MATH_DECL(Sub)
{
    __MINGW_ISINT32_MATH_NULLPTR_ASSERT(Sub);
    int64_t tmp = (int64_t)((int64_t)(op1) - (int64_t)(op2));

    if (INT32_MIN <= tmp && tmp <= INT32_MAX) {
        *result = (int32_t)tmp;
        return __MINGW_ISINT32_SUCCESS;
    }
    return __MINGW_ISINT32_FAILURE;
}

/* clean up */
#   undef __MINGW_ISINT32_SUCCESS
#   undef __MINGW_ISINT32_FAILURE
#   undef __MINGW_ISINT32_CONV_DECL
#   undef __MINGW_ISINT32_MATH_DECL
#   undef __MINGW_ISINT32_CONV_NULLPTR_ASSERT
#   undef __MINGW_ISINT32_MATH_NULLPTR_ASSERT

/* uint32_t counter parts */

#   define __MINGW_ISUINT32_SUCCESS S_OK
#   define __MINGW_ISUINT32_FAILURE INTSAFE_E_ARITHMETIC_OVERFLOW

#   define __MINGW_ISUINT32_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(UInt32), \
        ToType(uint32_t src, Type* dest) \
    )

#   define __MINGW_ISUINT32_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(UInt32), \
        Op(uint32_t op1, uint32_t op2, uint32_t* result) \
    )

#   define __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToType, Type) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(UInt32), \
                ToType(uint32_t, Type*) \
            ) \
        ), \
        dest \
    )

#   define __MINGW_ISUINT32_MATH_NULLPTR_ASSERT(Op) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(UInt32), \
                Op(uint32_t, uint32_t, uint32_t*) \
            ) \
        ), \
        result \
    )

#   define __MINGW_ISUINT32_API(X) \
    __MINGW_INTSAFE_PREPARE_PREFIX(X)

/* uint32_t Conversion Functions */

__MINGW_ISUINT32_CONV_DECL(ToInt8, int8_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToInt8, int8_t);
    if (src <= INT8_MAX) {
        *dest = (int8_t)src;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_CONV_DECL(ToInt16, int16_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToInt16, int16_t);
    if (src <= INT16_MAX) {
        *dest = (int16_t)src;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_CONV_DECL(ToInt32, int32_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToInt32, int32_t);
    if (src <= INT32_MAX) {
        *dest = (int32_t)src;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_CONV_DECL(ToInt64, int64_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToInt64, int64_t);
    *dest = (int64_t)src;
    return __MINGW_ISUINT32_SUCCESS;
}

__MINGW_ISUINT32_CONV_DECL(ToUInt8, uint8_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToUInt8, uint8_t);
    if (src <= UINT8_MAX) {
        *dest = (uint8_t)src;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_CONV_DECL(ToUInt16, uint16_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToUInt16, uint16_t);
    if (src <= UINT16_MAX) {
        *dest = (uint16_t)src;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_CONV_DECL(ToUInt32, uint32_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToUInt32, uint32_t);
    *dest = (uint32_t)src;
    return __MINGW_ISUINT32_SUCCESS;
}

__MINGW_ISUINT32_CONV_DECL(ToUInt64, uint64_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToUInt64, uint64_t);
    *dest = (uint64_t)src;
    return __MINGW_ISUINT32_SUCCESS;
}

__MINGW_ISUINT32_CONV_DECL(ToSizeT, size_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToSizeT, size_t);
    *dest = (size_t)src;
    return __MINGW_ISUINT32_SUCCESS;
}

__MINGW_ISUINT32_CONV_DECL(ToPtrdiffT, ptrdiff_t)
{
#   if defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T)
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToPtrdiffT, ptrdiff_t);
    *dest = (ptrdiff_t)src;
    return __MINGW_ISUINT32_SUCCESS;
#   elif defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T)
    return __MINGW_ISUINT32_API(UInt32ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT32_FAILURE;
#   endif
}

__MINGW_ISUINT32_CONV_DECL(ToIntPtrT, intptr_t)
{
#   if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToIntPtrT, intptr_t);
    *dest = (intptr_t)src;
    return __MINGW_ISUINT32_SUCCESS;
#   elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
    return __MINGW_ISUINT32_API(UInt32ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT32_FAILURE;
#   endif
}

__MINGW_ISUINT32_CONV_DECL(ToUIntPtrT, uintptr_t)
{
    __MINGW_ISUINT32_CONV_NULLPTR_ASSERT(ToUIntPtrT, uintptr_t);
    *dest = (uintptr_t)src;
    return __MINGW_ISUINT32_SUCCESS;
}

/* uint32_t Math Functions */

__MINGW_ISUINT32_MATH_DECL(Add)
{
    __MINGW_ISUINT32_MATH_NULLPTR_ASSERT(Add);
    uint64_t tmp = (uint64_t)((uint64_t)(op1) + (uint64_t)(op2));
    if (tmp <= UINT32_MAX) {
        *result = (uint32_t)tmp;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_MATH_DECL(Mult)
{
    __MINGW_ISUINT32_MATH_NULLPTR_ASSERT(Mult);
    uint64_t tmp = (uint64_t)((uint64_t)(op1) * (uint64_t)(op2));
    if (tmp <= UINT32_MAX) {
        *result = (uint32_t)tmp;
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

__MINGW_ISUINT32_MATH_DECL(Sub)
{
    __MINGW_ISUINT32_MATH_NULLPTR_ASSERT(Sub);
    if (op1 >= op2) {
        *result = (uint32_t)(op1 - op2);
        return __MINGW_ISUINT32_SUCCESS;
    }
    return __MINGW_ISUINT32_FAILURE;
}

/* clean up */
#   undef __MINGW_ISUINT32_SUCCESS
#   undef __MINGW_ISUINT32_FAILURE
#   undef __MINGW_ISUINT32_CONV_DECL
#   undef __MINGW_ISUINT32_MATH_DECL
#   undef __MINGW_ISUINT32_CONV_NULLPTR_ASSERT
#   undef __MINGW_ISUINT32_MATH_NULLPTR_ASSERT

#   ifdef __cplusplus
}
#   endif

#endif /* !__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS &&
        !__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS &&
        !__MINGW_INTSAFE_MISSING_CHAR_BIT */

#endif /* __MINGW_INTSAFE_32_H_INCLUDED */
