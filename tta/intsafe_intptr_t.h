/*
 * intsafe_intptr_t.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_INTSAFE_INTPTR_T_H_INCLUDED
#define __MINGW_INTSAFE_INTPTR_T_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#include "intsafe_common.h"
#include "intsafe_static_checks.h"

#if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
#include "intsafe_64.h"
#elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
#include "intsafe_32.h"
#else
/* intsafe_static_checks.h generates errors */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T)
#   define __MINGW_ISINTPTR_T_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(IntPtrT), \
        ToType(intptr_t src, Type* dest) \
    ) \
    { \
        return __MINGW_INTSAFE_JOIN( \
            __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
            ToType((int64_t)src, dest) \
        ); \
    }

#   define __MINGW_ISINTPTR_T_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(IntPtrT), \
        Op(intptr_t op1, intptr_t op2, intptr_t* result) \
    ) \
    { \
        return __MINGW_INTSAFE_JOIN( \
            __MINGW_INTSAFE_PREPARE_PREFIX(Int64), \
            Op((int64_t)op1, (int64_t)op2, (int64_t*)result) \
        ); \
    }

#elif defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)
#   define __MINGW_ISINTPTR_T_CONV_DECL(ToType, Type) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(IntPtrT), \
        ToType(intptr_t src, Type* dest) \
    ) \
    { \
        return __MINGW_INTSAFE_JOIN( \
            __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
            ToType((int32_t)src, dest) \
        ); \
    }

#   define __MINGW_ISINTPTR_T_MATH_DECL(Op) \
    __MINGW_INTSAFEAPI \
    __MINGW_INTSAFE_JOIN( \
        __MINGW_INTSAFE_PREPARE_PREFIX(IntPtrT), \
        Op(intptr_t op1, intptr_t op2, intptr_t* result) \
    ) \
    { \
        return __MINGW_INTSAFE_JOIN( \
            __MINGW_INTSAFE_PREPARE_PREFIX(Int32), \
            Op((int32_t)op1, (int32_t)op2, (int32_t*)result) \
        ); \
    }

#endif

#if defined(__MINGW_INTSAFE_INTPTR_T_IS_INT64_T) || \
    defined(__MINGW_INTSAFE_INTPTR_T_IS_INT32_T)

/* Conversion Functions */
__MINGW_ISINTPTR_T_CONV_DECL(ToInt8, int8_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToInt16, int16_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToInt32, int32_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToInt64, int64_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToUInt8, uint8_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToUInt16, uint16_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToUInt32, uint32_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToUInt64, uint64_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToSizeT, size_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToPtrdiffT, ptrdiff_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToIntPtrT, intptr_t)
__MINGW_ISINTPTR_T_CONV_DECL(ToUIntPtrT, uintptr_t)

/* Math Functions */
__MINGW_ISINTPTR_T_MATH_DECL(Add)
__MINGW_ISINTPTR_T_MATH_DECL(Mult)
__MINGW_ISINTPTR_T_MATH_DECL(Sub)

#   undef __MINGW_ISINTPTR_T_CONV_DECL
#   undef __MINGW_ISINTPTR_T_MATH_DECL

#endif

#ifdef __cplusplus
}
#endif

#endif /* __MINGW_INTSAFE_INTPTR_T_H_INCLUDED */
