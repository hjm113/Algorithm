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
unordered_map<string, int> m;
int n, k;
string ary[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    string name;
    cin >> name;
    m[name] = i;
    ary[i] = name;
  }
  for(int i = 0; i < k; i++) {
    string s;
    cin >> s;
    if(s[0] >= '0' && s[0] <= '9') {
      cout << ary[stoi(s)] << "\n";
    }
    else {
      cout << m[s] << "\n";
    }
  }
}
