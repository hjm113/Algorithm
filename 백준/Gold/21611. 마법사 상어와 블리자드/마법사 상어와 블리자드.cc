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
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int n, m;
int board[55][55];
int tmp[55][55];
int check[55][55];
int marvel = 0;
int ans = 0;
tuple<int,int> magic[105];
tuple<int,int> order[3000];
void moving() {
  for(int i = 1; i < marvel; i++) {
    int x, y;
    tie(x,y) = order[i];
    int stat = i;
    int col = board[x][y];
    if(board[x][y] > 0) {
      while(1) {
        int ori = stat;
        stat--;
        int bx,by;
        tie(bx,by) = order[stat];
        int ox,oy;
        tie(ox,oy) = order[ori];
        if(board[bx][by] > 0 || stat == 0) {
          break;
        }
        board[bx][by] = col;
        board[ox][oy] = 0;
      }
    }
  }
}
void bombing() {
  while(1) {
    int count = 0;
    int esc = 0;
    int col = 0;
    deque<pair<int,int>> bomb;
    for(int i = 1; i < marvel; i++) {
      int x, y;
      tie(x,y) = order[i];
      if(i == 1) {
        col = board[x][y];
      }
      if(col == board[x][y]) {
        bomb.push_back({x,y});
        count++;
      }
      else {
        if(count > 3) {
          int cl = 0;
          int cnt = 0;
          while(!bomb.empty()) {
            esc = 1;
            auto cur = bomb.front();
            bomb.pop_front();
            cl = board[cur.X][cur.Y];
            cnt++;
            board[cur.X][cur.Y] = 0;
          }
          if(cl == 1) {
            ans += cnt;
          }
          else if(cl == 2) {
            ans += (cnt*2);
          }
          else if(cl == 3) {
            ans += (cnt*3);
          }
        }
        while(!bomb.empty()) {
          bomb.pop_back();
        }
        col = board[x][y];
        bomb.push_back({x,y});
        count = 1;
      }
    }
    
    moving();
    if(esc == 0) {
      break;
    } 
  }
}
void numing() {
  int sx = n/2;
  int sy = (n/2)-1;
  int count = 2;
  int num = 0;
  int out = n / 2;
  while(1) {
    int turn = count;
    while(1) {
      turn--;
      num++;
      order[num] = make_tuple(sx,sy);
      check[sx][sy] = num;
      if(turn == 0) {
        break;
      }
      sx++;
    }
    turn = count;
    while(turn > 0) {
      sy++;
      num++;
      order[num] = make_tuple(sx,sy);
      check[sx][sy] = num;
      turn--;
    }
    
    turn = count;
    while(turn > 0) {
      sx--;
      num++;
      order[num] = make_tuple(sx,sy);
      check[sx][sy] = num;
      turn--;
    }
    
    turn = count;
    while(turn > 0) {
      sy--;
      num++;
      order[num] = make_tuple(sx,sy);
      check[sx][sy] = num;
      turn--;
    }
    sy--;
    count += 2;
    if(num == marvel-1) {
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  marvel = n*n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < m; i++) {
    int d, s;
    cin >> d >> s;
    magic[i] = make_tuple(d,s);
  }
  numing();
  /*
      
  */
  for(int c = 0; c < m; c++) {
    int d, s;
    tie(d,s) = magic[c];
    int posx = n / 2;
    int posy = n / 2;
    while(s > 0) {
      posx += dx[d];
      posy += dy[d];
      board[posx][posy] = 0;
      s--;
    }
    
    moving();
    
    bombing();
    
    
    int count = 1;
    int cl = 0;
    int ary[5] = {};
    for(int i = 1; i < marvel; i++) {
      int x, y;
      tie(x,y) = order[i];
      if(i == 1) {
        cl = board[x][y];
      }
      if(cl == board[x][y]) {
        ary[cl]++;
      }
      else {
        int rx, ry;
        tie(rx,ry) = order[count];
        tmp[rx][ry] = ary[cl];
        count++;
        int rsx, rsy;
        tie(rsx,rsy) = order[count];
        tmp[rsx][rsy] = cl;
        count++;
        if(count == marvel) {
          break;
        } 
        ary[cl] = 0;
        cl = board[x][y];
        ary[cl]++;
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        board[i][j] = tmp[i][j];
        tmp[i][j] = 0;
      }
    }
  }
  cout << ans;
}

