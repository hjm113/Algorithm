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
ll ary[200005];
int n, c;
int solve(int len) {
  int idx = 0;
  int cnt = 0;
  while(idx < n) {
    idx = lower_bound(ary,ary+n,ary[idx]+len) - ary;
    cnt++;
  }
  return cnt >= c;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  int st = 0;
  int en = 1000000000;
  while(st < en) {
    int mid = (st+en+1)/2;
    if(solve(mid)) {
      st = mid;
    }
    else {
      en = mid - 1;
    }
  }
  cout << st;
}