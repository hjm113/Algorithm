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
int dp[3][1005];
int n;
int ary[1005];
int mx = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ary[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      dp[j][i] = 1;
    }
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      if(ary[i] > ary[j]) {
        dp[0][i] = max(dp[0][i],dp[0][j]+1);
      }
      if(ary[i] < ary[j]) {
        dp[1][i] = max({dp[1][i],dp[0][j]+1,dp[1][j]+1});
      }
    }
  }
  //cout << dp[0][6] << " " << dp[1][6] << "\n";
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      if(dp[j][i] > mx) {
        mx = dp[j][i];
      }
    }
  }
  cout << mx;
}
