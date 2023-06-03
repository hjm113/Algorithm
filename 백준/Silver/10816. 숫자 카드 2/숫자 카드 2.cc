#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;
#define X first
#define Y second
int ary[500005];
int n, m;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  cin >> m;
  
  for(int i = 0; i < m; i++) {
    int target;
    cin >> target;
    cout << upper_bound(ary,ary+n,target)-lower_bound(ary,ary+n,target) << " ";
  }
}