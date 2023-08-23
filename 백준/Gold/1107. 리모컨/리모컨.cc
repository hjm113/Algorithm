#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
int num, n;
int check[1000005];
int mx = 100;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> num >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    check[x] = 1;
  }
  if(num == mx) {
    cout << 0;
    return 0;
  }
  int up = 2000000000;
  int out2 = 0;
  for(int i = num; i <= 1000000; i ++) {
    int ch = i;
    int chk = 0;
    if(check[ch] == 1) {
      chk = 1;
    }
    while(ch > 0) {
      int di = ch % 10;
      if(check[di] == 1) {
        chk = 1;
        break;
      }
      ch /= 10;
    }
    if(chk == 0) {
      out2 = 1;
      up = i;
      break;
    }
  }
  int down = -2000000000;
  int out1 = 0;
  for(int i = num; i >= 0; i--) {
    int ch = i;
    int chk = 0;
    if(check[ch] == 1) {
      chk = 1;
    }
    while(ch > 0) {
      int di = ch % 10;
      if(check[di] == 1) {
        chk = 1;
        break;
      }
      ch /= 10;
    }
    if(chk == 0) {
      out1 = 1;
      down = i;
      break;
    }
  }
  //cout << up << " " << down << "\n";
  int upnum = up - num;
  int donum = num - down;
  int us = to_string(up).length();
  int ud = to_string(down).length();
  int fi = num - mx;
  int fup = upnum + us;
  int fdo = donum + ud;
  //cout << fup << " " << fdo << " " << abs(fi) << "\n";
  if(out1 == 1 && out2 == 1) {
    cout << min(min(fup,fdo),abs(fi));
  }
  else if(out1 == 0) {
    cout << min(fup,abs(fi));
  }
  else if(out2 == 0){
    cout << min(fdo,abs(fi));
  }
  else {
    cout << abs(fi);
  }
  
}
