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
int n;
int board[25][25];
vector<int> stu[450];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int num = n*n;
  for(int i = 0; i < num; i++) {
    int oril = 0;
    int oris = 0;
    int ox = 10000;
    int oy = 10000;
    int my, x, y, z, w;
    cin >> my >> x >> y >> z >> w;
    stu[my].push_back(x);
    stu[my].push_back(y);
    stu[my].push_back(z);
    stu[my].push_back(w);
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        int like = 0;
        int space = 0;
        if(board[j][k] > 0) {
          continue;
        }
        for(int dir = 0; dir < 4; dir++) {
          int nx = j + dx[dir];
          int ny = k + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
          }
          if(board[nx][ny] == x || board[nx][ny] == y || board[nx][ny] == z || board[nx][ny] == w) {
            like++;
          }
          else if(board[nx][ny] == 0) {
            space++;
          }
        }
        //cout << like << "like" << "\n";
        //cout << space << "space" << "\n";
        if(oril < like) {
          ox = j;
          oy = k;
          oril = like;
          oris = space;
        }
        else if(oril == like) {
          if(oris < space) {
            ox = j;
            oy = k;
            oris = space;
          }
          else if(oris == space) {
            if(ox > j){
              ox = j;
              oy = k;
            }
            else if(ox == j) {
              if(oy > k){
                ox = j;
                oy = k;
              }
            }
          }
        }

      }
    }
    board[ox][oy] = my;
    /*
     cout << "\n";
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        cout << board[j][k] << " ";
      }
      cout << "\n";
    }
    */
  }
  int ans = 0;
  for(int j = 0; j < n; j++) {
    for(int k = 0; k < n; k++) {
      int on = stu[board[j][k]][0];
      int tw = stu[board[j][k]][1];
      int tr = stu[board[j][k]][2];
      int fr = stu[board[j][k]][3];
      int like = 0;
      for(int dir = 0; dir < 4; dir++) {
        int nx = j + dx[dir];
        int ny = k + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
          continue;
        }
        if(board[nx][ny] == on || board[nx][ny] == tw || board[nx][ny] == tr || board[nx][ny] == fr) {
          like++;
        }
        
      }
      if(like == 4) {
        ans += 1000;
      }
      else if(like == 3) {
        ans += 100;
      }
      else if(like == 2) {
        ans += 10;
      }
      else if(like == 1) {
        ans += 1;
      }
    }
  }
  cout << ans;
}

