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
int func1(int x) {
  int cnt = 0;
  for(ll i = 2; i <= x; i*=2) {
    cnt += x/i;
  }
  return cnt;
}
int func2(int x) {
  int cnt = 0;
  for(ll i = 5; i <= x; i*=5) {
    cnt += x/i;
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int ans2 = 0;
  int ans5 = 0;
  int a = n;
  int b = m;
  int c = n - m;
  int a2 = func1(a);
  int a5 = func2(a);
  int b2 = func1(b);
  int b5 = func2(b);
  int c2 = func1(c);
  int c5 = func2(c);
  ans2 = a2-b2-c2;
  ans5 = a5-b5-c5;
  cout << min(ans2,ans5);
}