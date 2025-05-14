#include <iostream>
#include "container.h"
using namespace std;

template <> class container<char> {
    char element;
public:
    explicit container (char arg): element(arg) {}
    char uppercase ();
};

char container<char>::uppercase() {
    if((element >= 'a') && (element <= 'z')) element += 'A' - 'a';
    return element;
}

/// Partially specialized class templates
template <typename T, typename U>
struct Class {
    Class() { cout << "Class <T, U>\n"; }
};

template <typename T>
struct Class <T, T> {
    Class() { cout << "Class <T, T>\n"; }
};

template <typename T>
struct Class <T, int> {
    Class() { cout << "Class <T, int>\n"; }
};

template <typename T, typename U>
struct Class <T*, U*> {
    Class() { cout << "Class <T*, U*>\n"; }
};

int main()
{
    container<int> myint(7);
    container<double> mydouble(10.5);
    container<char> mychar('j');

    cout << myint.increase() << '\n'
         << mydouble.increase() << '\n'
         << mychar.uppercase() << '\n';

    Class<int, double> a;       // Class <T, U>
    Class<double, double> b;    // Class <T, T>
    Class<double, int> c;       // Class <T, int>
    Class<int*, double*> d;     // Class <T*, U*>
    // Class<int, int> e;       // Ambiguous

    return 0;
}
