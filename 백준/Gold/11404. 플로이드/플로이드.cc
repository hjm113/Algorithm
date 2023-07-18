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
int n, m;
int mx = 200000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      board[i][j] = mx;
    }
  }
  for(int i = 0; i < m; i++) {
    int x, y, cost;
    cin >> x >> y >> cost;
    board[x][y] = min(board[x][y],cost);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= n; k++) {
        if(j == k) {
          continue;
        }
        board[j][k] = min(board[j][k],board[j][i]+board[i][k]);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(board[i][j] == mx) {
        cout << 0 << " ";
      }
      else {
        cout << board[i][j] << " ";
      }
    }
    cout << "\n";
  }
}