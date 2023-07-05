#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;
#define X first
#define Y second

int n, m;
vector<int> board[1005];
int vis[1005];
void dfs(int x) {
  for(int i = 0; i < board[x].size(); i++) {
    if(vis[board[x][i]] == 1) {
      continue;
    }
    vis[board[x][i]] = 1;
    dfs(board[x][i]);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    board[x].push_back(y);
    board[y].push_back(x);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(vis[i] == 1) {
      continue;
    }
    ans++;
    vis[i] = 1;
    dfs(i);
  }
  cout << ans;
}