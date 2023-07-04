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

int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    priority_queue<ll, vector<ll>, greater<>> pq;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
      int num;
      cin >> num;
      pq.push(num);
    }
    ll ans = 0;
    while(1) {
      ll fst = pq.top();
      pq.pop();
      ll snd = pq.top();
      pq.pop();
      ans += (fst+snd);
      if(pq.empty()) {
        break;
      }
      pq.push(fst+snd);
    }
    cout << ans << "\n";
  }
  
}