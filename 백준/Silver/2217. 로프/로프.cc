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
int n, k;
pair<int,int> dis[100005];
int rope[10005];
bool cmp(int a, int b) {
  return a > b;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> rope[i];
  }
  sort(rope,rope+n,cmp);
  int mx = 0;
  for(int i = 0; i < n; i++) {
    if(mx < rope[i]*(i+1)) {
      mx = rope[i]*(i+1);
    }
  }
  cout << mx;
} 