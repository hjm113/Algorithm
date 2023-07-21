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
int hmx[305][305];
int n, m, t;
int mx = 500000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      hmx[i][j] = mx;
    }
  }
  for(int i = 0; i < m; i++) {
    int u, v, h;
    cin >> u >> v >> h;
    hmx[u][v] = h;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        int h = max(hmx[i][k],hmx[k][j]);
        hmx[i][j] = min(h, hmx[i][j]);
      }
    }
  }
  for(int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    if(hmx[x][y] >= mx) {
      cout << -1 << "\n";
    }
    else {
      cout << hmx[x][y] << "\n";
    }
  }
}