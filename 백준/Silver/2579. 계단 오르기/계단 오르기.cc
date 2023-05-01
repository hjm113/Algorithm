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
int dp[310][10];
int s[310];
int t, n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  dp[1][1] = s[1];
  dp[2][1] = s[2];
  dp[2][2] = s[1]+s[2];
  for(int i = 3; i <= n; i++) {
    int val1 = dp[i-1][1];
    int val2 = dp[i-2][2];
    int val3 = dp[i-2][1];
    int fst = max(val2,val3);
    dp[i][2] = val1 + s[i];
    dp[i][1] = fst + s[i];
  }
  cout << max(dp[n][1],dp[n][2]);
}