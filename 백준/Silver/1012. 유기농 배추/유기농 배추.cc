#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  cin >> num;
  for(int i = 0; i < num; i++) {
    int board[52][52];
    int vis[52][52];
    int n;
    int m;
    cin >> m >> n;
    int numc;
    cin >> numc;
    for(int q = 0; q < n; q++) {
      for(int p = 0; p < m; p++) {
        board[q][p] = 0;
        vis[q][p] = -1;
      }
    }
    for(int j = 0; j < numc; j++) {
      int x;
      int y;
      cin >> y >> x;
      board[x][y] = 1;
    }
    queue<pair<int, int>> Q;
    int count = 0;
    for(int q = 0; q < n; q++) {
      for(int p = 0; p < m; p++) {
        if(board[q][p] == 1) {
          if(vis[q][p] != 1) {
            Q.push({q,p});
            count++;
          }
        }
        while(!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();
          for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n|| ny < 0|| ny >= m) {
              continue;
            }
            if(vis[nx][ny] > 0 || board[nx][ny] != 1) {
              continue;
            }
            vis[nx][ny] = 1;
            Q.push({nx,ny});
          }
        }
      }
    }
    cout << count << "\n";
  }
}