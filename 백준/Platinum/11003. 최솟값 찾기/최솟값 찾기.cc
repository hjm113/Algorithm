#include <bits/stdc++.h>
using namespace std;

int min = INT_MIN;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int l;
  cin >> n >> l;
  deque<int> dq;
  deque<int> dq2;
  int min;
  cin >> min;
  cout << min << " ";
  dq.push_back(min);
  dq2.push_back(0);
  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if(dq.size() != 0) {
      if(i-l == dq2.front()) {
      dq.pop_front();
      dq2.pop_front();
      }
    }
    if(dq.size() != 0) {
      while(dq.back() > x) {
      dq.pop_back();
      dq2.pop_back();
        if(dq.size() == 0) {
          break;
        }
      }
    }
    dq.push_back(x);
    dq2.push_back(i);
    cout << dq.front() << " ";
  }
}