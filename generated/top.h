#pragma once

#include <wtypesbase.h>
#include <limits.h>
#include <sal.h>

#ifndef S_OK
#define S_OK ((HRESULT)0)
#endif

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
