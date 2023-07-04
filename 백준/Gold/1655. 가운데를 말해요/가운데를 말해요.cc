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
priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;
int n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if(maxh.size() == minh.size()) {
      maxh.push(num);
    }
    else {
      minh.push(num);
    }
    if(!minh.empty() && maxh.top() > minh.top()) {
      minh.push(maxh.top());
      maxh.pop();
      maxh.push(minh.top());
      minh.pop();
    }
    cout << maxh.top() << "\n";
  }
}