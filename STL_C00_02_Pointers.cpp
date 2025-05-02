#include <iostream>
using namespace std;

void printNumber(int* numberPtr) {
    cout << *numberPtr << '\n';
}

void printLetter(char* charPtr) {
    cout << *charPtr << '\n';
}

void print(void* Ptr, char type) {
    switch (type) {
        case 'i': cout << *((int*)Ptr) << '\n'; break;
        case 'c': cout << *((char*)Ptr) << '\n'; break;
    }
}

int getMin(int numbers[], int size) {
    int min = numbers[0];
    for(int i=1; i<size; i++) {
        if (numbers[i] < min) min = numbers[i];
    }
    return min;
}

int getMax(int numbers[], int size) {
    int max = numbers[0];
    for(int i=1; i<size; i++) {
        if (numbers[i] > max) max = numbers[i];
    }
    return max;
}

void getMinAndMax(int numbers[], int size, int* min, int* max) {
    for(int i=1; i<size; i++) {
        if (numbers[i] > *max) *max = numbers[i];
        if (numbers[i] < *min) *min = numbers[i];
    }
}

int main()
{
    int n = 5;
    cout << n << '\n';
    cout << &n << '\n';
    int* ptr = &n;
    cout << ptr << '\n';
    cout << *ptr << '\n';
    *ptr = 10;
    cout << *ptr << '\n';
    cout << n << '\n';

    int v;
    int* ptr2 = &v;
    *ptr2 = 7;
    cout << "v = " << v << '\n';

    int number = 5;
    char letter = 'a';
    printNumber(&number);
    printLetter(&letter);
    print(&number, 'i');
    print(&letter, 'c');

    /* int luckyNumbers[5] = {2, 3, 5, 7, 9};
    cout << luckyNumbers << '\n';
    cout << &luckyNumbers[0] << '\n';
    cout << luckyNumbers[2] << '\n';
    cout << *(luckyNumbers + 2) << '\n';
    for (int i = 0; i < 5; i++) {
        cout << "Number: ";
        cin >> luckyNumbers[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << *(luckyNumbers + i) << ' ';
    }
    cout << '\n'; */

    int numbers[5] = {5, 4, -2, 29, 6};
    // cout << "Minimum number in numbers[] is " << getMin(numbers, 5) << '\n';
    // cout << "Maximum number in numbers[] is " << getMax(numbers, 5) << '\n';
    int min = numbers[0], max = numbers[0];
    getMinAndMax(numbers, 5, &min, &max);
    cout << "Minimum number in numbers[] is " << min << '\n';
    cout << "Maximum number in numbers[] is " << max << '\n';

    int size;
    cout << "Size: ";
    cin >> size;
    // int myArray[size];
    int* myArray = new int[size];
    for(int i=0; i<size; i++) {
        cout << "Array[" << i << "]: ";
        cin >> myArray[i];
    }
    for(int i=0; i<size; i++) {
        // cout << myArray[i] << ' ';
        cout << *(myArray + i) << ' ';
    }
    delete[] myArray;
    myArray = NULL;

    cout << '\n';
    return 0;
}
