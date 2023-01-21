#include <bits/stdc++.h>
using namespace std;


// #include <windows.h>

void print(char s){
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(s == 'o' || s == 'O'){
        // SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << s;
    }
    else if(s == 'x' || s == 'X'){
        // SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        cout << s;
    }
    else 
        cout << s;
    // SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void display_update (char n[8][8]){
    system ("cls"); //CLS
    for(int i=0;i<8;i++)
    cout << "    " << i << "   ";
    cout << endl;
    for(int i=0;i<8;i++){
        cout << "  #################################################################" << endl;
        cout << "  #       #       #       #       #       #       #       #       #" << endl;
        cout << i;
        for(int j=0;j<8;j++){ 
            cout <<  " #   ";
            print(n[i][j]);
            cout << "  ";
        }
        cout << " #" << " " << endl;
        cout << "  #       #       #       #       #       #       #       #       #" << endl;
    }
    
            cout << " #################################################################" << endl;
}



void update (char n[8][8], bool turn) {
    int x1, y1, x2, y2;
    cout << "please enter your next move :\n";
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 < 0 || x1 >= 8 || x2 < 0 || x2 >= 8 || y1 < 0 || y1 >= 8 || y2 < 0 || y2 >= 8) {
        cout << "Not a valid move :\n";
        update (n, turn);
    }

    if (turn == 1) {
        // 'o' 'O'
        if (n[x2][y2] == 'o' || n[x2][y2] == 'O') {
            cout << "Not a valid move :\n";
                update (n, turn);
        }
        else if (n[x1][y1] == 'o') {
            if (x2 != x1+1 || (y2 != y1-1 && y2 != y1+1)) {
                cout << "Not a valid move :\n";
                update (n, turn);
            }
            
        }
        else if (n[x1][y1] == 'O'){
            if ((y2 != y1+1 && y2 != y1+1) || (x2 != x1-1 && x2 != x1+1)) {
                cout << "Not a valid move :\n";
                update (n, turn);
            }
            
        }
        else {
            cout << "Not a valid move :\n";
            update (n, turn);
        }
    }
    else {
        // 'x' 'X' 
         if (n[x2][y2] == 'x' || n[x2][y2] == 'X') {
            cout << "Not a valid move :\n";
                update (n, turn);
        }
        else if (n[x1][y1] == 'x') {
            if (x2 != x1-1 || (y2 != y1-1 && y2 != y1+1)) {
                cout << "Not a valid move :\n";
                update (n, turn);
            }
        }
        else if (n[x1][y1] == 'X'){
            if ((y2 != y1-1 && y2 != y1+1) || (x2 != x1-1 && x2 != x1+1)) {
                cout << "Not a valid move :\n";
                update (n, turn);
            }

        }
        else {
            cout << "Not a valid move :\n";
            update (n, turn);
        }
    }
}

bool check (char n[8][8]) {
    //cnt1 for 'o' 'O' 
    //cnt2 for 'x' 'X'
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (n[i][j] == 'o' || n[i][j] == 'O')
                cnt1++;
            if (n[i][j] == 'x' || n[i][j] == 'X')
                cnt2++;
        }
    }
    if (cnt1 == 0) {
        cout << "The second player wins";
        return false;
    }
    if (cnt2 == 0) {
        cout << "The first player wins";
        return false;
    }
    return true;
}

int main(){
    char n[8][8]; // board
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int f = (8 * i) + j;
            if (f < 24 && (i+j)%2 == 0)
                n[i][j] = 'o';
            else if (f >= 40 && (i+j)%2 == 0)
                n[i][j] = 'x';
            else 
                n[i][j] = ' ';
        }
    }
    bool turn = 1;
    //turn == 1 => 'o'
    //turn == 0 => 'x'
    while (check (n)) {
        display_update (n);
        update (n, turn);
        turn = 1 - turn;
    }
    
} 
