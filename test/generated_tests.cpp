#include <intsafe.h>
#include <wtypesbase.h>

#if __cplusplus
#include <type_traits>
#endif

#define INITIAL_VALUE 78

void error(const char * format, ...) __attribute__((format (printf, 1, 2)));

void test_should_include_specstrings()
{
    #ifndef __specstrings
    error("intsafe.h did not include specstrings.h");
    #endif
}

void test_arithmetic_overflow_value()
{
    // 0x80070216L is used in the coreclr implementation.
    if (INTSAFE_E_ARITHMETIC_OVERFLOW != (HRESULT)0x80070216L)
    {
        error("INTSAFE_E_ARITHMETIC_OVERFLOW value is wrong");
    }
}

void tests_manual()
{
    test_should_include_specstrings();
}
#ifdef _WIN64
#ifdef __CHAR_UNSIGNED__
static void test_UCHAR_eq_uint8_t()
{
    if(sizeof(UCHAR) != 1)
        error("UCHAR is actually %d bytes", (int)sizeof(UCHAR));
    UCHAR x = 0;
    if(!((UCHAR)(x - 1) > x))
        error("UCHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UCHAR>::value)
        error("UCHAR is a pointer");
    #endif
}

static void test_BYTE_eq_uint8_t()
{
    if(sizeof(BYTE) != 1)
        error("BYTE is actually %d bytes", (int)sizeof(BYTE));
    BYTE x = 0;
    if(!((BYTE)(x - 1) > x))
        error("BYTE sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<BYTE>::value)
        error("BYTE is a pointer");
    #endif
}

static void test_CHAR_eq_uint8_t()
{
    if(sizeof(CHAR) != 1)
        error("CHAR is actually %d bytes", (int)sizeof(CHAR));
    CHAR x = 0;
    if(!((CHAR)(x - 1) > x))
        error("CHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<CHAR>::value)
        error("CHAR is a pointer");
    #endif
}

static void test_USHORT_eq_uint16_t()
{
    if(sizeof(USHORT) != 2)
        error("USHORT is actually %d bytes", (int)sizeof(USHORT));
    USHORT x = 0;
    if(!((USHORT)(x - 1) > x))
        error("USHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<USHORT>::value)
        error("USHORT is a pointer");
    #endif
}

static void test_WORD_eq_uint16_t()
{
    if(sizeof(WORD) != 2)
        error("WORD is actually %d bytes", (int)sizeof(WORD));
    WORD x = 0;
    if(!((WORD)(x - 1) > x))
        error("WORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<WORD>::value)
        error("WORD is a pointer");
    #endif
}

static void test_SHORT_eq_int16_t()
{
    if(sizeof(SHORT) != 2)
        error("SHORT is actually %d bytes", (int)sizeof(SHORT));
    SHORT x = 0;
    if(!((SHORT)(x - 1) < x))
        error("SHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SHORT>::value)
        error("SHORT is a pointer");
    #endif
}

static void test_UINT_eq_uint32_t()
{
    if(sizeof(UINT) != 4)
        error("UINT is actually %d bytes", (int)sizeof(UINT));
    UINT x = 0;
    if(!((UINT)(x - 1) > x))
        error("UINT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT>::value)
        error("UINT is a pointer");
    #endif
}

static void test_ULONG_eq_uint32_t()
{
    if(sizeof(ULONG) != 4)
        error("ULONG is actually %d bytes", (int)sizeof(ULONG));
    ULONG x = 0;
    if(!((ULONG)(x - 1) > x))
        error("ULONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG>::value)
        error("ULONG is a pointer");
    #endif
}

static void test_DWORD_eq_uint32_t()
{
    if(sizeof(DWORD) != 4)
        error("DWORD is actually %d bytes", (int)sizeof(DWORD));
    DWORD x = 0;
    if(!((DWORD)(x - 1) > x))
        error("DWORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD>::value)
        error("DWORD is a pointer");
    #endif
}

static void test_INT_eq_int32_t()
{
    if(sizeof(INT) != 4)
        error("INT is actually %d bytes", (int)sizeof(INT));
    INT x = 0;
    if(!((INT)(x - 1) < x))
        error("INT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT>::value)
        error("INT is a pointer");
    #endif
}

static void test_LONG_eq_int32_t()
{
    if(sizeof(LONG) != 4)
        error("LONG is actually %d bytes", (int)sizeof(LONG));
    LONG x = 0;
    if(!((LONG)(x - 1) < x))
        error("LONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG>::value)
        error("LONG is a pointer");
    #endif
}

static void test_ULONGLONG_eq_uint64_t()
{
    if(sizeof(ULONGLONG) != 8)
        error("ULONGLONG is actually %d bytes", (int)sizeof(ULONGLONG));
    ULONGLONG x = 0;
    if(!((ULONGLONG)(x - 1) > x))
        error("ULONGLONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONGLONG>::value)
        error("ULONGLONG is a pointer");
    #endif
}

static void test_INT64_eq_int64_t()
{
    if(sizeof(INT64) != 8)
        error("INT64 is actually %d bytes", (int)sizeof(INT64));
    INT64 x = 0;
    if(!((INT64)(x - 1) < x))
        error("INT64 sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT64>::value)
        error("INT64 is a pointer");
    #endif
}

static void test_UINT_PTR_eq_uint64_t()
{
    if(sizeof(UINT_PTR) != 8)
        error("UINT_PTR is actually %d bytes", (int)sizeof(UINT_PTR));
    UINT_PTR x = 0;
    if(!((UINT_PTR)(x - 1) > x))
        error("UINT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT_PTR>::value)
        error("UINT_PTR is a pointer");
    #endif
}

static void test_size_t_eq_uint64_t()
{
    if(sizeof(size_t) != 8)
        error("size_t is actually %d bytes", (int)sizeof(size_t));
    size_t x = 0;
    if(!((size_t)(x - 1) > x))
        error("size_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<size_t>::value)
        error("size_t is a pointer");
    #endif
}

static void test_DWORD_PTR_eq_uint64_t()
{
    if(sizeof(DWORD_PTR) != 8)
        error("DWORD_PTR is actually %d bytes", (int)sizeof(DWORD_PTR));
    DWORD_PTR x = 0;
    if(!((DWORD_PTR)(x - 1) > x))
        error("DWORD_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD_PTR>::value)
        error("DWORD_PTR is a pointer");
    #endif
}

static void test_ULONG_PTR_eq_uint64_t()
{
    if(sizeof(ULONG_PTR) != 8)
        error("ULONG_PTR is actually %d bytes", (int)sizeof(ULONG_PTR));
    ULONG_PTR x = 0;
    if(!((ULONG_PTR)(x - 1) > x))
        error("ULONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG_PTR>::value)
        error("ULONG_PTR is a pointer");
    #endif
}

static void test_INT_PTR_eq_int64_t()
{
    if(sizeof(INT_PTR) != 8)
        error("INT_PTR is actually %d bytes", (int)sizeof(INT_PTR));
    INT_PTR x = 0;
    if(!((INT_PTR)(x - 1) < x))
        error("INT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT_PTR>::value)
        error("INT_PTR is a pointer");
    #endif
}

static void test_LONG_PTR_eq_int64_t()
{
    if(sizeof(LONG_PTR) != 8)
        error("LONG_PTR is actually %d bytes", (int)sizeof(LONG_PTR));
    LONG_PTR x = 0;
    if(!((LONG_PTR)(x - 1) < x))
        error("LONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG_PTR>::value)
        error("LONG_PTR is a pointer");
    #endif
}

static void test_ptrdiff_t_eq_int64_t()
{
    if(sizeof(ptrdiff_t) != 8)
        error("ptrdiff_t is actually %d bytes", (int)sizeof(ptrdiff_t));
    ptrdiff_t x = 0;
    if(!((ptrdiff_t)(x - 1) < x))
        error("ptrdiff_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ptrdiff_t>::value)
        error("ptrdiff_t is a pointer");
    #endif
}

static void test_SSIZE_T_eq_int64_t()
{
    if(sizeof(SSIZE_T) != 8)
        error("SSIZE_T is actually %d bytes", (int)sizeof(SSIZE_T));
    SSIZE_T x = 0;
    if(!((SSIZE_T)(x - 1) < x))
        error("SSIZE_T sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SSIZE_T>::value)
        error("SSIZE_T is a pointer");
    #endif
}

static void tests_types()
{
    test_UCHAR_eq_uint8_t();
    test_BYTE_eq_uint8_t();
    test_CHAR_eq_uint8_t();
    test_USHORT_eq_uint16_t();
    test_WORD_eq_uint16_t();
    test_SHORT_eq_int16_t();
    test_UINT_eq_uint32_t();
    test_ULONG_eq_uint32_t();
    test_DWORD_eq_uint32_t();
    test_INT_eq_int32_t();
    test_LONG_eq_int32_t();
    test_ULONGLONG_eq_uint64_t();
    test_INT64_eq_int64_t();
    test_UINT_PTR_eq_uint64_t();
    test_size_t_eq_uint64_t();
    test_DWORD_PTR_eq_uint64_t();
    test_ULONG_PTR_eq_uint64_t();
    test_INT_PTR_eq_int64_t();
    test_LONG_PTR_eq_int64_t();
    test_ptrdiff_t_eq_int64_t();
    test_SSIZE_T_eq_int64_t();
}

static void test_UShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &UShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToUChar), HRESULT (*)(_In_ USHORT, _Out_ UCHAR *)>::value)
            error("UShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0, &out) != 0)
            error("UShortToUChar failed to convert 0");
        if(out != 0)
            error("UShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0xff, &out) != 0)
            error("UShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToUChar(0x100, &out))
            error("UShortToUChar did not overflow when given 0x100");
    }

}

static void test_UShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ BYTE *) __attribute__ ((unused)) = &UShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToByte), HRESULT (*)(_In_ USHORT, _Out_ BYTE *)>::value)
            error("UShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0, &out) != 0)
            error("UShortToByte failed to convert 0");
        if(out != 0)
            error("UShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0xff, &out) != 0)
            error("UShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("UShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToByte(0x100, &out))
            error("UShortToByte did not overflow when given 0x100");
    }

}

static void test_UShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ CHAR *) __attribute__ ((unused)) = &UShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToChar), HRESULT (*)(_In_ USHORT, _Out_ CHAR *)>::value)
            error("UShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0, &out) != 0)
            error("UShortToChar failed to convert 0");
        if(out != 0)
            error("UShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0xff, &out) != 0)
            error("UShortToChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToChar(0x100, &out))
            error("UShortToChar did not overflow when given 0x100");
    }

}

static void test_UShortToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ SHORT *) __attribute__ ((unused)) = &UShortToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToShort), HRESULT (*)(_In_ USHORT, _Out_ SHORT *)>::value)
            error("UShortToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0, &out) != 0)
            error("UShortToShort failed to convert 0");
        if(out != 0)
            error("UShortToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0x7fff, &out) != 0)
            error("UShortToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UShortToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToShort(0x8000, &out))
            error("UShortToShort did not overflow when given 0x8000");
    }

}

static void test_WordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ UCHAR *) __attribute__ ((unused)) = &WordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToUChar), HRESULT (*)(_In_ WORD, _Out_ UCHAR *)>::value)
            error("WordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0, &out) != 0)
            error("WordToUChar failed to convert 0");
        if(out != 0)
            error("WordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0xff, &out) != 0)
            error("WordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToUChar(0x100, &out))
            error("WordToUChar did not overflow when given 0x100");
    }

}

static void test_WordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ BYTE *) __attribute__ ((unused)) = &WordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToByte), HRESULT (*)(_In_ WORD, _Out_ BYTE *)>::value)
            error("WordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToByte(0, &out) != 0)
            error("WordToByte failed to convert 0");
        if(out != 0)
            error("WordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToByte(0xff, &out) != 0)
            error("WordToByte failed to convert 0xff");
        if(out != 0xff)
            error("WordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToByte(0x100, &out))
            error("WordToByte did not overflow when given 0x100");
    }

}

static void test_WordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ CHAR *) __attribute__ ((unused)) = &WordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToChar), HRESULT (*)(_In_ WORD, _Out_ CHAR *)>::value)
            error("WordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToChar(0, &out) != 0)
            error("WordToChar failed to convert 0");
        if(out != 0)
            error("WordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToChar(0xff, &out) != 0)
            error("WordToChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToChar(0x100, &out))
            error("WordToChar did not overflow when given 0x100");
    }

}

static void test_WordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ SHORT *) __attribute__ ((unused)) = &WordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToShort), HRESULT (*)(_In_ WORD, _Out_ SHORT *)>::value)
            error("WordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToShort(0, &out) != 0)
            error("WordToShort failed to convert 0");
        if(out != 0)
            error("WordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToShort(0x7fff, &out) != 0)
            error("WordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("WordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToShort(0x8000, &out))
            error("WordToShort did not overflow when given 0x8000");
    }

}

static void test_ShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &ShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUChar), HRESULT (*)(_In_ SHORT, _Out_ UCHAR *)>::value)
            error("ShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0, &out) != 0)
            error("ShortToUChar failed to convert 0");
        if(out != 0)
            error("ShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0xff, &out) != 0)
            error("ShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar(0x100, &out))
            error("ShortToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar((-0ll - 1), &out))
            error("ShortToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ BYTE *) __attribute__ ((unused)) = &ShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToByte), HRESULT (*)(_In_ SHORT, _Out_ BYTE *)>::value)
            error("ShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0, &out) != 0)
            error("ShortToByte failed to convert 0");
        if(out != 0)
            error("ShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0xff, &out) != 0)
            error("ShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("ShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte(0x100, &out))
            error("ShortToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte((-0ll - 1), &out))
            error("ShortToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ CHAR *) __attribute__ ((unused)) = &ShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToChar), HRESULT (*)(_In_ SHORT, _Out_ CHAR *)>::value)
            error("ShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0, &out) != 0)
            error("ShortToChar failed to convert 0");
        if(out != 0)
            error("ShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0xff, &out) != 0)
            error("ShortToChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar(0x100, &out))
            error("ShortToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar((-0ll - 1), &out))
            error("ShortToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ USHORT *) __attribute__ ((unused)) = &ShortToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUShort), HRESULT (*)(_In_ SHORT, _Out_ USHORT *)>::value)
            error("ShortToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0, &out) != 0)
            error("ShortToUShort failed to convert 0");
        if(out != 0)
            error("ShortToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0x7fff, &out) != 0)
            error("ShortToUShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToUShort changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUShort((-0ll - 1), &out))
            error("ShortToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ WORD *) __attribute__ ((unused)) = &ShortToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToWord), HRESULT (*)(_In_ SHORT, _Out_ WORD *)>::value)
            error("ShortToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0, &out) != 0)
            error("ShortToWord failed to convert 0");
        if(out != 0)
            error("ShortToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0x7fff, &out) != 0)
            error("ShortToWord failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToWord changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToWord((-0ll - 1), &out))
            error("ShortToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_UIntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ UCHAR *) __attribute__ ((unused)) = &UIntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUChar), HRESULT (*)(_In_ UINT, _Out_ UCHAR *)>::value)
            error("UIntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0, &out) != 0)
            error("UIntToUChar failed to convert 0");
        if(out != 0)
            error("UIntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0xff, &out) != 0)
            error("UIntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUChar(0x100, &out))
            error("UIntToUChar did not overflow when given 0x100");
    }

}

static void test_UIntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ BYTE *) __attribute__ ((unused)) = &UIntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToByte), HRESULT (*)(_In_ UINT, _Out_ BYTE *)>::value)
            error("UIntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0, &out) != 0)
            error("UIntToByte failed to convert 0");
        if(out != 0)
            error("UIntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0xff, &out) != 0)
            error("UIntToByte failed to convert 0xff");
        if(out != 0xff)
            error("UIntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToByte(0x100, &out))
            error("UIntToByte did not overflow when given 0x100");
    }

}

static void test_UIntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ CHAR *) __attribute__ ((unused)) = &UIntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToChar), HRESULT (*)(_In_ UINT, _Out_ CHAR *)>::value)
            error("UIntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0, &out) != 0)
            error("UIntToChar failed to convert 0");
        if(out != 0)
            error("UIntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0xff, &out) != 0)
            error("UIntToChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToChar(0x100, &out))
            error("UIntToChar did not overflow when given 0x100");
    }

}

static void test_UIntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ USHORT *) __attribute__ ((unused)) = &UIntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUShort), HRESULT (*)(_In_ UINT, _Out_ USHORT *)>::value)
            error("UIntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0, &out) != 0)
            error("UIntToUShort failed to convert 0");
        if(out != 0)
            error("UIntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0xffff, &out) != 0)
            error("UIntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUShort(0x10000, &out))
            error("UIntToUShort did not overflow when given 0x10000");
    }

}

static void test_UIntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ WORD *) __attribute__ ((unused)) = &UIntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToWord), HRESULT (*)(_In_ UINT, _Out_ WORD *)>::value)
            error("UIntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0, &out) != 0)
            error("UIntToWord failed to convert 0");
        if(out != 0)
            error("UIntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0xffff, &out) != 0)
            error("UIntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToWord(0x10000, &out))
            error("UIntToWord did not overflow when given 0x10000");
    }

}

static void test_UIntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SHORT *) __attribute__ ((unused)) = &UIntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToShort), HRESULT (*)(_In_ UINT, _Out_ SHORT *)>::value)
            error("UIntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0, &out) != 0)
            error("UIntToShort failed to convert 0");
        if(out != 0)
            error("UIntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0x7fff, &out) != 0)
            error("UIntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UIntToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToShort(0x8000, &out))
            error("UIntToShort did not overflow when given 0x8000");
    }

}

static void test_UIntToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT *) __attribute__ ((unused)) = &UIntToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToInt), HRESULT (*)(_In_ UINT, _Out_ INT *)>::value)
            error("UIntToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0, &out) != 0)
            error("UIntToInt failed to convert 0");
        if(out != 0)
            error("UIntToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0x7fffffff, &out) != 0)
            error("UIntToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToInt(0x80000000, &out))
            error("UIntToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG *) __attribute__ ((unused)) = &UIntToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLong), HRESULT (*)(_In_ UINT, _Out_ LONG *)>::value)
            error("UIntToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0, &out) != 0)
            error("UIntToLong failed to convert 0");
        if(out != 0)
            error("UIntToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0x7fffffff, &out) != 0)
            error("UIntToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLong(0x80000000, &out))
            error("UIntToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToIntPtr), HRESULT (*)(_In_ UINT, _Out_ INT_PTR *)>::value)
            error("UIntToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0, &out) != 0)
            error("UIntToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0xffffffff, &out) != 0)
            error("UIntToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_UIntToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLongPtr), HRESULT (*)(_In_ UINT, _Out_ LONG_PTR *)>::value)
            error("UIntToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0, &out) != 0)
            error("UIntToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0xffffffff, &out) != 0)
            error("UIntToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_UIntToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &UIntToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToPtrdiffT), HRESULT (*)(_In_ UINT, _Out_ ptrdiff_t *)>::value)
            error("UIntToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0");
        if(out != 0)
            error("UIntToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0xffffffff, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_UIntToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToSSIZET), HRESULT (*)(_In_ UINT, _Out_ SSIZE_T *)>::value)
            error("UIntToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0, &out) != 0)
            error("UIntToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0xffffffff, &out) != 0)
            error("UIntToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_ULongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UCHAR *) __attribute__ ((unused)) = &ULongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUChar), HRESULT (*)(_In_ ULONG, _Out_ UCHAR *)>::value)
            error("ULongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0, &out) != 0)
            error("ULongToUChar failed to convert 0");
        if(out != 0)
            error("ULongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0xff, &out) != 0)
            error("ULongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUChar(0x100, &out))
            error("ULongToUChar did not overflow when given 0x100");
    }

}

static void test_ULongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ BYTE *) __attribute__ ((unused)) = &ULongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToByte), HRESULT (*)(_In_ ULONG, _Out_ BYTE *)>::value)
            error("ULongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0, &out) != 0)
            error("ULongToByte failed to convert 0");
        if(out != 0)
            error("ULongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0xff, &out) != 0)
            error("ULongToByte failed to convert 0xff");
        if(out != 0xff)
            error("ULongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToByte(0x100, &out))
            error("ULongToByte did not overflow when given 0x100");
    }

}

static void test_ULongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ CHAR *) __attribute__ ((unused)) = &ULongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToChar), HRESULT (*)(_In_ ULONG, _Out_ CHAR *)>::value)
            error("ULongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0, &out) != 0)
            error("ULongToChar failed to convert 0");
        if(out != 0)
            error("ULongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0xff, &out) != 0)
            error("ULongToChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToChar(0x100, &out))
            error("ULongToChar did not overflow when given 0x100");
    }

}

static void test_ULongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ USHORT *) __attribute__ ((unused)) = &ULongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUShort), HRESULT (*)(_In_ ULONG, _Out_ USHORT *)>::value)
            error("ULongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0, &out) != 0)
            error("ULongToUShort failed to convert 0");
        if(out != 0)
            error("ULongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0xffff, &out) != 0)
            error("ULongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUShort(0x10000, &out))
            error("ULongToUShort did not overflow when given 0x10000");
    }

}

static void test_ULongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ WORD *) __attribute__ ((unused)) = &ULongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToWord), HRESULT (*)(_In_ ULONG, _Out_ WORD *)>::value)
            error("ULongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0, &out) != 0)
            error("ULongToWord failed to convert 0");
        if(out != 0)
            error("ULongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0xffff, &out) != 0)
            error("ULongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToWord(0x10000, &out))
            error("ULongToWord did not overflow when given 0x10000");
    }

}

static void test_ULongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SHORT *) __attribute__ ((unused)) = &ULongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToShort), HRESULT (*)(_In_ ULONG, _Out_ SHORT *)>::value)
            error("ULongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0, &out) != 0)
            error("ULongToShort failed to convert 0");
        if(out != 0)
            error("ULongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0x7fff, &out) != 0)
            error("ULongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ULongToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToShort(0x8000, &out))
            error("ULongToShort did not overflow when given 0x8000");
    }

}

static void test_ULongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUInt), HRESULT (*)(_In_ ULONG, _Out_ UINT *)>::value)
            error("ULongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0, &out) != 0)
            error("ULongToUInt failed to convert 0");
        if(out != 0)
            error("ULongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0xffffffff, &out) != 0)
            error("ULongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT *) __attribute__ ((unused)) = &ULongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToInt), HRESULT (*)(_In_ ULONG, _Out_ INT *)>::value)
            error("ULongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0, &out) != 0)
            error("ULongToInt failed to convert 0");
        if(out != 0)
            error("ULongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0x7fffffff, &out) != 0)
            error("ULongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToInt(0x80000000, &out))
            error("ULongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLong), HRESULT (*)(_In_ ULONG, _Out_ LONG *)>::value)
            error("ULongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0, &out) != 0)
            error("ULongToLong failed to convert 0");
        if(out != 0)
            error("ULongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0x7fffffff, &out) != 0)
            error("ULongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLong(0x80000000, &out))
            error("ULongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUIntPtr), HRESULT (*)(_In_ ULONG, _Out_ UINT_PTR *)>::value)
            error("ULongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0, &out) != 0)
            error("ULongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToIntPtr), HRESULT (*)(_In_ ULONG, _Out_ INT_PTR *)>::value)
            error("ULongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0, &out) != 0)
            error("ULongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0xffffffff, &out) != 0)
            error("ULongToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLongPtr), HRESULT (*)(_In_ ULONG, _Out_ LONG_PTR *)>::value)
            error("ULongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0, &out) != 0)
            error("ULongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0xffffffff, &out) != 0)
            error("ULongToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToPtrdiffT), HRESULT (*)(_In_ ULONG, _Out_ ptrdiff_t *)>::value)
            error("ULongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0xffffffff, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_ULongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToSSIZET), HRESULT (*)(_In_ ULONG, _Out_ SSIZE_T *)>::value)
            error("ULongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0, &out) != 0)
            error("ULongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0xffffffff, &out) != 0)
            error("ULongToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_DWordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UCHAR *) __attribute__ ((unused)) = &DWordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUChar), HRESULT (*)(_In_ DWORD, _Out_ UCHAR *)>::value)
            error("DWordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0, &out) != 0)
            error("DWordToUChar failed to convert 0");
        if(out != 0)
            error("DWordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0xff, &out) != 0)
            error("DWordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUChar(0x100, &out))
            error("DWordToUChar did not overflow when given 0x100");
    }

}

static void test_DWordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ BYTE *) __attribute__ ((unused)) = &DWordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToByte), HRESULT (*)(_In_ DWORD, _Out_ BYTE *)>::value)
            error("DWordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0, &out) != 0)
            error("DWordToByte failed to convert 0");
        if(out != 0)
            error("DWordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0xff, &out) != 0)
            error("DWordToByte failed to convert 0xff");
        if(out != 0xff)
            error("DWordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToByte(0x100, &out))
            error("DWordToByte did not overflow when given 0x100");
    }

}

static void test_DWordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ CHAR *) __attribute__ ((unused)) = &DWordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToChar), HRESULT (*)(_In_ DWORD, _Out_ CHAR *)>::value)
            error("DWordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0, &out) != 0)
            error("DWordToChar failed to convert 0");
        if(out != 0)
            error("DWordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0xff, &out) != 0)
            error("DWordToChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToChar(0x100, &out))
            error("DWordToChar did not overflow when given 0x100");
    }

}

static void test_DWordToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ USHORT *) __attribute__ ((unused)) = &DWordToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUShort), HRESULT (*)(_In_ DWORD, _Out_ USHORT *)>::value)
            error("DWordToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0, &out) != 0)
            error("DWordToUShort failed to convert 0");
        if(out != 0)
            error("DWordToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0xffff, &out) != 0)
            error("DWordToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUShort(0x10000, &out))
            error("DWordToUShort did not overflow when given 0x10000");
    }

}

static void test_DWordToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ WORD *) __attribute__ ((unused)) = &DWordToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToWord), HRESULT (*)(_In_ DWORD, _Out_ WORD *)>::value)
            error("DWordToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0, &out) != 0)
            error("DWordToWord failed to convert 0");
        if(out != 0)
            error("DWordToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0xffff, &out) != 0)
            error("DWordToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToWord(0x10000, &out))
            error("DWordToWord did not overflow when given 0x10000");
    }

}

static void test_DWordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SHORT *) __attribute__ ((unused)) = &DWordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToShort), HRESULT (*)(_In_ DWORD, _Out_ SHORT *)>::value)
            error("DWordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0, &out) != 0)
            error("DWordToShort failed to convert 0");
        if(out != 0)
            error("DWordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0x7fff, &out) != 0)
            error("DWordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("DWordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToShort(0x8000, &out))
            error("DWordToShort did not overflow when given 0x8000");
    }

}

static void test_DWordToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT *) __attribute__ ((unused)) = &DWordToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUInt), HRESULT (*)(_In_ DWORD, _Out_ UINT *)>::value)
            error("DWordToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0, &out) != 0)
            error("DWordToUInt failed to convert 0");
        if(out != 0)
            error("DWordToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0xffffffff, &out) != 0)
            error("DWordToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT *) __attribute__ ((unused)) = &DWordToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToInt), HRESULT (*)(_In_ DWORD, _Out_ INT *)>::value)
            error("DWordToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0, &out) != 0)
            error("DWordToInt failed to convert 0");
        if(out != 0)
            error("DWordToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0x7fffffff, &out) != 0)
            error("DWordToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToInt(0x80000000, &out))
            error("DWordToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG *) __attribute__ ((unused)) = &DWordToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLong), HRESULT (*)(_In_ DWORD, _Out_ LONG *)>::value)
            error("DWordToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0, &out) != 0)
            error("DWordToLong failed to convert 0");
        if(out != 0)
            error("DWordToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0x7fffffff, &out) != 0)
            error("DWordToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLong(0x80000000, &out))
            error("DWordToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUIntPtr), HRESULT (*)(_In_ DWORD, _Out_ UINT_PTR *)>::value)
            error("DWordToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0, &out) != 0)
            error("DWordToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0xffffffff, &out) != 0)
            error("DWordToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToIntPtr), HRESULT (*)(_In_ DWORD, _Out_ INT_PTR *)>::value)
            error("DWordToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0, &out) != 0)
            error("DWordToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0xffffffff, &out) != 0)
            error("DWordToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLongPtr), HRESULT (*)(_In_ DWORD, _Out_ LONG_PTR *)>::value)
            error("DWordToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0, &out) != 0)
            error("DWordToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0xffffffff, &out) != 0)
            error("DWordToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToPtrdiffT), HRESULT (*)(_In_ DWORD, _Out_ ptrdiff_t *)>::value)
            error("DWordToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0xffffffff, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_DWordToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToSSIZET), HRESULT (*)(_In_ DWORD, _Out_ SSIZE_T *)>::value)
            error("DWordToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0, &out) != 0)
            error("DWordToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0xffffffff, &out) != 0)
            error("DWordToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_IntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UCHAR *) __attribute__ ((unused)) = &IntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUChar), HRESULT (*)(_In_ INT, _Out_ UCHAR *)>::value)
            error("IntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0, &out) != 0)
            error("IntToUChar failed to convert 0");
        if(out != 0)
            error("IntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0xff, &out) != 0)
            error("IntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar(0x100, &out))
            error("IntToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar((-0ll - 1), &out))
            error("IntToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ BYTE *) __attribute__ ((unused)) = &IntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToByte), HRESULT (*)(_In_ INT, _Out_ BYTE *)>::value)
            error("IntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToByte(0, &out) != 0)
            error("IntToByte failed to convert 0");
        if(out != 0)
            error("IntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToByte(0xff, &out) != 0)
            error("IntToByte failed to convert 0xff");
        if(out != 0xff)
            error("IntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte(0x100, &out))
            error("IntToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte((-0ll - 1), &out))
            error("IntToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ CHAR *) __attribute__ ((unused)) = &IntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToChar), HRESULT (*)(_In_ INT, _Out_ CHAR *)>::value)
            error("IntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToChar(0, &out) != 0)
            error("IntToChar failed to convert 0");
        if(out != 0)
            error("IntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToChar(0xff, &out) != 0)
            error("IntToChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar(0x100, &out))
            error("IntToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar((-0ll - 1), &out))
            error("IntToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ USHORT *) __attribute__ ((unused)) = &IntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUShort), HRESULT (*)(_In_ INT, _Out_ USHORT *)>::value)
            error("IntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0, &out) != 0)
            error("IntToUShort failed to convert 0");
        if(out != 0)
            error("IntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0xffff, &out) != 0)
            error("IntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort(0x10000, &out))
            error("IntToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort((-0ll - 1), &out))
            error("IntToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ WORD *) __attribute__ ((unused)) = &IntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToWord), HRESULT (*)(_In_ INT, _Out_ WORD *)>::value)
            error("IntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToWord(0, &out) != 0)
            error("IntToWord failed to convert 0");
        if(out != 0)
            error("IntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToWord(0xffff, &out) != 0)
            error("IntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord(0x10000, &out))
            error("IntToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord((-0ll - 1), &out))
            error("IntToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ SHORT *) __attribute__ ((unused)) = &IntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToShort), HRESULT (*)(_In_ INT, _Out_ SHORT *)>::value)
            error("IntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToShort(0, &out) != 0)
            error("IntToShort failed to convert 0");
        if(out != 0)
            error("IntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToShort(0x7fff, &out) != 0)
            error("IntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("IntToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToShort((-0x7fffll - 1), &out) != 0)
            error("IntToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("IntToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort(0x8000, &out))
            error("IntToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort((-0x8000ll - 1), &out))
            error("IntToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_IntToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT *) __attribute__ ((unused)) = &IntToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUInt), HRESULT (*)(_In_ INT, _Out_ UINT *)>::value)
            error("IntToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0, &out) != 0)
            error("IntToUInt failed to convert 0");
        if(out != 0)
            error("IntToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0x7fffffff, &out) != 0)
            error("IntToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUInt((-0ll - 1), &out))
            error("IntToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG *) __attribute__ ((unused)) = &IntToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULong), HRESULT (*)(_In_ INT, _Out_ ULONG *)>::value)
            error("IntToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULong(0, &out) != 0)
            error("IntToULong failed to convert 0");
        if(out != 0)
            error("IntToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULong(0x7fffffff, &out) != 0)
            error("IntToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULong((-0ll - 1), &out))
            error("IntToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD *) __attribute__ ((unused)) = &IntToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWord), HRESULT (*)(_In_ INT, _Out_ DWORD *)>::value)
            error("IntToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0, &out) != 0)
            error("IntToDWord failed to convert 0");
        if(out != 0)
            error("IntToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0x7fffffff, &out) != 0)
            error("IntToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWord((-0ll - 1), &out))
            error("IntToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongLong), HRESULT (*)(_In_ INT, _Out_ ULONGLONG *)>::value)
            error("IntToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0, &out) != 0)
            error("IntToULongLong failed to convert 0");
        if(out != 0)
            error("IntToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0x7fffffff, &out) != 0)
            error("IntToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongLong((-0ll - 1), &out))
            error("IntToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUIntPtr), HRESULT (*)(_In_ INT, _Out_ UINT_PTR *)>::value)
            error("IntToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0, &out) != 0)
            error("IntToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0x7fffffff, &out) != 0)
            error("IntToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUIntPtr((-0ll - 1), &out))
            error("IntToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ size_t *) __attribute__ ((unused)) = &IntToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToSizeT), HRESULT (*)(_In_ INT, _Out_ size_t *)>::value)
            error("IntToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0, &out) != 0)
            error("IntToSizeT failed to convert 0");
        if(out != 0)
            error("IntToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0x7fffffff, &out) != 0)
            error("IntToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToSizeT((-0ll - 1), &out))
            error("IntToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWordPtr), HRESULT (*)(_In_ INT, _Out_ DWORD_PTR *)>::value)
            error("IntToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0, &out) != 0)
            error("IntToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0x7fffffff, &out) != 0)
            error("IntToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWordPtr((-0ll - 1), &out))
            error("IntToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongPtr), HRESULT (*)(_In_ INT, _Out_ ULONG_PTR *)>::value)
            error("IntToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0, &out) != 0)
            error("IntToULongPtr failed to convert 0");
        if(out != 0)
            error("IntToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0x7fffffff, &out) != 0)
            error("IntToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongPtr((-0ll - 1), &out))
            error("IntToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UCHAR *) __attribute__ ((unused)) = &LongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUChar), HRESULT (*)(_In_ LONG, _Out_ UCHAR *)>::value)
            error("LongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0, &out) != 0)
            error("LongToUChar failed to convert 0");
        if(out != 0)
            error("LongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0xff, &out) != 0)
            error("LongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar(0x100, &out))
            error("LongToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar((-0ll - 1), &out))
            error("LongToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ BYTE *) __attribute__ ((unused)) = &LongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToByte), HRESULT (*)(_In_ LONG, _Out_ BYTE *)>::value)
            error("LongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToByte(0, &out) != 0)
            error("LongToByte failed to convert 0");
        if(out != 0)
            error("LongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToByte(0xff, &out) != 0)
            error("LongToByte failed to convert 0xff");
        if(out != 0xff)
            error("LongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte(0x100, &out))
            error("LongToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte((-0ll - 1), &out))
            error("LongToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ CHAR *) __attribute__ ((unused)) = &LongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToChar), HRESULT (*)(_In_ LONG, _Out_ CHAR *)>::value)
            error("LongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToChar(0, &out) != 0)
            error("LongToChar failed to convert 0");
        if(out != 0)
            error("LongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToChar(0xff, &out) != 0)
            error("LongToChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar(0x100, &out))
            error("LongToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar((-0ll - 1), &out))
            error("LongToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ USHORT *) __attribute__ ((unused)) = &LongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUShort), HRESULT (*)(_In_ LONG, _Out_ USHORT *)>::value)
            error("LongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0, &out) != 0)
            error("LongToUShort failed to convert 0");
        if(out != 0)
            error("LongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0xffff, &out) != 0)
            error("LongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort(0x10000, &out))
            error("LongToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort((-0ll - 1), &out))
            error("LongToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ WORD *) __attribute__ ((unused)) = &LongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToWord), HRESULT (*)(_In_ LONG, _Out_ WORD *)>::value)
            error("LongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToWord(0, &out) != 0)
            error("LongToWord failed to convert 0");
        if(out != 0)
            error("LongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToWord(0xffff, &out) != 0)
            error("LongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord(0x10000, &out))
            error("LongToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord((-0ll - 1), &out))
            error("LongToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ SHORT *) __attribute__ ((unused)) = &LongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToShort), HRESULT (*)(_In_ LONG, _Out_ SHORT *)>::value)
            error("LongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToShort(0, &out) != 0)
            error("LongToShort failed to convert 0");
        if(out != 0)
            error("LongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToShort(0x7fff, &out) != 0)
            error("LongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("LongToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToShort((-0x7fffll - 1), &out) != 0)
            error("LongToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("LongToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort(0x8000, &out))
            error("LongToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort((-0x8000ll - 1), &out))
            error("LongToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_LongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT *) __attribute__ ((unused)) = &LongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUInt), HRESULT (*)(_In_ LONG, _Out_ UINT *)>::value)
            error("LongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0, &out) != 0)
            error("LongToUInt failed to convert 0");
        if(out != 0)
            error("LongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0x7fffffff, &out) != 0)
            error("LongToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUInt((-0ll - 1), &out))
            error("LongToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG *) __attribute__ ((unused)) = &LongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULong), HRESULT (*)(_In_ LONG, _Out_ ULONG *)>::value)
            error("LongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULong(0, &out) != 0)
            error("LongToULong failed to convert 0");
        if(out != 0)
            error("LongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULong(0x7fffffff, &out) != 0)
            error("LongToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULong((-0ll - 1), &out))
            error("LongToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD *) __attribute__ ((unused)) = &LongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWord), HRESULT (*)(_In_ LONG, _Out_ DWORD *)>::value)
            error("LongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0, &out) != 0)
            error("LongToDWord failed to convert 0");
        if(out != 0)
            error("LongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0x7fffffff, &out) != 0)
            error("LongToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWord((-0ll - 1), &out))
            error("LongToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT *) __attribute__ ((unused)) = &LongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToInt), HRESULT (*)(_In_ LONG, _Out_ INT *)>::value)
            error("LongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToInt(0, &out) != 0)
            error("LongToInt failed to convert 0");
        if(out != 0)
            error("LongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToInt(0x7fffffff, &out) != 0)
            error("LongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongLong), HRESULT (*)(_In_ LONG, _Out_ ULONGLONG *)>::value)
            error("LongToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0, &out) != 0)
            error("LongToULongLong failed to convert 0");
        if(out != 0)
            error("LongToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0x7fffffff, &out) != 0)
            error("LongToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongLong((-0ll - 1), &out))
            error("LongToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUIntPtr), HRESULT (*)(_In_ LONG, _Out_ UINT_PTR *)>::value)
            error("LongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0, &out) != 0)
            error("LongToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0x7fffffff, &out) != 0)
            error("LongToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUIntPtr((-0ll - 1), &out))
            error("LongToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ size_t *) __attribute__ ((unused)) = &LongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToSizeT), HRESULT (*)(_In_ LONG, _Out_ size_t *)>::value)
            error("LongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0, &out) != 0)
            error("LongToSizeT failed to convert 0");
        if(out != 0)
            error("LongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0x7fffffff, &out) != 0)
            error("LongToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToSizeT((-0ll - 1), &out))
            error("LongToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWordPtr), HRESULT (*)(_In_ LONG, _Out_ DWORD_PTR *)>::value)
            error("LongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0, &out) != 0)
            error("LongToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0x7fffffff, &out) != 0)
            error("LongToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWordPtr((-0ll - 1), &out))
            error("LongToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongPtr), HRESULT (*)(_In_ LONG, _Out_ ULONG_PTR *)>::value)
            error("LongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0, &out) != 0)
            error("LongToULongPtr failed to convert 0");
        if(out != 0)
            error("LongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0x7fffffff, &out) != 0)
            error("LongToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongPtr((-0ll - 1), &out))
            error("LongToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToIntPtr), HRESULT (*)(_In_ LONG, _Out_ INT_PTR *)>::value)
            error("LongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0, &out) != 0)
            error("LongToIntPtr failed to convert 0");
        if(out != 0)
            error("LongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0x7fffffff, &out) != 0)
            error("LongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &LongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToPtrdiffT), HRESULT (*)(_In_ LONG, _Out_ ptrdiff_t *)>::value)
            error("LongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0, &out) != 0)
            error("LongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("LongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0x7fffffff, &out) != 0)
            error("LongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("LongToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_ULongLongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongLongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUInt), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT *)>::value)
            error("ULongLongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0, &out) != 0)
            error("ULongLongToUInt failed to convert 0");
        if(out != 0)
            error("ULongLongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0xffffffff, &out) != 0)
            error("ULongLongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUInt(0x100000000, &out))
            error("ULongLongToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG *) __attribute__ ((unused)) = &ULongLongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULong), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG *)>::value)
            error("ULongLongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0, &out) != 0)
            error("ULongLongToULong failed to convert 0");
        if(out != 0)
            error("ULongLongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0xffffffff, &out) != 0)
            error("ULongLongToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULong(0x100000000, &out))
            error("ULongLongToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD *) __attribute__ ((unused)) = &ULongLongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWord), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD *)>::value)
            error("ULongLongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0, &out) != 0)
            error("ULongLongToDWord failed to convert 0");
        if(out != 0)
            error("ULongLongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0xffffffff, &out) != 0)
            error("ULongLongToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWord(0x100000000, &out))
            error("ULongLongToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT *) __attribute__ ((unused)) = &ULongLongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt), HRESULT (*)(_In_ ULONGLONG, _Out_ INT *)>::value)
            error("ULongLongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0, &out) != 0)
            error("ULongLongToInt failed to convert 0");
        if(out != 0)
            error("ULongLongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0x7fffffff, &out) != 0)
            error("ULongLongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt(0x80000000, &out))
            error("ULongLongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongLongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLong), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG *)>::value)
            error("ULongLongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0, &out) != 0)
            error("ULongLongToLong failed to convert 0");
        if(out != 0)
            error("ULongLongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0x7fffffff, &out) != 0)
            error("ULongLongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLong(0x80000000, &out))
            error("ULongLongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT64 *) __attribute__ ((unused)) = &ULongLongToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt64), HRESULT (*)(_In_ ULONGLONG, _Out_ INT64 *)>::value)
            error("ULongLongToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0, &out) != 0)
            error("ULongLongToInt64 failed to convert 0");
        if(out != 0)
            error("ULongLongToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt64(0x8000000000000000, &out))
            error("ULongLongToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongLongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT_PTR *)>::value)
            error("ULongLongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ size_t *) __attribute__ ((unused)) = &ULongLongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSizeT), HRESULT (*)(_In_ ULONGLONG, _Out_ size_t *)>::value)
            error("ULongLongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0, &out) != 0)
            error("ULongLongToSizeT failed to convert 0");
        if(out != 0)
            error("ULongLongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0xffffffffffffffff, &out) != 0)
            error("ULongLongToSizeT failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToSizeT changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &ULongLongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWordPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD_PTR *)>::value)
            error("ULongLongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToDWordPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &ULongLongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG_PTR *)>::value)
            error("ULongLongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToULongPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongLongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ INT_PTR *)>::value)
            error("ULongLongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToIntPtr(0x8000000000000000, &out))
            error("ULongLongToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongLongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG_PTR *)>::value)
            error("ULongLongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLongPtr(0x8000000000000000, &out))
            error("ULongLongToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongLongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToPtrdiffT), HRESULT (*)(_In_ ULONGLONG, _Out_ ptrdiff_t *)>::value)
            error("ULongLongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongLongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToPtrdiffT(0x8000000000000000, &out))
            error("ULongLongToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongLongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSSIZET), HRESULT (*)(_In_ ULONGLONG, _Out_ SSIZE_T *)>::value)
            error("ULongLongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongLongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSSIZET(0x8000000000000000, &out))
            error("ULongLongToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_Int64ToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT *) __attribute__ ((unused)) = &Int64ToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUInt), HRESULT (*)(_In_ INT64, _Out_ UINT *)>::value)
            error("Int64ToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0, &out) != 0)
            error("Int64ToUInt failed to convert 0");
        if(out != 0)
            error("Int64ToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0xffffffff, &out) != 0)
            error("Int64ToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt(0x100000000, &out))
            error("Int64ToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt((-0ll - 1), &out))
            error("Int64ToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG *) __attribute__ ((unused)) = &Int64ToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULong), HRESULT (*)(_In_ INT64, _Out_ ULONG *)>::value)
            error("Int64ToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0, &out) != 0)
            error("Int64ToULong failed to convert 0");
        if(out != 0)
            error("Int64ToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0xffffffff, &out) != 0)
            error("Int64ToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong(0x100000000, &out))
            error("Int64ToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong((-0ll - 1), &out))
            error("Int64ToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD *) __attribute__ ((unused)) = &Int64ToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWord), HRESULT (*)(_In_ INT64, _Out_ DWORD *)>::value)
            error("Int64ToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0, &out) != 0)
            error("Int64ToDWord failed to convert 0");
        if(out != 0)
            error("Int64ToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0xffffffff, &out) != 0)
            error("Int64ToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord(0x100000000, &out))
            error("Int64ToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord((-0ll - 1), &out))
            error("Int64ToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT *) __attribute__ ((unused)) = &Int64ToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToInt), HRESULT (*)(_In_ INT64, _Out_ INT *)>::value)
            error("Int64ToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0, &out) != 0)
            error("Int64ToInt failed to convert 0");
        if(out != 0)
            error("Int64ToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0x7fffffff, &out) != 0)
            error("Int64ToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt(0x80000000, &out))
            error("Int64ToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt((-0x80000000ll - 1), &out))
            error("Int64ToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG *) __attribute__ ((unused)) = &Int64ToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLong), HRESULT (*)(_In_ INT64, _Out_ LONG *)>::value)
            error("Int64ToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0, &out) != 0)
            error("Int64ToLong failed to convert 0");
        if(out != 0)
            error("Int64ToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0x7fffffff, &out) != 0)
            error("Int64ToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong(0x80000000, &out))
            error("Int64ToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong((-0x80000000ll - 1), &out))
            error("Int64ToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONGLONG *) __attribute__ ((unused)) = &Int64ToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongLong), HRESULT (*)(_In_ INT64, _Out_ ULONGLONG *)>::value)
            error("Int64ToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0, &out) != 0)
            error("Int64ToULongLong failed to convert 0");
        if(out != 0)
            error("Int64ToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongLong((-0ll - 1), &out))
            error("Int64ToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT_PTR *) __attribute__ ((unused)) = &Int64ToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUIntPtr), HRESULT (*)(_In_ INT64, _Out_ UINT_PTR *)>::value)
            error("Int64ToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr((-0ll - 1), &out))
            error("Int64ToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ size_t *) __attribute__ ((unused)) = &Int64ToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSizeT), HRESULT (*)(_In_ INT64, _Out_ size_t *)>::value)
            error("Int64ToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0, &out) != 0)
            error("Int64ToSizeT failed to convert 0");
        if(out != 0)
            error("Int64ToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0x7fffffffffffffff, &out) != 0)
            error("Int64ToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT((-0ll - 1), &out))
            error("Int64ToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &Int64ToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWordPtr), HRESULT (*)(_In_ INT64, _Out_ DWORD_PTR *)>::value)
            error("Int64ToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0");
        if(out != 0)
            error("Int64ToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr((-0ll - 1), &out))
            error("Int64ToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &Int64ToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongPtr), HRESULT (*)(_In_ INT64, _Out_ ULONG_PTR *)>::value)
            error("Int64ToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0, &out) != 0)
            error("Int64ToULongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr((-0ll - 1), &out))
            error("Int64ToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT_PTR *) __attribute__ ((unused)) = &Int64ToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToIntPtr), HRESULT (*)(_In_ INT64, _Out_ INT_PTR *)>::value)
            error("Int64ToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0, &out) != 0)
            error("Int64ToIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG_PTR *) __attribute__ ((unused)) = &Int64ToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLongPtr), HRESULT (*)(_In_ INT64, _Out_ LONG_PTR *)>::value)
            error("Int64ToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0, &out) != 0)
            error("Int64ToLongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToLongPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToLongPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &Int64ToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToPtrdiffT), HRESULT (*)(_In_ INT64, _Out_ ptrdiff_t *)>::value)
            error("Int64ToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0");
        if(out != 0)
            error("Int64ToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToPtrdiffT failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToPtrdiffT changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ SSIZE_T *) __attribute__ ((unused)) = &Int64ToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSSIZET), HRESULT (*)(_In_ INT64, _Out_ SSIZE_T *)>::value)
            error("Int64ToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0, &out) != 0)
            error("Int64ToSSIZET failed to convert 0");
        if(out != 0)
            error("Int64ToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("Int64ToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToSSIZET failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToSSIZET changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_UIntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &UIntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToUInt), HRESULT (*)(_In_ UINT_PTR, _Out_ UINT *)>::value)
            error("UIntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0, &out) != 0)
            error("UIntPtrToUInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0xffffffff, &out) != 0)
            error("UIntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToUInt(0x100000000, &out))
            error("UIntPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &UIntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToULong), HRESULT (*)(_In_ UINT_PTR, _Out_ ULONG *)>::value)
            error("UIntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0, &out) != 0)
            error("UIntPtrToULong failed to convert 0");
        if(out != 0)
            error("UIntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0xffffffff, &out) != 0)
            error("UIntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToULong(0x100000000, &out))
            error("UIntPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &UIntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToDWord), HRESULT (*)(_In_ UINT_PTR, _Out_ DWORD *)>::value)
            error("UIntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0, &out) != 0)
            error("UIntPtrToDWord failed to convert 0");
        if(out != 0)
            error("UIntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0xffffffff, &out) != 0)
            error("UIntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToDWord(0x100000000, &out))
            error("UIntPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT *) __attribute__ ((unused)) = &UIntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt), HRESULT (*)(_In_ UINT_PTR, _Out_ INT *)>::value)
            error("UIntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0, &out) != 0)
            error("UIntPtrToInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0x7fffffff, &out) != 0)
            error("UIntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt(0x80000000, &out))
            error("UIntPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &UIntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLong), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG *)>::value)
            error("UIntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0, &out) != 0)
            error("UIntPtrToLong failed to convert 0");
        if(out != 0)
            error("UIntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0x7fffffff, &out) != 0)
            error("UIntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLong(0x80000000, &out))
            error("UIntPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &UIntPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt64), HRESULT (*)(_In_ UINT_PTR, _Out_ INT64 *)>::value)
            error("UIntPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt64(0x8000000000000000, &out))
            error("UIntPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToIntPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ INT_PTR *)>::value)
            error("UIntPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToIntPtr(0x8000000000000000, &out))
            error("UIntPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLongPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG_PTR *)>::value)
            error("UIntPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLongPtr(0x8000000000000000, &out))
            error("UIntPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToSSIZET), HRESULT (*)(_In_ UINT_PTR, _Out_ SSIZE_T *)>::value)
            error("UIntPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToSSIZET(0x8000000000000000, &out))
            error("UIntPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ UINT *) __attribute__ ((unused)) = &SizeTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToUInt), HRESULT (*)(_In_ size_t, _Out_ UINT *)>::value)
            error("SizeTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0, &out) != 0)
            error("SizeTToUInt failed to convert 0");
        if(out != 0)
            error("SizeTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0xffffffff, &out) != 0)
            error("SizeTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToUInt(0x100000000, &out))
            error("SizeTToUInt did not overflow when given 0x100000000");
    }

}

static void test_SizeTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ULONG *) __attribute__ ((unused)) = &SizeTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToULong), HRESULT (*)(_In_ size_t, _Out_ ULONG *)>::value)
            error("SizeTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0, &out) != 0)
            error("SizeTToULong failed to convert 0");
        if(out != 0)
            error("SizeTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0xffffffff, &out) != 0)
            error("SizeTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToULong(0x100000000, &out))
            error("SizeTToULong did not overflow when given 0x100000000");
    }

}

static void test_SizeTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ DWORD *) __attribute__ ((unused)) = &SizeTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToDWord), HRESULT (*)(_In_ size_t, _Out_ DWORD *)>::value)
            error("SizeTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0, &out) != 0)
            error("SizeTToDWord failed to convert 0");
        if(out != 0)
            error("SizeTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0xffffffff, &out) != 0)
            error("SizeTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToDWord(0x100000000, &out))
            error("SizeTToDWord did not overflow when given 0x100000000");
    }

}

static void test_SizeTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT *) __attribute__ ((unused)) = &SizeTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt), HRESULT (*)(_In_ size_t, _Out_ INT *)>::value)
            error("SizeTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0, &out) != 0)
            error("SizeTToInt failed to convert 0");
        if(out != 0)
            error("SizeTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0x7fffffff, &out) != 0)
            error("SizeTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt(0x80000000, &out))
            error("SizeTToInt did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG *) __attribute__ ((unused)) = &SizeTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLong), HRESULT (*)(_In_ size_t, _Out_ LONG *)>::value)
            error("SizeTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0, &out) != 0)
            error("SizeTToLong failed to convert 0");
        if(out != 0)
            error("SizeTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0x7fffffff, &out) != 0)
            error("SizeTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLong(0x80000000, &out))
            error("SizeTToLong did not overflow when given 0x80000000");
    }

}

static void test_SizeTToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT64 *) __attribute__ ((unused)) = &SizeTToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt64), HRESULT (*)(_In_ size_t, _Out_ INT64 *)>::value)
            error("SizeTToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0, &out) != 0)
            error("SizeTToInt64 failed to convert 0");
        if(out != 0)
            error("SizeTToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0x7fffffffffffffff, &out) != 0)
            error("SizeTToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt64(0x8000000000000000, &out))
            error("SizeTToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT_PTR *) __attribute__ ((unused)) = &SizeTToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToIntPtr), HRESULT (*)(_In_ size_t, _Out_ INT_PTR *)>::value)
            error("SizeTToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0, &out) != 0)
            error("SizeTToIntPtr failed to convert 0");
        if(out != 0)
            error("SizeTToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SizeTToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToIntPtr(0x8000000000000000, &out))
            error("SizeTToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG_PTR *) __attribute__ ((unused)) = &SizeTToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLongPtr), HRESULT (*)(_In_ size_t, _Out_ LONG_PTR *)>::value)
            error("SizeTToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0, &out) != 0)
            error("SizeTToLongPtr failed to convert 0");
        if(out != 0)
            error("SizeTToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("SizeTToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLongPtr(0x8000000000000000, &out))
            error("SizeTToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &SizeTToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToPtrdiffT), HRESULT (*)(_In_ size_t, _Out_ ptrdiff_t *)>::value)
            error("SizeTToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0");
        if(out != 0)
            error("SizeTToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToPtrdiffT(0x8000000000000000, &out))
            error("SizeTToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ SSIZE_T *) __attribute__ ((unused)) = &SizeTToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToSSIZET), HRESULT (*)(_In_ size_t, _Out_ SSIZE_T *)>::value)
            error("SizeTToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0, &out) != 0)
            error("SizeTToSSIZET failed to convert 0");
        if(out != 0)
            error("SizeTToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("SizeTToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToSSIZET(0x8000000000000000, &out))
            error("SizeTToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT *) __attribute__ ((unused)) = &DWordPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT *)>::value)
            error("DWordPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0, &out) != 0)
            error("DWordPtrToUInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0xffffffff, &out) != 0)
            error("DWordPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToUInt(0x100000000, &out))
            error("DWordPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &DWordPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToULong), HRESULT (*)(_In_ DWORD_PTR, _Out_ ULONG *)>::value)
            error("DWordPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0, &out) != 0)
            error("DWordPtrToULong failed to convert 0");
        if(out != 0)
            error("DWordPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0xffffffff, &out) != 0)
            error("DWordPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToULong(0x100000000, &out))
            error("DWordPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &DWordPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value)
            error("DWordPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0, &out) != 0)
            error("DWordPtrToDWord failed to convert 0");
        if(out != 0)
            error("DWordPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0xffffffff, &out) != 0)
            error("DWordPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToDWord(0x100000000, &out))
            error("DWordPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT *) __attribute__ ((unused)) = &DWordPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT *)>::value)
            error("DWordPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0, &out) != 0)
            error("DWordPtrToInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0x7fffffff, &out) != 0)
            error("DWordPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt(0x80000000, &out))
            error("DWordPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG *) __attribute__ ((unused)) = &DWordPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLong), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG *)>::value)
            error("DWordPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0, &out) != 0)
            error("DWordPtrToLong failed to convert 0");
        if(out != 0)
            error("DWordPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0x7fffffff, &out) != 0)
            error("DWordPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLong(0x80000000, &out))
            error("DWordPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &DWordPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt64), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT64 *)>::value)
            error("DWordPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt64(0x8000000000000000, &out))
            error("DWordPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT_PTR *)>::value)
            error("DWordPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("DWordPtrToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_DWordPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT_PTR *)>::value)
            error("DWordPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToIntPtr(0x8000000000000000, &out))
            error("DWordPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLongPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG_PTR *)>::value)
            error("DWordPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLongPtr(0x8000000000000000, &out))
            error("DWordPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToPtrdiffT), HRESULT (*)(_In_ DWORD_PTR, _Out_ ptrdiff_t *)>::value)
            error("DWordPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToPtrdiffT(0x8000000000000000, &out))
            error("DWordPtrToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToSSIZET), HRESULT (*)(_In_ DWORD_PTR, _Out_ SSIZE_T *)>::value)
            error("DWordPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToSSIZET(0x8000000000000000, &out))
            error("DWordPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &ULongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT *)>::value)
            error("ULongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0, &out) != 0)
            error("ULongPtrToUInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0xffffffff, &out) != 0)
            error("ULongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToUInt(0x100000000, &out))
            error("ULongPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &ULongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToULong), HRESULT (*)(_In_ ULONG_PTR, _Out_ ULONG *)>::value)
            error("ULongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0, &out) != 0)
            error("ULongPtrToULong failed to convert 0");
        if(out != 0)
            error("ULongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0xffffffff, &out) != 0)
            error("ULongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToULong(0x100000000, &out))
            error("ULongPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &ULongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToDWord), HRESULT (*)(_In_ ULONG_PTR, _Out_ DWORD *)>::value)
            error("ULongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0, &out) != 0)
            error("ULongPtrToDWord failed to convert 0");
        if(out != 0)
            error("ULongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0xffffffff, &out) != 0)
            error("ULongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToDWord(0x100000000, &out))
            error("ULongPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &ULongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT *)>::value)
            error("ULongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0, &out) != 0)
            error("ULongPtrToInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0x7fffffff, &out) != 0)
            error("ULongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt(0x80000000, &out))
            error("ULongPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &ULongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLong), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG *)>::value)
            error("ULongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0, &out) != 0)
            error("ULongPtrToLong failed to convert 0");
        if(out != 0)
            error("ULongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0x7fffffff, &out) != 0)
            error("ULongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLong(0x80000000, &out))
            error("ULongPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &ULongPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt64), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT64 *)>::value)
            error("ULongPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt64(0x8000000000000000, &out))
            error("ULongPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT_PTR *)>::value)
            error("ULongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongPtrToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT_PTR *)>::value)
            error("ULongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToIntPtr(0x8000000000000000, &out))
            error("ULongPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLongPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG_PTR *)>::value)
            error("ULongPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLongPtr(0x8000000000000000, &out))
            error("ULongPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToPtrdiffT), HRESULT (*)(_In_ ULONG_PTR, _Out_ ptrdiff_t *)>::value)
            error("ULongPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToPtrdiffT(0x8000000000000000, &out))
            error("ULongPtrToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToSSIZET), HRESULT (*)(_In_ ULONG_PTR, _Out_ SSIZE_T *)>::value)
            error("ULongPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToSSIZET(0x8000000000000000, &out))
            error("ULongPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_IntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &IntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUInt), HRESULT (*)(_In_ INT_PTR, _Out_ UINT *)>::value)
            error("IntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0, &out) != 0)
            error("IntPtrToUInt failed to convert 0");
        if(out != 0)
            error("IntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0xffffffff, &out) != 0)
            error("IntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt(0x100000000, &out))
            error("IntPtrToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt((-0ll - 1), &out))
            error("IntPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &IntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG *)>::value)
            error("IntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0, &out) != 0)
            error("IntPtrToULong failed to convert 0");
        if(out != 0)
            error("IntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0xffffffff, &out) != 0)
            error("IntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong(0x100000000, &out))
            error("IntPtrToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong((-0ll - 1), &out))
            error("IntPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &IntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWord), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD *)>::value)
            error("IntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0, &out) != 0)
            error("IntPtrToDWord failed to convert 0");
        if(out != 0)
            error("IntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0xffffffff, &out) != 0)
            error("IntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord(0x100000000, &out))
            error("IntPtrToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord((-0ll - 1), &out))
            error("IntPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ INT *) __attribute__ ((unused)) = &IntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToInt), HRESULT (*)(_In_ INT_PTR, _Out_ INT *)>::value)
            error("IntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0, &out) != 0)
            error("IntPtrToInt failed to convert 0");
        if(out != 0)
            error("IntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0x7fffffff, &out) != 0)
            error("IntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToInt(0x80000000, &out))
            error("IntPtrToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToInt((-0x80000000ll - 1), &out))
            error("IntPtrToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_IntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &IntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToLong), HRESULT (*)(_In_ INT_PTR, _Out_ LONG *)>::value)
            error("IntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0, &out) != 0)
            error("IntPtrToLong failed to convert 0");
        if(out != 0)
            error("IntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0x7fffffff, &out) != 0)
            error("IntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToLong(0x80000000, &out))
            error("IntPtrToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToLong((-0x80000000ll - 1), &out))
            error("IntPtrToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_IntPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongLong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONGLONG *)>::value)
            error("IntPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0, &out) != 0)
            error("IntPtrToULongLong failed to convert 0");
        if(out != 0)
            error("IntPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongLong((-0ll - 1), &out))
            error("IntPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUIntPtr), HRESULT (*)(_In_ INT_PTR, _Out_ UINT_PTR *)>::value)
            error("IntPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUIntPtr((-0ll - 1), &out))
            error("IntPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ size_t *) __attribute__ ((unused)) = &IntPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToSizeT), HRESULT (*)(_In_ INT_PTR, _Out_ size_t *)>::value)
            error("IntPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0, &out) != 0)
            error("IntPtrToSizeT failed to convert 0");
        if(out != 0)
            error("IntPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToSizeT((-0ll - 1), &out))
            error("IntPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWordPtr), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD_PTR *)>::value)
            error("IntPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWordPtr((-0ll - 1), &out))
            error("IntPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongPtr), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG_PTR *)>::value)
            error("IntPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongPtr((-0ll - 1), &out))
            error("IntPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &LongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUInt), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT *)>::value)
            error("LongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0, &out) != 0)
            error("LongPtrToUInt failed to convert 0");
        if(out != 0)
            error("LongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0xffffffff, &out) != 0)
            error("LongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt(0x100000000, &out))
            error("LongPtrToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt((-0ll - 1), &out))
            error("LongPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &LongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG *)>::value)
            error("LongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0, &out) != 0)
            error("LongPtrToULong failed to convert 0");
        if(out != 0)
            error("LongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0xffffffff, &out) != 0)
            error("LongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong(0x100000000, &out))
            error("LongPtrToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong((-0ll - 1), &out))
            error("LongPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &LongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWord), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD *)>::value)
            error("LongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0, &out) != 0)
            error("LongPtrToDWord failed to convert 0");
        if(out != 0)
            error("LongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0xffffffff, &out) != 0)
            error("LongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord(0x100000000, &out))
            error("LongPtrToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord((-0ll - 1), &out))
            error("LongPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &LongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToInt), HRESULT (*)(_In_ LONG_PTR, _Out_ INT *)>::value)
            error("LongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0, &out) != 0)
            error("LongPtrToInt failed to convert 0");
        if(out != 0)
            error("LongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0x7fffffff, &out) != 0)
            error("LongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToInt(0x80000000, &out))
            error("LongPtrToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToInt((-0x80000000ll - 1), &out))
            error("LongPtrToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_LongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &LongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToLong), HRESULT (*)(_In_ LONG_PTR, _Out_ LONG *)>::value)
            error("LongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0, &out) != 0)
            error("LongPtrToLong failed to convert 0");
        if(out != 0)
            error("LongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0x7fffffff, &out) != 0)
            error("LongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToLong(0x80000000, &out))
            error("LongPtrToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToLong((-0x80000000ll - 1), &out))
            error("LongPtrToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_LongPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongLong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONGLONG *)>::value)
            error("LongPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0, &out) != 0)
            error("LongPtrToULongLong failed to convert 0");
        if(out != 0)
            error("LongPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongLong((-0ll - 1), &out))
            error("LongPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT_PTR *)>::value)
            error("LongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUIntPtr((-0ll - 1), &out))
            error("LongPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ size_t *) __attribute__ ((unused)) = &LongPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToSizeT), HRESULT (*)(_In_ LONG_PTR, _Out_ size_t *)>::value)
            error("LongPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0, &out) != 0)
            error("LongPtrToSizeT failed to convert 0");
        if(out != 0)
            error("LongPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToSizeT((-0ll - 1), &out))
            error("LongPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWordPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD_PTR *)>::value)
            error("LongPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWordPtr((-0ll - 1), &out))
            error("LongPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG_PTR *)>::value)
            error("LongPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongPtr((-0ll - 1), &out))
            error("LongPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ INT_PTR *)>::value)
            error("LongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("LongPtrToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("LongPtrToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT *) __attribute__ ((unused)) = &PtrdiffTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT *)>::value)
            error("PtrdiffTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0xffffffff, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt(0x100000000, &out))
            error("PtrdiffTToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt((-0ll - 1), &out))
            error("PtrdiffTToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG *) __attribute__ ((unused)) = &PtrdiffTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULong), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG *)>::value)
            error("PtrdiffTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0, &out) != 0)
            error("PtrdiffTToULong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0xffffffff, &out) != 0)
            error("PtrdiffTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong(0x100000000, &out))
            error("PtrdiffTToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong((-0ll - 1), &out))
            error("PtrdiffTToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD *) __attribute__ ((unused)) = &PtrdiffTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWord), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD *)>::value)
            error("PtrdiffTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0xffffffff, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord(0x100000000, &out))
            error("PtrdiffTToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord((-0ll - 1), &out))
            error("PtrdiffTToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ INT *) __attribute__ ((unused)) = &PtrdiffTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ INT *)>::value)
            error("PtrdiffTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0, &out) != 0)
            error("PtrdiffTToInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToInt(0x80000000, &out))
            error("PtrdiffTToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToInt((-0x80000000ll - 1), &out))
            error("PtrdiffTToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_PtrdiffTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ LONG *) __attribute__ ((unused)) = &PtrdiffTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToLong), HRESULT (*)(_In_ ptrdiff_t, _Out_ LONG *)>::value)
            error("PtrdiffTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0, &out) != 0)
            error("PtrdiffTToLong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0x7fffffff, &out) != 0)
            error("PtrdiffTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToLong(0x80000000, &out))
            error("PtrdiffTToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToLong((-0x80000000ll - 1), &out))
            error("PtrdiffTToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_PtrdiffTToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT_PTR *) __attribute__ ((unused)) = &PtrdiffTToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUIntPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT_PTR *)>::value)
            error("PtrdiffTToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUIntPtr((-0ll - 1), &out))
            error("PtrdiffTToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ size_t *) __attribute__ ((unused)) = &PtrdiffTToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToSizeT), HRESULT (*)(_In_ ptrdiff_t, _Out_ size_t *)>::value)
            error("PtrdiffTToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0");
        if(out != 0)
            error("PtrdiffTToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToSizeT((-0ll - 1), &out))
            error("PtrdiffTToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &PtrdiffTToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWordPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD_PTR *)>::value)
            error("PtrdiffTToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWordPtr((-0ll - 1), &out))
            error("PtrdiffTToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &PtrdiffTToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULongPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG_PTR *)>::value)
            error("PtrdiffTToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULongPtr((-0ll - 1), &out))
            error("PtrdiffTToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT *) __attribute__ ((unused)) = &SSIZETToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUInt), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT *)>::value)
            error("SSIZETToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0, &out) != 0)
            error("SSIZETToUInt failed to convert 0");
        if(out != 0)
            error("SSIZETToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0xffffffff, &out) != 0)
            error("SSIZETToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt(0x100000000, &out))
            error("SSIZETToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt((-0ll - 1), &out))
            error("SSIZETToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG *) __attribute__ ((unused)) = &SSIZETToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULong), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG *)>::value)
            error("SSIZETToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0, &out) != 0)
            error("SSIZETToULong failed to convert 0");
        if(out != 0)
            error("SSIZETToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0xffffffff, &out) != 0)
            error("SSIZETToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong(0x100000000, &out))
            error("SSIZETToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong((-0ll - 1), &out))
            error("SSIZETToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD *) __attribute__ ((unused)) = &SSIZETToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWord), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD *)>::value)
            error("SSIZETToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0, &out) != 0)
            error("SSIZETToDWord failed to convert 0");
        if(out != 0)
            error("SSIZETToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0xffffffff, &out) != 0)
            error("SSIZETToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord(0x100000000, &out))
            error("SSIZETToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord((-0ll - 1), &out))
            error("SSIZETToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT *) __attribute__ ((unused)) = &SSIZETToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToInt), HRESULT (*)(_In_ SSIZE_T, _Out_ INT *)>::value)
            error("SSIZETToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0, &out) != 0)
            error("SSIZETToInt failed to convert 0");
        if(out != 0)
            error("SSIZETToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0x7fffffff, &out) != 0)
            error("SSIZETToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToInt(0x80000000, &out))
            error("SSIZETToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToInt((-0x80000000ll - 1), &out))
            error("SSIZETToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_SSIZETToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ LONG *) __attribute__ ((unused)) = &SSIZETToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToLong), HRESULT (*)(_In_ SSIZE_T, _Out_ LONG *)>::value)
            error("SSIZETToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0, &out) != 0)
            error("SSIZETToLong failed to convert 0");
        if(out != 0)
            error("SSIZETToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0x7fffffff, &out) != 0)
            error("SSIZETToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToLong(0x80000000, &out))
            error("SSIZETToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToLong((-0x80000000ll - 1), &out))
            error("SSIZETToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_SSIZETToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT_PTR *) __attribute__ ((unused)) = &SSIZETToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT_PTR *)>::value)
            error("SSIZETToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUIntPtr((-0ll - 1), &out))
            error("SSIZETToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ size_t *) __attribute__ ((unused)) = &SSIZETToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToSizeT), HRESULT (*)(_In_ SSIZE_T, _Out_ size_t *)>::value)
            error("SSIZETToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0, &out) != 0)
            error("SSIZETToSizeT failed to convert 0");
        if(out != 0)
            error("SSIZETToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToSizeT((-0ll - 1), &out))
            error("SSIZETToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &SSIZETToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWordPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD_PTR *)>::value)
            error("SSIZETToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWordPtr((-0ll - 1), &out))
            error("SSIZETToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &SSIZETToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULongPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG_PTR *)>::value)
            error("SSIZETToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULongPtr((-0ll - 1), &out))
            error("SSIZETToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT_PTR *) __attribute__ ((unused)) = &SSIZETToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ INT_PTR *)>::value)
            error("SSIZETToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("SSIZETToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("SSIZETToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void tests_conversions()
{
    test_UShortToUChar();
    test_UShortToByte();
    test_UShortToChar();
    test_UShortToShort();
    test_WordToUChar();
    test_WordToByte();
    test_WordToChar();
    test_WordToShort();
    test_ShortToUChar();
    test_ShortToByte();
    test_ShortToChar();
    test_ShortToUShort();
    test_ShortToWord();
    test_UIntToUChar();
    test_UIntToByte();
    test_UIntToChar();
    test_UIntToUShort();
    test_UIntToWord();
    test_UIntToShort();
    test_UIntToInt();
    test_UIntToLong();
    test_UIntToIntPtr();
    test_UIntToLongPtr();
    test_UIntToPtrdiffT();
    test_UIntToSSIZET();
    test_ULongToUChar();
    test_ULongToByte();
    test_ULongToChar();
    test_ULongToUShort();
    test_ULongToWord();
    test_ULongToShort();
    test_ULongToUInt();
    test_ULongToInt();
    test_ULongToLong();
    test_ULongToUIntPtr();
    test_ULongToIntPtr();
    test_ULongToLongPtr();
    test_ULongToPtrdiffT();
    test_ULongToSSIZET();
    test_DWordToUChar();
    test_DWordToByte();
    test_DWordToChar();
    test_DWordToUShort();
    test_DWordToWord();
    test_DWordToShort();
    test_DWordToUInt();
    test_DWordToInt();
    test_DWordToLong();
    test_DWordToUIntPtr();
    test_DWordToIntPtr();
    test_DWordToLongPtr();
    test_DWordToPtrdiffT();
    test_DWordToSSIZET();
    test_IntToUChar();
    test_IntToByte();
    test_IntToChar();
    test_IntToUShort();
    test_IntToWord();
    test_IntToShort();
    test_IntToUInt();
    test_IntToULong();
    test_IntToDWord();
    test_IntToULongLong();
    test_IntToUIntPtr();
    test_IntToSizeT();
    test_IntToDWordPtr();
    test_IntToULongPtr();
    test_LongToUChar();
    test_LongToByte();
    test_LongToChar();
    test_LongToUShort();
    test_LongToWord();
    test_LongToShort();
    test_LongToUInt();
    test_LongToULong();
    test_LongToDWord();
    test_LongToInt();
    test_LongToULongLong();
    test_LongToUIntPtr();
    test_LongToSizeT();
    test_LongToDWordPtr();
    test_LongToULongPtr();
    test_LongToIntPtr();
    test_LongToPtrdiffT();
    test_ULongLongToUInt();
    test_ULongLongToULong();
    test_ULongLongToDWord();
    test_ULongLongToInt();
    test_ULongLongToLong();
    test_ULongLongToInt64();
    test_ULongLongToUIntPtr();
    test_ULongLongToSizeT();
    test_ULongLongToDWordPtr();
    test_ULongLongToULongPtr();
    test_ULongLongToIntPtr();
    test_ULongLongToLongPtr();
    test_ULongLongToPtrdiffT();
    test_ULongLongToSSIZET();
    test_Int64ToUInt();
    test_Int64ToULong();
    test_Int64ToDWord();
    test_Int64ToInt();
    test_Int64ToLong();
    test_Int64ToULongLong();
    test_Int64ToUIntPtr();
    test_Int64ToSizeT();
    test_Int64ToDWordPtr();
    test_Int64ToULongPtr();
    test_Int64ToIntPtr();
    test_Int64ToLongPtr();
    test_Int64ToPtrdiffT();
    test_Int64ToSSIZET();
    test_UIntPtrToUInt();
    test_UIntPtrToULong();
    test_UIntPtrToDWord();
    test_UIntPtrToInt();
    test_UIntPtrToLong();
    test_UIntPtrToInt64();
    test_UIntPtrToIntPtr();
    test_UIntPtrToLongPtr();
    test_UIntPtrToSSIZET();
    test_SizeTToUInt();
    test_SizeTToULong();
    test_SizeTToDWord();
    test_SizeTToInt();
    test_SizeTToLong();
    test_SizeTToInt64();
    test_SizeTToIntPtr();
    test_SizeTToLongPtr();
    test_SizeTToPtrdiffT();
    test_SizeTToSSIZET();
    test_DWordPtrToUInt();
    test_DWordPtrToULong();
    test_DWordPtrToDWord();
    test_DWordPtrToInt();
    test_DWordPtrToLong();
    test_DWordPtrToInt64();
    test_DWordPtrToUIntPtr();
    test_DWordPtrToIntPtr();
    test_DWordPtrToLongPtr();
    test_DWordPtrToPtrdiffT();
    test_DWordPtrToSSIZET();
    test_ULongPtrToUInt();
    test_ULongPtrToULong();
    test_ULongPtrToDWord();
    test_ULongPtrToInt();
    test_ULongPtrToLong();
    test_ULongPtrToInt64();
    test_ULongPtrToUIntPtr();
    test_ULongPtrToIntPtr();
    test_ULongPtrToLongPtr();
    test_ULongPtrToPtrdiffT();
    test_ULongPtrToSSIZET();
    test_IntPtrToUInt();
    test_IntPtrToULong();
    test_IntPtrToDWord();
    test_IntPtrToInt();
    test_IntPtrToLong();
    test_IntPtrToULongLong();
    test_IntPtrToUIntPtr();
    test_IntPtrToSizeT();
    test_IntPtrToDWordPtr();
    test_IntPtrToULongPtr();
    test_LongPtrToUInt();
    test_LongPtrToULong();
    test_LongPtrToDWord();
    test_LongPtrToInt();
    test_LongPtrToLong();
    test_LongPtrToULongLong();
    test_LongPtrToUIntPtr();
    test_LongPtrToSizeT();
    test_LongPtrToDWordPtr();
    test_LongPtrToULongPtr();
    test_LongPtrToIntPtr();
    test_PtrdiffTToUInt();
    test_PtrdiffTToULong();
    test_PtrdiffTToDWord();
    test_PtrdiffTToInt();
    test_PtrdiffTToLong();
    test_PtrdiffTToUIntPtr();
    test_PtrdiffTToSizeT();
    test_PtrdiffTToDWordPtr();
    test_PtrdiffTToULongPtr();
    test_SSIZETToUInt();
    test_SSIZETToULong();
    test_SSIZETToDWord();
    test_SSIZETToInt();
    test_SSIZETToLong();
    test_SSIZETToUIntPtr();
    test_SSIZETToSizeT();
    test_SSIZETToDWordPtr();
    test_SSIZETToULongPtr();
    test_SSIZETToIntPtr();
}

static void tests_auto()
{
    tests_types();
    tests_conversions();
}

#else /* __CHAR_UNSIGNED__ */
static void test_UCHAR_eq_uint8_t()
{
    if(sizeof(UCHAR) != 1)
        error("UCHAR is actually %d bytes", (int)sizeof(UCHAR));
    UCHAR x = 0;
    if(!((UCHAR)(x - 1) > x))
        error("UCHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UCHAR>::value)
        error("UCHAR is a pointer");
    #endif
}

static void test_BYTE_eq_uint8_t()
{
    if(sizeof(BYTE) != 1)
        error("BYTE is actually %d bytes", (int)sizeof(BYTE));
    BYTE x = 0;
    if(!((BYTE)(x - 1) > x))
        error("BYTE sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<BYTE>::value)
        error("BYTE is a pointer");
    #endif
}

static void test_CHAR_eq_int8_t()
{
    if(sizeof(CHAR) != 1)
        error("CHAR is actually %d bytes", (int)sizeof(CHAR));
    CHAR x = 0;
    if(!((CHAR)(x - 1) < x))
        error("CHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<CHAR>::value)
        error("CHAR is a pointer");
    #endif
}

static void test_USHORT_eq_uint16_t()
{
    if(sizeof(USHORT) != 2)
        error("USHORT is actually %d bytes", (int)sizeof(USHORT));
    USHORT x = 0;
    if(!((USHORT)(x - 1) > x))
        error("USHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<USHORT>::value)
        error("USHORT is a pointer");
    #endif
}

static void test_WORD_eq_uint16_t()
{
    if(sizeof(WORD) != 2)
        error("WORD is actually %d bytes", (int)sizeof(WORD));
    WORD x = 0;
    if(!((WORD)(x - 1) > x))
        error("WORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<WORD>::value)
        error("WORD is a pointer");
    #endif
}

static void test_SHORT_eq_int16_t()
{
    if(sizeof(SHORT) != 2)
        error("SHORT is actually %d bytes", (int)sizeof(SHORT));
    SHORT x = 0;
    if(!((SHORT)(x - 1) < x))
        error("SHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SHORT>::value)
        error("SHORT is a pointer");
    #endif
}

static void test_UINT_eq_uint32_t()
{
    if(sizeof(UINT) != 4)
        error("UINT is actually %d bytes", (int)sizeof(UINT));
    UINT x = 0;
    if(!((UINT)(x - 1) > x))
        error("UINT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT>::value)
        error("UINT is a pointer");
    #endif
}

static void test_ULONG_eq_uint32_t()
{
    if(sizeof(ULONG) != 4)
        error("ULONG is actually %d bytes", (int)sizeof(ULONG));
    ULONG x = 0;
    if(!((ULONG)(x - 1) > x))
        error("ULONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG>::value)
        error("ULONG is a pointer");
    #endif
}

static void test_DWORD_eq_uint32_t()
{
    if(sizeof(DWORD) != 4)
        error("DWORD is actually %d bytes", (int)sizeof(DWORD));
    DWORD x = 0;
    if(!((DWORD)(x - 1) > x))
        error("DWORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD>::value)
        error("DWORD is a pointer");
    #endif
}

static void test_INT_eq_int32_t()
{
    if(sizeof(INT) != 4)
        error("INT is actually %d bytes", (int)sizeof(INT));
    INT x = 0;
    if(!((INT)(x - 1) < x))
        error("INT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT>::value)
        error("INT is a pointer");
    #endif
}

static void test_LONG_eq_int32_t()
{
    if(sizeof(LONG) != 4)
        error("LONG is actually %d bytes", (int)sizeof(LONG));
    LONG x = 0;
    if(!((LONG)(x - 1) < x))
        error("LONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG>::value)
        error("LONG is a pointer");
    #endif
}

static void test_ULONGLONG_eq_uint64_t()
{
    if(sizeof(ULONGLONG) != 8)
        error("ULONGLONG is actually %d bytes", (int)sizeof(ULONGLONG));
    ULONGLONG x = 0;
    if(!((ULONGLONG)(x - 1) > x))
        error("ULONGLONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONGLONG>::value)
        error("ULONGLONG is a pointer");
    #endif
}

static void test_INT64_eq_int64_t()
{
    if(sizeof(INT64) != 8)
        error("INT64 is actually %d bytes", (int)sizeof(INT64));
    INT64 x = 0;
    if(!((INT64)(x - 1) < x))
        error("INT64 sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT64>::value)
        error("INT64 is a pointer");
    #endif
}

static void test_UINT_PTR_eq_uint64_t()
{
    if(sizeof(UINT_PTR) != 8)
        error("UINT_PTR is actually %d bytes", (int)sizeof(UINT_PTR));
    UINT_PTR x = 0;
    if(!((UINT_PTR)(x - 1) > x))
        error("UINT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT_PTR>::value)
        error("UINT_PTR is a pointer");
    #endif
}

static void test_size_t_eq_uint64_t()
{
    if(sizeof(size_t) != 8)
        error("size_t is actually %d bytes", (int)sizeof(size_t));
    size_t x = 0;
    if(!((size_t)(x - 1) > x))
        error("size_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<size_t>::value)
        error("size_t is a pointer");
    #endif
}

static void test_DWORD_PTR_eq_uint64_t()
{
    if(sizeof(DWORD_PTR) != 8)
        error("DWORD_PTR is actually %d bytes", (int)sizeof(DWORD_PTR));
    DWORD_PTR x = 0;
    if(!((DWORD_PTR)(x - 1) > x))
        error("DWORD_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD_PTR>::value)
        error("DWORD_PTR is a pointer");
    #endif
}

static void test_ULONG_PTR_eq_uint64_t()
{
    if(sizeof(ULONG_PTR) != 8)
        error("ULONG_PTR is actually %d bytes", (int)sizeof(ULONG_PTR));
    ULONG_PTR x = 0;
    if(!((ULONG_PTR)(x - 1) > x))
        error("ULONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG_PTR>::value)
        error("ULONG_PTR is a pointer");
    #endif
}

static void test_INT_PTR_eq_int64_t()
{
    if(sizeof(INT_PTR) != 8)
        error("INT_PTR is actually %d bytes", (int)sizeof(INT_PTR));
    INT_PTR x = 0;
    if(!((INT_PTR)(x - 1) < x))
        error("INT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT_PTR>::value)
        error("INT_PTR is a pointer");
    #endif
}

static void test_LONG_PTR_eq_int64_t()
{
    if(sizeof(LONG_PTR) != 8)
        error("LONG_PTR is actually %d bytes", (int)sizeof(LONG_PTR));
    LONG_PTR x = 0;
    if(!((LONG_PTR)(x - 1) < x))
        error("LONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG_PTR>::value)
        error("LONG_PTR is a pointer");
    #endif
}

static void test_ptrdiff_t_eq_int64_t()
{
    if(sizeof(ptrdiff_t) != 8)
        error("ptrdiff_t is actually %d bytes", (int)sizeof(ptrdiff_t));
    ptrdiff_t x = 0;
    if(!((ptrdiff_t)(x - 1) < x))
        error("ptrdiff_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ptrdiff_t>::value)
        error("ptrdiff_t is a pointer");
    #endif
}

static void test_SSIZE_T_eq_int64_t()
{
    if(sizeof(SSIZE_T) != 8)
        error("SSIZE_T is actually %d bytes", (int)sizeof(SSIZE_T));
    SSIZE_T x = 0;
    if(!((SSIZE_T)(x - 1) < x))
        error("SSIZE_T sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SSIZE_T>::value)
        error("SSIZE_T is a pointer");
    #endif
}

static void tests_types()
{
    test_UCHAR_eq_uint8_t();
    test_BYTE_eq_uint8_t();
    test_CHAR_eq_int8_t();
    test_USHORT_eq_uint16_t();
    test_WORD_eq_uint16_t();
    test_SHORT_eq_int16_t();
    test_UINT_eq_uint32_t();
    test_ULONG_eq_uint32_t();
    test_DWORD_eq_uint32_t();
    test_INT_eq_int32_t();
    test_LONG_eq_int32_t();
    test_ULONGLONG_eq_uint64_t();
    test_INT64_eq_int64_t();
    test_UINT_PTR_eq_uint64_t();
    test_size_t_eq_uint64_t();
    test_DWORD_PTR_eq_uint64_t();
    test_ULONG_PTR_eq_uint64_t();
    test_INT_PTR_eq_int64_t();
    test_LONG_PTR_eq_int64_t();
    test_ptrdiff_t_eq_int64_t();
    test_SSIZE_T_eq_int64_t();
}

static void test_UShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &UShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToUChar), HRESULT (*)(_In_ USHORT, _Out_ UCHAR *)>::value)
            error("UShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0, &out) != 0)
            error("UShortToUChar failed to convert 0");
        if(out != 0)
            error("UShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0xff, &out) != 0)
            error("UShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToUChar(0x100, &out))
            error("UShortToUChar did not overflow when given 0x100");
    }

}

static void test_UShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ BYTE *) __attribute__ ((unused)) = &UShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToByte), HRESULT (*)(_In_ USHORT, _Out_ BYTE *)>::value)
            error("UShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0, &out) != 0)
            error("UShortToByte failed to convert 0");
        if(out != 0)
            error("UShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0xff, &out) != 0)
            error("UShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("UShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToByte(0x100, &out))
            error("UShortToByte did not overflow when given 0x100");
    }

}

static void test_UShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ CHAR *) __attribute__ ((unused)) = &UShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToChar), HRESULT (*)(_In_ USHORT, _Out_ CHAR *)>::value)
            error("UShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0, &out) != 0)
            error("UShortToChar failed to convert 0");
        if(out != 0)
            error("UShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0x7f, &out) != 0)
            error("UShortToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("UShortToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToChar(0x80, &out))
            error("UShortToChar did not overflow when given 0x80");
    }

}

static void test_UShortToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ SHORT *) __attribute__ ((unused)) = &UShortToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToShort), HRESULT (*)(_In_ USHORT, _Out_ SHORT *)>::value)
            error("UShortToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0, &out) != 0)
            error("UShortToShort failed to convert 0");
        if(out != 0)
            error("UShortToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0x7fff, &out) != 0)
            error("UShortToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UShortToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToShort(0x8000, &out))
            error("UShortToShort did not overflow when given 0x8000");
    }

}

static void test_WordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ UCHAR *) __attribute__ ((unused)) = &WordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToUChar), HRESULT (*)(_In_ WORD, _Out_ UCHAR *)>::value)
            error("WordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0, &out) != 0)
            error("WordToUChar failed to convert 0");
        if(out != 0)
            error("WordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0xff, &out) != 0)
            error("WordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToUChar(0x100, &out))
            error("WordToUChar did not overflow when given 0x100");
    }

}

static void test_WordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ BYTE *) __attribute__ ((unused)) = &WordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToByte), HRESULT (*)(_In_ WORD, _Out_ BYTE *)>::value)
            error("WordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToByte(0, &out) != 0)
            error("WordToByte failed to convert 0");
        if(out != 0)
            error("WordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToByte(0xff, &out) != 0)
            error("WordToByte failed to convert 0xff");
        if(out != 0xff)
            error("WordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToByte(0x100, &out))
            error("WordToByte did not overflow when given 0x100");
    }

}

static void test_WordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ CHAR *) __attribute__ ((unused)) = &WordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToChar), HRESULT (*)(_In_ WORD, _Out_ CHAR *)>::value)
            error("WordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToChar(0, &out) != 0)
            error("WordToChar failed to convert 0");
        if(out != 0)
            error("WordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToChar(0x7f, &out) != 0)
            error("WordToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("WordToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToChar(0x80, &out))
            error("WordToChar did not overflow when given 0x80");
    }

}

static void test_WordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ SHORT *) __attribute__ ((unused)) = &WordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToShort), HRESULT (*)(_In_ WORD, _Out_ SHORT *)>::value)
            error("WordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToShort(0, &out) != 0)
            error("WordToShort failed to convert 0");
        if(out != 0)
            error("WordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToShort(0x7fff, &out) != 0)
            error("WordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("WordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToShort(0x8000, &out))
            error("WordToShort did not overflow when given 0x8000");
    }

}

static void test_ShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &ShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUChar), HRESULT (*)(_In_ SHORT, _Out_ UCHAR *)>::value)
            error("ShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0, &out) != 0)
            error("ShortToUChar failed to convert 0");
        if(out != 0)
            error("ShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0xff, &out) != 0)
            error("ShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar(0x100, &out))
            error("ShortToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar((-0ll - 1), &out))
            error("ShortToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ BYTE *) __attribute__ ((unused)) = &ShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToByte), HRESULT (*)(_In_ SHORT, _Out_ BYTE *)>::value)
            error("ShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0, &out) != 0)
            error("ShortToByte failed to convert 0");
        if(out != 0)
            error("ShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0xff, &out) != 0)
            error("ShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("ShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte(0x100, &out))
            error("ShortToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte((-0ll - 1), &out))
            error("ShortToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ CHAR *) __attribute__ ((unused)) = &ShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToChar), HRESULT (*)(_In_ SHORT, _Out_ CHAR *)>::value)
            error("ShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0, &out) != 0)
            error("ShortToChar failed to convert 0");
        if(out != 0)
            error("ShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0x7f, &out) != 0)
            error("ShortToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("ShortToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar((-0x7fll - 1), &out) != 0)
            error("ShortToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("ShortToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar(0x80, &out))
            error("ShortToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar((-0x80ll - 1), &out))
            error("ShortToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_ShortToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ USHORT *) __attribute__ ((unused)) = &ShortToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUShort), HRESULT (*)(_In_ SHORT, _Out_ USHORT *)>::value)
            error("ShortToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0, &out) != 0)
            error("ShortToUShort failed to convert 0");
        if(out != 0)
            error("ShortToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0x7fff, &out) != 0)
            error("ShortToUShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToUShort changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUShort((-0ll - 1), &out))
            error("ShortToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ WORD *) __attribute__ ((unused)) = &ShortToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToWord), HRESULT (*)(_In_ SHORT, _Out_ WORD *)>::value)
            error("ShortToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0, &out) != 0)
            error("ShortToWord failed to convert 0");
        if(out != 0)
            error("ShortToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0x7fff, &out) != 0)
            error("ShortToWord failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToWord changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToWord((-0ll - 1), &out))
            error("ShortToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_UIntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ UCHAR *) __attribute__ ((unused)) = &UIntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUChar), HRESULT (*)(_In_ UINT, _Out_ UCHAR *)>::value)
            error("UIntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0, &out) != 0)
            error("UIntToUChar failed to convert 0");
        if(out != 0)
            error("UIntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0xff, &out) != 0)
            error("UIntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUChar(0x100, &out))
            error("UIntToUChar did not overflow when given 0x100");
    }

}

static void test_UIntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ BYTE *) __attribute__ ((unused)) = &UIntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToByte), HRESULT (*)(_In_ UINT, _Out_ BYTE *)>::value)
            error("UIntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0, &out) != 0)
            error("UIntToByte failed to convert 0");
        if(out != 0)
            error("UIntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0xff, &out) != 0)
            error("UIntToByte failed to convert 0xff");
        if(out != 0xff)
            error("UIntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToByte(0x100, &out))
            error("UIntToByte did not overflow when given 0x100");
    }

}

static void test_UIntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ CHAR *) __attribute__ ((unused)) = &UIntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToChar), HRESULT (*)(_In_ UINT, _Out_ CHAR *)>::value)
            error("UIntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0, &out) != 0)
            error("UIntToChar failed to convert 0");
        if(out != 0)
            error("UIntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0x7f, &out) != 0)
            error("UIntToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("UIntToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToChar(0x80, &out))
            error("UIntToChar did not overflow when given 0x80");
    }

}

static void test_UIntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ USHORT *) __attribute__ ((unused)) = &UIntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUShort), HRESULT (*)(_In_ UINT, _Out_ USHORT *)>::value)
            error("UIntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0, &out) != 0)
            error("UIntToUShort failed to convert 0");
        if(out != 0)
            error("UIntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0xffff, &out) != 0)
            error("UIntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUShort(0x10000, &out))
            error("UIntToUShort did not overflow when given 0x10000");
    }

}

static void test_UIntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ WORD *) __attribute__ ((unused)) = &UIntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToWord), HRESULT (*)(_In_ UINT, _Out_ WORD *)>::value)
            error("UIntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0, &out) != 0)
            error("UIntToWord failed to convert 0");
        if(out != 0)
            error("UIntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0xffff, &out) != 0)
            error("UIntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToWord(0x10000, &out))
            error("UIntToWord did not overflow when given 0x10000");
    }

}

static void test_UIntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SHORT *) __attribute__ ((unused)) = &UIntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToShort), HRESULT (*)(_In_ UINT, _Out_ SHORT *)>::value)
            error("UIntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0, &out) != 0)
            error("UIntToShort failed to convert 0");
        if(out != 0)
            error("UIntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0x7fff, &out) != 0)
            error("UIntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UIntToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToShort(0x8000, &out))
            error("UIntToShort did not overflow when given 0x8000");
    }

}

static void test_UIntToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT *) __attribute__ ((unused)) = &UIntToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToInt), HRESULT (*)(_In_ UINT, _Out_ INT *)>::value)
            error("UIntToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0, &out) != 0)
            error("UIntToInt failed to convert 0");
        if(out != 0)
            error("UIntToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0x7fffffff, &out) != 0)
            error("UIntToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToInt(0x80000000, &out))
            error("UIntToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG *) __attribute__ ((unused)) = &UIntToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLong), HRESULT (*)(_In_ UINT, _Out_ LONG *)>::value)
            error("UIntToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0, &out) != 0)
            error("UIntToLong failed to convert 0");
        if(out != 0)
            error("UIntToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0x7fffffff, &out) != 0)
            error("UIntToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLong(0x80000000, &out))
            error("UIntToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToIntPtr), HRESULT (*)(_In_ UINT, _Out_ INT_PTR *)>::value)
            error("UIntToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0, &out) != 0)
            error("UIntToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0xffffffff, &out) != 0)
            error("UIntToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_UIntToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLongPtr), HRESULT (*)(_In_ UINT, _Out_ LONG_PTR *)>::value)
            error("UIntToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0, &out) != 0)
            error("UIntToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0xffffffff, &out) != 0)
            error("UIntToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_UIntToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &UIntToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToPtrdiffT), HRESULT (*)(_In_ UINT, _Out_ ptrdiff_t *)>::value)
            error("UIntToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0");
        if(out != 0)
            error("UIntToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0xffffffff, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_UIntToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToSSIZET), HRESULT (*)(_In_ UINT, _Out_ SSIZE_T *)>::value)
            error("UIntToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0, &out) != 0)
            error("UIntToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0xffffffff, &out) != 0)
            error("UIntToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_ULongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UCHAR *) __attribute__ ((unused)) = &ULongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUChar), HRESULT (*)(_In_ ULONG, _Out_ UCHAR *)>::value)
            error("ULongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0, &out) != 0)
            error("ULongToUChar failed to convert 0");
        if(out != 0)
            error("ULongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0xff, &out) != 0)
            error("ULongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUChar(0x100, &out))
            error("ULongToUChar did not overflow when given 0x100");
    }

}

static void test_ULongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ BYTE *) __attribute__ ((unused)) = &ULongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToByte), HRESULT (*)(_In_ ULONG, _Out_ BYTE *)>::value)
            error("ULongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0, &out) != 0)
            error("ULongToByte failed to convert 0");
        if(out != 0)
            error("ULongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0xff, &out) != 0)
            error("ULongToByte failed to convert 0xff");
        if(out != 0xff)
            error("ULongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToByte(0x100, &out))
            error("ULongToByte did not overflow when given 0x100");
    }

}

static void test_ULongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ CHAR *) __attribute__ ((unused)) = &ULongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToChar), HRESULT (*)(_In_ ULONG, _Out_ CHAR *)>::value)
            error("ULongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0, &out) != 0)
            error("ULongToChar failed to convert 0");
        if(out != 0)
            error("ULongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0x7f, &out) != 0)
            error("ULongToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("ULongToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToChar(0x80, &out))
            error("ULongToChar did not overflow when given 0x80");
    }

}

static void test_ULongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ USHORT *) __attribute__ ((unused)) = &ULongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUShort), HRESULT (*)(_In_ ULONG, _Out_ USHORT *)>::value)
            error("ULongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0, &out) != 0)
            error("ULongToUShort failed to convert 0");
        if(out != 0)
            error("ULongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0xffff, &out) != 0)
            error("ULongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUShort(0x10000, &out))
            error("ULongToUShort did not overflow when given 0x10000");
    }

}

static void test_ULongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ WORD *) __attribute__ ((unused)) = &ULongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToWord), HRESULT (*)(_In_ ULONG, _Out_ WORD *)>::value)
            error("ULongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0, &out) != 0)
            error("ULongToWord failed to convert 0");
        if(out != 0)
            error("ULongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0xffff, &out) != 0)
            error("ULongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToWord(0x10000, &out))
            error("ULongToWord did not overflow when given 0x10000");
    }

}

static void test_ULongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SHORT *) __attribute__ ((unused)) = &ULongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToShort), HRESULT (*)(_In_ ULONG, _Out_ SHORT *)>::value)
            error("ULongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0, &out) != 0)
            error("ULongToShort failed to convert 0");
        if(out != 0)
            error("ULongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0x7fff, &out) != 0)
            error("ULongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ULongToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToShort(0x8000, &out))
            error("ULongToShort did not overflow when given 0x8000");
    }

}

static void test_ULongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUInt), HRESULT (*)(_In_ ULONG, _Out_ UINT *)>::value)
            error("ULongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0, &out) != 0)
            error("ULongToUInt failed to convert 0");
        if(out != 0)
            error("ULongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0xffffffff, &out) != 0)
            error("ULongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT *) __attribute__ ((unused)) = &ULongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToInt), HRESULT (*)(_In_ ULONG, _Out_ INT *)>::value)
            error("ULongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0, &out) != 0)
            error("ULongToInt failed to convert 0");
        if(out != 0)
            error("ULongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0x7fffffff, &out) != 0)
            error("ULongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToInt(0x80000000, &out))
            error("ULongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLong), HRESULT (*)(_In_ ULONG, _Out_ LONG *)>::value)
            error("ULongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0, &out) != 0)
            error("ULongToLong failed to convert 0");
        if(out != 0)
            error("ULongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0x7fffffff, &out) != 0)
            error("ULongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLong(0x80000000, &out))
            error("ULongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUIntPtr), HRESULT (*)(_In_ ULONG, _Out_ UINT_PTR *)>::value)
            error("ULongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0, &out) != 0)
            error("ULongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToIntPtr), HRESULT (*)(_In_ ULONG, _Out_ INT_PTR *)>::value)
            error("ULongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0, &out) != 0)
            error("ULongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0xffffffff, &out) != 0)
            error("ULongToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLongPtr), HRESULT (*)(_In_ ULONG, _Out_ LONG_PTR *)>::value)
            error("ULongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0, &out) != 0)
            error("ULongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0xffffffff, &out) != 0)
            error("ULongToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToPtrdiffT), HRESULT (*)(_In_ ULONG, _Out_ ptrdiff_t *)>::value)
            error("ULongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0xffffffff, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_ULongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToSSIZET), HRESULT (*)(_In_ ULONG, _Out_ SSIZE_T *)>::value)
            error("ULongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0, &out) != 0)
            error("ULongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0xffffffff, &out) != 0)
            error("ULongToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_DWordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UCHAR *) __attribute__ ((unused)) = &DWordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUChar), HRESULT (*)(_In_ DWORD, _Out_ UCHAR *)>::value)
            error("DWordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0, &out) != 0)
            error("DWordToUChar failed to convert 0");
        if(out != 0)
            error("DWordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0xff, &out) != 0)
            error("DWordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUChar(0x100, &out))
            error("DWordToUChar did not overflow when given 0x100");
    }

}

static void test_DWordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ BYTE *) __attribute__ ((unused)) = &DWordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToByte), HRESULT (*)(_In_ DWORD, _Out_ BYTE *)>::value)
            error("DWordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0, &out) != 0)
            error("DWordToByte failed to convert 0");
        if(out != 0)
            error("DWordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0xff, &out) != 0)
            error("DWordToByte failed to convert 0xff");
        if(out != 0xff)
            error("DWordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToByte(0x100, &out))
            error("DWordToByte did not overflow when given 0x100");
    }

}

static void test_DWordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ CHAR *) __attribute__ ((unused)) = &DWordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToChar), HRESULT (*)(_In_ DWORD, _Out_ CHAR *)>::value)
            error("DWordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0, &out) != 0)
            error("DWordToChar failed to convert 0");
        if(out != 0)
            error("DWordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0x7f, &out) != 0)
            error("DWordToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("DWordToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToChar(0x80, &out))
            error("DWordToChar did not overflow when given 0x80");
    }

}

static void test_DWordToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ USHORT *) __attribute__ ((unused)) = &DWordToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUShort), HRESULT (*)(_In_ DWORD, _Out_ USHORT *)>::value)
            error("DWordToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0, &out) != 0)
            error("DWordToUShort failed to convert 0");
        if(out != 0)
            error("DWordToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0xffff, &out) != 0)
            error("DWordToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUShort(0x10000, &out))
            error("DWordToUShort did not overflow when given 0x10000");
    }

}

static void test_DWordToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ WORD *) __attribute__ ((unused)) = &DWordToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToWord), HRESULT (*)(_In_ DWORD, _Out_ WORD *)>::value)
            error("DWordToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0, &out) != 0)
            error("DWordToWord failed to convert 0");
        if(out != 0)
            error("DWordToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0xffff, &out) != 0)
            error("DWordToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToWord(0x10000, &out))
            error("DWordToWord did not overflow when given 0x10000");
    }

}

static void test_DWordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SHORT *) __attribute__ ((unused)) = &DWordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToShort), HRESULT (*)(_In_ DWORD, _Out_ SHORT *)>::value)
            error("DWordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0, &out) != 0)
            error("DWordToShort failed to convert 0");
        if(out != 0)
            error("DWordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0x7fff, &out) != 0)
            error("DWordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("DWordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToShort(0x8000, &out))
            error("DWordToShort did not overflow when given 0x8000");
    }

}

static void test_DWordToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT *) __attribute__ ((unused)) = &DWordToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUInt), HRESULT (*)(_In_ DWORD, _Out_ UINT *)>::value)
            error("DWordToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0, &out) != 0)
            error("DWordToUInt failed to convert 0");
        if(out != 0)
            error("DWordToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0xffffffff, &out) != 0)
            error("DWordToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT *) __attribute__ ((unused)) = &DWordToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToInt), HRESULT (*)(_In_ DWORD, _Out_ INT *)>::value)
            error("DWordToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0, &out) != 0)
            error("DWordToInt failed to convert 0");
        if(out != 0)
            error("DWordToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0x7fffffff, &out) != 0)
            error("DWordToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToInt(0x80000000, &out))
            error("DWordToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG *) __attribute__ ((unused)) = &DWordToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLong), HRESULT (*)(_In_ DWORD, _Out_ LONG *)>::value)
            error("DWordToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0, &out) != 0)
            error("DWordToLong failed to convert 0");
        if(out != 0)
            error("DWordToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0x7fffffff, &out) != 0)
            error("DWordToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLong(0x80000000, &out))
            error("DWordToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUIntPtr), HRESULT (*)(_In_ DWORD, _Out_ UINT_PTR *)>::value)
            error("DWordToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0, &out) != 0)
            error("DWordToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0xffffffff, &out) != 0)
            error("DWordToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToIntPtr), HRESULT (*)(_In_ DWORD, _Out_ INT_PTR *)>::value)
            error("DWordToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0, &out) != 0)
            error("DWordToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0xffffffff, &out) != 0)
            error("DWordToIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLongPtr), HRESULT (*)(_In_ DWORD, _Out_ LONG_PTR *)>::value)
            error("DWordToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0, &out) != 0)
            error("DWordToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0xffffffff, &out) != 0)
            error("DWordToLongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToLongPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToPtrdiffT), HRESULT (*)(_In_ DWORD, _Out_ ptrdiff_t *)>::value)
            error("DWordToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0xffffffff, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToPtrdiffT changed 0xffffffff to something else.");
    }

}

static void test_DWordToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToSSIZET), HRESULT (*)(_In_ DWORD, _Out_ SSIZE_T *)>::value)
            error("DWordToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0, &out) != 0)
            error("DWordToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0xffffffff, &out) != 0)
            error("DWordToSSIZET failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToSSIZET changed 0xffffffff to something else.");
    }

}

static void test_IntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UCHAR *) __attribute__ ((unused)) = &IntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUChar), HRESULT (*)(_In_ INT, _Out_ UCHAR *)>::value)
            error("IntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0, &out) != 0)
            error("IntToUChar failed to convert 0");
        if(out != 0)
            error("IntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0xff, &out) != 0)
            error("IntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar(0x100, &out))
            error("IntToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar((-0ll - 1), &out))
            error("IntToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ BYTE *) __attribute__ ((unused)) = &IntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToByte), HRESULT (*)(_In_ INT, _Out_ BYTE *)>::value)
            error("IntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToByte(0, &out) != 0)
            error("IntToByte failed to convert 0");
        if(out != 0)
            error("IntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToByte(0xff, &out) != 0)
            error("IntToByte failed to convert 0xff");
        if(out != 0xff)
            error("IntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte(0x100, &out))
            error("IntToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte((-0ll - 1), &out))
            error("IntToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ CHAR *) __attribute__ ((unused)) = &IntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToChar), HRESULT (*)(_In_ INT, _Out_ CHAR *)>::value)
            error("IntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToChar(0, &out) != 0)
            error("IntToChar failed to convert 0");
        if(out != 0)
            error("IntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToChar(0x7f, &out) != 0)
            error("IntToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("IntToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToChar((-0x7fll - 1), &out) != 0)
            error("IntToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("IntToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar(0x80, &out))
            error("IntToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar((-0x80ll - 1), &out))
            error("IntToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_IntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ USHORT *) __attribute__ ((unused)) = &IntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUShort), HRESULT (*)(_In_ INT, _Out_ USHORT *)>::value)
            error("IntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0, &out) != 0)
            error("IntToUShort failed to convert 0");
        if(out != 0)
            error("IntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0xffff, &out) != 0)
            error("IntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort(0x10000, &out))
            error("IntToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort((-0ll - 1), &out))
            error("IntToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ WORD *) __attribute__ ((unused)) = &IntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToWord), HRESULT (*)(_In_ INT, _Out_ WORD *)>::value)
            error("IntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToWord(0, &out) != 0)
            error("IntToWord failed to convert 0");
        if(out != 0)
            error("IntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToWord(0xffff, &out) != 0)
            error("IntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord(0x10000, &out))
            error("IntToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord((-0ll - 1), &out))
            error("IntToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ SHORT *) __attribute__ ((unused)) = &IntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToShort), HRESULT (*)(_In_ INT, _Out_ SHORT *)>::value)
            error("IntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToShort(0, &out) != 0)
            error("IntToShort failed to convert 0");
        if(out != 0)
            error("IntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToShort(0x7fff, &out) != 0)
            error("IntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("IntToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToShort((-0x7fffll - 1), &out) != 0)
            error("IntToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("IntToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort(0x8000, &out))
            error("IntToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort((-0x8000ll - 1), &out))
            error("IntToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_IntToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT *) __attribute__ ((unused)) = &IntToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUInt), HRESULT (*)(_In_ INT, _Out_ UINT *)>::value)
            error("IntToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0, &out) != 0)
            error("IntToUInt failed to convert 0");
        if(out != 0)
            error("IntToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0x7fffffff, &out) != 0)
            error("IntToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUInt((-0ll - 1), &out))
            error("IntToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG *) __attribute__ ((unused)) = &IntToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULong), HRESULT (*)(_In_ INT, _Out_ ULONG *)>::value)
            error("IntToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULong(0, &out) != 0)
            error("IntToULong failed to convert 0");
        if(out != 0)
            error("IntToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULong(0x7fffffff, &out) != 0)
            error("IntToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULong((-0ll - 1), &out))
            error("IntToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD *) __attribute__ ((unused)) = &IntToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWord), HRESULT (*)(_In_ INT, _Out_ DWORD *)>::value)
            error("IntToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0, &out) != 0)
            error("IntToDWord failed to convert 0");
        if(out != 0)
            error("IntToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0x7fffffff, &out) != 0)
            error("IntToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWord((-0ll - 1), &out))
            error("IntToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongLong), HRESULT (*)(_In_ INT, _Out_ ULONGLONG *)>::value)
            error("IntToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0, &out) != 0)
            error("IntToULongLong failed to convert 0");
        if(out != 0)
            error("IntToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0x7fffffff, &out) != 0)
            error("IntToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongLong((-0ll - 1), &out))
            error("IntToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUIntPtr), HRESULT (*)(_In_ INT, _Out_ UINT_PTR *)>::value)
            error("IntToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0, &out) != 0)
            error("IntToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0x7fffffff, &out) != 0)
            error("IntToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUIntPtr((-0ll - 1), &out))
            error("IntToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ size_t *) __attribute__ ((unused)) = &IntToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToSizeT), HRESULT (*)(_In_ INT, _Out_ size_t *)>::value)
            error("IntToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0, &out) != 0)
            error("IntToSizeT failed to convert 0");
        if(out != 0)
            error("IntToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0x7fffffff, &out) != 0)
            error("IntToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToSizeT((-0ll - 1), &out))
            error("IntToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWordPtr), HRESULT (*)(_In_ INT, _Out_ DWORD_PTR *)>::value)
            error("IntToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0, &out) != 0)
            error("IntToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0x7fffffff, &out) != 0)
            error("IntToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWordPtr((-0ll - 1), &out))
            error("IntToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongPtr), HRESULT (*)(_In_ INT, _Out_ ULONG_PTR *)>::value)
            error("IntToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0, &out) != 0)
            error("IntToULongPtr failed to convert 0");
        if(out != 0)
            error("IntToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0x7fffffff, &out) != 0)
            error("IntToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongPtr((-0ll - 1), &out))
            error("IntToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UCHAR *) __attribute__ ((unused)) = &LongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUChar), HRESULT (*)(_In_ LONG, _Out_ UCHAR *)>::value)
            error("LongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0, &out) != 0)
            error("LongToUChar failed to convert 0");
        if(out != 0)
            error("LongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0xff, &out) != 0)
            error("LongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar(0x100, &out))
            error("LongToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar((-0ll - 1), &out))
            error("LongToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ BYTE *) __attribute__ ((unused)) = &LongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToByte), HRESULT (*)(_In_ LONG, _Out_ BYTE *)>::value)
            error("LongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToByte(0, &out) != 0)
            error("LongToByte failed to convert 0");
        if(out != 0)
            error("LongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToByte(0xff, &out) != 0)
            error("LongToByte failed to convert 0xff");
        if(out != 0xff)
            error("LongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte(0x100, &out))
            error("LongToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte((-0ll - 1), &out))
            error("LongToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ CHAR *) __attribute__ ((unused)) = &LongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToChar), HRESULT (*)(_In_ LONG, _Out_ CHAR *)>::value)
            error("LongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToChar(0, &out) != 0)
            error("LongToChar failed to convert 0");
        if(out != 0)
            error("LongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToChar(0x7f, &out) != 0)
            error("LongToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("LongToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToChar((-0x7fll - 1), &out) != 0)
            error("LongToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("LongToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar(0x80, &out))
            error("LongToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar((-0x80ll - 1), &out))
            error("LongToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_LongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ USHORT *) __attribute__ ((unused)) = &LongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUShort), HRESULT (*)(_In_ LONG, _Out_ USHORT *)>::value)
            error("LongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0, &out) != 0)
            error("LongToUShort failed to convert 0");
        if(out != 0)
            error("LongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0xffff, &out) != 0)
            error("LongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort(0x10000, &out))
            error("LongToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort((-0ll - 1), &out))
            error("LongToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ WORD *) __attribute__ ((unused)) = &LongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToWord), HRESULT (*)(_In_ LONG, _Out_ WORD *)>::value)
            error("LongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToWord(0, &out) != 0)
            error("LongToWord failed to convert 0");
        if(out != 0)
            error("LongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToWord(0xffff, &out) != 0)
            error("LongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord(0x10000, &out))
            error("LongToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord((-0ll - 1), &out))
            error("LongToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ SHORT *) __attribute__ ((unused)) = &LongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToShort), HRESULT (*)(_In_ LONG, _Out_ SHORT *)>::value)
            error("LongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToShort(0, &out) != 0)
            error("LongToShort failed to convert 0");
        if(out != 0)
            error("LongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToShort(0x7fff, &out) != 0)
            error("LongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("LongToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToShort((-0x7fffll - 1), &out) != 0)
            error("LongToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("LongToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort(0x8000, &out))
            error("LongToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort((-0x8000ll - 1), &out))
            error("LongToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_LongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT *) __attribute__ ((unused)) = &LongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUInt), HRESULT (*)(_In_ LONG, _Out_ UINT *)>::value)
            error("LongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0, &out) != 0)
            error("LongToUInt failed to convert 0");
        if(out != 0)
            error("LongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0x7fffffff, &out) != 0)
            error("LongToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUInt((-0ll - 1), &out))
            error("LongToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG *) __attribute__ ((unused)) = &LongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULong), HRESULT (*)(_In_ LONG, _Out_ ULONG *)>::value)
            error("LongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULong(0, &out) != 0)
            error("LongToULong failed to convert 0");
        if(out != 0)
            error("LongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULong(0x7fffffff, &out) != 0)
            error("LongToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULong((-0ll - 1), &out))
            error("LongToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD *) __attribute__ ((unused)) = &LongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWord), HRESULT (*)(_In_ LONG, _Out_ DWORD *)>::value)
            error("LongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0, &out) != 0)
            error("LongToDWord failed to convert 0");
        if(out != 0)
            error("LongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0x7fffffff, &out) != 0)
            error("LongToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWord((-0ll - 1), &out))
            error("LongToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT *) __attribute__ ((unused)) = &LongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToInt), HRESULT (*)(_In_ LONG, _Out_ INT *)>::value)
            error("LongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToInt(0, &out) != 0)
            error("LongToInt failed to convert 0");
        if(out != 0)
            error("LongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToInt(0x7fffffff, &out) != 0)
            error("LongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongLong), HRESULT (*)(_In_ LONG, _Out_ ULONGLONG *)>::value)
            error("LongToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0, &out) != 0)
            error("LongToULongLong failed to convert 0");
        if(out != 0)
            error("LongToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0x7fffffff, &out) != 0)
            error("LongToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongLong((-0ll - 1), &out))
            error("LongToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUIntPtr), HRESULT (*)(_In_ LONG, _Out_ UINT_PTR *)>::value)
            error("LongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0, &out) != 0)
            error("LongToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0x7fffffff, &out) != 0)
            error("LongToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUIntPtr((-0ll - 1), &out))
            error("LongToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ size_t *) __attribute__ ((unused)) = &LongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToSizeT), HRESULT (*)(_In_ LONG, _Out_ size_t *)>::value)
            error("LongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0, &out) != 0)
            error("LongToSizeT failed to convert 0");
        if(out != 0)
            error("LongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0x7fffffff, &out) != 0)
            error("LongToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToSizeT((-0ll - 1), &out))
            error("LongToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWordPtr), HRESULT (*)(_In_ LONG, _Out_ DWORD_PTR *)>::value)
            error("LongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0, &out) != 0)
            error("LongToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0x7fffffff, &out) != 0)
            error("LongToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWordPtr((-0ll - 1), &out))
            error("LongToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongPtr), HRESULT (*)(_In_ LONG, _Out_ ULONG_PTR *)>::value)
            error("LongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0, &out) != 0)
            error("LongToULongPtr failed to convert 0");
        if(out != 0)
            error("LongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0x7fffffff, &out) != 0)
            error("LongToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongPtr((-0ll - 1), &out))
            error("LongToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToIntPtr), HRESULT (*)(_In_ LONG, _Out_ INT_PTR *)>::value)
            error("LongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0, &out) != 0)
            error("LongToIntPtr failed to convert 0");
        if(out != 0)
            error("LongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0x7fffffff, &out) != 0)
            error("LongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &LongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToPtrdiffT), HRESULT (*)(_In_ LONG, _Out_ ptrdiff_t *)>::value)
            error("LongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0, &out) != 0)
            error("LongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("LongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0x7fffffff, &out) != 0)
            error("LongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("LongToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_ULongLongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongLongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUInt), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT *)>::value)
            error("ULongLongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0, &out) != 0)
            error("ULongLongToUInt failed to convert 0");
        if(out != 0)
            error("ULongLongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0xffffffff, &out) != 0)
            error("ULongLongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUInt(0x100000000, &out))
            error("ULongLongToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG *) __attribute__ ((unused)) = &ULongLongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULong), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG *)>::value)
            error("ULongLongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0, &out) != 0)
            error("ULongLongToULong failed to convert 0");
        if(out != 0)
            error("ULongLongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0xffffffff, &out) != 0)
            error("ULongLongToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULong(0x100000000, &out))
            error("ULongLongToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD *) __attribute__ ((unused)) = &ULongLongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWord), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD *)>::value)
            error("ULongLongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0, &out) != 0)
            error("ULongLongToDWord failed to convert 0");
        if(out != 0)
            error("ULongLongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0xffffffff, &out) != 0)
            error("ULongLongToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWord(0x100000000, &out))
            error("ULongLongToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT *) __attribute__ ((unused)) = &ULongLongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt), HRESULT (*)(_In_ ULONGLONG, _Out_ INT *)>::value)
            error("ULongLongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0, &out) != 0)
            error("ULongLongToInt failed to convert 0");
        if(out != 0)
            error("ULongLongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0x7fffffff, &out) != 0)
            error("ULongLongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt(0x80000000, &out))
            error("ULongLongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongLongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLong), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG *)>::value)
            error("ULongLongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0, &out) != 0)
            error("ULongLongToLong failed to convert 0");
        if(out != 0)
            error("ULongLongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0x7fffffff, &out) != 0)
            error("ULongLongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLong(0x80000000, &out))
            error("ULongLongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT64 *) __attribute__ ((unused)) = &ULongLongToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt64), HRESULT (*)(_In_ ULONGLONG, _Out_ INT64 *)>::value)
            error("ULongLongToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0, &out) != 0)
            error("ULongLongToInt64 failed to convert 0");
        if(out != 0)
            error("ULongLongToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt64(0x8000000000000000, &out))
            error("ULongLongToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongLongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT_PTR *)>::value)
            error("ULongLongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ size_t *) __attribute__ ((unused)) = &ULongLongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSizeT), HRESULT (*)(_In_ ULONGLONG, _Out_ size_t *)>::value)
            error("ULongLongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0, &out) != 0)
            error("ULongLongToSizeT failed to convert 0");
        if(out != 0)
            error("ULongLongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0xffffffffffffffff, &out) != 0)
            error("ULongLongToSizeT failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToSizeT changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &ULongLongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWordPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD_PTR *)>::value)
            error("ULongLongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToDWordPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &ULongLongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG_PTR *)>::value)
            error("ULongLongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0xffffffffffffffff, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongLongToULongPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongLongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongLongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ INT_PTR *)>::value)
            error("ULongLongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToIntPtr(0x8000000000000000, &out))
            error("ULongLongToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongLongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG_PTR *)>::value)
            error("ULongLongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLongPtr(0x8000000000000000, &out))
            error("ULongLongToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongLongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToPtrdiffT), HRESULT (*)(_In_ ULONGLONG, _Out_ ptrdiff_t *)>::value)
            error("ULongLongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongLongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToPtrdiffT(0x8000000000000000, &out))
            error("ULongLongToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongLongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSSIZET), HRESULT (*)(_In_ ULONGLONG, _Out_ SSIZE_T *)>::value)
            error("ULongLongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongLongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSSIZET(0x8000000000000000, &out))
            error("ULongLongToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_Int64ToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT *) __attribute__ ((unused)) = &Int64ToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUInt), HRESULT (*)(_In_ INT64, _Out_ UINT *)>::value)
            error("Int64ToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0, &out) != 0)
            error("Int64ToUInt failed to convert 0");
        if(out != 0)
            error("Int64ToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0xffffffff, &out) != 0)
            error("Int64ToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt(0x100000000, &out))
            error("Int64ToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt((-0ll - 1), &out))
            error("Int64ToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG *) __attribute__ ((unused)) = &Int64ToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULong), HRESULT (*)(_In_ INT64, _Out_ ULONG *)>::value)
            error("Int64ToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0, &out) != 0)
            error("Int64ToULong failed to convert 0");
        if(out != 0)
            error("Int64ToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0xffffffff, &out) != 0)
            error("Int64ToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong(0x100000000, &out))
            error("Int64ToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong((-0ll - 1), &out))
            error("Int64ToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD *) __attribute__ ((unused)) = &Int64ToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWord), HRESULT (*)(_In_ INT64, _Out_ DWORD *)>::value)
            error("Int64ToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0, &out) != 0)
            error("Int64ToDWord failed to convert 0");
        if(out != 0)
            error("Int64ToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0xffffffff, &out) != 0)
            error("Int64ToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord(0x100000000, &out))
            error("Int64ToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord((-0ll - 1), &out))
            error("Int64ToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT *) __attribute__ ((unused)) = &Int64ToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToInt), HRESULT (*)(_In_ INT64, _Out_ INT *)>::value)
            error("Int64ToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0, &out) != 0)
            error("Int64ToInt failed to convert 0");
        if(out != 0)
            error("Int64ToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0x7fffffff, &out) != 0)
            error("Int64ToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt(0x80000000, &out))
            error("Int64ToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt((-0x80000000ll - 1), &out))
            error("Int64ToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG *) __attribute__ ((unused)) = &Int64ToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLong), HRESULT (*)(_In_ INT64, _Out_ LONG *)>::value)
            error("Int64ToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0, &out) != 0)
            error("Int64ToLong failed to convert 0");
        if(out != 0)
            error("Int64ToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0x7fffffff, &out) != 0)
            error("Int64ToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong(0x80000000, &out))
            error("Int64ToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong((-0x80000000ll - 1), &out))
            error("Int64ToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONGLONG *) __attribute__ ((unused)) = &Int64ToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongLong), HRESULT (*)(_In_ INT64, _Out_ ULONGLONG *)>::value)
            error("Int64ToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0, &out) != 0)
            error("Int64ToULongLong failed to convert 0");
        if(out != 0)
            error("Int64ToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongLong((-0ll - 1), &out))
            error("Int64ToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT_PTR *) __attribute__ ((unused)) = &Int64ToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUIntPtr), HRESULT (*)(_In_ INT64, _Out_ UINT_PTR *)>::value)
            error("Int64ToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr((-0ll - 1), &out))
            error("Int64ToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ size_t *) __attribute__ ((unused)) = &Int64ToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSizeT), HRESULT (*)(_In_ INT64, _Out_ size_t *)>::value)
            error("Int64ToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0, &out) != 0)
            error("Int64ToSizeT failed to convert 0");
        if(out != 0)
            error("Int64ToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0x7fffffffffffffff, &out) != 0)
            error("Int64ToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT((-0ll - 1), &out))
            error("Int64ToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &Int64ToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWordPtr), HRESULT (*)(_In_ INT64, _Out_ DWORD_PTR *)>::value)
            error("Int64ToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0");
        if(out != 0)
            error("Int64ToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr((-0ll - 1), &out))
            error("Int64ToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &Int64ToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongPtr), HRESULT (*)(_In_ INT64, _Out_ ULONG_PTR *)>::value)
            error("Int64ToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0, &out) != 0)
            error("Int64ToULongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr((-0ll - 1), &out))
            error("Int64ToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT_PTR *) __attribute__ ((unused)) = &Int64ToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToIntPtr), HRESULT (*)(_In_ INT64, _Out_ INT_PTR *)>::value)
            error("Int64ToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0, &out) != 0)
            error("Int64ToIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG_PTR *) __attribute__ ((unused)) = &Int64ToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLongPtr), HRESULT (*)(_In_ INT64, _Out_ LONG_PTR *)>::value)
            error("Int64ToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0, &out) != 0)
            error("Int64ToLongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("Int64ToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToLongPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToLongPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &Int64ToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToPtrdiffT), HRESULT (*)(_In_ INT64, _Out_ ptrdiff_t *)>::value)
            error("Int64ToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0");
        if(out != 0)
            error("Int64ToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToPtrdiffT failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToPtrdiffT changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_Int64ToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ SSIZE_T *) __attribute__ ((unused)) = &Int64ToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSSIZET), HRESULT (*)(_In_ INT64, _Out_ SSIZE_T *)>::value)
            error("Int64ToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0, &out) != 0)
            error("Int64ToSSIZET failed to convert 0");
        if(out != 0)
            error("Int64ToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("Int64ToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET((-0x7fffffffffffffffll - 1), &out) != 0)
            error("Int64ToSSIZET failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("Int64ToSSIZET changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_UIntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &UIntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToUInt), HRESULT (*)(_In_ UINT_PTR, _Out_ UINT *)>::value)
            error("UIntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0, &out) != 0)
            error("UIntPtrToUInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0xffffffff, &out) != 0)
            error("UIntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToUInt(0x100000000, &out))
            error("UIntPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &UIntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToULong), HRESULT (*)(_In_ UINT_PTR, _Out_ ULONG *)>::value)
            error("UIntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0, &out) != 0)
            error("UIntPtrToULong failed to convert 0");
        if(out != 0)
            error("UIntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0xffffffff, &out) != 0)
            error("UIntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToULong(0x100000000, &out))
            error("UIntPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &UIntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToDWord), HRESULT (*)(_In_ UINT_PTR, _Out_ DWORD *)>::value)
            error("UIntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0, &out) != 0)
            error("UIntPtrToDWord failed to convert 0");
        if(out != 0)
            error("UIntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0xffffffff, &out) != 0)
            error("UIntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToDWord(0x100000000, &out))
            error("UIntPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_UIntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT *) __attribute__ ((unused)) = &UIntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt), HRESULT (*)(_In_ UINT_PTR, _Out_ INT *)>::value)
            error("UIntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0, &out) != 0)
            error("UIntPtrToInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0x7fffffff, &out) != 0)
            error("UIntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt(0x80000000, &out))
            error("UIntPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &UIntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLong), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG *)>::value)
            error("UIntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0, &out) != 0)
            error("UIntPtrToLong failed to convert 0");
        if(out != 0)
            error("UIntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0x7fffffff, &out) != 0)
            error("UIntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLong(0x80000000, &out))
            error("UIntPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &UIntPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt64), HRESULT (*)(_In_ UINT_PTR, _Out_ INT64 *)>::value)
            error("UIntPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt64(0x8000000000000000, &out))
            error("UIntPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToIntPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ INT_PTR *)>::value)
            error("UIntPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToIntPtr(0x8000000000000000, &out))
            error("UIntPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLongPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG_PTR *)>::value)
            error("UIntPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLongPtr(0x8000000000000000, &out))
            error("UIntPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_UIntPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToSSIZET), HRESULT (*)(_In_ UINT_PTR, _Out_ SSIZE_T *)>::value)
            error("UIntPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("UIntPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToSSIZET(0x8000000000000000, &out))
            error("UIntPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ UINT *) __attribute__ ((unused)) = &SizeTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToUInt), HRESULT (*)(_In_ size_t, _Out_ UINT *)>::value)
            error("SizeTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0, &out) != 0)
            error("SizeTToUInt failed to convert 0");
        if(out != 0)
            error("SizeTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0xffffffff, &out) != 0)
            error("SizeTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToUInt(0x100000000, &out))
            error("SizeTToUInt did not overflow when given 0x100000000");
    }

}

static void test_SizeTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ULONG *) __attribute__ ((unused)) = &SizeTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToULong), HRESULT (*)(_In_ size_t, _Out_ ULONG *)>::value)
            error("SizeTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0, &out) != 0)
            error("SizeTToULong failed to convert 0");
        if(out != 0)
            error("SizeTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0xffffffff, &out) != 0)
            error("SizeTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToULong(0x100000000, &out))
            error("SizeTToULong did not overflow when given 0x100000000");
    }

}

static void test_SizeTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ DWORD *) __attribute__ ((unused)) = &SizeTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToDWord), HRESULT (*)(_In_ size_t, _Out_ DWORD *)>::value)
            error("SizeTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0, &out) != 0)
            error("SizeTToDWord failed to convert 0");
        if(out != 0)
            error("SizeTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0xffffffff, &out) != 0)
            error("SizeTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToDWord(0x100000000, &out))
            error("SizeTToDWord did not overflow when given 0x100000000");
    }

}

static void test_SizeTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT *) __attribute__ ((unused)) = &SizeTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt), HRESULT (*)(_In_ size_t, _Out_ INT *)>::value)
            error("SizeTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0, &out) != 0)
            error("SizeTToInt failed to convert 0");
        if(out != 0)
            error("SizeTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0x7fffffff, &out) != 0)
            error("SizeTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt(0x80000000, &out))
            error("SizeTToInt did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG *) __attribute__ ((unused)) = &SizeTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLong), HRESULT (*)(_In_ size_t, _Out_ LONG *)>::value)
            error("SizeTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0, &out) != 0)
            error("SizeTToLong failed to convert 0");
        if(out != 0)
            error("SizeTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0x7fffffff, &out) != 0)
            error("SizeTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLong(0x80000000, &out))
            error("SizeTToLong did not overflow when given 0x80000000");
    }

}

static void test_SizeTToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT64 *) __attribute__ ((unused)) = &SizeTToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt64), HRESULT (*)(_In_ size_t, _Out_ INT64 *)>::value)
            error("SizeTToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0, &out) != 0)
            error("SizeTToInt64 failed to convert 0");
        if(out != 0)
            error("SizeTToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0x7fffffffffffffff, &out) != 0)
            error("SizeTToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt64(0x8000000000000000, &out))
            error("SizeTToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT_PTR *) __attribute__ ((unused)) = &SizeTToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToIntPtr), HRESULT (*)(_In_ size_t, _Out_ INT_PTR *)>::value)
            error("SizeTToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0, &out) != 0)
            error("SizeTToIntPtr failed to convert 0");
        if(out != 0)
            error("SizeTToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SizeTToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToIntPtr(0x8000000000000000, &out))
            error("SizeTToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG_PTR *) __attribute__ ((unused)) = &SizeTToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLongPtr), HRESULT (*)(_In_ size_t, _Out_ LONG_PTR *)>::value)
            error("SizeTToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0, &out) != 0)
            error("SizeTToLongPtr failed to convert 0");
        if(out != 0)
            error("SizeTToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("SizeTToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLongPtr(0x8000000000000000, &out))
            error("SizeTToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &SizeTToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToPtrdiffT), HRESULT (*)(_In_ size_t, _Out_ ptrdiff_t *)>::value)
            error("SizeTToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0");
        if(out != 0)
            error("SizeTToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToPtrdiffT(0x8000000000000000, &out))
            error("SizeTToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_SizeTToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ SSIZE_T *) __attribute__ ((unused)) = &SizeTToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToSSIZET), HRESULT (*)(_In_ size_t, _Out_ SSIZE_T *)>::value)
            error("SizeTToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0, &out) != 0)
            error("SizeTToSSIZET failed to convert 0");
        if(out != 0)
            error("SizeTToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("SizeTToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SizeTToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToSSIZET(0x8000000000000000, &out))
            error("SizeTToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT *) __attribute__ ((unused)) = &DWordPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT *)>::value)
            error("DWordPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0, &out) != 0)
            error("DWordPtrToUInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0xffffffff, &out) != 0)
            error("DWordPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToUInt(0x100000000, &out))
            error("DWordPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &DWordPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToULong), HRESULT (*)(_In_ DWORD_PTR, _Out_ ULONG *)>::value)
            error("DWordPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0, &out) != 0)
            error("DWordPtrToULong failed to convert 0");
        if(out != 0)
            error("DWordPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0xffffffff, &out) != 0)
            error("DWordPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToULong(0x100000000, &out))
            error("DWordPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &DWordPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value)
            error("DWordPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0, &out) != 0)
            error("DWordPtrToDWord failed to convert 0");
        if(out != 0)
            error("DWordPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0xffffffff, &out) != 0)
            error("DWordPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToDWord(0x100000000, &out))
            error("DWordPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_DWordPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT *) __attribute__ ((unused)) = &DWordPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT *)>::value)
            error("DWordPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0, &out) != 0)
            error("DWordPtrToInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0x7fffffff, &out) != 0)
            error("DWordPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt(0x80000000, &out))
            error("DWordPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG *) __attribute__ ((unused)) = &DWordPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLong), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG *)>::value)
            error("DWordPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0, &out) != 0)
            error("DWordPtrToLong failed to convert 0");
        if(out != 0)
            error("DWordPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0x7fffffff, &out) != 0)
            error("DWordPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLong(0x80000000, &out))
            error("DWordPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &DWordPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt64), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT64 *)>::value)
            error("DWordPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt64(0x8000000000000000, &out))
            error("DWordPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT_PTR *)>::value)
            error("DWordPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("DWordPtrToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_DWordPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT_PTR *)>::value)
            error("DWordPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToIntPtr(0x8000000000000000, &out))
            error("DWordPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLongPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG_PTR *)>::value)
            error("DWordPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLongPtr(0x8000000000000000, &out))
            error("DWordPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToPtrdiffT), HRESULT (*)(_In_ DWORD_PTR, _Out_ ptrdiff_t *)>::value)
            error("DWordPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToPtrdiffT(0x8000000000000000, &out))
            error("DWordPtrToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_DWordPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToSSIZET), HRESULT (*)(_In_ DWORD_PTR, _Out_ SSIZE_T *)>::value)
            error("DWordPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("DWordPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToSSIZET(0x8000000000000000, &out))
            error("DWordPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &ULongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT *)>::value)
            error("ULongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0, &out) != 0)
            error("ULongPtrToUInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0xffffffff, &out) != 0)
            error("ULongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToUInt(0x100000000, &out))
            error("ULongPtrToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &ULongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToULong), HRESULT (*)(_In_ ULONG_PTR, _Out_ ULONG *)>::value)
            error("ULongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0, &out) != 0)
            error("ULongPtrToULong failed to convert 0");
        if(out != 0)
            error("ULongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0xffffffff, &out) != 0)
            error("ULongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToULong(0x100000000, &out))
            error("ULongPtrToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &ULongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToDWord), HRESULT (*)(_In_ ULONG_PTR, _Out_ DWORD *)>::value)
            error("ULongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0, &out) != 0)
            error("ULongPtrToDWord failed to convert 0");
        if(out != 0)
            error("ULongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0xffffffff, &out) != 0)
            error("ULongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToDWord(0x100000000, &out))
            error("ULongPtrToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &ULongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT *)>::value)
            error("ULongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0, &out) != 0)
            error("ULongPtrToInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0x7fffffff, &out) != 0)
            error("ULongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt(0x80000000, &out))
            error("ULongPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &ULongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLong), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG *)>::value)
            error("ULongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0, &out) != 0)
            error("ULongPtrToLong failed to convert 0");
        if(out != 0)
            error("ULongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0x7fffffff, &out) != 0)
            error("ULongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLong(0x80000000, &out))
            error("ULongPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &ULongPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt64), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT64 *)>::value)
            error("ULongPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt64(0x8000000000000000, &out))
            error("ULongPtrToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT_PTR *)>::value)
            error("ULongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0xffffffffffffffff, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0xffffffffffffffff");
        if(out != 0xffffffffffffffff)
            error("ULongPtrToUIntPtr changed 0xffffffffffffffff to something else.");
    }

}

static void test_ULongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT_PTR *)>::value)
            error("ULongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToIntPtr(0x8000000000000000, &out))
            error("ULongPtrToIntPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLongPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG_PTR *)>::value)
            error("ULongPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToLongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLongPtr(0x8000000000000000, &out))
            error("ULongPtrToLongPtr did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToPtrdiffT), HRESULT (*)(_In_ ULONG_PTR, _Out_ ptrdiff_t *)>::value)
            error("ULongPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToPtrdiffT changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToPtrdiffT(0x8000000000000000, &out))
            error("ULongPtrToPtrdiffT did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToSSIZET), HRESULT (*)(_In_ ULONG_PTR, _Out_ SSIZE_T *)>::value)
            error("ULongPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0x7fffffffffffffff, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongPtrToSSIZET changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToSSIZET(0x8000000000000000, &out))
            error("ULongPtrToSSIZET did not overflow when given 0x8000000000000000");
    }

}

static void test_IntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &IntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUInt), HRESULT (*)(_In_ INT_PTR, _Out_ UINT *)>::value)
            error("IntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0, &out) != 0)
            error("IntPtrToUInt failed to convert 0");
        if(out != 0)
            error("IntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0xffffffff, &out) != 0)
            error("IntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt(0x100000000, &out))
            error("IntPtrToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt((-0ll - 1), &out))
            error("IntPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &IntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG *)>::value)
            error("IntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0, &out) != 0)
            error("IntPtrToULong failed to convert 0");
        if(out != 0)
            error("IntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0xffffffff, &out) != 0)
            error("IntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong(0x100000000, &out))
            error("IntPtrToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong((-0ll - 1), &out))
            error("IntPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &IntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWord), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD *)>::value)
            error("IntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0, &out) != 0)
            error("IntPtrToDWord failed to convert 0");
        if(out != 0)
            error("IntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0xffffffff, &out) != 0)
            error("IntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("IntPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord(0x100000000, &out))
            error("IntPtrToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord((-0ll - 1), &out))
            error("IntPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ INT *) __attribute__ ((unused)) = &IntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToInt), HRESULT (*)(_In_ INT_PTR, _Out_ INT *)>::value)
            error("IntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0, &out) != 0)
            error("IntPtrToInt failed to convert 0");
        if(out != 0)
            error("IntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0x7fffffff, &out) != 0)
            error("IntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToInt(0x80000000, &out))
            error("IntPtrToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToInt((-0x80000000ll - 1), &out))
            error("IntPtrToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_IntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &IntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToLong), HRESULT (*)(_In_ INT_PTR, _Out_ LONG *)>::value)
            error("IntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0, &out) != 0)
            error("IntPtrToLong failed to convert 0");
        if(out != 0)
            error("IntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0x7fffffff, &out) != 0)
            error("IntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToLong(0x80000000, &out))
            error("IntPtrToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToLong((-0x80000000ll - 1), &out))
            error("IntPtrToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_IntPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongLong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONGLONG *)>::value)
            error("IntPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0, &out) != 0)
            error("IntPtrToULongLong failed to convert 0");
        if(out != 0)
            error("IntPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongLong((-0ll - 1), &out))
            error("IntPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUIntPtr), HRESULT (*)(_In_ INT_PTR, _Out_ UINT_PTR *)>::value)
            error("IntPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUIntPtr((-0ll - 1), &out))
            error("IntPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ size_t *) __attribute__ ((unused)) = &IntPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToSizeT), HRESULT (*)(_In_ INT_PTR, _Out_ size_t *)>::value)
            error("IntPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0, &out) != 0)
            error("IntPtrToSizeT failed to convert 0");
        if(out != 0)
            error("IntPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToSizeT((-0ll - 1), &out))
            error("IntPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWordPtr), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD_PTR *)>::value)
            error("IntPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWordPtr((-0ll - 1), &out))
            error("IntPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongPtr), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG_PTR *)>::value)
            error("IntPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("IntPtrToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongPtr((-0ll - 1), &out))
            error("IntPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &LongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUInt), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT *)>::value)
            error("LongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0, &out) != 0)
            error("LongPtrToUInt failed to convert 0");
        if(out != 0)
            error("LongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0xffffffff, &out) != 0)
            error("LongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt(0x100000000, &out))
            error("LongPtrToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt((-0ll - 1), &out))
            error("LongPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &LongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG *)>::value)
            error("LongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0, &out) != 0)
            error("LongPtrToULong failed to convert 0");
        if(out != 0)
            error("LongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0xffffffff, &out) != 0)
            error("LongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong(0x100000000, &out))
            error("LongPtrToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong((-0ll - 1), &out))
            error("LongPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &LongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWord), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD *)>::value)
            error("LongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0, &out) != 0)
            error("LongPtrToDWord failed to convert 0");
        if(out != 0)
            error("LongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0xffffffff, &out) != 0)
            error("LongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("LongPtrToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord(0x100000000, &out))
            error("LongPtrToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord((-0ll - 1), &out))
            error("LongPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &LongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToInt), HRESULT (*)(_In_ LONG_PTR, _Out_ INT *)>::value)
            error("LongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0, &out) != 0)
            error("LongPtrToInt failed to convert 0");
        if(out != 0)
            error("LongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0x7fffffff, &out) != 0)
            error("LongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToInt(0x80000000, &out))
            error("LongPtrToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToInt((-0x80000000ll - 1), &out))
            error("LongPtrToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_LongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &LongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToLong), HRESULT (*)(_In_ LONG_PTR, _Out_ LONG *)>::value)
            error("LongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0, &out) != 0)
            error("LongPtrToLong failed to convert 0");
        if(out != 0)
            error("LongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0x7fffffff, &out) != 0)
            error("LongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToLong(0x80000000, &out))
            error("LongPtrToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToLong((-0x80000000ll - 1), &out))
            error("LongPtrToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_LongPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongLong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONGLONG *)>::value)
            error("LongPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0, &out) != 0)
            error("LongPtrToULongLong failed to convert 0");
        if(out != 0)
            error("LongPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongLong((-0ll - 1), &out))
            error("LongPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT_PTR *)>::value)
            error("LongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUIntPtr((-0ll - 1), &out))
            error("LongPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ size_t *) __attribute__ ((unused)) = &LongPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToSizeT), HRESULT (*)(_In_ LONG_PTR, _Out_ size_t *)>::value)
            error("LongPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0, &out) != 0)
            error("LongPtrToSizeT failed to convert 0");
        if(out != 0)
            error("LongPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToSizeT((-0ll - 1), &out))
            error("LongPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWordPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD_PTR *)>::value)
            error("LongPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWordPtr((-0ll - 1), &out))
            error("LongPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG_PTR *)>::value)
            error("LongPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongPtr((-0ll - 1), &out))
            error("LongPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ INT_PTR *)>::value)
            error("LongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("LongPtrToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("LongPtrToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("LongPtrToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT *) __attribute__ ((unused)) = &PtrdiffTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT *)>::value)
            error("PtrdiffTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0xffffffff, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt(0x100000000, &out))
            error("PtrdiffTToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt((-0ll - 1), &out))
            error("PtrdiffTToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG *) __attribute__ ((unused)) = &PtrdiffTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULong), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG *)>::value)
            error("PtrdiffTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0, &out) != 0)
            error("PtrdiffTToULong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0xffffffff, &out) != 0)
            error("PtrdiffTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong(0x100000000, &out))
            error("PtrdiffTToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong((-0ll - 1), &out))
            error("PtrdiffTToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD *) __attribute__ ((unused)) = &PtrdiffTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWord), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD *)>::value)
            error("PtrdiffTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0xffffffff, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("PtrdiffTToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord(0x100000000, &out))
            error("PtrdiffTToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord((-0ll - 1), &out))
            error("PtrdiffTToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ INT *) __attribute__ ((unused)) = &PtrdiffTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ INT *)>::value)
            error("PtrdiffTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0, &out) != 0)
            error("PtrdiffTToInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToInt(0x80000000, &out))
            error("PtrdiffTToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToInt((-0x80000000ll - 1), &out))
            error("PtrdiffTToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_PtrdiffTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ LONG *) __attribute__ ((unused)) = &PtrdiffTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToLong), HRESULT (*)(_In_ ptrdiff_t, _Out_ LONG *)>::value)
            error("PtrdiffTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0, &out) != 0)
            error("PtrdiffTToLong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0x7fffffff, &out) != 0)
            error("PtrdiffTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToLong(0x80000000, &out))
            error("PtrdiffTToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToLong((-0x80000000ll - 1), &out))
            error("PtrdiffTToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_PtrdiffTToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT_PTR *) __attribute__ ((unused)) = &PtrdiffTToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUIntPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT_PTR *)>::value)
            error("PtrdiffTToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUIntPtr((-0ll - 1), &out))
            error("PtrdiffTToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ size_t *) __attribute__ ((unused)) = &PtrdiffTToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToSizeT), HRESULT (*)(_In_ ptrdiff_t, _Out_ size_t *)>::value)
            error("PtrdiffTToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0");
        if(out != 0)
            error("PtrdiffTToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToSizeT((-0ll - 1), &out))
            error("PtrdiffTToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &PtrdiffTToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWordPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD_PTR *)>::value)
            error("PtrdiffTToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWordPtr((-0ll - 1), &out))
            error("PtrdiffTToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &PtrdiffTToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULongPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG_PTR *)>::value)
            error("PtrdiffTToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("PtrdiffTToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULongPtr((-0ll - 1), &out))
            error("PtrdiffTToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT *) __attribute__ ((unused)) = &SSIZETToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUInt), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT *)>::value)
            error("SSIZETToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0, &out) != 0)
            error("SSIZETToUInt failed to convert 0");
        if(out != 0)
            error("SSIZETToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0xffffffff, &out) != 0)
            error("SSIZETToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt(0x100000000, &out))
            error("SSIZETToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt((-0ll - 1), &out))
            error("SSIZETToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG *) __attribute__ ((unused)) = &SSIZETToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULong), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG *)>::value)
            error("SSIZETToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0, &out) != 0)
            error("SSIZETToULong failed to convert 0");
        if(out != 0)
            error("SSIZETToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0xffffffff, &out) != 0)
            error("SSIZETToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong(0x100000000, &out))
            error("SSIZETToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong((-0ll - 1), &out))
            error("SSIZETToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD *) __attribute__ ((unused)) = &SSIZETToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWord), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD *)>::value)
            error("SSIZETToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0, &out) != 0)
            error("SSIZETToDWord failed to convert 0");
        if(out != 0)
            error("SSIZETToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0xffffffff, &out) != 0)
            error("SSIZETToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SSIZETToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord(0x100000000, &out))
            error("SSIZETToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord((-0ll - 1), &out))
            error("SSIZETToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT *) __attribute__ ((unused)) = &SSIZETToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToInt), HRESULT (*)(_In_ SSIZE_T, _Out_ INT *)>::value)
            error("SSIZETToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0, &out) != 0)
            error("SSIZETToInt failed to convert 0");
        if(out != 0)
            error("SSIZETToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0x7fffffff, &out) != 0)
            error("SSIZETToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToInt(0x80000000, &out))
            error("SSIZETToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToInt((-0x80000000ll - 1), &out))
            error("SSIZETToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_SSIZETToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ LONG *) __attribute__ ((unused)) = &SSIZETToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToLong), HRESULT (*)(_In_ SSIZE_T, _Out_ LONG *)>::value)
            error("SSIZETToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0, &out) != 0)
            error("SSIZETToLong failed to convert 0");
        if(out != 0)
            error("SSIZETToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0x7fffffff, &out) != 0)
            error("SSIZETToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToLong(0x80000000, &out))
            error("SSIZETToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToLong((-0x80000000ll - 1), &out))
            error("SSIZETToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_SSIZETToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT_PTR *) __attribute__ ((unused)) = &SSIZETToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT_PTR *)>::value)
            error("SSIZETToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToUIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUIntPtr((-0ll - 1), &out))
            error("SSIZETToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ size_t *) __attribute__ ((unused)) = &SSIZETToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToSizeT), HRESULT (*)(_In_ SSIZE_T, _Out_ size_t *)>::value)
            error("SSIZETToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0, &out) != 0)
            error("SSIZETToSizeT failed to convert 0");
        if(out != 0)
            error("SSIZETToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToSizeT failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToSizeT changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToSizeT((-0ll - 1), &out))
            error("SSIZETToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &SSIZETToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWordPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD_PTR *)>::value)
            error("SSIZETToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToDWordPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWordPtr((-0ll - 1), &out))
            error("SSIZETToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &SSIZETToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULongPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG_PTR *)>::value)
            error("SSIZETToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToULongPtr changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULongPtr((-0ll - 1), &out))
            error("SSIZETToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT_PTR *) __attribute__ ((unused)) = &SSIZETToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ INT_PTR *)>::value)
            error("SSIZETToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0x7fffffffffffffff, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("SSIZETToIntPtr changed 0x7fffffffffffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr((-0x7fffffffffffffffll - 1), &out) != 0)
            error("SSIZETToIntPtr failed to convert (-0x7fffffffffffffffll - 1)");
        if(out != (-0x7fffffffffffffffll - 1))
            error("SSIZETToIntPtr changed (-0x7fffffffffffffffll - 1) to something else.");
    }

}

static void tests_conversions()
{
    test_UShortToUChar();
    test_UShortToByte();
    test_UShortToChar();
    test_UShortToShort();
    test_WordToUChar();
    test_WordToByte();
    test_WordToChar();
    test_WordToShort();
    test_ShortToUChar();
    test_ShortToByte();
    test_ShortToChar();
    test_ShortToUShort();
    test_ShortToWord();
    test_UIntToUChar();
    test_UIntToByte();
    test_UIntToChar();
    test_UIntToUShort();
    test_UIntToWord();
    test_UIntToShort();
    test_UIntToInt();
    test_UIntToLong();
    test_UIntToIntPtr();
    test_UIntToLongPtr();
    test_UIntToPtrdiffT();
    test_UIntToSSIZET();
    test_ULongToUChar();
    test_ULongToByte();
    test_ULongToChar();
    test_ULongToUShort();
    test_ULongToWord();
    test_ULongToShort();
    test_ULongToUInt();
    test_ULongToInt();
    test_ULongToLong();
    test_ULongToUIntPtr();
    test_ULongToIntPtr();
    test_ULongToLongPtr();
    test_ULongToPtrdiffT();
    test_ULongToSSIZET();
    test_DWordToUChar();
    test_DWordToByte();
    test_DWordToChar();
    test_DWordToUShort();
    test_DWordToWord();
    test_DWordToShort();
    test_DWordToUInt();
    test_DWordToInt();
    test_DWordToLong();
    test_DWordToUIntPtr();
    test_DWordToIntPtr();
    test_DWordToLongPtr();
    test_DWordToPtrdiffT();
    test_DWordToSSIZET();
    test_IntToUChar();
    test_IntToByte();
    test_IntToChar();
    test_IntToUShort();
    test_IntToWord();
    test_IntToShort();
    test_IntToUInt();
    test_IntToULong();
    test_IntToDWord();
    test_IntToULongLong();
    test_IntToUIntPtr();
    test_IntToSizeT();
    test_IntToDWordPtr();
    test_IntToULongPtr();
    test_LongToUChar();
    test_LongToByte();
    test_LongToChar();
    test_LongToUShort();
    test_LongToWord();
    test_LongToShort();
    test_LongToUInt();
    test_LongToULong();
    test_LongToDWord();
    test_LongToInt();
    test_LongToULongLong();
    test_LongToUIntPtr();
    test_LongToSizeT();
    test_LongToDWordPtr();
    test_LongToULongPtr();
    test_LongToIntPtr();
    test_LongToPtrdiffT();
    test_ULongLongToUInt();
    test_ULongLongToULong();
    test_ULongLongToDWord();
    test_ULongLongToInt();
    test_ULongLongToLong();
    test_ULongLongToInt64();
    test_ULongLongToUIntPtr();
    test_ULongLongToSizeT();
    test_ULongLongToDWordPtr();
    test_ULongLongToULongPtr();
    test_ULongLongToIntPtr();
    test_ULongLongToLongPtr();
    test_ULongLongToPtrdiffT();
    test_ULongLongToSSIZET();
    test_Int64ToUInt();
    test_Int64ToULong();
    test_Int64ToDWord();
    test_Int64ToInt();
    test_Int64ToLong();
    test_Int64ToULongLong();
    test_Int64ToUIntPtr();
    test_Int64ToSizeT();
    test_Int64ToDWordPtr();
    test_Int64ToULongPtr();
    test_Int64ToIntPtr();
    test_Int64ToLongPtr();
    test_Int64ToPtrdiffT();
    test_Int64ToSSIZET();
    test_UIntPtrToUInt();
    test_UIntPtrToULong();
    test_UIntPtrToDWord();
    test_UIntPtrToInt();
    test_UIntPtrToLong();
    test_UIntPtrToInt64();
    test_UIntPtrToIntPtr();
    test_UIntPtrToLongPtr();
    test_UIntPtrToSSIZET();
    test_SizeTToUInt();
    test_SizeTToULong();
    test_SizeTToDWord();
    test_SizeTToInt();
    test_SizeTToLong();
    test_SizeTToInt64();
    test_SizeTToIntPtr();
    test_SizeTToLongPtr();
    test_SizeTToPtrdiffT();
    test_SizeTToSSIZET();
    test_DWordPtrToUInt();
    test_DWordPtrToULong();
    test_DWordPtrToDWord();
    test_DWordPtrToInt();
    test_DWordPtrToLong();
    test_DWordPtrToInt64();
    test_DWordPtrToUIntPtr();
    test_DWordPtrToIntPtr();
    test_DWordPtrToLongPtr();
    test_DWordPtrToPtrdiffT();
    test_DWordPtrToSSIZET();
    test_ULongPtrToUInt();
    test_ULongPtrToULong();
    test_ULongPtrToDWord();
    test_ULongPtrToInt();
    test_ULongPtrToLong();
    test_ULongPtrToInt64();
    test_ULongPtrToUIntPtr();
    test_ULongPtrToIntPtr();
    test_ULongPtrToLongPtr();
    test_ULongPtrToPtrdiffT();
    test_ULongPtrToSSIZET();
    test_IntPtrToUInt();
    test_IntPtrToULong();
    test_IntPtrToDWord();
    test_IntPtrToInt();
    test_IntPtrToLong();
    test_IntPtrToULongLong();
    test_IntPtrToUIntPtr();
    test_IntPtrToSizeT();
    test_IntPtrToDWordPtr();
    test_IntPtrToULongPtr();
    test_LongPtrToUInt();
    test_LongPtrToULong();
    test_LongPtrToDWord();
    test_LongPtrToInt();
    test_LongPtrToLong();
    test_LongPtrToULongLong();
    test_LongPtrToUIntPtr();
    test_LongPtrToSizeT();
    test_LongPtrToDWordPtr();
    test_LongPtrToULongPtr();
    test_LongPtrToIntPtr();
    test_PtrdiffTToUInt();
    test_PtrdiffTToULong();
    test_PtrdiffTToDWord();
    test_PtrdiffTToInt();
    test_PtrdiffTToLong();
    test_PtrdiffTToUIntPtr();
    test_PtrdiffTToSizeT();
    test_PtrdiffTToDWordPtr();
    test_PtrdiffTToULongPtr();
    test_SSIZETToUInt();
    test_SSIZETToULong();
    test_SSIZETToDWord();
    test_SSIZETToInt();
    test_SSIZETToLong();
    test_SSIZETToUIntPtr();
    test_SSIZETToSizeT();
    test_SSIZETToDWordPtr();
    test_SSIZETToULongPtr();
    test_SSIZETToIntPtr();
}

static void tests_auto()
{
    tests_types();
    tests_conversions();
}

#endif /* __CHAR_UNSIGNED__ else */
#else /* _WIN64 */
#ifdef __CHAR_UNSIGNED__
static void test_UCHAR_eq_uint8_t()
{
    if(sizeof(UCHAR) != 1)
        error("UCHAR is actually %d bytes", (int)sizeof(UCHAR));
    UCHAR x = 0;
    if(!((UCHAR)(x - 1) > x))
        error("UCHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UCHAR>::value)
        error("UCHAR is a pointer");
    #endif
}

static void test_BYTE_eq_uint8_t()
{
    if(sizeof(BYTE) != 1)
        error("BYTE is actually %d bytes", (int)sizeof(BYTE));
    BYTE x = 0;
    if(!((BYTE)(x - 1) > x))
        error("BYTE sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<BYTE>::value)
        error("BYTE is a pointer");
    #endif
}

static void test_CHAR_eq_uint8_t()
{
    if(sizeof(CHAR) != 1)
        error("CHAR is actually %d bytes", (int)sizeof(CHAR));
    CHAR x = 0;
    if(!((CHAR)(x - 1) > x))
        error("CHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<CHAR>::value)
        error("CHAR is a pointer");
    #endif
}

static void test_USHORT_eq_uint16_t()
{
    if(sizeof(USHORT) != 2)
        error("USHORT is actually %d bytes", (int)sizeof(USHORT));
    USHORT x = 0;
    if(!((USHORT)(x - 1) > x))
        error("USHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<USHORT>::value)
        error("USHORT is a pointer");
    #endif
}

static void test_WORD_eq_uint16_t()
{
    if(sizeof(WORD) != 2)
        error("WORD is actually %d bytes", (int)sizeof(WORD));
    WORD x = 0;
    if(!((WORD)(x - 1) > x))
        error("WORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<WORD>::value)
        error("WORD is a pointer");
    #endif
}

static void test_SHORT_eq_int16_t()
{
    if(sizeof(SHORT) != 2)
        error("SHORT is actually %d bytes", (int)sizeof(SHORT));
    SHORT x = 0;
    if(!((SHORT)(x - 1) < x))
        error("SHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SHORT>::value)
        error("SHORT is a pointer");
    #endif
}

static void test_UINT_eq_uint32_t()
{
    if(sizeof(UINT) != 4)
        error("UINT is actually %d bytes", (int)sizeof(UINT));
    UINT x = 0;
    if(!((UINT)(x - 1) > x))
        error("UINT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT>::value)
        error("UINT is a pointer");
    #endif
}

static void test_ULONG_eq_uint32_t()
{
    if(sizeof(ULONG) != 4)
        error("ULONG is actually %d bytes", (int)sizeof(ULONG));
    ULONG x = 0;
    if(!((ULONG)(x - 1) > x))
        error("ULONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG>::value)
        error("ULONG is a pointer");
    #endif
}

static void test_DWORD_eq_uint32_t()
{
    if(sizeof(DWORD) != 4)
        error("DWORD is actually %d bytes", (int)sizeof(DWORD));
    DWORD x = 0;
    if(!((DWORD)(x - 1) > x))
        error("DWORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD>::value)
        error("DWORD is a pointer");
    #endif
}

static void test_INT_eq_int32_t()
{
    if(sizeof(INT) != 4)
        error("INT is actually %d bytes", (int)sizeof(INT));
    INT x = 0;
    if(!((INT)(x - 1) < x))
        error("INT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT>::value)
        error("INT is a pointer");
    #endif
}

static void test_LONG_eq_int32_t()
{
    if(sizeof(LONG) != 4)
        error("LONG is actually %d bytes", (int)sizeof(LONG));
    LONG x = 0;
    if(!((LONG)(x - 1) < x))
        error("LONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG>::value)
        error("LONG is a pointer");
    #endif
}

static void test_ULONGLONG_eq_uint64_t()
{
    if(sizeof(ULONGLONG) != 8)
        error("ULONGLONG is actually %d bytes", (int)sizeof(ULONGLONG));
    ULONGLONG x = 0;
    if(!((ULONGLONG)(x - 1) > x))
        error("ULONGLONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONGLONG>::value)
        error("ULONGLONG is a pointer");
    #endif
}

static void test_INT64_eq_int64_t()
{
    if(sizeof(INT64) != 8)
        error("INT64 is actually %d bytes", (int)sizeof(INT64));
    INT64 x = 0;
    if(!((INT64)(x - 1) < x))
        error("INT64 sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT64>::value)
        error("INT64 is a pointer");
    #endif
}

static void test_UINT_PTR_eq_uint32_t()
{
    if(sizeof(UINT_PTR) != 4)
        error("UINT_PTR is actually %d bytes", (int)sizeof(UINT_PTR));
    UINT_PTR x = 0;
    if(!((UINT_PTR)(x - 1) > x))
        error("UINT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT_PTR>::value)
        error("UINT_PTR is a pointer");
    #endif
}

static void test_size_t_eq_uint32_t()
{
    if(sizeof(size_t) != 4)
        error("size_t is actually %d bytes", (int)sizeof(size_t));
    size_t x = 0;
    if(!((size_t)(x - 1) > x))
        error("size_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<size_t>::value)
        error("size_t is a pointer");
    #endif
}

static void test_DWORD_PTR_eq_uint32_t()
{
    if(sizeof(DWORD_PTR) != 4)
        error("DWORD_PTR is actually %d bytes", (int)sizeof(DWORD_PTR));
    DWORD_PTR x = 0;
    if(!((DWORD_PTR)(x - 1) > x))
        error("DWORD_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD_PTR>::value)
        error("DWORD_PTR is a pointer");
    #endif
}

static void test_ULONG_PTR_eq_uint32_t()
{
    if(sizeof(ULONG_PTR) != 4)
        error("ULONG_PTR is actually %d bytes", (int)sizeof(ULONG_PTR));
    ULONG_PTR x = 0;
    if(!((ULONG_PTR)(x - 1) > x))
        error("ULONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG_PTR>::value)
        error("ULONG_PTR is a pointer");
    #endif
}

static void test_INT_PTR_eq_int32_t()
{
    if(sizeof(INT_PTR) != 4)
        error("INT_PTR is actually %d bytes", (int)sizeof(INT_PTR));
    INT_PTR x = 0;
    if(!((INT_PTR)(x - 1) < x))
        error("INT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT_PTR>::value)
        error("INT_PTR is a pointer");
    #endif
}

static void test_LONG_PTR_eq_int32_t()
{
    if(sizeof(LONG_PTR) != 4)
        error("LONG_PTR is actually %d bytes", (int)sizeof(LONG_PTR));
    LONG_PTR x = 0;
    if(!((LONG_PTR)(x - 1) < x))
        error("LONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG_PTR>::value)
        error("LONG_PTR is a pointer");
    #endif
}

static void test_ptrdiff_t_eq_int32_t()
{
    if(sizeof(ptrdiff_t) != 4)
        error("ptrdiff_t is actually %d bytes", (int)sizeof(ptrdiff_t));
    ptrdiff_t x = 0;
    if(!((ptrdiff_t)(x - 1) < x))
        error("ptrdiff_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ptrdiff_t>::value)
        error("ptrdiff_t is a pointer");
    #endif
}

static void test_SSIZE_T_eq_int32_t()
{
    if(sizeof(SSIZE_T) != 4)
        error("SSIZE_T is actually %d bytes", (int)sizeof(SSIZE_T));
    SSIZE_T x = 0;
    if(!((SSIZE_T)(x - 1) < x))
        error("SSIZE_T sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SSIZE_T>::value)
        error("SSIZE_T is a pointer");
    #endif
}

static void tests_types()
{
    test_UCHAR_eq_uint8_t();
    test_BYTE_eq_uint8_t();
    test_CHAR_eq_uint8_t();
    test_USHORT_eq_uint16_t();
    test_WORD_eq_uint16_t();
    test_SHORT_eq_int16_t();
    test_UINT_eq_uint32_t();
    test_ULONG_eq_uint32_t();
    test_DWORD_eq_uint32_t();
    test_INT_eq_int32_t();
    test_LONG_eq_int32_t();
    test_ULONGLONG_eq_uint64_t();
    test_INT64_eq_int64_t();
    test_UINT_PTR_eq_uint32_t();
    test_size_t_eq_uint32_t();
    test_DWORD_PTR_eq_uint32_t();
    test_ULONG_PTR_eq_uint32_t();
    test_INT_PTR_eq_int32_t();
    test_LONG_PTR_eq_int32_t();
    test_ptrdiff_t_eq_int32_t();
    test_SSIZE_T_eq_int32_t();
}

static void test_UShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &UShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToUChar), HRESULT (*)(_In_ USHORT, _Out_ UCHAR *)>::value)
            error("UShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0, &out) != 0)
            error("UShortToUChar failed to convert 0");
        if(out != 0)
            error("UShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0xff, &out) != 0)
            error("UShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToUChar(0x100, &out))
            error("UShortToUChar did not overflow when given 0x100");
    }

}

static void test_UShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ BYTE *) __attribute__ ((unused)) = &UShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToByte), HRESULT (*)(_In_ USHORT, _Out_ BYTE *)>::value)
            error("UShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0, &out) != 0)
            error("UShortToByte failed to convert 0");
        if(out != 0)
            error("UShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0xff, &out) != 0)
            error("UShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("UShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToByte(0x100, &out))
            error("UShortToByte did not overflow when given 0x100");
    }

}

static void test_UShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ CHAR *) __attribute__ ((unused)) = &UShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToChar), HRESULT (*)(_In_ USHORT, _Out_ CHAR *)>::value)
            error("UShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0, &out) != 0)
            error("UShortToChar failed to convert 0");
        if(out != 0)
            error("UShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0xff, &out) != 0)
            error("UShortToChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToChar(0x100, &out))
            error("UShortToChar did not overflow when given 0x100");
    }

}

static void test_UShortToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ SHORT *) __attribute__ ((unused)) = &UShortToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToShort), HRESULT (*)(_In_ USHORT, _Out_ SHORT *)>::value)
            error("UShortToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0, &out) != 0)
            error("UShortToShort failed to convert 0");
        if(out != 0)
            error("UShortToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0x7fff, &out) != 0)
            error("UShortToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UShortToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToShort(0x8000, &out))
            error("UShortToShort did not overflow when given 0x8000");
    }

}

static void test_WordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ UCHAR *) __attribute__ ((unused)) = &WordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToUChar), HRESULT (*)(_In_ WORD, _Out_ UCHAR *)>::value)
            error("WordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0, &out) != 0)
            error("WordToUChar failed to convert 0");
        if(out != 0)
            error("WordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0xff, &out) != 0)
            error("WordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToUChar(0x100, &out))
            error("WordToUChar did not overflow when given 0x100");
    }

}

static void test_WordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ BYTE *) __attribute__ ((unused)) = &WordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToByte), HRESULT (*)(_In_ WORD, _Out_ BYTE *)>::value)
            error("WordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToByte(0, &out) != 0)
            error("WordToByte failed to convert 0");
        if(out != 0)
            error("WordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToByte(0xff, &out) != 0)
            error("WordToByte failed to convert 0xff");
        if(out != 0xff)
            error("WordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToByte(0x100, &out))
            error("WordToByte did not overflow when given 0x100");
    }

}

static void test_WordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ CHAR *) __attribute__ ((unused)) = &WordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToChar), HRESULT (*)(_In_ WORD, _Out_ CHAR *)>::value)
            error("WordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToChar(0, &out) != 0)
            error("WordToChar failed to convert 0");
        if(out != 0)
            error("WordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToChar(0xff, &out) != 0)
            error("WordToChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToChar(0x100, &out))
            error("WordToChar did not overflow when given 0x100");
    }

}

static void test_WordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ SHORT *) __attribute__ ((unused)) = &WordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToShort), HRESULT (*)(_In_ WORD, _Out_ SHORT *)>::value)
            error("WordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToShort(0, &out) != 0)
            error("WordToShort failed to convert 0");
        if(out != 0)
            error("WordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToShort(0x7fff, &out) != 0)
            error("WordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("WordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToShort(0x8000, &out))
            error("WordToShort did not overflow when given 0x8000");
    }

}

static void test_ShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &ShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUChar), HRESULT (*)(_In_ SHORT, _Out_ UCHAR *)>::value)
            error("ShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0, &out) != 0)
            error("ShortToUChar failed to convert 0");
        if(out != 0)
            error("ShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0xff, &out) != 0)
            error("ShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar(0x100, &out))
            error("ShortToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar((-0ll - 1), &out))
            error("ShortToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ BYTE *) __attribute__ ((unused)) = &ShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToByte), HRESULT (*)(_In_ SHORT, _Out_ BYTE *)>::value)
            error("ShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0, &out) != 0)
            error("ShortToByte failed to convert 0");
        if(out != 0)
            error("ShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0xff, &out) != 0)
            error("ShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("ShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte(0x100, &out))
            error("ShortToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte((-0ll - 1), &out))
            error("ShortToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ CHAR *) __attribute__ ((unused)) = &ShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToChar), HRESULT (*)(_In_ SHORT, _Out_ CHAR *)>::value)
            error("ShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0, &out) != 0)
            error("ShortToChar failed to convert 0");
        if(out != 0)
            error("ShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0xff, &out) != 0)
            error("ShortToChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar(0x100, &out))
            error("ShortToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar((-0ll - 1), &out))
            error("ShortToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ USHORT *) __attribute__ ((unused)) = &ShortToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUShort), HRESULT (*)(_In_ SHORT, _Out_ USHORT *)>::value)
            error("ShortToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0, &out) != 0)
            error("ShortToUShort failed to convert 0");
        if(out != 0)
            error("ShortToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0x7fff, &out) != 0)
            error("ShortToUShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToUShort changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUShort((-0ll - 1), &out))
            error("ShortToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ WORD *) __attribute__ ((unused)) = &ShortToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToWord), HRESULT (*)(_In_ SHORT, _Out_ WORD *)>::value)
            error("ShortToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0, &out) != 0)
            error("ShortToWord failed to convert 0");
        if(out != 0)
            error("ShortToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0x7fff, &out) != 0)
            error("ShortToWord failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToWord changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToWord((-0ll - 1), &out))
            error("ShortToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_UIntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ UCHAR *) __attribute__ ((unused)) = &UIntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUChar), HRESULT (*)(_In_ UINT, _Out_ UCHAR *)>::value)
            error("UIntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0, &out) != 0)
            error("UIntToUChar failed to convert 0");
        if(out != 0)
            error("UIntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0xff, &out) != 0)
            error("UIntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUChar(0x100, &out))
            error("UIntToUChar did not overflow when given 0x100");
    }

}

static void test_UIntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ BYTE *) __attribute__ ((unused)) = &UIntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToByte), HRESULT (*)(_In_ UINT, _Out_ BYTE *)>::value)
            error("UIntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0, &out) != 0)
            error("UIntToByte failed to convert 0");
        if(out != 0)
            error("UIntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0xff, &out) != 0)
            error("UIntToByte failed to convert 0xff");
        if(out != 0xff)
            error("UIntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToByte(0x100, &out))
            error("UIntToByte did not overflow when given 0x100");
    }

}

static void test_UIntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ CHAR *) __attribute__ ((unused)) = &UIntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToChar), HRESULT (*)(_In_ UINT, _Out_ CHAR *)>::value)
            error("UIntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0, &out) != 0)
            error("UIntToChar failed to convert 0");
        if(out != 0)
            error("UIntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0xff, &out) != 0)
            error("UIntToChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToChar(0x100, &out))
            error("UIntToChar did not overflow when given 0x100");
    }

}

static void test_UIntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ USHORT *) __attribute__ ((unused)) = &UIntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUShort), HRESULT (*)(_In_ UINT, _Out_ USHORT *)>::value)
            error("UIntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0, &out) != 0)
            error("UIntToUShort failed to convert 0");
        if(out != 0)
            error("UIntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0xffff, &out) != 0)
            error("UIntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUShort(0x10000, &out))
            error("UIntToUShort did not overflow when given 0x10000");
    }

}

static void test_UIntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ WORD *) __attribute__ ((unused)) = &UIntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToWord), HRESULT (*)(_In_ UINT, _Out_ WORD *)>::value)
            error("UIntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0, &out) != 0)
            error("UIntToWord failed to convert 0");
        if(out != 0)
            error("UIntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0xffff, &out) != 0)
            error("UIntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToWord(0x10000, &out))
            error("UIntToWord did not overflow when given 0x10000");
    }

}

static void test_UIntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SHORT *) __attribute__ ((unused)) = &UIntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToShort), HRESULT (*)(_In_ UINT, _Out_ SHORT *)>::value)
            error("UIntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0, &out) != 0)
            error("UIntToShort failed to convert 0");
        if(out != 0)
            error("UIntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0x7fff, &out) != 0)
            error("UIntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UIntToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToShort(0x8000, &out))
            error("UIntToShort did not overflow when given 0x8000");
    }

}

static void test_UIntToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT *) __attribute__ ((unused)) = &UIntToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToInt), HRESULT (*)(_In_ UINT, _Out_ INT *)>::value)
            error("UIntToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0, &out) != 0)
            error("UIntToInt failed to convert 0");
        if(out != 0)
            error("UIntToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0x7fffffff, &out) != 0)
            error("UIntToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToInt(0x80000000, &out))
            error("UIntToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG *) __attribute__ ((unused)) = &UIntToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLong), HRESULT (*)(_In_ UINT, _Out_ LONG *)>::value)
            error("UIntToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0, &out) != 0)
            error("UIntToLong failed to convert 0");
        if(out != 0)
            error("UIntToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0x7fffffff, &out) != 0)
            error("UIntToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLong(0x80000000, &out))
            error("UIntToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToIntPtr), HRESULT (*)(_In_ UINT, _Out_ INT_PTR *)>::value)
            error("UIntToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0, &out) != 0)
            error("UIntToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0x7fffffff, &out) != 0)
            error("UIntToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToIntPtr(0x80000000, &out))
            error("UIntToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLongPtr), HRESULT (*)(_In_ UINT, _Out_ LONG_PTR *)>::value)
            error("UIntToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0, &out) != 0)
            error("UIntToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0x7fffffff, &out) != 0)
            error("UIntToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLongPtr(0x80000000, &out))
            error("UIntToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &UIntToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToPtrdiffT), HRESULT (*)(_In_ UINT, _Out_ ptrdiff_t *)>::value)
            error("UIntToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0");
        if(out != 0)
            error("UIntToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0x7fffffff, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToPtrdiffT(0x80000000, &out))
            error("UIntToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_UIntToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToSSIZET), HRESULT (*)(_In_ UINT, _Out_ SSIZE_T *)>::value)
            error("UIntToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0, &out) != 0)
            error("UIntToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0x7fffffff, &out) != 0)
            error("UIntToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToSSIZET(0x80000000, &out))
            error("UIntToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_ULongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UCHAR *) __attribute__ ((unused)) = &ULongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUChar), HRESULT (*)(_In_ ULONG, _Out_ UCHAR *)>::value)
            error("ULongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0, &out) != 0)
            error("ULongToUChar failed to convert 0");
        if(out != 0)
            error("ULongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0xff, &out) != 0)
            error("ULongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUChar(0x100, &out))
            error("ULongToUChar did not overflow when given 0x100");
    }

}

static void test_ULongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ BYTE *) __attribute__ ((unused)) = &ULongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToByte), HRESULT (*)(_In_ ULONG, _Out_ BYTE *)>::value)
            error("ULongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0, &out) != 0)
            error("ULongToByte failed to convert 0");
        if(out != 0)
            error("ULongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0xff, &out) != 0)
            error("ULongToByte failed to convert 0xff");
        if(out != 0xff)
            error("ULongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToByte(0x100, &out))
            error("ULongToByte did not overflow when given 0x100");
    }

}

static void test_ULongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ CHAR *) __attribute__ ((unused)) = &ULongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToChar), HRESULT (*)(_In_ ULONG, _Out_ CHAR *)>::value)
            error("ULongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0, &out) != 0)
            error("ULongToChar failed to convert 0");
        if(out != 0)
            error("ULongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0xff, &out) != 0)
            error("ULongToChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToChar(0x100, &out))
            error("ULongToChar did not overflow when given 0x100");
    }

}

static void test_ULongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ USHORT *) __attribute__ ((unused)) = &ULongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUShort), HRESULT (*)(_In_ ULONG, _Out_ USHORT *)>::value)
            error("ULongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0, &out) != 0)
            error("ULongToUShort failed to convert 0");
        if(out != 0)
            error("ULongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0xffff, &out) != 0)
            error("ULongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUShort(0x10000, &out))
            error("ULongToUShort did not overflow when given 0x10000");
    }

}

static void test_ULongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ WORD *) __attribute__ ((unused)) = &ULongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToWord), HRESULT (*)(_In_ ULONG, _Out_ WORD *)>::value)
            error("ULongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0, &out) != 0)
            error("ULongToWord failed to convert 0");
        if(out != 0)
            error("ULongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0xffff, &out) != 0)
            error("ULongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToWord(0x10000, &out))
            error("ULongToWord did not overflow when given 0x10000");
    }

}

static void test_ULongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SHORT *) __attribute__ ((unused)) = &ULongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToShort), HRESULT (*)(_In_ ULONG, _Out_ SHORT *)>::value)
            error("ULongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0, &out) != 0)
            error("ULongToShort failed to convert 0");
        if(out != 0)
            error("ULongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0x7fff, &out) != 0)
            error("ULongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ULongToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToShort(0x8000, &out))
            error("ULongToShort did not overflow when given 0x8000");
    }

}

static void test_ULongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUInt), HRESULT (*)(_In_ ULONG, _Out_ UINT *)>::value)
            error("ULongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0, &out) != 0)
            error("ULongToUInt failed to convert 0");
        if(out != 0)
            error("ULongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0xffffffff, &out) != 0)
            error("ULongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT *) __attribute__ ((unused)) = &ULongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToInt), HRESULT (*)(_In_ ULONG, _Out_ INT *)>::value)
            error("ULongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0, &out) != 0)
            error("ULongToInt failed to convert 0");
        if(out != 0)
            error("ULongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0x7fffffff, &out) != 0)
            error("ULongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToInt(0x80000000, &out))
            error("ULongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLong), HRESULT (*)(_In_ ULONG, _Out_ LONG *)>::value)
            error("ULongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0, &out) != 0)
            error("ULongToLong failed to convert 0");
        if(out != 0)
            error("ULongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0x7fffffff, &out) != 0)
            error("ULongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLong(0x80000000, &out))
            error("ULongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUIntPtr), HRESULT (*)(_In_ ULONG, _Out_ UINT_PTR *)>::value)
            error("ULongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0, &out) != 0)
            error("ULongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToIntPtr), HRESULT (*)(_In_ ULONG, _Out_ INT_PTR *)>::value)
            error("ULongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0, &out) != 0)
            error("ULongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0x7fffffff, &out) != 0)
            error("ULongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToIntPtr(0x80000000, &out))
            error("ULongToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLongPtr), HRESULT (*)(_In_ ULONG, _Out_ LONG_PTR *)>::value)
            error("ULongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0, &out) != 0)
            error("ULongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0x7fffffff, &out) != 0)
            error("ULongToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLongPtr(0x80000000, &out))
            error("ULongToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToPtrdiffT), HRESULT (*)(_In_ ULONG, _Out_ ptrdiff_t *)>::value)
            error("ULongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToPtrdiffT(0x80000000, &out))
            error("ULongToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToSSIZET), HRESULT (*)(_In_ ULONG, _Out_ SSIZE_T *)>::value)
            error("ULongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0, &out) != 0)
            error("ULongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0x7fffffff, &out) != 0)
            error("ULongToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToSSIZET(0x80000000, &out))
            error("ULongToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_DWordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UCHAR *) __attribute__ ((unused)) = &DWordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUChar), HRESULT (*)(_In_ DWORD, _Out_ UCHAR *)>::value)
            error("DWordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0, &out) != 0)
            error("DWordToUChar failed to convert 0");
        if(out != 0)
            error("DWordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0xff, &out) != 0)
            error("DWordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUChar(0x100, &out))
            error("DWordToUChar did not overflow when given 0x100");
    }

}

static void test_DWordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ BYTE *) __attribute__ ((unused)) = &DWordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToByte), HRESULT (*)(_In_ DWORD, _Out_ BYTE *)>::value)
            error("DWordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0, &out) != 0)
            error("DWordToByte failed to convert 0");
        if(out != 0)
            error("DWordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0xff, &out) != 0)
            error("DWordToByte failed to convert 0xff");
        if(out != 0xff)
            error("DWordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToByte(0x100, &out))
            error("DWordToByte did not overflow when given 0x100");
    }

}

static void test_DWordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ CHAR *) __attribute__ ((unused)) = &DWordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToChar), HRESULT (*)(_In_ DWORD, _Out_ CHAR *)>::value)
            error("DWordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0, &out) != 0)
            error("DWordToChar failed to convert 0");
        if(out != 0)
            error("DWordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0xff, &out) != 0)
            error("DWordToChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToChar(0x100, &out))
            error("DWordToChar did not overflow when given 0x100");
    }

}

static void test_DWordToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ USHORT *) __attribute__ ((unused)) = &DWordToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUShort), HRESULT (*)(_In_ DWORD, _Out_ USHORT *)>::value)
            error("DWordToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0, &out) != 0)
            error("DWordToUShort failed to convert 0");
        if(out != 0)
            error("DWordToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0xffff, &out) != 0)
            error("DWordToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUShort(0x10000, &out))
            error("DWordToUShort did not overflow when given 0x10000");
    }

}

static void test_DWordToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ WORD *) __attribute__ ((unused)) = &DWordToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToWord), HRESULT (*)(_In_ DWORD, _Out_ WORD *)>::value)
            error("DWordToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0, &out) != 0)
            error("DWordToWord failed to convert 0");
        if(out != 0)
            error("DWordToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0xffff, &out) != 0)
            error("DWordToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToWord(0x10000, &out))
            error("DWordToWord did not overflow when given 0x10000");
    }

}

static void test_DWordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SHORT *) __attribute__ ((unused)) = &DWordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToShort), HRESULT (*)(_In_ DWORD, _Out_ SHORT *)>::value)
            error("DWordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0, &out) != 0)
            error("DWordToShort failed to convert 0");
        if(out != 0)
            error("DWordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0x7fff, &out) != 0)
            error("DWordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("DWordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToShort(0x8000, &out))
            error("DWordToShort did not overflow when given 0x8000");
    }

}

static void test_DWordToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT *) __attribute__ ((unused)) = &DWordToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUInt), HRESULT (*)(_In_ DWORD, _Out_ UINT *)>::value)
            error("DWordToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0, &out) != 0)
            error("DWordToUInt failed to convert 0");
        if(out != 0)
            error("DWordToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0xffffffff, &out) != 0)
            error("DWordToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT *) __attribute__ ((unused)) = &DWordToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToInt), HRESULT (*)(_In_ DWORD, _Out_ INT *)>::value)
            error("DWordToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0, &out) != 0)
            error("DWordToInt failed to convert 0");
        if(out != 0)
            error("DWordToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0x7fffffff, &out) != 0)
            error("DWordToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToInt(0x80000000, &out))
            error("DWordToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG *) __attribute__ ((unused)) = &DWordToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLong), HRESULT (*)(_In_ DWORD, _Out_ LONG *)>::value)
            error("DWordToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0, &out) != 0)
            error("DWordToLong failed to convert 0");
        if(out != 0)
            error("DWordToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0x7fffffff, &out) != 0)
            error("DWordToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLong(0x80000000, &out))
            error("DWordToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUIntPtr), HRESULT (*)(_In_ DWORD, _Out_ UINT_PTR *)>::value)
            error("DWordToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0, &out) != 0)
            error("DWordToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0xffffffff, &out) != 0)
            error("DWordToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToIntPtr), HRESULT (*)(_In_ DWORD, _Out_ INT_PTR *)>::value)
            error("DWordToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0, &out) != 0)
            error("DWordToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0x7fffffff, &out) != 0)
            error("DWordToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToIntPtr(0x80000000, &out))
            error("DWordToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLongPtr), HRESULT (*)(_In_ DWORD, _Out_ LONG_PTR *)>::value)
            error("DWordToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0, &out) != 0)
            error("DWordToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0x7fffffff, &out) != 0)
            error("DWordToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLongPtr(0x80000000, &out))
            error("DWordToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToPtrdiffT), HRESULT (*)(_In_ DWORD, _Out_ ptrdiff_t *)>::value)
            error("DWordToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0x7fffffff, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToPtrdiffT(0x80000000, &out))
            error("DWordToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_DWordToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToSSIZET), HRESULT (*)(_In_ DWORD, _Out_ SSIZE_T *)>::value)
            error("DWordToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0, &out) != 0)
            error("DWordToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0x7fffffff, &out) != 0)
            error("DWordToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToSSIZET(0x80000000, &out))
            error("DWordToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_IntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UCHAR *) __attribute__ ((unused)) = &IntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUChar), HRESULT (*)(_In_ INT, _Out_ UCHAR *)>::value)
            error("IntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0, &out) != 0)
            error("IntToUChar failed to convert 0");
        if(out != 0)
            error("IntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0xff, &out) != 0)
            error("IntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar(0x100, &out))
            error("IntToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar((-0ll - 1), &out))
            error("IntToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ BYTE *) __attribute__ ((unused)) = &IntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToByte), HRESULT (*)(_In_ INT, _Out_ BYTE *)>::value)
            error("IntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToByte(0, &out) != 0)
            error("IntToByte failed to convert 0");
        if(out != 0)
            error("IntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToByte(0xff, &out) != 0)
            error("IntToByte failed to convert 0xff");
        if(out != 0xff)
            error("IntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte(0x100, &out))
            error("IntToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte((-0ll - 1), &out))
            error("IntToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ CHAR *) __attribute__ ((unused)) = &IntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToChar), HRESULT (*)(_In_ INT, _Out_ CHAR *)>::value)
            error("IntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToChar(0, &out) != 0)
            error("IntToChar failed to convert 0");
        if(out != 0)
            error("IntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToChar(0xff, &out) != 0)
            error("IntToChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar(0x100, &out))
            error("IntToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar((-0ll - 1), &out))
            error("IntToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ USHORT *) __attribute__ ((unused)) = &IntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUShort), HRESULT (*)(_In_ INT, _Out_ USHORT *)>::value)
            error("IntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0, &out) != 0)
            error("IntToUShort failed to convert 0");
        if(out != 0)
            error("IntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0xffff, &out) != 0)
            error("IntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort(0x10000, &out))
            error("IntToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort((-0ll - 1), &out))
            error("IntToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ WORD *) __attribute__ ((unused)) = &IntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToWord), HRESULT (*)(_In_ INT, _Out_ WORD *)>::value)
            error("IntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToWord(0, &out) != 0)
            error("IntToWord failed to convert 0");
        if(out != 0)
            error("IntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToWord(0xffff, &out) != 0)
            error("IntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord(0x10000, &out))
            error("IntToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord((-0ll - 1), &out))
            error("IntToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ SHORT *) __attribute__ ((unused)) = &IntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToShort), HRESULT (*)(_In_ INT, _Out_ SHORT *)>::value)
            error("IntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToShort(0, &out) != 0)
            error("IntToShort failed to convert 0");
        if(out != 0)
            error("IntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToShort(0x7fff, &out) != 0)
            error("IntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("IntToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToShort((-0x7fffll - 1), &out) != 0)
            error("IntToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("IntToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort(0x8000, &out))
            error("IntToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort((-0x8000ll - 1), &out))
            error("IntToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_IntToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT *) __attribute__ ((unused)) = &IntToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUInt), HRESULT (*)(_In_ INT, _Out_ UINT *)>::value)
            error("IntToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0, &out) != 0)
            error("IntToUInt failed to convert 0");
        if(out != 0)
            error("IntToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0x7fffffff, &out) != 0)
            error("IntToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUInt((-0ll - 1), &out))
            error("IntToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG *) __attribute__ ((unused)) = &IntToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULong), HRESULT (*)(_In_ INT, _Out_ ULONG *)>::value)
            error("IntToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULong(0, &out) != 0)
            error("IntToULong failed to convert 0");
        if(out != 0)
            error("IntToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULong(0x7fffffff, &out) != 0)
            error("IntToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULong((-0ll - 1), &out))
            error("IntToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD *) __attribute__ ((unused)) = &IntToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWord), HRESULT (*)(_In_ INT, _Out_ DWORD *)>::value)
            error("IntToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0, &out) != 0)
            error("IntToDWord failed to convert 0");
        if(out != 0)
            error("IntToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0x7fffffff, &out) != 0)
            error("IntToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWord((-0ll - 1), &out))
            error("IntToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongLong), HRESULT (*)(_In_ INT, _Out_ ULONGLONG *)>::value)
            error("IntToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0, &out) != 0)
            error("IntToULongLong failed to convert 0");
        if(out != 0)
            error("IntToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0x7fffffff, &out) != 0)
            error("IntToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongLong((-0ll - 1), &out))
            error("IntToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUIntPtr), HRESULT (*)(_In_ INT, _Out_ UINT_PTR *)>::value)
            error("IntToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0, &out) != 0)
            error("IntToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0x7fffffff, &out) != 0)
            error("IntToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUIntPtr((-0ll - 1), &out))
            error("IntToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ size_t *) __attribute__ ((unused)) = &IntToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToSizeT), HRESULT (*)(_In_ INT, _Out_ size_t *)>::value)
            error("IntToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0, &out) != 0)
            error("IntToSizeT failed to convert 0");
        if(out != 0)
            error("IntToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0x7fffffff, &out) != 0)
            error("IntToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToSizeT((-0ll - 1), &out))
            error("IntToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWordPtr), HRESULT (*)(_In_ INT, _Out_ DWORD_PTR *)>::value)
            error("IntToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0, &out) != 0)
            error("IntToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0x7fffffff, &out) != 0)
            error("IntToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWordPtr((-0ll - 1), &out))
            error("IntToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongPtr), HRESULT (*)(_In_ INT, _Out_ ULONG_PTR *)>::value)
            error("IntToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0, &out) != 0)
            error("IntToULongPtr failed to convert 0");
        if(out != 0)
            error("IntToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0x7fffffff, &out) != 0)
            error("IntToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongPtr((-0ll - 1), &out))
            error("IntToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UCHAR *) __attribute__ ((unused)) = &LongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUChar), HRESULT (*)(_In_ LONG, _Out_ UCHAR *)>::value)
            error("LongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0, &out) != 0)
            error("LongToUChar failed to convert 0");
        if(out != 0)
            error("LongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0xff, &out) != 0)
            error("LongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar(0x100, &out))
            error("LongToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar((-0ll - 1), &out))
            error("LongToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ BYTE *) __attribute__ ((unused)) = &LongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToByte), HRESULT (*)(_In_ LONG, _Out_ BYTE *)>::value)
            error("LongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToByte(0, &out) != 0)
            error("LongToByte failed to convert 0");
        if(out != 0)
            error("LongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToByte(0xff, &out) != 0)
            error("LongToByte failed to convert 0xff");
        if(out != 0xff)
            error("LongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte(0x100, &out))
            error("LongToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte((-0ll - 1), &out))
            error("LongToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ CHAR *) __attribute__ ((unused)) = &LongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToChar), HRESULT (*)(_In_ LONG, _Out_ CHAR *)>::value)
            error("LongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToChar(0, &out) != 0)
            error("LongToChar failed to convert 0");
        if(out != 0)
            error("LongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToChar(0xff, &out) != 0)
            error("LongToChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar(0x100, &out))
            error("LongToChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar((-0ll - 1), &out))
            error("LongToChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ USHORT *) __attribute__ ((unused)) = &LongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUShort), HRESULT (*)(_In_ LONG, _Out_ USHORT *)>::value)
            error("LongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0, &out) != 0)
            error("LongToUShort failed to convert 0");
        if(out != 0)
            error("LongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0xffff, &out) != 0)
            error("LongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort(0x10000, &out))
            error("LongToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort((-0ll - 1), &out))
            error("LongToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ WORD *) __attribute__ ((unused)) = &LongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToWord), HRESULT (*)(_In_ LONG, _Out_ WORD *)>::value)
            error("LongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToWord(0, &out) != 0)
            error("LongToWord failed to convert 0");
        if(out != 0)
            error("LongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToWord(0xffff, &out) != 0)
            error("LongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord(0x10000, &out))
            error("LongToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord((-0ll - 1), &out))
            error("LongToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ SHORT *) __attribute__ ((unused)) = &LongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToShort), HRESULT (*)(_In_ LONG, _Out_ SHORT *)>::value)
            error("LongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToShort(0, &out) != 0)
            error("LongToShort failed to convert 0");
        if(out != 0)
            error("LongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToShort(0x7fff, &out) != 0)
            error("LongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("LongToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToShort((-0x7fffll - 1), &out) != 0)
            error("LongToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("LongToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort(0x8000, &out))
            error("LongToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort((-0x8000ll - 1), &out))
            error("LongToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_LongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT *) __attribute__ ((unused)) = &LongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUInt), HRESULT (*)(_In_ LONG, _Out_ UINT *)>::value)
            error("LongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0, &out) != 0)
            error("LongToUInt failed to convert 0");
        if(out != 0)
            error("LongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0x7fffffff, &out) != 0)
            error("LongToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUInt((-0ll - 1), &out))
            error("LongToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG *) __attribute__ ((unused)) = &LongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULong), HRESULT (*)(_In_ LONG, _Out_ ULONG *)>::value)
            error("LongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULong(0, &out) != 0)
            error("LongToULong failed to convert 0");
        if(out != 0)
            error("LongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULong(0x7fffffff, &out) != 0)
            error("LongToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULong((-0ll - 1), &out))
            error("LongToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD *) __attribute__ ((unused)) = &LongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWord), HRESULT (*)(_In_ LONG, _Out_ DWORD *)>::value)
            error("LongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0, &out) != 0)
            error("LongToDWord failed to convert 0");
        if(out != 0)
            error("LongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0x7fffffff, &out) != 0)
            error("LongToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWord((-0ll - 1), &out))
            error("LongToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT *) __attribute__ ((unused)) = &LongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToInt), HRESULT (*)(_In_ LONG, _Out_ INT *)>::value)
            error("LongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToInt(0, &out) != 0)
            error("LongToInt failed to convert 0");
        if(out != 0)
            error("LongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToInt(0x7fffffff, &out) != 0)
            error("LongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongLong), HRESULT (*)(_In_ LONG, _Out_ ULONGLONG *)>::value)
            error("LongToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0, &out) != 0)
            error("LongToULongLong failed to convert 0");
        if(out != 0)
            error("LongToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0x7fffffff, &out) != 0)
            error("LongToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongLong((-0ll - 1), &out))
            error("LongToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUIntPtr), HRESULT (*)(_In_ LONG, _Out_ UINT_PTR *)>::value)
            error("LongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0, &out) != 0)
            error("LongToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0x7fffffff, &out) != 0)
            error("LongToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUIntPtr((-0ll - 1), &out))
            error("LongToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ size_t *) __attribute__ ((unused)) = &LongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToSizeT), HRESULT (*)(_In_ LONG, _Out_ size_t *)>::value)
            error("LongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0, &out) != 0)
            error("LongToSizeT failed to convert 0");
        if(out != 0)
            error("LongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0x7fffffff, &out) != 0)
            error("LongToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToSizeT((-0ll - 1), &out))
            error("LongToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWordPtr), HRESULT (*)(_In_ LONG, _Out_ DWORD_PTR *)>::value)
            error("LongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0, &out) != 0)
            error("LongToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0x7fffffff, &out) != 0)
            error("LongToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWordPtr((-0ll - 1), &out))
            error("LongToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongPtr), HRESULT (*)(_In_ LONG, _Out_ ULONG_PTR *)>::value)
            error("LongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0, &out) != 0)
            error("LongToULongPtr failed to convert 0");
        if(out != 0)
            error("LongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0x7fffffff, &out) != 0)
            error("LongToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongPtr((-0ll - 1), &out))
            error("LongToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToIntPtr), HRESULT (*)(_In_ LONG, _Out_ INT_PTR *)>::value)
            error("LongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0, &out) != 0)
            error("LongToIntPtr failed to convert 0");
        if(out != 0)
            error("LongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0x7fffffff, &out) != 0)
            error("LongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &LongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToPtrdiffT), HRESULT (*)(_In_ LONG, _Out_ ptrdiff_t *)>::value)
            error("LongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0, &out) != 0)
            error("LongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("LongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0x7fffffff, &out) != 0)
            error("LongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("LongToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_ULongLongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongLongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUInt), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT *)>::value)
            error("ULongLongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0, &out) != 0)
            error("ULongLongToUInt failed to convert 0");
        if(out != 0)
            error("ULongLongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0xffffffff, &out) != 0)
            error("ULongLongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUInt(0x100000000, &out))
            error("ULongLongToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG *) __attribute__ ((unused)) = &ULongLongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULong), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG *)>::value)
            error("ULongLongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0, &out) != 0)
            error("ULongLongToULong failed to convert 0");
        if(out != 0)
            error("ULongLongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0xffffffff, &out) != 0)
            error("ULongLongToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULong(0x100000000, &out))
            error("ULongLongToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD *) __attribute__ ((unused)) = &ULongLongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWord), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD *)>::value)
            error("ULongLongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0, &out) != 0)
            error("ULongLongToDWord failed to convert 0");
        if(out != 0)
            error("ULongLongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0xffffffff, &out) != 0)
            error("ULongLongToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWord(0x100000000, &out))
            error("ULongLongToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT *) __attribute__ ((unused)) = &ULongLongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt), HRESULT (*)(_In_ ULONGLONG, _Out_ INT *)>::value)
            error("ULongLongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0, &out) != 0)
            error("ULongLongToInt failed to convert 0");
        if(out != 0)
            error("ULongLongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0x7fffffff, &out) != 0)
            error("ULongLongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt(0x80000000, &out))
            error("ULongLongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongLongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLong), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG *)>::value)
            error("ULongLongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0, &out) != 0)
            error("ULongLongToLong failed to convert 0");
        if(out != 0)
            error("ULongLongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0x7fffffff, &out) != 0)
            error("ULongLongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLong(0x80000000, &out))
            error("ULongLongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT64 *) __attribute__ ((unused)) = &ULongLongToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt64), HRESULT (*)(_In_ ULONGLONG, _Out_ INT64 *)>::value)
            error("ULongLongToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0, &out) != 0)
            error("ULongLongToInt64 failed to convert 0");
        if(out != 0)
            error("ULongLongToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt64(0x8000000000000000, &out))
            error("ULongLongToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongLongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT_PTR *)>::value)
            error("ULongLongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUIntPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUIntPtr(0x100000000, &out))
            error("ULongLongToUIntPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ size_t *) __attribute__ ((unused)) = &ULongLongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSizeT), HRESULT (*)(_In_ ULONGLONG, _Out_ size_t *)>::value)
            error("ULongLongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0, &out) != 0)
            error("ULongLongToSizeT failed to convert 0");
        if(out != 0)
            error("ULongLongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0xffffffff, &out) != 0)
            error("ULongLongToSizeT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToSizeT changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSizeT(0x100000000, &out))
            error("ULongLongToSizeT did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &ULongLongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWordPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD_PTR *)>::value)
            error("ULongLongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0xffffffff, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWordPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWordPtr(0x100000000, &out))
            error("ULongLongToDWordPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &ULongLongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG_PTR *)>::value)
            error("ULongLongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0xffffffff, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULongPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULongPtr(0x100000000, &out))
            error("ULongLongToULongPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongLongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ INT_PTR *)>::value)
            error("ULongLongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0x7fffffff, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToIntPtr(0x80000000, &out))
            error("ULongLongToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongLongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG_PTR *)>::value)
            error("ULongLongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0x7fffffff, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLongPtr(0x80000000, &out))
            error("ULongLongToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongLongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToPtrdiffT), HRESULT (*)(_In_ ULONGLONG, _Out_ ptrdiff_t *)>::value)
            error("ULongLongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongLongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToPtrdiffT(0x80000000, &out))
            error("ULongLongToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongLongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSSIZET), HRESULT (*)(_In_ ULONGLONG, _Out_ SSIZE_T *)>::value)
            error("ULongLongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongLongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0x7fffffff, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSSIZET(0x80000000, &out))
            error("ULongLongToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_Int64ToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT *) __attribute__ ((unused)) = &Int64ToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUInt), HRESULT (*)(_In_ INT64, _Out_ UINT *)>::value)
            error("Int64ToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0, &out) != 0)
            error("Int64ToUInt failed to convert 0");
        if(out != 0)
            error("Int64ToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0xffffffff, &out) != 0)
            error("Int64ToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt(0x100000000, &out))
            error("Int64ToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt((-0ll - 1), &out))
            error("Int64ToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG *) __attribute__ ((unused)) = &Int64ToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULong), HRESULT (*)(_In_ INT64, _Out_ ULONG *)>::value)
            error("Int64ToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0, &out) != 0)
            error("Int64ToULong failed to convert 0");
        if(out != 0)
            error("Int64ToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0xffffffff, &out) != 0)
            error("Int64ToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong(0x100000000, &out))
            error("Int64ToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong((-0ll - 1), &out))
            error("Int64ToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD *) __attribute__ ((unused)) = &Int64ToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWord), HRESULT (*)(_In_ INT64, _Out_ DWORD *)>::value)
            error("Int64ToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0, &out) != 0)
            error("Int64ToDWord failed to convert 0");
        if(out != 0)
            error("Int64ToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0xffffffff, &out) != 0)
            error("Int64ToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord(0x100000000, &out))
            error("Int64ToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord((-0ll - 1), &out))
            error("Int64ToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT *) __attribute__ ((unused)) = &Int64ToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToInt), HRESULT (*)(_In_ INT64, _Out_ INT *)>::value)
            error("Int64ToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0, &out) != 0)
            error("Int64ToInt failed to convert 0");
        if(out != 0)
            error("Int64ToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0x7fffffff, &out) != 0)
            error("Int64ToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt(0x80000000, &out))
            error("Int64ToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt((-0x80000000ll - 1), &out))
            error("Int64ToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG *) __attribute__ ((unused)) = &Int64ToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLong), HRESULT (*)(_In_ INT64, _Out_ LONG *)>::value)
            error("Int64ToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0, &out) != 0)
            error("Int64ToLong failed to convert 0");
        if(out != 0)
            error("Int64ToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0x7fffffff, &out) != 0)
            error("Int64ToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong(0x80000000, &out))
            error("Int64ToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong((-0x80000000ll - 1), &out))
            error("Int64ToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONGLONG *) __attribute__ ((unused)) = &Int64ToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongLong), HRESULT (*)(_In_ INT64, _Out_ ULONGLONG *)>::value)
            error("Int64ToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0, &out) != 0)
            error("Int64ToULongLong failed to convert 0");
        if(out != 0)
            error("Int64ToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongLong((-0ll - 1), &out))
            error("Int64ToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT_PTR *) __attribute__ ((unused)) = &Int64ToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUIntPtr), HRESULT (*)(_In_ INT64, _Out_ UINT_PTR *)>::value)
            error("Int64ToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0xffffffff, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUIntPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr(0x100000000, &out))
            error("Int64ToUIntPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr((-0ll - 1), &out))
            error("Int64ToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ size_t *) __attribute__ ((unused)) = &Int64ToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSizeT), HRESULT (*)(_In_ INT64, _Out_ size_t *)>::value)
            error("Int64ToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0, &out) != 0)
            error("Int64ToSizeT failed to convert 0");
        if(out != 0)
            error("Int64ToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0xffffffff, &out) != 0)
            error("Int64ToSizeT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToSizeT changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT(0x100000000, &out))
            error("Int64ToSizeT did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT((-0ll - 1), &out))
            error("Int64ToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &Int64ToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWordPtr), HRESULT (*)(_In_ INT64, _Out_ DWORD_PTR *)>::value)
            error("Int64ToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0");
        if(out != 0)
            error("Int64ToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0xffffffff, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWordPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr(0x100000000, &out))
            error("Int64ToDWordPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr((-0ll - 1), &out))
            error("Int64ToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &Int64ToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongPtr), HRESULT (*)(_In_ INT64, _Out_ ULONG_PTR *)>::value)
            error("Int64ToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0, &out) != 0)
            error("Int64ToULongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0xffffffff, &out) != 0)
            error("Int64ToULongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULongPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr(0x100000000, &out))
            error("Int64ToULongPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr((-0ll - 1), &out))
            error("Int64ToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT_PTR *) __attribute__ ((unused)) = &Int64ToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToIntPtr), HRESULT (*)(_In_ INT64, _Out_ INT_PTR *)>::value)
            error("Int64ToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0, &out) != 0)
            error("Int64ToIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0x7fffffff, &out) != 0)
            error("Int64ToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToIntPtr(0x80000000, &out))
            error("Int64ToIntPtr did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToIntPtr((-0x80000000ll - 1), &out))
            error("Int64ToIntPtr did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG_PTR *) __attribute__ ((unused)) = &Int64ToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLongPtr), HRESULT (*)(_In_ INT64, _Out_ LONG_PTR *)>::value)
            error("Int64ToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0, &out) != 0)
            error("Int64ToLongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0x7fffffff, &out) != 0)
            error("Int64ToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLongPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLongPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLongPtr changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLongPtr(0x80000000, &out))
            error("Int64ToLongPtr did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLongPtr((-0x80000000ll - 1), &out))
            error("Int64ToLongPtr did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &Int64ToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToPtrdiffT), HRESULT (*)(_In_ INT64, _Out_ ptrdiff_t *)>::value)
            error("Int64ToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0");
        if(out != 0)
            error("Int64ToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0x7fffffff, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToPtrdiffT(0x80000000, &out))
            error("Int64ToPtrdiffT did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToPtrdiffT((-0x80000000ll - 1), &out))
            error("Int64ToPtrdiffT did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ SSIZE_T *) __attribute__ ((unused)) = &Int64ToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSSIZET), HRESULT (*)(_In_ INT64, _Out_ SSIZE_T *)>::value)
            error("Int64ToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0, &out) != 0)
            error("Int64ToSSIZET failed to convert 0");
        if(out != 0)
            error("Int64ToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0x7fffffff, &out) != 0)
            error("Int64ToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToSSIZET changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToSSIZET failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToSSIZET changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSSIZET(0x80000000, &out))
            error("Int64ToSSIZET did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSSIZET((-0x80000000ll - 1), &out))
            error("Int64ToSSIZET did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_UIntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &UIntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToUInt), HRESULT (*)(_In_ UINT_PTR, _Out_ UINT *)>::value)
            error("UIntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0, &out) != 0)
            error("UIntPtrToUInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0xffffffff, &out) != 0)
            error("UIntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &UIntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToULong), HRESULT (*)(_In_ UINT_PTR, _Out_ ULONG *)>::value)
            error("UIntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0, &out) != 0)
            error("UIntPtrToULong failed to convert 0");
        if(out != 0)
            error("UIntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0xffffffff, &out) != 0)
            error("UIntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &UIntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToDWord), HRESULT (*)(_In_ UINT_PTR, _Out_ DWORD *)>::value)
            error("UIntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0, &out) != 0)
            error("UIntPtrToDWord failed to convert 0");
        if(out != 0)
            error("UIntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0xffffffff, &out) != 0)
            error("UIntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT *) __attribute__ ((unused)) = &UIntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt), HRESULT (*)(_In_ UINT_PTR, _Out_ INT *)>::value)
            error("UIntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0, &out) != 0)
            error("UIntPtrToInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0x7fffffff, &out) != 0)
            error("UIntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt(0x80000000, &out))
            error("UIntPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &UIntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLong), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG *)>::value)
            error("UIntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0, &out) != 0)
            error("UIntPtrToLong failed to convert 0");
        if(out != 0)
            error("UIntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0x7fffffff, &out) != 0)
            error("UIntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLong(0x80000000, &out))
            error("UIntPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &UIntPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt64), HRESULT (*)(_In_ UINT_PTR, _Out_ INT64 *)>::value)
            error("UIntPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0xffffffff, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToIntPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ INT_PTR *)>::value)
            error("UIntPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0x7fffffff, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToIntPtr(0x80000000, &out))
            error("UIntPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLongPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG_PTR *)>::value)
            error("UIntPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0x7fffffff, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLongPtr(0x80000000, &out))
            error("UIntPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToSSIZET), HRESULT (*)(_In_ UINT_PTR, _Out_ SSIZE_T *)>::value)
            error("UIntPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0x7fffffff, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToSSIZET(0x80000000, &out))
            error("UIntPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_SizeTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ UINT *) __attribute__ ((unused)) = &SizeTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToUInt), HRESULT (*)(_In_ size_t, _Out_ UINT *)>::value)
            error("SizeTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0, &out) != 0)
            error("SizeTToUInt failed to convert 0");
        if(out != 0)
            error("SizeTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0xffffffff, &out) != 0)
            error("SizeTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToUInt changed 0xffffffff to something else.");
    }

}

static void test_SizeTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ULONG *) __attribute__ ((unused)) = &SizeTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToULong), HRESULT (*)(_In_ size_t, _Out_ ULONG *)>::value)
            error("SizeTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0, &out) != 0)
            error("SizeTToULong failed to convert 0");
        if(out != 0)
            error("SizeTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0xffffffff, &out) != 0)
            error("SizeTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToULong changed 0xffffffff to something else.");
    }

}

static void test_SizeTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ DWORD *) __attribute__ ((unused)) = &SizeTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToDWord), HRESULT (*)(_In_ size_t, _Out_ DWORD *)>::value)
            error("SizeTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0, &out) != 0)
            error("SizeTToDWord failed to convert 0");
        if(out != 0)
            error("SizeTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0xffffffff, &out) != 0)
            error("SizeTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToDWord changed 0xffffffff to something else.");
    }

}

static void test_SizeTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT *) __attribute__ ((unused)) = &SizeTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt), HRESULT (*)(_In_ size_t, _Out_ INT *)>::value)
            error("SizeTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0, &out) != 0)
            error("SizeTToInt failed to convert 0");
        if(out != 0)
            error("SizeTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0x7fffffff, &out) != 0)
            error("SizeTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt(0x80000000, &out))
            error("SizeTToInt did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG *) __attribute__ ((unused)) = &SizeTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLong), HRESULT (*)(_In_ size_t, _Out_ LONG *)>::value)
            error("SizeTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0, &out) != 0)
            error("SizeTToLong failed to convert 0");
        if(out != 0)
            error("SizeTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0x7fffffff, &out) != 0)
            error("SizeTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLong(0x80000000, &out))
            error("SizeTToLong did not overflow when given 0x80000000");
    }

}

static void test_SizeTToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT64 *) __attribute__ ((unused)) = &SizeTToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt64), HRESULT (*)(_In_ size_t, _Out_ INT64 *)>::value)
            error("SizeTToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0, &out) != 0)
            error("SizeTToInt64 failed to convert 0");
        if(out != 0)
            error("SizeTToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0xffffffff, &out) != 0)
            error("SizeTToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToInt64 changed 0xffffffff to something else.");
    }

}

static void test_SizeTToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT_PTR *) __attribute__ ((unused)) = &SizeTToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToIntPtr), HRESULT (*)(_In_ size_t, _Out_ INT_PTR *)>::value)
            error("SizeTToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0, &out) != 0)
            error("SizeTToIntPtr failed to convert 0");
        if(out != 0)
            error("SizeTToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0x7fffffff, &out) != 0)
            error("SizeTToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToIntPtr(0x80000000, &out))
            error("SizeTToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG_PTR *) __attribute__ ((unused)) = &SizeTToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLongPtr), HRESULT (*)(_In_ size_t, _Out_ LONG_PTR *)>::value)
            error("SizeTToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0, &out) != 0)
            error("SizeTToLongPtr failed to convert 0");
        if(out != 0)
            error("SizeTToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0x7fffffff, &out) != 0)
            error("SizeTToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLongPtr(0x80000000, &out))
            error("SizeTToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_SizeTToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &SizeTToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToPtrdiffT), HRESULT (*)(_In_ size_t, _Out_ ptrdiff_t *)>::value)
            error("SizeTToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0");
        if(out != 0)
            error("SizeTToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0x7fffffff, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToPtrdiffT(0x80000000, &out))
            error("SizeTToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_SizeTToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ SSIZE_T *) __attribute__ ((unused)) = &SizeTToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToSSIZET), HRESULT (*)(_In_ size_t, _Out_ SSIZE_T *)>::value)
            error("SizeTToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0, &out) != 0)
            error("SizeTToSSIZET failed to convert 0");
        if(out != 0)
            error("SizeTToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0x7fffffff, &out) != 0)
            error("SizeTToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToSSIZET(0x80000000, &out))
            error("SizeTToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT *) __attribute__ ((unused)) = &DWordPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT *)>::value)
            error("DWordPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0, &out) != 0)
            error("DWordPtrToUInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0xffffffff, &out) != 0)
            error("DWordPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &DWordPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToULong), HRESULT (*)(_In_ DWORD_PTR, _Out_ ULONG *)>::value)
            error("DWordPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0, &out) != 0)
            error("DWordPtrToULong failed to convert 0");
        if(out != 0)
            error("DWordPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0xffffffff, &out) != 0)
            error("DWordPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &DWordPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value)
            error("DWordPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0, &out) != 0)
            error("DWordPtrToDWord failed to convert 0");
        if(out != 0)
            error("DWordPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0xffffffff, &out) != 0)
            error("DWordPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT *) __attribute__ ((unused)) = &DWordPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT *)>::value)
            error("DWordPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0, &out) != 0)
            error("DWordPtrToInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0x7fffffff, &out) != 0)
            error("DWordPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt(0x80000000, &out))
            error("DWordPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG *) __attribute__ ((unused)) = &DWordPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLong), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG *)>::value)
            error("DWordPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0, &out) != 0)
            error("DWordPtrToLong failed to convert 0");
        if(out != 0)
            error("DWordPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0x7fffffff, &out) != 0)
            error("DWordPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLong(0x80000000, &out))
            error("DWordPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &DWordPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt64), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT64 *)>::value)
            error("DWordPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0xffffffff, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT_PTR *)>::value)
            error("DWordPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0xffffffff, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT_PTR *)>::value)
            error("DWordPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0x7fffffff, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToIntPtr(0x80000000, &out))
            error("DWordPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLongPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG_PTR *)>::value)
            error("DWordPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0x7fffffff, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLongPtr(0x80000000, &out))
            error("DWordPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToPtrdiffT), HRESULT (*)(_In_ DWORD_PTR, _Out_ ptrdiff_t *)>::value)
            error("DWordPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0x7fffffff, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToPtrdiffT(0x80000000, &out))
            error("DWordPtrToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToSSIZET), HRESULT (*)(_In_ DWORD_PTR, _Out_ SSIZE_T *)>::value)
            error("DWordPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0x7fffffff, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToSSIZET(0x80000000, &out))
            error("DWordPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &ULongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT *)>::value)
            error("ULongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0, &out) != 0)
            error("ULongPtrToUInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0xffffffff, &out) != 0)
            error("ULongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &ULongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToULong), HRESULT (*)(_In_ ULONG_PTR, _Out_ ULONG *)>::value)
            error("ULongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0, &out) != 0)
            error("ULongPtrToULong failed to convert 0");
        if(out != 0)
            error("ULongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0xffffffff, &out) != 0)
            error("ULongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &ULongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToDWord), HRESULT (*)(_In_ ULONG_PTR, _Out_ DWORD *)>::value)
            error("ULongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0, &out) != 0)
            error("ULongPtrToDWord failed to convert 0");
        if(out != 0)
            error("ULongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0xffffffff, &out) != 0)
            error("ULongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &ULongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT *)>::value)
            error("ULongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0, &out) != 0)
            error("ULongPtrToInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0x7fffffff, &out) != 0)
            error("ULongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt(0x80000000, &out))
            error("ULongPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &ULongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLong), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG *)>::value)
            error("ULongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0, &out) != 0)
            error("ULongPtrToLong failed to convert 0");
        if(out != 0)
            error("ULongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0x7fffffff, &out) != 0)
            error("ULongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLong(0x80000000, &out))
            error("ULongPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &ULongPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt64), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT64 *)>::value)
            error("ULongPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0xffffffff, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT_PTR *)>::value)
            error("ULongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0xffffffff, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT_PTR *)>::value)
            error("ULongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0x7fffffff, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToIntPtr(0x80000000, &out))
            error("ULongPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLongPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG_PTR *)>::value)
            error("ULongPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0x7fffffff, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLongPtr(0x80000000, &out))
            error("ULongPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToPtrdiffT), HRESULT (*)(_In_ ULONG_PTR, _Out_ ptrdiff_t *)>::value)
            error("ULongPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToPtrdiffT(0x80000000, &out))
            error("ULongPtrToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToSSIZET), HRESULT (*)(_In_ ULONG_PTR, _Out_ SSIZE_T *)>::value)
            error("ULongPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0x7fffffff, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToSSIZET(0x80000000, &out))
            error("ULongPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_IntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &IntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUInt), HRESULT (*)(_In_ INT_PTR, _Out_ UINT *)>::value)
            error("IntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0, &out) != 0)
            error("IntPtrToUInt failed to convert 0");
        if(out != 0)
            error("IntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0x7fffffff, &out) != 0)
            error("IntPtrToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt((-0ll - 1), &out))
            error("IntPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &IntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG *)>::value)
            error("IntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0, &out) != 0)
            error("IntPtrToULong failed to convert 0");
        if(out != 0)
            error("IntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0x7fffffff, &out) != 0)
            error("IntPtrToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong((-0ll - 1), &out))
            error("IntPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &IntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWord), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD *)>::value)
            error("IntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0, &out) != 0)
            error("IntPtrToDWord failed to convert 0");
        if(out != 0)
            error("IntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0x7fffffff, &out) != 0)
            error("IntPtrToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord((-0ll - 1), &out))
            error("IntPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ INT *) __attribute__ ((unused)) = &IntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToInt), HRESULT (*)(_In_ INT_PTR, _Out_ INT *)>::value)
            error("IntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0, &out) != 0)
            error("IntPtrToInt failed to convert 0");
        if(out != 0)
            error("IntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0x7fffffff, &out) != 0)
            error("IntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_IntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &IntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToLong), HRESULT (*)(_In_ INT_PTR, _Out_ LONG *)>::value)
            error("IntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0, &out) != 0)
            error("IntPtrToLong failed to convert 0");
        if(out != 0)
            error("IntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0x7fffffff, &out) != 0)
            error("IntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_IntPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongLong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONGLONG *)>::value)
            error("IntPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0, &out) != 0)
            error("IntPtrToULongLong failed to convert 0");
        if(out != 0)
            error("IntPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0x7fffffff, &out) != 0)
            error("IntPtrToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongLong((-0ll - 1), &out))
            error("IntPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUIntPtr), HRESULT (*)(_In_ INT_PTR, _Out_ UINT_PTR *)>::value)
            error("IntPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0x7fffffff, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUIntPtr((-0ll - 1), &out))
            error("IntPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ size_t *) __attribute__ ((unused)) = &IntPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToSizeT), HRESULT (*)(_In_ INT_PTR, _Out_ size_t *)>::value)
            error("IntPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0, &out) != 0)
            error("IntPtrToSizeT failed to convert 0");
        if(out != 0)
            error("IntPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0x7fffffff, &out) != 0)
            error("IntPtrToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToSizeT((-0ll - 1), &out))
            error("IntPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWordPtr), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD_PTR *)>::value)
            error("IntPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0x7fffffff, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWordPtr((-0ll - 1), &out))
            error("IntPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongPtr), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG_PTR *)>::value)
            error("IntPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0x7fffffff, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongPtr((-0ll - 1), &out))
            error("IntPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &LongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUInt), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT *)>::value)
            error("LongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0, &out) != 0)
            error("LongPtrToUInt failed to convert 0");
        if(out != 0)
            error("LongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0x7fffffff, &out) != 0)
            error("LongPtrToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt((-0ll - 1), &out))
            error("LongPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &LongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG *)>::value)
            error("LongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0, &out) != 0)
            error("LongPtrToULong failed to convert 0");
        if(out != 0)
            error("LongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0x7fffffff, &out) != 0)
            error("LongPtrToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong((-0ll - 1), &out))
            error("LongPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &LongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWord), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD *)>::value)
            error("LongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0, &out) != 0)
            error("LongPtrToDWord failed to convert 0");
        if(out != 0)
            error("LongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0x7fffffff, &out) != 0)
            error("LongPtrToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord((-0ll - 1), &out))
            error("LongPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &LongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToInt), HRESULT (*)(_In_ LONG_PTR, _Out_ INT *)>::value)
            error("LongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0, &out) != 0)
            error("LongPtrToInt failed to convert 0");
        if(out != 0)
            error("LongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0x7fffffff, &out) != 0)
            error("LongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &LongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToLong), HRESULT (*)(_In_ LONG_PTR, _Out_ LONG *)>::value)
            error("LongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0, &out) != 0)
            error("LongPtrToLong failed to convert 0");
        if(out != 0)
            error("LongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0x7fffffff, &out) != 0)
            error("LongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongLong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONGLONG *)>::value)
            error("LongPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0, &out) != 0)
            error("LongPtrToULongLong failed to convert 0");
        if(out != 0)
            error("LongPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0x7fffffff, &out) != 0)
            error("LongPtrToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongLong((-0ll - 1), &out))
            error("LongPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT_PTR *)>::value)
            error("LongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0x7fffffff, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUIntPtr((-0ll - 1), &out))
            error("LongPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ size_t *) __attribute__ ((unused)) = &LongPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToSizeT), HRESULT (*)(_In_ LONG_PTR, _Out_ size_t *)>::value)
            error("LongPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0, &out) != 0)
            error("LongPtrToSizeT failed to convert 0");
        if(out != 0)
            error("LongPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0x7fffffff, &out) != 0)
            error("LongPtrToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToSizeT((-0ll - 1), &out))
            error("LongPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWordPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD_PTR *)>::value)
            error("LongPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0x7fffffff, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWordPtr((-0ll - 1), &out))
            error("LongPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG_PTR *)>::value)
            error("LongPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0x7fffffff, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongPtr((-0ll - 1), &out))
            error("LongPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ INT_PTR *)>::value)
            error("LongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0x7fffffff, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT *) __attribute__ ((unused)) = &PtrdiffTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT *)>::value)
            error("PtrdiffTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt((-0ll - 1), &out))
            error("PtrdiffTToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG *) __attribute__ ((unused)) = &PtrdiffTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULong), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG *)>::value)
            error("PtrdiffTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0, &out) != 0)
            error("PtrdiffTToULong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0x7fffffff, &out) != 0)
            error("PtrdiffTToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong((-0ll - 1), &out))
            error("PtrdiffTToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD *) __attribute__ ((unused)) = &PtrdiffTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWord), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD *)>::value)
            error("PtrdiffTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0x7fffffff, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord((-0ll - 1), &out))
            error("PtrdiffTToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ INT *) __attribute__ ((unused)) = &PtrdiffTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ INT *)>::value)
            error("PtrdiffTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0, &out) != 0)
            error("PtrdiffTToInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ LONG *) __attribute__ ((unused)) = &PtrdiffTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToLong), HRESULT (*)(_In_ ptrdiff_t, _Out_ LONG *)>::value)
            error("PtrdiffTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0, &out) != 0)
            error("PtrdiffTToLong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0x7fffffff, &out) != 0)
            error("PtrdiffTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT_PTR *) __attribute__ ((unused)) = &PtrdiffTToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUIntPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT_PTR *)>::value)
            error("PtrdiffTToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUIntPtr((-0ll - 1), &out))
            error("PtrdiffTToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ size_t *) __attribute__ ((unused)) = &PtrdiffTToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToSizeT), HRESULT (*)(_In_ ptrdiff_t, _Out_ size_t *)>::value)
            error("PtrdiffTToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0");
        if(out != 0)
            error("PtrdiffTToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0x7fffffff, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToSizeT((-0ll - 1), &out))
            error("PtrdiffTToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &PtrdiffTToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWordPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD_PTR *)>::value)
            error("PtrdiffTToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWordPtr((-0ll - 1), &out))
            error("PtrdiffTToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &PtrdiffTToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULongPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG_PTR *)>::value)
            error("PtrdiffTToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULongPtr((-0ll - 1), &out))
            error("PtrdiffTToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT *) __attribute__ ((unused)) = &SSIZETToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUInt), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT *)>::value)
            error("SSIZETToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0, &out) != 0)
            error("SSIZETToUInt failed to convert 0");
        if(out != 0)
            error("SSIZETToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0x7fffffff, &out) != 0)
            error("SSIZETToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt((-0ll - 1), &out))
            error("SSIZETToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG *) __attribute__ ((unused)) = &SSIZETToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULong), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG *)>::value)
            error("SSIZETToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0, &out) != 0)
            error("SSIZETToULong failed to convert 0");
        if(out != 0)
            error("SSIZETToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0x7fffffff, &out) != 0)
            error("SSIZETToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong((-0ll - 1), &out))
            error("SSIZETToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD *) __attribute__ ((unused)) = &SSIZETToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWord), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD *)>::value)
            error("SSIZETToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0, &out) != 0)
            error("SSIZETToDWord failed to convert 0");
        if(out != 0)
            error("SSIZETToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0x7fffffff, &out) != 0)
            error("SSIZETToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord((-0ll - 1), &out))
            error("SSIZETToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT *) __attribute__ ((unused)) = &SSIZETToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToInt), HRESULT (*)(_In_ SSIZE_T, _Out_ INT *)>::value)
            error("SSIZETToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0, &out) != 0)
            error("SSIZETToInt failed to convert 0");
        if(out != 0)
            error("SSIZETToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0x7fffffff, &out) != 0)
            error("SSIZETToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_SSIZETToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ LONG *) __attribute__ ((unused)) = &SSIZETToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToLong), HRESULT (*)(_In_ SSIZE_T, _Out_ LONG *)>::value)
            error("SSIZETToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0, &out) != 0)
            error("SSIZETToLong failed to convert 0");
        if(out != 0)
            error("SSIZETToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0x7fffffff, &out) != 0)
            error("SSIZETToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_SSIZETToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT_PTR *) __attribute__ ((unused)) = &SSIZETToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT_PTR *)>::value)
            error("SSIZETToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0x7fffffff, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUIntPtr((-0ll - 1), &out))
            error("SSIZETToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ size_t *) __attribute__ ((unused)) = &SSIZETToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToSizeT), HRESULT (*)(_In_ SSIZE_T, _Out_ size_t *)>::value)
            error("SSIZETToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0, &out) != 0)
            error("SSIZETToSizeT failed to convert 0");
        if(out != 0)
            error("SSIZETToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0x7fffffff, &out) != 0)
            error("SSIZETToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToSizeT((-0ll - 1), &out))
            error("SSIZETToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &SSIZETToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWordPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD_PTR *)>::value)
            error("SSIZETToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0x7fffffff, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWordPtr((-0ll - 1), &out))
            error("SSIZETToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &SSIZETToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULongPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG_PTR *)>::value)
            error("SSIZETToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0x7fffffff, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULongPtr((-0ll - 1), &out))
            error("SSIZETToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT_PTR *) __attribute__ ((unused)) = &SSIZETToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ INT_PTR *)>::value)
            error("SSIZETToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0x7fffffff, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void tests_conversions()
{
    test_UShortToUChar();
    test_UShortToByte();
    test_UShortToChar();
    test_UShortToShort();
    test_WordToUChar();
    test_WordToByte();
    test_WordToChar();
    test_WordToShort();
    test_ShortToUChar();
    test_ShortToByte();
    test_ShortToChar();
    test_ShortToUShort();
    test_ShortToWord();
    test_UIntToUChar();
    test_UIntToByte();
    test_UIntToChar();
    test_UIntToUShort();
    test_UIntToWord();
    test_UIntToShort();
    test_UIntToInt();
    test_UIntToLong();
    test_UIntToIntPtr();
    test_UIntToLongPtr();
    test_UIntToPtrdiffT();
    test_UIntToSSIZET();
    test_ULongToUChar();
    test_ULongToByte();
    test_ULongToChar();
    test_ULongToUShort();
    test_ULongToWord();
    test_ULongToShort();
    test_ULongToUInt();
    test_ULongToInt();
    test_ULongToLong();
    test_ULongToUIntPtr();
    test_ULongToIntPtr();
    test_ULongToLongPtr();
    test_ULongToPtrdiffT();
    test_ULongToSSIZET();
    test_DWordToUChar();
    test_DWordToByte();
    test_DWordToChar();
    test_DWordToUShort();
    test_DWordToWord();
    test_DWordToShort();
    test_DWordToUInt();
    test_DWordToInt();
    test_DWordToLong();
    test_DWordToUIntPtr();
    test_DWordToIntPtr();
    test_DWordToLongPtr();
    test_DWordToPtrdiffT();
    test_DWordToSSIZET();
    test_IntToUChar();
    test_IntToByte();
    test_IntToChar();
    test_IntToUShort();
    test_IntToWord();
    test_IntToShort();
    test_IntToUInt();
    test_IntToULong();
    test_IntToDWord();
    test_IntToULongLong();
    test_IntToUIntPtr();
    test_IntToSizeT();
    test_IntToDWordPtr();
    test_IntToULongPtr();
    test_LongToUChar();
    test_LongToByte();
    test_LongToChar();
    test_LongToUShort();
    test_LongToWord();
    test_LongToShort();
    test_LongToUInt();
    test_LongToULong();
    test_LongToDWord();
    test_LongToInt();
    test_LongToULongLong();
    test_LongToUIntPtr();
    test_LongToSizeT();
    test_LongToDWordPtr();
    test_LongToULongPtr();
    test_LongToIntPtr();
    test_LongToPtrdiffT();
    test_ULongLongToUInt();
    test_ULongLongToULong();
    test_ULongLongToDWord();
    test_ULongLongToInt();
    test_ULongLongToLong();
    test_ULongLongToInt64();
    test_ULongLongToUIntPtr();
    test_ULongLongToSizeT();
    test_ULongLongToDWordPtr();
    test_ULongLongToULongPtr();
    test_ULongLongToIntPtr();
    test_ULongLongToLongPtr();
    test_ULongLongToPtrdiffT();
    test_ULongLongToSSIZET();
    test_Int64ToUInt();
    test_Int64ToULong();
    test_Int64ToDWord();
    test_Int64ToInt();
    test_Int64ToLong();
    test_Int64ToULongLong();
    test_Int64ToUIntPtr();
    test_Int64ToSizeT();
    test_Int64ToDWordPtr();
    test_Int64ToULongPtr();
    test_Int64ToIntPtr();
    test_Int64ToLongPtr();
    test_Int64ToPtrdiffT();
    test_Int64ToSSIZET();
    test_UIntPtrToUInt();
    test_UIntPtrToULong();
    test_UIntPtrToDWord();
    test_UIntPtrToInt();
    test_UIntPtrToLong();
    test_UIntPtrToInt64();
    test_UIntPtrToIntPtr();
    test_UIntPtrToLongPtr();
    test_UIntPtrToSSIZET();
    test_SizeTToUInt();
    test_SizeTToULong();
    test_SizeTToDWord();
    test_SizeTToInt();
    test_SizeTToLong();
    test_SizeTToInt64();
    test_SizeTToIntPtr();
    test_SizeTToLongPtr();
    test_SizeTToPtrdiffT();
    test_SizeTToSSIZET();
    test_DWordPtrToUInt();
    test_DWordPtrToULong();
    test_DWordPtrToDWord();
    test_DWordPtrToInt();
    test_DWordPtrToLong();
    test_DWordPtrToInt64();
    test_DWordPtrToUIntPtr();
    test_DWordPtrToIntPtr();
    test_DWordPtrToLongPtr();
    test_DWordPtrToPtrdiffT();
    test_DWordPtrToSSIZET();
    test_ULongPtrToUInt();
    test_ULongPtrToULong();
    test_ULongPtrToDWord();
    test_ULongPtrToInt();
    test_ULongPtrToLong();
    test_ULongPtrToInt64();
    test_ULongPtrToUIntPtr();
    test_ULongPtrToIntPtr();
    test_ULongPtrToLongPtr();
    test_ULongPtrToPtrdiffT();
    test_ULongPtrToSSIZET();
    test_IntPtrToUInt();
    test_IntPtrToULong();
    test_IntPtrToDWord();
    test_IntPtrToInt();
    test_IntPtrToLong();
    test_IntPtrToULongLong();
    test_IntPtrToUIntPtr();
    test_IntPtrToSizeT();
    test_IntPtrToDWordPtr();
    test_IntPtrToULongPtr();
    test_LongPtrToUInt();
    test_LongPtrToULong();
    test_LongPtrToDWord();
    test_LongPtrToInt();
    test_LongPtrToLong();
    test_LongPtrToULongLong();
    test_LongPtrToUIntPtr();
    test_LongPtrToSizeT();
    test_LongPtrToDWordPtr();
    test_LongPtrToULongPtr();
    test_LongPtrToIntPtr();
    test_PtrdiffTToUInt();
    test_PtrdiffTToULong();
    test_PtrdiffTToDWord();
    test_PtrdiffTToInt();
    test_PtrdiffTToLong();
    test_PtrdiffTToUIntPtr();
    test_PtrdiffTToSizeT();
    test_PtrdiffTToDWordPtr();
    test_PtrdiffTToULongPtr();
    test_SSIZETToUInt();
    test_SSIZETToULong();
    test_SSIZETToDWord();
    test_SSIZETToInt();
    test_SSIZETToLong();
    test_SSIZETToUIntPtr();
    test_SSIZETToSizeT();
    test_SSIZETToDWordPtr();
    test_SSIZETToULongPtr();
    test_SSIZETToIntPtr();
}

static void tests_auto()
{
    tests_types();
    tests_conversions();
}

#else /* __CHAR_UNSIGNED__ */
static void test_UCHAR_eq_uint8_t()
{
    if(sizeof(UCHAR) != 1)
        error("UCHAR is actually %d bytes", (int)sizeof(UCHAR));
    UCHAR x = 0;
    if(!((UCHAR)(x - 1) > x))
        error("UCHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UCHAR>::value)
        error("UCHAR is a pointer");
    #endif
}

static void test_BYTE_eq_uint8_t()
{
    if(sizeof(BYTE) != 1)
        error("BYTE is actually %d bytes", (int)sizeof(BYTE));
    BYTE x = 0;
    if(!((BYTE)(x - 1) > x))
        error("BYTE sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<BYTE>::value)
        error("BYTE is a pointer");
    #endif
}

static void test_CHAR_eq_int8_t()
{
    if(sizeof(CHAR) != 1)
        error("CHAR is actually %d bytes", (int)sizeof(CHAR));
    CHAR x = 0;
    if(!((CHAR)(x - 1) < x))
        error("CHAR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<CHAR>::value)
        error("CHAR is a pointer");
    #endif
}

static void test_USHORT_eq_uint16_t()
{
    if(sizeof(USHORT) != 2)
        error("USHORT is actually %d bytes", (int)sizeof(USHORT));
    USHORT x = 0;
    if(!((USHORT)(x - 1) > x))
        error("USHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<USHORT>::value)
        error("USHORT is a pointer");
    #endif
}

static void test_WORD_eq_uint16_t()
{
    if(sizeof(WORD) != 2)
        error("WORD is actually %d bytes", (int)sizeof(WORD));
    WORD x = 0;
    if(!((WORD)(x - 1) > x))
        error("WORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<WORD>::value)
        error("WORD is a pointer");
    #endif
}

static void test_SHORT_eq_int16_t()
{
    if(sizeof(SHORT) != 2)
        error("SHORT is actually %d bytes", (int)sizeof(SHORT));
    SHORT x = 0;
    if(!((SHORT)(x - 1) < x))
        error("SHORT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SHORT>::value)
        error("SHORT is a pointer");
    #endif
}

static void test_UINT_eq_uint32_t()
{
    if(sizeof(UINT) != 4)
        error("UINT is actually %d bytes", (int)sizeof(UINT));
    UINT x = 0;
    if(!((UINT)(x - 1) > x))
        error("UINT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT>::value)
        error("UINT is a pointer");
    #endif
}

static void test_ULONG_eq_uint32_t()
{
    if(sizeof(ULONG) != 4)
        error("ULONG is actually %d bytes", (int)sizeof(ULONG));
    ULONG x = 0;
    if(!((ULONG)(x - 1) > x))
        error("ULONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG>::value)
        error("ULONG is a pointer");
    #endif
}

static void test_DWORD_eq_uint32_t()
{
    if(sizeof(DWORD) != 4)
        error("DWORD is actually %d bytes", (int)sizeof(DWORD));
    DWORD x = 0;
    if(!((DWORD)(x - 1) > x))
        error("DWORD sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD>::value)
        error("DWORD is a pointer");
    #endif
}

static void test_INT_eq_int32_t()
{
    if(sizeof(INT) != 4)
        error("INT is actually %d bytes", (int)sizeof(INT));
    INT x = 0;
    if(!((INT)(x - 1) < x))
        error("INT sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT>::value)
        error("INT is a pointer");
    #endif
}

static void test_LONG_eq_int32_t()
{
    if(sizeof(LONG) != 4)
        error("LONG is actually %d bytes", (int)sizeof(LONG));
    LONG x = 0;
    if(!((LONG)(x - 1) < x))
        error("LONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG>::value)
        error("LONG is a pointer");
    #endif
}

static void test_ULONGLONG_eq_uint64_t()
{
    if(sizeof(ULONGLONG) != 8)
        error("ULONGLONG is actually %d bytes", (int)sizeof(ULONGLONG));
    ULONGLONG x = 0;
    if(!((ULONGLONG)(x - 1) > x))
        error("ULONGLONG sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONGLONG>::value)
        error("ULONGLONG is a pointer");
    #endif
}

static void test_INT64_eq_int64_t()
{
    if(sizeof(INT64) != 8)
        error("INT64 is actually %d bytes", (int)sizeof(INT64));
    INT64 x = 0;
    if(!((INT64)(x - 1) < x))
        error("INT64 sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT64>::value)
        error("INT64 is a pointer");
    #endif
}

static void test_UINT_PTR_eq_uint32_t()
{
    if(sizeof(UINT_PTR) != 4)
        error("UINT_PTR is actually %d bytes", (int)sizeof(UINT_PTR));
    UINT_PTR x = 0;
    if(!((UINT_PTR)(x - 1) > x))
        error("UINT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<UINT_PTR>::value)
        error("UINT_PTR is a pointer");
    #endif
}

static void test_size_t_eq_uint32_t()
{
    if(sizeof(size_t) != 4)
        error("size_t is actually %d bytes", (int)sizeof(size_t));
    size_t x = 0;
    if(!((size_t)(x - 1) > x))
        error("size_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<size_t>::value)
        error("size_t is a pointer");
    #endif
}

static void test_DWORD_PTR_eq_uint32_t()
{
    if(sizeof(DWORD_PTR) != 4)
        error("DWORD_PTR is actually %d bytes", (int)sizeof(DWORD_PTR));
    DWORD_PTR x = 0;
    if(!((DWORD_PTR)(x - 1) > x))
        error("DWORD_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<DWORD_PTR>::value)
        error("DWORD_PTR is a pointer");
    #endif
}

static void test_ULONG_PTR_eq_uint32_t()
{
    if(sizeof(ULONG_PTR) != 4)
        error("ULONG_PTR is actually %d bytes", (int)sizeof(ULONG_PTR));
    ULONG_PTR x = 0;
    if(!((ULONG_PTR)(x - 1) > x))
        error("ULONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ULONG_PTR>::value)
        error("ULONG_PTR is a pointer");
    #endif
}

static void test_INT_PTR_eq_int32_t()
{
    if(sizeof(INT_PTR) != 4)
        error("INT_PTR is actually %d bytes", (int)sizeof(INT_PTR));
    INT_PTR x = 0;
    if(!((INT_PTR)(x - 1) < x))
        error("INT_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<INT_PTR>::value)
        error("INT_PTR is a pointer");
    #endif
}

static void test_LONG_PTR_eq_int32_t()
{
    if(sizeof(LONG_PTR) != 4)
        error("LONG_PTR is actually %d bytes", (int)sizeof(LONG_PTR));
    LONG_PTR x = 0;
    if(!((LONG_PTR)(x - 1) < x))
        error("LONG_PTR sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<LONG_PTR>::value)
        error("LONG_PTR is a pointer");
    #endif
}

static void test_ptrdiff_t_eq_int32_t()
{
    if(sizeof(ptrdiff_t) != 4)
        error("ptrdiff_t is actually %d bytes", (int)sizeof(ptrdiff_t));
    ptrdiff_t x = 0;
    if(!((ptrdiff_t)(x - 1) < x))
        error("ptrdiff_t sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<ptrdiff_t>::value)
        error("ptrdiff_t is a pointer");
    #endif
}

static void test_SSIZE_T_eq_int32_t()
{
    if(sizeof(SSIZE_T) != 4)
        error("SSIZE_T is actually %d bytes", (int)sizeof(SSIZE_T));
    SSIZE_T x = 0;
    if(!((SSIZE_T)(x - 1) < x))
        error("SSIZE_T sign check failed");
    #ifdef __cplusplus
    if(std::is_pointer<SSIZE_T>::value)
        error("SSIZE_T is a pointer");
    #endif
}

static void tests_types()
{
    test_UCHAR_eq_uint8_t();
    test_BYTE_eq_uint8_t();
    test_CHAR_eq_int8_t();
    test_USHORT_eq_uint16_t();
    test_WORD_eq_uint16_t();
    test_SHORT_eq_int16_t();
    test_UINT_eq_uint32_t();
    test_ULONG_eq_uint32_t();
    test_DWORD_eq_uint32_t();
    test_INT_eq_int32_t();
    test_LONG_eq_int32_t();
    test_ULONGLONG_eq_uint64_t();
    test_INT64_eq_int64_t();
    test_UINT_PTR_eq_uint32_t();
    test_size_t_eq_uint32_t();
    test_DWORD_PTR_eq_uint32_t();
    test_ULONG_PTR_eq_uint32_t();
    test_INT_PTR_eq_int32_t();
    test_LONG_PTR_eq_int32_t();
    test_ptrdiff_t_eq_int32_t();
    test_SSIZE_T_eq_int32_t();
}

static void test_UShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &UShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToUChar), HRESULT (*)(_In_ USHORT, _Out_ UCHAR *)>::value)
            error("UShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0, &out) != 0)
            error("UShortToUChar failed to convert 0");
        if(out != 0)
            error("UShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToUChar(0xff, &out) != 0)
            error("UShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToUChar(0x100, &out))
            error("UShortToUChar did not overflow when given 0x100");
    }

}

static void test_UShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ BYTE *) __attribute__ ((unused)) = &UShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToByte), HRESULT (*)(_In_ USHORT, _Out_ BYTE *)>::value)
            error("UShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0, &out) != 0)
            error("UShortToByte failed to convert 0");
        if(out != 0)
            error("UShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToByte(0xff, &out) != 0)
            error("UShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("UShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToByte(0x100, &out))
            error("UShortToByte did not overflow when given 0x100");
    }

}

static void test_UShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ CHAR *) __attribute__ ((unused)) = &UShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToChar), HRESULT (*)(_In_ USHORT, _Out_ CHAR *)>::value)
            error("UShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0, &out) != 0)
            error("UShortToChar failed to convert 0");
        if(out != 0)
            error("UShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToChar(0x7f, &out) != 0)
            error("UShortToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("UShortToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToChar(0x80, &out))
            error("UShortToChar did not overflow when given 0x80");
    }

}

static void test_UShortToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ USHORT, _Out_ SHORT *) __attribute__ ((unused)) = &UShortToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UShortToShort), HRESULT (*)(_In_ USHORT, _Out_ SHORT *)>::value)
            error("UShortToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0, &out) != 0)
            error("UShortToShort failed to convert 0");
        if(out != 0)
            error("UShortToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UShortToShort(0x7fff, &out) != 0)
            error("UShortToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UShortToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UShortToShort(0x8000, &out))
            error("UShortToShort did not overflow when given 0x8000");
    }

}

static void test_WordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ UCHAR *) __attribute__ ((unused)) = &WordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToUChar), HRESULT (*)(_In_ WORD, _Out_ UCHAR *)>::value)
            error("WordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0, &out) != 0)
            error("WordToUChar failed to convert 0");
        if(out != 0)
            error("WordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToUChar(0xff, &out) != 0)
            error("WordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("WordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToUChar(0x100, &out))
            error("WordToUChar did not overflow when given 0x100");
    }

}

static void test_WordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ BYTE *) __attribute__ ((unused)) = &WordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToByte), HRESULT (*)(_In_ WORD, _Out_ BYTE *)>::value)
            error("WordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToByte(0, &out) != 0)
            error("WordToByte failed to convert 0");
        if(out != 0)
            error("WordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToByte(0xff, &out) != 0)
            error("WordToByte failed to convert 0xff");
        if(out != 0xff)
            error("WordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToByte(0x100, &out))
            error("WordToByte did not overflow when given 0x100");
    }

}

static void test_WordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ CHAR *) __attribute__ ((unused)) = &WordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToChar), HRESULT (*)(_In_ WORD, _Out_ CHAR *)>::value)
            error("WordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToChar(0, &out) != 0)
            error("WordToChar failed to convert 0");
        if(out != 0)
            error("WordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToChar(0x7f, &out) != 0)
            error("WordToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("WordToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToChar(0x80, &out))
            error("WordToChar did not overflow when given 0x80");
    }

}

static void test_WordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ WORD, _Out_ SHORT *) __attribute__ ((unused)) = &WordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&WordToShort), HRESULT (*)(_In_ WORD, _Out_ SHORT *)>::value)
            error("WordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(WordToShort(0, &out) != 0)
            error("WordToShort failed to convert 0");
        if(out != 0)
            error("WordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(WordToShort(0x7fff, &out) != 0)
            error("WordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("WordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != WordToShort(0x8000, &out))
            error("WordToShort did not overflow when given 0x8000");
    }

}

static void test_ShortToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ UCHAR *) __attribute__ ((unused)) = &ShortToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUChar), HRESULT (*)(_In_ SHORT, _Out_ UCHAR *)>::value)
            error("ShortToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0, &out) != 0)
            error("ShortToUChar failed to convert 0");
        if(out != 0)
            error("ShortToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUChar(0xff, &out) != 0)
            error("ShortToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ShortToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar(0x100, &out))
            error("ShortToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUChar((-0ll - 1), &out))
            error("ShortToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ BYTE *) __attribute__ ((unused)) = &ShortToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToByte), HRESULT (*)(_In_ SHORT, _Out_ BYTE *)>::value)
            error("ShortToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0, &out) != 0)
            error("ShortToByte failed to convert 0");
        if(out != 0)
            error("ShortToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToByte(0xff, &out) != 0)
            error("ShortToByte failed to convert 0xff");
        if(out != 0xff)
            error("ShortToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte(0x100, &out))
            error("ShortToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToByte((-0ll - 1), &out))
            error("ShortToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ CHAR *) __attribute__ ((unused)) = &ShortToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToChar), HRESULT (*)(_In_ SHORT, _Out_ CHAR *)>::value)
            error("ShortToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0, &out) != 0)
            error("ShortToChar failed to convert 0");
        if(out != 0)
            error("ShortToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar(0x7f, &out) != 0)
            error("ShortToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("ShortToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(ShortToChar((-0x7fll - 1), &out) != 0)
            error("ShortToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("ShortToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar(0x80, &out))
            error("ShortToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToChar((-0x80ll - 1), &out))
            error("ShortToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_ShortToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ USHORT *) __attribute__ ((unused)) = &ShortToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToUShort), HRESULT (*)(_In_ SHORT, _Out_ USHORT *)>::value)
            error("ShortToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0, &out) != 0)
            error("ShortToUShort failed to convert 0");
        if(out != 0)
            error("ShortToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToUShort(0x7fff, &out) != 0)
            error("ShortToUShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToUShort changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToUShort((-0ll - 1), &out))
            error("ShortToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_ShortToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SHORT, _Out_ WORD *) __attribute__ ((unused)) = &ShortToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ShortToWord), HRESULT (*)(_In_ SHORT, _Out_ WORD *)>::value)
            error("ShortToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0, &out) != 0)
            error("ShortToWord failed to convert 0");
        if(out != 0)
            error("ShortToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ShortToWord(0x7fff, &out) != 0)
            error("ShortToWord failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ShortToWord changed 0x7fff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ShortToWord((-0ll - 1), &out))
            error("ShortToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_UIntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ UCHAR *) __attribute__ ((unused)) = &UIntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUChar), HRESULT (*)(_In_ UINT, _Out_ UCHAR *)>::value)
            error("UIntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0, &out) != 0)
            error("UIntToUChar failed to convert 0");
        if(out != 0)
            error("UIntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUChar(0xff, &out) != 0)
            error("UIntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("UIntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUChar(0x100, &out))
            error("UIntToUChar did not overflow when given 0x100");
    }

}

static void test_UIntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ BYTE *) __attribute__ ((unused)) = &UIntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToByte), HRESULT (*)(_In_ UINT, _Out_ BYTE *)>::value)
            error("UIntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0, &out) != 0)
            error("UIntToByte failed to convert 0");
        if(out != 0)
            error("UIntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToByte(0xff, &out) != 0)
            error("UIntToByte failed to convert 0xff");
        if(out != 0xff)
            error("UIntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToByte(0x100, &out))
            error("UIntToByte did not overflow when given 0x100");
    }

}

static void test_UIntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ CHAR *) __attribute__ ((unused)) = &UIntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToChar), HRESULT (*)(_In_ UINT, _Out_ CHAR *)>::value)
            error("UIntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0, &out) != 0)
            error("UIntToChar failed to convert 0");
        if(out != 0)
            error("UIntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToChar(0x7f, &out) != 0)
            error("UIntToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("UIntToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToChar(0x80, &out))
            error("UIntToChar did not overflow when given 0x80");
    }

}

static void test_UIntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ USHORT *) __attribute__ ((unused)) = &UIntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToUShort), HRESULT (*)(_In_ UINT, _Out_ USHORT *)>::value)
            error("UIntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0, &out) != 0)
            error("UIntToUShort failed to convert 0");
        if(out != 0)
            error("UIntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToUShort(0xffff, &out) != 0)
            error("UIntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToUShort(0x10000, &out))
            error("UIntToUShort did not overflow when given 0x10000");
    }

}

static void test_UIntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ WORD *) __attribute__ ((unused)) = &UIntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToWord), HRESULT (*)(_In_ UINT, _Out_ WORD *)>::value)
            error("UIntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0, &out) != 0)
            error("UIntToWord failed to convert 0");
        if(out != 0)
            error("UIntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToWord(0xffff, &out) != 0)
            error("UIntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("UIntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToWord(0x10000, &out))
            error("UIntToWord did not overflow when given 0x10000");
    }

}

static void test_UIntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SHORT *) __attribute__ ((unused)) = &UIntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToShort), HRESULT (*)(_In_ UINT, _Out_ SHORT *)>::value)
            error("UIntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0, &out) != 0)
            error("UIntToShort failed to convert 0");
        if(out != 0)
            error("UIntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToShort(0x7fff, &out) != 0)
            error("UIntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("UIntToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToShort(0x8000, &out))
            error("UIntToShort did not overflow when given 0x8000");
    }

}

static void test_UIntToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT *) __attribute__ ((unused)) = &UIntToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToInt), HRESULT (*)(_In_ UINT, _Out_ INT *)>::value)
            error("UIntToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0, &out) != 0)
            error("UIntToInt failed to convert 0");
        if(out != 0)
            error("UIntToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToInt(0x7fffffff, &out) != 0)
            error("UIntToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToInt(0x80000000, &out))
            error("UIntToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG *) __attribute__ ((unused)) = &UIntToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLong), HRESULT (*)(_In_ UINT, _Out_ LONG *)>::value)
            error("UIntToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0, &out) != 0)
            error("UIntToLong failed to convert 0");
        if(out != 0)
            error("UIntToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLong(0x7fffffff, &out) != 0)
            error("UIntToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLong(0x80000000, &out))
            error("UIntToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToIntPtr), HRESULT (*)(_In_ UINT, _Out_ INT_PTR *)>::value)
            error("UIntToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0, &out) != 0)
            error("UIntToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToIntPtr(0x7fffffff, &out) != 0)
            error("UIntToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToIntPtr(0x80000000, &out))
            error("UIntToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToLongPtr), HRESULT (*)(_In_ UINT, _Out_ LONG_PTR *)>::value)
            error("UIntToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0, &out) != 0)
            error("UIntToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToLongPtr(0x7fffffff, &out) != 0)
            error("UIntToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToLongPtr(0x80000000, &out))
            error("UIntToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &UIntToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToPtrdiffT), HRESULT (*)(_In_ UINT, _Out_ ptrdiff_t *)>::value)
            error("UIntToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0");
        if(out != 0)
            error("UIntToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToPtrdiffT(0x7fffffff, &out) != 0)
            error("UIntToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToPtrdiffT(0x80000000, &out))
            error("UIntToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_UIntToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntToSSIZET), HRESULT (*)(_In_ UINT, _Out_ SSIZE_T *)>::value)
            error("UIntToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0, &out) != 0)
            error("UIntToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntToSSIZET(0x7fffffff, &out) != 0)
            error("UIntToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntToSSIZET(0x80000000, &out))
            error("UIntToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_ULongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UCHAR *) __attribute__ ((unused)) = &ULongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUChar), HRESULT (*)(_In_ ULONG, _Out_ UCHAR *)>::value)
            error("ULongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0, &out) != 0)
            error("ULongToUChar failed to convert 0");
        if(out != 0)
            error("ULongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUChar(0xff, &out) != 0)
            error("ULongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("ULongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUChar(0x100, &out))
            error("ULongToUChar did not overflow when given 0x100");
    }

}

static void test_ULongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ BYTE *) __attribute__ ((unused)) = &ULongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToByte), HRESULT (*)(_In_ ULONG, _Out_ BYTE *)>::value)
            error("ULongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0, &out) != 0)
            error("ULongToByte failed to convert 0");
        if(out != 0)
            error("ULongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToByte(0xff, &out) != 0)
            error("ULongToByte failed to convert 0xff");
        if(out != 0xff)
            error("ULongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToByte(0x100, &out))
            error("ULongToByte did not overflow when given 0x100");
    }

}

static void test_ULongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ CHAR *) __attribute__ ((unused)) = &ULongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToChar), HRESULT (*)(_In_ ULONG, _Out_ CHAR *)>::value)
            error("ULongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0, &out) != 0)
            error("ULongToChar failed to convert 0");
        if(out != 0)
            error("ULongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToChar(0x7f, &out) != 0)
            error("ULongToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("ULongToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToChar(0x80, &out))
            error("ULongToChar did not overflow when given 0x80");
    }

}

static void test_ULongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ USHORT *) __attribute__ ((unused)) = &ULongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUShort), HRESULT (*)(_In_ ULONG, _Out_ USHORT *)>::value)
            error("ULongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0, &out) != 0)
            error("ULongToUShort failed to convert 0");
        if(out != 0)
            error("ULongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUShort(0xffff, &out) != 0)
            error("ULongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToUShort(0x10000, &out))
            error("ULongToUShort did not overflow when given 0x10000");
    }

}

static void test_ULongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ WORD *) __attribute__ ((unused)) = &ULongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToWord), HRESULT (*)(_In_ ULONG, _Out_ WORD *)>::value)
            error("ULongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0, &out) != 0)
            error("ULongToWord failed to convert 0");
        if(out != 0)
            error("ULongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToWord(0xffff, &out) != 0)
            error("ULongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("ULongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToWord(0x10000, &out))
            error("ULongToWord did not overflow when given 0x10000");
    }

}

static void test_ULongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SHORT *) __attribute__ ((unused)) = &ULongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToShort), HRESULT (*)(_In_ ULONG, _Out_ SHORT *)>::value)
            error("ULongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0, &out) != 0)
            error("ULongToShort failed to convert 0");
        if(out != 0)
            error("ULongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToShort(0x7fff, &out) != 0)
            error("ULongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("ULongToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToShort(0x8000, &out))
            error("ULongToShort did not overflow when given 0x8000");
    }

}

static void test_ULongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUInt), HRESULT (*)(_In_ ULONG, _Out_ UINT *)>::value)
            error("ULongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0, &out) != 0)
            error("ULongToUInt failed to convert 0");
        if(out != 0)
            error("ULongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUInt(0xffffffff, &out) != 0)
            error("ULongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT *) __attribute__ ((unused)) = &ULongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToInt), HRESULT (*)(_In_ ULONG, _Out_ INT *)>::value)
            error("ULongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0, &out) != 0)
            error("ULongToInt failed to convert 0");
        if(out != 0)
            error("ULongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToInt(0x7fffffff, &out) != 0)
            error("ULongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToInt(0x80000000, &out))
            error("ULongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLong), HRESULT (*)(_In_ ULONG, _Out_ LONG *)>::value)
            error("ULongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0, &out) != 0)
            error("ULongToLong failed to convert 0");
        if(out != 0)
            error("ULongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLong(0x7fffffff, &out) != 0)
            error("ULongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLong(0x80000000, &out))
            error("ULongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToUIntPtr), HRESULT (*)(_In_ ULONG, _Out_ UINT_PTR *)>::value)
            error("ULongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0, &out) != 0)
            error("ULongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToIntPtr), HRESULT (*)(_In_ ULONG, _Out_ INT_PTR *)>::value)
            error("ULongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0, &out) != 0)
            error("ULongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToIntPtr(0x7fffffff, &out) != 0)
            error("ULongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToIntPtr(0x80000000, &out))
            error("ULongToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToLongPtr), HRESULT (*)(_In_ ULONG, _Out_ LONG_PTR *)>::value)
            error("ULongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0, &out) != 0)
            error("ULongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToLongPtr(0x7fffffff, &out) != 0)
            error("ULongToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToLongPtr(0x80000000, &out))
            error("ULongToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToPtrdiffT), HRESULT (*)(_In_ ULONG, _Out_ ptrdiff_t *)>::value)
            error("ULongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToPtrdiffT(0x80000000, &out))
            error("ULongToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongToSSIZET), HRESULT (*)(_In_ ULONG, _Out_ SSIZE_T *)>::value)
            error("ULongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0, &out) != 0)
            error("ULongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongToSSIZET(0x7fffffff, &out) != 0)
            error("ULongToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongToSSIZET(0x80000000, &out))
            error("ULongToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_DWordToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UCHAR *) __attribute__ ((unused)) = &DWordToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUChar), HRESULT (*)(_In_ DWORD, _Out_ UCHAR *)>::value)
            error("DWordToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0, &out) != 0)
            error("DWordToUChar failed to convert 0");
        if(out != 0)
            error("DWordToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUChar(0xff, &out) != 0)
            error("DWordToUChar failed to convert 0xff");
        if(out != 0xff)
            error("DWordToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUChar(0x100, &out))
            error("DWordToUChar did not overflow when given 0x100");
    }

}

static void test_DWordToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ BYTE *) __attribute__ ((unused)) = &DWordToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToByte), HRESULT (*)(_In_ DWORD, _Out_ BYTE *)>::value)
            error("DWordToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0, &out) != 0)
            error("DWordToByte failed to convert 0");
        if(out != 0)
            error("DWordToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToByte(0xff, &out) != 0)
            error("DWordToByte failed to convert 0xff");
        if(out != 0xff)
            error("DWordToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToByte(0x100, &out))
            error("DWordToByte did not overflow when given 0x100");
    }

}

static void test_DWordToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ CHAR *) __attribute__ ((unused)) = &DWordToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToChar), HRESULT (*)(_In_ DWORD, _Out_ CHAR *)>::value)
            error("DWordToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0, &out) != 0)
            error("DWordToChar failed to convert 0");
        if(out != 0)
            error("DWordToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToChar(0x7f, &out) != 0)
            error("DWordToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("DWordToChar changed 0x7f to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToChar(0x80, &out))
            error("DWordToChar did not overflow when given 0x80");
    }

}

static void test_DWordToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ USHORT *) __attribute__ ((unused)) = &DWordToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUShort), HRESULT (*)(_In_ DWORD, _Out_ USHORT *)>::value)
            error("DWordToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0, &out) != 0)
            error("DWordToUShort failed to convert 0");
        if(out != 0)
            error("DWordToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUShort(0xffff, &out) != 0)
            error("DWordToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToUShort(0x10000, &out))
            error("DWordToUShort did not overflow when given 0x10000");
    }

}

static void test_DWordToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ WORD *) __attribute__ ((unused)) = &DWordToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToWord), HRESULT (*)(_In_ DWORD, _Out_ WORD *)>::value)
            error("DWordToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0, &out) != 0)
            error("DWordToWord failed to convert 0");
        if(out != 0)
            error("DWordToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToWord(0xffff, &out) != 0)
            error("DWordToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("DWordToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToWord(0x10000, &out))
            error("DWordToWord did not overflow when given 0x10000");
    }

}

static void test_DWordToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SHORT *) __attribute__ ((unused)) = &DWordToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToShort), HRESULT (*)(_In_ DWORD, _Out_ SHORT *)>::value)
            error("DWordToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0, &out) != 0)
            error("DWordToShort failed to convert 0");
        if(out != 0)
            error("DWordToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToShort(0x7fff, &out) != 0)
            error("DWordToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("DWordToShort changed 0x7fff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToShort(0x8000, &out))
            error("DWordToShort did not overflow when given 0x8000");
    }

}

static void test_DWordToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT *) __attribute__ ((unused)) = &DWordToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUInt), HRESULT (*)(_In_ DWORD, _Out_ UINT *)>::value)
            error("DWordToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0, &out) != 0)
            error("DWordToUInt failed to convert 0");
        if(out != 0)
            error("DWordToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUInt(0xffffffff, &out) != 0)
            error("DWordToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT *) __attribute__ ((unused)) = &DWordToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToInt), HRESULT (*)(_In_ DWORD, _Out_ INT *)>::value)
            error("DWordToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0, &out) != 0)
            error("DWordToInt failed to convert 0");
        if(out != 0)
            error("DWordToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToInt(0x7fffffff, &out) != 0)
            error("DWordToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToInt(0x80000000, &out))
            error("DWordToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG *) __attribute__ ((unused)) = &DWordToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLong), HRESULT (*)(_In_ DWORD, _Out_ LONG *)>::value)
            error("DWordToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0, &out) != 0)
            error("DWordToLong failed to convert 0");
        if(out != 0)
            error("DWordToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLong(0x7fffffff, &out) != 0)
            error("DWordToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLong(0x80000000, &out))
            error("DWordToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToUIntPtr), HRESULT (*)(_In_ DWORD, _Out_ UINT_PTR *)>::value)
            error("DWordToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0, &out) != 0)
            error("DWordToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToUIntPtr(0xffffffff, &out) != 0)
            error("DWordToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToIntPtr), HRESULT (*)(_In_ DWORD, _Out_ INT_PTR *)>::value)
            error("DWordToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0, &out) != 0)
            error("DWordToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToIntPtr(0x7fffffff, &out) != 0)
            error("DWordToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToIntPtr(0x80000000, &out))
            error("DWordToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToLongPtr), HRESULT (*)(_In_ DWORD, _Out_ LONG_PTR *)>::value)
            error("DWordToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0, &out) != 0)
            error("DWordToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToLongPtr(0x7fffffff, &out) != 0)
            error("DWordToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToLongPtr(0x80000000, &out))
            error("DWordToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToPtrdiffT), HRESULT (*)(_In_ DWORD, _Out_ ptrdiff_t *)>::value)
            error("DWordToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToPtrdiffT(0x7fffffff, &out) != 0)
            error("DWordToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToPtrdiffT(0x80000000, &out))
            error("DWordToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_DWordToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordToSSIZET), HRESULT (*)(_In_ DWORD, _Out_ SSIZE_T *)>::value)
            error("DWordToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0, &out) != 0)
            error("DWordToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordToSSIZET(0x7fffffff, &out) != 0)
            error("DWordToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordToSSIZET(0x80000000, &out))
            error("DWordToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_IntToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UCHAR *) __attribute__ ((unused)) = &IntToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUChar), HRESULT (*)(_In_ INT, _Out_ UCHAR *)>::value)
            error("IntToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0, &out) != 0)
            error("IntToUChar failed to convert 0");
        if(out != 0)
            error("IntToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUChar(0xff, &out) != 0)
            error("IntToUChar failed to convert 0xff");
        if(out != 0xff)
            error("IntToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar(0x100, &out))
            error("IntToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUChar((-0ll - 1), &out))
            error("IntToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ BYTE *) __attribute__ ((unused)) = &IntToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToByte), HRESULT (*)(_In_ INT, _Out_ BYTE *)>::value)
            error("IntToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToByte(0, &out) != 0)
            error("IntToByte failed to convert 0");
        if(out != 0)
            error("IntToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToByte(0xff, &out) != 0)
            error("IntToByte failed to convert 0xff");
        if(out != 0xff)
            error("IntToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte(0x100, &out))
            error("IntToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToByte((-0ll - 1), &out))
            error("IntToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ CHAR *) __attribute__ ((unused)) = &IntToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToChar), HRESULT (*)(_In_ INT, _Out_ CHAR *)>::value)
            error("IntToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToChar(0, &out) != 0)
            error("IntToChar failed to convert 0");
        if(out != 0)
            error("IntToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToChar(0x7f, &out) != 0)
            error("IntToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("IntToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToChar((-0x7fll - 1), &out) != 0)
            error("IntToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("IntToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar(0x80, &out))
            error("IntToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToChar((-0x80ll - 1), &out))
            error("IntToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_IntToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ USHORT *) __attribute__ ((unused)) = &IntToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUShort), HRESULT (*)(_In_ INT, _Out_ USHORT *)>::value)
            error("IntToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0, &out) != 0)
            error("IntToUShort failed to convert 0");
        if(out != 0)
            error("IntToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUShort(0xffff, &out) != 0)
            error("IntToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort(0x10000, &out))
            error("IntToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUShort((-0ll - 1), &out))
            error("IntToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ WORD *) __attribute__ ((unused)) = &IntToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToWord), HRESULT (*)(_In_ INT, _Out_ WORD *)>::value)
            error("IntToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToWord(0, &out) != 0)
            error("IntToWord failed to convert 0");
        if(out != 0)
            error("IntToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToWord(0xffff, &out) != 0)
            error("IntToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("IntToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord(0x10000, &out))
            error("IntToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToWord((-0ll - 1), &out))
            error("IntToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ SHORT *) __attribute__ ((unused)) = &IntToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToShort), HRESULT (*)(_In_ INT, _Out_ SHORT *)>::value)
            error("IntToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToShort(0, &out) != 0)
            error("IntToShort failed to convert 0");
        if(out != 0)
            error("IntToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToShort(0x7fff, &out) != 0)
            error("IntToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("IntToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntToShort((-0x7fffll - 1), &out) != 0)
            error("IntToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("IntToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort(0x8000, &out))
            error("IntToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToShort((-0x8000ll - 1), &out))
            error("IntToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_IntToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT *) __attribute__ ((unused)) = &IntToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUInt), HRESULT (*)(_In_ INT, _Out_ UINT *)>::value)
            error("IntToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0, &out) != 0)
            error("IntToUInt failed to convert 0");
        if(out != 0)
            error("IntToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUInt(0x7fffffff, &out) != 0)
            error("IntToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUInt((-0ll - 1), &out))
            error("IntToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG *) __attribute__ ((unused)) = &IntToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULong), HRESULT (*)(_In_ INT, _Out_ ULONG *)>::value)
            error("IntToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULong(0, &out) != 0)
            error("IntToULong failed to convert 0");
        if(out != 0)
            error("IntToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULong(0x7fffffff, &out) != 0)
            error("IntToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULong((-0ll - 1), &out))
            error("IntToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD *) __attribute__ ((unused)) = &IntToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWord), HRESULT (*)(_In_ INT, _Out_ DWORD *)>::value)
            error("IntToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0, &out) != 0)
            error("IntToDWord failed to convert 0");
        if(out != 0)
            error("IntToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWord(0x7fffffff, &out) != 0)
            error("IntToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWord((-0ll - 1), &out))
            error("IntToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongLong), HRESULT (*)(_In_ INT, _Out_ ULONGLONG *)>::value)
            error("IntToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0, &out) != 0)
            error("IntToULongLong failed to convert 0");
        if(out != 0)
            error("IntToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongLong(0x7fffffff, &out) != 0)
            error("IntToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongLong((-0ll - 1), &out))
            error("IntToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToUIntPtr), HRESULT (*)(_In_ INT, _Out_ UINT_PTR *)>::value)
            error("IntToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0, &out) != 0)
            error("IntToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToUIntPtr(0x7fffffff, &out) != 0)
            error("IntToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToUIntPtr((-0ll - 1), &out))
            error("IntToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ size_t *) __attribute__ ((unused)) = &IntToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToSizeT), HRESULT (*)(_In_ INT, _Out_ size_t *)>::value)
            error("IntToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0, &out) != 0)
            error("IntToSizeT failed to convert 0");
        if(out != 0)
            error("IntToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToSizeT(0x7fffffff, &out) != 0)
            error("IntToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToSizeT((-0ll - 1), &out))
            error("IntToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToDWordPtr), HRESULT (*)(_In_ INT, _Out_ DWORD_PTR *)>::value)
            error("IntToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0, &out) != 0)
            error("IntToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToDWordPtr(0x7fffffff, &out) != 0)
            error("IntToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToDWordPtr((-0ll - 1), &out))
            error("IntToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntToULongPtr), HRESULT (*)(_In_ INT, _Out_ ULONG_PTR *)>::value)
            error("IntToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0, &out) != 0)
            error("IntToULongPtr failed to convert 0");
        if(out != 0)
            error("IntToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntToULongPtr(0x7fffffff, &out) != 0)
            error("IntToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntToULongPtr((-0ll - 1), &out))
            error("IntToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUChar()
{
    UCHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UCHAR *) __attribute__ ((unused)) = &LongToUChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUChar), HRESULT (*)(_In_ LONG, _Out_ UCHAR *)>::value)
            error("LongToUChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0, &out) != 0)
            error("LongToUChar failed to convert 0");
        if(out != 0)
            error("LongToUChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUChar(0xff, &out) != 0)
            error("LongToUChar failed to convert 0xff");
        if(out != 0xff)
            error("LongToUChar changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar(0x100, &out))
            error("LongToUChar did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUChar((-0ll - 1), &out))
            error("LongToUChar did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToByte()
{
    BYTE out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ BYTE *) __attribute__ ((unused)) = &LongToByte;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToByte), HRESULT (*)(_In_ LONG, _Out_ BYTE *)>::value)
            error("LongToByte does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToByte(0, &out) != 0)
            error("LongToByte failed to convert 0");
        if(out != 0)
            error("LongToByte changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToByte(0xff, &out) != 0)
            error("LongToByte failed to convert 0xff");
        if(out != 0xff)
            error("LongToByte changed 0xff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte(0x100, &out))
            error("LongToByte did not overflow when given 0x100");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToByte((-0ll - 1), &out))
            error("LongToByte did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToChar()
{
    CHAR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ CHAR *) __attribute__ ((unused)) = &LongToChar;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToChar), HRESULT (*)(_In_ LONG, _Out_ CHAR *)>::value)
            error("LongToChar does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToChar(0, &out) != 0)
            error("LongToChar failed to convert 0");
        if(out != 0)
            error("LongToChar changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToChar(0x7f, &out) != 0)
            error("LongToChar failed to convert 0x7f");
        if(out != 0x7f)
            error("LongToChar changed 0x7f to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToChar((-0x7fll - 1), &out) != 0)
            error("LongToChar failed to convert (-0x7fll - 1)");
        if(out != (-0x7fll - 1))
            error("LongToChar changed (-0x7fll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar(0x80, &out))
            error("LongToChar did not overflow when given 0x80");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToChar((-0x80ll - 1), &out))
            error("LongToChar did not overflow when given (-0x80ll - 1)");
    }

}

static void test_LongToUShort()
{
    USHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ USHORT *) __attribute__ ((unused)) = &LongToUShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUShort), HRESULT (*)(_In_ LONG, _Out_ USHORT *)>::value)
            error("LongToUShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0, &out) != 0)
            error("LongToUShort failed to convert 0");
        if(out != 0)
            error("LongToUShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUShort(0xffff, &out) != 0)
            error("LongToUShort failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToUShort changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort(0x10000, &out))
            error("LongToUShort did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUShort((-0ll - 1), &out))
            error("LongToUShort did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToWord()
{
    WORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ WORD *) __attribute__ ((unused)) = &LongToWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToWord), HRESULT (*)(_In_ LONG, _Out_ WORD *)>::value)
            error("LongToWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToWord(0, &out) != 0)
            error("LongToWord failed to convert 0");
        if(out != 0)
            error("LongToWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToWord(0xffff, &out) != 0)
            error("LongToWord failed to convert 0xffff");
        if(out != 0xffff)
            error("LongToWord changed 0xffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord(0x10000, &out))
            error("LongToWord did not overflow when given 0x10000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToWord((-0ll - 1), &out))
            error("LongToWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToShort()
{
    SHORT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ SHORT *) __attribute__ ((unused)) = &LongToShort;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToShort), HRESULT (*)(_In_ LONG, _Out_ SHORT *)>::value)
            error("LongToShort does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToShort(0, &out) != 0)
            error("LongToShort failed to convert 0");
        if(out != 0)
            error("LongToShort changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToShort(0x7fff, &out) != 0)
            error("LongToShort failed to convert 0x7fff");
        if(out != 0x7fff)
            error("LongToShort changed 0x7fff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToShort((-0x7fffll - 1), &out) != 0)
            error("LongToShort failed to convert (-0x7fffll - 1)");
        if(out != (-0x7fffll - 1))
            error("LongToShort changed (-0x7fffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort(0x8000, &out))
            error("LongToShort did not overflow when given 0x8000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToShort((-0x8000ll - 1), &out))
            error("LongToShort did not overflow when given (-0x8000ll - 1)");
    }

}

static void test_LongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT *) __attribute__ ((unused)) = &LongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUInt), HRESULT (*)(_In_ LONG, _Out_ UINT *)>::value)
            error("LongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0, &out) != 0)
            error("LongToUInt failed to convert 0");
        if(out != 0)
            error("LongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUInt(0x7fffffff, &out) != 0)
            error("LongToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUInt((-0ll - 1), &out))
            error("LongToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG *) __attribute__ ((unused)) = &LongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULong), HRESULT (*)(_In_ LONG, _Out_ ULONG *)>::value)
            error("LongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULong(0, &out) != 0)
            error("LongToULong failed to convert 0");
        if(out != 0)
            error("LongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULong(0x7fffffff, &out) != 0)
            error("LongToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULong((-0ll - 1), &out))
            error("LongToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD *) __attribute__ ((unused)) = &LongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWord), HRESULT (*)(_In_ LONG, _Out_ DWORD *)>::value)
            error("LongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0, &out) != 0)
            error("LongToDWord failed to convert 0");
        if(out != 0)
            error("LongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWord(0x7fffffff, &out) != 0)
            error("LongToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWord((-0ll - 1), &out))
            error("LongToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT *) __attribute__ ((unused)) = &LongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToInt), HRESULT (*)(_In_ LONG, _Out_ INT *)>::value)
            error("LongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToInt(0, &out) != 0)
            error("LongToInt failed to convert 0");
        if(out != 0)
            error("LongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToInt(0x7fffffff, &out) != 0)
            error("LongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongLong), HRESULT (*)(_In_ LONG, _Out_ ULONGLONG *)>::value)
            error("LongToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0, &out) != 0)
            error("LongToULongLong failed to convert 0");
        if(out != 0)
            error("LongToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongLong(0x7fffffff, &out) != 0)
            error("LongToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongLong((-0ll - 1), &out))
            error("LongToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToUIntPtr), HRESULT (*)(_In_ LONG, _Out_ UINT_PTR *)>::value)
            error("LongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0, &out) != 0)
            error("LongToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToUIntPtr(0x7fffffff, &out) != 0)
            error("LongToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToUIntPtr((-0ll - 1), &out))
            error("LongToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ size_t *) __attribute__ ((unused)) = &LongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToSizeT), HRESULT (*)(_In_ LONG, _Out_ size_t *)>::value)
            error("LongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0, &out) != 0)
            error("LongToSizeT failed to convert 0");
        if(out != 0)
            error("LongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToSizeT(0x7fffffff, &out) != 0)
            error("LongToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToSizeT((-0ll - 1), &out))
            error("LongToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToDWordPtr), HRESULT (*)(_In_ LONG, _Out_ DWORD_PTR *)>::value)
            error("LongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0, &out) != 0)
            error("LongToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToDWordPtr(0x7fffffff, &out) != 0)
            error("LongToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToDWordPtr((-0ll - 1), &out))
            error("LongToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToULongPtr), HRESULT (*)(_In_ LONG, _Out_ ULONG_PTR *)>::value)
            error("LongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0, &out) != 0)
            error("LongToULongPtr failed to convert 0");
        if(out != 0)
            error("LongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToULongPtr(0x7fffffff, &out) != 0)
            error("LongToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongToULongPtr((-0ll - 1), &out))
            error("LongToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToIntPtr), HRESULT (*)(_In_ LONG, _Out_ INT_PTR *)>::value)
            error("LongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0, &out) != 0)
            error("LongToIntPtr failed to convert 0");
        if(out != 0)
            error("LongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr(0x7fffffff, &out) != 0)
            error("LongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &LongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongToPtrdiffT), HRESULT (*)(_In_ LONG, _Out_ ptrdiff_t *)>::value)
            error("LongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0, &out) != 0)
            error("LongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("LongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT(0x7fffffff, &out) != 0)
            error("LongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("LongToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_ULongLongToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT *) __attribute__ ((unused)) = &ULongLongToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUInt), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT *)>::value)
            error("ULongLongToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0, &out) != 0)
            error("ULongLongToUInt failed to convert 0");
        if(out != 0)
            error("ULongLongToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUInt(0xffffffff, &out) != 0)
            error("ULongLongToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUInt(0x100000000, &out))
            error("ULongLongToUInt did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG *) __attribute__ ((unused)) = &ULongLongToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULong), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG *)>::value)
            error("ULongLongToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0, &out) != 0)
            error("ULongLongToULong failed to convert 0");
        if(out != 0)
            error("ULongLongToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULong(0xffffffff, &out) != 0)
            error("ULongLongToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULong(0x100000000, &out))
            error("ULongLongToULong did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD *) __attribute__ ((unused)) = &ULongLongToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWord), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD *)>::value)
            error("ULongLongToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0, &out) != 0)
            error("ULongLongToDWord failed to convert 0");
        if(out != 0)
            error("ULongLongToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWord(0xffffffff, &out) != 0)
            error("ULongLongToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWord(0x100000000, &out))
            error("ULongLongToDWord did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT *) __attribute__ ((unused)) = &ULongLongToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt), HRESULT (*)(_In_ ULONGLONG, _Out_ INT *)>::value)
            error("ULongLongToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0, &out) != 0)
            error("ULongLongToInt failed to convert 0");
        if(out != 0)
            error("ULongLongToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt(0x7fffffff, &out) != 0)
            error("ULongLongToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt(0x80000000, &out))
            error("ULongLongToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG *) __attribute__ ((unused)) = &ULongLongToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLong), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG *)>::value)
            error("ULongLongToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0, &out) != 0)
            error("ULongLongToLong failed to convert 0");
        if(out != 0)
            error("ULongLongToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLong(0x7fffffff, &out) != 0)
            error("ULongLongToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLong(0x80000000, &out))
            error("ULongLongToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT64 *) __attribute__ ((unused)) = &ULongLongToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToInt64), HRESULT (*)(_In_ ULONGLONG, _Out_ INT64 *)>::value)
            error("ULongLongToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0, &out) != 0)
            error("ULongLongToInt64 failed to convert 0");
        if(out != 0)
            error("ULongLongToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToInt64(0x7fffffffffffffff, &out) != 0)
            error("ULongLongToInt64 failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("ULongLongToInt64 changed 0x7fffffffffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToInt64(0x8000000000000000, &out))
            error("ULongLongToInt64 did not overflow when given 0x8000000000000000");
    }

}

static void test_ULongLongToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongLongToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToUIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ UINT_PTR *)>::value)
            error("ULongLongToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToUIntPtr(0xffffffff, &out) != 0)
            error("ULongLongToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToUIntPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToUIntPtr(0x100000000, &out))
            error("ULongLongToUIntPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ size_t *) __attribute__ ((unused)) = &ULongLongToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSizeT), HRESULT (*)(_In_ ULONGLONG, _Out_ size_t *)>::value)
            error("ULongLongToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0, &out) != 0)
            error("ULongLongToSizeT failed to convert 0");
        if(out != 0)
            error("ULongLongToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSizeT(0xffffffff, &out) != 0)
            error("ULongLongToSizeT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToSizeT changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSizeT(0x100000000, &out))
            error("ULongLongToSizeT did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &ULongLongToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToDWordPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ DWORD_PTR *)>::value)
            error("ULongLongToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToDWordPtr(0xffffffff, &out) != 0)
            error("ULongLongToDWordPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToDWordPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToDWordPtr(0x100000000, &out))
            error("ULongLongToDWordPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &ULongLongToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToULongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ ULONG_PTR *)>::value)
            error("ULongLongToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToULongPtr(0xffffffff, &out) != 0)
            error("ULongLongToULongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongLongToULongPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToULongPtr(0x100000000, &out))
            error("ULongLongToULongPtr did not overflow when given 0x100000000");
    }

}

static void test_ULongLongToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongLongToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToIntPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ INT_PTR *)>::value)
            error("ULongLongToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToIntPtr(0x7fffffff, &out) != 0)
            error("ULongLongToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToIntPtr(0x80000000, &out))
            error("ULongLongToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongLongToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToLongPtr), HRESULT (*)(_In_ ULONGLONG, _Out_ LONG_PTR *)>::value)
            error("ULongLongToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongLongToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToLongPtr(0x7fffffff, &out) != 0)
            error("ULongLongToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToLongPtr(0x80000000, &out))
            error("ULongLongToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongLongToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToPtrdiffT), HRESULT (*)(_In_ ULONGLONG, _Out_ ptrdiff_t *)>::value)
            error("ULongLongToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongLongToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongLongToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToPtrdiffT(0x80000000, &out))
            error("ULongLongToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongLongToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONGLONG, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongLongToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongLongToSSIZET), HRESULT (*)(_In_ ULONGLONG, _Out_ SSIZE_T *)>::value)
            error("ULongLongToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongLongToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongLongToSSIZET(0x7fffffff, &out) != 0)
            error("ULongLongToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongLongToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongLongToSSIZET(0x80000000, &out))
            error("ULongLongToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_Int64ToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT *) __attribute__ ((unused)) = &Int64ToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUInt), HRESULT (*)(_In_ INT64, _Out_ UINT *)>::value)
            error("Int64ToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0, &out) != 0)
            error("Int64ToUInt failed to convert 0");
        if(out != 0)
            error("Int64ToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUInt(0xffffffff, &out) != 0)
            error("Int64ToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUInt changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt(0x100000000, &out))
            error("Int64ToUInt did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUInt((-0ll - 1), &out))
            error("Int64ToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG *) __attribute__ ((unused)) = &Int64ToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULong), HRESULT (*)(_In_ INT64, _Out_ ULONG *)>::value)
            error("Int64ToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0, &out) != 0)
            error("Int64ToULong failed to convert 0");
        if(out != 0)
            error("Int64ToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULong(0xffffffff, &out) != 0)
            error("Int64ToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULong changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong(0x100000000, &out))
            error("Int64ToULong did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULong((-0ll - 1), &out))
            error("Int64ToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD *) __attribute__ ((unused)) = &Int64ToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWord), HRESULT (*)(_In_ INT64, _Out_ DWORD *)>::value)
            error("Int64ToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0, &out) != 0)
            error("Int64ToDWord failed to convert 0");
        if(out != 0)
            error("Int64ToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWord(0xffffffff, &out) != 0)
            error("Int64ToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWord changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord(0x100000000, &out))
            error("Int64ToDWord did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWord((-0ll - 1), &out))
            error("Int64ToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT *) __attribute__ ((unused)) = &Int64ToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToInt), HRESULT (*)(_In_ INT64, _Out_ INT *)>::value)
            error("Int64ToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0, &out) != 0)
            error("Int64ToInt failed to convert 0");
        if(out != 0)
            error("Int64ToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt(0x7fffffff, &out) != 0)
            error("Int64ToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToInt((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToInt changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt(0x80000000, &out))
            error("Int64ToInt did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToInt((-0x80000000ll - 1), &out))
            error("Int64ToInt did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG *) __attribute__ ((unused)) = &Int64ToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLong), HRESULT (*)(_In_ INT64, _Out_ LONG *)>::value)
            error("Int64ToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0, &out) != 0)
            error("Int64ToLong failed to convert 0");
        if(out != 0)
            error("Int64ToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong(0x7fffffff, &out) != 0)
            error("Int64ToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLong((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLong changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong(0x80000000, &out))
            error("Int64ToLong did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLong((-0x80000000ll - 1), &out))
            error("Int64ToLong did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONGLONG *) __attribute__ ((unused)) = &Int64ToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongLong), HRESULT (*)(_In_ INT64, _Out_ ULONGLONG *)>::value)
            error("Int64ToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0, &out) != 0)
            error("Int64ToULongLong failed to convert 0");
        if(out != 0)
            error("Int64ToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongLong(0x7fffffffffffffff, &out) != 0)
            error("Int64ToULongLong failed to convert 0x7fffffffffffffff");
        if(out != 0x7fffffffffffffff)
            error("Int64ToULongLong changed 0x7fffffffffffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongLong((-0ll - 1), &out))
            error("Int64ToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ UINT_PTR *) __attribute__ ((unused)) = &Int64ToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToUIntPtr), HRESULT (*)(_In_ INT64, _Out_ UINT_PTR *)>::value)
            error("Int64ToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToUIntPtr(0xffffffff, &out) != 0)
            error("Int64ToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToUIntPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr(0x100000000, &out))
            error("Int64ToUIntPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToUIntPtr((-0ll - 1), &out))
            error("Int64ToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ size_t *) __attribute__ ((unused)) = &Int64ToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSizeT), HRESULT (*)(_In_ INT64, _Out_ size_t *)>::value)
            error("Int64ToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0, &out) != 0)
            error("Int64ToSizeT failed to convert 0");
        if(out != 0)
            error("Int64ToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSizeT(0xffffffff, &out) != 0)
            error("Int64ToSizeT failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToSizeT changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT(0x100000000, &out))
            error("Int64ToSizeT did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSizeT((-0ll - 1), &out))
            error("Int64ToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &Int64ToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToDWordPtr), HRESULT (*)(_In_ INT64, _Out_ DWORD_PTR *)>::value)
            error("Int64ToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0");
        if(out != 0)
            error("Int64ToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToDWordPtr(0xffffffff, &out) != 0)
            error("Int64ToDWordPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToDWordPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr(0x100000000, &out))
            error("Int64ToDWordPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToDWordPtr((-0ll - 1), &out))
            error("Int64ToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &Int64ToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToULongPtr), HRESULT (*)(_In_ INT64, _Out_ ULONG_PTR *)>::value)
            error("Int64ToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0, &out) != 0)
            error("Int64ToULongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToULongPtr(0xffffffff, &out) != 0)
            error("Int64ToULongPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("Int64ToULongPtr changed 0xffffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr(0x100000000, &out))
            error("Int64ToULongPtr did not overflow when given 0x100000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToULongPtr((-0ll - 1), &out))
            error("Int64ToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_Int64ToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ INT_PTR *) __attribute__ ((unused)) = &Int64ToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToIntPtr), HRESULT (*)(_In_ INT64, _Out_ INT_PTR *)>::value)
            error("Int64ToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0, &out) != 0)
            error("Int64ToIntPtr failed to convert 0");
        if(out != 0)
            error("Int64ToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr(0x7fffffff, &out) != 0)
            error("Int64ToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToIntPtr(0x80000000, &out))
            error("Int64ToIntPtr did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToIntPtr((-0x80000000ll - 1), &out))
            error("Int64ToIntPtr did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ LONG_PTR *) __attribute__ ((unused)) = &Int64ToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToLongPtr), HRESULT (*)(_In_ INT64, _Out_ LONG_PTR *)>::value)
            error("Int64ToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0, &out) != 0)
            error("Int64ToLongPtr failed to convert 0");
        if(out != 0)
            error("Int64ToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr(0x7fffffff, &out) != 0)
            error("Int64ToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToLongPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToLongPtr((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToLongPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToLongPtr changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLongPtr(0x80000000, &out))
            error("Int64ToLongPtr did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToLongPtr((-0x80000000ll - 1), &out))
            error("Int64ToLongPtr did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &Int64ToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToPtrdiffT), HRESULT (*)(_In_ INT64, _Out_ ptrdiff_t *)>::value)
            error("Int64ToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0");
        if(out != 0)
            error("Int64ToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT(0x7fffffff, &out) != 0)
            error("Int64ToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToPtrdiffT changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToPtrdiffT((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToPtrdiffT failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToPtrdiffT changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToPtrdiffT(0x80000000, &out))
            error("Int64ToPtrdiffT did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToPtrdiffT((-0x80000000ll - 1), &out))
            error("Int64ToPtrdiffT did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_Int64ToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT64, _Out_ SSIZE_T *) __attribute__ ((unused)) = &Int64ToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&Int64ToSSIZET), HRESULT (*)(_In_ INT64, _Out_ SSIZE_T *)>::value)
            error("Int64ToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0, &out) != 0)
            error("Int64ToSSIZET failed to convert 0");
        if(out != 0)
            error("Int64ToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET(0x7fffffff, &out) != 0)
            error("Int64ToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("Int64ToSSIZET changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(Int64ToSSIZET((-0x7fffffffll - 1), &out) != 0)
            error("Int64ToSSIZET failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("Int64ToSSIZET changed (-0x7fffffffll - 1) to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSSIZET(0x80000000, &out))
            error("Int64ToSSIZET did not overflow when given 0x80000000");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != Int64ToSSIZET((-0x80000000ll - 1), &out))
            error("Int64ToSSIZET did not overflow when given (-0x80000000ll - 1)");
    }

}

static void test_UIntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &UIntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToUInt), HRESULT (*)(_In_ UINT_PTR, _Out_ UINT *)>::value)
            error("UIntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0, &out) != 0)
            error("UIntPtrToUInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToUInt(0xffffffff, &out) != 0)
            error("UIntPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &UIntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToULong), HRESULT (*)(_In_ UINT_PTR, _Out_ ULONG *)>::value)
            error("UIntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0, &out) != 0)
            error("UIntPtrToULong failed to convert 0");
        if(out != 0)
            error("UIntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToULong(0xffffffff, &out) != 0)
            error("UIntPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &UIntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToDWord), HRESULT (*)(_In_ UINT_PTR, _Out_ DWORD *)>::value)
            error("UIntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0, &out) != 0)
            error("UIntPtrToDWord failed to convert 0");
        if(out != 0)
            error("UIntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToDWord(0xffffffff, &out) != 0)
            error("UIntPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT *) __attribute__ ((unused)) = &UIntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt), HRESULT (*)(_In_ UINT_PTR, _Out_ INT *)>::value)
            error("UIntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0, &out) != 0)
            error("UIntPtrToInt failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt(0x7fffffff, &out) != 0)
            error("UIntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToInt(0x80000000, &out))
            error("UIntPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &UIntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLong), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG *)>::value)
            error("UIntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0, &out) != 0)
            error("UIntPtrToLong failed to convert 0");
        if(out != 0)
            error("UIntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLong(0x7fffffff, &out) != 0)
            error("UIntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLong(0x80000000, &out))
            error("UIntPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &UIntPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToInt64), HRESULT (*)(_In_ UINT_PTR, _Out_ INT64 *)>::value)
            error("UIntPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0");
        if(out != 0)
            error("UIntPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToInt64(0xffffffff, &out) != 0)
            error("UIntPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("UIntPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_UIntPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &UIntPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToIntPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ INT_PTR *)>::value)
            error("UIntPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToIntPtr(0x7fffffff, &out) != 0)
            error("UIntPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToIntPtr(0x80000000, &out))
            error("UIntPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &UIntPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToLongPtr), HRESULT (*)(_In_ UINT_PTR, _Out_ LONG_PTR *)>::value)
            error("UIntPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("UIntPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToLongPtr(0x7fffffff, &out) != 0)
            error("UIntPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToLongPtr(0x80000000, &out))
            error("UIntPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_UIntPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ UINT_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &UIntPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&UIntPtrToSSIZET), HRESULT (*)(_In_ UINT_PTR, _Out_ SSIZE_T *)>::value)
            error("UIntPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("UIntPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(UIntPtrToSSIZET(0x7fffffff, &out) != 0)
            error("UIntPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("UIntPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != UIntPtrToSSIZET(0x80000000, &out))
            error("UIntPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_SizeTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ UINT *) __attribute__ ((unused)) = &SizeTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToUInt), HRESULT (*)(_In_ size_t, _Out_ UINT *)>::value)
            error("SizeTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0, &out) != 0)
            error("SizeTToUInt failed to convert 0");
        if(out != 0)
            error("SizeTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToUInt(0xffffffff, &out) != 0)
            error("SizeTToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToUInt changed 0xffffffff to something else.");
    }

}

static void test_SizeTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ULONG *) __attribute__ ((unused)) = &SizeTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToULong), HRESULT (*)(_In_ size_t, _Out_ ULONG *)>::value)
            error("SizeTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0, &out) != 0)
            error("SizeTToULong failed to convert 0");
        if(out != 0)
            error("SizeTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToULong(0xffffffff, &out) != 0)
            error("SizeTToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToULong changed 0xffffffff to something else.");
    }

}

static void test_SizeTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ DWORD *) __attribute__ ((unused)) = &SizeTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToDWord), HRESULT (*)(_In_ size_t, _Out_ DWORD *)>::value)
            error("SizeTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0, &out) != 0)
            error("SizeTToDWord failed to convert 0");
        if(out != 0)
            error("SizeTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToDWord(0xffffffff, &out) != 0)
            error("SizeTToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToDWord changed 0xffffffff to something else.");
    }

}

static void test_SizeTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT *) __attribute__ ((unused)) = &SizeTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt), HRESULT (*)(_In_ size_t, _Out_ INT *)>::value)
            error("SizeTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0, &out) != 0)
            error("SizeTToInt failed to convert 0");
        if(out != 0)
            error("SizeTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt(0x7fffffff, &out) != 0)
            error("SizeTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToInt(0x80000000, &out))
            error("SizeTToInt did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG *) __attribute__ ((unused)) = &SizeTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLong), HRESULT (*)(_In_ size_t, _Out_ LONG *)>::value)
            error("SizeTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0, &out) != 0)
            error("SizeTToLong failed to convert 0");
        if(out != 0)
            error("SizeTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLong(0x7fffffff, &out) != 0)
            error("SizeTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLong(0x80000000, &out))
            error("SizeTToLong did not overflow when given 0x80000000");
    }

}

static void test_SizeTToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT64 *) __attribute__ ((unused)) = &SizeTToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToInt64), HRESULT (*)(_In_ size_t, _Out_ INT64 *)>::value)
            error("SizeTToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0, &out) != 0)
            error("SizeTToInt64 failed to convert 0");
        if(out != 0)
            error("SizeTToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToInt64(0xffffffff, &out) != 0)
            error("SizeTToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("SizeTToInt64 changed 0xffffffff to something else.");
    }

}

static void test_SizeTToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ INT_PTR *) __attribute__ ((unused)) = &SizeTToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToIntPtr), HRESULT (*)(_In_ size_t, _Out_ INT_PTR *)>::value)
            error("SizeTToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0, &out) != 0)
            error("SizeTToIntPtr failed to convert 0");
        if(out != 0)
            error("SizeTToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToIntPtr(0x7fffffff, &out) != 0)
            error("SizeTToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToIntPtr(0x80000000, &out))
            error("SizeTToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_SizeTToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ LONG_PTR *) __attribute__ ((unused)) = &SizeTToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToLongPtr), HRESULT (*)(_In_ size_t, _Out_ LONG_PTR *)>::value)
            error("SizeTToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0, &out) != 0)
            error("SizeTToLongPtr failed to convert 0");
        if(out != 0)
            error("SizeTToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToLongPtr(0x7fffffff, &out) != 0)
            error("SizeTToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToLongPtr(0x80000000, &out))
            error("SizeTToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_SizeTToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &SizeTToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToPtrdiffT), HRESULT (*)(_In_ size_t, _Out_ ptrdiff_t *)>::value)
            error("SizeTToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0");
        if(out != 0)
            error("SizeTToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToPtrdiffT(0x7fffffff, &out) != 0)
            error("SizeTToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToPtrdiffT(0x80000000, &out))
            error("SizeTToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_SizeTToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ size_t, _Out_ SSIZE_T *) __attribute__ ((unused)) = &SizeTToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SizeTToSSIZET), HRESULT (*)(_In_ size_t, _Out_ SSIZE_T *)>::value)
            error("SizeTToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0, &out) != 0)
            error("SizeTToSSIZET failed to convert 0");
        if(out != 0)
            error("SizeTToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SizeTToSSIZET(0x7fffffff, &out) != 0)
            error("SizeTToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SizeTToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SizeTToSSIZET(0x80000000, &out))
            error("SizeTToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT *) __attribute__ ((unused)) = &DWordPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT *)>::value)
            error("DWordPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0, &out) != 0)
            error("DWordPtrToUInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUInt(0xffffffff, &out) != 0)
            error("DWordPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &DWordPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToULong), HRESULT (*)(_In_ DWORD_PTR, _Out_ ULONG *)>::value)
            error("DWordPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0, &out) != 0)
            error("DWordPtrToULong failed to convert 0");
        if(out != 0)
            error("DWordPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToULong(0xffffffff, &out) != 0)
            error("DWordPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &DWordPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToDWord), HRESULT (*)(_In_ DWORD_PTR, _Out_ DWORD *)>::value)
            error("DWordPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0, &out) != 0)
            error("DWordPtrToDWord failed to convert 0");
        if(out != 0)
            error("DWordPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToDWord(0xffffffff, &out) != 0)
            error("DWordPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT *) __attribute__ ((unused)) = &DWordPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT *)>::value)
            error("DWordPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0, &out) != 0)
            error("DWordPtrToInt failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt(0x7fffffff, &out) != 0)
            error("DWordPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToInt(0x80000000, &out))
            error("DWordPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG *) __attribute__ ((unused)) = &DWordPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLong), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG *)>::value)
            error("DWordPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0, &out) != 0)
            error("DWordPtrToLong failed to convert 0");
        if(out != 0)
            error("DWordPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLong(0x7fffffff, &out) != 0)
            error("DWordPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLong(0x80000000, &out))
            error("DWordPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &DWordPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToInt64), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT64 *)>::value)
            error("DWordPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0");
        if(out != 0)
            error("DWordPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToInt64(0xffffffff, &out) != 0)
            error("DWordPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &DWordPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToUIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ UINT_PTR *)>::value)
            error("DWordPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToUIntPtr(0xffffffff, &out) != 0)
            error("DWordPtrToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("DWordPtrToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_DWordPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &DWordPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToIntPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ INT_PTR *)>::value)
            error("DWordPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToIntPtr(0x7fffffff, &out) != 0)
            error("DWordPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToIntPtr(0x80000000, &out))
            error("DWordPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &DWordPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToLongPtr), HRESULT (*)(_In_ DWORD_PTR, _Out_ LONG_PTR *)>::value)
            error("DWordPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("DWordPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToLongPtr(0x7fffffff, &out) != 0)
            error("DWordPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToLongPtr(0x80000000, &out))
            error("DWordPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &DWordPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToPtrdiffT), HRESULT (*)(_In_ DWORD_PTR, _Out_ ptrdiff_t *)>::value)
            error("DWordPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("DWordPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToPtrdiffT(0x7fffffff, &out) != 0)
            error("DWordPtrToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToPtrdiffT(0x80000000, &out))
            error("DWordPtrToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_DWordPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ DWORD_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &DWordPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&DWordPtrToSSIZET), HRESULT (*)(_In_ DWORD_PTR, _Out_ SSIZE_T *)>::value)
            error("DWordPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("DWordPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(DWordPtrToSSIZET(0x7fffffff, &out) != 0)
            error("DWordPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("DWordPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != DWordPtrToSSIZET(0x80000000, &out))
            error("DWordPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &ULongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT *)>::value)
            error("ULongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0, &out) != 0)
            error("ULongPtrToUInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUInt(0xffffffff, &out) != 0)
            error("ULongPtrToUInt failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUInt changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &ULongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToULong), HRESULT (*)(_In_ ULONG_PTR, _Out_ ULONG *)>::value)
            error("ULongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0, &out) != 0)
            error("ULongPtrToULong failed to convert 0");
        if(out != 0)
            error("ULongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToULong(0xffffffff, &out) != 0)
            error("ULongPtrToULong failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToULong changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &ULongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToDWord), HRESULT (*)(_In_ ULONG_PTR, _Out_ DWORD *)>::value)
            error("ULongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0, &out) != 0)
            error("ULongPtrToDWord failed to convert 0");
        if(out != 0)
            error("ULongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToDWord(0xffffffff, &out) != 0)
            error("ULongPtrToDWord failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToDWord changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &ULongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT *)>::value)
            error("ULongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0, &out) != 0)
            error("ULongPtrToInt failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt(0x7fffffff, &out) != 0)
            error("ULongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToInt changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToInt(0x80000000, &out))
            error("ULongPtrToInt did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &ULongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLong), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG *)>::value)
            error("ULongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0, &out) != 0)
            error("ULongPtrToLong failed to convert 0");
        if(out != 0)
            error("ULongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLong(0x7fffffff, &out) != 0)
            error("ULongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLong changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLong(0x80000000, &out))
            error("ULongPtrToLong did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToInt64()
{
    INT64 out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT64 *) __attribute__ ((unused)) = &ULongPtrToInt64;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToInt64), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT64 *)>::value)
            error("ULongPtrToInt64 does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0");
        if(out != 0)
            error("ULongPtrToInt64 changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToInt64(0xffffffff, &out) != 0)
            error("ULongPtrToInt64 failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToInt64 changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &ULongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToUIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ UINT_PTR *)>::value)
            error("ULongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToUIntPtr(0xffffffff, &out) != 0)
            error("ULongPtrToUIntPtr failed to convert 0xffffffff");
        if(out != 0xffffffff)
            error("ULongPtrToUIntPtr changed 0xffffffff to something else.");
    }

}

static void test_ULongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &ULongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToIntPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ INT_PTR *)>::value)
            error("ULongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToIntPtr(0x7fffffff, &out) != 0)
            error("ULongPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToIntPtr(0x80000000, &out))
            error("ULongPtrToIntPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToLongPtr()
{
    LONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ LONG_PTR *) __attribute__ ((unused)) = &ULongPtrToLongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToLongPtr), HRESULT (*)(_In_ ULONG_PTR, _Out_ LONG_PTR *)>::value)
            error("ULongPtrToLongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0");
        if(out != 0)
            error("ULongPtrToLongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToLongPtr(0x7fffffff, &out) != 0)
            error("ULongPtrToLongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToLongPtr changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToLongPtr(0x80000000, &out))
            error("ULongPtrToLongPtr did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToPtrdiffT()
{
    ptrdiff_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ ptrdiff_t *) __attribute__ ((unused)) = &ULongPtrToPtrdiffT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToPtrdiffT), HRESULT (*)(_In_ ULONG_PTR, _Out_ ptrdiff_t *)>::value)
            error("ULongPtrToPtrdiffT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0");
        if(out != 0)
            error("ULongPtrToPtrdiffT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToPtrdiffT(0x7fffffff, &out) != 0)
            error("ULongPtrToPtrdiffT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToPtrdiffT changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToPtrdiffT(0x80000000, &out))
            error("ULongPtrToPtrdiffT did not overflow when given 0x80000000");
    }

}

static void test_ULongPtrToSSIZET()
{
    SSIZE_T out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ULONG_PTR, _Out_ SSIZE_T *) __attribute__ ((unused)) = &ULongPtrToSSIZET;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&ULongPtrToSSIZET), HRESULT (*)(_In_ ULONG_PTR, _Out_ SSIZE_T *)>::value)
            error("ULongPtrToSSIZET does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0");
        if(out != 0)
            error("ULongPtrToSSIZET changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(ULongPtrToSSIZET(0x7fffffff, &out) != 0)
            error("ULongPtrToSSIZET failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("ULongPtrToSSIZET changed 0x7fffffff to something else.");
    }

    // rejects maximum value + 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != ULongPtrToSSIZET(0x80000000, &out))
            error("ULongPtrToSSIZET did not overflow when given 0x80000000");
    }

}

static void test_IntPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT *) __attribute__ ((unused)) = &IntPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUInt), HRESULT (*)(_In_ INT_PTR, _Out_ UINT *)>::value)
            error("IntPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0, &out) != 0)
            error("IntPtrToUInt failed to convert 0");
        if(out != 0)
            error("IntPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUInt(0x7fffffff, &out) != 0)
            error("IntPtrToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUInt((-0ll - 1), &out))
            error("IntPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &IntPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG *)>::value)
            error("IntPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0, &out) != 0)
            error("IntPtrToULong failed to convert 0");
        if(out != 0)
            error("IntPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULong(0x7fffffff, &out) != 0)
            error("IntPtrToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULong((-0ll - 1), &out))
            error("IntPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &IntPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWord), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD *)>::value)
            error("IntPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0, &out) != 0)
            error("IntPtrToDWord failed to convert 0");
        if(out != 0)
            error("IntPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWord(0x7fffffff, &out) != 0)
            error("IntPtrToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWord((-0ll - 1), &out))
            error("IntPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ INT *) __attribute__ ((unused)) = &IntPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToInt), HRESULT (*)(_In_ INT_PTR, _Out_ INT *)>::value)
            error("IntPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0, &out) != 0)
            error("IntPtrToInt failed to convert 0");
        if(out != 0)
            error("IntPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt(0x7fffffff, &out) != 0)
            error("IntPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_IntPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ LONG *) __attribute__ ((unused)) = &IntPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToLong), HRESULT (*)(_In_ INT_PTR, _Out_ LONG *)>::value)
            error("IntPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0, &out) != 0)
            error("IntPtrToLong failed to convert 0");
        if(out != 0)
            error("IntPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong(0x7fffffff, &out) != 0)
            error("IntPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("IntPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("IntPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_IntPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &IntPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongLong), HRESULT (*)(_In_ INT_PTR, _Out_ ULONGLONG *)>::value)
            error("IntPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0, &out) != 0)
            error("IntPtrToULongLong failed to convert 0");
        if(out != 0)
            error("IntPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongLong(0x7fffffff, &out) != 0)
            error("IntPtrToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongLong((-0ll - 1), &out))
            error("IntPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &IntPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToUIntPtr), HRESULT (*)(_In_ INT_PTR, _Out_ UINT_PTR *)>::value)
            error("IntPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToUIntPtr(0x7fffffff, &out) != 0)
            error("IntPtrToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToUIntPtr((-0ll - 1), &out))
            error("IntPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ size_t *) __attribute__ ((unused)) = &IntPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToSizeT), HRESULT (*)(_In_ INT_PTR, _Out_ size_t *)>::value)
            error("IntPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0, &out) != 0)
            error("IntPtrToSizeT failed to convert 0");
        if(out != 0)
            error("IntPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToSizeT(0x7fffffff, &out) != 0)
            error("IntPtrToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToSizeT((-0ll - 1), &out))
            error("IntPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &IntPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToDWordPtr), HRESULT (*)(_In_ INT_PTR, _Out_ DWORD_PTR *)>::value)
            error("IntPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToDWordPtr(0x7fffffff, &out) != 0)
            error("IntPtrToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToDWordPtr((-0ll - 1), &out))
            error("IntPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_IntPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ INT_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &IntPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&IntPtrToULongPtr), HRESULT (*)(_In_ INT_PTR, _Out_ ULONG_PTR *)>::value)
            error("IntPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("IntPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(IntPtrToULongPtr(0x7fffffff, &out) != 0)
            error("IntPtrToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("IntPtrToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != IntPtrToULongPtr((-0ll - 1), &out))
            error("IntPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT *) __attribute__ ((unused)) = &LongPtrToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUInt), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT *)>::value)
            error("LongPtrToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0, &out) != 0)
            error("LongPtrToUInt failed to convert 0");
        if(out != 0)
            error("LongPtrToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUInt(0x7fffffff, &out) != 0)
            error("LongPtrToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUInt((-0ll - 1), &out))
            error("LongPtrToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG *) __attribute__ ((unused)) = &LongPtrToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG *)>::value)
            error("LongPtrToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0, &out) != 0)
            error("LongPtrToULong failed to convert 0");
        if(out != 0)
            error("LongPtrToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULong(0x7fffffff, &out) != 0)
            error("LongPtrToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULong((-0ll - 1), &out))
            error("LongPtrToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD *) __attribute__ ((unused)) = &LongPtrToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWord), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD *)>::value)
            error("LongPtrToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0, &out) != 0)
            error("LongPtrToDWord failed to convert 0");
        if(out != 0)
            error("LongPtrToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWord(0x7fffffff, &out) != 0)
            error("LongPtrToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWord((-0ll - 1), &out))
            error("LongPtrToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT *) __attribute__ ((unused)) = &LongPtrToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToInt), HRESULT (*)(_In_ LONG_PTR, _Out_ INT *)>::value)
            error("LongPtrToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0, &out) != 0)
            error("LongPtrToInt failed to convert 0");
        if(out != 0)
            error("LongPtrToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt(0x7fffffff, &out) != 0)
            error("LongPtrToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToInt((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongPtrToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ LONG *) __attribute__ ((unused)) = &LongPtrToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToLong), HRESULT (*)(_In_ LONG_PTR, _Out_ LONG *)>::value)
            error("LongPtrToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0, &out) != 0)
            error("LongPtrToLong failed to convert 0");
        if(out != 0)
            error("LongPtrToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong(0x7fffffff, &out) != 0)
            error("LongPtrToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToLong((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_LongPtrToULongLong()
{
    ULONGLONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONGLONG *) __attribute__ ((unused)) = &LongPtrToULongLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongLong), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONGLONG *)>::value)
            error("LongPtrToULongLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0, &out) != 0)
            error("LongPtrToULongLong failed to convert 0");
        if(out != 0)
            error("LongPtrToULongLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongLong(0x7fffffff, &out) != 0)
            error("LongPtrToULongLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULongLong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongLong((-0ll - 1), &out))
            error("LongPtrToULongLong did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ UINT_PTR *) __attribute__ ((unused)) = &LongPtrToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToUIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ UINT_PTR *)>::value)
            error("LongPtrToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToUIntPtr(0x7fffffff, &out) != 0)
            error("LongPtrToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToUIntPtr((-0ll - 1), &out))
            error("LongPtrToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ size_t *) __attribute__ ((unused)) = &LongPtrToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToSizeT), HRESULT (*)(_In_ LONG_PTR, _Out_ size_t *)>::value)
            error("LongPtrToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0, &out) != 0)
            error("LongPtrToSizeT failed to convert 0");
        if(out != 0)
            error("LongPtrToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToSizeT(0x7fffffff, &out) != 0)
            error("LongPtrToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToSizeT((-0ll - 1), &out))
            error("LongPtrToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &LongPtrToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToDWordPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ DWORD_PTR *)>::value)
            error("LongPtrToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToDWordPtr(0x7fffffff, &out) != 0)
            error("LongPtrToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToDWordPtr((-0ll - 1), &out))
            error("LongPtrToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &LongPtrToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToULongPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ ULONG_PTR *)>::value)
            error("LongPtrToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToULongPtr(0x7fffffff, &out) != 0)
            error("LongPtrToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != LongPtrToULongPtr((-0ll - 1), &out))
            error("LongPtrToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_LongPtrToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ LONG_PTR, _Out_ INT_PTR *) __attribute__ ((unused)) = &LongPtrToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&LongPtrToIntPtr), HRESULT (*)(_In_ LONG_PTR, _Out_ INT_PTR *)>::value)
            error("LongPtrToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0");
        if(out != 0)
            error("LongPtrToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr(0x7fffffff, &out) != 0)
            error("LongPtrToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("LongPtrToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(LongPtrToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("LongPtrToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("LongPtrToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT *) __attribute__ ((unused)) = &PtrdiffTToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT *)>::value)
            error("PtrdiffTToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUInt((-0ll - 1), &out))
            error("PtrdiffTToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG *) __attribute__ ((unused)) = &PtrdiffTToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULong), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG *)>::value)
            error("PtrdiffTToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0, &out) != 0)
            error("PtrdiffTToULong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULong(0x7fffffff, &out) != 0)
            error("PtrdiffTToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULong((-0ll - 1), &out))
            error("PtrdiffTToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD *) __attribute__ ((unused)) = &PtrdiffTToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWord), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD *)>::value)
            error("PtrdiffTToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWord(0x7fffffff, &out) != 0)
            error("PtrdiffTToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWord((-0ll - 1), &out))
            error("PtrdiffTToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ INT *) __attribute__ ((unused)) = &PtrdiffTToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToInt), HRESULT (*)(_In_ ptrdiff_t, _Out_ INT *)>::value)
            error("PtrdiffTToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0, &out) != 0)
            error("PtrdiffTToInt failed to convert 0");
        if(out != 0)
            error("PtrdiffTToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt(0x7fffffff, &out) != 0)
            error("PtrdiffTToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToInt((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ LONG *) __attribute__ ((unused)) = &PtrdiffTToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToLong), HRESULT (*)(_In_ ptrdiff_t, _Out_ LONG *)>::value)
            error("PtrdiffTToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0, &out) != 0)
            error("PtrdiffTToLong failed to convert 0");
        if(out != 0)
            error("PtrdiffTToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong(0x7fffffff, &out) != 0)
            error("PtrdiffTToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToLong((-0x7fffffffll - 1), &out) != 0)
            error("PtrdiffTToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("PtrdiffTToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_PtrdiffTToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ UINT_PTR *) __attribute__ ((unused)) = &PtrdiffTToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToUIntPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ UINT_PTR *)>::value)
            error("PtrdiffTToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToUIntPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToUIntPtr((-0ll - 1), &out))
            error("PtrdiffTToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ size_t *) __attribute__ ((unused)) = &PtrdiffTToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToSizeT), HRESULT (*)(_In_ ptrdiff_t, _Out_ size_t *)>::value)
            error("PtrdiffTToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0");
        if(out != 0)
            error("PtrdiffTToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToSizeT(0x7fffffff, &out) != 0)
            error("PtrdiffTToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToSizeT((-0ll - 1), &out))
            error("PtrdiffTToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &PtrdiffTToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToDWordPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ DWORD_PTR *)>::value)
            error("PtrdiffTToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToDWordPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToDWordPtr((-0ll - 1), &out))
            error("PtrdiffTToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_PtrdiffTToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ ptrdiff_t, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &PtrdiffTToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&PtrdiffTToULongPtr), HRESULT (*)(_In_ ptrdiff_t, _Out_ ULONG_PTR *)>::value)
            error("PtrdiffTToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0");
        if(out != 0)
            error("PtrdiffTToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(PtrdiffTToULongPtr(0x7fffffff, &out) != 0)
            error("PtrdiffTToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("PtrdiffTToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != PtrdiffTToULongPtr((-0ll - 1), &out))
            error("PtrdiffTToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToUInt()
{
    UINT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT *) __attribute__ ((unused)) = &SSIZETToUInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUInt), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT *)>::value)
            error("SSIZETToUInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0, &out) != 0)
            error("SSIZETToUInt failed to convert 0");
        if(out != 0)
            error("SSIZETToUInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUInt(0x7fffffff, &out) != 0)
            error("SSIZETToUInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToUInt changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUInt((-0ll - 1), &out))
            error("SSIZETToUInt did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULong()
{
    ULONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG *) __attribute__ ((unused)) = &SSIZETToULong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULong), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG *)>::value)
            error("SSIZETToULong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0, &out) != 0)
            error("SSIZETToULong failed to convert 0");
        if(out != 0)
            error("SSIZETToULong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULong(0x7fffffff, &out) != 0)
            error("SSIZETToULong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToULong changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULong((-0ll - 1), &out))
            error("SSIZETToULong did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWord()
{
    DWORD out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD *) __attribute__ ((unused)) = &SSIZETToDWord;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWord), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD *)>::value)
            error("SSIZETToDWord does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0, &out) != 0)
            error("SSIZETToDWord failed to convert 0");
        if(out != 0)
            error("SSIZETToDWord changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWord(0x7fffffff, &out) != 0)
            error("SSIZETToDWord failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToDWord changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWord((-0ll - 1), &out))
            error("SSIZETToDWord did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToInt()
{
    INT out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT *) __attribute__ ((unused)) = &SSIZETToInt;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToInt), HRESULT (*)(_In_ SSIZE_T, _Out_ INT *)>::value)
            error("SSIZETToInt does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0, &out) != 0)
            error("SSIZETToInt failed to convert 0");
        if(out != 0)
            error("SSIZETToInt changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt(0x7fffffff, &out) != 0)
            error("SSIZETToInt failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToInt changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToInt((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToInt failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToInt changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_SSIZETToLong()
{
    LONG out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ LONG *) __attribute__ ((unused)) = &SSIZETToLong;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToLong), HRESULT (*)(_In_ SSIZE_T, _Out_ LONG *)>::value)
            error("SSIZETToLong does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0, &out) != 0)
            error("SSIZETToLong failed to convert 0");
        if(out != 0)
            error("SSIZETToLong changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong(0x7fffffff, &out) != 0)
            error("SSIZETToLong failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToLong changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToLong((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToLong failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToLong changed (-0x7fffffffll - 1) to something else.");
    }

}

static void test_SSIZETToUIntPtr()
{
    UINT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ UINT_PTR *) __attribute__ ((unused)) = &SSIZETToUIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToUIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ UINT_PTR *)>::value)
            error("SSIZETToUIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToUIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToUIntPtr(0x7fffffff, &out) != 0)
            error("SSIZETToUIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToUIntPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToUIntPtr((-0ll - 1), &out))
            error("SSIZETToUIntPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToSizeT()
{
    size_t out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ size_t *) __attribute__ ((unused)) = &SSIZETToSizeT;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToSizeT), HRESULT (*)(_In_ SSIZE_T, _Out_ size_t *)>::value)
            error("SSIZETToSizeT does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0, &out) != 0)
            error("SSIZETToSizeT failed to convert 0");
        if(out != 0)
            error("SSIZETToSizeT changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToSizeT(0x7fffffff, &out) != 0)
            error("SSIZETToSizeT failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToSizeT changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToSizeT((-0ll - 1), &out))
            error("SSIZETToSizeT did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToDWordPtr()
{
    DWORD_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ DWORD_PTR *) __attribute__ ((unused)) = &SSIZETToDWordPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToDWordPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ DWORD_PTR *)>::value)
            error("SSIZETToDWordPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToDWordPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToDWordPtr(0x7fffffff, &out) != 0)
            error("SSIZETToDWordPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToDWordPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToDWordPtr((-0ll - 1), &out))
            error("SSIZETToDWordPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToULongPtr()
{
    ULONG_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ ULONG_PTR *) __attribute__ ((unused)) = &SSIZETToULongPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToULongPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ ULONG_PTR *)>::value)
            error("SSIZETToULongPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToULongPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToULongPtr(0x7fffffff, &out) != 0)
            error("SSIZETToULongPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToULongPtr changed 0x7fffffff to something else.");
    }

    // rejects minimum value - 1
    {
        if(INTSAFE_E_ARITHMETIC_OVERFLOW != SSIZETToULongPtr((-0ll - 1), &out))
            error("SSIZETToULongPtr did not overflow when given (-0ll - 1)");
    }

}

static void test_SSIZETToIntPtr()
{
    INT_PTR out;
    // Make sure it has the right type.
    {
        HRESULT (*tmp)(_In_ SSIZE_T, _Out_ INT_PTR *) __attribute__ ((unused)) = &SSIZETToIntPtr;
        #ifdef __cplusplus
        if(!std::is_same<decltype(&SSIZETToIntPtr), HRESULT (*)(_In_ SSIZE_T, _Out_ INT_PTR *)>::value)
            error("SSIZETToIntPtr does not have the right signature");
        #endif
    }

    // converts 0 to 0
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0");
        if(out != 0)
            error("SSIZETToIntPtr changed 0 to something else.");
    }

    // converts the maximum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr(0x7fffffff, &out) != 0)
            error("SSIZETToIntPtr failed to convert 0x7fffffff");
        if(out != 0x7fffffff)
            error("SSIZETToIntPtr changed 0x7fffffff to something else.");
    }

    // converts the minimum value
    {
        out = INITIAL_VALUE;
        if(SSIZETToIntPtr((-0x7fffffffll - 1), &out) != 0)
            error("SSIZETToIntPtr failed to convert (-0x7fffffffll - 1)");
        if(out != (-0x7fffffffll - 1))
            error("SSIZETToIntPtr changed (-0x7fffffffll - 1) to something else.");
    }

}

static void tests_conversions()
{
    test_UShortToUChar();
    test_UShortToByte();
    test_UShortToChar();
    test_UShortToShort();
    test_WordToUChar();
    test_WordToByte();
    test_WordToChar();
    test_WordToShort();
    test_ShortToUChar();
    test_ShortToByte();
    test_ShortToChar();
    test_ShortToUShort();
    test_ShortToWord();
    test_UIntToUChar();
    test_UIntToByte();
    test_UIntToChar();
    test_UIntToUShort();
    test_UIntToWord();
    test_UIntToShort();
    test_UIntToInt();
    test_UIntToLong();
    test_UIntToIntPtr();
    test_UIntToLongPtr();
    test_UIntToPtrdiffT();
    test_UIntToSSIZET();
    test_ULongToUChar();
    test_ULongToByte();
    test_ULongToChar();
    test_ULongToUShort();
    test_ULongToWord();
    test_ULongToShort();
    test_ULongToUInt();
    test_ULongToInt();
    test_ULongToLong();
    test_ULongToUIntPtr();
    test_ULongToIntPtr();
    test_ULongToLongPtr();
    test_ULongToPtrdiffT();
    test_ULongToSSIZET();
    test_DWordToUChar();
    test_DWordToByte();
    test_DWordToChar();
    test_DWordToUShort();
    test_DWordToWord();
    test_DWordToShort();
    test_DWordToUInt();
    test_DWordToInt();
    test_DWordToLong();
    test_DWordToUIntPtr();
    test_DWordToIntPtr();
    test_DWordToLongPtr();
    test_DWordToPtrdiffT();
    test_DWordToSSIZET();
    test_IntToUChar();
    test_IntToByte();
    test_IntToChar();
    test_IntToUShort();
    test_IntToWord();
    test_IntToShort();
    test_IntToUInt();
    test_IntToULong();
    test_IntToDWord();
    test_IntToULongLong();
    test_IntToUIntPtr();
    test_IntToSizeT();
    test_IntToDWordPtr();
    test_IntToULongPtr();
    test_LongToUChar();
    test_LongToByte();
    test_LongToChar();
    test_LongToUShort();
    test_LongToWord();
    test_LongToShort();
    test_LongToUInt();
    test_LongToULong();
    test_LongToDWord();
    test_LongToInt();
    test_LongToULongLong();
    test_LongToUIntPtr();
    test_LongToSizeT();
    test_LongToDWordPtr();
    test_LongToULongPtr();
    test_LongToIntPtr();
    test_LongToPtrdiffT();
    test_ULongLongToUInt();
    test_ULongLongToULong();
    test_ULongLongToDWord();
    test_ULongLongToInt();
    test_ULongLongToLong();
    test_ULongLongToInt64();
    test_ULongLongToUIntPtr();
    test_ULongLongToSizeT();
    test_ULongLongToDWordPtr();
    test_ULongLongToULongPtr();
    test_ULongLongToIntPtr();
    test_ULongLongToLongPtr();
    test_ULongLongToPtrdiffT();
    test_ULongLongToSSIZET();
    test_Int64ToUInt();
    test_Int64ToULong();
    test_Int64ToDWord();
    test_Int64ToInt();
    test_Int64ToLong();
    test_Int64ToULongLong();
    test_Int64ToUIntPtr();
    test_Int64ToSizeT();
    test_Int64ToDWordPtr();
    test_Int64ToULongPtr();
    test_Int64ToIntPtr();
    test_Int64ToLongPtr();
    test_Int64ToPtrdiffT();
    test_Int64ToSSIZET();
    test_UIntPtrToUInt();
    test_UIntPtrToULong();
    test_UIntPtrToDWord();
    test_UIntPtrToInt();
    test_UIntPtrToLong();
    test_UIntPtrToInt64();
    test_UIntPtrToIntPtr();
    test_UIntPtrToLongPtr();
    test_UIntPtrToSSIZET();
    test_SizeTToUInt();
    test_SizeTToULong();
    test_SizeTToDWord();
    test_SizeTToInt();
    test_SizeTToLong();
    test_SizeTToInt64();
    test_SizeTToIntPtr();
    test_SizeTToLongPtr();
    test_SizeTToPtrdiffT();
    test_SizeTToSSIZET();
    test_DWordPtrToUInt();
    test_DWordPtrToULong();
    test_DWordPtrToDWord();
    test_DWordPtrToInt();
    test_DWordPtrToLong();
    test_DWordPtrToInt64();
    test_DWordPtrToUIntPtr();
    test_DWordPtrToIntPtr();
    test_DWordPtrToLongPtr();
    test_DWordPtrToPtrdiffT();
    test_DWordPtrToSSIZET();
    test_ULongPtrToUInt();
    test_ULongPtrToULong();
    test_ULongPtrToDWord();
    test_ULongPtrToInt();
    test_ULongPtrToLong();
    test_ULongPtrToInt64();
    test_ULongPtrToUIntPtr();
    test_ULongPtrToIntPtr();
    test_ULongPtrToLongPtr();
    test_ULongPtrToPtrdiffT();
    test_ULongPtrToSSIZET();
    test_IntPtrToUInt();
    test_IntPtrToULong();
    test_IntPtrToDWord();
    test_IntPtrToInt();
    test_IntPtrToLong();
    test_IntPtrToULongLong();
    test_IntPtrToUIntPtr();
    test_IntPtrToSizeT();
    test_IntPtrToDWordPtr();
    test_IntPtrToULongPtr();
    test_LongPtrToUInt();
    test_LongPtrToULong();
    test_LongPtrToDWord();
    test_LongPtrToInt();
    test_LongPtrToLong();
    test_LongPtrToULongLong();
    test_LongPtrToUIntPtr();
    test_LongPtrToSizeT();
    test_LongPtrToDWordPtr();
    test_LongPtrToULongPtr();
    test_LongPtrToIntPtr();
    test_PtrdiffTToUInt();
    test_PtrdiffTToULong();
    test_PtrdiffTToDWord();
    test_PtrdiffTToInt();
    test_PtrdiffTToLong();
    test_PtrdiffTToUIntPtr();
    test_PtrdiffTToSizeT();
    test_PtrdiffTToDWordPtr();
    test_PtrdiffTToULongPtr();
    test_SSIZETToUInt();
    test_SSIZETToULong();
    test_SSIZETToDWord();
    test_SSIZETToInt();
    test_SSIZETToLong();
    test_SSIZETToUIntPtr();
    test_SSIZETToSizeT();
    test_SSIZETToDWordPtr();
    test_SSIZETToULongPtr();
    test_SSIZETToIntPtr();
}

static void tests_auto()
{
    tests_types();
    tests_conversions();
}

#endif /* __CHAR_UNSIGNED__ else */
#endif /* _WIN64 else */
void tests_all()
{
    tests_manual();
    tests_auto();
}

int main()
{
    tests_all();
    return 0;
}

#include <stdarg.h>
#include <stdio.h>
void error(const char * format, ...)
{
    va_list ap;
    va_start(ap, format);
    fprintf(stderr, "error: ");
    vfprintf(stderr, format, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}
