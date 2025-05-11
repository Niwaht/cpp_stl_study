#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

long sum(long a, long b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

/// Function templates are special functions that can operate on different data types
/// without code separation for each of them.

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, typename U>
U add(T a, U b) {
    return a + b;
}

template <typename R, typename T, typename U>
R max(T a, U b) {
    return a < b ? b : a;
}

int main()
{
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;
    double a = 10.5, b = 5.5, d;

    k = sum(i, j);
    n = sum(l, m);
    d = sum(a, b);
    cout << "Via plus:\n" << k << '\n' << n << '\n' << d << '\n';

    k = add<int>(i, j);
    n = add<long>(l, m);
    d = add<double>(a, b);
    cout << "Via add:\n" << k << '\n' << n << '\n' << d << '\n';

    k = add(i, j);
    n = add(l, m);
    d = add(10.5, 16.7);
    cout << "Via add (with argument deduction):\n" << k << '\n' << n << '\n' << d << '\n';

    int p = add(i, l);
    cout << "Via add (with 2 templates):\n" << p << '\n';

    d = max<double>(5.5, 2);
    i = max<int, char, char>('a', 'b');
    cout << "Via max:\n" << d << '\n' << i << '\n';

    return 0;
}
