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
int n,m;
int dp[5005];
string s;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  if(s[0] == '0') {
    cout << 0;
    return 0;
  }
  if(s[1] == '0' && (s[0] > '2' || s[0] < '1')) {
    cout << 0;
    return 0;
  }
  dp[0] = 1;
  if(s[1] > '0' && s[1] <= '9' && s[0] == '1') {
    dp[1] = 2;
  }
  else if(s[1] > '0' && s[1] <= '6' && (s[0] == '1' || s[0] == '2')) {
    dp[1] = 2;
  }
  else {
    dp[1] = 1;
  }
  for(int i = 2; i < s.length(); i++) {
    if(s[i] == '0' && (s[i-1] > '2' || s[i-1] < '1')) {
      cout << 0;
      return 0;
    }
    if(s[i+1] == '0') {
      dp[i] = dp[i-1] % 1000000;
    }
    else if(s[i] > '0' && s[i] <= '9' && s[i-1] == '1') {
      dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
    }
    else if(s[i] > '0' && s[i] <= '6' && (s[i-1] == '1' || s[i-1] == '2')) {
      dp[i] = (dp[i-1] + dp[i-2]) % 1000000;;
    }
    else {
      dp[i] = (dp[i-1]) % 1000000;;
    }
  }
  cout << dp[s.length()-1];
} 