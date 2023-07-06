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
vector<int> heavy[105];
vector<int> light[105];
int ans = 0;
int n, m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    heavy[x].push_back(y);
    light[y].push_back(x);
  }
  
  for(int i = 1; i <=n; i++) {
    int vis[105] = {};
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int sumh = 0;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : heavy[cur]) {
        if(vis[nxt] == 1) {
          continue;
        }
        q.push(nxt);
        vis[nxt] = 1;
        sumh++;
      }
    }
    if((n+1)/2 <= sumh) {
      ans++;
    }
  }
  for(int i = 1; i <=n; i++) {
    int vis[105] = {};
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int suml = 0;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : light[cur]) {
        if(vis[nxt] == 1) {
          continue;
        }
        q.push(nxt);
        vis[nxt] = 1;
        suml++;
      }
    }
    if((n+1)/2 <= suml) {
      ans++;
    }
  }
  cout << ans;
}