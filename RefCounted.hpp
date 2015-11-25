#ifndef _SMARTREF_RECOUNTED_HPP
#define _SMARTREF_RECOUNTED_HPP

#include <cstdint>
#include <cassert>
#include "Atomic.hpp"
#include "Noncopyable.hpp"

namespace xl {

    template <typename T>
    class RefCounted {
    protected:
        explicit RefCounted() : mRefCount(0) {}

        ~RefCounted() {
            assert(mRefCount == 0);
        }
    public:
        void AddRef() {
            AtomicIncrease(&mRefCount);
        }

        void Release() {
            if (!AtomicDecrease(&mRefCount)) {
                delete static_cast<const T*>(this);
            }
        }
    private:
        DISALLOW_COPY_AND_ASSIGN(RefCounted<T>);
    private:
        mutable int32_t mRefCount;
    };


    template <typename T>
    class RefCountedNonAtomic {
    protected:
        explicit RefCountedNonAtomic() : mRefCount(0) {}

        ~RefCountedNonAtomic() {
            assert(mRefCount == 0);
        }
    public:
        void AddRef() {
            ++mRefCount;
        }

        void Release() {
            if (0 == --mRefCount) {
                delete static_cast<const T*>(this);
            }
        }
    private:
        DISALLOW_COPY_AND_ASSIGN(RefCountedNonAtomic<T>);
    private:
        mutable int32_t mRefCount;
    };


}


#endif // _SMARTREF_RECOUNTED_HPP
