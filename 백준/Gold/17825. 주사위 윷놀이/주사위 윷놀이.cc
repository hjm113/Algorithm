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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m, t;
int board[5][100] = {{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38},
{0,2,4,6,8,10,13,16,19,25},
{0,2,4,6,8,10,12,14,16,18,20,22,24},
{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25},
{25,30,35,40,0}
};
int other[5] = {1,2,3,4};
int dice[11];
int ary[11];
int mx = 0;
void func (int k) {
  if(k == 10) {
    int check[5][25] = {};
    int pos[5] = {};
    int map[5] = {};
    int ans = 0;
    for(int i = 0; i < k; i++) {
      check[map[ary[i]]][pos[ary[i]]] = 0;
      if(pos[ary[i]] == -1) {
        return;
      }
      pos[ary[i]] += dice[i];
      if(pos[ary[i]] == 5 && map[ary[i]] == 0) {
        map[ary[i]] = 1;
      }
      else if(pos[ary[i]] == 10 && map[ary[i]] == 0) {
        map[ary[i]] = 2;
      }
      else if(pos[ary[i]] == 15 && map[ary[i]] == 0) {
        map[ary[i]] = 3;
      }
        
      else if(pos[ary[i]] >= 9 && map[ary[i]] == 1) {
        pos[ary[i]] %= 9;
        map[ary[i]] = 4;
      }
      else if(pos[ary[i]] >= 13 && map[ary[i]] == 2) {
        pos[ary[i]] %= 13;
        map[ary[i]] = 4;
      }
      else if(pos[ary[i]] >= 19 && map[ary[i]] == 3) {
        pos[ary[i]] %= 19;
        map[ary[i]] = 4;
      }
      else if(pos[ary[i]] == 20 && map[ary[i]] == 0) {
        pos[ary[i]] = 3;
        map[ary[i]] = 4;
      }
      else if(pos[ary[i]] > 20 && map[ary[i]] == 0) {
        pos[ary[i]] = 4;
        map[ary[i]] = 4;
      }
      
      if(check[map[ary[i]]][pos[ary[i]]] > 0) {
        return;
      }
      ans += board[map[ary[i]]][pos[ary[i]]];
      check[map[ary[i]]][pos[ary[i]]] = 1;
      if(board[map[ary[i]]][pos[ary[i]]] == 0) {
        check[map[ary[i]]][pos[ary[i]]] = 0;
        pos[ary[i]] = -1;
      }
    }
    if(mx < ans) {
      mx = ans;
    }
    return;
  }
  for(int i = 1; i <= 4; i++) {
    ary[k] = i;
    func(k+1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 10; i++) {
    cin >> dice[i];
  }
  func(0);
  cout << mx;
}
