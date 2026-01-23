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

/// Kruskal's algorithm
#include <algorithm>
#include <numeric>
struct edge { int u, v, w; bool operator<(const edge& o) const { return w < o.w; } };
struct DSU {
    vector<int> p;
    DSU(int n) : p(n + 1) { iota(begin(p), end(p), 0); }
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if(root_i != root_j) { p[root_i] = root_j; return true; }
        return false;       // cycle
    }
};
int kruskal(int n, vector<edge>& edges) {
    sort(begin(edges), end(edges));
    DSU dsu(n);
    int total = 0, cnt = 0;
    for(auto& e : edges) {
        if(dsu.unite(e.u, e.v)) {
            total += e.w;
            if(++cnt == n - 1) break;       // early exit
        }
    }
    return (cnt == n - 1) ? total : -1;
}
void main_3() {
    cout << "\nKruskal's algorithm\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 8, m = 11;
    vector<edge> edges(m);
    // for(int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    auto push = [&](int u, int v, int w){ edges.push_back({u, v, w}); };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1);  push(7, 4, 5); push(8, 3, 4);
    int result = kruskal(n, edges);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

/// Kruskal's algorithm II
void main_4() {
    cout << "\nKruskal's algorithm II\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 7, m = 8;
    vector<edge> edges(m);
    // for(int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    auto push = [&](int u, int v, int w){ edges.push_back({u, v, w}); };
    push(1, 2, 30); push(1, 3, 9); push(2, 6, -20); push(3, 4, 6);
    push(3, 5, 2); push(4, 5, -10); push(4, 6, 9);  push(6, 7, 1);
    int result = kruskal(n, edges);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

/// Boruvka's algorithm
#define edge edge_5
#define DSU DSU_5
struct edge { int u, v, w; };
struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n + 1, -1); }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) { int r1 = find(i), r2 = find(j); if(r1 != r2) { p[r1] = r2; return true; } return false; }
};
int boruvka(int n, vector<edge>& edges) {
    DSU dsu(n);
    int mstW = 0, numComp = n, edgesUsed = 0;
    while(numComp > 1) {
        vector<int> best(n + 1, -1);
        bool foundAny = false;
        for(int i = 0; i < (int)edges.size(); i++) {
            int r1 = dsu.find(edges[i].u), r2 = dsu.find(edges[i].v);
            if(r1 == r2) continue;          // skip if the components are already connected
            if(best[r1] == -1 || edges[i].w < edges[best[r1]].w) best[r1] = i;
            if(best[r2] == -1 || edges[i].w < edges[best[r2]].w) best[r2] = i;
        }
        for(int i = 1; i <= n; i++) {
            if(best[i] != -1) {
                int e = best[i];
                if(dsu.unite(edges[e].u, edges[e].v)) { mstW += edges[e].w; edgesUsed++; numComp--; foundAny = true; }
            }
        }
        if(!foundAny) break;                // graph is disconnected
    }
    return (edgesUsed == n - 1) ? mstW : -1;
}
void main_5() {
    cout << "\nBoruvka's algorithm\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 8, m = 11;
    vector<edge> edges(m);
    // for(int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    auto push = [&](int u, int v, int w){ edges.push_back({u, v, w}); };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1);  push(7, 4, 5); push(8, 3, 4);
    int result = boruvka(n, edges);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

/// Boruvka's algorithm II
void main_6() {
    cout << "\nBoruvka's algorithm II\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 7, m = 8;
    vector<edge> edges(m);
    // for(int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    auto push = [&](int u, int v, int w){ edges.push_back({u, v, w}); };
    push(1, 2, 30); push(1, 3, 9); push(2, 6, -20); push(3, 4, 6);
    push(3, 5, 2); push(4, 5, -10); push(4, 6, 9);  push(6, 7, 1);
    int result = boruvka(n, edges);
    cout << "MST Calculation:\n";
    if(result != -1) cout << "Total weight of MST: " << result << '\n';
    else cout << "MST not found\n";
}

/// Second best minimum spanning tree
#define edge edge_7
#define DSU DSU_7
const int INF = 1e9;
struct edge { int u, v, w, id; };
struct DSU {
    vector<int> p;
    DSU(int n) { p.resize(n + 1); for(int i = 0; i <= n; i++) p[i] = i; }
    int find(int i) { return (p[i] == i) ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) { int ri = find(i), rj = find(j); if(ri != rj) { p[ri] = rj; return 1; } return 0; }
};
pair<int, vector<int>> get_mst(int n, vector<edge>& es, int skip) {
    DSU dsu(n); int weight = 0, cnt = 0; vector<int> ids;
    for(auto &e : es) { if(e.id == skip) continue; if(dsu.unite(e.u, e.v)) { weight += e.w; ids.push_back(e.id); cnt++; } }
    if(cnt != n - 1) return {INF, {}};
    return {weight, ids};
}
void main_7() {
    cout << "\nSecond best minimum spanning tree\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 8, m = 1l;
    vector<edge> es(m);
    // for(int i = 0; i < m; i++) { cin >> es[i].u >> es[i].v >> es[i].w; es[i].id = i; }
    int i = 0;
    auto push = [&](int u, int v, int w){ es.push_back({u, v, w, i}); i++; };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1);  push(7, 4, 5); push(8, 3, 4);
    sort(begin(es), end(es), [](edge a, edge b){ return a.w < b.w; });
    auto first = get_mst(n, es, -1);
    if(first.first == INF) return;
    int ans = INF;
    for(int id : first.second) ans = min(ans, get_mst(n, es, id).first);
    if(ans == INF) cout << "Second best MST not found\n";
    else cout << "Total weight of second best MST: " << ans << '\n';
}

