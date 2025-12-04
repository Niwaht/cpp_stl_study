#include <iostream>
using namespace std;

/// Unordered maps
#include <unordered_map>
void main_1() {
    cout << "Unordered maps----------------------------------------\n";
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

    umap.erase(11);             // by key
    umap.erase(umap.find(10));  // by iterator
    cout << "After deletion:\n";
    for(auto x : umap) cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    main_1();
    return 0;
}
