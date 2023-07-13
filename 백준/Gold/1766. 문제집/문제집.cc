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
vector<int> adj[32005];
int deg[32005];
vector<int> ans;
int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
int used[32005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    deg[y]++;
  }
  for(int i = 1; i <= n; i++) {
    if(deg[i] == 0) {
      pq.push(i);
    }
  }
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    cout << cur << " ";
    for(auto nxt : adj[cur]) {
      deg[nxt]--;
      if(deg[nxt] == 0) {
        pq.push(nxt);
      }
    }
  }
}