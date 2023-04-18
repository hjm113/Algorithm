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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, k;
int board[250];
int robo[250];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n*2; i++) {
    cin >> board[i];
  }
  int cnt = 0;
  while(1) {
    cnt++;
    int tmpb = board[(2*n)-1];
    for(int i = (2*n)-2; i >= 0; i--) {
      board[i+1] = board[i];
    }
     board[0] = tmpb;
    for(int i = n-2; i >= 0; i--) {
      robo[i+1] = robo[i];
    }
    robo[0] = 0;
    if(robo[n-1] == 1) {
      robo[n-1] = 0;
    }
    for(int i = n-2; i >= 0; i--) {
      if(robo[i] == 1) {
        if(board[i+1] > 0 && robo[i+1] == 0) {
          robo[i+1] = 1;
          robo[i] = 0;
          board[i+1]--;
        }
      }
    }
    if(board[0] > 0) {
      robo[0] = 1;
      board[0]--;
    }
    int sum = 0;
    for(int i = 0; i < n*2; i++) {
      if(board[i] == 0) {
        sum++;
      }
    }
    if(k <= sum) {
      break;
    }
  }
  cout << cnt;
}
