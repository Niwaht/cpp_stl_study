#include <iostream>
#include <memory>                                                   /// For creating smart pointers
using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor invoked" << '\n'; }
    ~MyClass() { cout << "Destructor invoked" << '\n'; }
};

int main()
{
    unique_ptr<int> unPtr1 = make_unique<int>(25);                  /// Smart pointers I: Unique pointers
    cout << unPtr1.get() << '\n';

    unique_ptr<int> unPtr2 = move(unPtr1);                          /// Moving ownership of address
    cout << unPtr2.get() << '\n';
    cout << *unPtr2 << '\n';
    // cout << *unPtr1 << '\n';                                     // Already becomes nullptr

    unique_ptr<MyClass> unPtr3 = make_unique<MyClass>();            // Invoking object constructor/destructor

    {
        shared_ptr<MyClass> shPtr1 = make_shared<MyClass>();        /// Smart pointers II: Shared pointers
        cout << "Shared count: " << shPtr1.use_count() << '\n';     // Counts the number of owners of this address

        {
            shared_ptr<MyClass> shPtr2 = shPtr1;                    /// Sharing ownership of address (in scope)
            cout << "Shared count: " << shPtr1.use_count() << '\n';
        }

        cout << "Shared count: " << shPtr1.use_count() << '\n';
    }

    weak_ptr<int> wePtr1;                                           /// Smart pointers III: Weak pointers
    {
        shared_ptr<int> shPtr1 = make_shared<int>(25);
        wePtr1 = shPtr1;                                            // Assigning data
    }

    system("pause>nul");
    return 0;
}
