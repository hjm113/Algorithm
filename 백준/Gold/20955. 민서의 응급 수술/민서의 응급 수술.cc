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
using namespace std;
using ll = long long;
#define X first
#define Y second
vector<int> adj[100005];
int p[100005];
int n, m;
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int sum1 = -1;
  int sum2 = 0;
  for(int i = 1; i <= n; i++) {
    if(p[i] > 0) {
      continue;
    }
    sum1++;
    q.push(i);
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      int check = 0;
      for(auto nxt : adj[cur]) {
        if(p[cur] == nxt) {
          continue;
        }
        if(p[nxt] > 0) {
          sum2++;
          continue;
        }
        p[nxt] = cur;
        q.push(nxt);
      }
    }
  }
  int ans = sum1 + (sum2/2);
  cout << ans;
}