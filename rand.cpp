#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;



int* genUnicPosled(int n, int b, int e) {
    int* temp, * arr;
    temp = new int[e - b + 1];
    arr = new int[n];
    for (int i = b; i <= e; i++) {
        
        temp[i - b] = i;
    }
    int emax = e - b + 1;
    for (int i = 0; i < n; i++) {
        int r = rand() % (emax);
        arr[i] = temp[r];
        temp[r] = temp[emax - 1];
        emax--;
    }
    return arr;
}

int* sort(int* arr, int size) {
    int buf;
    for (int i = size; i > 1; i--) {
        bool flag = false;
        int sh = 0;
        for (int j = 0; j < i / 2;) {
            int largest = j, left = 2 * j + 1, right = j * 2 + 2;
            if (arr[left] > arr[largest]) {
                buf = arr[left];
                arr[left] = arr[largest];
                arr[largest] = buf;
                flag = 1;
            }
            if (right < i) {
                if (arr[right] > arr[largest]) {
                    buf = arr[right];
                    arr[right] = arr[largest];
                    arr[largest] = buf;
                    flag = true;
                }
            }
            if (flag && j > 0) {
                j = (j - 1) / 2;
                sh++;
                flag = 0;
            }
            else {
                j = j + 1 + sh;
                sh = 0;
            }
        }
        
        buf = arr[i - 1];
        arr[i - 1] = arr[0];
        arr[0] = buf;
        cout << i << "\n";
    }
    return(arr);
}

int main() {
    int k = 10000;
    double sum = 0;

    for(int i = 0; i < 10; i++) {
        int start = clock();
        int* arr = genUnicPosled(k, 0,k);
        int* arr1 = sort(arr, k);
        int end = clock();

        double seconds = (double)(end - start);
        sum += seconds;
    }

    cout << (sum / 10) / CLOCKS_PER_SEC;
     
}