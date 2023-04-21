#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
#define X first
#define Y second
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int mx = 1000;
int rot = 0;
vector<vector<int>> board(15, vector<int>(15,0));
void func(vector<vector<int>> ary, int cnt, vector<int> num) {
  int check = 0;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(ary[i][j] == 1) {
        check = 1;
      }
    }
  }
  rot++;
  if(check == 0) {
    if(cnt < mx) {
      mx = cnt;
    }
    return;
  }
  int f = 0;
  int x = 0;
  int y = 0;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(ary[i][j] == 1) {
        x = i;
        y = j;
        f = 1;
        break;
      }
    }
    if(f == 1) {
      break;
    }
  }
  
  for(int count = 5; count > 0; count--) {
    if(num[count] == 5 || x+count > 10 || y+count > 10) {
      continue;
    }
    int out = 0;
    for(int k = 0; k < count; k++) {
      for(int w = 0; w < count; w++) {
        if(ary[x+k][y+w] == 0) {
          out = 1;
        }
      }
    }
    if(out == 0) {
      for(int k = 0; k < count; k++) {
        for(int w = 0; w < count; w++) {
          ary[x+k][y+w] = 0;
        }
      }
      num[count]++;
      func(ary, cnt+1, num);
      num[count]--;
      for(int k = 0; k < count; k++) {
        for(int w = 0; w < count; w++) {
          ary[x+k][y+w] = 1;
        }
      }
    }
  }

  
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> num;
  for(int i = 0; i <= 5; i++) {
    num.push_back(0);
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cin >> board[i][j];
    }
  }
  func(board, 0, num);
  if(mx == 1000) {
    cout << -1;
    return 0;
  }
  cout << mx;
}

