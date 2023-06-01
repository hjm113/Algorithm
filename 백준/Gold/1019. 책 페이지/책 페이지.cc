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
int cnt[11];
int e;
void calc(int x, int add) {
  while(x > 0) {
    cnt[x%10] += add;
    x /= 10;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> e;
  int s = 1;
  int num = 1;
  int out = 0;
  int count = 0;
  while(1) {
    while(1) {
      if(e < 10) {
        break;
      }
      if(e % 10 == 9) {
        break;
      }
      calc(e,num);
      e--;
    }
    while(1) {
      if(s % 10 == 0) {
        break;
      }
      if(s == e) {
        calc(s,num);
        out = 1;
        break;
      }
      calc(s,num);
      s++;
    }
    if(out == 1) {
      break;
    }
    s /= 10;
    e /= 10;
    for(int i = 0; i < 10; i++) {
      cnt[i] += (e-s+1)*num;
    }
    num *= 10;
  }
  for(int i = 0; i < 10; i++) {
    cout << cnt[i] << " ";
  }
}