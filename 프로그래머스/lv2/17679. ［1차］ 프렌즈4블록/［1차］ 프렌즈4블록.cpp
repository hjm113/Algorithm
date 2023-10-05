#include <string>
#include <vector>
#include <iostream>
using namespace std;
int tmp[35][35];
int solution(int n, int m, vector<string> board) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    while(1) {
        int out = 0;
        int vis[35][35] = {};
        for(int i = 0; i <= n-2; i++) {
            for(int j = 0; j <= m-2; j++) {
                if(board[i][j] == '1') {
                    continue;
                }
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]) {
                    out = 1;
                    tmp[i][j] = '1';
                    tmp[i][j+1] = '1';
                    tmp[i+1][j] = '1';
                    tmp[i+1][j+1] = '1';
                    if(vis[i][j] == 0) {
                        answer++;
                    }
                    if(vis[i][j+1] == 0) {
                        answer++;
                    }
                    if(vis[i+1][j] == 0) {
                        answer++;
                    }
                    if(vis[i+1][j+1] == 0) {
                        answer++;
                    }
                    vis[i][j] = 1;
                    vis[i][j+1] = 1;
                    vis[i+1][j] = 1;
                    vis[i+1][j+1] = 1;
                }
            }
        }
        if(out == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = tmp[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            int idx = 0;
            int cnt = 0;
            for(int j = n-1; j >= 0; j--) {
                if(cnt == 0 && board[j][i] == '1') {
                    idx = j;
                    cnt++;
                    //cout << idx << "\n";
                }
                if(cnt == 1 && board[j][i] != '1') {
                    board[idx][i] = board[j][i];
                    board[j][i] = '1';
                    idx--;
                }
                
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        /*
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
    }
    return answer;
}