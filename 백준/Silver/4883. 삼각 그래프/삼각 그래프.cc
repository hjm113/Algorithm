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
int n;
int t = 1;
long long dp[1000005][5];
int num[1000005][4];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n != 0) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= 3; j++) {
        cin >> num[i][j];
      }
    }
    dp[1][1] = 10000;
    dp[1][2] = num[1][2];
    dp[1][3] = num[1][2] + num[1][3];
    
    for(int i = 2; i <= n; i++) {
      dp[i][1] = min({dp[i-1][1],dp[i-1][2]}) + num[i][1];
      dp[i][2] = min({dp[i-1][1],dp[i-1][2],dp[i][1],dp[i-1][3]}) + num[i][2];
      dp[i][3] = min({dp[i-1][2],dp[i-1][3],dp[i][2]}) + num[i][3];
    }
    cout << t << ". " << dp[n][2] << "\n";
    t++;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= 3; j++) {
        num[i][j] = 0;
        dp[i][j] = 0;
      }
    }
    cin >> n;
  }
  

}