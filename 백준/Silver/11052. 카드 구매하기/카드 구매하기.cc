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
long long dp[1005];
int n, m;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> dp[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i-1; j > 0; j--) {
      dp[i] = max(dp[j]+dp[i-j],dp[i]);
    }
  }
  cout << dp[n];
}