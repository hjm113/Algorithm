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
int dx[9] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, -1, -1, -1, 0, 1, 1, 1};
int n;
int mx = 0;
vector<vector<pair<int,int>>> board;
void func(int check, int ssum, int sdir, int sx, int sy, vector<vector<pair<int,int>>> ary, vector <pair<int,int>> vec) {
  if(check == 1) {
    
    cout << ssum;
    
    return;
  }
  
  for(int i = 1; i < 17; i++) {
    int x = vec[i].X;
    int y = vec[i].Y;
    int pos = ary[x][y].X;
    int dir = ary[x][y].Y;
    if(dir == -1) {
      continue;
    }
    while(1) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
        dir = (dir+1) % 8;
      }
      else if(nx == sx && ny == sy) {
        dir = (dir+1) % 8;
      }
      else {
        int tmppos = ary[nx][ny].X;
        int tmpdir = ary[nx][ny].Y;
        ary[nx][ny] = {pos,dir};
        ary[x][y] = {tmppos,tmpdir};
        vec[pos] = {nx,ny};
        vec[tmppos] = {x,y};
        break;
      }
    }
  }
 
  int cnt = 0;
  
  while(1) {
    sx += dx[sdir];
    sy += dy[sdir];
    if(sx < 0 || sx >= 4 || sy < 0 || sy >= 4) {
      if(cnt == 0) {
        if(mx < ssum) {
          mx = ssum;
        }
        return;
      }
      break;
    }
    else if(ary[sx][sy].Y > -1) {
      int tmpx = ary[sx][sy].X;
      int tmpy = ary[sx][sy].Y;
      ssum += tmpx;
      ary[sx][sy].Y = -1;
      func(0,ssum,tmpy,sx,sy,ary,vec);
      ary[sx][sy] = {tmpx,tmpy};
      ssum -= tmpx;
      cnt++;
    }
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int,int>> vec(20);
  for(int i = 0; i < 4; i++) {
    vector<pair<int,int>> row;
    for(int j = 0; j < 4; j++) {
      int pos, dir;
      cin >> pos >> dir;
      dir--;
      row.push_back({pos,dir});
      vec[pos] = {i,j};
    }
    board.push_back(row);
  }
  int sum = board[0][0].X;
  int sdir = board[0][0].Y;
  board[0][0].Y = -1;
  func(0,sum,sdir, 0, 0,board,vec);
  cout << mx;
}
