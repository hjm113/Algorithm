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
int dp[100005];
int s[100005];
int ans[100005];
int n, m;
int t;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  dp[1] = s[1];
  for(int i = 2; i <= n; i++) {
    int ans = max(s[i],dp[i-1]+s[i]);
    dp[i] = ans;
  }
  int ans = *max_element(dp+1,dp+n+1);
  cout << ans;
}