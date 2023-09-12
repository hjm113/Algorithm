#include <string>
#include <vector>
#include <iostream>
using namespace std;
int f[11][11];
int board[4][4] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ndx[4] = {1,-1,1,-1};
int ndy[4] = {1,-1,-1,1};
int mx = 200000000;
int dp[100005][10][10];
int c2i(char c) {
    return c - '0';
}
int solution(string numbers) {
    int answer = 0;
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            f[i][j] = mx;
        }
    }
    for(int i = 0; i < 10; i++) {
        f[i][i] = 1;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == -1) {
                continue;
            }
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || ny < 0 || nx >= 4 || ny >= 3) {
                    continue;
                }
                f[board[i][j]][board[nx][ny]] = 2;
            }
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + ndx[dir];
                int ny = j + ndy[dir];
                if(nx < 0 || ny < 0 || nx >= 4 || ny >= 3) {
                    continue;
                }
                f[board[i][j]][board[nx][ny]] = 3;
            }
        }
    }
    for(int k = 0; k < 10; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(f[i][j] > f[i][k]+f[k][j]) {
                    f[i][j] = f[i][k]+f[k][j];
                }
            }
        }
    }
    for(int k = 0; k <= 100000; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                dp[k][i][j] = mx;
            }
        }
    }
    dp[0][4][6] = 0;
    int n = numbers.length();
    for(int i = 1; i <= n; i++) {
        int num = c2i(numbers[i-1]);
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(num != k) {
                    dp[i][num][k] = min(dp[i][num][k], dp[i-1][j][k]+f[j][num]);
                }
                if(num != j) {
                    dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k]+f[k][num]);
                }
            }
        }
    }
    /*
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            //cout << dp[2][i][j] << " ";
            if(mx > dp[n][i][j]) {
                mx = dp[n][i][j];
            }
        }
        //cout << "\n";
    }
    answer = mx;
    return answer;
}