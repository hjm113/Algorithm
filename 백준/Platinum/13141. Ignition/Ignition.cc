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
int adj[205][205];
vector<tuple<int,int,int>> rod;
int n, m, t;
int mx = 500000000;
int used[205];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      d[i][j] = mx;
      d[i][i] = 0;
    }
  }
  for(int i = 0; i < m; i++) {
    int s, e, l;
    cin >> s >> e >> l;
      d[s][e] = min(d[s][e], l);
      d[e][s] = min(d[e][s], l);
      adj[s][e] = max(adj[s][e], l);
      adj[e][s] = max(adj[e][s], l);
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  double mn = mx;
  for(int k = 1; k <= n; k++) {
    double sum = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        double rest = adj[i][j] - (d[k][i]-d[k][j]);
        sum = max(sum,rest/2+d[k][i]);
      }
    }
    mn = min(mn,sum);
  }
  printf("%0.1f",mn);
}