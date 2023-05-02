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
int t[20];
int p[20];
int dp[20];
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
  }
  for(int i = n; i > 0; i--) {
    if(i + t[i] <= n+1) {
      dp[i] = max(dp[i+t[i]]+p[i],dp[i+1]);
    }
    else {
      dp[i] = dp[i+1];
    }
  }
  cout << *max_element(dp+1,dp+n+1);
}