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
vector<pair<double,int>> adj[100005];
vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int n;
int check[100005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int xa, ya, za;
    cin >> xa >> ya >> za;
    x.push_back({xa,i});
    y.push_back({ya,i});
    z.push_back({za,i});
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  sort(z.begin(),z.end());
  for(int i = 0; i < n-1; i++) {
    adj[x[i].Y].push_back({abs(x[i].X-x[i+1].X),x[i+1].Y});
    adj[x[i+1].Y].push_back({abs(x[i].X-x[i+1].X),x[i].Y});
    adj[y[i].Y].push_back({abs(y[i].X-y[i+1].X),y[i+1].Y});
    adj[y[i+1].Y].push_back({abs(y[i].X-y[i+1].X),y[i].Y});
    adj[z[i].Y].push_back({abs(z[i].X-z[i+1].X),z[i+1].Y});
    adj[z[i+1].Y].push_back({abs(z[i].X-z[i+1].X),z[i].Y});
  }
  check[1] = 1;
  int cnt = 0;
  int ans = 0;
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