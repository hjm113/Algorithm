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
set<int> g[105][105];
set<int> lv[105];
pair<int,int> ary[100005];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    ary[x] = {y,z};
    g[z][y].insert(x);
    lv[y].insert(x);
  }
  cin >> m;
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if(s == "recommend") {
      int gr, x;
      cin >> gr >> x;
      if(x == 1) {
        for(int i = 100; i >= 1; i--) {
          if(g[gr][i].empty()) {
            continue;
          }
          cout << *prev(g[gr][i].end()) << "\n";
          break;
        }
      }
      else {
        for(int i = 1; i <= 100; i++) {
          if(g[gr][i].empty()) {
            continue;
          }
          cout << *g[gr][i].begin() << "\n";
          break;
        }
      }
    }
    else if(s == "recommend2") {
      int x;
      cin >> x;
      if(x == 1) {
        for(int i = 100; i >= 1; i--) {
          if(lv[i].empty()) {
            continue;
          }
          cout << *prev(lv[i].end()) << "\n";
          break;
        }
      }
      else {
        for(int i = 1; i <= 100; i++) {
          if(lv[i].empty()) {
            continue;
          }
          cout << *lv[i].begin() << "\n";
          break;
        }
      }
    }
    else if(s == "recommend3") {
      int x, l;
      cin >> x >> l;
      int ans = -1;
      if(x == 1) {
        for(int i = l; i <= 100; i++) {
          if(lv[i].empty()) {
            continue;
          }
          ans = *lv[i].begin();
          break;
        }
      }
      else {
        for(int i = l-1; i >= 1; i--) {
          if(lv[i].empty()) {
            continue;
          }
          ans = *prev(lv[i].end());
          break;
        }
      }
      cout << ans << "\n";
    }
    else if(s == "add") {
      int x, y, z;
      cin >> x >> y >> z;
      ary[x] = {y,z};
      g[z][y].insert(x);
      lv[y].insert(x);
    }
    else if(s == "solved"){
      int p;
      cin >> p;
      int l = ary[p].X;
      int gr = ary[p].Y;
      g[gr][l].erase(p);
      lv[l].erase(p);
    }
  }
}
