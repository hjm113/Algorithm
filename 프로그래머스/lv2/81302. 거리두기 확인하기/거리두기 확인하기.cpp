#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;

int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,1,-1};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < 5; i++) {
        int chk = 1;
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(places[i][j][k] != 'P') {
                    continue;
                }
                int vis[10][10] = {};
                queue<pair<int,int>> q;
                q.push({j,k});
                vis[j][k] = 1;
                int cnt = 0;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) {
                            continue;
                        }
                        if(places[i][nx][ny] == 'X' || vis[nx][ny] > 0) {
                            continue;
                        }
                        q.push({nx,ny});
                        vis[nx][ny] = vis[cur.X][cur.Y]+1;
                        if(places[i][nx][ny] == 'P' && vis[nx][ny] <= 3) {
                            chk = 0;
                        }
                    }
                }
                /*
                cout << i << "\n";
                for(int w = 0; w < 5; w++) {
                    for(int r = 0; r < 5; r++) {
                        cout << vis[i][w][r] << " ";
                    }
                    cout << "\n";
                }
                cout << "\n";
                */
            }
        }
        answer.push_back(chk);
    }
    return answer;
}