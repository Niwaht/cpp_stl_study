#include <iostream>
using namespace std;

/// Trees
#include <vector>
#define n1 node_1
struct n1 {
    int id, parent;
    vector<int> children;
    n1(int _id, int _parent = -1) { id = _id; parent = _parent; }
};
void main_1() {
    cout << "Trees\n----------------------------------------\n";
    vector<n1*> tree;
    for(int i = 0; i <= 10; i++) tree.push_back(new n1(i));
    tree[1]->children = {2, 3};
    tree[2]->parent = 1;
    tree[2]->children = {4, 5};
    tree[5]->parent = 2;
    tree[5]->children = {7, 8};
    cout << "Children of Node 2: ";
    for(int child : tree[2]->children) cout << child << ' ';
    cout << "\nParent   of Node 5: " << tree[5]->parent << '\n';
}

/// Tree traversals
#include <queue>
#define n2 node_2
struct n2 {
    int data;
    n2 *left, *right;
    n2(int v) { data = v; left = right = nullptr; }
};
void printPreOrder(n2* node) {      // DFS: root -> left -> right
    if(node == nullptr) return;
    cout << node->data << ' '; printPreOrder(node->left); printPreOrder(node->right);
}
void printInOrder(n2* node) {       // DFS: left -> root -> right
    if(node == nullptr) return;
    printInOrder(node->left); cout << node->data << ' '; printInOrder(node->right);
}
void printPostOrder(n2* node) {     // DFS: left -> right -> root
    if(node == nullptr) return;
    printPostOrder(node->left); printPostOrder(node->right); cout << node->data << ' ';
}
void printLevelOrder(n2* node) {    // BFS
    if(node == nullptr) return;
    queue<n2*> q; q.push(node);
    while(!q.empty()) {
        n2* current = q.front(); q.pop();
        cout << current->data << ' ';
        if(current->left  != nullptr) q.push(current->left);
        if(current->right != nullptr) q.push(current->right);
    }
}
void main_2() {
    cout << "\nTree traversals\n----------------------------------------\n";
    n2* root = new n2(1);
    root->left = new n2(2);
    root->right = new n2(3);
    root->left->left = new n2(4);
    root->left->right = new n2(5);
    cout << "  Pre-order traversal: "; printPreOrder(root);   cout << '\n';
    cout << "   In-order traversal: "; printInOrder(root);    cout << '\n';
    cout << " Post-order traversal: "; printPostOrder(root);  cout << '\n';
    cout << "Level-order traversal: "; printLevelOrder(root); cout << '\n';
}

/// Tree reconstructions
#include <unordered_map>
#include <algorithm>
#define n3 node_3
struct n3 {
    int data;
    n3 *left, *right;
    n3(int v) : data(v), left(nullptr), right(nullptr) {}
};
n3* buildPreIn(vector<int>& pre, int& preIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(inStart > inEnd) return nullptr;
    int rootVal = pre[preIdx++];
    n3* root = new n3(rootVal);
    int rootInIdx = inMap[rootVal];

    // Pre-order: left -> right
    root->left  = buildPreIn(pre, preIdx, inStart, rootInIdx - 1, inMap);
    root->right = buildPreIn(pre, preIdx, rootInIdx + 1, inEnd,   inMap);
    return root;
}
n3* buildPostIn(vector<int>& post, int& postIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(inStart > inEnd) return nullptr;
    int rootVal = post[postIdx--];
    n3* root = new n3(rootVal);
    int rootInIdx = inMap[rootVal];

    // Post-order: right -> left
    root->right = buildPostIn(post, postIdx, rootInIdx + 1, inEnd,   inMap);
    root->left  = buildPostIn(post, postIdx, inStart, rootInIdx - 1, inMap);
    return root;
}
void printLevelOrder_3(n3* root) {
    if(!root) return;
    vector<n3*> q = {root};
    int i = 0;
    while(i < (int)q.size()) {
        n3* curr = q[i++];
        cout << curr->data << ' ';
        if(curr->left)  q.push_back(curr->left);
        if(curr->right) q.push_back(curr->right);
    }
}
void main_3() {
    cout << "\nTree reconstructions\n----------------------------------------\n";
    vector<int> preOrder = {1, 2, 4, 5, 3}, inOrder = {4, 2, 5, 1, 3}, postOrder = {4, 5, 2, 3, 1};
    unordered_map<int, int> inMap;
    for(int i = 0; i < (int)inOrder.size(); i++) inMap[inOrder[i]] = i;
    int preIdx = 0, postIdx = postOrder.size() - 1;
    n3 *preRoot  = buildPreIn(preOrder,   preIdx,  0, inOrder.size() - 1, inMap),
       *postRoot = buildPostIn(postOrder, postIdx, 0, inOrder.size() - 1, inMap);
    cout << "Tree from Pre+In  (Level-order): "; printLevelOrder_3(preRoot);  cout << '\n';
    cout << "Tree from Post+In (Level-order): "; printLevelOrder_3(postRoot); cout << '\n';
}

