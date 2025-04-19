#define D_GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v {1, 2, 3};
    v.shrink_to_fit();
    const auto it (begin(v));

    cout << *it << '\n';

    v.push_back(123);

    cout << *it << '\n';

    return 0;
}
