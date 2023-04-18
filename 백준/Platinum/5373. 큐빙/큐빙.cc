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
int dy[4] = {1, 0, -1, 0};

int cube[6] = {0,1,2,3,4,5};
char board[6][3][3];
int tc, n;
void rotatecw(int rot) {
  char tmp[3][3] = {};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      tmp[j][3-1-i] = board[rot][i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[rot][i][j] = tmp[i][j];
    }
  }
  
}
void rotateccw(int rot) {
  char tmp[3][3] = {};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      tmp[3-1-j][i] = board[rot][i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[rot][i][j] = tmp[i][j];
    }
  }
  
}

void cw1 (int rot, int k, char pos) {
  if(pos == 'R') {
    rotateccw(rot);
  }
  else {
    rotatecw(rot);
  }
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[0][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[0][2-i][k] = board[1][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[1][2-i][k] = board[5][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[5][i][k] = board[3][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[3][i][k] = ary[i];
  }
}
void ccw1 (int rot, int k, char pos) {
  if(pos == 'R') {
    rotatecw(rot);
  }
  else {
    rotateccw(rot);
  }
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[0][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[0][i][k] = board[3][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[3][i][k] = board[5][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[5][2-i][k] = board[1][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[1][2-i][k] = ary[i];
  }
  
}
void cw2 (int rot, int k, char pos) {
  if(pos == 'D') {
    rotateccw(rot);
  }
  else {
    rotatecw(rot);
  }
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[1][k][i];
  }
  for(int i = 2; i <= 4; i++) {
    for(int j = 0; j < 3; j++) {
      if(i-1 == 1) {
        board[i-1][k][2-j] = board[i][k][j];
      }
      else {
        board[i-1][k][j] = board[i][k][j];
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    board[4][k][2-i] = ary[i];
  }
}

void ccw2 (int rot, int k, char pos) {
  if(pos == 'D') {
    rotatecw(rot);
  }
  else {
    rotateccw(rot);
  }
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[4][k][i];
  }
  for(int i = 3; i >= 1; i--) {
    for(int j = 0; j < 3; j++) {
      if(i == 1) {
        board[i+1][k][2-j] = board[i][k][j];
      }
      else {
        board[i+1][k][j] = board[i][k][j];
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    board[1][k][2-i] = ary[i];
  }
}
void cw3 (int rot, int k, char pos) {
  rotatecw(rot);
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[0][k][i];
  }
  for(int i = 0; i < 3; i++) {
    board[0][k][2-i] = board[2][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[2][i][k] = board[5][2-k][i];
  }
  for(int i = 0; i < 3; i++) {
    board[5][2-k][2-i] = board[4][i][2-k];
  }
  for(int i = 0; i < 3; i++) {
    board[4][i][2-k] = ary[i];
  }
}
void ccw3 (int rot, int k, char pos) {
  rotateccw(rot);
  char ary[3] = {};
  for(int i = 0; i < 3; i++) {
    ary[i] = board[0][k][i];
  }
  for(int i = 0; i < 3; i++) {
    board[0][k][i] = board[4][i][2-k];
  }
  for(int i = 0; i < 3; i++) {
    board[4][2-i][2-k] = board[5][2-k][i];
  }
  for(int i = 0; i < 3; i++) {
    board[5][2-k][i] = board[2][i][k];
  }
  for(int i = 0; i < 3; i++) {
    board[2][2-i][k] = ary[i];
  }
}


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  int cnt = 0;
  while(tc > 0){
    
    for(int i = 0; i < 6; i++) {
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          if(i == 0) {
            board[i][j][k] = 'w';
          }
          else if(i == 1) {
            board[i][j][k] = 'o';
          }
          else if(i == 4) {
            board[i][j][k] = 'b';
          }
          else if(i == 2) {
            board[i][j][k] = 'g';
          }
          else if(i == 3) {
            board[i][j][k] = 'r';
          }
          else if(i == 5) {
            board[i][j][k] = 'y';
          }
        }
      }
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
      char pos, dir;
      cin >> pos >> dir;
      if(pos == 'L') {
        if(dir == '+') {
          cw1(2,0,pos);
        }
        if(dir == '-') {
          ccw1(2,0,pos);
        }
      }
      else if(pos == 'R') {
        if(dir == '+') {
          ccw1(4,2, pos);
        }
        if(dir == '-') {
          cw1(4,2,pos);
        }
      }
      else if(pos == 'U') {
        if(dir == '+') {
          cw2(0,0,pos);
        }
        if(dir == '-') {
          ccw2(0,0,pos);
        }
      }
      else if(pos == 'D') {
        if(dir == '+') {
          ccw2(5,2,pos);
        }
        if(dir == '-') {
          cw2(5,2,pos);
        }
      }
      else if(pos == 'F') {
        if(dir == '+') {
          cw3(3,2,pos);
        }
        if(dir == '-') {
          ccw3(3,2,pos);
        }
      }
      else if(pos == 'B') {
        if(dir == '+') {
          ccw3(1,0,pos);
        }
        if(dir == '-') {
          cw3(1,0,pos);
        }
      }
      
      /*
      cout << "\n";
      
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          cout << board[4][j][k];
        }
        cout << "\n";
      }
      cout << "\n";
      
      
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          cout << board[5][j][k];
        }
        cout << "\n";
      }
      cout << cnt;
      cnt++;
       cout << "\n";
      
     
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          cout << board[4][j][k];
        }
        cout << "\n";
      }
      cout << "\n"; */
    }
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        cout << board[0][j][k];
      }
      cout << "\n";
    }
    tc--;
  }
}
