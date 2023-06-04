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
vector<int> uni;
int mx = 0;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      uni.push_back(ary[i]+ary[j]);
    }
  }
  sort(uni.begin(),uni.end());
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(binary_search(uni.begin(),uni.end(),(ary[i]-ary[j]))) {
        if(mx < ary[i]) {
          mx = ary[i];
        }
      }
    }
  }
  cout << mx;
}