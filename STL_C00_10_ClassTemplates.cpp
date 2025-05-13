#include <iostream>
#include "type_wrapper.h"
#include "pair.h"

template <typename T>
class Container {
    T element;
public:
    explicit Container(const T &arg) : element(arg) {}

    T increase() { return ++element; }
};

template <typename T>
struct Class_A {
    T *p_;

    explicit Class_A(T *p) : p_(p) {
        cout << typeid(p).name() << '\n';
    }

    void f(T *t) const {
        cout << typeid(t).name() << '\n';
    }
};

struct Class_B {
    template <typename T>
    void mf(T *t) {
        cout << typeid(t).name() << '\n';
    }
};

template <typename T>
struct Class_C {
    template <typename U>
    void mf(U u, T *t) {
        cout << typeid(u).name() << '\n';
        cout << typeid(t).name() << '\n';
    }
};

int main()
{
    {
        type_wrapper<int> p1(10);
        type_wrapper<int> p2(20);

        my_pair::pair<type_wrapper<int>> i_pair(p1, p2);

        std::cout << "The max of " << p1 << " and " << p2 << " is " << i_pair.max() << '\n';
    }

    {
        double d1 = 100.4;
        double d2 = 200.8;

        my_pair::pair<double> d_pair(d1, d2);

        std::cout << "The max of " << d1 << " and " << d2 << " is " << d_pair.max() << '\n';
    }

    Container<int> myInt(7);
    cout << myInt.increase() << '\n';

    long l;
    Class_A<long> a(&l);
    a.f(&l);

    int i;
    double d;
    Class_B b;
    b.mf(&i);
    b.mf(&d);

    Class_C<int> c;
    Class_C<double> cc;

    c.mf(10, &i);
    cc.mf(20.5, &d);

    return 0;
}
