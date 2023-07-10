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
int n, r, nq;
vector<int> adj[1005];
int p[1005];
int lc[100000];
int rc[100000];
int cnt = 0;
int en = 0;
void dfs1(int cur) {
  if(lc[cur] > 0) {
    dfs1(lc[cur]);
  }
  en = cur;
  if(rc[cur] > 0) {
    dfs1(rc[cur]);
  }
}
void dfs2(int cur) {
  int check = 0;
  if(lc[cur] > 0) {
    cnt++;
    //cout << cur << "\n";
    dfs2(lc[cur]);
  }
  if(rc[cur] > 0) {
    cnt++;
    //cout << cur << "\n";
    dfs2(rc[cur]);
  }
  if(cur == en) {
    cout << cnt;
  }
  cnt++;
  //cout << cur << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    lc[x] = y;
    rc[x] = z;
  }
  dfs1(1);
  dfs2(1);
}