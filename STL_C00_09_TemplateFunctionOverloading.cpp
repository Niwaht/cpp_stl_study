#include <iostream>
using namespace std;

// We can overload a template function with a non-template function to specialize such function
template <typename T>
void f (T a, T b) {
    cout << "Template" << '\n';
    cout << a << ' ' << b << '\n';
}

void f (int a, int b) {
    cout << "Non-template" << '\n';
    cout << a << ' ' << b << '\n';
}

template <typename T>
T cmin (T p1, T p2) {
    if(p1 < p2) return p1;
    else return p2;
    // You can also do: return p1 < p2 ? p1 : p2;
}

template <typename T>
T cmin (T p1, T p2, T p3) {
    if(min(p1, p2) < p3) return min(p1, p2);
    else return p3;
}

int main()
{
    f(1, 2);
    f('a', 'b');
    f(1, 'b');      // Auto-converts 'b' to 98 (int)

    int i = cmin(9, 6);
    cout << "Minimum of integers: " << i << '\n';

    double d = cmin(10.5, 11.3);
    cout << "Minimum of doubles: " << d << '\n';
    /// You cannot do double d = (10, 11.3) because implicit casts are not allowed for template functions

    d = cmin<double>(10, 11.3);
    cout << "Minimum of integers and doubles: " << d << '\n';

    i = cmin(3, 6, 4);
    cout << "Minimum of 3 integers: " << i << '\n';

    return 0;
}
