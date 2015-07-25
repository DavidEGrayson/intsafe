/*
 * intsafe_strict_mode.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_INTSAFE_STRICT_MODE_H_INCLUDED
#define __MINGW_INTSAFE_STRICT_MODE_H_INCLUDED

/* All headers include this file. */
#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * It is recommended to compile with -D__MINGW_INTSAFE_ENABLE_STRICT_MODE
 * and "-Wall -Wextra" to identify security problems (if have) in your code.
 */
#ifdef __MINGW_INTSAFE_ENABLE_STRICT_MODE
#   if __MINGW_GNUC_PREREQ (4, 2)
/* Warnings that SHOULD BE treated as errors:
 *
 * 1. Warning about ignoring return value of function marked with
 * __attribute__((warn_unused_result)) since it implies a security problem or
 * a bug. Memory management functions, intsafe.h APIs etc. are kind of
 * such functions.
 *
 * 2. Waring about passing NULL to functions marked with
 * __attribute__((nonnull)) since it also implies a bug.
 */
#       if __MINGW_GNUC_PREREQ (4, 5)
#           pragma GCC diagnostic error "-Wunused-result"
#       endif
#       pragma GCC diagnostic error "-Wnonnull"
/*
 * Several warnings may be considered as errors
 * Note: not all of them are enable by "-Wall".
 *
 * FIXME: some of them may not be supported by old versions of GCC. Please
 * someone checks this for me.
 */
#       pragma GCC diagnostic error "-Wconversion"
#       pragma GCC diagnostic error "-Woverflow"
#       pragma GCC diagnostic error "-Wsign-compare"
#       pragma GCC diagnostic error "-Wsign-conversion"
#       pragma GCC diagnostic error "-Wsign-promo"
#       pragma GCC diagnostic error "-Wstrict-overflow"
#       pragma GCC diagnostic error "-Wtype-limits"
#   endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __MINGW_INTSAFE_STRICT_MODE_H_INCLUDED */
