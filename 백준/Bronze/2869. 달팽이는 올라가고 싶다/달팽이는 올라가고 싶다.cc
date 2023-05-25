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
int a, b, v;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> v;
  int res = 0;
  int ans = v - a;
  if(ans % (a-b) == 0) {
    res = 1 + (ans/(a-b));
    cout << res;
    return 0;
  }
  else {
    res = 2 + (ans/(a-b));
    cout << res;
    return 0;
  }
}