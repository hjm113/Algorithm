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
int ary[105][10005];
int m, n;
void compress(int a[]) {
  vector<int> v(a,a+n);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i = 0; i < n; i++) {
    a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
  }
}
int compare(int a[], int b[]) {
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      return false;
    }
  }
  return true;
}
 
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> ary[i][j];
    }
    compress(ary[i]);
  }
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    for(int j = i+1; j < m; j++) {
      if(compare(ary[i],ary[j])) {
        cnt++;
      }
    }
  }
  cout << cnt;
}