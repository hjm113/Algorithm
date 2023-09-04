#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<string> board) {
    int answer = 1;
    int cnto = 0;
    int cntx = 0;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].length(); j++) {
            if(board[i][j] == 'O') {
                cnto++;
            }
            if(board[i][j] == 'X') {
                cntx++;
            }
        }
    }
    if(cnto < cntx || cnto-1 > cntx) {
        answer = 0;
        return answer;
    }
    int chko = 0;
    /*
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
        chko = 1;
    }
    */
    int chk0 = 0;
    int chkX = 0;
    for(int i = 0; i < 3; i++) {
        int chk = 0;
        int chk1 = 0;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'O') {
                chk = 1;
            }
            if(board[i][j] != 'X') {
                chk1 = 1;
            }
        }
        if(chk == 0) {
            chk0 = 1;
        }
        if(chk1 == 0) {
            chkX = 1;
        }
    }
    for(int i = 0; i < 3; i++) {
        int chk = 0;
        int chk1 = 0;
        for(int j = 0; j < 3; j++) {
            if(board[j][i] != 'O') {
                chk = 1;
            }
            if(board[j][i] != 'X') {
                chk1 = 1;
            }
        }
        if(chk == 0) {
            chk0 = 1;
        }
        if(chk1 == 0) {
            chkX = 1;
        }
    }
    int check0 = 0;
    int checkX = 0;
    for(int i = 0; i < 3; i++) {
        if(board[i][i] != 'O') {
            check0 = 1;
        }
        if(board[i][i] != 'X') {
            checkX = 1;
        }
    }
    if(check0 == 0) {
        chk0 = 1;
    } 
    if(checkX == 0) {
        chkX = 1;
    } 
    check0 = 0;
    checkX = 0;
    for(int i = 0; i < 3; i++) {
        if(board[i][2-i] != 'O') {
            check0 = 1;
        }
        if(board[i][2-i] != 'X') {
            checkX = 1;
        }
    }
    if(check0 == 0) {
        chk0 = 1;
    }
    if(checkX == 0) {
        chkX = 1;
    }
    if(chk0 == 1) {
        if(cntx >= cnto) {
            answer = 0;
            return answer;
        }
    }
    if(chkX == 1) {
        if(cnto > cntx) {
            answer = 0;
            return answer;
        }
    }
    //cout << chk0 << "\n";
    return answer;
}