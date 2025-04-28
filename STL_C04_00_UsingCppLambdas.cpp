#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

/*
void print_it(int i)
{
    cout << ":" << i << ":\n";
}
*/

int main()
{
    list int_list {1, 2, 5, 4, 3, 6, 8, 7, 9};

    // for_each(int_list.begin(), int_list.end(), print_it);
    /// Use lambdas instead:
    for_each(int_list.begin(), int_list.end(), [](int i){ cout << ":" << i << ":\n"; });
    cout << '\n';

    [](int i){ cout << ":" << i << ":\n"; }(42);        /// Lambda call right after declaration

    /// Keeping lambdas as function objects
    auto emote = [](int i){ cout << ":" << i << ":\n"; };
    emote(43);
    cout << '\n';

    // Possible forms of lambdas:
    [](){ cout << "Hello from trivial lambda!" << '\n'; }();

    if([](int i, int j){ return 2*i == j; }(12, 24)) cout << "It's true!\n";
    else cout << "It's false!\n";

    cout << "This lambda returns " << [](int x, int y) -> int {
        if(x > 5) return x + y;
        else if (y < 2) return x - y;
        else return x * y;
    }(4, 3) << '\n';

    cout << "This lambda returns " << [](double x, double y) -> int {
        return x + y;
    }(3.14, 2.7) << '\n';

    cout << '\n';
    return 0;
}
