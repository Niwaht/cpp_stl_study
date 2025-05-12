#include <iostream>
#include "type_wrapper.h"
#include "pair.h"

int main()
{
    {
        type_wrapper<int> p1(10);
        type_wrapper<int> p2(20);

        my_pair::pair<type_wrapper<int>> i_pair(p1, p2);

        std::cout << "The max of " << p1 << " and " << p2 << " is " << i_pair.max() << '\n';
    }

    {
        double d1 = 100.4;
        double d2 = 200.8;

        my_pair::pair<double> d_pair(d1, d2);

        std::cout << "The max of " << d1 << " and " << d2 << " is " << d_pair.max() << '\n';
    }

    return 0;
}
