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
int n, r, nq;
vector<int> adj[100005];
vector<int> par[100005];
int p[100005];
queue<int> q;
int dp[100005];

int dfs(int cur) {
  int check = 0;
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt) {
      continue;
    }
    check = 1;
    p[nxt] = cur;
    dp[cur] += dfs(nxt);
  }
  if(check == 0) {
    dp[cur]++;
    return dp[cur];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r >> nq;
  for(int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(r);
  for(int i = 0; i < nq; i++) {
    int x;
    cin >> x;
    cout << dp[x] << "\n";
  }
}