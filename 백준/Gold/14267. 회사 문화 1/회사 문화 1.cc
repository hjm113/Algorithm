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
vector<int> adj[100005];
int p[100005];
int w[100005];
int ans[100005];
int n, m;
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(x != -1) {
      adj[x].push_back(i);
      adj[i].push_back(x);
    }
  }
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    w[x] += y;
  }
  q.push(1);
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    ans[cur] += w[cur];
    for(auto nxt : adj[cur]) {
      if(p[cur] == nxt) {
        continue;
      }
      ans[nxt] += ans[cur];
      p[nxt] = cur;
      q.push(nxt);
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}