#include <iostream>
using namespace std;

class Major {
public:
    string name;

    Major() : name("Undeclared")
    {
        cout << "Major Constructor (Undeclared)" << '\n';
    }
    Major(string name) : name(name)
    {
        cout << "Major Constructor (" << name << ")" << '\n';
    }
};

class Minor {
public:
    string name;

    Minor(string name) : name(name) {}
};

class Student {
public:
    string name;
    int start_year;
    int grad_year;
    const string id;
    Major major;
    Minor &minor1;
    Minor minor2;

    Student(string name, int start_year, string major, Minor &minor) :
        name(name),
        start_year(start_year),
        grad_year(start_year + 4),
        id(name.append(to_string(start_year))),
        major(Major(major)),
        minor1(minor),
        minor2(Minor("Physics"))
    {
        cout << "Student Object Constructed!" << '\n';
    }
};

class MatureStudent : Student {
public:
    int age;

    MatureStudent(int age, string name, int start_year, string major, Minor &minor) :
        Student(name, start_year, major, minor),
        age(age)
    {}
};

int main()
{
    Minor minor("Economics");
    Student s1("John", 2041, "Computer Science", minor);
    cout << "Name: " << s1.name << '\n'
         << "Start Year: " << s1.start_year << '\n'
         << "Grad Year: " << s1.grad_year << '\n'
         << "ID: " << s1.id << '\n'
         << "Major: " << s1.major.name << '\n'
         << "Minor1: " << s1.minor1.name << '\n'
         << "Minor2: " << s1.minor2.name << '\n';

    return 0;
}
