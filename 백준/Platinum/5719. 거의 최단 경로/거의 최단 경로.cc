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
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
int n, m, st, en;
int mx = INT_MAX;
queue<int> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(1) {
    if(n == 0 || m == 0) {
      break;
    }
    cin >> st >> en;
    vector<pair<int,int>> adj[505] = {};
    int d[505] = {};
    vector <int> pre[505] = {};
    int check[505] = {};
    int lst[505][505] = {};
    for(int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      adj[u].push_back({p,v});
    }
    for(int i = 0; i <= n; i++) {
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
        if(d[nxt.Y] > cur.X+nxt.X) {
          d[nxt.Y] = cur.X+nxt.X;
          pre[nxt.Y].clear();
          pre[nxt.Y].push_back(cur.Y);
          pq.push({cur.X+nxt.X,nxt.Y});
        }
        if(d[nxt.Y] == cur.X+nxt.X) {
          pre[nxt.Y].push_back(cur.Y);
        }
      }
    }
    check[en] = 1;
    q.push(en);
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : pre[cur]) {
        if(lst[cur][nxt] > 0) {
          continue;
        }
        lst[cur][nxt] = 1;
        q.push(nxt);
      }
    }
    for(int i = 0; i <= n; i++) {
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
        if(lst[nxt.Y][cur.Y] == 1) {
          continue;
        }
        if(d[nxt.Y] > cur.X+nxt.X) {
          d[nxt.Y] = cur.X+nxt.X;
          pq.push({cur.X+nxt.X,nxt.Y});
        }
      }
    }
    if(d[en] == mx) {
      cout << -1 << "\n";
    }
    else {
      cout << d[en] << "\n";
    }
    cin >> n >> m;
  }
}