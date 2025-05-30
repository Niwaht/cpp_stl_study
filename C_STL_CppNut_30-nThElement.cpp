// TOPIC: STL Algorithm nth_element

// NOTES:
// 0. nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
//    a. The element at the nth position is the one which should be at that position if we sort the list.
//    b. It does not sort the list, just that all the elements, which precede the nth element are not greater than it,
//       and all the elements after it are not less than it.
// 1. nth_element algorithm is implemented using introselect.
//    a. introselect is a hybrid of quickselect and median of medians algorithm.
//       1. quickselect is used to find kth smallest number in an unsorted array.
//       2. median of medians is an median selection algorithm for better pivot selection maily used in quickselect.

// SUPPORTS TYPES:
// 1. sorting integral data types
// 2. sorting user defined data types
// 3. sort using function object
// 4. sort using lambda expression

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector<int> v{5,6,4,3,2,6,7,9,2};

    nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    cout << "The median is " << v[v.size()/2] << '\n';

    nth_element(v.begin(), v.begin()+1, v.end(), greater<int>());
    cout << "The second largest element is " << v[1] << '\n';

    return 0;
}
