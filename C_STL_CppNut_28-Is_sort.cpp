// TOPIC: STL Algorithm is_sort

// NOTES
// 0. Check if the elements in range (first, last) are sorted in non-descending order.

// TYPES:
// 1. Can check integer data types
// 2. Can check user defined data type
// 3. Can check using a function object
// 4. Can check using lambda expression

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec{5,4,6,7,3,2,8,9,1};

    sort(vec.begin(),vec.end(), greater<int>());

    for (auto elm: vec) {
        cout << elm << " ";
    }

    if (is_sorted(vec.begin(), vec.end(), greater<int>())) {
        cout << "Sorted" << endl;
    }
    else {
        cout << "Unsorted" << endl;
    }

    return 0;
}
