#include <iostream>
using namespace std;

/// Adjacency matrices
const int MAX_N = 6;
int adj[MAX_N][MAX_N];
int N = 5;
void init() { for(int i = 1; i <= N; i++) { for(int j = 1; j <= N; j++) adj[i][j] = 0; } }
void add_edge(int u, int v) { adj[u][v] = 1; }
void print_neighbors(int v) {
    cout << "Neighbors of " << v << ": ";
    for(int i = 1; i <= N; i++) { if(adj[v][i] != 0) cout << i << ' '; }
    cout << '\n';
}
void print_matrix() {
    cout << "Adjacency Matrix:\n";
    for(int i = 1; i <= N; i++) { for(int j = 1; j <= N; j++) { cout << adj[i][j] << ' '; } cout << '\n'; }
}
void main_1() {
    cout << "Adjacency matrices\n----------------------------------------\n";
    init();
    add_edge(1, 2); add_edge(1, 4); add_edge(2, 4); add_edge(2, 5); add_edge(3, 1); add_edge(5, 3);
    print_matrix();
    for(int v = 1; v <= N; v++) print_neighbors(v);
}

int main()
{
    main_1();
    return 0;
}
