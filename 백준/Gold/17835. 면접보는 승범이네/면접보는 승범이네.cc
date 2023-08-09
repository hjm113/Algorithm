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
ll d[100005];
vector<pair<ll,ll>> adj[100005];
ll mx = 2000000000000;
int n, m, k;
ll st = 0;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    adj[b].push_back({c,a});
  }
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    adj[st].push_back({0,x});
  }
  for(int i = 1; i <= n; i++) {
    d[i] = mx;
  }
  pq.push({0,st});
  d[st] = 0;
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) {
      continue;
    }
    for(auto nxt : adj[cur.Y]) {
      if(d[nxt.Y] > nxt.X+cur.X) {
        d[nxt.Y] = nxt.X+cur.X;
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  ll ans = 0;
  ll idx = 0;
  for(int i = 1; i <= n; i++) {
    if(ans < d[i]) {
      ans = d[i];
      idx = i;
    }
  }
  cout << idx << "\n" << ans;
}