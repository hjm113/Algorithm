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
int ary[100005];
int m, n;
vector<int> num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  int ans1 = 100000000;
  int ans2 = 100000000;
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(ary,ary+n,-ary[i]) - ary;
    if(idx != i && idx < n && abs(ary[i]+ary[idx]) < abs(ans1+ans2)) {
      ans1 = ary[i];
      ans2 = ary[idx];
    }
    if(idx+1 != i && idx+1 < n && abs(ary[i]+ary[idx+1]) < abs(ans1+ans2)) {
      ans1 = ary[i];
      ans2 = ary[idx+1];
    }
    if(idx-1 != i && idx-1 > 0 && abs(ary[i]+ary[idx-1]) < abs(ans1+ans2)) {
      ans1 = ary[i];
      ans2 = ary[idx-1];
    }
  }
  cout << ans1 + ans2;
}