#include <iostream>
using namespace std;

/// Wings and nuggets
#include <vector>
#include <algorithm>
typedef long long ll;
const ll INF = 1e18;
void solveNuggets() {
    /*
        ll X, a, b, c;
        cin >> X >> a >> b >> c;
        ll p4_36 = 9 * a, p6_36 = 6 * b, p9_36 = 4 * c;
        ll best_lcm_price = min({p4_36, p6_36, p9_36});
        ll offset_cost = 0, count4 = 0, count6 = 0, count9 = 0;
        if(X > 500) {
            ll num_bundles = (X - 500) / 36;
            offset_cost = num_bundles * best_lcm_price;
            X -= (num_bundles * 36);
            if(best_lcm_price == p4_36) count4 += num_bundles * 9;
            else if(best_lcm_price == p6_36) count6 += num_bundles * 6;
            else count9 += num_bundles * 4;
        }
        int max_limit = X + 10;
        vector<ll> dp(max_limit + 1, INF);
        vector<int> choice(max_limit + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= max_limit; i++) {
            if(i >= 4 && dp[i - 4] + a < dp[i]) { dp[i] = dp[i - 4] + a; choice[i] = 4; }
            if(i >= 6 && dp[i - 6] + b < dp[i]) { dp[i] = dp[i - 6] + b; choice[i] = 6; }
            if(i >= 9 && dp[i - 9] + c < dp[i]) { dp[i] = dp[i - 9] + c; choice[i] = 9; }
        }
        int best_total_nuggets = X;
        for(int i = X; i <= max_limit; i++) { if(dp[i] < dp[best_total_nuggets]) best_total_nuggets = i; }
        int curr = best_total_nuggets;
        while(curr > 0 && choice[curr] != -1) {
            int pack = choice[curr];
            if(pack == 4) count4++;
            else if(pack == 6) count6++;
            else if(pack == 9) count9++;
            curr -= pack;
        }
    */

    // ll X = 36, a = 40, b = 89, c = 91;
    // ll X = 37, a = 40, b = 89, c = 91;
    // X = 1006, a = 40, b = 89, c = 91;
    ll X = 11119, a = 40, b = 89, c = 91;
    // Find the cheapest package for 36 nuggets
    ll p4_36 = 9 * a, p6_36 = 6 * b, p9_36 = 4 * c;
    ll best_lcm_price = min({p4_36, p6_36, p9_36});
    ll offset_cost = 0, count4 = 0, count6 = 0, count9 = 0;
    // Greedy algorithm for large X
    if(X > 500) {
        ll num_bundles = (X - 500) / 36;
        offset_cost = num_bundles * best_lcm_price;
        X -= (num_bundles * 36);
        // Note the number of nuggets counted from the package
        if(best_lcm_price == p4_36) count4 += num_bundles * 9;
        else if(best_lcm_price == p6_36) count6 += num_bundles * 6;
        else count9 += num_bundles * 4;
    }
    // DP + backtracking
    int max_limit = X + 10;
    vector<ll> dp(max_limit + 1, INF);
    vector<int> choice(max_limit + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= max_limit; i++) {
        if(i >= 4 && dp[i - 4] + a < dp[i]) { dp[i] = dp[i - 4] + a; choice[i] = 4; }
        if(i >= 6 && dp[i - 6] + b < dp[i]) { dp[i] = dp[i - 6] + b; choice[i] = 6; }
        if(i >= 9 && dp[i - 9] + c < dp[i]) { dp[i] = dp[i - 9] + c; choice[i] = 9; }
    }
    // Find the best number of nuggets
    int best_total_nuggets = X;
    for(int i = X; i <= max_limit; i++) { if(dp[i] < dp[best_total_nuggets]) best_total_nuggets = i; }
    // Backtrack to find number of packages counted via DP
    int curr = best_total_nuggets;
    while(curr > 0 && choice[curr] != -1) {
        int pack = choice[curr];
        if(pack == 4) count4++;
        else if(pack == 6) count6++;
        else if(pack == 9) count9++;
        curr -= pack;
    }
    // Print the result
    cout << "Result:\nTotal Cost: " << offset_cost + dp[best_total_nuggets] << '\n'
         << "Total Nuggets: " << (best_total_nuggets + (offset_cost > 0 ? (offset_cost/best_lcm_price) * 36 : 0)) << '\n'
         << "4-pack: " << count4 << " packs\n6-pack: " << count6 << " packs\n9-pack: " << count9 << " packs\n";
}
void main_1() {
    cout << "Wings and nuggets\n----------------------------------------\n";
    solveNuggets();
}

int main()
{
    main_1();
    return 0;
}
