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
int n, t;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int dp[5][100005] = {};
    int num[5][100005] = {};
    int n;
    cin >> n;
    for(int i = 1; i <= 2; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> num[i][j];
      }
    }
    dp[1][1] = num[1][1];
    dp[2][1] = num[2][1];
    for(int i = 2; i <= 100000; i++) {
      for(int j = 1; j <= 2; j++) {
        int val = 0;
        val = max(dp[1][i-2], dp[2][i-2]);
        val = max(val, dp[3-j][i-1]);
        dp[j][i] = val + num[j][i];
      }
    }
    cout << max(dp[1][n],dp[2][n]) << "\n";
  }
  
}