#include <iostream>
using namespace std;

/// Sets
#include <set>
void main_1() {
    cout << "Sets\n----------------------------------------\n";
    set<int> s;
    s.insert(4); s.insert(6); s.insert(9);
    cout << "Size = " << s.size() << '\n';
    for(auto str: s) cout << str << ' ';
    cout << '\n';
    if(s.find(4) != s.end()) cout << "4 is in the BST\n";
    s.erase(6);
    cout << "After deletion:\n";
    for(auto str: s) cout << str << ' ';
    cout << '\n';
}

/// Lower bounds and upper bounds
void main_2() {
    cout << "\nLower bounds and upper bounds\n----------------------------------------\n";
    set<int> s;
    s.insert(9); s.insert(4); s.insert(6);
    cout << "Size = "             << s.size()          << '\n'
         << "min = "              << *s.begin()        << '\n'
         << "Max = "              << *s.rbegin()       << '\n'
         << "Lower bound of 6 = " << *s.lower_bound(6) << '\n'
         << "Upper bound of 6 = " << *s.upper_bound(6) << '\n';
}

/// Maps
#include <map>
#define ins insertValue
#define del eraseValue
#define print printMap
void main_3() {
    cout << "\nMaps\n----------------------------------------\n";
    map<int, int> mp;
    auto insertValue = [&](int x){ mp[x]++; };
    auto eraseValue = [&](int x){ mp[x]--; if(mp[x] == 0) mp.erase(x); };
    auto printMap = [&](){
        cout << "Current map content:\n";
        for(auto &p : mp) cout << "Value = " << p.first << ", Count = " << p.second << '\n';
        cout << "-----------------------------\n";
    };
    ins(5); ins(5); ins(3); ins(7); ins(3); print();
    del(5); print(); del(3); print();
}

/// Multiset operations
void main_4() {
    cout << "\nMultiset operations\n----------------------------------------\n";
    multiset<int> bst;
    int N, x;
    // cin >> N;
    N = 5;
    // for(int i = 0; i < N; i++) { cin >> x; bst.insert(x); }
    for(int i = 0; i < N; i++) { bst.insert(i + 1); }
    cout << "Before: ";
    for(int v : bst) cout << v << ' ';
    cout << "\nMin = " << *bst.begin()  << '\n'
         <<   "Max = " << *bst.rbegin() << '\n';
    bst.erase(bst.begin());
    auto it = bst.end();
    it--;
    bst.erase(it);
    cout << "After: ";
    for(int v : bst) cout << v << ' ';
    cout << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
