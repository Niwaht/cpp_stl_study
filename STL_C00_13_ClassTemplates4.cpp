#include <iostream>
#include "container.h"
using namespace std;

template <> class container <char*> {
    char* element;
public:
    explicit container (char* arg): element(arg) {}
    char* uppercase();
};

char* container<char*>::uppercase() {
    for(int i=0; element[i] != '\0'; ++i)
        if((element[i] >= 'a') && (element[i] <= 'z')) element[i] += 'A' - 'a';
    return element;
}

class Foo {
    int i_;
public:
    explicit Foo(int i): i_(i) {}
    explicit operator int() const { return i_; }
    Foo operator++() {
        cout << "Foo::operator++" << '\n';
        return Foo(++i_);
    }
};

ostream &operator<<(ostream &os, const Foo& foo) {
    return os << int(foo);
}

template <> class container<Foo> {
    Foo element;
public:
    explicit container (Foo arg): element(arg) {}
    Foo increase() {
        cout << "container<Foo>::increase()" << '\n';
        return ++element;
    }
};

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
template <typename T>
T minimum(const T& i, const T& j) {
    return i < j ? i : j;
}

int main()
{
    container<int> myint(7);
    container<double> mydouble(10.5);
    char lowercase[] = "hello world";
    container<char*> mystring(lowercase);
    container<Foo> myFoo(Foo(10));

    cout << myint.increase() << '\n'
         << mydouble.increase() << '\n'
         << mystring.uppercase() << '\n'
         << myFoo.increase() << '\n';

    int a = 10, b = 20;
    cout << "min = " << minimum(a++, b++) << '\n'
         << "a = " << a << " b = " << b << '\n'
         << "MIN = " << MIN(a++, b++) << '\n'
         << "a = " << a << " b = " << b << '\n';

    return 0;
}
