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
int ary[30005];
int check[3005];
int n, d, k, c;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> k >> c;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  int en = 0;
  int ans = 0;
  int mx = 0;
  //cout << "\n";
  for(int st = 0; st < n; st++) {
    if(st == 0) {
      while(en < k) {
        if(check[ary[en]] == 0) {
          ans++;
        }
        check[ary[en]]++;
        en++;
        en %= n;
      }
    }
    else {
      //cout << en << "  " << ans << "   sadf\n";
      if(check[ary[en]] == 0) {
        //cout << "checkkfksdfsdf\n";
        ans++;
      }
      check[ary[en]]++;
      en++;
      en %= n;
    }
    
    if(check[c] == 0) {
      //cout << ans+1 << "\n";
      mx = max(mx,ans+1);
    }
    else {
      //cout << ans << "\n";
      mx = max(mx,ans);
    }
    if(check[ary[st]] == 1) {
      ans--;
    }
    check[ary[st]]--;
  }
  cout << mx;
}
