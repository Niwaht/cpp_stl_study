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
    cout << "\nParent of Node 5: " << tree[5]->parent << '\n';
}

int main()
{
    main_1();
    return 0;
}
