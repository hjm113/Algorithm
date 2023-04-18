#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
using namespace std;
#define X first
#define Y second
string board[1600];
string board2[1600];
int vis[1600][1600];
int vis2[1600][1600];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
    board2[i] = board[i];
  }
  
  queue <pair<int,int>> qs;
  queue <pair<int,int>> qs2;
  queue <pair<int,int>> q;
  queue <pair<int,int>> q2;
  int count = 0;
  int si = 0;
  int sj = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == 'L') {
        si = i;
        sj = j;
      }
      if(board[i][j] != 'X') {
        q.push({i,j});
      }
    }
  }
  qs.push({si,sj});
  vis2[si][sj] = 1;
  while(1) {
    while(!q.empty()){
      auto cur = q.front();
      q.pop();
      int check = 0;
      for(int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        if(vis[nx][ny] > 0) {
          continue;
        }
        if(board[nx][ny] == 'X') {
          q2.push({nx,ny});
          vis[nx][ny] = 1;
        }
      }
    }
    while(!q2.empty()) {
      auto cur = q2.front();
      q2.pop();
      board[cur.X][cur.Y] = '.';
      q.push({cur.X,cur.Y});
    }
    count++;
    while(!qs.empty()) {
      auto cur = qs.front();
      qs.pop();
      for(int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        if(vis2[nx][ny] > 0) {
          continue;
        }
        if(board[nx][ny] == 'L') {
          cout << count;
          return 0;
        }
        if(board[nx][ny] == '.') {
          vis2[nx][ny] = 1;
          qs.push({nx,ny});
        }
        if(board[nx][ny] == 'X') {
          vis2[nx][ny] = 1;
          qs2.push({nx,ny});
        }
      }
    }
    while(!qs2.empty()) {
      auto cur = qs2.front();
      qs2.pop();
      qs.push({cur.X,cur.Y});
    }
  }
}