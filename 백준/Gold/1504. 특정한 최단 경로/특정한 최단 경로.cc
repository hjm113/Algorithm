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
int d[805];
vector<pair<int,int>> adj[805];
int mx = 2000000000;
int n, m, fst, snd;
vector<int> order1;
vector<int> order2;
long long ans1 = 0;
long long ans2 = 0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  cin >> fst >> snd;
  order1.push_back(1);
  order1.push_back(fst);
  order1.push_back(snd);
  order1.push_back(n);
  for(int i = 0; i < order1.size()-1; i++) {
    for(int j = 1; j <= n; j++) {
      d[j] = mx;
    }
    d[order1[i]] = 0;
    pq.push({0,order1[i]});
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
    ans1 += d[order1[i+1]];
  }
  order2.push_back(1);
  order2.push_back(snd);
  order2.push_back(fst);
  order2.push_back(n);
  for(int i = 0; i < order2.size()-1; i++) {
    for(int j = 1; j <= n; j++) {
      d[j] = mx;
    }
    d[order2[i]] = 0;
    pq.push({0,order2[i]});
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
    ans2 += d[order2[i+1]];
  }
  long long ret = 0;
  if(ans1 < ans2) {
    ret = ans1;
  }
  else {
    ret = ans2;
  }
  if(ret >= mx) {
    cout << -1;
    return 0;
  }
  cout << ret;
}