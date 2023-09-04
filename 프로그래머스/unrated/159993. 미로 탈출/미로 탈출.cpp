#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#define X first
#define Y second
using namespace std;
int vis[3][105][105];
queue<tuple<int,int,int>> q;
int dx[5] = {0,0,-1,1};
int dy[5] = {1,-1,0,0};
int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int lx = 0;
    int ly = 0;
    int ex = 0;
    int ey = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] == 'S') {
                q.push({0,i,j});
                vis[0][i][j] = 1;
            }
            if(maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
            if(maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    while(!q.empty()) {
        int k,x,y;
        tie(k,x,y) = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(maps[nx][ny] == 'X' || vis[k][nx][ny] > 0) {
                continue;
            }
            if(maps[nx][ny] == 'L') {
                vis[k+1][nx][ny] = vis[k][x][y] + 1;
                q.push({k+1,nx,ny});
            }
            else {
                vis[k][nx][ny] = vis[k][x][y] + 1;
                q.push({k,nx,ny});
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++) {
            cout << vis[1][i][j] << " ";
        }
        cout << "\n";
    }
    answer = vis[1][ex][ey] - 1;
    return answer;
}