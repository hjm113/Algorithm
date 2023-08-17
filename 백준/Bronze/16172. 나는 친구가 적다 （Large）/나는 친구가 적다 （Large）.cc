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
string s, p, stmp;
int f[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> p;
  int np = p.length();
  int ns = s.length();
  for(int i = 0; i < ns; i++) {
    if(s[i] >= '0' && s[i] <= '9') {
      continue;
    }
    stmp += s[i];
  }
  ns = stmp.length();
  s = stmp;
  int j = 0;
  for(int i = 1; i < np; i++) {
    while(j > 0 && p[i] != p[j]) {
      j = f[j-1];
    }
    if(p[i] == p[j]) {
      f[i] = ++j;
    }
  }
  j = 0;
  int check = 0;
  for(int i = 0; i < ns; i++) {
    while(j > 0 && s[i] != p[j]) {
      j = f[j-1];
    }
    if(s[i] == p[j]) {
      j++;
    }
    if(j == np) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
}