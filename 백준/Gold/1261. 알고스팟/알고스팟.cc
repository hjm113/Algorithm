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
int d[105][105];
char board[105][105];
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
vector<tuple<int,int,int>> adj[105][105];
int mx = 2000000000;
int n, m, k;
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
queue<tuple<int,int,int>> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int dir = 0; dir < 4; dir++) {
        if(i+dx[dir] < 1 || j+dy[dir] < 1 || i+dx[dir] > n || j+dy[dir] > m) {
          continue;
        }
        if(board[i+dx[dir]][j+dy[dir]] == '0') {
          adj[i][j].push_back({0,i+dx[dir],j+dy[dir]});
        }
        else {
          adj[i][j].push_back({1,i+dx[dir],j+dy[dir]});
        }
      }
      d[i][j] = mx;
    }
  }
  d[1][1] = 0;
  pq.push({0,1,1});
  while(!pq.empty()) {
    int dist, x, y;
    tie(dist,x,y) = pq.top();
    pq.pop();
    if(d[x][y] != dist) {
      continue;
    }
    for(auto nxt : adj[x][y]) {
      int ndist,nx,ny;
      tie(ndist,nx,ny) = nxt;
      if(d[nx][ny] > dist+ndist) {
        d[nx][ny] = dist+ndist;
        pq.push({dist+ndist,nx,ny});
      }
    }
  }
  cout << d[n][m];
}