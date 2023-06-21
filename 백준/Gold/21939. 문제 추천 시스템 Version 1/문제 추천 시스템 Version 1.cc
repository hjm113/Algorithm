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
int ary[100005];
int n, m;
multiset<int> s[105];
multiset<int> ms;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ms.insert(y);
    s[y].insert(x);
    ary[x] = y;
  }
  cin >> m;
  for(int i = 0; i < m; i++) {
    string order;
    cin >> order;
    if(order == "add") {
      int x, y;
      cin >> x >> y;
      ms.insert(y);
      s[y].insert(x);
      ary[x] = y;
    }
    else if(order == "recommend") {
      int x;
      cin >> x;
      if(x == 1) {
        cout << *prev(s[*prev(ms.end())].end()) << "\n";
      }
      else {
        cout << *s[*ms.begin()].begin() << "\n";
      }
    }
    else {
      int x;
      cin >> x;
      int lv = ary[x];
      ary[x] = 0;
      ms.erase(ms.find(lv));
      s[lv].erase(x);
    }
  }
}
