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
int dp[1000005];
int num;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> num;
  dp[1] = 0;
  for(int i = 2; i <= num; i++) {
    int val3 = 1000000;
    int val2 = 1000000;
    int val1 = 1000000;
    if(i % 3 == 0) {
      val3 = dp[i/3] + 1;
    }
    if(i % 2 == 0) {
      val2 = dp[i/2] + 1;
    }
    val1 = dp[i-1] + 1;
    int ans = min(val1,val2);
    int fians = min(ans,val3);
    dp[i] = fians;
  }
  cout << dp[num];
}