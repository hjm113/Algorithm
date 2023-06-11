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
int ary[1000005];
vector <int> num;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  num.push_back(ary[0]);
  for(int i = 1; i < n; i++) {
    int idx = num.size() - 1;
    if(num[idx] < ary[i]) {
      num.push_back(ary[i]);
    }
    else {
      int lb = lower_bound(num.begin(), num.end(), ary[i]) - num.begin();
      if(lb == num.size()) {
        continue;
      }
      num[lb] = ary[i];
    }
  }
  cout << num.size();
}