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
    cout << "\nKahn with lexicographical order\n----------------------------------------\n";
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

/// Topological sorts via depth-first searches
#include <string>
#include <algorithm>
map<string, vector<string>> adj;
map<string, int> st;                // 0: W, 1: G, 2: B
vector<string> res;
bool dfs(string u) {
    st[u] = 1;
    for(auto &v : adj[u]) if(st[v] == 1 || (!st[v] && !dfs(v))) return false;   // check cycle
    st[u] = 2; res.push_back(u);
    return true;
}
void main_3() {
    cout << "\nTopological sorts via DFS\n----------------------------------------\n";
    // int n, e; cin >> n >> e;
    /*
        while(e--) {
            string u, v; cin >> u >> v;
            adj[u].push_back(v);
            if(st.find(u) == end(st)) st[u] = 0;
            if(st.find(v) == end(st)) st[v] = 0;
        }
    */
    auto push = [&](string u, string v){
        adj[u].push_back(v);
        if(st.find(u) == end(st)) st[u] = 0;
        if(st.find(v) == end(st)) st[v] = 0;
    };
    push("A", "B"); push("A", "D"); push("B", "C"); push("D", "B");
    push("D", "E"); push("D", "F"); push("E", "F");
    for(auto const& [name, status] : st) if(status == 0 && !dfs(name)) { cout << "Cycle detected\n"; return; }
    reverse(begin(res), end(res));
    for(int i = 0; i < (int)res.size(); i++) cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << '\n';
}

/// Topological sorts via depth-first searches with lexicographical order
void main_4() {
    cout << "\nTopological sorts via DFS with lexicographical order\n----------------------------------------\n";
    adj.clear(); st.clear(); res.clear();               // cleaning up leftovers from main_3()
    // int n, e; string u, v; vector<string> nds;
    vector<string> nds;
    // for(cin >> n >> e; e--; nds.push_back(u), nds.push_back(v)) cin >> u >> v, adj[u].push_back(v);
    auto push = [&](string u, string v){ nds.push_back(u); nds.push_back(v); adj[u].push_back(v); };
    push("A", "B"); push("A", "D"); push("B", "C"); push("D", "B");
    push("D", "E"); push("D", "F"); push("E", "F");
    sort(begin(nds), end(nds));
    nds.erase(unique(begin(nds), end(nds)), end(nds));
    for(auto &p : adj) sort(rbegin(p.second), rend(p.second));
    for(int i = nds.size(); i--;) if(!st[nds[i]] && !dfs(nds[i])) { cout << "Cycle detected\n"; return; }
    reverse(begin(res), end(res));
    for(int i = 0; i < (int)res.size(); i++) cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    cout << '\n';
}

/// Longest path in directed acyclic graphs
#define adj adj_5
typedef long long ll;
vector<pair<int, int>> adj[100005]; ll dp[100005];
map<string, int> nm; string id[100005]; vector<int> topo;
int deg[100005], p[100005];
void longestPathDP(int n, bool f) {
    fill(dp, dp + n + 1, f ? -2e18 : 2e18); fill(p, p + n + 1, -1);      // initialization
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);                  // start with 0 in-degree nodes
    if(!q.empty()) dp[q.front()] = 0;                                   // initial distance at start
    while(!q.empty()) {
        int u = q.front(); q.pop(); topo.push_back(u);
        for(auto &e : adj[u]) {
            int v = e.first;
            if(abs(dp[u]) < 1e18 && (f ? dp[u] + e.second > dp[v] : dp[u] + e.second < dp[v])) {
                dp[v] = dp[u] + e.second; p[v] = u;                     // store parent; relax edge
            }
            if(!--deg[v]) q.push(v);                                    // decrement in-degree after edge relaxation
        }
    }
}
void main_5() {
    cout << "\nLongest path in directed acyclic graphs\n----------------------------------------\n";
    // int n, m, w; cin >> n >> m;
    int n = 6;
    /*
        for(string u, v; m-- && cin >> u >> v >> w;) {
            if(!nm[u]) { nm[u] = nm.size(); id[nm[u]] = u; }
            if(!nm[v]) { nm[v] = nm.size(); id[nm[v]] = v; }
            adj[nm[u]].push_back({nm[v], w}); deg[nm[v]]++;
        }
    */
    auto push = [&](string u, string v, int w){
        if(!nm[u]) { nm[u] = nm.size(); id[nm[u]] = u; }
        if(!nm[v]) { nm[v] = nm.size(); id[nm[v]] = v; }
        adj[nm[u]].push_back({nm[v], w}); deg[nm[v]]++;
    };
    push("A", "B", 5); push("A", "C", 2); push("B", "C", 3); push("B", "D", 8);
    push("C", "E", 1); push("D", "F", 6); push("E", "D", 7); push("E", "F", 4);
    bool f = 1; longestPathDP(n, f);                                    // f = 1: longest, f = 0: shortest
    int t = topo.back();
    if(abs(dp[t]) > 1e17) { cout << "No optimized path was found\n"; return; }
    cout << (f ? "Longest" : "Shortest") << " distance: " << dp[t] << "\nPath: ";
    vector<int> path;
    for(int v = t; v != -1; v = p[v]) path.push_back(v);
    reverse(begin(path), end(path));
    for(int i = 0; i < (int)path.size(); i++) cout << id[path[i]] << (i == (int)path.size() - 1 ? "" : " ");
    cout << '\n';
}

/// Shortest path in directed acyclic graphs
void main_6() {
    cout << "\nShortest path in directed acyclic graphs\n----------------------------------------\n";
    // int n, m, w; cin >> n >> m;
    int n = 6;
    /*
        for(string u, v; m-- && cin >> u >> v >> w;) {
            if(!nm[u]) { nm[u] = nm.size(); id[nm[u]] = u; }
            if(!nm[v]) { nm[v] = nm.size(); id[nm[v]] = v; }
            adj[nm[u]].push_back({nm[v], w}); deg[nm[v]]++;
        }
    */
    auto push = [&](string u, string v, int w){
        if(!nm[u]) { nm[u] = nm.size(); id[nm[u]] = u; }
        if(!nm[v]) { nm[v] = nm.size(); id[nm[v]] = v; }
        adj[nm[u]].push_back({nm[v], w}); deg[nm[v]]++;
    };
    push("A", "B", 5); push("A", "C", 2); push("B", "C", 3); push("B", "D", 8);
    push("C", "E", 1); push("D", "F", 6); push("E", "D", 7); push("E", "F", 4);
    bool f = 0; longestPathDP(n, f);                                    // f = 1: longest, f = 0: shortest
    int t = topo.back();
    if(abs(dp[t]) > 1e17) { cout << "No optimized path was found\n"; return; }
    cout << (f ? "Longest" : "Shortest") << " distance: " << dp[t] << "\nPath: ";
    vector<int> path;
    for(int v = t; v != -1; v = p[v]) path.push_back(v);
    reverse(begin(path), end(path));
    for(int i = 0; i < (int)path.size(); i++) cout << id[path[i]] << (i == (int)path.size() - 1 ? "" : " ");
    cout << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6();
    return 0;
}
