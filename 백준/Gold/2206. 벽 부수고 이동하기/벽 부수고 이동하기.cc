#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

#define X first
#define Y second
string board[1100];
int vis[1100][1100][2];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
  }
  for(int q = 0; q < n; q++) {
    for(int p = 0; p < m; p++) {
      vis[q][p][0] = -1;
      vis[q][p][1] = -1;
    }
  }
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(0, 0, 0));
  vis[0][0][0] = 1; 
  vis[0][0][1] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(get<0>(cur) == n-1 && get<1>(cur) == m-1) {
        cout << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
        return 0;
      }
    for(int dir = 0; dir < 4; dir++) {
      int nx = get<0>(cur) + dx[dir];
      int ny = get<1>(cur) + dy[dir];
      int check = get<2>(cur);
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }
      if(board[nx][ny] == '0' && vis[nx][ny][check] == -1) {
        vis[nx][ny][check] = vis[get<0>(cur)][get<1>(cur)][check] + 1;
        q.push(make_tuple(nx, ny, check));
      }
      if(check == 0 && board[nx][ny] == '1' && vis[nx][ny][check] == -1) {
        vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][check] + 1;
        q.push(make_tuple(nx, ny, 1));
      }
      
    }
  }
  cout << -1;
}