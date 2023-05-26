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
int t;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    ll s, e;
    cin >> s >> e;
    ll ans = e-s;
    ll res = 1;
    ll count = 1;
    ll cnt = 1;
    while(1) {
      res += count;
      if(ans <= res) {
        if(ans == res) {
          cnt++;
        }
        break;
      }
      cnt++;
      res += count;
      if(ans <= res) {
        if(ans == res) {
          cnt++;
        }
        break;
      }
      count++;
      cnt++;
    }
    cout << cnt << "\n";
  }
  
}