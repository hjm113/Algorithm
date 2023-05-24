#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int t, n, m, x, y;
int gcf(int x, int y) {
  if(y == 0) {
    return x;
  }
  return gcf(y,x%y);
}
int lcm(int x, int y) {
  return x / gcf(x,y)*y;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m >> x >> y;
    int l = lcm(n,m);
    if(m == y) {
      y = 0;
    }
    int ans = -1;
    for(int i = x; i <= l; i+=n) {
      if(i % m == y) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
}