#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, m;
int ary[1000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if(n == 1) {
    return 0;
  }
  int i = 2;
  while(i*i <= n) {
    if(n % i == 0) {
      n /= i;
      cout << i << "\n";
    }
    else {
      i++;
    }
  }
  cout << n;
}