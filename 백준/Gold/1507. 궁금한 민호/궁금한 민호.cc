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
using ll = long long;
#define X first
#define Y second
int d[25][25];
int used[25][25];
int n;
vector<string> vis;
map<string, int> mp;
int mx = 50000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> d[i][j];
    }
  }
  int ans = 0;
  int cnt = 0;
  for(int i = 1; i < n; i++) {
    for(int j = i+1; j <= n; j++) {
      int mn = d[i][j];
      d[i][j] = mx;
      for(int k = 1; k <= n; k++) {
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
      if(d[i][j] > mn) {
        ans += mn;
        d[i][j] = mn;
      }
      if(d[i][j] < mn) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
  
}