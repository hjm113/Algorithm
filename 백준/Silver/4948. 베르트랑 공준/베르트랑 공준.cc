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
int check[300005];
int n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int en = 123456*2;
  check[1] = 1;
  for(int i = 2; i*i <= en; i++) {
    if(check[i] == 1) {
      continue;
    }
    for(int j = i*i; j <= en; j+=i) {
      check[j] = 1;
    }
  }
  cin >> n;
  while(n > 0) {
    int cnt = 0;
    for(int i = n+1; i <= n*2; i++) {
      if(check[i] == 0) {
        cnt++;
      }
    }
    cout << cnt << "\n";
    cin >> n;
  }
}