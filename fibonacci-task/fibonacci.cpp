#include <iostream>
#include <math.h>

using namespace std;

bool checkInput(int number) {
    if(number > 0) {
        return true;
    }

    return false;
}

unsigned long long* fibonacci(int size) {

    unsigned long long *arr = new unsigned long long[size];

    for(int i = 0; i < size; i++) {
        arr[i] = trunc((pow((1 + sqrt(5)) / 2, i) - pow((1 - sqrt(5)) / 2, i)) / sqrt(5));

        if(ULLONG_MAX - arr[i] < arr[i-1]) {
            return arr;
        }
    }

    return arr;
}       


int main() {
    int number;
    int count;
    cout << "Input the number of fibonacci: ";
    cin >> number;

    if(checkInput) {
        unsigned long long *newArr = fibonacci(number);

        for(int i = 0; i < number; i++) {
            if(newArr[i] != 0 && i != 0) {
                cout << newArr[i] << " ";
            } else {
                count++;
            }
        }

        cout << "\n" << "Correct numbers: " << number - count;
        cout << "\n" << "Incorrect numbers: " << count;

        delete [] newArr;
    } else {
        cout << "Incorrect input";
    }


    return 0;
}

