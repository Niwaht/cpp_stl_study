#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include "memblock.h"
using namespace std;

// Template classes (but not template functions) can take default template parameters.
template <typename T = int>             // Sets T to int by default.
class stack {
    vector<T> s;
public:
    // ...
};

template <typename T, template <typename ...> class container = deque>
class stackcon {
    container<T> s;
public:
    void push(const T &t) { s.push_back(t); }
    void pop() { s.pop_back(); }
    T top() { return s.back(); }
    // ...
};

// A function can define 'non-type' function template parameters.
template <typename T, int V>
T add (const T &n) {
    return n + V;
}

int main()
{
    stack<double> a_stack_of_doubles;
    stack<> a_stack_of_ints;            // Uses default template type.
    /// 'stack a_stack_of_ints;' is not allowed

    memblock<int, 5> my_ints;
    memblock<double, 15> my_doubles;
    my_ints.setmem(0, 100);
    my_doubles.setmem(3, 3.1416);
    cout << my_ints.getmem(0) << '\n'
         << my_doubles.getmem(3) << '\n';

    int i = add<int, 6>(10);
    cout << "i = " << i << '\n';

    stackcon<string> a_deque_stack_of_strings;      // Container type defaults to deque.
    stackcon<int, list> a_list_stack_of_ints;       // Container type is specified to be list.

    a_deque_stack_of_strings.push("hello");
    string s = a_deque_stack_of_strings.top();
    cout << "s = " << s << '\n';
    a_deque_stack_of_strings.pop();

    a_list_stack_of_ints.push(42);
    int j = a_list_stack_of_ints.top();
    cout << "j = " << j << '\n';
    a_list_stack_of_ints.pop();

    return 0;
}
