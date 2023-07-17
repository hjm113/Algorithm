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
vector<pair<double,int>> adj[1005];
vector<pair<int,int>> coor;
int check[1005];
int conn[1005][1005];
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int n, m, k;
int mx = 0;
double sum = 0;
int same[1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    check[x] = 1;
  }
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
    adj[v].push_back({w,u});
  }
  for(int i = 1; i <= n; i++) {
    if(check[i] == 1) {
      for(auto nxt : adj[i]) {
        pq.push({nxt.X,i,nxt.Y});
      }
    }
  }
  int cnt = 0;
  while(cnt < n-k) {
    int cost, a, b;
    tie(cost,a,b) = pq.top();
    pq.pop();
    if(check[b] == 1) {
      continue;
    }
    check[b] = 1;
    sum += cost;
    for(auto nxt : adj[b]) {
      if(check[nxt.Y] == 1) {
        continue;
      }
      pq.push({nxt.X,b,nxt.Y});
    }
    cnt++;
  }
  cout << sum;
}