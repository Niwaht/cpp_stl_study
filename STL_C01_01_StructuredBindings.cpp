#include <iostream>
#include <vector>
using namespace std;

struct employee {
    unsigned id;
    string name;
    string role;
    unsigned salary;
};

int main()
{
    vector<employee> employees {{01, "Frank", "Officer", 15000},
                                {04, "James", "Manager", 55000},
                                {07, "Alan", "President", 200000},
                                {10, "Chris", "CEO", 1000000}}; // Either initialized or inputted
    for(const auto &[id, name, role, salary] : employees) {
        cout << "Name: " << name << " Role: " << role << " Salary: " << salary << endl;
    }

    return 0;
}
