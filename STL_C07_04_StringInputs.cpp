#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter two numbers:\n";
    int x;
    double y;
    if(cin >> x >> y) {
            cout << "You entered: " << x << " and " << y << '\n';
    } else {
        cout << "Oh no, that did not go well!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "now please enter some comma separated names:\n> ";
    for(string s; getline(cin >> ws, s, ',');) {
        if(s.empty()) break;
        cout << "name: \"" << s << "\"\n";
    }

    return 0;
}
