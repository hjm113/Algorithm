#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int mx = 0;
int vis[505][505];
int chk[505][505];
int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    int cnt2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] > 0 || land[i][j] == 0) {
                continue;
            }
            int cnt = 0;
            cnt2++;
            queue<pair<int,int>> ans;
            queue<pair<int,int>> q;
            vis[i][j] = 1;
            chk[i][j] = cnt2;
            q.push({i,j});
            ans.push({i,j});
            cnt++;
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                        continue;
                    }
                    if(vis[nx][ny] > 0 || land[nx][ny] == 0) {
                        continue;
                    }
                    vis[nx][ny] = vis[cur.X][cur.Y]+1;
                    q.push({nx,ny});
                    ans.push({nx,ny});
                    cnt++;
                }
            }
            while(!ans.empty()) {
                auto cur = ans.front();
                ans.pop();
                vis[cur.X][cur.Y] = cnt;
                chk[cur.X][cur.Y] = cnt2;
            }
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << chk[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i = 0; i < m; i++) {
        int cnt = 0;
        int used[100000] = {};
        for(int j = 0; j < n; j++) {
            if(used[chk[j][i]] == 1) {
                continue;
            }
            cnt += vis[j][i];
            used[chk[j][i]] = 1;
        }
        mx = max(mx,cnt);
    }
    answer = mx;
    return answer;
}