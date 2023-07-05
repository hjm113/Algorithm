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
vector<int> adj[55];
int check[55];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(1) {
    int x, y;
    cin >> x >> y;
    if(x == -1) {
      break;
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  for(int i = 1; i <= n; i++) {
    int vis[55] = {};
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
        if(vis[adj[cur][nxt]] > 0) {
          continue;
        }
        q.push(adj[cur][nxt]);
        vis[adj[cur][nxt]] = vis[cur] + 1;
        check[i] = vis[cur];
      }
    }
  }
  int mn = *min_element(check+1,check+n+1);
  cout << mn << " ";
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(check[i] == mn) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  for(int i = 1; i <= n; i++) {
    if(check[i] == mn) {
      cout << i << " ";
    }
  }
}