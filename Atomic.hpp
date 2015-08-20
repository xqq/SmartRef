#ifndef _SMARTREF_ATOMIC_HPP
#define _SMARTREF_ATOMIC_HPP

namespace xl {

    // Increase a int32 value by 1.
    inline void AtomicIncrease(volatile int32_t* ptr);

    // Decrease a int32 value by 1, and return whether the result is non-zero.
    inline bool AtomicDecrease(volatile int32_t* ptr);

}

#if defined(__GNUC__) || defined(__clang__)
    #include "Atomic_GCC.hpp"
#elif defined(_WIN32) || defined(_MSC_VER)
    #include "Atomic_Win32.hpp"
#elif
    #error "Unsupported compiler"
#endif

#endif // _SMARTREF_ATOMIC_HPP
