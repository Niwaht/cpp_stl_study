#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    /* non-pointer
    pair<int, int> p = make_pair(10,20);

    cout << p.first << "-" << p.second << endl;

    */


    unordered_map<int, int> mp;

    mp[4]=400;
    mp[3]=300;

    mp.insert(make_pair(4,400));
    mp.insert(make_pair(10,700));
    mp.insert(make_pair(3,300));
    mp.insert(make_pair(10,900));
    mp.insert(make_pair(10,1000));


    mp[10]=700;

    //iterate
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "-----" << it->second << endl;
    }

    return 0;
}
