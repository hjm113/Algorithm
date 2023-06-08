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
int ary[10005];
int m, n;
vector<int> num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  ll ans = 0;
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
    ans += upper_bound(ary+j+1,ary+n,-ary[i]-ary[j]) - lower_bound(ary+j+1,ary+n,-ary[i]-ary[j]); 
    }
  }
  cout << ans;
}