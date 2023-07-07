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
int n, m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int cnt = 0;
  while(n != 0) {
    cnt++;
    int ans = 0;
    vector<int> adj[505] = {};
    int vis[505] = {};
    int p[505] = {};
    queue<int> q;
    for(int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
      if(p[i] > 0) {
        continue;
      }
      q.push(i);
      int check = 0;
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
          if(p[cur] == nxt) {
            continue;
          }
          if(p[nxt] > 0) {
            check = 1;
            continue;
          }
          p[nxt] = cur;
          q.push(nxt);
        }
      }
      if(check == 0) {
        ans++;
      }
    }
    if(ans > 1) {
      cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";
    }
    else if(ans == 1) {
      cout << "Case " << cnt << ": There is one tree.\n";
    }
    else {
       cout << "Case " << cnt << ": No trees.\n";
    }
    cin >> n >> m;
  }
 
}