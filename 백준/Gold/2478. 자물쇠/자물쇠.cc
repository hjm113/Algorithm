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
int n, k;
int board[505];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ary[10];
int ori[505];

void find(vector<int> vc, int fst, int snd, int last) {
  int ans = 0;
  for(int i = 1; i < n; i++) {
    int tmp = vc[n-1];
    for(int j = n-2; j >= 0; j--) {
      vc[j+1] = vc[j];
    }
    vc[0] = tmp;  
    int out = 0;
    for(int k = 0; k < n; k++) {
      if(vc[k] != ori[k]) {
        out = 1;
      }
    }
    if(out == 0) {
      ans = i;
      break;
    }
  }
  if(ans > 0) {
    cout << ans << "\n";
    cout << fst + 1 << " " << snd + 1 << "\n";
    cout << last;
    exit(0);
  }
}

void flip(vector<int> vc, int last) {
  int fst = 0;
  int snd = 0;
  for(int i = 0; i < n-1; i++) {
    if(vc[i] == n && vc[i+1] == 1) {
      continue;
    }
    if(vc[i]+1 != vc[i+1]) {
      int st = i;
      fst = i + 1;
      for(int j = st+1; j < n; j++) {
        if(vc[st]+1 == vc[j] || (vc[st] == n && vc[j] == 1)) {
          snd = j;
          break;
        }
      }
    }
    if(snd > 0) {
      break;
    }
  }
  vector<int> tmp;
  for(int i = fst; i <= snd; i++) {
    tmp.push_back(vc[i]);
  }
  int count = 0;
  while(1) {
    vc[snd-count] = tmp[count];
    count++;
    if(count == tmp.size()) {
      break;
    }
  }
  find(vc, fst, snd, last);
}

void move(int last) {
  int tmp = board[n-1];
  for(int i = n-2; i >= 0; i--) {
    board[i+1] = board[i];
  }
  board[0] = tmp;  
  vector<int> sc;
  for(int i = 0; i < n; i++) {
    sc.push_back(board[i]);
  }
/*
  cout << "\n";
  for(int i = 0; i < n; i++) {
    cout << sc[i] << " ";
  }
   cout << "\n";
  */
  flip(sc,last);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
    ori[i] = i+1;
  }
  for(int i = 1; i < n; i++) {
    move(i);
  }
}