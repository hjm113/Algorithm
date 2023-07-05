#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;
#define X first
#define Y second

int n, m, k;
vector<int> adj[505];
int vis[505];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    vis[i] = -1;
  }
  queue<int> q;
  q.push(1);
  vis[1] = 0;
  int ans = 0;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
      if(vis[adj[cur][nxt]] > -1) {
        continue;
      }
      q.push(adj[cur][nxt]);
      vis[adj[cur][nxt]] = vis[cur] + 1;
      if(vis[adj[cur][nxt]] <= 2) {
        ans++;
      }
    }
  }
  cout << ans;
}