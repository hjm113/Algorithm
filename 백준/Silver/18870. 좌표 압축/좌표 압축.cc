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
int ary[1000005];
int n, m;
int num[1000005];
int tmp[1000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
    tmp[i] = ary[i];
  }
  sort(ary,ary+n);
  int check = -1000000005;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(check != ary[i]) {
      num[cnt] = ary[i];
      cnt++;
    }
    check = ary[i];
  }
  for(int i = 0; i < n; i++) {
    cout << lower_bound(num,num+cnt,tmp[i]) - &num[0]  << " ";
  }
  
}