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
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int n, m;
int board[55][55];
int check[55][55];
tuple<int,int> order[105];
deque<tuple<int,int>> cld;
deque<tuple<int,int>> tmp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cld.push_back(make_tuple(n,1));
  cld.push_back(make_tuple(n,2));
  cld.push_back(make_tuple(n-1,1));
  cld.push_back(make_tuple(n-1,2));
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < m; i++) {
    int d, s;
    cin >> d >> s;
    order[i] = {d,s};
  }
  int count = 0;
  while(1) {
    while(!cld.empty()) {
      int x, y;
      tie(x,y) = cld.front();
      cld.pop_front();
      int dir, sp;
      tie(dir,sp) = order[count];
      while(sp > 0) {
        x += dx[dir];
        y += dy[dir];
        if(x < 1) {
          x = n;
        }
        if(x > n) {
          x = 1;
        }
        if(y < 1) {
          y = n;
        }
        if(y > n) {
          y = 1;
        }
        sp--;
      }
      board[x][y]++;
      tmp.push_back(make_tuple(x,y));
    }
    while(!tmp.empty()) {
      int x, y;
      tie(x,y) = tmp.front();
      tmp.pop_front();
      int ext = 0;
      for(int dir = 2; dir <= 8; dir+=2) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || nx > n || ny < 1 || ny > n) {
          continue;
        }
        if(board[nx][ny] > 0) {
          ext++;
        }
      }
      check[x][y] = 1;
      board[x][y] += ext;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(check[i][j] == 0) {
          if(board[i][j] > 1) {
            board[i][j] -= 2;
            cld.push_back(make_tuple(i,j));
          }
        }
        else if(check[i][j] == 1) {
          check[i][j] = 0;
        }
      }
    }
    count++;
    /*
    cout << "\n";
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
    */
    if(count == m) {
      break;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      ans += board[i][j];
    }
  }
  cout << ans;
}

