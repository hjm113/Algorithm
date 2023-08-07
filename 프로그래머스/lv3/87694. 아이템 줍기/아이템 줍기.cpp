#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int path[110][110];
int tmp[55][55];
int vis[110][110];
int ovl[55][55];
int dx[9] = {0,0,1,-1,1,-1,-1,1};
int dy[9] = {1,-1,0,0,1,-1,1,-1};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i = 0; i < rectangle.size(); i++) {
        int sx = rectangle[i][0]*2;
        int sy = rectangle[i][1]*2;
        int ex = rectangle[i][2]*2;
        int ey = rectangle[i][3]*2;
        for(int j = sy; j <= ey; j++) {
            for(int k = sx; k <= ex; k++) {
                path[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < rectangle.size(); i++) {
        int sx = rectangle[i][0]*2;
        int sy = rectangle[i][1]*2;
        int ex = rectangle[i][2]*2;
        int ey = rectangle[i][3]*2;
        for(int j = sy+1; j < ey; j++) {
            for(int k = sx+1; k < ex; k++) {
                path[j][k] = 0;
            }
        }
    }
    for(int i = 0; i <= 105; i++) {
        for(int j = 0; j <= 105; j++) {
            vis[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    q.push({characterY*2,characterX*2});
    vis[characterY*2][characterX*2] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(vis[nx][ny] > 0 || path[nx][ny] == 0) {
                continue;
            }
            q.push({nx,ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }
    answer = vis[itemY*2][itemX*2]/2;
    return answer;
}