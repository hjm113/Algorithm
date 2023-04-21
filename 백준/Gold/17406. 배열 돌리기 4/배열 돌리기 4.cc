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
vector<vector<int>> board(55, vector<int>(55,0));
vector<vector<int>> tmp(55, vector<int>(55,0));
int n, m, k;
int mx = INT_MAX;
int num[10];
int check[10];
tuple<int,int,int,int> ary[10];
void rotate(int sx, int sy, int ex, int ey) {
  while(1) {
    if(sx == ex && sy == ey) {
      break;
    }
    int tmp = board[sx][sy];
    for(int i = sx+1; i <= ex; i++) {
      board[i-1][sy] = board[i][sy];
    }
    for(int i = sy+1; i <= ey; i++) {
      board[ex][i-1] = board[ex][i];
    }
    for(int i = ex-1; i >= sx; i--) {
      board[i+1][ey] = board[i][ey];
    }
    for(int i = ey-1; i > sy; i--) {
      board[sx][i+1] = board[sx][i];
    }
    board[sx][sy+1] = tmp;
    sx++;
    sy++;
    ex--;
    ey--;
  }
}

void func(int id) {
  if(id == k) {
    for(int i = 0; i < k; i++) {
      int sx,sy,ex,ey;
      tie(sx,sy,ex,ey) = ary[num[i]];
      rotate(sx,sy,ex,ey);
    }
    for(int i = 1; i <= n; i++) {
      int sum = 0;
      for(int j = 1; j <= m; j++) {
        sum += board[i][j];
      }
      if(sum < mx) {
        mx = sum;
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        board[i][j] = tmp[i][j];
      }
    }
  }
  for(int i = 0; i < k; i++) {
    if(check[i] == 0) {
      num[id] = i;
      check[i] = 1;
      func(id+1);
      check[i] = 0;
    }
    
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> board[i][j];
      tmp[i][j] = board[i][j];
    }
  }
  for(int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    int stx = r-s;
    int sty = c-s;
    int edx = r+s;
    int edy = c+s;
    ary[i] = {stx,sty,edx,edy};
  }
  func(0);
  cout << mx;
}

