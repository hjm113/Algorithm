#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n;
int dp[205];
int num[205];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      if(num[i] > num[j]) {
        dp[i] = max(dp[i],dp[j]+1);
      }
    }
  }
  int max = *max_element(dp+1,dp+n+1);
  cout << n - max;
}