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
vector<int> adj[10005];
int check[10005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--) {
    int x, y;
    cin >> x >> y;
    adj[y].push_back(x);
  }
  
  for(int i = 1; i <= n; i++) {
    int vis[10005] = {};
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int sum = 0;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int nxt = 0; nxt < adj[cur].size(); nxt++) {
        if(vis[adj[cur][nxt]] > 0) {
          continue;
        }
        q.push(adj[cur][nxt]);
        vis[adj[cur][nxt]] = 1;
        sum++;
      }
    }
    check[i] = sum;
  }
  int mx = *max_element(check+1,check+n+1);
  
  for(int i = 1; i <= n; i++) {
    if(check[i] == mx) {
      cout << i << " ";
    }
  }
}