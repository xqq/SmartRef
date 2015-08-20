#ifndef _SMARTREF_NONCOPYABLE_HPP
#define _SMARTREF_NONCOPYABLE_HPP

namespace xl {

    class Noncopyable {
    public:
        explicit Noncopyable() = default;
        ~Noncopyable() = default;
    private:
        explicit Noncopyable(const Noncopyable&) = delete;
        Noncopyable& operator=(const Noncopyable&) = delete;
    };

}

#endif // _SMARTREF_NONCOPYABLE_HPP
