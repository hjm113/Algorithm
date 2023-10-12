#include <string>
#include <vector>
#include <iostream>
using namespace std;
int board[1500][1500];
vector<int> solution(int n) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    int cnt = 1;
    int out = 0;
    if(n == 1) {
        answer.push_back(1);
        return answer;
    }
    if(n == 2) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }
    while(1) {
        if(board[x+1][y] != 0) {
            break;
        }
        while(1) {
            if(x >= n || board[x+1][y] != 0) {
                break;
            }
            x++;
            board[x][y] = cnt;
            cnt++;
        }
        while(1) {
            if(y+2 > n || board[x][y+1] != 0) {
                break;
            }
            y++;
            board[x][y] = cnt;
            cnt++;
        }
        while(1) {
            if(board[x-1][y-1] != 0) {
                break;
            }
            x--;
            y--;
            board[x][y] = cnt;
            cnt++;
        }
    }
    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) {
                break;
            }
            answer.push_back(board[i][j]);
        }
        //cout << "\n";
    }
    return answer;
}