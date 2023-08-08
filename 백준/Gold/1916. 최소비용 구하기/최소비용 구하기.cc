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
int d[1005];
vector<pair<int,int>> adj[1005];
int mx = 2000000000;
int n, m, st, en;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
  }
  cin >> st >> en;
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
  cout << d[en];
}