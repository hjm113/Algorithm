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
vector<pair<int,int>> adj[100005];
int check[100005];
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int n, m;
int mx = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;

    adj[x].push_back({z,y});
    adj[y].push_back({z,x});
  }
  int cnt = 0;
  ll ans = 0; 
  check[1] = 1;
  for(auto nxt : adj[1]) {
    pq.push({nxt.X,1,nxt.Y});
  }
  while(cnt < n-1) {
    int cost, a, b;
    tie(cost,a,b) = pq.top();
    pq.pop();
    if(check[b] == 1) {
      continue;
    }
    check[b] = 1;
    ans += cost;
    mx = max(mx,cost);
    for(auto nxt : adj[b]) {
      if(check[nxt.Y] == 1) {
        continue;
      }
      pq.push({nxt.X,b,nxt.Y});
    }
    cnt++;
  }
  cout << ans-mx;
}