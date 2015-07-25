/*
 * intsafe_64.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/**
 * Safe functions for 64bit integral types (uint64_t & int64_t)
 * @note
 * Each type has 8 conversion functions corresponding to 8 different ISOC types:
 * - [u]int8_t
 * - [u]int64_t
 * - [u]int64_t
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
#ifndef __MINGW_INTSAFE_64_H_INCLUDED
#define __MINGW_INTSAFE_64_H_INCLUDED

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

/* int64_t counter parts */

#   define __MINGW_ISINT64_SUCCESS S_OK
#   define __MINGW_ISINT64_FAILURE INTSAFE_E_ARITHMETIC_OVERFLOW

#   define __MINGW_ISINT64_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
        ToType(int64_t src, Type* dest) \
    )

#   define __MINGW_ISINT64_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
        Op(int64_t op1, int64_t op2, int64_t* result) \
    )

#   define __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToType, Type) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
                ToType(int64_t, Type*) \
            ) \
        ), \
        dest \
    )

#   define __MINGW_ISINT64_MATH_NULLPTR_ASSERT(Op) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
                Op(int64_t, int64_t, int64_t*) \
            ) \
        ), \
        result \
    )

#   define __MINGW_ISINT64_API(X) \
    __MINGW_INTSAFE_PREPARE_PREFIX(X)

/* int64_t Conversion Functions */

