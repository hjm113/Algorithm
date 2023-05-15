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
int w[1005];
int v[105];
int dp[1005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  sort(w+1,w+n+1);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i-1] + w[i];
    ans += dp[i];
  }
  cout << ans;
} 