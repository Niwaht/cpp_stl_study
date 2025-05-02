#include <iostream>
using namespace std;

static void print(int x, int y) {
    cout << "(" << x << ", " << y << ")\n";
}

int main()
{
    constexpr auto call_cart (
        [=](auto f, auto x, auto ...rest) constexpr {
            (void)initializer_list<int>{
                (((x < rest)
                ? (void)f(x, rest)
                : (void)0)
            ,0)...
        };
    });

    constexpr auto cartesian ([=](auto ...xs) constexpr {
        return [=](auto f) constexpr {
            (void)initializer_list<int>{
                ((void)call_cart(f, xs, xs...), 0)...
            };
        };
    });

    constexpr auto print_cart (cartesian(1, 2, 3));

    print_cart(print);

    return 0;
}
