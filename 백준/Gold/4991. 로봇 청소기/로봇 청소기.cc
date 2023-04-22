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

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n, m, t;
int posx = 0;
int posy = 0;
int tmpx = 0;
int tmpy = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  while(n != 0 || m != 0) {
    int mx = 10000;
    int cnt = 1;
    int num[12] = {};
    char board[30][30] = {};
    int check[30][30] = {};
    int dist[12][12] = {};
    vector<tuple<int,int>> postmp;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        cin >> board[j][k];
        if(board[j][k] == 'o') {
          postmp.push_back(make_tuple(j,k));
          check[j][k] = 0;
        }
        if(board[j][k] == '*') {
          postmp.push_back(make_tuple(j,k));
          check[j][k] = cnt;
          cnt++;
        }
      }
    }
    int neg = 1;
    for(int i = 0; i < postmp.size(); i++) {
      int x, y;
      tie(x,y) = postmp[i];
      int vis[30][30] = {};
      queue<pair<int,int>> q;
      q.push({x,y});
      vis[x][y] = 1;
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
          }
          if(vis[nx][ny] > 0 || board[nx][ny] == 'x') {
            continue;
          }
          if(board[nx][ny] == '*') {
            if(check[x][y] == 0) {
              neg += 1;
            }
            dist[check[x][y]][check[nx][ny]] = vis[cur.X][cur.Y];
          }
          vis[nx][ny] = vis[cur.X][cur.Y] + 1;
          q.push({nx,ny});
        }
      }
    }
    for(int i = 0; i < cnt-1; i++) {
      num[i] = i+1;
    }
    do{
      int sum = 0;
      for(int i = 0; i < cnt-1; i++) {
        if(i == 0) {
          sum += dist[0][num[i]];
        }
        sum += dist[num[i]][num[i+1]];
      }
      if(mx > sum) {
        mx = sum;
      }
    }while(next_permutation(num,num+cnt-1));
    if(cnt > 1) {
      if(neg != cnt) {
        cout << -1 << "\n";
      }
      else {
        cout << mx << "\n";
      }
    }
    else if(cnt == 1) {
      cout << mx << "\n";
    }
    
    cin >> m >> n;
  }
}
