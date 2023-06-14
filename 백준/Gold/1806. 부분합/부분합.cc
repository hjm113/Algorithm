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
int mn = 1000000000;
int n, s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  int st = 0;
  int en = 0;
  int sum = 0;
  for(int st = 0; st < n; st++) {
    sum -= ary[st-1];
    while(sum < s && en < n) {
      sum += ary[en];
      en++;
    }
    if(sum >= s) {
      mn = min(mn,en-st);
    }
  }
  if(mn == 1000000000) {
    cout << 0;
    return 0;
  }
  cout << mn;
}
