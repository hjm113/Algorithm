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
int board[15][15];
int t, n;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
int ary[15];
int ans[30];
vector<pair<int,int>> pos;
int mxcon = 0;
int mx = 200000000;
vector<int> usi[30];
void dfs(int k, int num, int conn, int used) {
  if(k == num) {
    if(mxcon <= conn) {
      mxcon = conn;
      ans[mxcon] = min(ans[mxcon],used);
    }
    return;
  }
  for(int dir = 0; dir < 4; dir++) {
    vector<pair<int,int>> tmp;
    int nx = pos[k].X;
    int ny = pos[k].Y;
    int check = 0;
    while(1) {
      nx += dx[dir];
      ny += dy[dir];
      if(board[nx][ny] == 1) {
        check = 1;
        break;
      }
      if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
        break;
      }
      tmp.push_back({nx,ny});
    }
    if(check == 0) {
      for(int i = 0; i < tmp.size(); i++) {
        board[tmp[i].X][tmp[i].Y] = 1;
      }
      dfs(k+1,num,conn+1,used+tmp.size());
      for(int i = 0; i < tmp.size(); i++) {
        board[tmp[i].X][tmp[i].Y] = 0;
      }
    }
  }
  dfs(k+1,num,conn,used);
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int count = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> board[i][j];
        if(board[i][j] == 1 && i != 0 && j != 0 && i != n-1 && j != n-1) {
          pos.push_back({i,j});
        }
      }
    }
    for(int i = 0; i < 30; i++) {
      ans[i] = mx;
    }
    mxcon = 0;
    dfs(0,pos.size(),0,0);
    for(int i = 0; i < 30; i++) {
      while(!usi[i].empty()) {
        usi[i].pop_back();
      }
    }
    while(!pos.empty()) {
      pos.pop_back();
    }
    cout << "#" << count << " " << ans[mxcon] << "\n";
    count++;
  }
  return 0;
}