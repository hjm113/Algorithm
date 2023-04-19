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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m, q;
int l;
int d;
int board[70][70];
int tmpboard[70][70];
queue<pair<int,int>> que;
int vis[70][70];

void rotate() {
  int tmp[70][70] = {};
  for(int stx = 0; stx < n; stx+=l) {
    for(int sty = 0; sty < n; sty+=l) {
      int countx = 0;
      int county = 0;
      for(int i = 0; i < l; i++) {
        for(int j = 0; j < l; j++) {
          tmp[j][l-1-i] = board[stx+i][sty+j];
        }
      }
      for(int i = 0; i < l; i++) {
        for(int j = 0; j < l; j++) {
          board[stx+i][sty+j] = tmp[i][j];
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> q;
  n = (1<<m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < q; i++) {
    cin >> d;
    l = (1<<d);
    rotate();
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int count = 0;
        if(board[i][j] == 0) {
          continue;
        }
        for(int dir = 0; dir < 4; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            count++;
            continue;
          }
          else if(board[nx][ny] == 0) {
            count++;
          }
        }
        if(count > 1) {
          tmpboard[i][j] = 1;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(tmpboard[i][j] == 1) {
          board[i][j]--;
          tmpboard[i][j] = 0;
        }
      }
    }
  }
  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      sum += board[i][j];
    }
  }
  cout << sum << "\n";
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int cnt = 0;
      if(board[i][j] == 0 | vis[i][j] == 1) {
        continue;
      } 
      que.push({i,j});
      vis[i][j] = 1;
      cnt++;
      while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
          }
          if(board[nx][ny] == 0 || vis[nx][ny] == 1) {
            continue;
          }
          que.push({nx,ny});
          vis[nx][ny] = 1;
          cnt++;
        }
      }
      if(ans < cnt) {
        ans = cnt;
      }
    }
  }
  cout << ans;
}
