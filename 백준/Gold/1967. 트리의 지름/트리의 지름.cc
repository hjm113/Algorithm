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
vector<pair<int,int>> adj[10005];
int p[10005];
int n, m;
int mx = 0;
queue<int> q;
int fst = 0;
int snd = 0;
void dfs(int cur, int sum) {
  int check = 0;
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt.X) {
      continue;
    }
    check = 1;
    p[nxt.X] = cur;
    sum += nxt.Y;
    dfs(nxt.X,sum);
    sum -= nxt.Y;
  }
  if(check == 0) {
    if(mx < sum) {
      mx = sum;
      fst = cur;
    }
    return;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
  dfs(1, 0);
  for(int i = 0; i < 10005; i++) {
    p[i] = 0;
  }
  mx = 0;
  dfs(fst,0);
  cout << mx;
}