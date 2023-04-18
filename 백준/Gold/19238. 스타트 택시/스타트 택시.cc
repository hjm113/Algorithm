#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
#define X first
#define Y second
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[25][25];
int s[25][25];
pair<int,int> f[450];
int n, m, k;
pair<int, int> car;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  queue<pair<int,int>> q;
  cin >> car.X >> car.Y;
  for(int i = 0; i < m; i++) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    s[a][b] = i;
    board[a][b] = 10;
    f[i] = {c,d};
  }

  while(1) {
    int len = 10000;
    int ansx = 10000;
    int ansy = 10000;
    int out = 0;
    int viss[25][25] = {};
    q.push({car.X,car.Y});
    viss[car.X][car.Y] = 1;
    if(board[car.X][car.Y] == 10) {
      len = 0;
      ansx = car.X;
      ansy = car.Y;
    }
    else {
       while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 1 || nx > n || ny < 1 || ny > n) {
            continue;
          }
          if(viss[nx][ny] > 0 || board[nx][ny] == 1) {
            continue;
          }
          if(board[nx][ny] == 10) {
            int tmplen = viss[cur.X][cur.Y];
            if(len > tmplen) {
              len = tmplen;
              ansx = nx;
              ansy = ny;
            }
            else if(len == tmplen) {
              if(ansx > nx) {
                ansx = nx;
                ansy = ny;
              }
              if(ansx == nx) {
                if(ansy > ny) {
                  ansx = nx;
                  ansy = ny;
                }
              }
            }
            else if(len < tmplen) {
              out = 1;
              while(!q.empty()) {
                q.pop();
              }
              break; //out
            }
          }
          q.push({nx,ny});
          viss[nx][ny] = viss[cur.X][cur.Y] + 1;
        }
        if(out == 1) {
          break;
        }
      }
    }
    if(ansx == 10000) {
      k = -1;
      break;
    }
    board[ansx][ansy] = 0;
    k -= len;
    if(k < 0) {
      k = -1;
      break;
    }
    
    int visf[25][25] = {};
    q.push({ansx,ansy});
    visf[ansx][ansy] = 1;
    int arr = 0;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 1 || nx > n || ny < 1 || ny > n) {
          continue;
        }
        if(visf[nx][ny] > 0 || board[nx][ny] == 1) {
          continue;
        }
        if(nx == f[s[ansx][ansy]].X && ny == f[s[ansx][ansy]].Y) {
          len = visf[cur.X][cur.Y];
          arr = 1;
          while(!q.empty()) {
            q.pop();
          }
          break;
        }
        q.push({nx,ny});
        visf[nx][ny] = visf[cur.X][cur.Y] + 1;
      }
    }
    if(arr == 0) {
      k = -1;
      break;
    }
    //cout << f[s[ansx][ansy]].X << " " << f[s[ansx][ansy]].Y << "\n";
    //cout << "len" << len<< "\n";
    k -= len;
    if(k < 0) {
      k = -1;
      break;
    }
    k += (len*2);
    car = {f[s[ansx][ansy]].X,f[s[ansx][ansy]].Y};
    int check = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(board[i][j] == 10) {
          check = 1;
        }
      }
    }
    if(check == 0) {
      break;
    }
  }
  cout << k;
}
