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
vector<int> adj[20005];
int check[20005];
int vis[20005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
      if(vis[adj[cur][nxt]] > 0) {
        continue;
      }
      q.push(adj[cur][nxt]);
      vis[adj[cur][nxt]] = vis[cur] + 1;
      check[adj[cur][nxt]] = vis[cur];
    }
  }
  int mx = *max_element(check+1,check+n+1);
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(check[i] == mx) {
      if(cnt == 0) {
        cout << i << " ";
      }
      cnt++;
    }
  }
  cout << mx << " " << cnt << "\n";
}