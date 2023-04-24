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
int board[15][15];
int vis[15][15];
int used[10];
int check[10] = {1,1,1,1,1,1,1,1,1,1};
vector<pair<int,int>> isld[10];
int brid[10][10];
int n, m;
int cnt = 0;
int sum = 0;
vector<int> lis[10];
int mx = INT_MAX;
void func(int k, vector<int> bfs[]) {
  if(k == cnt){
    int vis1[10] = {};
    queue<int> q;
    q.push(1);
    vis1[1] = 1;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < bfs[cur].size(); dir++) {
        if(vis1[bfs[cur][dir]] == 0) {
          q.push(bfs[cur][dir]);
          vis1[bfs[cur][dir]] = 1;
        }
      }
    }
    for(int i = 1; i <= cnt; i++) {
      if(vis1[i] == 0) {
        return;
      }
    }
    if(mx > sum) {
      mx = sum;
    }
    return;
  }
  for(int i = 1; i <= cnt; i++) {
    if(brid[k][i] > 0) {
      sum += brid[k][i];
      int tmp = brid[i][k];
      brid[i][k] = 0;   
      bfs[i].push_back(k);
      bfs[k].push_back(i);
      //cout << sum;
      //cout << " " << "pos" << k << " " << i << "\n"; 
      func(k+1, bfs);
      //cout << "now" << "\n";
      brid[i][k] = tmp;
      bfs[i].pop_back();
      bfs[k].pop_back();
      sum -= brid[k][i];
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  queue<pair<int,int>> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == 0 || vis[i][j] == 1) {
        continue;
      }
      cnt++;
      board[i][j] = cnt;
      vis[i][j] = 1;
      q.push({i,j});
      used[cnt] = 1;
      isld[cnt].push_back({i,j});
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
          }
          if(board[nx][ny] == 0 || vis[nx][ny] == 1) {
            continue;
          }
          vis[nx][ny] = 1;
          q.push({nx,ny});
          board[nx][ny] = cnt;
          isld[cnt].push_back({nx,ny});
        }
      }
    }
  }
  for(int i = 1; i <= cnt; i++) {
    int vis[15][15] = {};
    for(int j = 0; j < isld[i].size(); j++) {
      int x, y;
      tie(x,y) = isld[i][j];
      for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        if(board[nx][ny] == i) {
          continue;
        }
        vis[nx][ny] = 1;
        while(1) {
          int ox = nx;
          int oy = ny;
          nx += dx[dir];
          ny += dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            break;
          }
          if(board[nx][ny] == i) {
            break;
          }
          if(board[nx][ny] > 0 && vis[ox][oy] > 1) {
            if(brid[i][board[nx][ny]] > 0) {
              if(brid[i][board[nx][ny]] > vis[ox][oy]) {
                brid[i][board[nx][ny]] = vis[ox][oy];
              }
            }
            else {
              brid[i][board[nx][ny]] = vis[ox][oy];
            }
            break;
          }
          else if(board[nx][ny] > 0 && vis[ox][oy] == 1) {
            break;
          }
          vis[nx][ny] = vis[ox][oy] + 1;
        }
      }
    }
  }
  func(1,lis);
  if(mx == INT_MAX) {
    cout << -1;
  }
  else {
    cout << mx;
  }
  /*
  cout << "\n";
  for(int i = 1; i <= cnt; i++) {
    for(int j = 1; j <= cnt; j++) {
      cout << brid[i][j] << " ";
    }
    cout << "\n";
  }
  
  cout << "\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  */
  
}

