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
int n, t;
long long dp[1005];
long long tmp[15];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[1] = 10;

  for(int i = 1; i <= 10; i++) {
    tmp[i] = i;
  }
  for(int i = 2; i <= n; i++) {
    int ans = 0;
    for(int j = 1; j <= 10; j++) {
      ans += tmp[j];
      tmp[j] = ans % 10007;
    }
    dp[i] = ans % 10007;
  }
  cout << dp[n];
}