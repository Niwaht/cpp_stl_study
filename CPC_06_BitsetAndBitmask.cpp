#include <iostream>
using namespace std;

/// Bitsets
#include <bitset>
void main_1() {
    cout << "Bitsets\n----------------------------------------\n";
    bitset<8> b1("01011001");
    bitset<8> b2("00011110");
    cout << (b1 & b2) << ' ' << (b1 | b2) << ' ' << b1.count() << '\n';
}

/// Bitset operations
void main_2() {
    cout << "\nBitset operations\n----------------------------------------\n";
    // create two 8-bit-sized bitsets
    bitset<8> b1("01011001");   // 89 in decimal
    bitset<8> b2("00011110");   // 30 in decimal
    cout << "b1: " << b1 << ",      b2: " << b2 << '\n'
         << "b1 & b2: " << (b1 & b2) << ", "                // bitwise AND (00011000)
         << "b1 | b2: " << (b1 | b2) << ", "                // bitwise OR  (01011111)
         << "b1 ^ b2: " << (b1 ^ b2) << '\n'                // bitwise XOR (01000111)
         << "~b1: " << b1 << ",     "                       // bitwise NOT (10100110)
         << "b1[3]: " << b1[3] << '\n'                      // THIRD bit   (1)
         << "Number of 1's in b1: " << b1.count() << '\n';  // COUNT       (4)
    b1.set(2, 0); cout << "b1 after setting bit 2 to 0: "      << b1 << '\n';
    b1.set();     cout << "b1 after setting all bits to 1: "   << b1 << '\n';
    b2.reset();   cout << "b2 after resetting all bits to 0: " << b2 << '\n';
    b1.flip(3);   cout << "b1 after flipping bit 3: " << b1 << '\n';
    if(b1.any())  { cout << "b1 has at least a bit set to 1\n"; } else { "b1 has no bits set to 1\n"; }     // ANY  (has at least one 1)
    if(b2.none()) { cout << "b2 has no bits set to 1\n"; } else { "b2 has at least a bit set to 1\n"; }     // NONE (has no 1s)
    cout << "b1 as decimal: " << b1.to_ulong() << '\n';
}

/// Bitset tests
void main_3() {
    cout << "\nBitset tests\n----------------------------------------\n";
    bitset<8> b1("01011001");
    cout << "Bit at position 0: " << b1.test(0) << '\n'     // (1)
         << "Bit at position 3: " << b1.test(3) << '\n'     // (1)
         << "Bit at position 7: " << b1.test(7) << '\n'     // (0)
         << "Bit at position 2: " << b1.test(2) << '\n'     // (1)
         << "Bit at position 5: " << b1.test(5) << '\n'     // (1)
         << "Bit at position 6: " << b1.test(6) << '\n';    // (0)
}

/// Character counting
#include <vector>
void main_4() {
    cout << "\nCharacter counting\n----------------------------------------\n";
    vector<char> name = {'A', 'B', 'C', 'D', 'E'};
    int mask;
    // cin >> mask;
    mask = 31;
    cout << "Members = { ";
    for(int i = 0; i < 5; i++) { if(mask & (1 << i)) cout << name[i] << ' '; }
    cout << "}\nCount = " << __builtin_popcount(mask) << '\n';
}

/// Permission adjustments
const int PERM_READ   = (1 << 0);   // 1
const int PERM_WRITE  = (1 << 1);   // 2
const int PERM_DELETE = (1 << 2);   // 4
const int PERM_ADMIN  = (1 << 3);   // 8
const int PERM_BACKUP = (1 << 4);   // 16
// Use bitwise AND (&) to check whether permission is set in user_mask
bool has_permission(int user_mask, int permission) { return (user_mask & permission) != 0; }
void main_5() {
    cout << "\nPermission adjustments\n----------------------------------------\n";
    int user_a_mask = PERM_READ | PERM_WRITE | PERM_ADMIN;      // 1 | 2 | 8 = 11 (01011)
    cout << "User A's mask (binary): " << bitset<5>(user_a_mask) << '\n'
         << "--- User A's permission check ---\n"
         << "READ:   " << (has_permission(user_a_mask, PERM_READ)   ? "YES" : "NO") << '\n'
         << "DELETE: " << (has_permission(user_a_mask, PERM_DELETE) ? "YES" : "NO") << '\n';
    user_a_mask |= PERM_BACKUP;
    cout << "--- User A's permission recheck ---\n"
         << "New mask (binary): " << bitset<5>(user_a_mask) << '\n'
         << "BACKUP: " << (has_permission(user_a_mask, PERM_BACKUP) ? "YES" : "NO") << '\n';
}

