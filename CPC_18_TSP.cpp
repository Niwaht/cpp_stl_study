#include <iostream>
using namespace std;

/// Traveling salesman problem: Brute force
#include <vector>
#include <algorithm>
#include <map>
const int INF = 1e9;
int bruteForceTSP(int n, vector<vector<int>>& d, vector<int>& best) {
    vector<int> nodes;
    for(int i = 1; i < n; i++) nodes.push_back(i);
    int min_d = INF;
    do {
        int cur_w = 0, u = 0; vector<int> path = {0};
        for(int v : nodes) { cur_w += d[u][v]; path.push_back(v); u = v; }
        cur_w += d[u][0]; path.push_back(0);
        if(cur_w < min_d) { min_d = cur_w; best = path; }
    } while(next_permutation(begin(nodes), end(nodes)));
    return min_d;
}
void main_1() {
    cout << "Traveling salesman problem: Brute force\n----------------------------------------\n";
    // int n, e; cin >> n >> e;
    int n = 4, c = 0;
    map<string, int> id; map<int, string> name;
    vector<vector<int>> d(n, vector<int>(n, INF));
    /*
        for(int i = 0, w, c = 0; i < e; i++) {
            string u_s, v_s; cin >> u_s >> v_s >> w;
            if(id.find(u_s) == end(id)) { id[u_s] = c; name[c++] = u_s; }
            if(id.find(v_s) == end(id)) { id[v_s] = c; name[c++] = v_s; }
            d[id[u_s]][id[v_s]] = d[id[v_s]][id[u_s]] = w;
        }
    */
    auto push = [&](string u_s, string v_s, int w){
        if(id.find(u_s) == end(id)) { id[u_s] = c; name[c++] = u_s; }
        if(id.find(v_s) == end(id)) { id[v_s] = c; name[c++] = v_s; }
        d[id[u_s]][id[v_s]] = d[id[v_s]][id[u_s]] = w;
    };
    push("a", "b", 5); push("a", "c", 6); push("a", "d", 7); push("b", "c", 4); push("b", "d", 3); push("c", "d", 2);
    // push("a", "b", 9); push("a", "c", -5); push("a", "d", 20); push("b", "c", -10); push("b", "d", -8); push("c", "d", 15);
    vector<int> best;
    int res = bruteForceTSP(n, d, best);
    if(res >= INF) cout << "No optimized path was found\n";
    else {
        cout << "Minimum weight: " << res << "\nPath: ";
        for(int i = 0; i < (int)best.size(); i++) cout << name[best[i]] << (i == (int)best.size() - 1 ? "" : " -> ");
        cout << '\n';
    }
}

/// Traveling salesman problem: Nearest neighbor
#include <string>
void nearestNeighborTSP(int n, vector<vector<int>>& d, map<int, string>& nm) {
    vector<int> path; vector<bool> vis(n, false);
    int cur = 0, sum = 0;
    vis[cur] = true; path.push_back(cur);
    for(int i = 0; i < n - 1; i++) {
        int nxt = -1, low = INF;
        for(int j = 0; j < n; j++) if(!vis[j] && d[cur][j] < low) { low = d[cur][j]; nxt = j; }
        if(nxt == -1) { cout << "Graph is disconnected\n"; return; }
        vis[nxt] = true; sum += low; path.push_back(nxt); cur = nxt;
    }
    path.push_back(0);
    if(d[cur][0] >= INF) { cout << "No optimized path was found\n"; return; }
    cout << "Minimum weight: " << sum + d[cur][0] << "\nPath: ";
    for(int i = 0; i < (int)path.size(); i++) cout << nm[path[i]] << (i == (int)path.size() - 1 ? "" : " -> ");
    cout << '\n';
}
void main_2() {
    cout << "\nTSP: Nearest neighbor\n----------------------------------------\n";
    // int n, e, v_cnt = 0; cin >> n >> e;
    int n = 5, v_cnt = 0;
    vector<vector<int>> d(n, vector<int>(n, INF));
    map<int, string> nm; map<string, int> id;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = (i == j ? 0 : INF);
    /*
        for(int i = 0; i < e; i++) {
            string u, v; int w; cin >> u >> v >> w;
            if(id.find(u) == end(id)) { id[u] = v_cnt; nm[v_cnt++] = u; }
            if(id.find(v) == end(id)) { id[v] = v_cnt; nm[v_cnt++] = v; }
            d[id[u]][id[v]] = d[id[v]][id[u]] = w;
        }
    */
    auto push = [&](string u, string v, int w){
        if(id.find(u) == end(id)) { id[u] = v_cnt; nm[v_cnt++] = u; }
        if(id.find(v) == end(id)) { id[v] = v_cnt; nm[v_cnt++] = v; }
        d[id[u]][id[v]] = d[id[v]][id[u]] = w;
    };
    push("A", "B", 5); push("A", "C", 15); push("A", "D", 1); push("A", "E", 2);
    push("B", "C", 6); push("B", "E", 8); push("C", "D", 10); push("D", "E", 3);
    // push("A", "B", 5); push("A", "D", 1); push("A", "E", 2);
    // push("B", "C", 6); push("B", "E", 8); push("D", "E", 3);
    if(v_cnt < n) cout << "City information were not found\n";
    else nearestNeighborTSP(n, d, nm);
}

int main()
{
    main_1(); main_2();
    return 0;
}
