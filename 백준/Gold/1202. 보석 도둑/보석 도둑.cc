#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
#define X first
#define Y second
pair<int,int> ary[300005];
int n, k;
multiset<int> s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ary[i] = {y,x}; 
  }
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  sort(ary,ary+n);
  ll ans = 0;
  for(int i = n-1; i >= 0; i--) {
    if(s.size() == 0) {
      break;
    }
    if(s.lower_bound(ary[i].Y) != s.end()) {
      ans += ary[i].X;
      //cout << *s.lower_bound(ary[i].Y) << "\n";
      s.erase(s.lower_bound(ary[i].Y));
    }
  }
  cout << ans;
}
