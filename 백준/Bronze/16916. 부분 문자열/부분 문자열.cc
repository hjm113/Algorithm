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
string s, p;
int f[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> p;
  int np = p.length();
  int ns = s.length();
  int j = 0;
  for(int i = 1; i < np; i++) {
    while(j > 0 && p[i] != p[j]) {
      j = f[j-1];
    }
    if(p[i] == p[j]) {
      f[i] = ++j;
    }
  }
  j = -1;
  int check = 0;
  for(int i = 0; i < ns; i++) {
    j++;
    if(s[i] == p[j]) {
      if(j == np-1) {
        check = 1;
        break;
      }
      continue;
    }
    j = f[j-1];
  }
  cout << check;
}