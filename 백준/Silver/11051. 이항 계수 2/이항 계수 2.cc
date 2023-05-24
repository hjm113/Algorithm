#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, k;
int dp[1005][1005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i = 2; i <= 1000; i++) {
    dp[i][0] = 1;
    for(int j = 1; j < i; j++) {
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
    }
    dp[i][i] = 1;
  }
  cout << dp[n][k];
}