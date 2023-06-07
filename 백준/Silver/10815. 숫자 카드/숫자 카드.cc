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
int ary[500005];
int n, k;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  for(int i = 0; i < k; i++) {
    cin >> ary[i];
  }
  sort(ary,ary+k);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cout << binary_search(ary,ary+k,num) << " ";
  }
}