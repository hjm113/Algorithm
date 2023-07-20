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
int d[205][205];
int nxt[205][205];
int n, m;
int mx = 500000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      d[i][j] = mx;
    }
  }
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b],c);
    nxt[a][b] = b;
    d[b][a] = min(d[b][a],c);
    nxt[b][a] = a;
  }
  for(int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(d[i][j] > d[i][k]+d[k][j]) {
          d[i][j] = d[i][k]+d[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(nxt[i][j] == 0) {
        cout << "-" << " ";
        continue;
      }
      cout << nxt[i][j] << " ";
    }
    cout << "\n";
  }
}