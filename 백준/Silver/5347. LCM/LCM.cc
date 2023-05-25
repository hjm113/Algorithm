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

ll gcd(int x, int y) {
  if(y == 0) {
    return x;
  }
  else {
    return gcd(y,x%y);
  }
}
ll lcm(int x, int y) {
  return x / gcd(x,y) * y;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << lcm(x,y) << "\n";
  }
}