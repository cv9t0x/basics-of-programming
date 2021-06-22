#include <iostream>
using namespace std;


int factorial(int num) {
    int buf;
    if(num == 0) {
        return 1;
    }
    else {
        buf = num * factorial(num-1);
        if(buf > INT_MAX) {
            return 0;
        }
        else  return num * factorial(num-1); 
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

    if(factorial(num) == 0) {
        cout << "Error";
    }
    else cout << "Factorial: " << factorial(num);
}