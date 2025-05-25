// TOPIC: STL Algorithm - Sort

// NOTES:
// 0. In C++ STL we have sort function which can sort in increasing and decreasing order
// 1. Not only integer but user data can be sorted using this function.
// 2. Internally it uses IntroSort which is combination of QuickSort, HeapSort and InsertionSort.
// 3. By default, It use QuickSort but if QuickSort is doing unfair partitioning and taking more than N*log N time.
//    It switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.
// 4. We can use parallel execution policy for better performance

// TYPES:
// 1. Sorting integral data types
// 2. Sorting user defined data types
// 3. Sort using a function object
// 4. Sort using lambda expression

#include <iostream>
#include <algorithm>
#include <vector>
//#include <execution>

using namespace std;

/*
// 1. Sort with integer data type

int main()
{
    std::vector<int> vec{5,4,6,7,3,2,8,9,1};
    std::sort(vec.begin(), vec.end());
//    std::sort(std::execution::par, vec.begin(), vec.end());

    for (auto elm: vec) {
        cout << elm << " ";
    }
    return 0;
}

*/

/**
// 2. Sorting user defined data types

class Point {
public:
    int x;
    int y;
    Point(int x=0, int y=0):x{x}, y{y} {}
    bool operator < (const Point& p1) {
        return (x+y)<(p1.x+p1.y);
    }
};

int main()
{
    std::vector<Point> vec {{1,2}, {3,1}, {0,1}};
    std::sort(vec.begin(), vec.end());

    for (auto e: vec) {
        cout << e.x << " " << e.y << endl;
    }

    return 0;
}
**/

/***
// 3. Sort using a function object

struct {
    bool operator()(int a, int b) const {
        return a < b;
    }
} customLess;

struct {
    bool operator()(int a, int b) const {
        return a > b;
    }
} customGreater;

int main()
{
    std::vector<int> vec {5,4,6,7,3,2,8,9,1};
    std::sort(vec.begin(), vec.end(), customGreater);

    for (auto elm: vec) {
        cout << elm << " ";
    }

    return 0;
}
***/


// 4. Sort using lambda expression

int main()
{
    std::vector<int> vec{5,4,6,7,3,2,8,9,1};
    std::sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; } );

    for (auto elm: vec) {
        cout << elm << " ";
    }

    return 0;
}

