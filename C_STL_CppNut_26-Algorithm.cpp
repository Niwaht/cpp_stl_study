// TOPIC: STL Algorithm

// NOTES:
// 0. STL algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating)
// 1. Algorithms are applied to range of elements.
// 2. <algorithm> header is used to get all algorithm in STL.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> vec {4, 3, 5, 2, 6, 1};
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 4);   // using find() in algorithm

    if (it == vec.end()) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found" << endl;
    }



    return 0;
}
