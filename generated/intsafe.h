/* This file is free and unencumbered software released into the
 * public domain. */

/* This file is an implementation of Microsoft's intsafe.h header, which
 * provides inline functions for safe integer conversions and math operations:
 *
 *     https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693
 *
 * It was mostly auto-generated using a script that can be found at:
 *
 *     https://github.com/DavidEGrayson/intsafe
 */

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
#define __MINGW_INTSAFE_API inline HRESULT
#endif

#define INTSAFE_E_ARITHMETIC_OVERFLOW ((HRESULT)0x80070216L)

__MINGW_INTSAFE_API UShortToUChar(_In_ USHORT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UShortToShort(_In_ USHORT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ShortToUChar(_In_ SHORT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ShortToUShort(_In_ SHORT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UIntToUChar(_In_ UINT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UIntToUShort(_In_ UINT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UIntToShort(_In_ UINT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UIntToInt(_In_ UINT operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API UIntToSSIZET(_In_ UINT operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToUChar(_In_ INT operand, _Out_ UCHAR * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToUShort(_In_ INT operand, _Out_ USHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToShort(_In_ INT operand, _Out_ SHORT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToUInt(_In_ INT operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToULongLong(_In_ INT operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API IntToSizeT(_In_ INT operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ULongLongToUInt(_In_ ULONGLONG operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ULongLongToInt(_In_ ULONGLONG operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ULongLongToInt64(_In_ ULONGLONG operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ULongLongToSizeT(_In_ ULONGLONG operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API ULongLongToSSIZET(_In_ ULONGLONG operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API Int64ToUInt(_In_ INT64 operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API Int64ToInt(_In_ INT64 operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API Int64ToULongLong(_In_ INT64 operand, _Out_ ULONGLONG * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API Int64ToSizeT(_In_ INT64 operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API Int64ToSSIZET(_In_ INT64 operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SizeTToUInt(_In_ SIZE_T operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SizeTToInt(_In_ SIZE_T operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SizeTToInt64(_In_ SIZE_T operand, _Out_ INT64 * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SizeTToSSIZET(_In_ SIZE_T operand, _Out_ SSIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SSIZETToUInt(_In_ SSIZE_T operand, _Out_ UINT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SSIZETToInt(_In_ SSIZE_T operand, _Out_ INT * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

__MINGW_INTSAFE_API SSIZETToSizeT(_In_ SSIZE_T operand, _Out_ SIZE_T * result)
{
*result = 0;
return INTSAFE_E_ARITHMETIC_OVERFLOW;
}

/* TODO: add 253 missing functions */
