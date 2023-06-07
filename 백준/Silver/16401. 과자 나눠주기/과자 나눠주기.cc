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
int ary[1000005];
int n, m;
int solve(int x) {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (ary[i]/x);
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  int st = 1;
  int en = 1000000000;
  int check = 0;
  while(st < en) {
    int mid = (st+en+1)/2;
    if(solve(mid) >= m) {
      st = mid;
    }
    else if(solve(mid) < m) {
      en = mid - 1;
    }
  }
  if(st == 1) {
    if(solve(st) >= m) {
      cout << st;
      return 0;
    }
    else {
      cout << 0;
      return 0;
    }
  }
  cout << st;
}