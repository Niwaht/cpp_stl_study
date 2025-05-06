// TOPIC: Map in C++ STL

// NOTES:
// 1. Syntax: map<type1, type2> obj; where type1 is key's type and type2 is value's type
// 2. std::map is associative container that store elements in key-value combination
//    where key must unique, otherwise it override the previous value. but value can be duplicate with not same key
// 3. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree).
// 4. It store key-value pair in sorted order on the basis of key (asc/desc)
// 5. std::map is generally used used in Dictionary type problems.

// EXAMPLE: Dictionary


#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main()
{
/* Map with int
    std::map<string, int> Map;
    Map["Chotu"] = 90909009;
    Map["Amit"] = 982349819;
    Map["Chotu"] = 90909010;
    Map.insert(std::make_pair("Bot",782348818));

    // Loop through map
    for (auto &el1: Map) {
        cout << el1.first << " " << el1.second << endl;
    }

    // Access using [] operator
    cout << Map["Chotu"] << endl;

*/

//  Map with Vector
    std::map<string, vector<int>> Map;
    Map["Chotu"].push_back(90909009);
    Map["Amit"].push_back(982349819);
    Map["Amit"].push_back(234123413);

    for (auto &el1: Map) {
        cout << el1.first;
        for (auto &el2: el1.second) {
            cout << " " << el2;
        }
        cout << endl;
    }

    return 0;
}
