#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, q;
int d[305][305][305];
int mx = 200000000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      d[i][j][0] = mx;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if(i==j) {
        d[i][j][0] = 0;
      }
      if(x == 0) {
        continue;
      }
      d[i][j][0] = min(d[i][j][0], x);
    }
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(d[i][j][k-1] > d[i][k][k-1]+d[k][j][k-1]) {
          d[i][j][k] = d[i][k][k-1]+d[k][j][k-1];
        }
        else {
          d[i][j][k] = d[i][j][k-1];
        }
      }
    }
  }
  for(int i = 0 ; i < q; i++) {
    int c, s, e;
    cin >> c >> s >> e;
    if(d[s][e][c-1] == mx) {
      cout << -1 << "\n";
    }
    else {
      cout << d[s][e][c-1] << "\n";
    }
  }
}