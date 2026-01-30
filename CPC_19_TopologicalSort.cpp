#include <iostream>
using namespace std;

/// Kahn's algorithm
#include <vector>
#include <queue>
#include <map>
vector<int> kahn(int n, vector<vector<int>>& adj) {
    vector<int> d(n + 1, 0), r;                         // in-degree, result
    for(auto& l : adj) for(int v : l) d[v]++;           // calculate in-degree
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!d[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        r.push_back(u);                                 // push node into result
        for(int v : adj[u]) if(!--d[v]) q.push(v);      // decrement degree of neighbors
    }
    return (int)r.size() == n ? r : vector<int>();      // check cycle
}
void main_1() {
    cout << "Kahn's algorithm\n----------------------------------------\n";
    // int n, m, c = 0; cin >> n >> m;
    int n = 6, c = 0;
    vector<vector<int>> adj(n + 1);
    map<string, int> s2i; map<int, string> i2s;
    auto f = [&](string s){ return s2i[s] ? s2i[s] : (i2s[++c] = s, s2i[s] = c); };
    // for(string u, v; m-- && cin >> u >> v;) adj[f(u)].push_back(f(v));
    auto push = [&](string u, string v){ adj[f(u)].push_back(f(v)); };
    push("A", "B"); push("A", "D"); push("B", "C"); push("D", "B");
    push("D", "E"); push("D", "F"); push("E", "F");
    auto r = kahn(n, adj);
    if(r.empty()) { cout << "Cycle detected\n"; return; }
    for(int i = 0; i < n; i++) cout << i2s[r[i]] << (i < n - 1 ? " " : "");
    cout << '\n';
}

/// Kahn's algorithm with lexicographical order
vector<int> kahn_lexico(int n, vector<vector<int>>& adj) {
    vector<int> d(n + 1, 0), r;
    for(auto& l : adj) for(int v : l) d[v]++;
    priority_queue<int, vector<int>, greater<int>> q;   // queue -> min-priority queue
    for(int i = 1; i <= n; i++) if(!d[i]) q.push(i);
    while(!q.empty()) {
        int u = q.top(); q.pop();                       // front -> top
        r.push_back(u);
        for(int v : adj[u]) if(!--d[v]) q.push(v);
    }
    return (int)r.size() == n ? r : vector<int>();
}
void main_2() {
    cout << "\nKahn's algorithm with lexicographical order\n----------------------------------------\n";
    // int n, m, c = 0; cin >> n >> m;
    int n = 6, c = 0;
    vector<vector<int>> adj(n + 1);
    map<string, int> s2i; map<int, string> i2s;
    auto f = [&](string s){ return s2i[s] ? s2i[s] : (i2s[++c] = s, s2i[s] = c); };
    // for(string u, v; m-- && cin >> u >> v;) adj[f(u)].push_back(f(v));
    auto push = [&](string u, string v){ adj[f(u)].push_back(f(v)); };
    push("A", "B"); push("A", "D"); push("B", "C"); push("D", "B");
    push("D", "E"); push("D", "F"); push("E", "F");
    auto r = kahn_lexico(n, adj);
    if(r.empty()) { cout << "Cycle detected\n"; return; }
    for(int i = 0; i < n; i++) cout << i2s[r[i]] << (i < n - 1 ? " " : "");
    cout << '\n';
}

int main()
{
    main_1(); main_2();
    return 0;
}
