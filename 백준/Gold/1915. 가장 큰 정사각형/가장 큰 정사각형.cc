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
char board[1005][1005];
int dp[1005][1005];
int n,m;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(board[i][j] == '1') {
        dp[i][j] = min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]}) + 1;
      }
    }
  }
  int mx = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(mx < dp[i][j]) {
        mx = dp[i][j];
      }
    }
  }
  cout << mx * mx;
}