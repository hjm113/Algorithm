#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;
int shape[300][55][55];
int tmp[300][55][55];
int vis[55][55];
queue<pair<int,int>> q;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
int used[60][60];
vector<pair<int,int>> opos;
vector<int> ygo;
// 저걸 어케 만들 수 가 있을까나

void rotate(int k, int n, int m) {
    int ttmp[55][55] = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ttmp[j][n-i-1] = tmp[k][i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            tmp[k][i][j] = ttmp[i][j];
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    int n = game_board.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] == 1 || game_board[i][j] == 1) {
                continue;
            }
            int erx = i;
            vis[i][j] = 1;
            shape[cnt][i-erx][j] = 1;
            q.push({i,j});
            int ery = j;
            int mxx = i;
            int mxy = j;
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }
                    if(game_board[nx][ny] == 1 || vis[nx][ny] == 1) {
                        continue;
                    }
                    if(ny < ery) {
                        ery = ny;
                    }
                    if(nx < erx) {
                        erx = nx;
                    }
                    if(ny > mxy) {
                        mxy = ny;
                    }
                    if(nx > mxx) {
                        mxx = nx;
                    }
                    vis[nx][ny] = 1;
                    shape[cnt][nx-erx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            ygo.push_back(ery);
            opos.push_back({mxx-erx+1,mxy-ery+1});
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(shape[i][j][k] == 1) {
                    tmp[i][j][k-ygo[i]] = 1;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < cnt; i++) {
        int a = 4;
        int out1 = 0;
        int out2 = 0;
        int out3 = 0;
        while(a--) {
            for(int j = 0; j <= n-opos[i].X; j++) {
                for(int k = 0; k <= n-opos[i].Y; k++) {
                    int check = 0;
                    queue<pair<int,int>> q1;
                    int vist[60][60] = {};
                    int cccnt = 0;
                    for(int r = 0; r < opos[i].X; r++) {
                        for(int w = 0; w < opos[i].Y; w++) {
                            if(table[j+r][k+w] == 1 && tmp[i][r][w] == 1) {
                                q1.push({j+r,k+w});
                                vist[j+r][k+w] = 1;
                                cccnt++;
                            }
                            if(table[j+r][k+w] != tmp[i][r][w] || used[j+r][k+w] == 1) {
                                check = 1;
                            }
                        }
                    }
                    if(check == 0) {
                        int out = 0;
                        queue<pair<int,int>> us;
                        while(!q1.empty()) {
                            auto cur = q1.front();
                            //cout << cur.X << " " << cur.Y << "\n";
                            us.push({cur.X,cur.Y});
                            q1.pop();
                            for(int dir = 0; dir < 4; dir++) {
                                int nx = cur.X + dx[dir];
                                int ny = cur.Y + dy[dir];
                                if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
                                    continue;
                                }
                                if(table[nx][ny] == 0 || vist[nx][ny] == 1) {
                                    continue;
                                }
                                if(table[nx][ny] == 1) {
                                    out = 1;
                                }
                            }
                        }
                        if(out == 0) {
                            while(!us.empty()) {
                                auto cur = us.front();
                                us.pop();
                                used[cur.X][cur.Y] = 1;
                            }
                            out1 = 1;
                            sum += cccnt;
                        }
                    }
                    if(out1 == 1) {
                        out2 = 1;
                        break;
                    }
                }
                if(out2 == 1) {
                    out3 = 1;
                    break;
                }
            }
            if(out3 == 1) {
                break;
            }
            rotate(i,opos[i].X,opos[i].Y);
            int tttmp = opos[i].X;
            opos[i].X = opos[i].Y;
            opos[i].Y = tttmp;
        }
        
    }
    answer = sum;
    return answer;
}