/// Second best minimum spanning tree II
void main_8() {
    cout << "\nSecond best minimum spanning tree II\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 7, m = 8;
    vector<edge> es(m);
    // for(int i = 0; i < m; i++) { cin >> es[i].u >> es[i].v >> es[i].w; es[i].id = i; }
    int i = 0;
    auto push = [&](int u, int v, int w){ es.push_back({u, v, w, i}); i++; };
    push(1, 2, 30); push(1, 3, 9); push(2, 6, -20); push(3, 4, 6);
    push(3, 5, 2); push(4, 5, -10); push(4, 6, 9);  push(6, 7, 1);
    sort(begin(es), end(es), [](edge a, edge b){ return a.w < b.w; });
    auto first = get_mst(n, es, -1);
    if(first.first == INF) return;
    int ans = INF;
    for(int id : first.second) ans = min(ans, get_mst(n, es, id).first);
    if(ans == INF) cout << "Second best MST not found\n";
    else cout << "Total weight of second best MST: " << ans << '\n';
}

/// Second best minimum spanning tree via lowest common ancestor: Euler tour and segment tree
#define edge edge_9
struct edge { int u, v, w; bool in; };
struct node { int to, w; };
vector<node> g[10005];
int p[10005], f[10005], tr[10005], st[10005], tid = 0;
int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
// Euler tour: convert tree into linear array
void euler_tour(int u, int pr, int w) {
    f[u] = ++tid; tr[tid] = w;
    for(auto &e : g[u]) if(e.to != pr) { euler_tour(e.to, u, e.w); tr[++tid] = w; }
}
// Segment tree: for range minimum queries
void segment_tree(int n, int s, int e) {
    if(s == e) { st[n] = tr[s]; return; }
    int m = (s + e) / 2;
    segment_tree(2 * n, s, m); segment_tree(2 * n + 1, m + 1, e);
    st[n] = max(st[2 * n], st[2 * n + 1]);
}
// Range minimum query
int query(int n, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return st[n];
    int m = (s + e) / 2;
    return max(query(2 * n, s, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}
void main_9() {
    cout << "\n2BMST via LCA: Euler tour and SegT\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 8;
    vector<edge> es;
    // for(int i = 0; i < m; i++) cin >> es[i].u >> es[i].v >> es[i].w;
    auto push = [&](int u, int v, int w){ es.push_back({u, v, w, false}); };
    push(1, 2, 5); push(1, 3, 9); push(2, 6, 20); push(2, 7, 8); push(3, 5, 2); push(3, 4, 6);
    push(4, 5, 3); push(4, 6, 9); push(5, 7, 1);  push(7, 4, 5); push(8, 3, 4);
    sort(begin(es), end(es), [](edge a, edge b){ return a.w < b.w; });
    for(int i = 1; i <= n; i++) p[i] = i;
    long long mw = 0;
    for(auto &e : es) if(find(e.u) != find(e.v)) {
        p[find(e.u)] = find(e.v); mw += (e.in = 1) * e.w;
        g[e.u].push_back({e.v, e.w}); g[e.v].push_back({e.u, e.w});
    }
    euler_tour(1, 0, 0); segment_tree(1, 1, tid); int dif = INF;
    for(auto &e : es) if(!e.in) {
        int l = f[e.u], r = f[e.v]; if(l > r) swap(l, r);
        dif = min(dif, e.w - query(1, 1, tid, l + 1, r));
    }
    cout << "Total weight of second best MST: " << mw + dif << '\n';
}

/// Second best minimum spanning tree via lowest common ancestor: Euler tour and segment tree II
void main_10() {
    cout << "\n2BMST via LCA: Euler tour and SegT II\n----------------------------------------\n";
    tid = 0; for(int i = 1; i <= 8; i++) g[i].clear();  // remove leftovers from main_9()
    // int n, m; cin >> n >> m;
    int n = 7;
    vector<edge> es;
    // for(int i = 0; i < m; i++) cin >> es[i].u >> es[i].v >> es[i].w;
    auto push = [&](int u, int v, int w){ es.push_back({u, v, w, false}); };
    push(1, 2, 30); push(1, 3, 9); push(2, 6, -20); push(3, 4, 6);
    push(3, 5, 2); push(4, 5, -10); push(4, 6, 9);  push(6, 7, 1);
    sort(begin(es), end(es), [](edge a, edge b){ return a.w < b.w; });
    for(int i = 1; i <= n; i++) p[i] = i;
    long long mw = 0;
    for(auto &e : es) if(find(e.u) != find(e.v)) {
        p[find(e.u)] = find(e.v); mw += (e.in = 1) * e.w;
        g[e.u].push_back({e.v, e.w}); g[e.v].push_back({e.u, e.w});
    }
    euler_tour(1, 0, 0); segment_tree(1, 1, tid); int dif = INF;
    for(auto &e : es) if(!e.in) {
        int l = f[e.u], r = f[e.v]; if(l > r) swap(l, r);
        dif = min(dif, e.w - query(1, 1, tid, l + 1, r));
    }
    cout << "Total weight of second best MST: " << mw + dif << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7(); main_8(); main_9(); main_10();
    return 0;
}
