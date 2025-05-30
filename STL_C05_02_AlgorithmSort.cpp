#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
using namespace std;

static void print(const vector<int> &v) {
    copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}

int main()
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Creating an RNG (Random Number Generator)
    random_device rd;
    mt19937 g (rd());

    cout << is_sorted(begin(v), end(v)) << '\n';    // Should return 1 (true)

    // Shuffle data in vector using RNG named g
    shuffle(begin(v), end(v), g);
    cout << is_sorted(begin(v), end(v)) << '\n';    // Should return 0 (false)
    print(v);

    sort(begin(v), end(v));
    cout << is_sorted(begin(v), end(v)) << '\n';    // Should return 1 (true)
    print(v);

    shuffle(begin(v), end(v), g);
    partition(begin(v), end(v), [](int i){ return i < 5; });
    print(v);

    shuffle(begin(v), end(v), g);
    auto middle (next(begin(v), int(v.size()) / 2));
    partial_sort(begin(v), middle, end(v));
    print(v);

    // Sorting data structure which has no comparison operator
    struct mystruct {
        int a;
        int b;
    };
    vector<mystruct> mv {{5, 100}, {1, 50}, {-123, 1000}, {3, 70}, {-10, 20}};

    // Sorting function with optional sorting condition
    sort(begin(mv), end(mv),
         [](const mystruct &lhs, const mystruct &rhs){
            return lhs.b < rhs.b;
         });

    for(const auto &[a, b] : mv) {
        cout << "{" << a << ", " << b << "} ";
    }
    cout << '\n';

    return 0;
}
