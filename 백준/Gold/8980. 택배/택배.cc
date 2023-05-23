#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, k, m;
tuple<int,int,int> box[10005];
int cap[2005];

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
  int ax,ay,az;
  tie(ax,ay,az) = a;
  int bx,by,bz;
  tie(bx,by,bz) = b;
  if(ay < by) {
    return true;
  }
  else if(ay > by) {
    return false;
  }
  else {
    return ax < bx;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m;
  for(int i = 0; i < m; i++) {
    int x,y,z;
    cin >> x >> y >> z;
    box[i] = make_tuple(x,y,z);
  }
  sort(box,box+m,cmp);
  int ans = 0;
  for(int i = 0; i < m; i++) {
    int x,y,z;
    tie(x,y,z) = box[i];
    int maxz = 0;
    for(int j = x; j < y; j++) {
      maxz = max(cap[j],maxz);
    }
    int add = min(k-maxz,z);
    ans += add;
    for(int j = x; j < y; j++) {
      cap[j] += add;
    }
  }
  cout << ans;
}