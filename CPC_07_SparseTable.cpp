#include <iostream>
using namespace std;

/// Sparse tables
#include <vector>
void main_1() {
    cout << "Sparse tables\n----------------------------------------\n";
    vector<int> A = {0, 3, 4, 1, 5, 2};             // 1-based index
    int N = 5, K = __lg(N) + 1;
    vector<vector<int>> ST(N+1, vector<int>(K));
    for(int i = 1; i <= N; i++) ST[i][0] = A[i];    // x = 0
    for(int x = 1; (1<<x) <= N; x++) { for(int i = 1; i+(1<<x)-1 <= N; i++) ST[i][x] = min(ST[i][x-1], ST[i+(1<<(x-1))][x-1]); }

    // Query example
    int L = 2, R = 4, k = __lg(R-L+1), answer = min(ST[L][k], ST[R-(1<<k)+1][k]);
    cout << "RMQ min: " << answer << '\n';
}

/// Sparse tables via custom logarithm
const int MAXN = 100005;
int st[MAXN][20];                                   // Sparse Table
int lg[MAXN];                                       // log2 values
int n;
void buildLog() {
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
}
void buildSparseTable(vector<int>& a) {
    n = a.size();
    for(int i = 0; i < n; i++) st[i][0] = a[i];     // j = 0
    for(int j = 1; (1 << j) <= n; j++) {            // j > 0
        for(int i = 0; i + (1 << j) <= n; i++) { st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]); }
    }
}
int query(int L, int R) {
    int len = R - L + 1, j = lg[len];
    return min(st[L][j], st[(R-(1<<j))+1][j]);
}
void main_2() {
    cout << "\nSparse tables via custom logarithm\n----------------------------------------\n";
    vector<int> a = {5, 2, 4, 7, 1, 3, 6};
    buildLog();
    buildSparseTable(a);
    cout << query(1, 4) << '\n' << query(3, 6) << '\n';
}

/// Finding the maximum of the sum of minimums of k contiguous subarrays in an array
const int LOGN = 20;
int k, log2x[MAXN];
long long A[MAXN] = {5, 1, 3, 4, 2, 6};
long long st_3[MAXN][LOGN];
void createSparseTable() {
    for(int i = 1; i <= n; i++) st_3[i][0] = A[i];
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) st_3[i][j] = min(st_3[i][j-1], st_3[i+(1<<(j-1))][j-1]);
    }
    log2x[1] = 0;
    for(int i = 2; i <= n; i++) log2x[i] = log2x[i/2] + 1;
}
long long query_3(int l, int r) {
    int j = log2x[r-l+1];
    return min(st_3[l][j], st_3[r-(1<<j)+1][j]);
}
void main_3() {
    cout << "\nFinding max(sum(min(contig. subarrays)))\n----------------------------------------\n";
    // cin >> n >> k;
    n = 6; k = 3;
    // for(int i = 1; i <= n; i++) cin >> A[i];
    createSparseTable();
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, LLONG_MIN));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int p = j-1; p < i; p++) {
                long long minimum = query_3(p+1, i);        // minimum of current segment
                dp[i][j] = max(dp[i][j], dp[p][j-1] + minimum);
            }
        }
    }
    cout << dp[n][k] << '\n';
}

int main()
{
    main_1(); main_2(); main_3();
    return 0;
}
