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
long long ans[100005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n != 0) {
    deque<pair<long long, long long>> dq;
    deque<pair<long long, long long>> tmp;
    int a;
    cin >> a;
    dq.push_back({a,1});
    for(int i = 1; i < n; i++) {
      long long num;
      cin >> num;
      if(dq.back().X < num) {
        dq.push_back({num,1});
      }
      else if(dq.back().X >= num) {
        int count = 0;
        int ori = 0;
        while(dq.back().X >= num) {
          ori = dq.back().Y;
          ans[dq.back().Y+count] = max(dq.back().X,ans[dq.back().Y+count]);
          count += dq.back().Y;
          dq.pop_back();
          if(dq.size() == 0) {
            break;
          }
        }
        dq.push_back({num,count+1});
      }
    }
    if(dq.size() > 0) {
      tmp.push_back({dq.back().X,dq.back().Y});
      dq.pop_back();
    }
    int count = 0;
    while(!dq.empty()) {
      int num = dq.back().X;
      int range = dq.back().Y;
      int add = tmp.back().Y;
      dq.pop_back();
      ans[tmp.back().Y] = max(tmp.back().X,ans[tmp.back().Y]);
      tmp.pop_back();
      count++;
      tmp.push_back({num,range+add});
    }
    ans[tmp.back().Y] = max(tmp.back().X,ans[tmp.back().Y]);
    tmp.pop_back();
    long long mx = 0;
    /*
    cout << "\n";
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    */
    for(int i = 1; i <= n; i++) {
      if(mx < ans[i]*i) {
        mx = ans[i]*i;
      }
      ans[i] = 0;
    }
    cout << mx << "\n";
    cin >> n;
  }
} 