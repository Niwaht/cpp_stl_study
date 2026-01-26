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

int main()
{
    main_1();
    return 0;
}
