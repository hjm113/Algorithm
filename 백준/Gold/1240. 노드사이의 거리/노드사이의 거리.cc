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
vector<int> adj[1005];
int p[1005];
int dist[1005][1005];

void dfs(int cur, int f, int sum) {
  if(cur == f) {
    cout << sum << "\n";
    return;
  }
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt) {
      continue;
    }
    p[nxt] = cur;
    dfs(nxt, f, sum+dist[cur][nxt]);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> nq;
  for(int i = 0; i < n-1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back(y);
    adj[y].push_back(x);
    dist[x][y] = z;
    dist[y][x] = z;
  }
 
  for(int i = 0; i < nq; i++) {
    int s, e;
    cin >> s >> e;
    for(int j = 0; j <= 1000; j++) {
      p[j] = 0;
    } 
    dfs(s, e, 0);
  }
}