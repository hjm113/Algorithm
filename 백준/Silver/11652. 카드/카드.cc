#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
#define X first
#define Y second

bool cmp(long long a, long long b) {
  return a < b;
}
int n;
long long ary[100005];
int cnt[100005];
long long mx[100005];
int main(void){
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary, ary+n, cmp);
  int count = 0;
  long long a = -(1ll<<62)-2;
  for(int i = 0; i < n; i++) {
    if(a != ary[i]) {
      a = ary[i];
      count++;
      cnt[count]++;
      mx[count] = ary[i];
    }
    else {
      cnt[count]++;
    }
  }
  int mn = 0;
  int ans = 0;
  for(int i = 1; i <= count; i++) {
    if(mn < cnt[i]) {
      mn = cnt[i];
      ans = i;
    }
  }
  cout << mx[ans];
}