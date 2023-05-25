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
int e, s, m;
ll gcd(int x, int y) {
  if(y == 0) {
    return x;
  }
  else {
    return gcd(y,x%y);
  }
}
ll lcm(int x, int y) {
  return x / gcd(x,y) * y;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> e >> s >> m;
  int x = 15;
  int y = 28;
  int z = 19;
  int a = lcm(x,y);
  int end = lcm(a,z);
  if(e == x) {
    e = 0;
  }
  if(s == y) {
    s = 0;
  }
  if(m == z) {
    m = 0;
  }
  int ans = 0;
  for(int i = 1; i <= end; i++) {
    if(i % x == e && i % y == s && i % z == m) {
      ans = i;
    }
  }
  cout << ans;
}