#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> adj;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
int erase[10];
int sum = 0;
int mx = 2000000000;
int tmp[5][5];
int card[5][5];
vector<pair<int,int>> ans;
vector<int> ss;
void dfs(int x, int y, int cnt) {
    int val = tmp[x][y];
    int chk = 0;
    if(val > 0 && erase[val] < 2) {
        chk = val;
    }
    if(cnt == 0) {
        if(mx > sum) {
            /*
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i].X << " " << ans[i].Y << " " << ss[i] << "\n";
            }
            cout << sum << "\n";
            */
            mx = sum;
        }
        return;
    }
    int vis[5][5] = {};
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
                continue;
            }
            int out = 0;
            if(vis[nx][ny] == 0) {
                q.push({nx,ny});
                vis[nx][ny] = vis[cur.X][cur.Y]+1;
                out = 1;
            }
                if(tmp[nx][ny] > 0) {
                    continue;
                }
            while(1) {
                nx += dx[dir];
                ny += dy[dir];
                if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
                    int nnx = nx - dx[dir];
                    int nny = ny - dy[dir];
                    if(vis[nnx][nny] == 0) {
                        q.push({nnx,nny});
                        vis[nnx][nny] = vis[cur.X][cur.Y]+1;
                        break;
                    }
                    break;
                }
                if(tmp[nx][ny] > 0 && vis[nx][ny] == 0) {
                    q.push({nx,ny});
                    vis[nx][ny] = vis[cur.X][cur.Y]+1;
                    break;
                }
            }
        }
        /*
        if(cnt == 11) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    cout << vis[i][j] << " ";
                }
                cout << "\n";
            }
        }
        */
        
    }
    
    for(auto nxt : adj) {
        if(nxt.X == x && nxt.Y == y) {
            continue;
        }
        if(erase[card[nxt.X][nxt.Y]] == 2) {
            continue;
        }
        if(chk == 0) {
            int ori = tmp[x][y];
            tmp[x][y] = 0;
            erase[tmp[nxt.X][nxt.Y]]++;
            sum += (vis[nxt.X][nxt.Y]-1);
            ans.push_back({nxt.X,nxt.Y});
            ss.push_back(vis[nxt.X][nxt.Y]-1);
            dfs(nxt.X,nxt.Y,cnt-1);
            ss.pop_back();
            ans.pop_back();
            sum -= (vis[nxt.X][nxt.Y]-1);
            erase[tmp[nxt.X][nxt.Y]]--;
            tmp[x][y] = ori;
        }
        else {
            if(tmp[nxt.X][nxt.Y] == chk) {
                int ori = tmp[x][y];
                tmp[x][y] = 0;
                erase[tmp[nxt.X][nxt.Y]]++;
                sum += (vis[nxt.X][nxt.Y]-1);
                ans.push_back({nxt.X,nxt.Y});
                
                ss.push_back(vis[nxt.X][nxt.Y]-1);
                dfs(nxt.X,nxt.Y,cnt-1);
                ss.pop_back();
                ans.pop_back();
                sum -= (vis[nxt.X][nxt.Y]-1);
                erase[tmp[nxt.X][nxt.Y]]--;
                tmp[x][y] = ori;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tmp[i][j] = board[i][j];
            card[i][j] = board[i][j];
            if(board[i][j] > 0) {
                cnt++;
                adj.push_back({i,j});
            }
        }
    }
    int add = cnt;
    if(board[r][c] > 0) {
        cnt--;
        erase[board[r][c]]++;
    }
    dfs(r,c,cnt);
    answer = mx+add;
    return answer;
}