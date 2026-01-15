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

/// Bellman-Ford algorithm
#include <algorithm>
struct edge { int u, v, w; };
bool bellmanFord(int n, vector<edge> &E, int s, vector<long long> &d) {
    d.assign(n + 1, INF);
    d[s] = 0;
    bool isUpdate;
    for(int i = 1; i <= n; i++) {
        isUpdate = false;
        for(auto &e : E) {
            if(d[e.u] < INF && d[e.u] + e.w < d[e.v]) {
                d[e.v] = d[e.u] + e.w;
                isUpdate = true;
                if(i == n) return true;             // negative cycle
            }
        }
        if(!isUpdate) break;
    }
    return false;
}
void main_2() {
    cout << "\nBellman-Ford algorithm\n----------------------------------------\n";
    /*
        int n, m; cin >> n >> m;
        vector<edge> E(m);
        for(int i = 0; i < m; i++) cin >> E[i].u >> E[i].v >> E[i].w;
        vector<long long> d;
        if(bellmanFord(n, E, 1, d)) cout << "Negative cycle detected\n";
        else { for(int i = 1; i <= n; i++) cout << (d[i] == INF ? -1 : d[i]) << ' '; }
    */

    int n = 8;
    vector<edge> E = {{1, 2, 5}, {1, 3, 9}, {2, 6, 20}, {2, 7, 8}, {3, 5, 2}, {3, 4, 6},
                      {4, 5, 3}, {4, 6, 9}, {5, 7, 1}, {7, 4, 5}, {8, 3, 4}};
    vector<long long> d;
    if(bellmanFord(n, E, 1, d)) cout << "Negative cycle detected\n";
    else { for(int i = 1; i <= n; i++) cout << (d[i] == INF ? -1 : d[i]) << ' '; }
    cout << '\n';
}

/// Shortest path faster algorithm (SPFA)
#define edge edge_3
struct edge { int to, weight; };
long long spfa(int s, int t, int n, vector<vector<edge>>& adj) {
    vector<long long> dist(n + 1, INF);
    vector<int> cnt(n + 1, 0);
    vector<bool> inQ(n + 1, false);
    queue<int> q;
    dist[s] = 0; q.push(s); inQ[s] = true; cnt[s]++;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inQ[u] = false;
        for(auto &e : adj[u]) {
            // Relaxation
            if(dist[u] != INF && dist[e.to] > dist[u] + e.weight) {
                dist[e.to] = dist[u] + e.weight;
                if(!inQ[e.to]) { q.push(e.to); inQ[e.to] = true; if(++cnt[e.to] > n) return -2; }       // negative cycle
            }
        }
    }
    return dist[t];
}
void main_3() {
    cout << "\nShortest path faster algorithm (SPFA)\n----------------------------------------\n";
    /*
        int n, m, q_count;
        cin >> n >> m >> q_count;
        vector<vector<edge>> adj(n + 1);
        for(int i = 0, u, v, w; i < m; i++) { cin >> u >> v >> w; adj[u].push_back({v, w}); }
        while(q_count--) {
            int s, t; cin >> s >> t;
            long long res = spfa(s, t, n, adj);
            if(res == -2) cout << "Negative cycle detected\n";
            else if(res == INF) cout << "Node unreachable\n";
            else cout << res << '\n';
        }
    */

    int n = 8, s = 1, t = 6;
    vector<vector<edge>> adj(n + 1);
    auto push = [&](int u, int v, int w){ adj[u].push_back({v, w}); };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1); push(7, 4, 5); push(8, 3, 4);
    long long res = spfa(s, t, n, adj);
    if(res == -2) cout << "Negative cycle detected\n";
    else if(res == INF) cout << "Node unreachable\n";
    else cout << res << '\n';
}

int main()
{
    main_1(); main_2(); main_3();
    return 0;
}
