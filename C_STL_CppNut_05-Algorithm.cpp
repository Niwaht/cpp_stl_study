#include <iostream>
//Contiguous memory allocation
#include <vector>
//Doubly link list
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    /*
    //sequence container
    vector<int> v;

    v.push_back(100);
    v.push_back(20);
    v.push_back(400);
    v.push_back(50);

    //Random Access Iterators
    sort(v.begin(), v.end());
    //List is bidirectional iterator


    cout << "Size: " << v.size() << endl;

    // Iterator are similar to pointers..
    //list<int>::iterator itr = v.begin();

    auto itr = v.begin();

    //cout << *(itr+1) << endl;

    for (; itr != v.end(); itr++) {
        cout << "Value: " << *itr << endl;
    }

    v.clear();

    cout << "Size: " << v.size() << endl;

    */


    int arr[] = {100, 20, 300, 45, 55};
    int *begin = &arr[0];
    int *end = &arr[0] + (sizeof(arr)/sizeof(int));

    sort(begin,end);

    for (; begin != end; begin++) {
        cout << "Value: " << *begin << endl;
    }

    return 0;
}
