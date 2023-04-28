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

bool cmp(long long a, long long b) {
  return a < b;
}
int n;
long long ary[100005];
long long ans[100005];
int main(void){
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  for(int i = 0; i < n; i++) {
    int cnt = 0;
    long long num = ary[i];
    long long po = 1;
    while(num > 0) {
      num /= 10;
      po *= 10;
      cnt++;
    }
    po /= 10;
    cnt--;
    long long dig = 0;
    long long nu = ary[i];
    
    while(cnt >= 0) {
      long long fst = nu % 10;
      nu /= 10;
      dig += (fst*po);
      po /= 10;
      cnt--;
    }
    ans[i] = dig;
  }
  sort(ans, ans+n);
  for(int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}