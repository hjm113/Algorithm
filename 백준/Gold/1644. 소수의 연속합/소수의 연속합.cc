#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
#define X first
#define Y second
int check[4000100];
vector<int> prime;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  check[1] = 1;
  for(int i = 2; i*i <= n; i++) {
    if(check[i] == 1) {
      continue;
    }
    for(int j = i*i; j <=n; j+=i) {
      check[j] = 1;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(check[i] == 0) {
      prime.push_back(i);
    }
  }
  int len = prime.size();
  if(len == 0) {
    cout << 0;
    return 0;
  }
  int en = 0;
  int sum = prime[0];
  int ans = 0;
  for(int st = 0; st < len; st++) {
    while(sum < n && en < len) {
      en++;
      sum += prime[en];
    }
    if(en == len) {
      break;
    }
    if(sum == n) {
      ans++;
    }
    else if(sum > n) {
      sum -= prime[en];
      en--;
    }
    sum -= prime[st];
  }
  cout << ans;
}
