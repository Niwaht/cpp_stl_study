#include <iostream>
using namespace std;

/// Dijkstra's algorithm
#include <vector>
#include <queue>
typedef pair<long long, int> pli;                       // {distance, node}
const long long INF = 1e18;
vector<long long> dijkstra(int start, int n, vector<vector<pli>>& adj) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;  // min-heap
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        long long w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(w > dist[u]) continue;
        for(auto& e : adj[u]) {
            int v = e.second, weight = e.first;
            if(dist[v] > dist[u] + weight) { dist[v] = dist[u] + weight; pq.push({dist[v], v}); }
        }
    }
    return dist;
}
void main_1() {
    cout << "Dijkstra's algorithm\n----------------------------------------\n";
    /*
        int n, m, s, t;
        cin >> n >> m;
        vector<vector<pli>> adj(n + 1);
        while(m--) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({w, v});
        }
        cin >> s >> t;
        vector<long long> dist = dijkstra(s, n, adj);
        if(dist[t] == INF) cout << "Vertex is unreachable\n";
        else cout << "Shortest path's length: " << dist[t] << '\n';
    */

    int n = 3, s = 1, t = 3;
    vector<vector<pli>> adj(n + 1);
    adj[1].push_back({5, 2});
    adj[1].push_back({10, 3});
    adj[2].push_back({3, 3});
    vector<long long> dist = dijkstra(s, n, adj);
    if(dist[t] == INF) cout << "Vertex is unreachable\n";
    else cout << "Shortest path's length: " << dist[t] << '\n';
}

int main()
{
    main_1();
    return 0;
}
