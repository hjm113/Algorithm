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
multiset<int> ms;
pair<int,int> ary[250005];
ll h[250005];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int fst;
  cin >> fst;
  ms.insert(fst);
  h[fst] = 1;
  ll ans = 1;
  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if(ms.lower_bound(x) == ms.end()) {
      auto num = *prev(ms.lower_bound(x));
      h[x] = h[num] + 1;
      ans += h[num] + 1;
      ms.insert(x);
      continue;
    }
    auto num2 = *ms.lower_bound(x);
    if(ary[num2].X == 0) {
      h[x] = h[num2] + 1;
      ans += h[num2] + 1;
      ary[num2].X = 1;
      ms.insert(x);
    }
    else {
      auto num3 = *prev(ms.lower_bound(x));
      h[x] = h[num3] + 1;
      ans += h[num3] + 1;
      ary[num3].Y = 1;
      ms.insert(x);
    }
  }
  /*
  for(int i = 0; i < 10; i++) {
    cout << h[i] << " ";
  }
  cout << "\n";
  */
  cout << ans;
}
