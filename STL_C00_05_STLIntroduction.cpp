#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

void explainPair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << ' ' << p1.second << '\n';

    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << ' ' << p2.second.second << ' ' << p2.second.first << '\n';

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << '\n';
}

void explainVector() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v1 (5, 100);
    vector<int> v2 (5);
    vector<int> v3 (5, 20);
    vector<int> v4 (v3);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *it << ' ';

    it += 2;
    cout << *it << ' ';

    vector<int>::iterator it1 = v.end();
    // vector<int>::iterator it2 = v.rend();
    // vector<int>::iterator it3 = v.rbegin();

    cout << v[0] << ' ' << v.at(0) << '\n';
    cout << v.back() << '\n';

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << ' ';
    cout << '\n';

    for(auto it = v.begin(); it != v.end(); it++) cout << *it << ' ';
    cout << '\n';

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2, v.begin() + 4);

    vector<int>(2, 100);
    v.insert(v.begin(), 300);
    v.insert(v.begin() + 1, 2, 10);

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end());

    cout << v.size();
    v.pop_back();

    v1.swap(v2);

    v.clear();
    cout << v.empty() << '\n';
}

int main()
{
    explainPair();
    explainVector();

    return 0;
}
