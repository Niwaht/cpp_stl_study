// TOPIC: list in STL

// 1. This is double linked list what we know from C programming language
// 2. List is sequence container that allow non-contiguous memory location
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in term of
//    insertion, removal and moving elements in any position provided we have the iterator of the position
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. Few available operations
//    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
//    pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> list1 = {5, 2, 4, 6, 2};
    list<int> list2 = {7, 6, 1, 9};

    for (auto& elm: list1) {
        cout << elm << ' ';
    }

    cout << endl;

    for (auto& elm: list2) {
        cout << elm << ' ' ;
    }

    cout << endl;


    return 0;
}
