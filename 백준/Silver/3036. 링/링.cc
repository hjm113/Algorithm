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
int n, k;

int gcd(int x, int y) {
  if(y == 0) {
    return x;
  }
  return gcd(y, x%y);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int fst;
  cin >> fst;
  for(int i = 1; i < n; i++) {
    int num; 
    cin >> num;
    int d = gcd(fst,num);
    cout << fst/d << "/" << num/d << "\n";
  }
}