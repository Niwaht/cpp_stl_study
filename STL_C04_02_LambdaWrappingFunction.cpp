#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <functional>
using namespace std;

static auto consumer (auto &container) {
    return [&] (auto value) { container.push_back(value); };
}

static void print (const auto &c) {
    for(auto i : c) cout << i << ", ";
    cout << '\n';
}

int main()
{
    deque<int>  d;
    list<int>   l;
    vector<int> v;

    const vector<function<void(int)>> consumers
        {consumer(d), consumer(l), consumer(v)};

    for(size_t i {0}; i < 10; ++i)
        for(auto &&consume : consumers)
            consume(i);

    print(d);
    print(l);
    print(v);

    return 0;
}
