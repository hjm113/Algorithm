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
priority_queue< tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
vector<pair<ll,ll>> adj[10005];
ll dp[25][10005];
int n, m, k;
ll mx = LLONG_MAX;
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  for(int i = 0; i <= 20; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = mx;
    }
  }
  dp[0][1] = 0;
  pq.push({0,1,0});
  while(!pq.empty()) {
    ll c,b,r;
    tie(c,b,r) = pq.top();
    pq.pop();
    if(dp[r][b] != c) {
      continue;
    }
    for(auto nxt : adj[b]) {
      if(dp[r][nxt.Y] > nxt.X+c) {
        dp[r][nxt.Y] = nxt.X+c;
        pq.push({nxt.X+c,nxt.Y,r});
      }
      if(r+1 <= k && dp[r+1][nxt.Y] > c) {
        dp[r+1][nxt.Y] = c;
        pq.push({c,nxt.Y,r+1});
      }
    }
  }
  for(int i = 0; i <= k; i++) {
    if(mx > dp[i][n]) {
      mx = dp[i][n];
    }
  }
  cout << mx;
}