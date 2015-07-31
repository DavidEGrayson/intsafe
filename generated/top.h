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

#ifndef __MINGW_INTSAFE_API
#define __MINGW_INTSAFE_API inline
#endif

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)
