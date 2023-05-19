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
string str;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  int cnt0 = 0;
  int cnt1 = 0;
  if(str[0] == '0') {
    cnt0++;
  }
  else {
    cnt1++;
  }
  for(int i = 1; i < str.size(); i++) {
    if(str[i] == '0' && str[i-1] == '1') {
      cnt0++;
    }
    if(str[i] == '1' && str[i-1] == '0') {
      cnt1++;
    }
  }
  cout << min(cnt1,cnt0);
}