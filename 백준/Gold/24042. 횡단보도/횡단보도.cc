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
int n, m;
ll mx = 9000000000000;
ll d[100005];
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back({i,b});
    adj[b].push_back({i,a});
  }
  for(int i = 1; i <= n; i++) {
    d[i] = mx;
  }
  d[1] = 0;
  pq.push({0,1});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) {
      continue;
    }
    for(auto nxt : adj[cur.Y]) {
      ll used = cur.X / m;
      if(cur.X % m > nxt.X) {
        used++;
      }
      ll t = (m * used) + nxt.X + 1;
      if(d[nxt.Y] > t) {
        d[nxt.Y] = t;
        pq.push({t, nxt.Y});
      }
    }
  }
  cout << d[n] << "\n";
}