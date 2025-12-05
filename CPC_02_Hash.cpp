#include <iostream>
using namespace std;

/// Unordered maps
#include <unordered_map>
void main_1() {
    cout << "Unordered maps\n----------------------------------------\n";
    unordered_map<int, int> umap;
    umap[10]++;
    umap[11] = 10;
    umap[13] = 20;
    umap[11] = 2;
    umap.insert({14, 60});
    umap.insert({14, 80});

    cout << "Size = " << umap.size() << '\n';
    for(auto x : umap) cout << x.first << ' ' << x.second << '\n';
    if(umap.find(20) == umap.end()) cout << "20 is not in the hash table\n";

    umap.erase(11);                         // by key
    umap.erase(umap.find(10));              // by iterator
    cout << "After deletion:\n";
    for(auto x : umap) cout << x.first << ' ' << x.second << '\n';
}

/// Unordered sets
#include <unordered_set>
void main_2() {
    cout << "\nUnordered sets\n----------------------------------------\n";
    unordered_set<string> uset;

    uset.insert("hkoi");
    uset.insert("hash table");

    cout << "Size = " << uset.size() << '\n';
    for(auto x : uset) cout << x << '\n';
    if(uset.find("hkoi") != uset.end()) cout << "hkoi is in the hash table\n";

    uset.erase("hkoi");                     // by key
    uset.erase(uset.find("hash table"));    // by iterator
    cout << "After deletion:\n";
    for(auto x : uset) cout << x << '\n';
}

/// User-defined hash functions for unordered sets/maps
void main_3() {
    cout << "\nUser-defined h(x)'s for usets/umaps\n----------------------------------------\n";
    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };
    struct PointHash {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }

        // x = 3 -> h(x) = 3
        // y = 7 -> h(y) = 7
        // 7 << 1 -> 14 (00000111 -> 00001110)
        // 3 ^ 14 -> 13 (00000011 ^ 00001110 -> 00001101)
        /// Hashing purpose:
        // reduces chance of collision
        // distinguishes x and y values e.g. (3, 7) != (7, 3)
        // XOR is quick and efficient
    };

    unordered_map<Point, int, PointHash> mp;
    mp[{1, 2}] = 10;
    mp[{3, 4}] = 20;
    cout << "Value at (1, 2): " << mp[{1, 2}] << '\n';

    unordered_map<Point, string, PointHash> pointMap;
    pointMap[{1, 2}] = "Apple";
    pointMap[{5, 8}] = "Banana";
    cout << "Hash lookup {1, 2} = " << pointMap[{1, 2}] << '\n';
    cout << "Hash lookup {5, 8} = " << pointMap[{5, 8}] << '\n';
}

/// Floating point as hash table keys
#include <iomanip>
void main_4() {
    cout << "\nFloating point as hash table keys\n----------------------------------------\n";
    struct doubleHash {
        size_t operator()(double x) const {
            long long scaled = static_cast<long long>(x * 1000000);
            return hash<long long>()(scaled);
        }
    };

    unordered_map<double, string, doubleHash> mp;
    mp[0.3] = "Stored value for 0.3";
    double x = 0.1 + 0.2;
    cout << "Value of 0.3 -> " << mp[0.3] << '\n'
         << "Value of (0.1 + 0.2) -> " << mp[x] << '\n'
         << "Actual x = " << fixed << setprecision(25) << x << '\n';
}

/// Anti-hash tests
#include <chrono>
void main_5() {
    cout << "\nAnti-hash tests\n----------------------------------------\n";
    struct customHash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    unordered_map<uint64_t, int, customHash> mp;
    for(int i = 1; i <= 10; i++) mp[i] = i * 10;
    for(auto& p : mp) cout << p.first << ' ' << p.second << '\n';
}

int main()
{
    main_1(); main_2(); main_3(); main_4(); main_5();
    return 0;
}
