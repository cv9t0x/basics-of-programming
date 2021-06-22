#include <iostream>
#include <math.h> 
using namespace std;


bool checkTriangle(int xa, int ya, int xb, int yb,  int xc, int yc) 
{   
    double AB = sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
    double BC = sqrt(pow((xb - xc), 2) + pow((yb - yc), 2));
    double AC = sqrt(pow((xa - xc), 2) + pow((ya - yc), 2)); 

    if ((AB + BC > AC) || (AB + AC > BC) || (AC + BC > AB))
    {   
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int xa, xb, xc, ya, yb, yc;
    int xm, ym;

    int Def1 = (xm - xa) * (yb - ya) - (ym - ya) * (xb - xa);
    int Def2 = (xm - xb) * (yc - yb) - (ym - yb) * (xc - xb);
    int Def3 = (xm - xc) * (ya - yc) - (ym - yc) * (xa - xc);


    cout << "Input the coordinates of the fitst apex of a triangle: ";
    cin >> xa >> ya;
    cout << endl;

    cout << "Input the coordinates of the second apex of a triangle: ";
    cin >> xb >> yb;
    cout << endl;

    cout << "Input the coordinates of the third apex of a triangle: ";
    cin >> xc >> yc;
    cout << endl;

    cout << "Input the coordinates of the apex: ";
    cin >> xm >> ym;
    cout << endl;

    if (checkTriangle(xa, xb, xc, ya, yb, yc) == true) {
        
        if(Def1 >= 0 && Def2 >= 0 && Def3 >= 0){
            cout << "Apex in a triangle!" << "\n";
        }
        else 
            cout << "Apex out of a triangle :c" << "\n";

    }
    else 
        cout << "This triangle is impossible";

    return 0;
}