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
int lc[10005];
int rc[10005];
int minl[10005];
int maxl[10005];
int n, m;
queue<int> q;
int cnt = 1;
int lv = 1;
set<int> s;
int st = 0;
void dfs(int cur, int level) {
  if(lc[cur] != -1) {
    int nxtl = level+1;
    dfs(lc[cur],nxtl);
  }
  maxl[level] = max(maxl[level],cnt);
  minl[level] = min(minl[level],cnt);
  cnt++;
  if(rc[cur] != -1) {
    int nxtl = level+1;
    dfs(rc[cur],nxtl);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    lc[x] = y;
    rc[x] = z;
    s.insert(y);
    s.insert(z);
  }
  for(int i = 1; i <= n; i++) {
    if(s.find(i) == s.end()) {
      st = i;
      break;
    }
  }
  for(int i = 0; i < 10005; i++) {
    minl[i] = 10000000;
  }
  dfs(st, lv);
  int mx = 0;
  int ele = 0;
  for(int i = 1; i <= n; i++) {
    if(mx < maxl[i]-minl[i]+1) {
      mx = maxl[i]-minl[i]+1;
      ele = i;
    }
  }
  cout << ele << " " << mx;
}