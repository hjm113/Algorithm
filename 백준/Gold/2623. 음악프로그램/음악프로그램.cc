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
vector<int> adj[1005];
int deg[1005];
int n, m;
queue<int> q;
vector<int> ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    vector<int> asi;
    int x, fst;
    cin >> x >> fst;
    for(int j = 1; j < x; j++) {
      int y;
      cin >> y;
      deg[y]++;
      adj[fst].push_back(y);
      fst = y;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    ans.push_back(cur);
    for(auto nxt : adj[cur]) {
      deg[nxt]--;
      if(deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }
  if(ans.size() != n) {
    cout << 0;
    return 0;
  }
  for(auto ele : ans) {
    cout << ele << "\n";
  }
}