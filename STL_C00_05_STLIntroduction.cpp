#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
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

    // vector<int>::iterator it1 = v.end();
    // vector<int>::iterator it2 = v.rend();
    // vector<int>::iterator it3 = v.rbegin();

    cout << v[0] << ' ' << v.at(0) << '\n';
    cout << v.back() << '\n';

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << ' ';
    cout << '\n';

    for(auto it = v.begin(); it != v.end(); it++) cout << *it << ' ';
    cout << '\n';

    /* v.erase(v.begin() + 1);
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
    cout << v.empty() << '\n'; */
}

void explainList() {
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front();
}

void explainDeque() {
    deque<int> dq;
    dq.push_back(1);        // 1
    dq.emplace_back(2);     // 1, 2
    dq.push_front(4);       // 4, 1, 2
    dq.emplace_front(3);    // 3, 4, 1, 2

    dq.pop_back();          // 3, 4, 1
    dq.pop_front();         // 4, 1

    cout << "Deque:\n";
    cout << dq.back() << ' ';      // 1
    cout << dq.front() << '\n';     // 4
}

void explainStack() {
    stack<int> st;
    st.push(1);             // 1
    st.push(2);             // 1, 2
    st.push(3);             // 1, 2, 3
    st.push(3);             // 1, 2, 3, 3
    st.emplace(5);          // 1, 2, 3, 3, 5

    cout << "Stack:\n";
    cout << st.top() << '\n';       // 5
    st.pop();               // 1, 2, 3, 3
    cout << st.top() << '\n';       // 3
    cout << st.size() << '\n';      // 4
    // cout << st.empty();

    /* stack<int> st1, st2;
    st1.swap(st2); */
    stack<int> st3;
    st3.swap(st);
    cout << st.size() << '\n';      // 0
    cout << st3.size() << '\n';     // 4
}

void explainQueue() {
    queue<int> q;
    q.push(1);              // 1
    q.push(2);              // 1, 2
    q.emplace(4);           // 1, 2, 4

    q.back() += 5;          // 1, 2, 9

    cout << "Queue:\n";
    cout << q.back() << '\n';       // 9
    cout << q.front() << '\n';      // 1
    q.pop();                // 2, 9
    cout << q.front() << '\n';      // 2
}

void explainPriorityQueue() {
    priority_queue<int> pq;
    pq.push(5);             // 5
    pq.push(2);             // 2, 5
    pq.push(8);             // 2, 5, 8
    pq.emplace(10);         // 2, 5, 8, 10

    cout << "Priority Queue:\n";
    cout << pq.top() << '\n';       // 10
    pq.pop();               // 5, 2, 8
    cout << pq.top() << '\n';       // 8

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);             // 5
    pq1.push(2);             // 5, 2
    pq1.push(8);             // 8, 5, 2
    pq1.emplace(10);         // 10, 8, 5, 2

    cout << pq1.top() << '\n';      // 2
}

int main()
{
    explainPair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPriorityQueue();

    return 0;
}
