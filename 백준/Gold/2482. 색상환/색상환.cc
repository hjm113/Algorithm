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
int n,k;
int dp[1005][1005];
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  dp[1][1] = 1;
  dp[2][1] = 2;
  dp[3][1] = 3;
  for(int i = 4; i <= n; i++) {
    dp[i][1] = i;
    for(int j = 2; j <= k; j++) {
      dp[i][j] += ((dp[i-1][j]+dp[i-2][j-1]) % 1000000003);
    }
  }
  cout << dp[n][k];
} 