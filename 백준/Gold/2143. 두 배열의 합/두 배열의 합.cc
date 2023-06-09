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
int a[1005];
int b[1005];
int t, n, m;
vector <ll> numa;
vector <ll> numb;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    ll sum = 0;
    for(int j = i; j < n; j++) {
      sum += a[j];
      //cout << sum << " ";
      numa.push_back(sum);
    }
  }
  //cout << "\n";
  for(int i = 0; i < m; i++) {
    ll sum = 0;
    for(int j = i; j < m; j++) {
      sum += b[j];
      //cout << sum << " ";
      numb.push_back(sum);
    }
  }
  //cout << "\n";
  sort(numb.begin(),numb.end());
  sort(numa.begin(),numa.end());
  ll cnt = 0;
  if(numa.size() > numb.size()) {
    for(int i = 0; i < numa.size(); i++) {
      int ub = upper_bound(numb.begin(),numb.end(),t-numa[i]) - numb.begin();
      int lb = lower_bound(numb.begin(),numb.end(),t-numa[i]) - numb.begin();
      cnt += (ub-lb);
    }
  }
  else {
    for(int i = 0; i < numb.size(); i++) {
      int ub = upper_bound(numa.begin(),numa.end(),t-numb[i]) - numa.begin();;
      int lb = lower_bound(numa.begin(),numa.end(),t-numb[i]) - numa.begin();;
      cnt += (ub-lb);
    }
  }
  cout << cnt;
}