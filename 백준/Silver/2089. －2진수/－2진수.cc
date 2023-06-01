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
ll n, m, k;
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if(n == 0) {
    cout << 0;
    return 0;
  }
  while(1) {
    //cout << n << "\n";
    if(n == 1) {
      s+= '1';
      break;
    }
    if(n % -2 == 0) {
      s+= '0';
    }
    else if(n % -2 != 0) {
      s+= '1';
    }
    if(n < 0 && n % -2 != 0) {
      n /= -2;
      n++;
    }
    else{
      n /= -2;
    }
  }
  reverse(s.begin(),s.end());
  cout << s;
}