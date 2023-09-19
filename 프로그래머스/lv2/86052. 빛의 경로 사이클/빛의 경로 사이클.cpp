#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int chk[505][505];
int dx[5] = {1,0,-1,0};
int dy[5] = {0,1,0,-1};
int vis[505][505][5];
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int n = grid.size();
    int m = grid[0].length();
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                int chk = 0;
                int cnt = 0;
                //cout << x << " " << y << " " << st << "\n";
                while(1) {
                    if(nx < 0) {
                        nx = n-1;
                    }
                    else if(nx >= n) {
                        nx = 0;
                    }
                    else if(ny < 0) {
                        ny = m-1;
                    }
                    else if(ny >= m) {
                        ny = 0;
                    }
                    if(vis[nx][ny][dir] == 1) {
                        chk = 1;
                        break;
                    }
                    vis[nx][ny][dir] = 1;
                    if(grid[nx][ny] == 'L') {
                        dir++;
                        dir %= 4;
                    }
                    else if(grid[nx][ny] == 'R') {
                        dir += 4;
                        dir--;
                        dir %= 4;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                    cnt++;
                }
                if(chk == 1) {
                    if(cnt > 0){
                        answer.push_back(cnt);
                    }
                }
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}