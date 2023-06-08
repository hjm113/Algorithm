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
int ary[2005];
int check[2005];
int m, n;
vector<int> num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  int check = 0;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
    if(ary[i] == 0) {
      check = 1;
    }
  }
  if(n == 1 || n == 2) {
    cout << 0;
    return 0;
  }
  sort(ary,ary+n);
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(ary[i] == 0 || ary[j] == 0) {
        continue;
      }
      num.push_back(ary[i]+ary[j]);
    }
  }
  int ans = 0;
  sort(num.begin(),num.end());
  for(int i = 0; i < n; i++) {
    if(binary_search(num.begin(),num.end(),ary[i])) {
      ans++;
    }
    else {
      int ub = upper_bound(ary,ary+n,ary[i]) - ary;
      int lb = lower_bound(ary,ary+n,ary[i]) - ary;
      if(ary[i] == 0) {
        if(ub-lb > 2) {
          ans++;
        }
      }
      else {
        if(ub-lb > 1) {
          if(check == 1) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
}