#ifndef _SMARTREF_REFBASE_HPP
#define _SMARTREF_REFBASE_HPP

#include <cstdint>

namespace xl {

    class RefBase {
    public:
        void AddRef();
        void Release();
    private:
        mutable int32_t mRefCount;
    };

}

#endif // _SMARTREF_REFBASE_HPP
