#ifndef _SMARTREF_ATOMIC_WIN32_HPP
#define _SMARTREF_ATOMIC_WIN32_HPP

#include <cstdint>
#include <intrin.h>

namespace xl {

    inline void AtomicIncrease(volatile int32_t* ptr) {
        _InterlockedIncrement(static_cast<long*>(ptr));
    }

    inline bool AtomicDecrease(volatile int32_t* ptr) {
        return 0 != _InterlockedDecrement(static_cast<long*>(ptr));
    }

}

#endif // _SMARTREF_ATOMIC_WIN32_HPP
