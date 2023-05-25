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
vector<int> check(1000010, 0);
vector<int> prime;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  check[1] = 1;
  for(int i = 2; i*i <= 100000; i++) {
    if(check[i] == 1){
      continue;
    }
    for(int j = i*i; j <= 100000; j+=i) {
      check[j] = 1;
    }
  }
  for(int i = 1; i < 100000; i++) {
    if(check[i] == 0) {
      prime.push_back(i);
    }
  }
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < prime.size(); i++) {
      int count = 0;
      while(n % prime[i] == 0) {
        n /= prime[i];
        count++;
      }
      if(count > 0) {
        cout << prime[i] << " " << count << "\n";
      }
      if(n == 1) {
        break;
      }
    }
  }
}