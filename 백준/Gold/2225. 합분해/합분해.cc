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
int dp[205][205];
int n, k;
int ary[1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i <= n; i++) {
    dp[1][i] = 1;
  }
  for(int i = 2; i <= k; i++) {
    for(int j = 0; j <= n; j++) {
      for(int k = 0; k <= n; k++) {
        if(j+k > n) {
          continue;
        }
        dp[i][j+k] += (dp[i-1][j]);
        dp[i][j+k] %= 1000000000;
      }
    }
  }
  cout << dp[k][n];
}
