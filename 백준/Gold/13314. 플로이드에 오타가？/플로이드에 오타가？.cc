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
int d[205][205];
int nxt[205][205];
int n, m;
int mx = 500000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 100;
  cout << n << "\n";
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) {
        cout << 0 << " ";
      }
      else if(i == n || j == n) {
        cout << 10 << " ";
      }
      else {
        cout << 9000 << " ";
      }
    }
    cout << "\n";
  }
}