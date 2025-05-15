#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class trie {
    map<T, trie> tries;
public:
    template <typename It>
    void insert(It it, It end_it) {
        if(it == end_it) {  return; }
        tries[*it].insert(next(it), end_it);
    }

    template <typename C>
    void insert(const C &container) {
        insert(begin(container), end(container));
    }

    void insert(const initializer_list<T> &il) {
        insert(begin(il), end(il));
    }

    void print(vector<T> &v) const {
        if(tries.empty()) {
            copy(begin(v), end(v), ostream_iterator<T>{cout, ", "});
            cout << '\n';
        }
        for(const auto &p : tries) {
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
    }
};

int main()
{


    return 0;
}
