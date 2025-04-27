#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Plus {
    const int data;
public:
    Plus(const int data)
        : data(data)
    {}

    int operator() (const int value) { return value + data; }
};

auto plusL = [data=1](const int value){ return value + data; };

int main()
{
    Plus plusOne(1);
    assert(plusOne(2) == 3);

    Plus plusTwo(2);
    assert(plusTwo(2) == 4);

    assert(plusL(2) == 3);

    vector<int> test_data = {1, 2, 3, 4};
    transform(test_data.begin(), test_data.end(), test_data.begin(), plusOne);
    assert(test_data[3] == 5);

    return 0;
}
