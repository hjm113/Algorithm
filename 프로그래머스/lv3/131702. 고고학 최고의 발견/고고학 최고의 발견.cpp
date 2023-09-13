#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
int n = 0;
vector<int> board[10];
int mx = 2000000000;
int ori[10][10];
void dfs(int k, int sum) {
    if(k == n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ori[i][j] = board[i][j];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ori[i-1][j] == 0) {
                    continue;
                }
                int rot = 4 - ori[i-1][j];
                ori[i][j] += rot;
                ori[i][j] %= 4;
                sum += rot;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }
                    ori[nx][ny] += rot;
                    ori[nx][ny] %= 4;
                }
            }
        }
        int chk = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ori[i][j] != 0) {
                    chk = 1;
                }
            }
        }
        if(chk == 0) {
            if(mx > sum) {
                mx = sum;
            }
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int x = 0;
        int y = k;
        board[x][y] += i;
        board[x][y] %= 4;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            board[nx][ny] += i;
            board[nx][ny] %= 4;
        }
        dfs(k+1, sum+i);
        board[x][y] -= i;
        if(board[x][y] < 0) {
            board[x][y] += 4;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            board[nx][ny] -= i;
            if(board[nx][ny] < 0) {
                board[nx][ny] += 4;
            }
        }
    }
}

int solution(vector<vector<int>> clockHands) {
    int answer = 0;
    n = clockHands.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i].push_back(clockHands[i][j]);
        }
    }
    dfs(0, 0);
    answer = mx;
    return answer;
}