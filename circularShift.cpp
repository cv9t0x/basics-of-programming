#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

void printResult(int n, int buf, int mask) {
	cout << endl << "Process: " << endl;
	cout << bitset<8>(n) << " --> "
		<< bitset<8>(n << 1) << " --> "
		<< bitset<8>((n << 1) + 1) << " --> "
		<< bitset<8>(pow(2, int(log2(buf)))) << " --> "
		<< bitset<8>(mask) << " --> "
		<< bitset<8>(mask) << " & " << bitset<8>(buf) << " --> "
		<< bitset<8>(mask & buf) << endl;

	cout << endl << "The last: " << (mask & buf) << endl;
}

int main() {
	int n;

	cout << "Input the number: ";
	cin >> n;

	int buf = (n << 1) + 1;
	int mask = 1 << int(log2(n) + 1);

	cout << (buf - mask);
}
