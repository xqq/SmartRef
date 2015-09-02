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

#ifndef DISALLOW_COPY_AND_ASSIGN
    #define DISALLOW_COPY_AND_ASSIGN(TypeName) \
        TypeName(const TypeName&) = delete;    \
        TypeName& operator=(const TypeName&) = delete;
#endif

}

#endif // _SMARTREF_NONCOPYABLE_HPP
