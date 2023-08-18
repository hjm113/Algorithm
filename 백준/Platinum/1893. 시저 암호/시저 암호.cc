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
map<char,int> mp;
int f[50005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    string s, p, order;
    cin >> order >> p >> s;
    vector<int> ans;
    int no = order.length();
    int np = p.length();
    int ns = s.length();
    for(int i = 0; i < no; i++) {
      mp[order[i]] = i;
    }
    int j = 0;
    for(int i = 1; i < np; i++) {
      if(j < 0) {
        continue;
      }
      while(j > 0 && p[i] != p[j]) {
        j = f[j-1];
      }
      if(p[i] == p[j]) {
        f[i] = ++j;
      }
    }
    for(int w = 0; w < no; w++) {
      int k = 0;
      int cnt = 0;
      for(int i = 0; i < ns; i++) {
        if(k < 0) {
          continue;
        }
        while(k > 0 && s[i] != p[k]) {
          k = f[k-1];
        }
        if(s[i] == p[k]) {
          k++;
        }
        if(k == np) {
          cnt++;
          k = f[k-1];
        }
      }
      for(int i = 0; i < ns; i++) {
        int idx = mp[s[i]];
        if(idx == 0) {
          idx = no;
        }
        idx--;
        s[i] = order[idx];
      }
      if(cnt == 1) {
        ans.push_back(w);
      }
    }
    if(ans.size() == 0) {
      cout << "no solution";
    }
    else if(ans.size() == 1) {
      cout << "unique: ";
    }
    else if(ans.size() > 1) {
      cout << "ambiguous: ";
    }
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}