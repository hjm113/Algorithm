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
int n, m;
long long num[1005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> num[i];
  }
  for(int i = 0; i < m; i++) {
    long long num1 = *min_element(num,num+n);
    int idx1 = 0;
    for(int j = 0; j < n; j++) {
      if(num[j] == num1) {
        idx1 = j;
        break;
      }
    }
    num[idx1] = 9999999999999999;
    long long num2 = *min_element(num,num+n);
    int idx2 = 0;
    for(int j = 0; j < n; j++) {
      if(num[j] == num2) {
        idx2 = j;
        break;
      }
    }
    long long ans = num1 + num2;
    num[idx1] = ans;
    num[idx2] = ans;
  }
  long long res = 0;
  for(int j = 0; j < n; j++) {
    res += num[j];
  }
  cout << res;
} 