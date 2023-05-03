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
int dp[1005][35];
int t[1005];
int n, w;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w;
  for(int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  int cnt = 1;
  for(int i = 1; i <= n; i++) {
    if(t[i] == 1) {
      dp[i][0] = cnt;
      cnt++;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= w; j++) {
      if(j % 2 == 1 && t[i] == 2) {
        dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + 1;
      }
      else if(j % 2 == 0 && t[i] == 1) {
        dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
      }
    }
  }
  cout << *max_element(dp[n],dp[n]+w+1);
}