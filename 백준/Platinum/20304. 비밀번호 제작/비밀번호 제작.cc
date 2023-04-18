#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
using namespace std;
#define X first
#define Y second
string board[1600];
string board2[1600];
int vis[1600][1600];
int vis2[1600][1600];
int ary[1000010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  queue <int> q;
  for(int i = 0; i < m; i++) {
    int num;
    cin >> num;
    ary[num] = 1;
    q.push(num);
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int d = 0; d < 32; d++) {
      int nxt = 0;
      if(cur & (1 << d)) {
        nxt = cur & ~(1 << d);
      }
      else {
        nxt = cur | (1 << d);
      }
      if(nxt < 0) {
        continue;
      }
      if(nxt > n) {
        continue;
      }
      if(ary[nxt] > 0) {
        continue;
      }
      ary[nxt] = ary[cur] + 1;
      q.push(nxt);
    }
  }
  int max = 0;
  for(int i = 0; i <= 1000000; i++) {
    if(max < ary[i]) {
      max = ary[i];
    }
  }
  if(max == 0) {
    cout << 0;
  }
  else {
    cout << max - 1;
  }
}