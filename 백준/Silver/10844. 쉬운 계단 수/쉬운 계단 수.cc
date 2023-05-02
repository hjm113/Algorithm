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
long long dp[105][10];
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= 9; j++) {
      if(j != 0) {
        dp[i][j] += dp[i-1][j-1];
      }
      if(j != 9) {
        dp[i][j] += dp[i-1][j+1];
      }
      dp[i][j] %= 1000000000;
    }
  }
  long long ans = 0;
  for(int i = 0; i <= 9; i++) {
    ans += dp[n][i];
  }
  ans %= 1000000000;
  cout << ans;
}