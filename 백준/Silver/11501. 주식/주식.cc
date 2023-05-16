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
int t;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> num;
    for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      num.push_back(a);
    }
    long long ans = 0;
    int max = num[n-1];
    for(int i = n-2; i >= 0; i--) {
      if(num[i] > max) {
        max = num[i];
      }
      ans += max - num[i];
    }
    cout << ans << "\n";
  }
}