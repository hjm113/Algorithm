#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int p, l, v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> p >> v;
  int count = 1;
  while(p > 0) {
    int left = v % p;
    int other = (v / p) * l;
    if(left > l) {
      left = l;
    }
    cout << "Case " << count << ": " << left + other << "\n";
    cin >> l >> p >> v;
    count++;
  }
}