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
int tri[550][550];
int dp[550][550];
int n, m;
int t;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int count = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= count; j++) {
      cin >> tri[i][j];
    }
    count++;
  }
  dp[1][1] = tri[1][1];
  int cnt = 2;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= cnt; j++) {
      int val1 = dp[i-1][j-1];
      int val2 = dp[i-1][j];
      int ans = max(val1,val2);
      dp[i][j] = ans + tri[i][j];
    }
    cnt++;
  }
  int mx = 0;
  for(int i = 1; i < cnt; i++) {
    mx = max(mx,dp[n][i]);
  }
  cout << mx;
}