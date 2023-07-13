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
using ll = long long;
#define X first
#define Y second
int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    queue<int> q;
    int d[1005] = {};
    int dp[1005] = {};
    vector<int> adj[1005] = {};
    int deg[1005] = {};
    int n, k, ans;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
      cin >> d[i];
    }
    for(int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      deg[y]++;
    }
    for(int i = 1; i <= n; i++) {
      if(deg[i] == 0) {
        q.push(i);
        dp[i] = d[i];
      }
    }
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : adj[cur]) {
        dp[nxt] = max(dp[nxt],dp[cur]+d[nxt]);
        deg[nxt]--;
        if(deg[nxt] == 0) {
          q.push(nxt);
        }
      }
    }
    cin >> ans;
    cout << dp[ans] << "\n";
  }
}