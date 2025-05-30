// TOPIC: STL Algorithm is_sorted_until

// NOTES:
// 0. find how many elements are sorted in given range [first, last)

// SUPPORT TYPES:
// 1. sorting integral data types
// 2. sorting user defined data types
// 3. sort using function object
// 4. sort using lambda expression


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec {4,3,2,6,7,8,1};

    auto it = is_sorted_until(vec.begin()+1, vec.end());
    auto diff = distance(vec.begin(), it);

    cout << diff << endl;

    return 0;
}
