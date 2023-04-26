#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
#define X first
#define Y second
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int movx[5][5] = {{}, {-1,0,1}, {-1,0,1}, {0,-1,0}, {0,1,0}};
int movy[5][5] = {{}, {0,1,0}, {0,-1,0}, {-1,0,1}, {-1,0,1}};
int n, m, k;
int w;
vector<tuple<int,int,int>> air;
vector<tuple<int,int>> inv;
int board[25][25];
int ans[25][25];
int wall[25][25][25][25];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
      if(board[i][j] > 0 && board[i][j] < 5) {
        air.push_back(make_tuple(i,j,board[i][j]));
      }
      else if(board[i][j] == 5) {
        inv.push_back(make_tuple(i,j));
      }
    }
  }
  cin >> w;
  for(int i = 0; i < w; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    if(t == 0) {
      wall[x][y][x-1][y] = 1;
      wall[x-1][y][x][y] = 1;
    }
    else if(t == 1) {
      wall[x][y][x][y+1] = 1;
      wall[x][y+1][x][y] = 1;
    }
  }
  int choco = 0;
  while(1) {
    for(int i = 0; i < air.size(); i++) {
      int tmp[25][25] = {};
      deque<pair<int,int>> dist;
      deque<pair<int,int>> dtmp;
      int count = 5;
      int x, y, dir;
      tie(x,y,dir) = air[i];
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      //cout << "\n";
      //cout << nx << " " << ny << "\n";
      tmp[nx][ny] = count;
      dist.push_back({nx,ny});
      while(1) {
        count--;
        while(!dist.empty()) {
          auto cur = dist.front();
          dist.pop_front();
          for(int j = 0; j < 3; j++) {
            int ox = cur.X;
            int oy = cur.Y;
            if(j == 1) {
              int ax = ox+movx[dir][j];
              int ay = oy+movy[dir][j];
              if(ax < 1 || ax > n || ay < 1 || ay > m) {
                continue;
              }
              //cout << ox << oy << ax << ay << " " << wall[ox][oy][ax][ay] << "\n";
              if(wall[ox][oy][ax][ay] == 0) {
                if(tmp[ax][ay] > 0) {
                  continue;
                }
                tmp[ax][ay] = count;
                dtmp.push_back({ax,ay});
              }
            }
            else {
              int ax = ox+movx[dir][j];
              int ay = oy+movy[dir][j];
              if(ax < 1 || ax > n || ay < 1 || ay > m) {
                continue;
              }
              if(wall[ox][oy][ax][ay] == 0) {
                ox = ax;
                oy = ay;
                ax += movx[dir][1];
                ay += movy[dir][1];
                if(ax < 1 || ax > n || ay < 1 || ay > m) {
                  continue;
                }
                //cout << ox << oy << ax << ay << " " << wall[ox][oy][ax][ay] << "\n";
                if(wall[ox][oy][ax][ay] == 0) {
                  if(tmp[ax][ay] > 0) {
                    continue;
                  }
                  //cout << ox << oy << ax << ay << " " << count << "abcd  \n";
                  tmp[ax][ay] = count;
                  dtmp.push_back({ax,ay});
                }
              }
            }
          }
        }
        while(!dtmp.empty()) {
          auto cur = dtmp.front();
          dtmp.pop_front();
          dist.push_back({cur.X,cur.Y});
        }
        if(count == 1) {
          break;
        }
      }
      //cout << "\n";
      for(int w = 1; w <= n; w++) {
        for(int u = 1; u <= m; u++) {
          ans[w][u] += tmp[w][u];
          //cout << ans[w][u] << " ";
        }
        //cout << "\n";
      }
    }
    
    
    int atmp[25][25] = {};
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(ans[i][j] > 0) {
          atmp[i][j] += ans[i][j];
          for(int dir = 1; dir <= 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
              continue;
            }
            int num = abs(ans[i][j]-ans[nx][ny]) / 4;
            if(ans[i][j] < ans[nx][ny]) {
              continue;
            }
            if(wall[i][j][nx][ny] == 1) {
              continue;
            }
            atmp[nx][ny] += num;
            atmp[i][j] -= num;
          }
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        ans[i][j] = atmp[i][j];
      }
    }
    for(int i = 1; i <= n; i++) {
      if(ans[i][1] > 0) {
        ans[i][1]--; 
      }
    }
    for(int i = 1; i <= n; i++) {
      if(ans[i][m] > 0) {
        ans[i][m]--; 
      }
    }
    for(int i = 2; i < m; i++) {
      if(ans[1][i] > 0) {
        ans[1][i]--; 
      }
    }
    for(int i = 2; i < m; i++) {
      if(ans[n][i] > 0) {
        ans[n][i]--; 
      }
    }
    choco++;
    if(choco > 100) {
      break;
    }
    int out = 0;
    for(int i = 0; i < inv.size(); i++) {
      int x, y;
      tie(x,y) = inv[i];
      if(ans[x][y] < k) {
        out = 1;
      }
    }
    /*
       cout << "\n";
      for(int w = 1; w <= n; w++) {
        for(int u = 1; u <= m; u++) {
          cout << ans[w][u] << " ";
        }
        cout << "\n";
      }
    */
    if(out == 0) {
      break;
    }
  }
  cout << choco;
  
}

