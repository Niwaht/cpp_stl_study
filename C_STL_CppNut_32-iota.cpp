// TOPIC: STL Algorithm std::iota

// NOTES:
// 0. Fills the range[first, last) with sequencially increasing values,
//    starting with value and repetitively evaluating ++value.

#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    cout << "List: " << endl;
    list<int> lst(10);
    iota(lst.begin(), lst.end(), -5);

    for (auto elm: lst) cout << elm << endl;

    cout << endl;

    cout << "Vector: " << endl;
    vector<list<int>::iterator> vec(lst.size());
    iota(vec.begin(), vec.end(), lst.begin());

    for (auto elm: vec) cout << *elm << endl;

    return 0;
}
