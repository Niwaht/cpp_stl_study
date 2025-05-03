#include <iostream>
#include <vector>
using namespace std;

int getNumber() {
    return 5;
}

int add(int a, int b) {
    return a + b;
}

bool ascendingCompare(int a, int b) { return a < b; }
bool descendingCompare(int a, int b) { return a > b; }
void customSort(vector<int>& numbersVector, bool(*compareFuncPtr)(int, int)) {
    for(int startIndex = 0; startIndex < numbersVector.size(); startIndex++) {
        int bestIndex = startIndex;
        for(int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++) {
            if(compareFuncPtr(numbersVector[currentIndex], numbersVector[bestIndex]))
                bestIndex = currentIndex;
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}
void printNumbers(vector<int>& numbersVector) {
    for(int i=0; i<numbersVector.size(); i++)
        cout << numbersVector[i] << ' ';
}

int main()
{
    int(*funcPtr)() = getNumber;
    cout << funcPtr() << '\n';

    int(*funcPtr2)(int, int) = add;
    cout << add(2, 3) << '\n';
    cout << funcPtr2(3, 4) << '\n';

    vector<int> myNumbers = {2, 5, 1, 3, 6, 4};
    bool(*funcPtr3)(int, int) = descendingCompare;
    customSort(myNumbers, funcPtr3);
    printNumbers(myNumbers);

    return 0;
}
