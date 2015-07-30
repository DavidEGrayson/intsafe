/*
 * intsafe_integer_traits.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/**
 * Traits macros to determine properties of integral types, as well as the
 * relationship between two integral types.
 */
#ifndef __MINGW_INTSAFE_INTEGER_TRAITS_H_INCLUDED
#define __MINGW_INTSAFE_INTEGER_TRAITS_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup IntegerTraitsMacros Traits Macros For Integral Types
 * These macros are somewhat similar to C++ type-traits meta functions
 * but designed to work for both C/C++. They can be used with
 * __MINGW_INTSAFE_STATIC_ASSERT to perform compile-time checkings.
 * @warning Only integral types are supported.
 */

/**
 * @def __MINGW_INTSAFE_IS_UNSIGNED
 * This macro is used to determine whether a given type is unsigned.
 * @param T the checked type.
 * @return true if T is unsigned, false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_UNSIGNED(T) ((T)(-1) > (T)(0))

/**
 * @def __MINGW_INTSAFE_IS_SIGNED
 * This macro is used to determine whether a given type is signed.
 * @param T the checked type.
 * @return true if T is signed, false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_SIGNED(T) (!__MINGW_INTSAFE_IS_UNSIGNED(T))

/**
 * @def __MINGW_INTSAFE_IS_LARGER
 * This macro is used to determine whether T1 is larger than T2.
 * @param T1 the first type.
 * @param T2 the second type.
 * @return true if sizeof(T1) > sizeof(T2), false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_LARGER(T1, T2) (sizeof(T1) > sizeof(T2))

/**
 * @def __MINGW_INTSAFE_IS_SMALLER
 * This macro is used to determine whether T1 is smaller than T2.
 * @param T1 the first type.
 * @param T2 the second type.
 * @return true if sizeof(T1) < sizeof(T2), false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_SMALLER(T1, T2) (sizeof(T1) < sizeof(T2))

/**
 * @def __MINGW_INTSAFE_HAS_SAME_SIZE
 * This macro is used to determine whether size of T1 & size of T2 are the same.
 * @param T1 the first type.
 * @param T2 the second type.
 * @return true if sizeof(T1) == sizeof(T2), false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_HAS_SAME_SIZE(T1, T2) (sizeof(T1) == sizeof(T2))

/**
 * @def __MINGW_INTSAFE_HAS_SAME_SIGN
 * This macro is used to determine whether both T1 & T2 are [un]signed.
 * @param T1 the first type.
 * @param T2 the second type.
 * @return true if:
 * - T1 & T2 are signed
 * - T2 & T2 are unsigned
 * Otherwise, this macro return false.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_HAS_SAME_SIGN(T1, T2) ( \
    (__MINGW_INTSAFE_IS_SIGNED(T1) && __MINGW_INTSAFE_IS_SIGNED(T2)) || \
    (__MINGW_INTSAFE_IS_UNSIGNED(T1) && __MINGW_INTSAFE_IS_UNSIGNED(T2)))

/**
 * @def __MINGW_INTSAFE_IS_COMPATIBLE
 * This macro is used to determine whether T1 is "almost" the same as T2.
 * @param T1 the first type.
 * @param T2 the second type.
 * @return true if T1 & T2 has the same size and [un]signed-ness,
 * false otherwise.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_COMPATIBLE(T1, T2) ( \
    __MINGW_INTSAFE_HAS_SAME_SIZE(T1, T2) && \
    __MINGW_INTSAFE_HAS_SAME_SIGN(T1, T2))

/**
 * @def __MINGW_INTSAFE_IS_DIRECT_CAST
 * This macro is used to determine whether casting from T1 to T2 can be done
 * without losing precision as well as the need of additional checkings.
 * @param T1 the "source" type
 * @param T2 the "destination" type
 * @return true if:
 * - T2 is "almost" the same as T1, or
 * - T2 is larger than T1, and T2 has the same [un]signed-ness as T1, or
 * - T2 is larger than T1, and T1 is unsigned, e.g cast from uint8_t to int16_t
 * Otherwise, this macro returns false.
 * @ingroup IntegerTraitsMacros
 * @internal
 */
#define __MINGW_INTSAFE_IS_DIRECT_CAST(T1, T2) ( \
    __MINGW_INTSAFE_IS_COMPATIBLE(T1, T2) || \
    ( \
        __MINGW_INTSAFE_IS_LARGER(T2, T1) && \
        ( \
            __MINGW_INTSAFE_HAS_SAME_SIGN(T1, T2) || \
            __MINGW_INTSAFE_IS_UNSIGNED(T1) \
        ) \
    ) \
)

#ifdef __cplusplus
}
#endif

#endif /* __MINGW_INTSAFE_INTEGER_TRAITS_H_INCLUDED */
