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
ll a, b;
vector<int> check(10000010, 0);
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  check[1] = 1;
  for(ll i = 2; i <= 10000000; i++) {
    if(check[i] == 1) {
      continue;
    }
    for(ll j = i*i; j <= 10000000; j+=i) {
      check[j] = 1;
    }
  }
  ll ans = 0;
  for(ll i = 2; i <= 10000000; i++) {
    if(check[i] == 0) {
      ll num = i*i;
      while(a > num) {
        num *= i;
      }
      if(num <= b) {
        ans++;
      }
      int check = 0;
      while(b/i >= num) {
        num *= i;
        ans++;
        check = 1;
      }
    }
  }
  cout << ans;
}