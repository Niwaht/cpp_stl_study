#include <iostream>
using namespace std;

/// State space searches via BFS
#include <vector>
#include <queue>
void main_1() {
    cout << "State space searches via BFS\n----------------------------------------\n";
    // int X, Y; cin >> X >> Y;
    int X = 2, Y = 999;
    const int MAX = 1e5;
    vector<int> dist(MAX + 1, -1);
    queue<int> q; q.push(X); dist[X] = 0;
    while(!q.empty()) {
        int current = q.front(); q.pop();
        if(current == Y) break;
        vector<int> actions = {current + 1, current - 1, current * 2};
        for(int res : actions) {
            if(res >= 0 && res <= MAX && dist[res] == -1) { dist[res] = dist[current] + 1; q.push(res); }
        }
    }
    cout << "Least number of actions required: " << dist[Y] << '\n';
}

/// State space searches via DFS
#include <stack>
int n, m;
// vector<vector<int>> grid;
vector<vector<int>> grid = {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}};
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(grid[x][y] == 0 || visited[x][y]) return false;
    if(x == n - 1 && y == m - 1) return true;
    visited[x][y] = true;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(dfs(nx, ny)) return true;
    }
    return false;
}
void main_2() {
    cout << "\nState space searches via DFS\n----------------------------------------\n";
    // cin >> n >> m;
    n = 3; m = 3;
    // grid.assign(n, vector<int>(m));
    // for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cin >> grid[i][j]; }
    visited.assign(n, vector<bool>(m, false));
    (dfs(0, 0)) ? cout << "Reaching the destination is possible\n" : cout << "Reaching the destination is impossible\n";
}

/// State space searches via Dijkstra's algorithm
#include <climits>
void main_3() {
    cout << "\nState space searches via Dijkstra\n----------------------------------------\n";
    // int n, m; cin >> n >> m;
    int n = 3, m = 3;
    vector<vector<int>> cost = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cin >> cost[i][j]; }
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dist[0][0] = cost[0][0]; pq.push({dist[0][0], {0, 0}});
    while(!pq.empty()) {
        auto [d, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;
        if(d > dist[x][y]) continue;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(dist[nx][ny] > dist[x][y] + cost[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    cout << "Least cost via Dijkstra's algorithm: " << dist[n - 1][m - 1] << '\n';
}

int main()
{
    main_1(); main_2(); main_3();
    return 0;
}
