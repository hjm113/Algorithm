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
int n, k;
int w[105];
int v[105];
int dp[100005];
bool cmp(int a, int b) {
  return a > b;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(w,w+n);
  sort(v,v+n,cmp);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (w[i]*v[i]);
  }
  cout << ans;
} 