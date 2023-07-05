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
vector<int> adj[1005];
int visbfs[1005];
int visdfs[1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    sort(adj[i].rbegin(),adj[i].rend());
  }
  stack<int> s;
  s.push(k);
  while(!s.empty()) {
    auto cur = s.top();
    s.pop();
    if(visdfs[cur] == 1) {
      continue;
    }
    visdfs[cur] = 1;
    cout << cur << " ";
    for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
      s.push(adj[cur][nxt]);
    }
  }
  cout << "\n";
    for(int i = 1; i <= n; i++) {
    sort(adj[i].begin(),adj[i].end());
  }
  queue<int> q;
  visbfs[k] = 1;
  q.push(k);
  cout << k << " ";
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
      if(visbfs[adj[cur][nxt]] == 1) {
        continue;
      }
      visbfs[adj[cur][nxt]] = 1;
      q.push(adj[cur][nxt]);
      cout << adj[cur][nxt] << " ";
    }
  }
  cout << "\n";
}