#include <iostream>
#include <string>
using namespace std;

int main()
{
    /// Structure of lambda expressions
    /// auto lambda ([]( parameters ){ functions });
    auto just_one ([](){ return 1; });
    auto just_two ([]  { return 2; });
    cout << just_one() << ", " << just_two() << '\n';

    auto plus ([](auto l, auto r){ return l + r; });
    cout << plus(1, 2) << '\n';
    cout << plus(string{"a"}, "b") << '\n';

    // Creating lambdas in place
    cout << [](auto l, auto r){ return l+r; }(1, 2) << '\n';

    /// Closure
    auto counter ([count = 0]() mutable { return ++count; });
    for (size_t i {0}; i < 5; ++i) {
        cout << counter() << ", ";
    }

    // Closure with reference
    int a {0};
    auto incrementer ([&a]{ ++a; });
    incrementer();
    incrementer();
    incrementer();
    cout << "Value of 'a' after 3 incrementer() calls: " << a << '\n';

    /// Currying
    auto plus_ten ([=](int x){ return plus(10, x); });
    cout << plus_ten(5) << '\n';

    return 0;
}
