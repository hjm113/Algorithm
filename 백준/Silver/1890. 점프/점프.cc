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
int board[105][105];
int n,m;
long long dp[105][105];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  dp[1][1] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i+board[i][j] <= n && board[i][j] != 0) {
        dp[i+board[i][j]][j] += dp[i][j];
      }
      if(j+board[i][j] <= n && board[i][j] != 0) {
        dp[i][j+board[i][j]] += dp[i][j];
      }
    }
  }
  cout << dp[n][n];
} 