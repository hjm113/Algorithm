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
int ary[100005];
int n, m;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+n);
  cin >> m;
  for(int i = 0; i < m; i++) {
    int target;
    cin >> target;
    int st = 0;
    int en = n-1;
    int check = 0;
    while(st <= en) {
      int mid = (st+en)/2;
      if(ary[mid] == target) {
        check = 1;
        cout << 1 << "\n";
        break;
      }
      else if(ary[mid] > target) {
        en = mid-1;
      }
      else if(ary[mid] < target) {
        st = mid+1;
      }
    }
    if(check == 0) {
      cout << 0 << "\n";
    }
  }
}