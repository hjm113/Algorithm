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
string s, p;
int f[1000005];
vector<int> ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  getline(cin,s);
  getline(cin,p);
  int np = p.length();
  int ns = s.length();
  int j = 0;
  for(int i = 1; i < np; i++) {
    while(j > 0 && p[i] != p[j]) {
      j = f[j-1];
    }
    if(p[i] == p[j]) {
      f[i] = ++j;
    }
  }
  j = 0;
  int check = 0;
  for(int i = 0; i < ns; i++) {
    while(j > 0 && s[i] != p[j]) {
      j = f[j-1];
    }
    if(s[i] == p[j]) {
      j++;
    }
    if(j == np) {
      ans.push_back(i-j+2);
      j = f[j-1];
    }
  }
  cout << ans.size();
  cout << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}