__MINGW_ISINT64_CONV_DECL(ToInt8, int8_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToInt8, int8_t);
    if (INT8_MIN <= src && src <= INT8_MAX) {
        *dest = (int8_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToInt16, int16_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToInt16, int16_t);
    if (INT16_MIN <= src && src <= INT16_MAX) {
        *dest = (int16_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToInt32, int32_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToInt32, int32_t);
    if (INT32_MIN <= src && src <= INT32_MAX) {
        *dest = (int32_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToInt64, int64_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToInt64, int64_t);
    *dest = (int64_t)src;
    return __MINGW_ISINT64_SUCCESS;
}

__MINGW_ISINT64_CONV_DECL(ToUInt8, uint8_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToUInt8, uint8_t);
    if (0 <= src && src <= UINT8_MAX) {
        *dest = (uint8_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToUInt16, uint16_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToUInt16, uint16_t);
    if (0<= src && src <= UINT16_MAX) {
        *dest = (uint16_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToUInt32, uint32_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToUInt32, uint32_t);
    if (0<= src && src <= UINT32_MAX) {
        *dest = (uint32_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToUInt64, uint64_t)
{
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToUInt64, uint64_t);
    if (src >= 0) {
        *dest = (uint64_t)src;
        return __MINGW_ISINT64_SUCCESS;
    }
    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_CONV_DECL(ToSizeT, size_t)
{
#   if defined(__MINGW_INTSAFE_SIZE_T_IS_UINT64_T)
    return __MINGW_ISINT64_API(Int64ToUInt64(src, (uint64_t*)dest));
#   elif defined(__MINGW_INTSAFE_SIZE_T_IS_UINT32_T)
    return __MINGW_ISINT64_API(Int64ToUInt32(src, (uint32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISINT64_FAILURE;
#   endif
}

__MINGW_ISINT64_CONV_DECL(ToPtrdiffT, ptrdiff_t)
{
#   if defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T)
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToPtrdiffT, ptrdiff_t);
    *dest = (ptrdiff_t)src;
    return __MINGW_ISINT64_SUCCESS;
#   elif defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T)
    return __MINGW_ISINT64_API(Int64ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISINT64_FAILURE;
#   endif
}

__MINGW_ISINT64_CONV_DECL(ToIntPtrT, intptr_t)
{
#   if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
    __MINGW_ISINT64_CONV_NULLPTR_ASSERT(ToIntPtrT, intptr_t);
    *dest = (intptr_t)src;
    return __MINGW_ISINT64_SUCCESS;
#   elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
    return __MINGW_ISINT64_API(Int64ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISINT64_FAILURE;
#   endif
}

__MINGW_ISINT64_CONV_DECL(ToUIntPtrT, uintptr_t)
{
#   if defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T)
    return __MINGW_ISINT64_API(Int64ToUInt64(src, (uint64_t*)dest));
#   elif defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T)
    return __MINGW_ISINT64_API(Int64ToUInt32(src, (uint32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISINT64_FAILURE;
#   endif
}

/* int64_t Math Functions */
/* FIXME: better implementation (using 128bit integer ?) */

__MINGW_ISINT64_MATH_DECL(Add)
{
    __MINGW_ISINT64_MATH_NULLPTR_ASSERT(Add);
    int64_t tmp = (int64_t)(op1 + op2);

    if (op1 == 0 || op2 == 0) {
        *result = tmp;
        return __MINGW_ISINT64_SUCCESS;
    }

    if (op1 > 0 && op2 > 0 && (tmp < op1 || tmp < op2))
        return __MINGW_ISINT64_FAILURE;

    if (op1 < 0 && op2 < 0 && (tmp > op1 || tmp > op2))
        return __MINGW_ISINT64_FAILURE;

    *result = tmp;
    return __MINGW_ISINT64_SUCCESS;
}

__MINGW_ISINT64_MATH_DECL(Mult)
{
    __MINGW_ISINT64_MATH_NULLPTR_ASSERT(Mult);
    /* special values */
    if (op1 == 0 || (op1 == -1 && op2 != INT64_MIN) || op1 == 1 ||
        op2 == 0 || (op2 == -1 && op1 != INT64_MIN) || op2 == 1) {
        *result = (int64_t)(op1 * op2);
        return __MINGW_ISINT64_SUCCESS;
    }

    if (op1 == INT64_MAX || op1 == INT64_MIN ||
        op2 == INT64_MAX || op2 == INT64_MIN)
        return __MINGW_ISINT64_FAILURE;

    /* make sure op2 > 0 as always */
    if ((op1 < 0 && op2 < 0) || (op1 > 0 && op2 < 0)) {
        op1 = -op1;
        op2 = -op2;
    }

    if (INT64_MIN/op2 <= op1 && op1 <= INT64_MAX/op2) {
        *result = (int64_t)(op1 * op2);
        return __MINGW_ISINT64_SUCCESS;
    }

    return __MINGW_ISINT64_FAILURE;
}

__MINGW_ISINT64_MATH_DECL(Sub)
{
    __MINGW_ISINT64_MATH_NULLPTR_ASSERT(Sub);
    /* op1 - op2 */
    if (op2 == INT64_MIN) {
        if (op1 >= 0) /* -op2 causing overflow err */
            return __MINGW_ISINT64_FAILURE;
        else {
            /* -op2 = INT64_MAX + 1 */
            *result = (int64_t)(op1 + 1);
            *result = (int64_t)(*result + INT64_MAX);
            return __MINGW_ISINT64_SUCCESS;
        }
    }

    int64_t tmp = (int64_t)(op1 - op2);
    /* the following checks are similar to ones in Add function */
    if (op1 == 0 || op2 == 0) {
        *result = tmp;
        return __MINGW_ISINT64_SUCCESS;
    }

    if (op1 > 0 && -op2 > 0 && (tmp < op1 || tmp < -op2))
        return __MINGW_ISINT64_FAILURE;

    if (op1 < 0 && -op2 < 0 && (tmp > op1 || tmp > -op2))
        return __MINGW_ISINT64_FAILURE;

    *result = tmp;
    return __MINGW_ISINT64_SUCCESS;
}

/* clean up */
#   undef __MINGW_ISINT64_SUCCESS
#   undef __MINGW_ISINT64_FAILURE
#   undef __MINGW_ISINT64_CONV_DECL
#   undef __MINGW_ISINT64_MATH_DECL
#   undef __MINGW_ISINT64_CONV_NULLPTR_ASSERT
#   undef __MINGW_ISINT64_MATH_NULLPTR_ASSERT
#   undef __MINGW_ISINT64_API

/* uint64_t counter parts */

#   define __MINGW_ISUINT64_SUCCESS S_OK
#   define __MINGW_ISUINT64_FAILURE INTSAFE_E_ARITHMETIC_OVERFLOW

#   define __MINGW_ISUINT64_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(UInt64), \
        ToType(uint64_t src, Type* dest) \
    )

#   define __MINGW_ISUINT64_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(UInt64), \
        Op(uint64_t op1, uint64_t op2, uint64_t* result) \
    )

#   define __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToType, Type) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(UInt64), \
                ToType(uint64_t, Type*) \
            ) \
        ), \
        dest \
    )

#   define __MINGW_ISUINT64_MATH_NULLPTR_ASSERT(Op) \
    __MINGW_INTSAFE_NULLPTR_ASSERT( \
        __MINGW_INTSAFE_STRINGIZE( \
            __MINGW_INTSAFE_JOIN( \
                HRESULT __MINGW_INTSAFE_PREPARE_PREFIX(UInt64), \
                Op(uint64_t, uint64_t, uint64_t*) \
            ) \
        ), \
        result \
    )

#   define __MINGW_ISUINT64_API(X) \
    __MINGW_INTSAFE_PREPARE_PREFIX(X)

/* uint64_t Conversion Functions */

__MINGW_ISUINT64_CONV_DECL(ToInt8, int8_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToInt8, int8_t);
    if (src <= INT8_MAX) {
        *dest = (int8_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToInt16, int16_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToInt16, int16_t);
    if (src <= INT16_MAX) {
        *dest = (int16_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToInt32, int32_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToInt32, int32_t);
    if (src <= INT32_MAX) {
        *dest = (int32_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToInt64, int64_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToInt64, int64_t);
    if (src <= INT64_MAX) {
        *dest = (int64_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToUInt8, uint8_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToUInt64, uint8_t);
    if (src <= UINT8_MAX) {
        *dest = (uint8_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToUInt16, uint16_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToUInt16, uint16_t);
    if (src <= UINT16_MAX) {
        *dest = (uint16_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToUInt32, uint32_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToUInt32, uint32_t);
    if (src <= UINT32_MAX) {
        *dest = (uint32_t)src;
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_CONV_DECL(ToUInt64, uint64_t)
{
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToUInt64, uint64_t);
    *dest = (uint64_t)src;
    return __MINGW_ISUINT64_SUCCESS;
}

__MINGW_ISUINT64_CONV_DECL(ToSizeT, size_t)
{
#   if defined(__MINGW_INTSAFE_SIZE_T_IS_UINT64_T)
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToSizeT, size_t);
    *dest = (size_t)src;
    return __MINGW_ISUINT64_SUCCESS;
#   elif defined(__MINGW_INTSAFE_SIZE_T_IS_UINT32_T)
    return __MINGW_ISUINT64_API(UInt64ToUInt32(src, (uint32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT64_FAILURE;
#   endif
}

__MINGW_ISUINT64_CONV_DECL(ToPtrdiffT, ptrdiff_t)
{
#   if defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT64_T)
    return __MINGW_ISUINT64_API(UInt64ToInt64(src, (int64_t*)dest));
#   elif defined(__MINGW_INTSAFE_PTRDIFF_T_IS_INT32_T)
    return __MINGW_ISUINT64_API(UInt64ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT64_FAILURE;
#   endif
}

__MINGW_ISUINT64_CONV_DECL(ToIntPtrT, intptr_t)
{
#   if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
    return __MINGW_ISUINT64_API(UInt64ToInt64(src, (int64_t*)dest));
#   elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
    return __MINGW_ISUINT64_API(UInt64ToInt32(src, (int32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT64_FAILURE;
#   endif
}

__MINGW_ISUINT64_CONV_DECL(ToUIntPtrT, uintptr_t)
{
#   if defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT64_T)
    __MINGW_ISUINT64_CONV_NULLPTR_ASSERT(ToUIntPtrT, uintptr_t);
    *dest = (uintptr_t)src;
    return __MINGW_ISUINT64_SUCCESS;
#   elif defined(__MINGW_INTSAFE_UINTPTR_T_IS_UINT32_T)
    return __MINGW_ISUINT64_API(UInt64ToUInt32(src, (uint32_t*)dest));
#   else
    (void)src;
    (void)dest;
    return __MINGW_ISUINT64_FAILURE;
#   endif
}

/* uint64_t Math Functions */
/* FIXME: better implementation, esp for Mult */

__MINGW_ISUINT64_MATH_DECL(Add)
{
    __MINGW_ISUINT64_MATH_NULLPTR_ASSERT(Add);
    uint64_t tmp = (uint64_t)(op1 + op2);
    if (tmp < op1 || tmp < op2)
        return __MINGW_ISUINT64_FAILURE;

    *result = tmp;
    return __MINGW_ISUINT64_SUCCESS;
}

__MINGW_ISUINT64_MATH_DECL(Mult)
{
    __MINGW_ISUINT64_MATH_NULLPTR_ASSERT(Mult);
    if (op1 == 0 || op2 == 0 || op1 == 1 || op2 == 1) {
        *result = (uint64_t)(op1 * op2);
        return __MINGW_ISUINT64_SUCCESS;
    }

    if (op1 == UINT64_MAX || op2 == UINT64_MAX)
           return __MINGW_ISUINT64_FAILURE;

    if (op1 <= UINT64_MAX / op2) {
        *result = (uint64_t)(op1 * op2);
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

__MINGW_ISUINT64_MATH_DECL(Sub)
{
    __MINGW_ISUINT64_MATH_NULLPTR_ASSERT(Sub);
    if (op1 >= op2) {
        *result = (uint64_t)(op1 - op2);
        return __MINGW_ISUINT64_SUCCESS;
    }
    return __MINGW_ISUINT64_FAILURE;
}

/* clean up */
#   undef __MINGW_ISUINT64_SUCCESS
#   undef __MINGW_ISUINT64_FAILURE
#   undef __MINGW_ISUINT64_CONV_DECL
#   undef __MINGW_ISUINT64_MATH_DECL
#   undef __MINGW_ISUINT64_CONV_NULLPTR_ASSERT
#   undef __MINGW_ISUINT64_MATH_NULLPTR_ASSERT
#   undef __MINGW_ISUINT64_API

#   ifdef __cplusplus
}
#   endif

#endif /* !__MINGW_INTSAFE_MISSING_STDC_CONSTANT_MACROS &&
        !__MINGW_INTSAFE_MISSING_STDC_LIMIT_MACROS &&
        !__MINGW_INTSAFE_MISSING_CHAR_BIT */

#endif /* __MINGW_INTSAFE_64_H_INCLUDED */
