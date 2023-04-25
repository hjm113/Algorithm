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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int board[25][25];
void rotate() {
  int tmp[25][25] = {};
  int sub[25][25] = {};
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      sub[i][j] = board[i][j];
    }
  }
  for(int k = 0; k < 3; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        tmp[j][n-1-i] = sub[i][j];
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        sub[i][j] = tmp[i][j];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      board[i][j] = sub[i][j];
    }
  }
}
void down() {
  for(int i = 0; i < n; i++) {
    int mov = 100;
    for(int j = n-1; j >= 0; j--) {
      if(board[j][i] > -1 && board[j][i] < 9) {
        mov = j;
        int cl = board[j][i];
        while(1) {
          int ori = mov;
          mov++;
          if(board[mov][i] == -1 || mov == n) {
            break;;
          }
          else if(board[mov][i] == 9) {
            board[mov][i] = cl;
            board[ori][i] = 9;
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  while(1) {
    int fge = 0;
    int fim = 0;
    int fir = 0;
    int fx = 0;
    int fy = 0;
    int vis[6][25][25] = {};
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] < 1 || board[i][j] == 9) {
          continue;
        }
        int sx = i;
        int sy = j;
        int rbow = 0;
        int mag = 0;
        int gen = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int clr = board[i][j];
        vis[clr][i][j] = 1;
        mag++;
        gen++;
        while(!q.empty()) {
          auto cur = q.front();
          q.pop();
          for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
              continue;
            }
            if(vis[clr][nx][ny] > 0 || board[nx][ny] == -1) {
              continue;
            }
            if(board[nx][ny] == 0) {
              vis[clr][nx][ny] = 1;
              q.push({nx,ny});
              rbow++;
              mag++;
            }
            if(board[nx][ny] == clr) {
              vis[clr][nx][ny] = 1;
              q.push({nx,ny});
              mag++;
              gen++;
            }
          }
        }
        if(mag < 2 || gen < 1) {
          continue;
        }
        if(mag > fim) {
          fge = gen;
          fim = mag;
          fir = rbow;
          fx = sx;
          fy = sy;
        }
        else if(mag == fim) {
          if(rbow > fir) {
            fge = gen;
            fir = rbow;
            fx = sx;
            fy = sy;
          }
          else if(rbow == fir) {
            if(sx > fx) {
              fge = gen;
              fx = sx;
              fy = sy;
            }
            else if(sx == fx) {
              if(sy > fy) {
                fge = gen;
                fy = sy;
              }
            }
          }
        }
      }
    }
    if(fim < 2 || fge < 1) {
      break;
    }
    ans += (fim*fim);
    queue<pair<int,int>> q;
    int viss[25][25] = {};
    q.push({fx,fy});
    viss[25][25] = 1;
    int col = board[fx][fy];
    board[fx][fy] = 9;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
          continue;
        }
        if(viss[nx][ny] > 0 || board[nx][ny] == -1) {
          continue;
        }
        if(board[nx][ny] == 0 || board[nx][ny] == col) {
          viss[nx][ny] = 1;
          q.push({nx,ny});
          board[nx][ny] = 9;
        }
      }
    }
    down();
   
    rotate();
   
    down();
   
  }
  cout << ans;
}

