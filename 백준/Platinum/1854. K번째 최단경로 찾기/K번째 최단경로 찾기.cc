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
vector<pair<int,int>> adj[10005];
priority_queue<int> d[1005];
int n, m, k;
int mx = INT_MAX;
vector<ll> ans[1005];
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
  }
  pq.push({0,1});
  d[1].push(0);
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    for(auto nxt : adj[cur.Y]) {
      if(d[nxt.Y].size() < k) {
        d[nxt.Y].push(nxt.X+cur.X);
        pq.push({nxt.X+cur.X,nxt.Y});
      }
      else {
        if(d[nxt.Y].top() > nxt.X+cur.X) {
          d[nxt.Y].pop();
          d[nxt.Y].push(nxt.X+cur.X);
          pq.push({nxt.X+cur.X,nxt.Y});
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(d[i].size() < k) {
      cout << -1 << "\n";
    }
    else {
      cout << d[i].top() << "\n";
    }
  }
}