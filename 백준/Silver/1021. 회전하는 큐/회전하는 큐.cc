#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num1, num2;
  cin >> num1 >> num2;
  deque<int> dq;
  int count = 0;
  for(int i = 1; i <= num1; i++) {
    dq.push_back(i);
  }
  for(int i = 0; i < num2; i++) {
    int x;
    cin >> x;
    int check = 0;
    int lenc = dq.size() / 2;
    for(int i = 0; i < dq.size(); i++) {
      if(x == dq[i]) {
        check = i;
      }
    }
    if(check <= lenc) {
      while(x != dq.front()) {
        dq.push_back(dq.front());
        dq.pop_front();
        count++;
      }
      if(x == dq.front()) {
        dq.pop_front();
      }
    }
    else{
      while(x != dq.front()) {
        dq.push_front(dq.back());
        dq.pop_back();
        count++;
      }
      if(x == dq.front()) {
        dq.pop_front();
      }
    }
  }
  cout << count;
}