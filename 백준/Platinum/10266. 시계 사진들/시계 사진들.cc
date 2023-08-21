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
int s[200005];
int p[200005];
int stmp[200005];
int ptmp[200005];
int f[200005];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for(int j = 0; j < n; j++) {
    cin >> s[j];
  }
  sort(p,p+n);
  sort(s,s+n);
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      stmp[i] = 360000-s[n-1] + s[i];
      ptmp[i] = 360000-p[n-1] + p[i];
    }
    else {
      stmp[i] = s[i]-s[i-1];
      ptmp[i] = p[i]-p[i-1];
    }
  }
  /*
  for(int i = 0; i < n; i++) {
    cout << stmp[i] << " ";
  }
  cout << "\n";
  for(int i = 0; i < n; i++) {
    cout << ptmp[i] << " ";
  }
  cout << "\n";
  */
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && ptmp[i] != ptmp[j]) {
      j = f[j-1];
    }
    if(ptmp[i] == ptmp[j]) {
      f[i] = ++j;
    }
  }
  j = 0;
  int check = 0;
  for(int k = 0; k < n+n-1; k++) {
    int i = k % n;
    while(j > 0 && stmp[i] != ptmp[j]) {
      j = f[j-1];
    }
    if(stmp[i] == ptmp[j]) {
      j++;
    }
    if(j == n) {
      check = 1;
      break;
    }
  }
  if(check == 1) {
    cout << "possible";
  }
  else {
    cout << "impossible";
  }
}
