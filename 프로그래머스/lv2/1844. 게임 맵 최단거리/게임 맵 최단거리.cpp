#include<vector>
#include<queue>
#include<iostream>
using namespace std;
queue<pair<int,int>> q;
int vis[105][105];
#define X first
#define Y second
int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,-1,1};
int solution(vector<vector<int>>maps)
{
    int answer = 0;
    int m = maps[0].size();
    int n = maps.size();
    q.push({0,0});
    vis[0][0] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(vis[nx][ny] > 0 || maps[nx][ny] == 0) {
                continue;
            }
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    answer = vis[n-1][m-1];
    if(answer == 0) {
        answer = -1;
    }
    return answer;
}