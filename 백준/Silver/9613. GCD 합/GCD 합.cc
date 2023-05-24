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
deque<pair<int,int>> dq;
int gcd(int x, int y) {
  if(y == 0) {
    return x;
  }
  else {
    return gcd(y,x%y);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int num[105] = {};
    for(int i = 0; i < n; i++) {
      cin >> num[i];
    }
    long long ans = 0;
    for(int i = 0; i < n-1; i++) {
      for(int j = i+1; j < n; j++) {
        ans += gcd(num[i],num[j]);
      }
    }
    cout << ans << "\n";
  }
}