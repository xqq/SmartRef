#include <cstdio>
#include <cstdlib>
#include "SmartRef.hpp"

using namespace xl;

class FooClass : public xl::RefBase {
public:
    inline static RefPtr<FooClass> Create(int arg) {
        return RefPtr<FooClass>(new FooClass(arg));
    }
public:
    explicit FooClass(int arg) : mArg(arg) {}

    virtual ~FooClass() override {
        printf("destructor for FooClass\n");
    }

    void Fuck() {
        printf("Fuck you!\n");
    }
private:
    int mArg;
};

int main(int argc, char** argv) {
    RefPtr<FooClass> smart = FooClass::Create(23333);
    RefPtr<FooClass> yooo(smart);

    FooClass& obj = *yooo;
    obj.Fuck();

    yooo.Reset();
    smart.Reset();

    printf("attempt to return from main\n");
    getchar();
    return 0;
}