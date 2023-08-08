#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int d[1005];
int pre[1005];
int ans[1005];
vector<pair<int,int>> adj[1005];
int mx = 20000000;
int mn = 0;
int n, m, en;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> en;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  for(int i = 1; i <= n; i++) {
    d[i] = mx;
  }
  d[en] = 0;
  pq.push({0,en});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) {
      continue;
    }
    for(auto nxt : adj[cur.Y]) {
      if(d[nxt.Y] > nxt.X+cur.X) {
        pre[nxt.Y] = cur.Y;
        d[nxt.Y] = nxt.X+cur.X;
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    ans[i] += d[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      d[j] = mx;
    }
    d[i] = 0;
    pq.push({0,i});
    while(!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if(d[cur.Y] != cur.X) {
        continue;
      }
      for(auto nxt : adj[cur.Y]) {
        if(d[nxt.Y] > nxt.X+cur.X) {
          pre[nxt.Y] = cur.Y;
          d[nxt.Y] = nxt.X+cur.X;
          pq.push({nxt.X+cur.X,nxt.Y});
        }
      }
    }
    ans[i] += d[en];
  }
  for(int i = 1; i <= n; i++) {
    if(ans[i] > mn) {
      mn = ans[i];
    }
  }
  cout << mn;
}