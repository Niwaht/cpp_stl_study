// TOPIC: Container Inside Container

/*
Input
6
1 2
1 3
2 4
2 5
3 6
3 8

Output
23
45
68

*/

/*
Tree Structure

          (1)
         /   \
        /     \
      (2)     (3)
     / \      / \
   (4) (5)  (6) (8)
*/

/*
Program data structure
[0]
[1]->[2][3]
[2]->[4][5]
[3]->[6][8]
[4]
[5]
[6]
[7]
[8]
*/

#include <iostream>
#include <vector>


using namespace std;

int main()
{
    std::vector<vector<int>> Tree;
    int edge, n1, n2;

    cin >> edge;
    Tree.resize(edge);

    for (int i=0; i < edge; ++i) {
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
    }

    for (const auto &e1: Tree) {
        for (const auto &e2: e1) {
            cout << e2;
        }
        cout << endl;
    }

    return 0;
}
