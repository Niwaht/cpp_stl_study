#include <iostream>
using namespace std;

/// Iterative depth-first searches
#include <vector>
#include <stack>
void dfsIterative(int source, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(source);
    cout << "DFS Path: ";
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        if(!visited[x]) {
            visited[x] = true;
            cout << x << ' ';
            for(int neighbor : adj[x]) { if(!visited[neighbor]) s.push(neighbor); }
        }
    }
    cout << '\n';
}
void main_1() {
    cout << "Iterative depth-first searches\n----------------------------------------\n";
    int vertices = 5;
    vector<vector<int>> adj(vertices);
    adj[0] = {1, 2}; adj[1] = {0, 3, 4}; adj[2] = {0}; adj[3] = {1}; adj[4] = {1};
    cout << "Starting DFS from vertex 0:\n";
    dfsIterative(0, adj);
}

/// Iterative depth-first searches II
void main_2() {
    cout << "\nIterative depth-first searches II\n----------------------------------------\n";
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    cout << "Starting DFS from vertex 0:\n";
    dfsIterative(0, graph);
}

/// Recursive depth-first searches
vector<bool> visited;
vector<vector<int>> adj;
void dfsRecursive(int node) {
    visited[node] = true;
    cout << node << ' ';
    for(int neighbor : adj[node]) { if(!visited[neighbor]) dfsRecursive(neighbor); }
}
void main_3() {
    cout << "\nRecursive depth-first searches\n----------------------------------------\n";
    int vertices = 5;
    adj.resize(vertices);
    visited.assign(vertices, false);
    adj[0] = {1, 2}; adj[1] = {0, 3, 4}; adj[2] = {0}; adj[3] = {1}; adj[4] = {1};
    cout << "Starting DFS from vertex 0:\nDFS Path: ";
    dfsRecursive(0);
    // dfsRecursive(1);
    // dfsRecursive(3);
    cout << '\n';
}

/// Recursive depth-first searches II
void dfsRecursive_4(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << ' ';
    for(int neighbor : graph[node]) { if(!visited[neighbor]) dfsRecursive_4(neighbor, graph, visited); }
}
void main_4() {
    cout << "\nRecursive depth-first searches II\n----------------------------------------\n";
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    int n = graph.size();
    vector<bool> visited(n, false);
    cout << "Starting DFS from vertex 0:\nDFS Path: ";
    dfsRecursive_4(0, graph, visited);
    cout << '\n';
}

/// Flood fills
int R, C;
int grid[101][101], dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
bool visited_5[101][101];
int flood_fill_dfs(int r, int c) {
    visited_5[r][c] = true;
    int size = 1;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 1 && nr <= R && nc >= 1 && nc <= C && grid[nr][nc] == 0 && !visited_5[nr][nc]) size += flood_fill_dfs(nr, nc);
    }
    return size;
}
void flood_fill() {
    int regions = 0;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(grid[i][j] == 0 && !visited_5[i][j]) {
                regions++;
                int regionSize = flood_fill_dfs(i, j);
                cout << "Region " << regions << "'s size: " << regionSize << '\n';
            }
        }
    }
    cout << "Number of regions: " << regions << '\n';
}
void main_5() {
    cout << "\nFlood fills\n----------------------------------------\n";
    /*
        if(!(cin >> R >> C)) return;
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                cin >> grid[i][j];
                visited_5[i][j] = false;
            }
        }
        flood_fill();
    */

    R = 3; C = 4;
    grid[1][1] = 0; grid[1][2] = 1; grid[1][3] = 0; grid[1][4] = 0;
    grid[2][1] = 0; grid[2][2] = 1; grid[2][3] = 1; grid[2][4] = 1;
    grid[3][1] = 0; grid[3][2] = 0; grid[3][3] = 0; grid[3][4] = 1;
    for(int i = 1; i <= R; i++) { for(int j = 1; j <= C; j++) { visited_5[i][j] = false; } }
    flood_fill();
}

/// Sinking islands
void sink(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size(), cols = grid[0].size();
    if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') return;
    grid[r][c] = '0';
    sink(grid, r+1, c); sink(grid, r-1, c); sink(grid, r, c+1); sink(grid, r, c-1);
}
int countIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    int count = 0;
    for(int i = 0; i < (int)grid.size(); i++) {
        for(int j = 0; j < (int)grid[0].size(); j++) { if(grid[i][j] == '1') { count++; sink(grid, i, j); } }
    }
    return count;
}
void main_6() {
    cout << "\nSinking islands\n----------------------------------------\n";
    /*
        int R, C;
        cin >> R >> C;
        vector<vector<char>> grid(R, vector<char>(C));
        for(int i = 0; i < R; i++) { for(int j = 0; j < C; j++) cin >> grid[i][j]; }
        int result = countIslands(grid);
        cout << "Total number of islands: " << result << '\n';
    */

    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    int result = countIslands(grid);
    cout << "Total number of islands: " << result << '\n';
}

/// Maze traversals
#include <algorithm>
const int ROWS = 3, COLS = 4;
int maze[ROWS][COLS] = {{0, 0, 0, 0}, {1, 1, 0, 1}, {0, 0, 0, 0}};
// const int ROWS = 3, COLS = 3;
// int maze[ROWS][COLS] = {{0, 0, 1}, {0, 1, 0}, {0, 0, 0}};
// const int ROWS = 3, COLS = 3;
// int maze[ROWS][COLS] = {{0, 0, 1}, {0, 1, 0}, {0, 1, 0}};
bool visited_7[ROWS][COLS];
vector<pair<int, int>> path;
bool solveMaze(int r, int c) {
    if(r == ROWS - 1 && c == COLS - 1) { visited_7[r][c] = true; path.push_back({r, c}); return true; }
    if(r < 0 || c < 0 || r >= ROWS || c >= COLS || maze[r][c] || visited_7[r][c]) return false;
    visited_7[r][c] = true;
    path.push_back({r, c});
    for(int i = 0; i < 4; i++) { if(solveMaze(r + dr[i], c + dc[i])) return true; }
    path.pop_back();
    return false;
}
void printSolution() {
    char output[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) { (maze[i][j] == 1) ? output[i][j] = '#' : output[i][j] = '.'; }
    }
    for(auto p : path) output[p.first][p.second] = '*';
    cout << "Maze Solution (via DFS):\n[S = Start, E = Exit, * = Path, # = Wall]\n";
    output[0][0] = 'S'; output[ROWS-1][COLS-1] = 'E';
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) cout << output[i][j] << ' ';
        cout << '\n';
    }
}
void main_7() {
    cout << "\nMaze traversals\n----------------------------------------\n";
    if(solveMaze(0, 0)) { cout << "Path Found!\n"; printSolution(); }
    else cout << "No path to the exit found.\n";
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7();
    return 0;
}
