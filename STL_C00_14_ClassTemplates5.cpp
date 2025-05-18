#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;

template <typename T>
void print_data_type(const T& a) {
    cout << typeid(a).name() << '\n';
}

template <typename T>
struct example_class {
    example_class() {};
    T result(T t) { return t; }
    void add(const T& t) {}
};

template void print_data_type<int>(const int&);
template void print_data_type<double>(const double&);
template example_class<int>::example_class();
template struct example_class<double>;
template example_class<string>::example_class();
template void example_class<string>::add(const string&);
template string example_class<string>::result(string);

/// Template recursions
template <typename T>
T adder(T v) {
    cout << __PRETTY_FUNCTION__ << '\n';
    return v;
}

// Variadic template
template <typename T, typename... Args>
T adder(T first, Args... args) {
    cout << __PRETTY_FUNCTION__ << '\n';
    return first + adder(args...);
}


int main()
{
    example_class<int> ai;
    example_class<double> ad;

    cout << "ai type = ";
    print_data_type(ai);
    cout << "ad type = ";
    print_data_type(ad);

    auto sum = adder(1, 4, 2, 3, 8, 7);
    cout << "sum = " << sum << '\n';

    string s1 = "C++", s2 = " ", s3 = "is", s4 = " ", s5 = "cool!";
    auto string_sum = adder(s1, s2, s3, s4, s5);
    cout << "string_sum = " << string_sum << '\n';

    return 0;
}
