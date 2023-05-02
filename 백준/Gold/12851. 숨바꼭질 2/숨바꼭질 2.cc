#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, k;
int vis[110005];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vis[n] = 1;
  if(n == k) {
    cout << 0 << "\n";
    cout << 1;
    return 0;
  }
  queue<pair<int,int>> q;
  q.push({n,0});
  int cnt = 0;
  int len = 99999999;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    vis[cur.X] = 1;
    for(int dir = 0; dir < 3; dir++) {
      int nx = 0;
      if(dir == 0) {
        nx = cur.X + 1;
      }
      else if(dir == 1) {
        nx = cur.X - 1;
      }
      else if(dir == 2) {
        nx = cur.X * 2;
      }
      if(k == nx) {
        if(len >= cur.Y+1) {
          len = cur.Y+1;
          cnt++;
        }
      }
      if(nx < 0 || nx > 110000) {
        continue;
      }
      if(vis[nx] > 0) {
        continue;
      }
      q.push({nx,cur.Y+1});
    }
  }
  cout << len << "\n";
  cout << cnt;
}