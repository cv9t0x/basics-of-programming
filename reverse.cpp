#include <iostream>
#include <cmath>

using namespace std;

char alphabet[4] = {'A', 'B', 'C', 'D'};

bool checkInput(int number) {
    if (number > 1) {
        return false;
    }
    return true;
}

int divide(int number){
    int sum = 0;
    int i = 0;

    while (number > 0) {
		sum += ((number % 4) * (pow(10, i)));
        ++i;
		number /= 4;
	}

    return sum;
}

void fillMatrix(int number){

    string buffer;

    while (number > 0) {
		if (number % 10 != 0) {
			buffer += (alphabet[number % 10 - 1]);
		}
		else {
			buffer += "D";
            number-=10;
		}

		number /= 10;
	}

    for (int i = buffer.length()-1; i >= 0; --i)
    {
        cout << buffer[i];
    }
    
}



int main()
{
	int n = 0;

    while(checkInput(n)){
        cout << "Input the number: ";
        cin >> n;
        checkInput(n);
    }

    fillMatrix(divide(n));


    return 0;
}