#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  while(1) {
    int f[1000005] = {};
    if(s == ".") {
      break;
    }
    int n = s.length();
    int j = 0;
    for(int i = 1; i < n; i++) {
      while(j > 0 && s[i] != s[j]) {
        j = f[j-1];
      }
      if(s[i] == s[j]) {
        f[i] = ++j;
      }
    }
    int len = n - f[n-1];
    if(n % len != 0) {
      cout << 1 << "\n";
    }
    else {
      cout << n / len << "\n";
    }
    cin >> s;
  }
  return 0;
}
