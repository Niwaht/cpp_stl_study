#include <iostream>
using namespace std;

/// Binary heaps as priority queues
#include <queue>
void main_1() {
    cout << "Binary heaps as priority queues\n----------------------------------------\n";
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << "Size = " << pq.size() << '\n';
    cout << "Max = " << pq.top() << '\n';
    pq.pop();
    cout << "New max = " << pq.top() << '\n';
}

/// Min heaps as priority queues
void main_2() {
    cout << "\nMin heaps as priority queues\n----------------------------------------\n";
    struct T {
        int v;
        T(int v): v(v) {}
    };
    struct cmp {
        bool operator()(T const& a, T const& b) const { return a.v > b.v; }
    };
    priority_queue<T, vector<T>, cmp> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << "Size = " << pq.size() << '\n';
    cout << "Max = " << pq.top().v << '\n';
    pq.pop();
    cout << "New max = " << pq.top().v << "\n\n";
}


void main_3() {
    struct T {
        int v;
        T(int v): v(v) {}
        bool operator<(T const& T) const { return T.v < v; }
    };
    priority_queue<T> pq;
    cout << (int)(T(3) < T(2)) << '\n';
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << "Size = " << pq.size() << '\n';
    cout << "Max = " << pq.top().v << '\n';
    pq.pop();
    cout << "New max = " << pq.top().v << '\n';
}

/// Min heap example
void main_4() {
    cout << "\nMin heap example\n----------------------------------------\n";
    cin.tie(nullptr)->sync_with_stdio(false);
    int N = 4;
    // cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(2); pq.push(3); pq.push(4); pq.push(6);
    // for(int i = 0; i < N; i++) {
    //     int x;
    //     cin >> x;
    //     pq.push(x);
    // }
    long long totalCost = 0;
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int merged = a + b;
        totalCost += merged;
        pq.push(merged);
    }
    cout << N << '\n' << "2 3 4 6\n";
    cout << totalCost << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
