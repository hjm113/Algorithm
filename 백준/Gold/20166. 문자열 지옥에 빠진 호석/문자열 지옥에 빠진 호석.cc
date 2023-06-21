#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;
#define X first
#define Y second
int dx[9] = {1,-1,0,0,1,1,-1,-1};
int dy[9] = {0,0,1,-1,1,-1,1,-1};
int n, m, k;
char board[12][12];
unordered_map<string,int> map;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      string tmp = "";
      tmp += board[i][j];
      queue<tuple<int,int,string>> q;
      q.push(make_tuple(i,j,tmp));
      map[tmp]++;
      while(!q.empty()) {
        int x, y;
        string str;
        tie(x,y,str) = q.front();
        q.pop();
        if(str.length() >= 5) {
          break;
        }
        for(int dir = 0; dir < 8; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          nx %= n;
          ny %= m;
          if(nx < 0) {
            nx = n-1;
          }
          if(ny < 0) {
            ny = m-1;
          }
          string nstr = str + board[nx][ny];
          q.push(make_tuple(nx,ny,nstr));
          map[nstr]++;
        }
      }

    }
  }
  for(int i = 0; i < k; i++) {
    string find;
    cin >> find;
    cout << map[find] << "\n";
  }
}
