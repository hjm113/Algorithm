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
int n, m;
vector<pair<int,int>> adj[105];
int deg[105];
int ans[105];
int check[105];
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y,z});
    deg[y]++;
    check[x] = 1;
  }
  /*
  cout << "\n";
  */
  ans[n] = 1;
  q.push(n);
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      deg[nxt.X]--;
      ans[nxt.X] += ans[cur]*nxt.Y;
      if(deg[nxt.X] == 0) {
        /*
        cout << nxt.X << " " << cur << "\n";
        */
        q.push(nxt.X);
      }
    }
  }
  /*
  for(int i = 1; i <= n; i++) {
    cout << deg[i] << " ";
  }
  cout << "\n";
  */
  for(int i = 1; i <= n; i++) {
    if(check[i] == 1) {
      continue;
    }
    cout << i << " " << ans[i];
    cout << "\n";
  }
}