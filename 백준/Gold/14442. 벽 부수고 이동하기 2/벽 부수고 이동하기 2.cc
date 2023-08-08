#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
int d[1005];
char board[1005][1005];
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
vector<pair<int,int>> adj[1005];
int mx = 2000000000;
int n, m, k;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
queue<tuple<int,int,int>> q;
int vis[1005][1005][15];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  if(n == 1 && m == 1) {
    cout << 1;
    return 0;
  }
  q.push({0,0,0});
  vis[0][0][0] = 1;
  while(!q.empty()) {
    int x,y,z;
    tie(x,y,z) = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if(vis[nx][ny][z] > 0) {
        continue;
      }
      if(board[nx][ny] == '1' && z < k) {
        if(vis[nx][ny][z+1] > 0) {
          continue;
        }
        vis[nx][ny][z+1] = vis[x][y][z] + 1;
        q.push({nx,ny,z+1});
      }
      if(board[nx][ny] == '0') {
        vis[nx][ny][z] = vis[x][y][z] + 1;
        q.push({nx,ny,z});
      }
    }
  }
  for(int i = 0; i <= k; i++) {
    if(mx > vis[n-1][m-1][i] && vis[n-1][m-1][i] != 0) {
      mx = vis[n-1][m-1][i];
    }
  }
  if(mx == 2000000000) {
    cout << -1;
    return 0;
  }
  cout << mx;
}