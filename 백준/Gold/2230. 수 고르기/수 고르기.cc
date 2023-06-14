#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
#define X first
#define Y second
ll ary[100005];
int n, m;
ll mn = 2000000001;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  int st = 0;
  int en = 0;
  while(en < n) {
    if(ary[en]-ary[st] >= m) {
      mn = min(mn,ary[en]-ary[st]);
      st++;
    }
    else {
      en++;
    }
  }
  cout << mn;
}
