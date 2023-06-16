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
int num[1000005];
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for(int i = x+1; i <= y; i++) {
      num[i]++;
    }
  }
  int en = 0;
  int fst = 0;
  int sum = 0;
  int mx = 0;
  for(int st = 0; st <= 1000000; st++) {
    sum -= num[st];
    while(sum < k && en < 1000001) {
      en++;
      sum += num[en];
    }
    //cout << st << " " << en << " " << sum << "\n";
    if(sum == k) {
      fst = st;
      break;
    }
    if(en == 1000001) {
      cout << 0 << " " << 0;
      return 0;
    }
  }
  cout << fst << " " << en;
}
