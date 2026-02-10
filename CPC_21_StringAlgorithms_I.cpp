#include <iostream>
#include <string>
using namespace std;

/// Rabin-Karp algorithm
void rabin_karp(string t, string s) {
    // m : modulo, p : base, h : text hash, g : pattern hash, f : p^(n-1), i : index
    long long m = 1e9 + 7, p = 31, h = 0, g = 0, f = 1, i = 0, n = s.size(), L = t.size();
    if(n > L) return;
    // Precompute power and initial hash
    for(; i < n; i++) { g = (g * p + s[i]) % m; h = (h * p + t[i]) % m; if(i < n - 1) f = (f * p) % m; }
    // Sliding window (matching and rolling)
    for(i = 0; i <= L - n; i++) {
        // if(g == h && t.substr(i, n) == s) cout << i << ' ';                  // substr usage
        if(g == h && t.compare(i, n, s) == 0) cout << i << ' ';                 // compare usage
        // Rolling step
        if(i < L - n) h = (p * (h - t[i] * f % m + m) + t[i + n]) % m;
    }
}
void main_1() {
    cout << "Rabin-Karp algorithm\n----------------------------------------\n";
    rabin_karp("POSNTOIPOSN", "POSN");
    cout << '\n';
}

int main()
{
    main_1();
    return 0;
}
