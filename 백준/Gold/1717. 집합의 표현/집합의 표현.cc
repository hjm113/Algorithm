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
int p[1000005];
int n, m;
int findp(int x) {
  if(p[x] == x) {
    return x;
  }
  else {
    return p[x] = findp(p[x]);
  }
}
void uni(int a, int b) {
  int x = findp(a);
  int y = findp(b);
  if(x != y) {
    if(x < y) {
      p[y] = x;
    }
    else {
      p[x] = y;
    }
  }
 }

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    p[i] = i;
  }
  for(int i = 0; i < m; i++) {
    int q, a, b;
    cin >> q >> a >> b;
    if(q == 0) {
      uni(a,b);
    }
    if(q == 1) {
      //cout << findp(a) << " " << findp(b) << "\n";
      if(findp(a) == findp(b)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}
