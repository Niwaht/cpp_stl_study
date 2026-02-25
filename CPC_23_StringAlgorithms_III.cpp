#include <iostream>
#include <string>
#include <string_view>
using namespace std;

/// Prefix functions
#include <vector>
struct periodInfo { int period, maxBorder; };               // Minimum period, Maximum border
periodInfo analyze(const string& s) {
    int n = static_cast<int>(s.size()), j = 0;
    if(n == 0) return {0, 0};
    vector<int> p(n);                                       // Prefix function table
    for(int i = 1; i < n; p[i++] = j) {
        while(j > 0 && s[i] != s[j]) j = p[j - 1];          // Back to best (B-2-B)
        if(s[i] == s[j]) j++;                               // +1 limit (+1)
    }
    int b = p[n - 1];                                       // Maximum border
    int cand = n - b;                                       // Candidate period
    return {(cand > 0 && n % cand == 0) ? cand : n, b};     // Strict period
}
int main_1() {
    cout << "Prefix functions\n----------------------------------------\n";
    string s = "AB AB AB ";
    // if(!getline(cin, s) || s.empty()) return 0;
    auto [k, b] = analyze(s);
    int n = static_cast<int>(s.size());
    string_view v(s);                                       // Zero-copy
    cout << "Text: \"" << s << "\"\n---\n"
         << "Max Border: " << b << " (" << v.substr(0, b) << ")\n"
         << "Period: " << k << '\n'
         << "Compression: " << v.substr(0, k) << " x " << (n / k) << '\n';
    return 0;
}

/// Knuth-Morris-Pratt algorithm
vector<int> compute_pi(const string& P) {
    size_t m = P.length();
    if(m == 0) return {};
    vector<int> pi(m, 0);
    for(size_t i = 1, j = 0; i < m; i++) {
        while(j > 0 && P[i] != P[j]) j = static_cast<size_t>(pi[j - 1]);
        if(P[i] == P[j]) j++;
        pi[i] = static_cast<int>(j);
    }
    return pi;
}
vector<size_t> kmp(const string& T, const string& P) {
    size_t n = T.length(), m = P.length();
    if(m == 0 || n == 0) return {};
    vector<size_t> res;
    vector<int> pi = compute_pi(P);
    for(size_t i = 0, j = 0; i < n; i++) {
        while(j > 0 && T[i] != P[j]) j = static_cast<size_t>(pi[j - 1]);
        if(T[i] == P[j]) j++;
        if(j == m) { res.push_back(i - m + 1); j = static_cast<size_t>(pi[j - 1]); }
    }
    return res;
}
int main_2() {
    cout << "\nKnuth-Morris-Pratt algorithm\n----------------------------------------\n";
    string T = "ABABCABAC", P = "ABA";
    // cout << "Enter Text (T) and Pattern (P): "; cin >> T >> P;
    vector<size_t> results = kmp(T, P);
    if(results.empty()) cout << ">>> Pattern not found\n";
    else for(size_t idx : results) cout << ">>> Found Pattern at index: " << idx << '\n';
    return 0;
}

/// Knuth-Morris-Pratt algorithm: concatenation approach
const char es_char = '#';
vector<size_t> concat_pi(const string& s) {
    size_t n = s.size(), j = 0;
    vector<size_t> pi(n, 0);
    for(size_t i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];         // B-2-B
        if(s[i] == s[j]) j++;                               // +1 limit
        pi[i] = j;
    }
    return pi;
}
int main_3() {
    cout << "\nKMP algorithm: concatenation approach\n----------------------------------------\n";
    string T = "ABABCABAC", P = "ABA";
    // cout << "Enter T and P: "; cin >> T >> P;
    if(P.empty()) return cout << "Pattern is empty\n", 0;
    string S;
    S.reserve(P.size() + T.size() + 1);
    S.append(P).append(1, es_char).append(T);
    auto pi = concat_pi(S); size_t m = P.size(); bool found = false;
    for(size_t i = m + 1; i < S.size(); i++) if(pi[i] == m) { cout << ">>> Found at index: " << i - 2 * m << '\n'; found = true; }
    if(!found) cout << ">>> Not found\n";
    return 0;
}

/// Knuth-Morris-Pratt algorithm: optimized approach
vector<int> build_next(const string& P) {
    int m = P.size(), i = 0, j = -1; vector<int> n(m); n[0] = -1;
    while(i < m - 1)
        if(j < 0 || P[i] == P[j]) {
            i++; j++;
            if(P[i] == P[j]) n[i] = n[j];                   // Skip
            else n[i] = j;                                  // Select
        } else j = n[j];
    return n;
}
vector<int> opt_search(const string& T, const string& P) {
    int n = T.size(), m = P.size(), i = 0, j = 0;
    vector<int> res, next = build_next(P);
    while(i < n) {
        if(j < 0 || T[i] == P[j]) i++, j++;
        else j = next[j];
        if(j == m) {
            res.push_back(i - m);
            j = (m > 0) ? next[m - 1] + 1 : 0;
            if(j > 0 && P[m - 1] != P[j - 1]) j = 0;
        }
    }
    return res;
}
int main_4() {
    cout << "\nKMP algorithm: optimized approach\n----------------------------------------\n";
    string t = "AABCABCABCBAABC", p = "AB";
    // cout << "Text: ";    getline(cin, t);
    // cout << "Pattern: "; getline(cin, p);
    if(t == "" || p == "") return cout << "Input is empty\n", 1;
    vector<int> r = opt_search(t, p);
    if(r.empty()) cout << ">>> Not found\n";
    else for(int x : r) cout << ">>> Found at index: " << x << '\n';
    return 0;
}

int main()
{
    main_1(); main_2(); main_3(); main_4();
    return 0;
}
