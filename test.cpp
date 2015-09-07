#include <cstdio>
#include <cstdlib>
#include <vector>
#include "SmartRef.hpp"

using namespace xl;

class FooClass : public xl::RefCounted<FooClass> {
public:
    inline static RefPtr<FooClass> Create(int arg) {
        return RefPtr<FooClass>(new FooClass(arg));
    }
public:
    explicit FooClass(int arg) : mArg(arg) {}

    ~FooClass() {
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

    std::vector<RefPtr<FooClass>> vec;

    for (int i = 0; i <= 1000; i++) {
        vec.push_back(RefPtr<FooClass>(smart));
    }
    vec.clear();

    FooClass& obj = *yooo;
    obj.Fuck();

    yooo.Reset();
    smart.Reset();

    printf("attempt to return from main\n");
    getchar();
    return 0;
}