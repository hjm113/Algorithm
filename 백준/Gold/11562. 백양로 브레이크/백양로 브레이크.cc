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
int d[255][255];
int used[255][255];
int n, m, k;
vector<string> vis;
map<string, int> mp;
int mx = 50000000;
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
    int a, b, dir;
    cin >> a >> b >> dir;
    if(dir == 1) {
      d[a][b] = min(d[a][b], 0);
      d[b][a] = min(d[b][a], 0);
    }
    else {
      d[a][b] = min(d[a][b], 0);
      d[b][a] = min(d[b][a], 1);
    }
  }
  for(int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
      }
    }
  }
  cin >> k;
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    cout << d[x][y] << "\n";
  }
}