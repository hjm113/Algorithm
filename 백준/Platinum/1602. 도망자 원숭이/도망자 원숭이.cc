#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, q;
int mx = 200000000;
int d[505][505];
pair<int,int> dog[505];
int dmx[505][505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    dog[i] = {x,i};
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) {
        continue;
      }
      d[i][j] = mx;
    }
  }
  for(int i = 1; i <= m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    d[a][b] = min(d[a][b],t);
    d[b][a] = min(d[b][a],t);
    dmx[a][b] = max(dog[a].X,dog[b].X);
    dmx[b][a] = max(dog[a].X,dog[b].X);
  }
  sort(dog+1,dog+n+1);
  for(int w = 1; w <= n; w++) {
    int k = dog[w].Y;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) {
          continue;
        }
        if(d[i][j]+dmx[i][j] > d[i][k]+d[k][j]+max(dmx[i][k],dmx[k][j])) {
          d[i][j] = d[i][k]+d[k][j];
          dmx[i][j] = max(dmx[i][k],dmx[k][j]);
          //cout << k << " " << i << " " << j << " " << d[i][j] << " " << dmx[i][j] << "\n";
        }
      }
    }
  }
  //cout << dmx[1][3] << "\n\n";
  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    if(d[x][y] == mx) {
      cout << -1 << "\n";
      continue;
    }
    //cout << d[x][y] << " " << dmx[x][y] << " eeeee\n";
    cout << d[x][y]+dmx[x][y] << "\n";
  }
}