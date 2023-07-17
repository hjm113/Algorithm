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
priority_queue< tuple<double,int,int>, vector<tuple<double,int,int>>, greater<tuple<double,int,int>> > pq;
int n, m;
int mx = 0;
double sum = 0;
int same[1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    ll x1, y1;
    cin >> x1 >> y1;
    for(int j = 0; j < coor.size(); j++) {
      ll x2 = coor[j].X;
      ll y2 = coor[j].Y;
      ll ansx = (x1-x2)*(x1-x2);
      ll ansy = (y1-y2)*(y1-y2);
      double ans = sqrt(ansx+ansy);
      adj[i].push_back({ans,j+1});
      adj[j+1].push_back({ans,i});
    }
    coor.push_back({x1,y1});
  }
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < adj[x].size(); i++) {
      if(adj[x][i].Y == y) {
        adj[x][i].X = 0;
      }
    }
    for(int i = 0; i < adj[y].size(); i++) {
      if(adj[y][i].Y == x) {
        adj[y][i].X = 0;
      }
    }
  }
  check[1] = 1;
  for(auto nxt : adj[1]) {
    pq.push({nxt.X,1,nxt.Y});
  }
  int count = 0;
  while(cnt < n-1) {
    double cost;
    int a, b;
    
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
  printf("%0.2f",sum);
}