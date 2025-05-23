// TOPIC: std::unordered_multimap In C++

// NOTES
// 0. std::unordered_multimap is an associative container that supports equivalent keys (an unordered_multimap
//    may contain multiple copies of each key value) and that associative values of another type with the keys.
// 1. search, insertion, and removal have average constant-time complexity
// 2. Internally, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets.
// 4. This allows fast access to individual elements, because after computing the hash of the value it refers to
//    the exact bucket the element is placed into.

// WHY UNORDER_MAP
// 0. maintain a collection of duplicate {key:value} pairs with fast insertion and removal.

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    std::unordered_multimap<int,char> umm = {{5,'d'}};
    umm.insert({1,'a'});
    umm.insert(std::pair<int,char>{2,'b'});
    umm.insert(std::make_pair(3,'c'));
    umm.insert(std::make_pair(3,'d'));

    for (auto& elm: umm) { cout << elm.first << " " << elm.second << endl; }

    return 0;
}
