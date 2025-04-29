#include <iostream>

using namespace std;

class functionObj
{
    public:
    int operator()(int x, int y)
    {
        return x*y;
    }
};


int main()
{
    functionObj fo;

    int mult = fo(4,7);

    cout << "Multiplication of x and y is: " << mult << endl;


    return 0;
}
