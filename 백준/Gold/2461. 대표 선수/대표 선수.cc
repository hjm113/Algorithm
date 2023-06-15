#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
#define X first
#define Y second
int ary[1005][1005];
int idx[1005];
int n, m;
int ans = 2000000000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> ary[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    sort(ary[i],ary[i]+m);
  }
  
  int check = 0;
  int cnt = 0;
  while(1) {
    int mn = 2000000000;
    int mx = 0;
    int change = 0;
    for(int i = 0; i < n; i++) {
      if(mn > ary[i][idx[i]]) {
        mn = ary[i][idx[i]];
        change = i;
      }
      if(mx < ary[i][idx[i]]) {
        mx = ary[i][idx[i]];
      }
    }
    //cout << mx << " " << mn << " " << mx-mn << " sdfsdf\n";
    ans = min(ans,mx-mn);
    idx[change]++;
    if(idx[change] == m) {
      break;
    }
  }
  cout << ans;
}
