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

int dx[8] = {-1, 0, 0, 1};
int dy[8] = {0, -1, 1, 0};
int board[55][55];
int num[11];
vector<tuple<int,int>> pos;
int n, m;
int cnt = 0;
int mx = 1000000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(board[i][j] == 2) {
        pos.push_back(make_tuple(i,j));
        cnt++;
      }
    }
  }
  for(int i = cnt-m; i < cnt; i++) {
    num[i] = 1;
  }
  do {
    int vis[55][55] = {};
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] == 1) {
          vis[i][j] = -10;
        }
        if(board[i][j] == 2) {
          vis[i][j] = -10;
        }
      }
    }
    queue<tuple<int,int>> q;
    for(int i = 0; i < cnt; i++) {
      if(num[i] == 1) {
        int x,y;
        tie(x,y) = pos[i];
        vis[x][y] = 1;
        q.push(make_tuple(x,y));
      }
    }
    int check = 0;
    while(!q.empty()) {
      int x,y;
      tie(x,y) = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
          continue;
        }
        if(board[nx][ny] == 1) {
          continue;
        }
        if(vis[nx][ny] > 0) {
          continue;
        }
        if(board[nx][ny] == 2) {
          vis[nx][ny] = vis[x][y] + 1;
          q.push(make_tuple(nx,ny));
        }
        else {
          vis[nx][ny] = vis[x][y] + 1;
          check = vis[x][y] + 1;
          q.push(make_tuple(nx,ny));
        }
      }
    }
    int count = 0;;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(vis[i][j] == 0) {
          count = 1;
          break;
          
        }
      }
      if(count == 1) {
        break;
      }
    }
    if(mx > check && count == 0) {
      mx = check;
    }
  }while(next_permutation(num,num+cnt));
  
  if(mx == 1000000) {
    cout << -1;
  }
  else if(mx == 0) {
    cout << 0;
  }
  else {
    cout << mx - 1;
  }
  
}
