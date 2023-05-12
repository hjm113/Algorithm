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
int n, k;
pair<int,int> dis[100005];

bool cmp(pair<int,int> a, pair<int,int> b) {
  if(a.Y < b.Y) {
    return true;
  }
  else if(a.Y == b.Y) {
    if(a.X < b.X) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    dis[i] = {s,e};
  }
  sort(dis,dis+n,cmp);
  int x = dis[0].X;
  int y = dis[0].Y;
  int ans = 1;
  for(int i = 1; i < n; i++) {
    if(dis[i].X >= y) {
      ans++;
      x = dis[i].X;
      y = dis[i].Y;
    }
  }
  cout << ans;
  /*
  for(int i = 0; i < n; i++) {
    cout << dis[i].X << " " << dis[i].Y << "\n";
  }
  */
} 