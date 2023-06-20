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
string s;
unordered_map<string, int> m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    string tmp = "";
    for(int j = i; j < s.length(); j++) {
      tmp += s[j];
      m[tmp] = 1;
    }
  }
  cout << m.size();
}
