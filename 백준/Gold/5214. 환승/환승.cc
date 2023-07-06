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
vector<int> adj[101005];
int vis[101005];
int n, k, m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m; 
  for(int i = 1; i <= m; i++) {
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      adj[n+i].push_back(x);
      adj[x].push_back(n+i);
    }
  }
  /*
  for(int i = 0; i <= n+1000; i++) {
    vis[i] = -1;
  }
  */
  queue<int> q;
  vis[1] = 1;
  q.push(1);
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      if(vis[nxt] > 0) {
        continue;
      }
      vis[nxt] = vis[cur] + 1;
      q.push(nxt);
    }
  }
  if(vis[n] == 0) {
    cout << -1;
    return 0;
  }
  cout << vis[n]/2+1;
}