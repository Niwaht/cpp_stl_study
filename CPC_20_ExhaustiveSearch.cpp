#include <iostream>
using namespace std;

/// Dice sum problem
#include <vector>
vector<int> current_dice;
void solve_dice_sum(int num_dice, int target_sum, int dice_count, int current_sum) {
    // Pruning
    int remaining_dice = num_dice - dice_count;
    // Bounding
    if(current_sum + (remaining_dice * 1) > target_sum) return;
    if(current_sum + (remaining_dice * 6) < target_sum) return;
    // Base case
    if(dice_count == num_dice) {
        for(int i = 0; i < num_dice; i++) cout << current_dice[i] << (i < num_dice - 1 ? " " : "");
        cout << '\n'; return;
    }
    // Build search space
    for(int face = 1; face <= 6; face++) {
        // Explore & Backtracking
        current_dice.push_back(face);                       // do
        solve_dice_sum(num_dice, target_sum, dice_count + 1, current_sum + face);          // explore
        current_dice.pop_back();                            // undo
    }
}
void main_1() {
    cout << "Dice sum problem\n----------------------------------------\n";
    // int num_dice, target_sum; cin >> num_dice >> target_sum;
    int num_dice = 3, target_sum = 14;
    cout << "Solutions:\n"; solve_dice_sum(num_dice, target_sum, 0, 0);
}

/// Subset sums in ranges
#include <algorithm>
vector<long long> current_weights, results;
long long limit_R;
void subset_sum_es(int idx, long long accum_value) {
    if(accum_value > limit_R) return;                                                       // pruning
    if(idx == (int)current_weights.size()) { results.push_back(accum_value); return; }      // base case
    subset_sum_es(idx + 1, accum_value + current_weights[idx]);                             // build search space + backtracking
    subset_sum_es(idx + 1, accum_value);
}
void main_2() {
    cout << "\nSubset sums in ranges\n----------------------------------------\n";
    // int N; long long L, R; cin >> N >> L >> R;
    int N = 4; long long L = 5LL, R = 8LL;
    limit_R = R;
    /*
        vector<long long> all_w(N);
        for(int i = 0; i < N; i++) cin >> all_w[i];
    */
    vector<long long> all_w = {2LL, 3LL, 5LL, 10LL};
    // Meet-in-the-middle
    for(int i = 0; i < N / 2; i++) current_weights.push_back(all_w[i]);
    subset_sum_es(0, 0); vector<long long> sumsL = results;
    current_weights.clear(); results.clear();
    for(int i = N / 2; i < N; i++) current_weights.push_back(all_w[i]);
    subset_sum_es(0, 0); vector<long long> sumsR = results;
    // Matching
    sort(begin(sumsR), end(sumsR));
    long long total_ways = 0;
    for(long long x : sumsL) {
        // x + y -> [L, R]; y -> [L - x, R - x]
        auto it_low  = lower_bound(begin(sumsR), end(sumsR), L - x);
        auto it_high = upper_bound(begin(sumsR), end(sumsR), R - x);
        total_ways  += distance(it_low, it_high);
    }
    cout << total_ways << '\n';
}

/// Compact subset sums in ranges
typedef long long ll;
vector<ll> w, s[2];
void sses_compact(ll R, int i, ll v, int e, int t) {
    if(v > R) return;                                       // pruning
    if(i == e) { s[t].push_back(v); return; }               // base case
    sses_compact(R, i + 1, v + w[i], e, t);              // build search space + backtracking
    sses_compact(R, i + 1, v,        e, t);
}
void main_3() {
    cout << "\nCompact subset sums in ranges\n----------------------------------------\n";
    // ll n, L, R; cin >> n >> L >> R;
    ll n = 4LL, L = 5LL, R = 8LL;
    // w.resize(n); for(ll &x : w) cin >> x;
    w.push_back(2LL); w.push_back(3LL); w.push_back(5LL); w.push_back(10LL);
    sses_compact(R, 0, 0, n / 2, 0);
    sses_compact(R, n / 2, 0, n, 1);
    sort(begin(s[1]), end(s[1]));
    ll ans = 0;
    for(ll x : s[0]) ans += upper_bound(begin(s[1]), end(s[1]), R - x) - lower_bound(begin(s[1]), end(s[1]), L - x);
    cout << ans << '\n';
}

/// Digital vault hash-unlocks
#include <unordered_map>
unordered_map<ll, pair<ll, ll>> left_map; ll a[45], ans = 0;
void gen_left(ll n, ll S, int idx, ll sum, int cnt) {
    if(sum > S) return;
    if(idx == n / 2) { (cnt % 2 == 0) ? left_map[sum].first++ : left_map[sum].second++; return;}
    gen_left(n, S, idx + 1, sum, cnt); gen_left(n, S, idx + 1, sum + a[idx], cnt + 1);
}
void gen_right(ll n, ll S, int idx, ll sum, int cnt) {
    if(sum > S) return;
    if(idx == n) {
        ll need = S - sum; auto it = left_map.find(need);
        if(it != end(left_map)) { (cnt % 2 == 0) ? ans += it->second.second : ans += it->second.first; }
        return;
    }
    gen_right(n, S, idx + 1, sum, cnt); gen_right(n, S, idx + 1, sum + a[idx], cnt + 1);
}
void main_4() {
    cout << "\nDigital vault hash-unlocks\n----------------------------------------\n";
    // ll n, S; cin >> n >> S;
    ll n = 3LL, S = 10LL;
    // for(int i = 0; i < n; i++) cin >> a[i];
    a[0] = a[1] = a[2] = 10;
    left_map.reserve(1 << 20);
    gen_left(n, S, 0, 0, 0); gen_right(n, S, n / 2, 0, 0);
    cout << "Number of odd combinations: " << ans << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
