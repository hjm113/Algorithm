#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
char board[25][25];
int n, m;
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
map<char,int> mp;
int mx = 0;
void dfs(int x, int y, int k) {
  mp[board[x][y]] = 1;
  int check = 0;
  for(int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(mp[board[nx][ny]] == 1) {
      continue;
    }
    if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
      continue;
    }
    dfs(nx,ny,k+1);
    mp[board[nx][ny]] = 0;
    check = 1;
  }
  if(check == 0) {
    if(mx < k) {
      mx = k;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  dfs(0,0,1);
  cout << mx;
}
