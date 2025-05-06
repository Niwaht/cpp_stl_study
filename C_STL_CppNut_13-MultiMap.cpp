// TOPIC: Multimap in C++
// SYNTAX: multimap<type1, type2> obj; where type1 is key's type and type2 is value's type.

// NOTES:
// 1. Multimap is an associative container that contains a sorted list of key-value pairs.
// 2. It store key-value pare in sorted order on the basis of key (asc/desc)
//    Syntax: std::multimap<char, int, std::greater<>> Multimap;
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We don't have at() and [] function to get element like we had in std::map.


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    std::multimap<char, int> Multimap;
    Multimap.insert(pair<char, int>('a',1));
    Multimap.insert(make_pair('a',2));
    Multimap.insert(make_pair('a',3));
    Multimap.insert(make_pair('b',4));
    Multimap.insert(make_pair('b',5));

    // Iterate over multimap
    for (auto &elm: Multimap) {
        cout << elm.first << " " << elm.second << endl;
    }

    cout << endl << endl;

    // Get all the pairs of given key
    auto range = Multimap.equal_range('a');
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
