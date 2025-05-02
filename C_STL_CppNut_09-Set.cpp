// TOPIC: std::set<Type>

// SYNTAX: std::set<Type> objName;

// 1. std::set is an Associate Container that contains a sorted set of unique objects of type key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set we will have to provide
//    compare function so that set can store the in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (Asc/Desc)


#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;

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
    //- set<int> Set = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    set<Person, std::greater<>> Set = {{30,"Rupesh"}, {25,"Hitesh"}, {22, "John"}};
    for (const auto& e: Set) {
        cout << e.age << " " << e.name << endl;
    }
    return 0;
}
