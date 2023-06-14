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
int n, m, l;
int ary[55];
int solve(int x) {
  int ans = 0;
  for(int i = 1; i <= n+1; i++) {
    int dist = ary[i]-ary[i-1];
    int a = dist/x;
    int b = dist%x;
    if(b > 0) {
      a++;
    }
    ans += (a-1);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> l;
  ary[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> ary[i];
  }
  ary[n+1] = l;
  int st = 1;
  int en = l;
  sort(ary,ary+n+2);
  while(st < en) {
    int mid = (st+en)/2;
    if(solve(mid) > m) {
      st = mid+1;
    }
    else if(solve(mid) <= m) {
      en = mid;
    }
  }
  cout << st;
}