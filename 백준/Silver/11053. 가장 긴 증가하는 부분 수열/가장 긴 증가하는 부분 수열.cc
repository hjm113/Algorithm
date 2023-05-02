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

int s[1005];
int dp[1005];
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    dp[i] = 1;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      if(s[i] > s[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp+1,dp+n+1);
}