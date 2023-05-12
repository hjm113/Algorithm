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
int n,k;
int dp[1005][1005];
string s;
deque<pair<int,int>> dq;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int a;
  cin >> a;
  dq.push_back({a,1});
  long long ans = 0;
  for(int i = 1; i < n; i++) {
    int num;
    cin >> num;
    int count = 1;
    if(dq.back().X <= num) {
      while(dq.back().X <= num) {
        if(dq.back().X == num) {
          count = dq.back().Y + 1;
        }
        ans += dq.back().Y;
        dq.pop_back();
        if(dq.size() == 0) {
          break;
        }
      }
      if(dq.size() > 0) {
        ans++;
      }
      dq.push_back({num,count});
    }
    else if(dq.back().X > num) {
      ans++;
      dq.push_back({num,1});
    }
  }
  cout << ans;
} 