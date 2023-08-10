#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
int t = 10;
int n;
int board[1005];
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt = 1;
  while(t--) {
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> board[i];
    }
    for(int i = 2; i < n-2; i++) {
      if(board[i] > 0) {
        int mx = 0;
        for(int j = i-2; j <= i+2; j++) {
          if(i == j) {
            continue;
          }
          mx = max(mx,board[j]);
        }
        if(board[i] < mx) {
          continue;
        }
        ans += board[i]-mx;
      }
    }
    cout << "#" << cnt << " " << ans << "\n";
    cnt++;
  }
  return 0;
}