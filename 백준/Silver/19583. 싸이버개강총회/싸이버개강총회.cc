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
using namespace std;
using ll = long long;
#define X first
#define Y second
string s, e, q;
int is, ie, iq;
unordered_set<string> m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> e >> q;
  int idx = 1;
  for(int i = 4; i >= 0; i--) {
    if(i == 2) {
      continue;
    }
    is += (s[i]-'0')*idx;
    ie += (e[i]-'0')*idx;
    iq += (q[i]-'0')*idx;
    idx *= 10;
  }
  int ans = 0;
  int cnt = 0;
  string time, name;
  while(cin >> time >> name) {
    idx = 1;
    int it = 0;
    for(int i = 4; i >= 0; i--) {
      if(i == 2) {
        continue;
      }
      it += (time[i]-'0')*idx;
      idx *= 10;
    }
    if(it <= is) {
      m.insert(name);
    }
    if(ie <= it && it <= iq) {
      if(m.find(name) != m.end()) {
        m.erase(name);
        ans++;
      }
    }
    if(cnt == 17) {
      break;
    } 
  }
  cout << ans << "\n";
}
