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
int dpl[50];
int dpo[50];
int n, m;
int t;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  dpo[0] = 1;
  dpo[1] = 0;
  dpo[2] = 1;
  dpl[0] = 0;
  dpl[1] = 1;
  dpl[2] = 1;
  for(int i = 3; i <= 40; i++) {
    dpo[i] = dpo[i-1] + dpo[i-2];
    dpl[i] = dpl[i-1] + dpl[i-2];
  }
  while(t--) {
    cin >> n;
    cout << dpo[n] << " " << dpl[n] << "\n";
  }
}