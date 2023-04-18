#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
using namespace std;
#define X first
#define Y second
int vis[500100][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  queue<pair<int,int>> q;
  for(int i = 0; i < 500100; i++) {
    vis[i][0] = -1;
    vis[i][1] = -1;
  }
  vis[n][0] = 1;
  q.push({n,0});
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    int sec = cur.Y;
    int nk = k + sec*(sec+1)/2;
    if(vis[nk][sec%2] == 1) {
      cout << sec;
      return 0;
    }
    if(nk > 500000) {
      cout << -1;
      return 0;
    }
    sec++;
    for(int dir = 0; dir < 3; dir++) {
      int nx = 0;
      if(dir == 0) {
        nx = cur.X * 2;
      }
      else if(dir == 1) {
        nx = cur.X - 1;
      }
      else if(dir == 2) {
        nx = cur.X + 1;
      }
      if(nx < 0 || nx > 500000) {
        continue;
      }
      if(vis[nx][sec%2] >= 0) {
        continue;
      }
      vis[nx][sec%2] = 1;
      q.push({nx,sec});
    }
  }
}