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
int n,m;
int board[2005];
int dp[2005][2005];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> board[i];
  }
  for(int i = 1; i <= n; i++) {
    int l = i;
    int r = i;
    while(1) {
      if(board[l] == board[r]) {
        dp[l][r] = 1;
      }
      else if(board[l] != board[r]) {
        break;
      }
      l--;
      r++;
      if(l < 1 || r > n) {
        break;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    int l = i;
    int r = i+1;
    while(1) {
      if(board[l] == board[r]) {
        dp[l][r] = 1;
      }
      else if(board[l] != board[r]) {
        break;
      }
      l--;
      r++;
      if(l < 1 || r > n) {
        break;
      }
    }
  }
  
  cin >> m;
  while(m--) {
    int x, y;
    cin >> x >> y;
    cout << dp[x][y] << "\n";
  }
  /*
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  */
} 