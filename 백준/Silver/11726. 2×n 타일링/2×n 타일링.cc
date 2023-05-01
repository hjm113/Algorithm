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
int dp[1005];
int t, n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= n; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }
  cout << dp[n];
}