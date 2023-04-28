#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
#define X first
#define Y second

int ary1[1000009];
int ary2[1000009];
int n1;
int n2;
vector<int> ary;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n1 >> n2;
  for(int i = 0; i < n1; i++) {
    cin >> ary1[i];
  }
  for(int i = 0; i < n2; i++) {
    cin >> ary2[i];
  }
  int cnt1 = 0;
  int cnt2 = 0;
  while(1) {
    if(cnt1 == n1 && cnt2 == n2) {
      break;
    }
    if(cnt2 == n2) {
      ary.push_back(ary1[cnt1]);
      cnt1++;
      continue;
    }
    if(cnt1 == n1) {
      ary.push_back(ary2[cnt2]);
      cnt2++;
      continue;
    }
    if(ary1[cnt1] < ary2[cnt2]) {
      ary.push_back(ary1[cnt1]);
      cnt1++;
    }
    else {
      ary.push_back(ary2[cnt2]);
      cnt2++;
    }
  }
  for(int i = 0; i < ary.size(); i++) {
    cout << ary[i] << " ";
  }
}