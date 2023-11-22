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
typedef long long ll;
vector<pair<int,int>> vc;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n, m;
int board[1005][1005];
int vis[1005][1005];
queue<pair<int,int>> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(board[i][j] == 1) {
        vis[i][j] = 1;
        q.push({i,j});
      }
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if(board[nx][ny] == -1 || vis[nx][ny] > 0) {
        continue;
      }
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push({nx,ny});
    }
  }
  int mx = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vis[i][j] == 0 && board[i][j] != -1) {
        cout << -1;
        return 0;
      }
      if(vis[i][j] > mx) {
        mx = vis[i][j];
      }
    }
  }
  cout << mx-1;
}
