#include <iostream>
using namespace std;

/// Segment trees via recursion
const int MAXN = 100000;
int A[MAXN+1], tree[MAXN*4];
void build(int x, int L, int R) {
    if(L == R) { tree[x] = A[L]; return; }
    int mid = L+(R-L)/2;
    build(2*x, L, mid);
    build(2*x+1, mid+1, R);
    tree[x] = tree[2*x] + tree[2*x+1];
}
void main_1() {
    cout << "Segment trees via recursion\n----------------------------------------\n";
    int N = 8, temp[] = {0, 3, 1, 2, 5, 6, 4, 3, 2};
    for(int i = 1; i <= N; i++) A[i] = temp[i];
    build(1, 1, N);
    cout << "Sum of [1, " << N << "] = " << tree[1] << '\n';
}

int main()
{
    main_1();
    return 0;
}
