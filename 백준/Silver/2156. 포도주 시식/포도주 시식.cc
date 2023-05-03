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
int dp[10005][5];
int num[10005];
vector<int> order[1005];
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  dp[1][1] = num[1];
  dp[1][2] = 0;
  dp[2][1] = num[2];
  dp[2][2] = num[1] + num[2];
  for(int i = 3; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      if(i-1 == j) {
        dp[i][2] = dp[j][1] + num[i];
      }
      else {
        dp[i][1] = max({dp[j][1]+num[i], dp[j][2]+num[i], dp[i][1]});
      }
    }
    
    
  }
  int mx = 0;
  for(int i = 1; i <= n; i++) {
    //cout << dp[i][1] << " " << dp[i][2] << "\n";
    for(int j = 1; j <= 2; j++) {
      if(mx < dp[i][j]) {
        mx = dp[i][j];
      }
    }
  }
  cout << mx;
}