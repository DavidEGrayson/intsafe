/*
 * intsafe.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 * Reference:
 * - http://msdn.microsoft.com/en-us/library/ff521693%28v=VS.85%29.aspx
 *
 * No Microsoft header files are referenced and/or used to create this file.
 */

#ifndef __MINGW_INTSAFE_H_INCLUDED
#define __MINGW_INTSAFE_H_INCLUDED

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
#ifdef __GNUC__
#include "intsafe_cast.h"
#endif
#include "intsafe_mscompat.h"

#endif /* __MINGW_INTSAFE_H_INCLUDED */
