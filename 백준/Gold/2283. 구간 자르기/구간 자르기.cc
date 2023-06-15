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
pair<int,int> ary[1005];
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ary[i] = {x,y};
  }
  
  int en = 0;
  int fst = 0;
  int check = 0;
  for(int st = 0; st <= 1000000; st++) {
    int sum = 0;
    while(sum < k && en < 1000001) {
      en++;
      sum = 0;
      for(int i = 0; i < n; i++) {
        int mn = max(ary[i].X,st);
        int mx = min(ary[i].Y,en);
        if(en >= ary[i].X) {
          sum += mx-mn;
        }
        if(sum > k) {
          break;
        }
      }
      //cout << st << " " << en << " " << sum << "\n"; 
    }
    if(en == 1000001) {
      break;
    }
    if(sum == k) {
      check = 1;
      fst = st;
      break;
    }
    en--;
  }
  if(check == 0) {
    cout << 0 << " " << 0;
    return 0;
  }
  cout << fst << " " << en;
}
