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
priority_queue< tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>> > pq;
vector<pair<int,int>> adj[1005];
ll d[1005][1005];
int n, m, st, en, k;
ll mx = LLONG_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  cin >> st >> en;
  for(int i = 0; i < m; i++) {
    int u, v, p;
    cin >> u >> v >> p;
    adj[u].push_back({p,v});
    adj[v].push_back({p,u});
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      d[i][j] = mx;
    }
  }
  d[0][st] = 0;
  pq.push({0,st,0});
  while(!pq.empty()) {
    ll c,b,p;
    tie(c,b,p) = pq.top();
    pq.pop();
    if(d[p][b] != c) {
      continue;
    }
    for(auto nxt : adj[b]) {
      if(d[p+1][nxt.Y] > nxt.X+c) {
        d[p+1][nxt.Y] = nxt.X+c;
        pq.push({nxt.X+c,nxt.Y,p+1});
      }
    }
  }
  ll ans1 = mx;
  for(int i = 1; i <= n; i++) {
    if(d[i][en] == mx) {
      continue;
    }
    if(ans1 > d[i][en]) {
      ans1 = d[i][en];
    }
  }
  cout << ans1 << "\n";
  for(int i = 0; i < k; i++) {
    int tax;
    cin >> tax; 
    ll ans = mx;
    for(int i = 1; i <= n; i++) {
      if(d[i][en] == mx) {
        continue;
      }
      if(ans > d[i][en] + tax*i) {
        ans = d[i][en] + tax*i;
      }
      d[i][en] += tax*i;
    }
    cout << ans << "\n";
  }
  
}