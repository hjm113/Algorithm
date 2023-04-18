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
int dx[6] = {0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, -1, 1};
int dir[450][6][6];
int shark[450];
pair<int,int> pos[450];
int board[25][25];
vector<pair<int,int>> vis[25][25];
int n, m, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(board[i][j] > 0) {
        pos[board[i][j]] = {i,j};
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    cin >> shark[i];
  }
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= 4; j++) {
      for(int k = 1; k <= 4; k++) {
        cin >> dir[i][j][k];
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    int x = pos[i].X;
    int y = pos[i].Y;
    vis[x][y].push_back({i,k});
  }
  int cnt = 0;
  while(1) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(vis[i][j].size() > 0) {
          if(vis[i][j][0].Y > 0) {
            vis[i][j][0].Y--;
          }
        }
      }
    }
    pair<int,int> ori[25][25] = {};
    for(int i = 1; i <= m; i++) {
      int check = 0;
      int x = pos[i].X;
      int y = pos[i].Y;
      if(y == -1) {
        continue;
      }
      
      for(int j = 1; j <= 4; j++) {
        int move = dir[i][shark[i]][j];
        int nx = x + dx[move];
        int ny = y + dy[move];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
          continue;
        }
        if(vis[nx][ny].size() == 0){
          check = 1;
          if(ori[nx][ny].X > 0) {
            if(ori[nx][ny].X > i) {
              pos[ori[nx][ny].X].Y = -1;
              ori[nx][ny] = {i,k};
              pos[i] = {nx,ny};
              shark[i] = move;
              break;
            }
            else {
              pos[i].Y = -1;
              break;
            }
          }
          else {
            ori[nx][ny] = {i,k};
            pos[i] = {nx,ny};
            shark[i] = move;
          }
          break;
        }
      }
      if(check == 0) {
        for(int j = 1; j <= 4; j++) {
          int move = dir[i][shark[i]][j];
          int nx = x + dx[move];
          int ny = y + dy[move];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
          }
          if(vis[nx][ny].size() == 1 && vis[nx][ny][0].X == i){
            ori[nx][ny] = {i,k};
            pos[i] = {nx,ny};
            shark[i] = move;
            break;
          }
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(ori[i][j].X > 0) {
          if(vis[i][j].size() > 0) {
            vis[i][j].pop_back();
          }
          vis[i][j].push_back({ori[i][j].X,ori[i][j].Y});
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(vis[i][j].size() > 0) {
          if(vis[i][j][0].Y == 0) {
            vis[i][j].pop_back();
          }
        }
      }
    }
    cnt++;
    int out = 0;
    for(int i = 1; i <= m; i++) {
      if(pos[i].Y == -1) {
        out++;
      }
    }
    if(cnt > 1000) {
      break;
    }
    if(out + 1 == m) {
      break;
    }
  }
  if(cnt > 1000) {
    cout << -1;
  }
  else {
    cout << cnt;
  }
}
