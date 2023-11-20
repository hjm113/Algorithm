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
int n;
string board[30];
int vis[30][30];
vector<int> ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '0' || vis[i][j] == 1) {
        continue;
      }
      queue<pair<int,int>> q;
      vis[i][j] = 1;
      q.push({i,j});
      int cnt = 1;
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
            continue;
          }
          if(board[nx][ny] == '0' || vis[nx][ny] == 1) {
            continue;
          }
          vis[nx][ny] = 1;
          q.push({nx,ny});
          cnt++;
        }
      }
      ans.push_back(cnt);
    }
  }
  sort(ans.begin(),ans.end());
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
}
