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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int board[550][550];
int pos[550][550];
int n;
int out = 0;
void left(int x, int y) {
  int nx = x + dx[0];
  int ny = y + dy[0];
  int sand = board[nx][ny];
  int sand7 = sand *7 / 100;
  int sand10 = sand *10 / 100;
  int sand1 = sand *1 / 100;
  int sand2 = sand *2 / 100;
  int sand5 = sand *5 / 100;
  if(nx+1 >= n) {
    out += sand7;
  }
  else {
    board[nx+1][ny] += sand7;
  }
  if(nx-1 < 0) {
    out += sand7;
  }
  else {
    board[nx-1][ny] += sand7;
  }
  
  if(nx+1 >= n || ny-1 < 0) {
    out += sand10;
  }
  else {
    board[nx+1][ny-1] += sand10;
  }
  if(nx-1 < 0 || ny-1 < 0) {
    out += sand10;
  }
  else {
    board[nx-1][ny-1] += sand10;
  }
  if(nx+1 >= n || ny+1 >= n) {
    out += sand1;
  }
  else {
    board[nx+1][ny+1] += sand1;
  }
  if(nx-1 < 0 || ny+1 >= n) {
    out += sand1;
  }
  else {
    board[nx-1][ny+1] += sand1;
  }
  
  if(nx+2 >= n) {
    out += sand2;
  }
  else {
    board[nx+2][ny] += sand2;
  }
  if(nx-2 < 0) {
    out += sand2;
  }
  else {
    board[nx-2][ny] += sand2;
  }
  
  if(ny-2 < 0) {
    out += sand5;
  }
  else {
    board[nx][ny-2] += sand5;
  }
  if(ny-1 < 0) {
    out += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  } 
  else {
    board[nx][ny-1] += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  
  board[nx][ny] = 0;
}

void right(int x, int y) {
  int nx = x + dx[2];
  int ny = y + dy[2];
  int sand = board[nx][ny];
  int sand7 = sand *7 / 100;
  int sand10 = sand *10 / 100;
  int sand1 = sand *1 / 100;
  int sand2 = sand *2 / 100;
  int sand5 = sand *5 / 100;
  if(nx+1 >= n) {
    out += sand7;
  }
  else {
    board[nx+1][ny] += sand7;
  }
  if(nx-1 < 0) {
    out += sand7;
  }
  else {
    board[nx-1][ny] += sand7;
  }
  
  if(nx+1 >= n || ny-1 < 0) {
    out += sand1;
  }
  else {
    board[nx+1][ny-1] += sand1;
  }
  if(nx-1 < 0 || ny-1 < 0) {
    out += sand1;
  }
  else {
    board[nx-1][ny-1] += sand1;
  }
  
  if(nx+1 >= n || ny+1 >= n) {
    out += sand10;
  }
  else {
    board[nx+1][ny+1] += sand10;
  }
  if(nx-1 < 0 || ny+1 >= n) {
    out += sand10;
  }
  else {
    board[nx-1][ny+1] += sand10;
  }
  
  if(nx+2 >= n) {
    out += sand2;
  }
  else {
    board[nx+2][ny] += sand2;
  }
  if(nx-2 < 0) {
    out += sand2;
  }
  else {
    board[nx-2][ny] += sand2;
  }
  
  if(ny+2 >= n) {
    out += sand5;
  }
  else {
    board[nx][ny+2] += sand5;
  }
  if(ny+1 >= n) {
    out += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  else {
    board[nx][ny+1] += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  
  board[nx][ny] = 0;
}

void down(int x, int y) {
  int nx = x + dx[1];
  int ny = y + dy[1];
  int sand = board[nx][ny];
  int sand7 = sand *7 / 100;
  int sand10 = sand *10 / 100;
  int sand1 = sand *1 / 100;
  int sand2 = sand *2 / 100;
  int sand5 = sand *5 / 100;
  if(ny+1 >= n) {
    out += sand7;
  }
  else {
    board[nx][ny+1] += sand7;
  }
  if(ny-1 < 0) {
    out += sand7;
  }
  else {
    board[nx][ny-1] += sand7;
  }
  
  if(ny+1 >= n || nx-1 < 0) {
    out += sand1;
  }
  else {
    board[nx-1][ny+1] += sand1;
  }
  if(ny-1 < 0 || nx-1 < 0) {
    out += sand1;
  }
  else {
    board[nx-1][ny-1] += sand1;
  }
  
  if(ny+1 >= n || nx+1 >= n) {
    out += sand10;
  }
  else {
    board[nx+1][ny+1] += sand10;
  }
  if(ny-1 < 0 || nx+1 >= n) {
    out += sand10;
  }
  else {
    board[nx+1][ny-1] += sand10;
  }
  
  if(ny+2 >= n) {
    out += sand2;
  }
  else {
    board[nx][ny+2] += sand2;
  }
  if(ny-2 < 0) {
    out += sand2;
  }
  else {
    board[nx][ny-2] += sand2;
  }
  
  if(nx+2 >= n) {
    out += sand5;
  }
  else {
    board[nx+2][ny] += sand5;
  }
  if(nx+1 >= n) {
    out += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  else {
    board[nx+1][ny] += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  
  board[nx][ny] = 0;
}

void up(int x, int y) {
  int nx = x + dx[3];
  int ny = y + dy[3];
  int sand = board[nx][ny];
  int sand7 = sand *7 / 100;
  int sand10 = sand *10 / 100;
  int sand1 = sand *1 / 100;
  int sand2 = sand *2 / 100;
  int sand5 = sand *5 / 100;
  if(ny+1 >= n) {
    out += sand7;
  }
  else {
    board[nx][ny+1] += sand7;
  }
  if(ny-1 < 0) {
    out += sand7;
  }
  else {
    board[nx][ny-1] += sand7;
  }
  
  if(ny+1 >= n || nx-1 < 0) {
    out += sand10;
  }
  else {
    board[nx-1][ny+1] += sand10;
  }
  if(ny-1 < 0 || nx-1 < 0) {
    out += sand10;
  }
  else {
    board[nx-1][ny-1] += sand10;
  }
  
  if(ny+1 >= n || nx+1 >= n) {
    out += sand1;
  }
  else {
    board[nx+1][ny+1] += sand1;
  }
  if(ny-1 < 0 || nx+1 >= n) {
    out += sand1;
  }
  else {
    board[nx+1][ny-1] += sand1;
  }
  
  if(ny+2 >= n) {
    out += sand2;
  }
  else {
    board[nx][ny+2] += sand2;
  }
  if(ny-2 < 0) {
    out += sand2;
  }
  else {
    board[nx][ny-2] += sand2;
  }
  
  if(nx-2 < 0) {
    out += sand5;
  }
  else {
    board[nx-2][ny] += sand5;
  }
  if(nx-1 < 0) {
    out += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  else {
    board[nx-1][ny] += sand - (sand7*2 + sand10*2 + sand1*2 + sand2*2 + sand5);
  }
  board[nx][ny] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int st = n / 2;
  int cnt = 1;
  int x = st;
  int y = st;
  int count = 0;
  int good = 1;
  while(1) {
    pos[x][y] = good;
    for(int i = 0; i < cnt; i++) {
      left(x,y);
      x += dx[0];
      y += dy[0];
      if(y < 0) {
        cout << out;
        return 0;
      }
    }
   pos[x][y] = ++good;
    for(int i = 0; i < cnt; i++) {
      down(x,y);
      x += dx[1];
      y += dy[1];
    }
    pos[x][y] = ++good;
    cnt++;
    for(int i = 0; i < cnt; i++) {
      right(x,y);
      x += dx[2];
      y += dy[2];
    }
    pos[x][y] = ++good;
    for(int i = 0; i < cnt; i++) {
      up(x,y);
      x += dx[3];
      y += dy[3];
    }
    pos[x][y] = ++good;
     
    count++;
    cnt++;
    
  }
}
