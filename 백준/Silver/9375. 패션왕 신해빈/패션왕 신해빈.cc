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
int n, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    unordered_map<string, int> m;
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; i++) {
      string item, part;
      cin >> item >> part;
      m[part]++;
    }
    for(auto ele : m) {
      ans *= ele.Y+1;
    }
    cout << ans-1 << "\n";
  }
}
