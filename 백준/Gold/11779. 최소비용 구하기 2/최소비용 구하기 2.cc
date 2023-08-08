#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int d[1005];
int pre[1005];
vector<int> ans;
vector<pair<int,int>> adj[1005];
int mx = 20000000;
int n, m, st, en;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  cin >> st;
  cin >> en;
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
        pre[nxt.Y] = cur.Y;
        d[nxt.Y] = nxt.X+cur.X;
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  cout << d[en] << "\n";
  while(1) {
    ans.push_back(en);
    if(en == st) {
      break;
    }
    en = pre[en];
  }
  cout << ans.size() << "\n";
  for(int i = ans.size()-1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}