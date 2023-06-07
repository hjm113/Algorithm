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
int ary[1000005];
int n, k;
int dis(int x){
  int ans = 0;
  for(int i = 0; i < k; i++) {
    ans += (ary[i]/x);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> n;
  for(int i = 0; i < k; i++) {
    cin >> ary[i];
  }
  ll st = 0;
  ll en = (1ll<<31)-1;
  
  while(st < en) {
    int mid = (st+en+1)/2;
    if(dis(mid) < n) {
      en = mid-1;
    }
    else if(dis(mid) >= n) {
      st = mid;
    }
  }
  cout << st;
}