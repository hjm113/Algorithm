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
int n, k;
int dp[10005];
int coin[105];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> coin[i];
  }
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = coin[i]; j <= k; j++) {
      dp[j] += dp[j-coin[i]];
    }
  }
  cout << dp[k];
}