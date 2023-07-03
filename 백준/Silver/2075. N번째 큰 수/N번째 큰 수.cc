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
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n;
  for(int i = 0 ; i < n; i++) {
    int num;
    cin >> num;
    pq.push(num);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int num;
      cin >> num;
      if(num > pq.top()) {
        pq.pop();
        pq.push(num);
      }
    }
  }
  cout << pq.top();
}