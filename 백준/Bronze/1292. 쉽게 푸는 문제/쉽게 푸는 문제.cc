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
int n, m;
int ary[1005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int cnt = 1;
  int out = 0;
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= i; j++) {
      ary[cnt] = i;
      if(cnt == 1000) {
        out = 1;
        break;
      }
      cnt++;
    }
    if(out == 1) {
      break;
    }
  }
  int ans = 0;
  for(int i = n; i <= m; i++) {
    ans += ary[i];
  }
  cout << ans;
}