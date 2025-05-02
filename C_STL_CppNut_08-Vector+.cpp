// TOPIC: Best way to use vector in C++

// PROBLEM IN VECTOR?





#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;

    vec.reserve(32);

    for (int i=0; i<32; ++i) {
        vec.push_back(i);
        cout << "Size: " << vec.size() << " and Capacity: " << vec.capacity() << endl;
    }

    return 0;
}
