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
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
int board[20][20];
vector<vector<int>> st(20, vector<int>(20,0));
int n;
int cnt = 0;
void func(int pos, int ex, int ey, int stx, int sty) {
  if(stx == n && sty == n) {
    cnt++;
    return;
  }
  for(int i = 0; i < 3; i++) {
    if(pos == 0) {
      if(i == 0) {
        int nstx = stx + dx[0];
        int nsty = sty + dy[0];
        int nex = ex + dx[0];
        int ney = ey + dy[0];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1) {
          continue;
        }
        func(0,nex,ney,nstx,nsty);
      }
      else if(i == 1) {
        int nstx = stx + dx[1];
        int nsty = sty + dy[1];
        int nex = ex + dx[0];
        int ney = ey + dy[0];
        
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1 || board[nstx-1][nsty] == 1 || board[nstx][nsty-1] == 1) {
          continue;
        }
        func(1,nex,ney,nstx,nsty);
      }
    }
    else if(pos == 1) {
      if(i == 0) {
        int nstx = stx + dx[0];
        int nsty = sty + dy[0];
        int nex = ex + dx[1];
        int ney = ey + dy[1];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1) {
          continue;
        }
        func(0,nex,ney,nstx,nsty);
      }
      else if(i == 1) {
        int nstx = stx + dx[1];
        int nsty = sty + dy[1];
        int nex = ex + dx[1];
        int ney = ey + dy[1];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1 || board[nstx][nsty-1] == 1 || board[nstx-1][nsty] == 1) {
          continue;
        }
        func(1,nex,ney,nstx,nsty);
      }
      else if(i == 2) {
        int nstx = stx + dx[2];
        int nsty = sty + dy[2];
        int nex = ex + dx[1];
        int ney = ey + dy[1];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1) {
          continue;
        }
        func(2,nex,ney,nstx,nsty);
      }
    }
    else if(pos == 2) {
      if(i == 2) {
        int nstx = stx + dx[2];
        int nsty = sty + dy[2];
        int nex = ex + dx[2];
        int ney = ey + dy[2];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1) {
          continue;
        }
        func(2,nex,ney,nstx,nsty);
      }
      else if(i == 1) {
        int nstx = stx + dx[1];
        int nsty = sty + dy[1];
        int nex = ex + dx[2];
        int ney = ey + dy[2];
        if(nstx < 1 || nstx > n || nsty < 1 || nsty > n) {
          continue;
        }
        if(board[nstx][nsty] == 1 || board[nstx-1][nsty] == 1 || board[nstx][nsty-1] == 1) {
          continue;
        }
        func(1,nex,ney,nstx,nsty);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  func(0,1,1,1,2);
    cout << cnt;
  /*
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << st[i][j] << " ";
    }
    cout << "\n";
  }
  */
}

