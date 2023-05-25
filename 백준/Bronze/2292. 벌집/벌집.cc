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
int n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int fi = 1;
  int add = 6;
  int ans = 1;
  while(1) {
    if(n <= fi) {
      break;
    }
    fi += add;
    ans++;
    add += 6;
  }
  cout << ans;
}