#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
int dp[105][100005];
int n, k;
int w[105];
int v[105];
int mx = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> w[i];
    cin >> v[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      if(j-w[i] < 0) {
        dp[i][j] = dp[i-1][j];
        continue;
      }
      dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    }
  }
  cout << dp[n][k];
}
