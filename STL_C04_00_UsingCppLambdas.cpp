#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Thing {
    // Member variables
public:
    // various public member functions
    void save (ostream& os) const;
};

class Savem {
    ostream& output_stream;
public:
    Savem(ostream& output_stream_)
        : output_stream(output_stream_)
    {}
    void operator()(Thing * ptr) const {
        ptr->save(output_stream);
    }
};

class Gizmo {
    list<int> ints;
    int criterion;
    int count;
public:
    // Returns the number of ints greater than criterion
    int get_count_over_criterion();
};

/* int Gizmo::get_count_over_criterion() {
    count = 0;
    for(int i : ints)
        if(i > criterion) count++;
    return count;
} */

int Gizmo::get_count_over_criterion() {
    count = 0;
    for_each(ints.begin(), ints.end(),
             [/*&count, criterion*/this](int i){ if(i > criterion) count++; });
    return count;
}

/*
void print_it(int i)
{
    cout << ":" << i << ":\n";
}
*/

int main()
{
    list int_list {1, 2, 5, 4, 3, 6, 8, 7, 9};

    // for_each(int_list.begin(), int_list.end(), print_it);
    /// Use lambdas instead:
    for_each(int_list.begin(), int_list.end(), [](int i){ cout << ":" << i << ":\n"; });
    cout << '\n';

    [](int i){ cout << ":" << i << ":\n"; }(42);        /// Lambda call right after declaration

    /// Keeping lambdas as function objects
    auto emote = [](int i){ cout << ":" << i << ":\n"; };
    emote(43);
    cout << '\n';

    // Possible forms of lambdas:
    [](){ cout << "Hello from trivial lambda!" << '\n'; }();

    if([](int i, int j){ return 2*i == j; }(12, 24)) cout << "It's true!\n";
    else cout << "It's false!\n";

    cout << "This lambda returns " << [](int x, int y) -> int {
        if(x > 5) return x + y;
        else if (y < 2) return x - y;
        else return x * y;
    }(4, 3) << '\n';

    cout << "This lambda returns " << [](double x, double y) -> int {
        return x + y;
    }(3.14, 2.7) << '\n';

    {
        int int_var = 42;
        double dbl_var = 3.14;
        [int_var, dbl_var]()
        {
            int i = 7;
            cout << int_var << ' ' << dbl_var << ' ' << i << '\n';
        }();
    }

    int int_var = 52;
    auto lambda_func = [&int_var]()
        { cout << "This lambda has a copy of int_var when created: " << int_var << '\n'; };
    lambda_func();
    for(int i=0; i<3; i++) {
        int_var++;
        lambda_func();
    }

    list<Thing *> thing_ptrs;
    // ofstream out_file("output.txt");
    // for(auto it = thing_ptrs.begin(); it!=thing_ptrs.end(); ++it) (*it)->save(out_file);

    // for_each(thing_ptrs.begin(), thing_ptrs.end(), Savem(out_file));
    // for_each(thing_ptrs.begin(), thing_ptrs.end(),
    //          [out_file](Thing * ptr){ ptr->save(out_file); });

    cout << '\n';
    return 0;
}
