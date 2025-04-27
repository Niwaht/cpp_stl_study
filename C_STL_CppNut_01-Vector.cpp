#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    for (int i=1; i<=10; i++) {
        v.push_back(i);
    }

    cout << "Size: " << v.size();

    v.resize(7);

    cout << "\n After resize it become: " << v.size();

    if (v.empty() == false) {
        cout << "\n Not empty.";
    }
    else {
        cout << "\n Empty.";
    }

    cout << "\n Elements of vector: ";

    for (auto it=v.begin(); it!=v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
