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
int n;
int num[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= 10; i++) {
    num[10-i] = 1;
    do {
      if(cnt != n) {
        cnt++;
        continue;
      }
      for(int i = 0; i < 10; i++) {
        if(num[i] == 1) {
          cout << 9 - i;
        }
      }
      return 0;
    }while(next_permutation(num,num+10));
  }
  cout << -1;
}