/// Status of stocks
#define mso mark_sold_out
#define iso is_sold_out
const int ITEM_NUM = 100;
bitset<ITEM_NUM> out_of_stock;
void mark_sold_out(int item_id) { out_of_stock.set(item_id); cout << "Item ID " << item_id << " is now marked as SOLD OUT.\n"; }
bool is_sold_out(int item_id)   { return out_of_stock.test(item_id); }
void main_6() {
    cout << "\nStatus of stocks\n----------------------------------------\n";
    cout << "--- START ---\nBitset: " << out_of_stock << '\n';
    mso(5); mso(99); mso(0);
    cout << "--- AFTER OPERATION ---\nBitset: " << out_of_stock << '\n'
         << "--- CHECK ---\nITEM 5: " << (iso(5) ? "YES" : "NO") << "\nITEM 10: " << (iso(10) ? "YES" : "NO") << '\n'
         << "TOTAL SOLD OUT: " << out_of_stock.count() << '\n';
}

/// String comparison
void main_7() {
    cout << "\nString comparison\n----------------------------------------\n";
    string s1, s2;
    // cin >> s1 >> s2;
    s1 = "abacabad";
    s2 = "abbbabdd";
    int n = s1.size();
    bitset<1000> A, B;
    for(int i = 0; i < n; i++) { if(s1[i] == 'a') A.set(i); if(s2[i] == 'a') B.set(i); }
    bitset<1000> C = A & B;
    cout << s1 << '\n' << s2 << '\n' << C.count() << '\n';
}

/// Subset iterations
void main_8() {
    cout << "\nSubset iterations\n----------------------------------------\n";
    vector<char> name = {'A', 'B', 'C'};
    int n = name.size();
    for(int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for(int i = 0; i < n; i++) { if(mask & (1 << i)) cout << name[i] << ' '; }
        cout << "}\n";
    }
}

/// Subset iterations with criteria
void main_9() {
    cout << "\nSubset iterations with criteria\n----------------------------------------\n";
    vector<int> w = {2, 3, 4, 5};
    int n = 4, limit = 5;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for(int i = 0; i < n; i++) { if(mask & (1 << i)) sum += w[i]; }
        if(sum <= limit) {
            cout << "Subset: { ";
            for(int i = 0; i < n; i++) { if(mask & (1 << i)) cout << "ITEM" << i << ' '; }
            cout << "} = weight " << sum << '\n';
        }
    }
}

/// Optimal work assignment
#include <algorithm>
#include <cmath>
#define INF 1e9
void solve() {
    const int N = 3;
    // cost matrix C[employee][work]
    vector<vector<int>> C = {{3, 5, 1}, {2, 4, 6}, {7, 8, 9}};
    int total_states = (1 << N);                                                                // DP size = 2^N = 2^3 = 8
    vector<int> DP(total_states, INF);
    DP[0] = 0;                                                                                  // initial condition
    for(int mask = 1; mask < total_states; mask++) {                                            // iterate through all permutations
        int i = __builtin_popcount(mask) - 1;                                                   // C++20: std::popcount(mask)
        for(int j = 0; j < N; j++) {                                                            // iterate through all works
            if(mask & (1 << j)) {
                int mask_prev = mask ^ (1 << j), current_cost = DP[mask_prev] + C[i][j];        // calculate cost via cost matrix
                DP[mask] = min(DP[mask], current_cost);
            }
        }
    }
    int final_mask = total_states - 1;                                                          // binary 111
    cout << "Optimal cost: " << DP[final_mask] << '\n';
}
void main_10() {
    cout << "\nOptimal work assignment\n----------------------------------------\n";
    solve();
}

/// Travelling salesman problem (TSP)
#include <cstring>
int n = 4;
int dist[4][4] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
// int dist[20][20];
int dp[1 << 20][20];
int tsp(int mask, int pos, int n) {
    if(mask == (1 << n) - 1) return dist[pos][0];                                               // case after visiting every city
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INF;
    for(int city = 0; city < n; city++) {                                                       // case visiting a new city
        if((mask & (1 << city)) == 0) {
            int new_ans = dist[pos][city] + tsp(mask | (1 << city), city, n);
            ans = min(ans, new_ans);
        }
    }
    return dp[mask][pos] = ans;
}
void main_11() {
    cout << "\nTravelling salesman problem (TSP)\n----------------------------------------\n";
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++) { for(int j = 0; j < n; j++) { cin >> dist[i][j]; } }
    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0, n) << '\n';
}

/// Maximum subsets
void main_12() {
    cout << "\nMaximum subsets\n----------------------------------------\n";
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int max_sum = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) { sum += arr[i]; cnt++; }
            if(cnt <= k) max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5(); main_6(); main_7(); main_8(); main_9(); main_10();
    main_11(); main_12();
    return 0;
}
