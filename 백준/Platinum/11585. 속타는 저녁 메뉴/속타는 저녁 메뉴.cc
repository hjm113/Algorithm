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
char s[1000005];
char p[1000005];
int n;
int f[1000005];
int gcd(int a, int b) {
  if(a == 0) {
    return b;
  }
  return gcd(b%a,a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && p[i] != p[j]) {
      j = f[j-1];
    }
    if(p[i] == p[j]) {
      f[i] = ++j;
    }
  }
  j = 0;
  int cnt = 0;
  for(int k = 0; k < n+n-1; k++) {
    int i = k % n;
    while(j > 0 && s[i] != p[j]) {
      j = f[j-1];
    }
    if(s[i] == p[j]) {
      j++;
    }
    if(j == n) {
      cnt++;
    }
  }
  int num = gcd(cnt,n);
  cout << cnt/num << "/" << n/num;
}
