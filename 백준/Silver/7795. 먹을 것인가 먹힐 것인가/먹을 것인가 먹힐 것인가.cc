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
int t;
bool cmp(int a, int b) {
  return a > b;
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t > 0) {
    int n;
    int m;
    int arya[20005] = {};
    int aryb[20005] = {};
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      cin >> arya[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> aryb[i];
    }
    sort(arya,arya+n,cmp);
    sort(aryb,aryb+m,cmp);
    int count = 0;
    int ans = 0;
    for(int i = 0; i < m; i++) {
      if(arya[count] > aryb[i]) {
        ans += (m-i);
        i--;
        count++;
      }
    }
    cout << ans << "\n";
    t--;
  }
}