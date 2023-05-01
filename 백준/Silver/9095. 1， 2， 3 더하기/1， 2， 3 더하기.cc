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
int t, n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t > 0) {
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= n; i++) {
      dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    cout << dp[n] << "\n";
    t--;
  }
}