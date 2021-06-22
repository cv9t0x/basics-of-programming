#include <iostream>
using namespace std;

int numbers(int num) {
    if(num < 10) {
        return num;
    }
    else {
        return num % 10 + numbers(num / 10);
    }
}

int main() {
    int num;

    while(true) {
        cout << "Input number: ";
        cin >> num;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
        }

        else {
            break;
        }
    }

    cout << "Sum: " << numbers(num);
}