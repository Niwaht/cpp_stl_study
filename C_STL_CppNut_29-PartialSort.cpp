// TOPIC: STL Algorithm partial_sort

// NOTES:
// 0. partial_sort rearranges elements such that the range [first, middle) contains the sorted elements
// 1. The order of equal elements is not guaranteed to be preserved.
// 2. The order of remaining elements is unspecified.

// Look for the overloads in cppreference.com site.

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec{5,7,4,2,8,6,1,9,0,3};

    partial_sort(vec.begin(), vec.begin()+6, vec.end());

    for (int val: vec) {
        cout << val << " ";
    }

    return 0;
}
