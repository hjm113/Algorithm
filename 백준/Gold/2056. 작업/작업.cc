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
vector<int> adj[10005];
int deg[10005];
int t[10005];
int dp[10005];
int n;
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int m;
    cin >> t[i] >> m;
    for(int j = 0; j < m; j++) {
      int done;
      cin >> done;
      adj[done].push_back(i);
      deg[i]++;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(deg[i] == 0) {
      q.push(i);
      dp[i] = t[i];
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      dp[nxt] = max(dp[nxt],dp[cur]+t[nxt]);
      deg[nxt]--;
      if(deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }
  cout << *max_element(dp+1,dp+n+1);
}