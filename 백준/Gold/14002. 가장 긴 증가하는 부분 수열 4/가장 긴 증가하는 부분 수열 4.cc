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
int dp[1005];
int num[1005];
vector<int> order[1005];
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> num[i];
    order[i].push_back(num[i]);
    dp[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    int idx = 0;
    for(int j = 1; j < i; j++) {
      if(num[j] < num[i]) {
        dp[i] = max(dp[j]+1,dp[i]);
        if(max(dp[j]+1,dp[i]) == dp[j]+1) {
          idx = j;
        }
      }
    }
    for(int j = 0; j < order[idx].size(); j++) {
      order[i].push_back(order[idx][j]);
    }
  }
  int ans = *max_element(dp+1,dp+n+1);
  cout << ans;
  int loc = 0;
  for(int i = 1; i <= n; i++) {
    if(ans == dp[i]) {
      loc = i;
    }
  }
  cout << "\n";
  for(int j = order[loc].size()-1; j >= 0; j--) {
    cout << order[loc][j] << " ";
  }
}