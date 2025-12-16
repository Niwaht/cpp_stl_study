#include <iostream>
using namespace std;

/// DSUs
#include <vector>
vector<int> p;
int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
void unite(int u, int v) { u = find(u); v = find(v); if(u != v) p[v] = u; }

void main_1() {
    cout << "DSUs\n----------------------------------------\n";
    int n = 6;
    p.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    unite(1, 2); unite(2, 3); unite(4, 5);
    cout << "1 and 3 are in the " << (find(1) == find(3) ? "same group" : "different group") << '\n'
         << "3 and 4 are in the " << (find(3) == find(4) ? "same group" : "different group") << '\n';
}

/// Graphs via DSUs
void main_2() {
    cout << "\nGraphs via DSUs\n----------------------------------------\n";
    int n = 5;
    p.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {4, 5}};
    for(auto e : edges) unite(e.first, e.second);
    cout << "node 1 and node 3 are " << (find(1) == find(3) ? "connected" : "not connected") << '\n'
         << "node 3 and node 4 are " << (find(3) == find(4) ? "connected" : "not connected") << '\n';
}

/// Unions by size
#include <algorithm>
vector<int> ds;
void ubs(int u, int v) {
    u = find(u); v = find(v); if(u == v) return;
    if(ds[u] < ds[v]) swap(u, v);
    p[v] = u; ds[u] += ds[v];
}

void main_3() {
    cout << "\nUnions by size\n----------------------------------------\n";
    int n = 10;
    p.resize(n + 1); ds.assign(n + 1, 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    vector<pair<int, int>> ops = {{1, 2}, {3, 4}, {1, 3}, {5, 6}, {7, 8}, {5, 7}, {1, 5}};
    for(auto op : ops) ubs(op.first, op.second);
    cout << "2 and 4 are in the " << (find(2) == find(4) ? "same group" : "different group") << '\n'
         << "6 and 8 are in the " << (find(6) == find(8) ? "same group" : "different group") << '\n'
         << "8 and 8 are in the " << (find(8) == find(8) ? "same group" : "different group") << '\n';
}

/// Constraints satisfactions
void main_4() {
    cout << "\nConstraints satisfactions\n----------------------------------------\n";
    int n, m;
    // cin >> n >> m;
    n = 4; m = 3;
    p.resize(n + 1); ds.assign(n + 1, 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    vector<pair<int, int>> equal, notequal;
    int a, b;
    char op;
    // for(int i = 0; i < m; i++) { cin >> a >> op >> b; (op == '=') ? equal.push_back({a, b}) : notequal.push_back({a, b}); }
    equal = {{1, 2}, {2, 3}};
    notequal = {{1, 3}};
    for(auto eq : equal) ubs(eq.first, eq.second);
    for(auto neq : notequal) { if(find(neq.first) == find(neq.second)) { cout << "NO\n"; return; } }
    cout << "YES\n";
}

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
