#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;
priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> pq;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
int vis[30][30][5];
int mx = 2000000000;
int solution(vector<vector<int>> board) {
    int answer = mx;
    int n = board.size();
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
             for(int k = 0; k < 5; k++) {
                vis[i][j][k] = mx;
            }
        }
    }
    for(int dir = 0; dir < 4; dir++) {
        vis[0][0][dir] = 0;
        int nx = dx[dir];
        int ny = dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
            continue;
        }
        if(vis[nx][ny][dir] > 100) {
            vis[nx][ny][dir] = 100;
            pq.push({100,dir,dx[dir],dy[dir]});
        }
    }
    while(!pq.empty()) {
        int path,d,x,y;
        tie(path,d,x,y) = pq.top();
        pq.pop();
        if(board[x][y] == 1) {
            continue;
        }
        if(vis[x][y][d] != path) {
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            int npath = 0;
            if(dir == d) {
                npath = path+100;
            }
            else {
                npath = path+600;
            }
            if(vis[nx][ny][dir] > npath) {
                vis[nx][ny][dir] = npath;
                pq.push({npath,dir,nx,ny});
            }
        }
    }
    //cout << vis[1][1];
    for(int dir = 0; dir < 4; dir++) {
        if(answer > vis[n-1][n-1][dir]) {
            answer = vis[n-1][n-1][dir];
        }
    }
    return answer;
}