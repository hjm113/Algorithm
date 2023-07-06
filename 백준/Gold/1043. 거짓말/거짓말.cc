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
vector<int> adj[55];
vector<int> gr[55];
vector<int> intel;
int check[55];
int ans = 0;
int n, m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++) {
    int x;
    cin >> x;
    intel.push_back(x);
  }
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    for(int j = 0; j < x; j++) {
      int y;
      cin >> y;
      gr[i].push_back(y);
    }
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < gr[i].size(); j++) {
      for(int k = 0; k < gr[i].size(); k++) {
        if(j == k) {
           continue;
        }
        adj[gr[i][j]].push_back(gr[i][k]);
      }
    }
  }
  for(int i = 0; i < num; i++) {
    queue<int> q;
    int vis[55] = {};
    check[intel[i]] = 1;
    q.push(intel[i]);
    vis[intel[i]] = 1;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : adj[cur]) {
        if(vis[nxt] == 1) {
          continue;
        }
        q.push(nxt);
        vis[nxt] = 1;
        check[nxt] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    int out = 0;
    for(int j = 0; j < gr[i].size(); j++) {
      if(check[gr[i][j]] == 1) {
        out = 1;
        break;
      }
    }
    if(out == 0) {
      ans++;
    }
  }
  cout << ans;
}