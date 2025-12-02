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
    for(int i = 0; i < (int)s.length(); i++) cout << s[i] << ' ';
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

/// Stacks
#include <stack>
void main_19() {
    cout << "\nStacks\n----------------------------------------\n";
    stack<int> st;
    st.emplace(1);
    st.emplace(2);
    cout << st.top() << ' ';
    st.pop();
    cout << st.top() << '\n';
}

/// Queues
#include <queue>
void main_20() {
    cout << "\nQueues\n----------------------------------------\n";
    queue<int> q;
    q.emplace(1);
    q.emplace(2);
    cout << q.front() << ' ';
    q.pop();
    cout << q.front() << '\n';
}

/// Lists
#include <list>
void main_21() {
    cout << "\nLists\n----------------------------------------\n";
    list l{10, 20};
    l.emplace_back(30);
    l.emplace_front(0);
    cout << l.front() << ' ' << l.back() << '\n';
    auto it = l.begin();
    it++;
    it = l.erase(it);
    for(auto x : l) cout << x << ' ';
    cout << '\n';
    it++;
    it = l.emplace(it, 25);
    for(auto x : l) cout << x << ' ';
    cout << '\n';
    l.emplace(l.end(), 40);
    for(auto x : l) cout << x << ' ';
    cout << '\n'
         << *it << '\n';
}

/// Priority queues
void main_22() {
    cout << "\nPriority queues\n----------------------------------------\n";
    priority_queue<int> q;
    q.emplace(1);
    q.emplace(2);
    q.emplace(3);
    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << '\n';
}

/// Min heaps via self-defined struct
void main_23() {
    cout << "\nMin heaps via self-defined struct\n----------------------------------------\n";
    struct cmp {
        bool operator()(int a, int b){ return a > b; }
    };

    priority_queue<int, vector<int>, cmp> q;
    q.emplace(1);
    q.emplace(2);
    q.emplace(3);
    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << '\n';
}

/// Min heaps via self-defined lambda expression
void main_24() {
    cout << "\nMin heaps via self-defined lambda expr.\n----------------------------------------\n";
    auto cmp = [](int a, int b){ return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.emplace(1);
    q.emplace(2);
    q.emplace(3);
    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << '\n';
}

/// Sets
#include <set>
void main_25() {
    cout << "\nSets\n----------------------------------------\n";
    set s{1, 2, 2, 3, 4};
    s.emplace(5);
    cout << s.size() << ' ';
    s.erase(2);
    auto it = s.lower_bound(2);
    if(it != s.end()) cout << *it << ' ';
    else cout << "None\n";
    it = s.emplace(5).first;
    cout << *it << ' ';
    s.erase(it);
    it = s.find(3);
    if(it != s.end()) cout << *it << '\n';
    else cout << "None\n";
    for(auto x : s) cout << x << ' ';
    cout << '\n';
}

/// Multisets
void main_26() {
    cout << "\nMultisets\n----------------------------------------\n";
    multiset s{1, 2, 2, 3, 4};
    s.emplace(5);
    cout << s.size() << ' ';
    s.erase(2);
    auto it = s.lower_bound(2);
    if(it != s.end()) cout << *it << ' ';
    else cout << "None\n";
    it = s.emplace(5);
    cout << *it << ' ';
    s.erase(it);
    it = s.find(3);
    if(it != s.end()) cout << *it << '\n';
    else cout << "None\n";
    for(auto x : s) cout << x << ' ';
    cout << '\n';
}

/// Maps
#include <map>
void main_27() {
    cout << "\nMaps\n----------------------------------------\n";
    map<int, int> mp;
    auto it = mp.emplace(1, 2).first;
    cout << it->first << ' ' << it->second << ", ";
    mp[2] = 0;
    mp[2]++;
    it = mp.find(2);
    if(it != mp.end()) cout << it->first << ' ' << it->second << '\n';
    else cout << "None\n";
    for(auto [key, val] : mp) cout << key << ' ' << val << '\n';
}

/// Hash function via self-defined class
void main_28() {
    cout << "\nHash function via self-defined class\n----------------------------------------\n";
    struct Hash {
        int operator()(pair<int, int> x) const { return x.first + x.second; }
    };
    unordered_map<pair<int, int>, int, Hash> mp;
    cout << "Hash function created\n";
}

/// Bitsets
#include <bitset>
#define csn cout << s << '\n'
void main_29() {
    cout << "\nBitsets\n----------------------------------------\n";
    bitset<10> s(100);
    cout << s << ' ';
    cout << s.count() << '\n';
    s.set(0); csn;
    s.reset(3); csn;
    s.flip(1); csn;
    s[5] = 0; csn;
    s.reset(); csn;
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7(); main_8(); main_9(); main_10();
    main_11(); main_12(); main_13(); main_14(); main_15(); main_16(); main_17(); main_18(); main_19(); main_20();
    main_21(); main_22(); main_23(); main_24(); main_25(); main_26(); main_27(); main_28(); main_29();
    return 0;
}
