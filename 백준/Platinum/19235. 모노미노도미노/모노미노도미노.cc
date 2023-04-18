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
int dx[4] = {0, 0, 0, 1};
int dy[4] = {0, 0, 1, 0};
int n;
int t, x, y;
vector<vector<int>> g(8,vector<int>(6,0));
vector<vector<int>> b(8,vector<int>(6,0));
int block = 1;
int pp = 0;

void down(int dir, int pos, vector<vector<int>> &ary, int x, int num) {
  while(1) {
    if(ary[x][pos] > 0 || ary[x+dx[dir]][pos+dy[dir]] > 0) {
      x--;
      break;
    }
    if(dir == 3) {
      if(x == 4) {
        break;
      }
    }
    if(x == 5) {
      break;
    }
    x++;
  }
  ary[x][pos] = num;
  ary[x+dx[dir]][pos+dy[dir]] = num;
}

void func(int dir, int pos, vector<vector<int>> &ary ) {
 
  down(dir, pos, ary, 0, block);
   
  while(1) {
    int change = 0;
    int out = 0;
    for(int i = 5; i > 1; i--) {
      int check = 0;
      for(int j = 0; j < 4; j++) {
        if(ary[i][j] == 0) {
          check = 1;
        }
      }
      if(check == 0) {
        out = 1;
        pp++;
        for(int j = 0; j < 4; j++) {
          ary[i][j] = 0;
        }
        change = i;
      }
    }
    for(int i = change - 1; i >= 0; i--) {
      for(int j = 0; j < 4; j++) {
        int bk = ary[i][j];
        if(ary[i][j] > 0 && ary[i][j+1] == bk) {
          ary[i][j] = 0;
          ary[i][j+1] = 0;
          down(2,j,ary,i,bk);
        }
        else if(ary[i][j] > 0 && ary[i-1][j] == bk) {
          ary[i-1][j] = 0;
          ary[i][j] = 0;
          down(3,j,ary,i,bk);
        }
        else if(ary[i][j] > 0) {
          ary[i][j] = 0;
          down(1,j,ary,i,bk);
        }
      }
    }
    if(out == 0) {
      break;
    }
  }
  int cnt = 0;
  for(int i = 0; i < 2; i++) {
    int move = 0;
    for(int j = 0; j < 4; j++) {
      if(ary[i][j] > 0) {
        move = 1;
      }
    }
    if(move == 1) {
      cnt++;
    }
  }
  for(int i = 0; i < cnt; i++) {
    ary.pop_back();
    ary.insert(ary.begin(),vector<int>(4));
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n > 0) {
    cin >> t >> x >> y;
    if(t == 1) {
      func(1,y,g);
      func(1,x,b);
    }
    else if(t == 2) {
      func(2,y,g);
      func(3,x,b);
    }
    else if(t == 3) {
      func(3,y,g);
      func(2,x,b);
    }
    block++;
    n--;
  }
  int ans = 0;
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 4; j++) {
      if(b[i][j] > 0) {
        ans++;
      }
      if(g[i][j] > 0) {
        ans++;
      }
    }
  }
  cout << pp << " " << ans;
}
