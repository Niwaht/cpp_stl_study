#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int d = 7, e = 5;
    vector<int> v {2, 3, 7, 14, 23};

    for_each(v.begin(), v.end(), [&](int x){
        if(x%d == 0)
            cout << x << " is divisible by " << d << '\n';
        else
            cout << x << " is not divisible by " << d << '\n';
        d = 10;
        e = 19;
        cout << "d was changed to " << d;
    });

    system("pause>null");
    return 0;
}
