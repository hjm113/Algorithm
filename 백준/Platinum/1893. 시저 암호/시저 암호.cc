#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
int t;
vector<int> f;
string s, p, order;
vector<int> ans;
void solve(string a) {
  f.clear();
  f.resize(a.length());
  int j = 0;
  for(int i = 1; i < a.length(); i++) {
    while(j > 0 && a[i] != a[j]) {
      j = f[j-1];
    }
    if(a[i] == a[j]) {
      f[i] = ++j;
    }
  }
}
int kmp(string a, string b) {
  int k = 0;
  int cnt = 0;
  for(int i = 0; i < a.length(); i++) {
    while(k > 0 && s[i] != p[k]) {
      k = f[k-1];
    }
    if(s[i] == p[k]) {
      if(k == b.length()-1) {
        cnt++;
        k = f[k];
      }
      else {
        k++;
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> order >> p >> s;
    int no = order.length();
    ans.clear();
    map<char,int> mp;
    for(int i = 0; i < no; i++) {
      mp[order[i]] = i;
    }
    for(int w = 0; w < no; w++) {
      if (w > 0) {
        for (int j = 0; j < p.length(); j++) {
          p[j] = order[(mp[p[j]] + 1) % no];
        }
      }
      solve(p);
      if(kmp(s,p) == 1) {
        ans.push_back(w);
      }
    }
    if (!ans.size())
      cout << "no solution\n";
    else if (ans.size() == 1)
      cout << "unique: " << ans[0] << "\n";
    else {
      cout << "ambiguous: ";
      for (int x : ans)
          cout << x << " ";
      cout << "\n";
    }
  }
}