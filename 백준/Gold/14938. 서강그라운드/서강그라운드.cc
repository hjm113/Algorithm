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
using ll = long long;
#define X first
#define Y second
int board[105][105];
int item[105];
int n, m, r;
int mx = 200000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> r;
  for(int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    item[i] = t;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      board[i][j] = mx;
    }
  }
  for(int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    board[a][b] = min(board[a][b],l);
    board[b][a] = min(board[b][a],l);
  }
  for(int i = 1; i <= n; i++) {
    board[i][i] = 0;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        board[i][j] = min(board[i][j],board[i][k]+board[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int sum = 0;
    for(int j = 1; j <= n; j++) {
      if(board[i][j] <= m) {
        sum += item[j];
      }
    }
    if(ans < sum) {
      ans = sum;
    }
  }
  cout << ans;
}