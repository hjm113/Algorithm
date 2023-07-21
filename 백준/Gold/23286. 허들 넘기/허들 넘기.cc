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
using ll = long long;
#define X first
#define Y second
int d[305][305];
vector<int> height[305][305];
int hmx[305][305];
int n, m, t;
int mx = 500000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      d[i][j] = mx;
      hmx[i][j] = mx;
    }
  }
  for(int i = 0; i < m; i++) {
    int u, v, h;
    cin >> u >> v >> h;
    d[u][v] = 0;
    hmx[u][v] = h;
    height[u][v].push_back(h);
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) {
          continue;
        }
        if(d[i][j] >= d[i][k]+d[k][j] && d[i][k]+d[k][j] < mx) {
          d[i][j] = d[i][k]+d[k][j];
          int h = max(hmx[i][k],hmx[k][j]);
          hmx[i][j] = min(h, hmx[i][j]);
          height[i][j].push_back(hmx[i][j]);
        }
      }
    }
  }
  for(int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    if(height[x][y].size() > 0) {
      cout << *min_element(height[x][y].begin(),height[x][y].end()) << "\n";;
    }
    else {
      cout << -1 << "\n";
    }
    
  }
}