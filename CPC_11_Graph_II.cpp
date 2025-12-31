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

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
