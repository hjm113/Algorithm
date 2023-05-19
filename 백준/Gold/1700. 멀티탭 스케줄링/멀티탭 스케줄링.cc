#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, k;
int num[105];
int mul[105];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    cin >> num[i];
  }
  int ans = 0;
  for(int i = 0; i < k; i++) {
    int order[105] = {};
    int check = 0;
    for(int j = 0; j < n; j++) {
      if(mul[j] == num[i]) {
        check = 1;
        break;
      }
    }
    if(check == 1) {
      continue;
    }
    int idx = -1;
    for(int j = 0; j < n; j++) {
      if(mul[j] == 0) {
        idx = j;
      }
    }
    if(idx != -1) {
      mul[idx] = num[i];
    }
    else {
      for(int j = 0; j < n; j++) {
        order[mul[j]] = 10000000;
        for(int w = i+1; w < k; w++) {
          if(mul[j] == num[w]) {
            order[mul[j]] = w;
            break;
          }
        }
      }
      int mx = 0;
      int out = 0;
      for(int j = 0; j < n; j++) {
        if(mx < order[mul[j]]) {
          mx = order[mul[j]];
          out = j;
        }
      }
      /*
      for(int w = 0; w < k; w++) {
        cout << order[w] << " ";
      }
      cout << "\n";
      cout << mul[out] << "\n";
      */
      mul[out] = num[i];
      ans++;
    }
  }
  cout << ans;
}