/// Finding sizes of subtrees
const int MAXN = 100005;
vector<int> adj[MAXN];
int subtree_size[MAXN];
void calculate_size(int u, int p) {
    subtree_size[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        calculate_size(v, u);
        subtree_size[u] += subtree_size[v];
    }
}
void main_4() {
    cout << "\nFinding sizes of subtrees\n----------------------------------------\n";
    /*
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        calculate_size(1, -1);
        for(int i = 1; i <= n; i++) cout << "Size of subtree " << i << ": " << subtree_size[i] << '\n';
    */

    int n = 5;
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[2].push_back(5); adj[5].push_back(2);
    calculate_size(1, -1);
    for(int i = 1; i <= n; i++) cout << "Size of subtree " << i << ": " << subtree_size[i] << '\n';
}

/// Subtree operations
vector<int> adj_5[MAXN];
int in[MAXN], out[MAXN], timer = 0;
long long bit[MAXN];    // Fenwick Tree (Binary Indexed Tree)
void update_bit(int idx, int v, int n) { for(; idx <= n; idx += idx & -idx) bit[idx] += v; }
long long query_bit(int idx) {
    long long sum = 0;
    for(; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}
void dfs(int u, int p) {
    in[u] = ++timer;
    for(int v : adj_5[u]) { if(v != p) dfs(v, u); }
    out[u] = timer;
}
void main_5() {
    cout << "\nSubtree operations\n----------------------------------------\n";
    /*
        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj_5[u].push_back(v); adj_5[v].push_back(u);
        }
        dfs(1, 0);
        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int k, v; cin >> k >> v;
                update_bit(in[k], v, n);
                update_bit(out[k] + 1, -v, n);
            } else {
                int x; cin >> x;
                cout << query_bit(in[x]) << '\n';
            }
        }
    */

    int n = 5, q = 4;
    adj_5[1].push_back(2); adj_5[2].push_back(1);
    adj_5[1].push_back(3); adj_5[3].push_back(1);
    adj_5[2].push_back(4); adj_5[4].push_back(2);
    adj_5[2].push_back(5); adj_5[5].push_back(2);
    dfs(1, 0);
    vector<pair<int, pair<int, int>>> qs = {{1, {2, 5}}, {2, {2, -1}}, {2, {3, -1}}, {2, {4, -1}}};
    for(int i = 0; i < q; i++) {
        if(qs[i].first == 1) {
            int k = qs[i].second.first, v = qs[i].second.second;
            update_bit(in[k], v, n);
            update_bit(out[k] + 1, -v, n);
        } else {
            int x = qs[i].second.first;
            cout << query_bit(in[x]) << '\n';
        }
    }
}

/// Tree diameters
#define a6 adj_6
vector<vector<int>> a6;
int deepest, max_depth;
void dfs(int u, int parent, int depth) {
    if(depth > max_depth) { max_depth = depth; deepest = u; }
    for(int v : a6[u]) { if(v != parent) dfs(v, u, depth + 1); }
}
int diameter(int n) {
    if(n <= 1) return 0;
    max_depth = -1; dfs(1, -1, 0);
    int start = deepest;
    max_depth = -1; dfs(start, -1, 0);
    return max_depth;
}
void main_6() {
    cout << "\nTree diameters\n----------------------------------------\n";
    /*
        int n;
        cin >> n;
        a6.assign(n + 1, vector<int>());
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int result = diameter(n);
        cout << "Tree Diameter: " << result << '\n';
    */

    int n = 8;
    a6.assign(n + 1, vector<int>());
    auto push = [](int u, int v){ a6[u].push_back(v); a6[v].push_back(u); };
    push(1, 2); push(1, 3); push(2, 4); push(2, 5);
    push(3, 6); push(5, 7); push(5, 8);
    int result = diameter(n);
    cout << "Tree Diameter: " << result << '\n';
}

/// Tree diameters via iterative depth-first searches
#include <stack>
#define a7 adj_7
struct state { int u, parent, depth; };
vector<vector<int>> a7;
void dfs_iterative(int start) {
    stack<state> s;
    s.push({start, -1, 0});
    while(!s.empty()) {
        state current = s.top(); s.pop();
        int u = current.u, p = current.parent, d = current.depth;
        if(d > max_depth) { max_depth = d; deepest = u; }
        for(int v : a7[u]) { if(v != p) s.push({v, u, d + 1}); }
    }
}
int diameter_iterative(int n) {
    if(n <= 1) return 0;
    max_depth = -1; dfs_iterative(1);
    int start = deepest;
    max_depth = -1; dfs_iterative(start);
    return max_depth;
}
void main_7() {
    cout << "\nTree diameters via iterative DFS\n----------------------------------------\n";
    /*
        int n;
        cin >> n;
        a7.assign(n + 1, vector<int>());
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int result = diameter_iterative(n);
        cout << "Tree Diameter: " << result << '\n';
    */

    int n = 8;
    a7.assign(n + 1, vector<int>());
    auto push = [](int u, int v){ a7[u].push_back(v); a7[v].push_back(u); };
    push(1, 2); push(1, 3); push(2, 4); push(2, 5);
    push(3, 6); push(5, 7); push(5, 8);
    int result = diameter_iterative(n);
    cout << "Tree Diameter: " << result << '\n';
}


int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7();
    return 0;
}
