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
using namespace std;
using ll = long long;
#define X first
#define Y second
vector<int> adj[1000005];
int p[1000005];
int check[1000005];
int dp[1000005][3];
int n, m;
queue<int> q;
void dfs(int cur) {
  dp[cur][1] = 1;
  for(auto nxt : adj[cur]) {
    if(p[nxt] == cur) {
      continue;
    }
    p[cur] = nxt;
    dfs(nxt);
    dp[cur][0] += dp[nxt][1];
    dp[cur][1] += min(dp[nxt][1],dp[nxt][0]);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  cout << min(dp[1][1],dp[1][0]);
}