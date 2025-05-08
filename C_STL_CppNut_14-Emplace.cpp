// TOPIC: Emplace in STL

// 1. All the containers supports insert() and emplace() operation to store data
// 2. emplace() used to construct in-place and avoids unnecessary copy of objects.
// 3. insert() and emplace() is equal for primitive data type but when we deal with heavy objects.
//    we should use emplace if we can for efficiency.

#include <iostream>
#include <set>

using namespace std;

class A {
public:
    int x;
    A(int x=0): x{x} { cout << "Construct" << endl; };
    A(const A& rhs) {x = rhs.x; cout << "Copy" << endl; };
};

bool operator < (const A& lhs, const A& rhs) { return lhs.x < rhs.x; }

int main()
{
    set<A> Set;
    Set.insert(A(1));
    Set.emplace(2);

    return 0;
}
