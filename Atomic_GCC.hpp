#ifndef _SMARTREF_ATOMIC_GCC_HPP
#define _SMARTREF_ATOMIC_GCC_HPP

namespace xl {

    inline void AtomicIncrease(volatile int32_t* ptr) {
        __sync_fetch_and_add(ptr, 1);
    }

    inline bool AtomicDecrease(volatile int32_t* ptr) {
        return __sync_sub_and_fetch(ptr, 1) != 0;
    }

}

#endif // _SMARTREF_ATOMIC_GCC_HPP
