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
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int h, w, n;
    cin >> h >> w >> n;
    int he = n % h;
    int wi = 0;
    if(he == 0) {
      he = h;
      wi = n / h;
    }
    else {
      wi = n / h + 1;
    }
    if(wi < 10) {
      cout << he << 0 << wi << "\n";
    }
    else {
      cout << he << wi << "\n";
    }
    
  }
}