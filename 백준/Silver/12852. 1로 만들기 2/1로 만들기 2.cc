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
int dp[1000005];
int path[1000005];
int n, m;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[1] = 0;
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + 1;
    path[i] = i-1;
    if(dp[i] > dp[i/3]+1 && i % 3 == 0) {
      dp[i] = dp[i/3] + 1;
      path[i] = i/3;
    }
    if(dp[i] > dp[i/2]+1 && i % 2 == 0) {
      dp[i] = dp[i/2] + 1;
      path[i] = i/2;
    }
  }
  cout << dp[n] << "\n";
  while(1) {
    cout << n << " ";
    if(n == 1) {
      break;
    }
    n = path[n];
  }
}