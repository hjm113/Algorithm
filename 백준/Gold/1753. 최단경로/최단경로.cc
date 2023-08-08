#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int d[20005];
vector<pair<int,int>> adj[20005];
int mx = 200000000;
int n, m;
int st;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> st;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  for(int i = 1; i <= n; i++) {
    d[i] = mx;
  }
  d[st] = 0;
  pq.push({0,st});
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
  for(int i = 1; i <= n; i++) {
    if(d[i] == mx) {
      cout << "INF" << "\n";
    }
    else {
      cout << d[i] << "\n";
    }
  }
}