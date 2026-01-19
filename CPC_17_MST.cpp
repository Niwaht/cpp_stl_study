#include <iostream>
using namespace std;

/// Prim's algorithm
#include <vector>
#include <queue>
typedef pair<int, int> pii; // {weight, node}
int prim(int n, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n + 1, false);
    int total_weight = 0, nodes_count = 0;
    // int edges_count = 0; // nodes_count/edges_count used separately
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        total_weight += w;
        // if(w > 0) edges_count++;
        nodes_count++;
        for(auto& [weight, v] : adj[u]) { if(!visited[v]) pq.push({weight, v}); }
    }
    // return (n > 1 && edges_count != n - 1) ? -1 : total_weight;
    return (nodes_count == n) ? total_weight : -1;
}
void main_1() {
    cout << "Prim's algorithm\n----------------------------------------\n";
    // int n, e; cin >> n >> e;
    int n = 8;
    vector<vector<pii>> adj(n + 1);
    /*
        for(int i = 0; i < e; ++i) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({w, v}); adj[v].push_back({w, u});
        }
    */
    auto push = [&](int u, int v, int w){ adj[u].push_back({w, v}); adj[v].push_back({w, u}); };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1);  push(7, 4, 5); push(8, 3, 4);
    int result = prim(n, adj);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

/// Compact Prim's algorithm
int prim_compact(int n, const vector<pii> adj[]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(n + 1, 1e9); vector<bool> visited(n + 1, 0);
    int total = 0, cnt = 0;
    pq.push({distance[1] = 0, 1});
    while(!pq.empty() && cnt < n) { // cnt < n -> early exit
        auto [w, u] = pq.top(); pq.pop(); if(visited[u]) continue;
        visited[u] = 1; total += w; cnt++;
        for(auto [v, weight] : adj[u])
            if(!visited[v] && weight < distance[v]) pq.push({distance[v] = weight, v});
    }
    return (cnt == n) ? total : -1;
}
void main_2() {
    cout << "\nCompact Prim's algorithm\n----------------------------------------\n";
    // int n, e; cin >> n >> e;
    int n = 7;
    vector<pii> adj[n + 1];
    /*
        for(int i = 0; i < e; ++i) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({w, v}); adj[v].push_back({w, u});
        }
    */
    auto push = [&](int u, int v, int w){ adj[u].push_back({v, w}); adj[v].push_back({u, w}); };
    push(1, 2, 30); push(1, 3, 9); push(2, 6, -20); push(3, 4, 6);
    push(3, 5, 2); push(4, 5, -10); push(4, 6, 9);  push(6, 7, 1);
    int result = prim_compact(n, adj);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

int main()
{
    main_1(); main_2();
    return 0;
}
