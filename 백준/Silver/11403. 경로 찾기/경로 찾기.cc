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
int adj[105][105];
int check[105][105];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> adj[i][j];
    }
  }
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    int vis[105] = {};
    vis[i] = 1;
    q.push(i);
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int nxt = 1; nxt <= n; nxt++) {
        if(adj[cur][nxt] == 1) {
          if(vis[nxt] == 1) {
            if(nxt == i) {
              check[i][nxt] = 1;
            }
            continue;
          }
          vis[nxt] = 1;
          q.push(nxt);
          check[i][nxt] = 1;
        }
      }
    }
  }
  for(int j = 1; j <= n; j++) {
    for(int k = 1; k <= n; k++) {
      cout << check[j][k] << " ";
    }
    cout << "\n";
  }
}