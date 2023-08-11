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
priority_queue< pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
vector<pair<ll,ll>> adj[100005];
ll dst[100005];
ll den[100005];
ll mst[100005];
ll men[100005];
int n, m, a, b;
ll c;
ll mx = 9000000000000000;
ll ans = 9000000000000000;
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> a >> b >> c;
  for(int i = 0; i < m; i++) {
    int st, en;
    ll mon;
    cin >> st >> en >> mon;
    adj[st].push_back({mon,en});
    adj[en].push_back({mon,st});
  }
  for(int i = 1; i <= n; i++) {
    den[i] = mx;
    dst[i] = mx;
  }
  dst[a] = 0;
  mst[a] = 0;
  pq.push({0,a});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(dst[cur.Y] != cur.X) {
      continue;
    }
    for(auto nxt : adj[cur.Y]) {
      if(dst[nxt.Y] > nxt.X+cur.X) {
        dst[nxt.Y] = nxt.X+cur.X;
        mst[nxt.Y] = max(nxt.X,mst[cur.Y]);
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  den[b] = 0;
  men[b] = 0;
  pq.push({0,b});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(den[cur.Y] != cur.X) {
      continue;
    }
    for(auto nxt : adj[cur.Y]) {
      if(den[nxt.Y] > nxt.X+cur.X) {
        den[nxt.Y] = nxt.X+cur.X;
        men[nxt.Y] = max(nxt.X,men[cur.Y]);
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(dst[i]+den[i] <= c) {
      ll over = max(men[i],mst[i]);
      if(ans > over) {
        ans = over;
      }
    }
  }
  if(ans == mx) {
    cout << -1;
    return 0;
  }
  cout << ans;
}