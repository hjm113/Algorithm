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
  cin >> n >> m;
  ary[1] = 1;
  for(int i = 2; i*i <= m; i++) {
    if(ary[i] == 1) {
      continue;
    }
    for(int j = i*i; j <= m; j+=i) {
      ary[j] = 1;
    }
  }
  for(int i = n; i <= m; i++) {
    if(ary[i] == 0) {
      cout << i << " ";
    }
  }
}