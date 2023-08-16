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
vector<pair<int,int>> adj[200005];
int d[200005];
priority_queue<int, vector<int>, greater<int>> pre[200005];
int check[200005];
int ans = 0;
int n, m, st, en;
int mx = INT_MAX-1;
queue<int> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, p;
    cin >> u >> v >> p;
    adj[u].push_back({p,v});
    adj[v].push_back({p,u});
  }
  cin >> st >> en;
  for(int i = 0; i <= n; i++) {
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
      if(d[nxt.Y] > cur.X+nxt.X) {
        d[nxt.Y] = cur.X+nxt.X;
        pre[nxt.Y] = priority_queue<int, vector<int>, greater<int>> ();
        pre[nxt.Y].push(cur.Y);
        pq.push({cur.X+nxt.X,nxt.Y});
      }
      else if(d[nxt.Y] == cur.X+nxt.X) {
        pre[nxt.Y].push(cur.Y);
      }
    }
  }
  ans += d[st];
  int fst = st;
  while(1) {
    check[fst] = 1;;
    if(fst == en) {
      break;
    }
    fst = pre[fst].top();
  }
  check[st] = 0;
  check[en] = 0;
  
  for(int i = 0; i <= n; i++) {
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
      if(check[nxt.Y] == 1) {
        continue;
      }
      if(d[nxt.Y] > cur.X+nxt.X) {
        d[nxt.Y] = cur.X+nxt.X;
        pq.push({cur.X+nxt.X,nxt.Y});
      }
    }
  }
  ans += d[st];
  cout << ans;
}