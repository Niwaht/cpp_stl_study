#include <iostream>
using namespace std;

/// Comparisons via normal function
#include <vector>
#include <algorithm>
bool cmp(int a, int b) { return a > b; }
void main_1() {
    cout << "Comparisons via normal function\n----------------------------------------\n";
    vector<int> a = {1, 4, 2, 3, 5};
    sort(a.begin(), a.end(), cmp);
    for(auto x : a) cout << x << ' ';
    cout << '\n';
}

/// Lambda expressions
void main_2() {
    cout << "\nLambda expressions\n----------------------------------------\n";
    auto sum = [](int a, int b){ return a + b; };
    cout << sum(1, 2) << '\n';
    auto generic_sum = [](auto a, auto b){ return a + b; };
    cout << generic_sum(1.2, 3.4) << '\n';
    cout << generic_sum(5.6, 7) << '\n';
}

/// Recursive lambdas via function
#include <functional>
void main_3() {
    cout << "\nRecursive lambdas via function\n----------------------------------------\n";
    function<int(int)> fib;
    fib = [&](int n) {
        if(n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    };
    cout << fib(15) << '\n';
}

/// Recursive lambdas via passing itself
void main_4() {
    cout << "\nRecursive lambdas via passing itself\n----------------------------------------\n";
    auto fib = [](auto&& self, int n) {
        if(n <= 1) return n;
        return self(self, n - 1) + self(self, n - 2);
    };
    cout << fib(fib, 15) << '\n';
}

/// Comparisons via lambda expression
void main_5() {
    cout << "\nComparisons via lambda expression\n----------------------------------------\n";
    vector<int> a = {1, 4, 2, 3, 5};
    sort(a.begin(), a.end(), [](int a, int b){ return a > b; });
    for(auto x : a) cout << x << ' ';
    cout << '\n';
}

/// Binary search functions
#define abeg a.begin()
#define aend a.end()
void main_6() {
    cout << "\nBinary search functions\n----------------------------------------\n";
    vector a = {1, 2, 2, 4, 5};
    cout << lower_bound(abeg, aend, 2) - abeg << ' '
         << lower_bound(abeg, aend, 3) - abeg << ' '
         << *lower_bound(abeg, aend, 2) << ' '
         << *lower_bound(abeg, aend, 3) << ' '
         << upper_bound(abeg, aend, 2) - abeg << ' '
         << upper_bound(abeg, aend, 3) - abeg << ' '
         << *upper_bound(abeg, aend, 2) << ' '
         << *upper_bound(abeg, aend, 3) << ' '
         << binary_search(abeg, aend, 2) << ' '
         << binary_search(abeg, aend, 3) << '\n';
}

/// Unique
void main_7() {
    cout << "\nUnique\n----------------------------------------\n";
    vector a = {1, 2, 2, 4, 2};
    auto it = unique(abeg, aend);
    cout << it - abeg << '\n' << a.size() << '\n';
    for(auto x : a) cout << x << ' ';
    cout << '\n';
    a.erase(it, aend);
    cout << a.size() << '\n';
    for(auto x : a) cout << x << ' ';
    cout << '\n';
}

/// Discretization
void main_8() {
    cout << "\nDiscretization\n----------------------------------------\n";
    vector a = {748934, 23, 3232, 1, 328490, 2342, 123, 1, 2342, 123, 3232, 1};
    vector b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(auto& x : a) x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    for(auto x : a) cout << x << ' ';
    cout << '\n';
}

/// Iteration over a string
#include <string>
void main_9() {
    cout << "\nIteration over a string\n----------------------------------------\n";
    string s = "abcdef";
    for(int i = 0; i < s.length(); i++) cout << s[i] << ' ';
    cout << '\n';
    for(char& c : s) c -= 32;
    cout << s << '\n';
}

/// Using string::iterator
void main_10() {
    cout << "\nUsing string::iterator\n----------------------------------------\n";
    string s = "abcdef";
    for(auto it = s.begin(); it != s.end(); ++it) cout << *it << ' ';
    cout << '\n';
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

/// Concatenating strings
void main_11() {
    cout << "\nConcatenating strings\n----------------------------------------\n";
    string s = "ab", t = "d";
    s += 'c';   // append a character
    t += "ef";  // append a string
    cout << s.length() << '\n'
         << s + t << '\n';
}

/// Comparing strings
void main_12() {
    cout << "\nComparing strings\n----------------------------------------\n";
    cout << ("abc"s == "abc"s) << ' '
         << ("abc"s  < "def"s) << ' '
         << ("abcd"s > "abc"s) << ' '
         << "abc"s.compare("abx") << ' '
         << "xyz"s.compare("xyz") << ' '
         << "def"s.compare("a") << '\n';
}

/// Reading one line
void main_13() {
    cout << "\nReading one line\n----------------------------------------\n";
    string s = "it is a good day to die";
    // getline(cin, s);
    cout << s << '\n';
    s = "it";
    // cin >> s;
    cout << s << '\n';
}

/// Finding string
void main_14() {
    cout << "\nFinding string\n----------------------------------------\n";
    string s = "This is a string";
    int n = s.find("is");
    cout << n << ' ';
    n = s.find("is", 5);
    cout << n << ' ';
    n = s.find('q');
    cout << n << ' '
         << string::npos << '\n';
}

/// Modifying string
void main_15() {
    cout << "\nModifying string\n----------------------------------------\n";
    string s = "abc";
    s.insert(1, "abc", 2);
    cout << s << ' ';
    s.erase(3);
    cout << s << ' ';
    s.replace(1, 1, "123");
    cout << s << '\n';
}

/// Getting substring
void main_16() {
    cout << "\nGetting substring\n----------------------------------------\n";
    string s = "https://judge.hkoi.org";
    cout << s.substr(14, 4) << ' '
         << s.substr(8) << '\n';
}

/// String conversion [since C++11]
void main_17() {
    cout << "\nString conversion [since C++11]\n----------------------------------------\n";
    string s = "123";
    int a = stoi(s);
    cout << to_string(a + 1) << ' ';
    s += ".456";
    double b = stod(s);
    cout << to_string(b + 0.123) << '\n';
}

/// Deques
#include <deque>
void main_18() {
    cout << "\nDeques\n----------------------------------------\n";
    deque q{4, 5, 6};
    q.emplace_front(3);
    q.emplace_back(7);
    cout << q[2] << ' ';
    q.pop_back();
    cout << q.back() << ' ';
    q.pop_front();
    cout << q.front() << '\n';
    for(auto x : q) cout << x << ' ';
    cout << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7(); main_8(); main_9(); main_10();
    main_11(); main_12(); main_13(); main_14(); main_15(); main_16(); main_17(); main_18();
    return 0;
}
