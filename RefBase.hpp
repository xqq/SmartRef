#ifndef _SMARTREF_REFBASE_HPP
#define _SMARTREF_REFBASE_HPP

#include <cstdint>
#include "Atomic.hpp"

namespace xl {

    class RefBase : public Noncopyable {
    protected:
        explicit RefBase() : mRefCount(0) {}
        virtual ~RefBase() = default;

        void AddRef() {
            AtomicIncrease(&mRefCount);
        }

        void Release() {
            if (!AtomicDecrease(&mRefCount)) {
                delete this;
            }
        }
    private:
        mutable int32_t mRefCount;
    };


    class RefBaseNonAtomic : public Noncopyable {
    protected:
        explicit RefBaseNonAtomic() : mRefCount(0) {}
        virtual ~RefBaseNonAtomic() = default;

        void AddRef() {
            ++mRefCount;
        }

        void Release() {
            if (0 == --mRefCount) {
                delete this;
            }
        }
    private:
        mutable int32_t mRefCount;
    };


}

#endif // _SMARTREF_REFBASE_HPP
