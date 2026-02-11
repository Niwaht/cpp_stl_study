#include <iostream>
#include <string>
using namespace std;

/// Prefix hashing
#include <vector>
typedef long long ll;
struct prefixHash {
    static const ll M = 1e9 + 7, B = 31;
    vector<ll> h, p;                            // h : prefix hash, p : powers of B
    prefixHash(const string& s) {
        int n = s.size();
        h.assign(n + 1, 0); p.assign(n + 1, 1);
        for(int i = 0; i < n; i++) {
            p[i + 1] = (p[i] * B) % M;
            h[i + 1] = (h[i] * B + s[i]) % M;
        }
    }
    ll getHash(int l, int r) const { ll res = (h[r + 1] - (h[l] * p[r - l + 1]) % M + M) % M; return res; }
    static ll patternHash(const string& s) { ll v = 0; for(char c : s) v = (v * B + c) % M; return v; }
};
void main_1() {
    cout << "Prefix hashing\n----------------------------------------\n";
    string t, q_s; int Q;
    cin >> t >> Q;
    prefixHash H(t);
    cout << "Match Result:\n";
    while(Q--) {
        cin >> q_s;
        ll target = prefixHash::patternHash(q_s);
        int n = t.size(), m = q_s.size();
        cout << q_s << ": ";
        bool found = false;
        for(int i = 0; i <= n - m; i++) {
            if(H.getHash(i, i + m - 1) == target) { cout << i << ' '; found = true; }
        }
        if(!found) cout << "Matching sequence not found";
        cout << '\n';
    }
}

int main()
{
    main_1();
    return 0;
}
