// TOPIC: std::multiset<Type>

// SYNTAX: std::multiset<Type> objName;

// 1. std::set is an Associate Container that contains a sorted set of duplicate objects of type key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set we will have to provide
//    compare function so that set can store the in sorted order.
// 5. We can pass the order of sorting while constructing multiset object.

// BOTTOM LINE:
// multiset is similar to set except it can have multiple elements with same value.

#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;
/*  Example 1
int main()
{
    std::multiset<int> multiset = {5, 2, 4, 3, 2, 5};
    for (const auto& e: multiset) {
        cout << e << endl;
    }
    return 0;
}
*/

class Person {
    public:
        float age;
        string name;

    bool operator < (const Person& rhs) const {
        return age < rhs.age;
    }

    bool operator > (const Person& rhs) const {
        return age > rhs.age;
    }
};

int main()
{
    std::multiset<Person, std::greater<>> multiset = {{30,"Rupesh"}, {25,"Hitesh"}, {22, "John"}, {25,"Hitesh"}};
    for (const auto& e: multiset) {
        cout << e.age << " " << e.name << endl;
    }
    return 0;
}
