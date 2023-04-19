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

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int board[25][25];
int n;
int fin = 10000;
void func(int x, int y) {
  for(int d1 = 1; d1 <= n; d1++) {
    for(int d2 = 1; d2 <= n; d2++) {
      int dist[25][25] = {};
      dist[x][y] = 5;
      if(y-d1 < 1 || y + d2 > n || x + d1 + d2 > n) {
        continue;
      }
      int count1 = 0;
      int count2 = 0;
      int ter1 = 0;
      int ter2 = 0;
      for(int i = x; i <= x+d1+d2; i++) {
        for(int j = y - count1; j <= y + count2; j++) {
          dist[i][j] = 5;
        }
        if(d1 > count1 && ter1 == 0) {
          count1++;
        }
        else {
          count1--;
          ter1 = 1;
        }
        if(d2 > count2 && ter2 == 0) {
          count2++;
        }
        else {
          count2--;
          ter2 = 1;
        }
        
      }
      
      for(int i = 1; i < x+d1; i++) {
        for(int j = 1; j <= y; j++) {
          if(dist[i][j] != 5) {
            dist[i][j] = 1;
          }
        }
      }
      for(int i = 1; i <= x+d2; i++) {
        for(int j = y+1; j <= n; j++) {
          if(dist[i][j] != 5) {
            dist[i][j] = 2;
          }
        }
      }
      for(int i = x+d1; i <= n; i++) {
        for(int j = 1; j < y-d1+d2; j++) {
          if(dist[i][j] != 5) {
            dist[i][j] = 3;
          }
        }
      }
      for(int i = x+d2+1; i <= n; i++) {
        for(int j = y-d1+d2; j <= n; j++) {
          if(dist[i][j] != 5) {
            dist[i][j] = 4;
          }
        }
      }
      int cnt[6] = {};
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          if(dist[i][j] == 1) {
            cnt[1] += board[i][j];
          }
          else if(dist[i][j] == 2) {
            cnt[2] += board[i][j];
          }
          else if(dist[i][j] == 3) {
            cnt[3] += board[i][j];
          }
          else if(dist[i][j] == 4) {
            cnt[4] += board[i][j];
          }
          else if(dist[i][j] == 5) {
            cnt[5] += board[i][j];;
          }
        }
      }
      int mx = 0;
      for(int i = 1; i <= 5; i++) {
        if(mx < cnt[i]) {
          mx = cnt[i];
        }
      }
      int mn = 1000000;
      for(int i = 1; i <= 5; i++) {
        if(mn > cnt[i]) {
          mn = cnt[i];
        }
      }
      int ans = mx - mn;
      if(fin > ans) {
        fin = ans;
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
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        func(i,j);
    }
  }
  cout << fin;
}
