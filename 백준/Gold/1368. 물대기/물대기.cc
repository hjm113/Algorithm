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
int n;
vector<pair<int,int>> adj[305];
int check[305];
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int cost;
    cin >> cost;
    adj[n+1].push_back({cost,i});
    adj[i].push_back({cost,n+1});
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int cost;
      cin >> cost;
      if(i != j) {
        adj[i].push_back({cost,j});
      }
    }
  }
  check[1] = 1;
  for(auto nxt : adj[1]) {
    pq.push({nxt.X,1,nxt.Y});
  }
  int cnt = 0;
  int ans = 0;
  while(cnt < n) {
    int cost,a,b;
    tie(cost,a,b) = pq.top();
    pq.pop();
    if(check[b] == 1) {
      continue;
    }
    check[b] = 1;
    ans += cost;
    for(auto nxt : adj[b]) {
      if(check[nxt.Y] == 1) {
        continue;
      }
      pq.push({nxt.X,b,nxt.Y});
    }
    cnt++;
  }
  cout << ans;
}