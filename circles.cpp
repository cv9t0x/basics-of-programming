#include <iostream>
using namespace std;



int main() {

    int rows;
    int cols;
    int border = 1;
    int number = 2;
    
    bool check = true;

    int k;
    int m;

    cout << "Input the number of rows for the Matrix: ";
    cin >> rows;
    cout << "Input the number of cols for the Matrix: ";
    cin >> cols;

    cout << "Input k: ";
    cin >> k;
    cout << "Input m: ";
    cin >> m;
    
    

    if (rows >= k && cols >= m && rows >=1 && cols >=1) {
        
        if(k > 1){
        k--;
        }
        if (m > 1){
            m--;
        }

        if(rows == 1 && cols == 1 && k == 1 && m == 1) {
            cout << 1;
        }
        else if(rows == 1 && cols == 1 && (k < 1 || m < 1)) {
            cout << "Invalid data";
        }
        else {
            int** arr = new int* [rows];

            for (int i = 0; i < rows; i++)
            {
                arr[i] = new int [cols];
            }


            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = 0;
                }
            }
            

            while(check) {
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        if (i == k - border || j == m - border || i == k + border || j == m + border) {
                            arr[i][j] = number;
                        }    
                    }
                }
                arr[k][m] = 1;
                border++;
                number++;

                if(border == rows) {
                    check = false;
                }

            }
            

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << arr[i][j] << "\t";
                }
                cout << endl;
            }

            for (int i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }

            delete[] arr;
        }

    }
    else{
        cout << "Invalid data" << endl;
    }


    
    

    return 0;
}