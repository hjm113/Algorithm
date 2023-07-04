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

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int> pq;
  cin >> n;
  for(int i = 0 ; i < n; i++) {
    int num;
    cin >> num;
    if(num == 0) {
      if(pq.empty()) {
        cout << 0 << "\n";
      }
      else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
    else {
      pq.push(num);
    }
  }
}