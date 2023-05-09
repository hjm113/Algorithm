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
int w[105];
int v[105];
int dp[105][100005];
int n,k;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  int end = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= end; j++) {
      if(j > k) {
        continue;
      }
      dp[i][j] = dp[i-1][j];
    }
    for(int j = 0; j <= end; j++) {
      if(w[i]+j > k) {
        continue;
      }
      dp[i][w[i]+j] = max(dp[i][w[i]+j],dp[i-1][j]+v[i]);
    }
    /*
    cout << "\n";
    for(int i = 0; i < 20; i++) {
    cout << dp[i] << " ";
      */
    end += w[i];
  }
cout << *max_element(dp[n]+1,dp[n]+k+1);
}