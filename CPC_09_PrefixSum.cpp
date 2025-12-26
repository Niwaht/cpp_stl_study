#include <iostream>
using namespace std;

/// 1-dimensional prefix sums
#include <vector>
void main_1() {
    cout << "1-dimensional prefix sums\n----------------------------------------\n";
    /*
        int N, Q;
        cin >> N >> Q;
        vector<long long> A(N+1), P(N+1, 0);
        for(int i = 1; i <= N; i++) { cin >> A[i]; P[i] = P[i-1] + A[i]; }
        while(Q--) {
            int L, R;
            cin >> L >> R;
            cout << P[R] - P[L-1] << '\n';
        }
    */

    int N, Q;
    // cin >> N >> Q;
    N = 5; Q = 3;
    vector<long long> A = {3, 1, 4, 1, 5};
    vector<long long> P(N+1, 0);
    vector<pair<int, int>> qs = {{2, 4}, {1, 2}, {2, 5}};
    // for(int i = 1; i <= N; i++) { cin >> A[i]; P[i] = P[i-1] + A[i]; }
    for(int i = 0; i < N; i++) P[i + 1] = P[i] + A[i];
    for(int i = 0; i < Q; i++) {
        int L, R;
        // cin >> L >> R;
        L = qs[i].first; R = qs[i].second;
        cout << P[R] - P[L-1] << '\n';
    }
}

/// 1-dimensional prefix sums II
void main_2() {
    cout << "\n1-dimensional prefix sums II\n----------------------------------------\n";
    /*
        long long A[20005], P[20005];
        int N, Q; cin >> N >> Q;
        for(int i = 1; i <= N; i++) { cin >> A[i]; P[i] = P[i-1] + A[i]; }
        while(Q--) {
            int L, R; cin >> L >> R;
            cout << P[R] - P[L-1] << '\n';
        }
    */

    int N, Q;
    // cin >> N >> Q;
    N = 5; Q = 2;
    long long A[5] = {10, 20, 30, 40, 50};
    long long P[20005];
    pair<int, int> qs[2] = {{2, 4}, {1, 5}};
    // for(int i = 1; i <= N; i++) { cin >> A[i]; P[i] = P[i-1] + A[i]; }
    for(int i = 0; i < N; i++) P[i + 1] = P[i] + A[i];
    for(int i = 0; i < Q; i++) {
        int L, R;
        // cin >> L >> R;
        L = qs[i].first; R = qs[i].second;
        cout << P[R] - P[L-1] << '\n';
    }
}

/// Prefix sums for enumeration via certain conditions
// Build a 2-dimensional array for counting specific nitrogenous bases
int p[4][200005];
int getIdx(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;                     // error
    }
}
void main_3() {
    cout << "\nPrefix sums for counting via conditions\n----------------------------------------\n";
    string dna = "AACGTACGG";                   // example DNA strand
    int n = dna.length();
    for(int i = 0; i < n; i++) {
        int charIdx = getIdx(dna[i]);
        for(int j = 0; j < 4; j++) p[j][i+1] = p[j][i];
        p[charIdx][i+1]++;
    }
    int L = 3, R = 8, target = getIdx('G'), result = p[target][R] - p[target][L-1];
    cout << "Count of 'G' between " << L << " and " << R << " is: " << result << '\n';
}


int main()
{
    main_1(); main_2(); main_3();
    return 0;
}
