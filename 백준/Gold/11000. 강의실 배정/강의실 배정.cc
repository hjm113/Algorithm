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
int n;
deque<pair<int,int>> dq;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x,y;
    cin >> x >> y;
    dq.push_back({x,1});
    dq.push_back({y,-1});
  }
  sort(dq.begin(),dq.end());
  int ans = 0;
  int res = 0;
  for(int i = 0; i < n*2; i++) {
    res += dq[i].Y;
    ans = max(ans,res);
  }
  cout << ans;
}