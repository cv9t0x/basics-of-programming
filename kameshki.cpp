#include <iostream>
using namespace std;


bool checkInput(int number){
    if(number > 10){
        return false;
    }
    return true;
}

bool checkMove(int number, int currentNumber){
    if(number == 1){
        if(currentNumber == number+1)
            return false;
    }
    else if (number > 1) {
        if(currentNumber == number+1 || currentNumber == number-1){
            return false;
        }
    }
    return true;
}

bool gameCheck(int number){
    if(number <= 10){
        return false;
    }
    return true;
}

bool game(int number) {
    if(number <= 0){
        return false;
    }
    return true;
}

int main(){

    int n;
    int move;
    int userMove;
    int count = 0;

    cout << "Input the number of stones in a pile: ";
    cin >> n;

    while(checkInput(n)){ // Проверяем ввод пользователя 
        cout << "Input the number of stones in a pile: ";
        cin >> n;
        checkInput(n);
    }

    while(gameCheck(n)){ // Игра до 10 камешков
        move = 1;

        cout << "My turn: " << move << "\nLeft: " << n-move << endl;

        n-=move;

        cout << "Your turn: ";
        cin >> userMove;

        while (checkMove(move, userMove))
        {
            cout << "Your turn: ";
            cin >> userMove;
            checkMove(move, userMove);
        }
        
        cout << "Left: " << n-userMove << "\n";

        n -= userMove;
    }


    if(n == 10) { // Выиграшная стратегия, когда камешков осталось 10
        while (game(n)){
            move = 1;

            cout << "My turn: " << move << "\nLeft: " << n-move << endl;

            n-=move;

            if(n <= 0) {
                cout << "You lost :(";
                break;
            }

            cout << "Your turn: ";
            cin >> userMove;

            while (checkMove(move, userMove))
            {
                cout << "Your turn: ";
                cin >> userMove;
                checkMove(move, userMove);
            }
            
            cout << "Left: " << n-userMove << "\n";

            n -= userMove;
        }
    }

    if(n == 9) { // Выиграшная стратегия, когда камешков осталось 9
        while (game(n)){
            if (count == 2){
                move = 3;
            }
            else {
                move = 1;
            }

            cout << "My turn: " << move << "\nLeft: " << n-move << endl;

            n-=move;

            if(n <= 0) {
                cout << "You lost :(";
                break;
            }

            cout << "Your turn: ";
            cin >> userMove;

            while (checkMove(move, userMove))
            {
                cout << "Your turn: ";
                cin >> userMove;
                checkMove(move, userMove);
            }
            
            cout << "Left: " << n-userMove << "\n";

            n -= userMove;

            ++count;
        }
    }

    if(n == 8) { // Выиграшная стратегия, когда камешков осталось 8
        while (game(n)){
            if (count == 2){
                move = 2;
            }
            else {
                move = 1;
            }


            cout << "My turn: " << move << "\nLeft: " << n-move << endl;

            n-=move;

            if(n <= 0) {
                cout << "You lost :(";
                break;
            }

            cout << "Your turn: ";
            cin >> userMove;

            while (checkMove(move, userMove))
            {
                cout << "Your turn: ";
                cin >> userMove;
                checkMove(move, userMove);
            }
            
            cout << "Left: " << n-userMove << "\n";

            n -= userMove;

            ++count;
        }
    }

    return 0;
}