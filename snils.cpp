#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



bool checkNumber(long long number) {
    for (long long i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;
    return true;
}

bool checkSnilsID(long long number){
    
    int sum = 0;
    int index = 1;


    while(number > 0) {
        sum += (index * (number % 10));
        ++index;
        number /= 10;
    }

    if(sum % 101 == sum){
        return true;
    }

    return false;
}


int main() {
    
    ofstream out("output.txt");

    for (int i = 100000000; i < 1000000000; i++)
    {
        if ((checkNumber(i) == true) && (checkSnilsID(i) == true)){
            out << i << endl;
        }
    }

    out.close();

    return 0;
}