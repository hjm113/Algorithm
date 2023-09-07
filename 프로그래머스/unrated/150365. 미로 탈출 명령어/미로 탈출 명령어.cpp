#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
string board[2505][55][55];
char d[5] = {'d','l','r','u'};
int dx[5] = {1,0,0,-1};
int dy[5] = {0,-1,1,0};
queue<tuple<int,int,int>> q;
string solution(int n, int m, int ox, int oy, int r, int c, int k) {
    string answer = "";
    q.push({0,ox,oy});
    while(!q.empty()) {
        int num,x,y;
        tie(num,x,y) = q.front();
        q.pop();
        if(num == k) {
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || ny < 1 || nx > n || ny > m) {
                continue;
            }
            int remain = abs(nx-r)+abs(ny-c);
            if(remain <= k-num) {
                board[num+1][nx][ny] += board[num][x][y] + d[dir];
                q.push({num+1,nx,ny});
                break;
            }
        }
    }
    /*
    //cout << board[k][r][c];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << board[1][i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    answer = board[k][r][c];
    if(answer == "") {
        answer = "impossible";
    }
    return answer;
}