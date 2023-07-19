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
using ll = long long;
#define X first
#define Y second
int board[205][205];
vector<int> fri;
int n, m, r;
int mx = 200000000;
int num;
vector<pair<int,int>> ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      board[i][j] = mx;
    }
  }
  for(int i = 0; i < m; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    board[a][b] = min(board[a][b],l);
  }
  for(int i = 1; i <= n; i++) {
    board[i][i] = 0;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        board[i][j] = min(board[i][j],board[i][k]+board[k][j]);
      }
    }
  }
  cin >> num;
  for(int i = 0; i < num; i++) {
    int p;
    cin >> p;
    fri.push_back(p);
  }
  for(int i = 1; i <= n; i++) {
    int mxx = 0;
    for(int j = 0; j < fri.size(); j++) {
      if(mxx < board[fri[j]][i]+board[i][fri[j]]) {
        mxx = board[fri[j]][i]+board[i][fri[j]];
      }
    }
    ans.push_back({mxx,i});
  }
  sort(ans.begin(),ans.end());
  cout << ans[0].Y << " ";
  for(int i = 1; i < ans.size(); i++) {
    if(ans[0].X < ans[i].X) {
      return 0;
    }
    cout << ans[i].Y << " ";
  }
}