#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename ...Ts>
auto concat(T t, Ts ...ts)
{
    if constexpr (sizeof...(ts) > 0) {
        return [=](auto ...parameters) {
            return t(concat(ts...)(parameters...));
        };
    } else {
        return t;
    }
}

int main()
{
    auto twice  ([](int i){ return i*2; });
    auto thrice ([](int i){ return i*3; });
    auto combined { concat(twice, thrice, plus<int>{}) };

    cout << combined(2, 3) << '\n';

    return 0;
}
