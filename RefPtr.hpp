#ifndef _SMARTREF_REFPTR_HPP
#define _SMARTREF_REFPTR_HPP

#include <cassert>

namespace xl {

    template <typename T>
    class RefPtr {
    public:
        RefPtr() : ptr(nullptr) {}

        ~RefPtr() {
            if (ptr) {
                ptr->Release();
                ptr = nullptr;
            }
        }

        RefPtr(T* p) : ptr(p) {
            if (ptr) {
                ptr->AddRef();
            }
        }

        RefPtr(const RefPtr<T>& r) : ptr(r.ptr) {
            if (ptr) {
                ptr->AddRef();
            }
        }

        template <typename U>
        RefPtr(const RefPtr<U>& r) : ptr(r.Get()) {
            if (ptr) {
                ptr->AddRef();
            }
        }

        template <typename U>
        RefPtr(RefPtr<U>&& r) : ptr(r.Get()) {
            r.ptr = nullptr;
        }

        T* Get() const {
            return ptr;
        }

        T** GetAddressOf() const {
            return &ptr;
        }

        T& operator*() const {
            assert(ptr != nullptr);
            return *ptr;
        }

        T* operator->() const {
            assert(ptr != nullptr);
            return ptr;
        }

        T** operator&() {
            if (ptr) {
                ptr->Release();
                ptr = nullptr;
            }
            return &ptr;
        }

        RefPtr<T>& operator=(T* p) {
            if (p) {
                p->AddRef();
            }
            T* old = ptr;
            ptr = p;
            if (old) {
                old->Release();
            }
            return *this;
        }

        RefPtr<T>& operator=(const RefPtr<T>& r) {
            return operator=(r.ptr);
        }

        template <typename U>
        RefPtr<T> operator=(const RefPtr<U>& r) {
            return operator=(r.Get());
        }

        RefPtr<T> operator=(RefPtr<T>&& r) {
            RefPtr<T>(std::move(r)).Swap(*this);
            return *this;
        }

        template <typename U>
        RefPtr<T> operator=(RefPtr<U>&& r) {
            RefPtr<T>(std::move(r)).Swap(*this);
            return *this;
        }

        template <typename U>
        bool operator==(const RefPtr<U>& rhs) const {
            return ptr == rhs.Get();
        }

        template <typename U>
        bool operator!=(const RefPtr<U>& rhs) const {
            return ptr != rhs.Get();
        }

        template <typename U>
        bool operator<(const RefPtr<U>& rhs) const {
            return ptr < rhs.Get();
        }

        void Reset(T* p) {
            operator=(p);
        }

        void Reset() {
            Reset(nullptr);
        }

        void Swap(T** pp) {
            T* old = ptr;
            ptr = *pp;
            *pp = old;
        }

        void Swap(RefPtr<T>& r) {
            Swap(&r.ptr);
        }
    private:
        template <typename U>
        friend class RefPtr;

        typedef T* RefPtr::*Testable;
    public:
        operator Testable() const {
            return ptr ? &RefPtr::ptr : nullptr;
        }
    private:
        T* ptr;
    };

}

#endif // _SMARTREF_REFPTR_HPP
