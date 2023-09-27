#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;
int vis[105][105][105][105];
queue<tuple<int,int,int,int>> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vis[0][0][0][1] = 1;
    q.push({0,0,0,1});
    while(!q.empty()) {
        int lx,ly,rx,ry;
        tie(lx,ly,rx,ry) = q.front();
        q.pop();
        if((lx == n-1 && ly == n-1) || (rx == n-1 && ry == n-1)) {
            answer = vis[lx][ly][rx][ry]-1;
            break;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nlx = lx + dx[dir];
            int nly = ly + dy[dir];
            int nrx = rx + dx[dir];
            int nry = ry + dy[dir];
            if(nlx < 0 || nly < 0 || nlx >= n || nly >= n) {
                continue;
            }
            if(nrx < 0 || nry < 0 || nrx >= n || nry >= n) {
                continue;
            }
            if(vis[nrx][nry][nlx][nly] > 0 || vis[nlx][nly][nrx][nry] > 0) {
                continue;
            }
            if(board[nlx][nly] == 1 || board[nrx][nry] == 1) {
                continue;
            }
            vis[nlx][nly][nrx][nry] = vis[lx][ly][rx][ry] + 1;
            q.push({nlx,nly,nrx,nry});
        }
        if((rx == lx && ry-1 == ly) || (rx == lx && ry+1 == ly)) {
            int tx1 = lx;
            int ty1 = ly;
            int tx2 = rx;
            int ty2 = ry;
            if(rx == lx && ry+1 == ly) {
                lx = rx;
                ly = ry;
                rx = tx1;
                ry = ty1;
            }
            if(rx+1 < n) {
                //cout << rx+1 << " " << ry << " " << rx << " " << ry << " " << vis[tx1][ty1][tx2][ty2] << "\n";
                if(vis[rx+1][ry][rx][ry] == 0 && vis[rx][ry][rx+1][ry] == 0) {
                    if(board[rx][ry] == 0 && board[rx+1][ry] == 0 && board[rx+1][ry-1] == 0) {
                        vis[rx+1][ry][rx][ry] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({rx+1,ry,rx,ry});
                    }
                }
            }
            if(rx-1 >= 0) {
                if(vis[rx-1][ry][rx][ry] == 0 && vis[rx][ry][rx-1][ry] == 0) {
                    if(board[rx][ry] == 0 && board[rx-1][ry] == 0 && board[rx-1][ry-1] == 0) {
                        vis[rx-1][ry][rx][ry] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({rx-1,ry,rx,ry});
                    }
                }
            }
            if(lx+1 < n) {
                //cout << "asdfasd";
                if(vis[lx+1][ly][lx][ly] == 0 && vis[lx][ly][lx+1][ly] == 0) {
                    if(board[lx][ly] == 0 && board[lx+1][ly] == 0 && board[lx+1][ly+1] == 0) {
                        vis[lx][ly][lx+1][ly] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({lx,ly,lx+1,ly});
                    }
                }
            }
            if(lx-1 >= 0) {
                if(vis[lx-1][ly][lx][ly] == 0 && vis[lx][ly][lx-1][ly] == 0) {
                    if(board[lx][ly] == 0 && board[lx-1][ly] == 0 && board[lx-1][ly+1] == 0) {
                         vis[lx][ly][lx-1][ly] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({lx,ly,lx-1,ly});
                    }
                } 
            }
        }
        if((rx+1 == lx && ry == ly) || (rx-1 == lx && ry == ly)) {
            int tx1 = lx;
            int ty1 = ly;
            int tx2 = rx;
            int ty2 = ry;
            if(rx-1 == lx && ry == ly) {
                lx = rx;
                ly = ry;
                rx = tx1;
                ry = ty1;
            }
            if(ry+1 < n) {
                if(vis[rx][ry+1][rx][ry] == 0 && vis[rx][ry][rx][ry+1] == 0) {
                    if(board[rx][ry] == 0 && board[rx][ry+1] == 0 && board[rx+1][ry+1] == 0) {
                        vis[rx][ry+1][rx][ry] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({rx,ry+1,rx,ry});
                    }
                }
            }
            if(ry-1 >= 0) {
                if(vis[rx][ry-1][rx][ry] == 0 && vis[rx][ry][rx][ry-1] == 0) {
                    if(board[rx][ry] == 0 && board[rx][ry-1] == 0 && board[rx+1][ry-1] == 0) {
                        vis[rx][ry-1][rx][ry] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({rx,ry-1,rx,ry});
                    }
                }
            }
            if(ly+1 < n) {
                if(vis[lx][ly+1][lx][ly] == 0 && vis[lx][ly][lx][ly+1] == 0) {
                    if(board[lx][ly] == 0 && board[lx][ly+1] == 0 && board[lx-1][ly+1] == 0) {
                        vis[lx][ly][lx][ly+1] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({lx,ly,lx,ly+1});
                    }
                }
            }
            if(ly-1 >= 0) {
                if(vis[lx][ly-1][lx][ly] == 0 && vis[lx][ly][lx][ly-1] == 0) {
                    if(board[lx][ly] == 0 && board[lx][ly-1] == 0 && board[lx-1][ly-1] == 0) {
                        vis[lx][ly][lx][ly-1] = vis[tx1][ty1][tx2][ty2] + 1;
                        q.push({lx,ly,lx,ly-1});
                    }
                }
            }
        }
    }
    /*
    cout << vis[0][2][0][1] << "\n";
    cout << vis[1][1][0][1] << "\n";
    cout << vis[0][2][1][2] << "\n";
    cout << vis[1][2][2][2] << "\n";
    */
    return answer;
}