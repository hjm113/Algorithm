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
ll ary[5005];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  ll ans1 = 1000000005;
  ll ans2 = 1000000005;
  ll ans3 = 1000000005;
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      int idx = lower_bound(ary+j+1,ary+n,-(ary[i]+ary[j])) - ary;
      if(idx != i && idx != j && idx < n && abs(ary[i]+ary[j]+ary[idx]) < abs(ans1+ans2+ans3)) {
        ans1 = ary[i];
        ans2 = ary[j];
        ans3 = ary[idx];
      }
      if(idx+1 != i && idx+1 != j && idx+1 < n && abs(ary[i]+ary[j]+ary[idx+1]) < abs(ans1+ans2+ans3)) {
        ans1 = ary[i];
        ans2 = ary[j];
        ans3 = ary[idx+1];
      }
      if(idx+2 != i && idx+2 != j && idx+2 < n && abs(ary[i]+ary[j]+ary[idx+2]) < abs(ans1+ans2+ans3)) {
        ans1 = ary[i];
        ans2 = ary[j];
        ans3 = ary[idx+2];
      }
      if(idx-1 != i && idx-1 != j && idx-1 >= 0 && abs(ary[i]+ary[j]+ary[idx-1]) < abs(ans1+ans2+ans3)) {
        ans1 = ary[i];
        ans2 = ary[j];
        ans3 = ary[idx-1];
      }
    }
  }
  cout << ans1 << " " << ans2 << " " << ans3;
}