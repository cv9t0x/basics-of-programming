#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


double fastpow(double num, int degree) {
    if(degree == 0){
        return 1;
    }
    else if(degree % 2 == 0) {
        double buf = fastpow(num, degree / 2);
        return buf * buf;
    }
    else{
        return num * fastpow(num, degree - 1);
    }
}

int main() {
    double num;
    int degree;

    double resultFastPow = 0;
    double resultPow = 0;

    while(true) {
        cout << "Input number and degree: ";
        cin >> num >> degree;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
        }

        else {
            break;
        }
    }

    clock_t start;
    clock_t end;

    for(int i = 0; i < 1000000; i++) {
        // fastpow
        start = clock();
        fastpow(num, degree);
        end = clock();
        double seconds = (double)(end-start);
        resultFastPow += seconds;

        // -------

        // pow
        start = clock();
        pow(num, degree);
        end = clock();
        seconds = (double)(end-start); 
        resultPow += seconds;
    }

    cout << "Recursion sort: " << (resultFastPow / 10) / CLOCKS_PER_SEC << endl;
    cout << "Cmath sort: " << (resultPow / 10) / CLOCKS_PER_SEC;
}