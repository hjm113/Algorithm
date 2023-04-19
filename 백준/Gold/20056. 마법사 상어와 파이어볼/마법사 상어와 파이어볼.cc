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
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;
tuple<int,int,int,int> board[55][55];
deque<tuple<int,int,int,int,int>> q;
deque<tuple<int,int,int,int,int>> tmp;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    q.push_back(make_tuple(r,c,m,s,d));
  }
  int ans = 0;
  while(k > 0) {
    tuple<int,int,int,int> boardtmp[55][55] = {};
    int mass[55][55] = {};
    int dir[55][55] = {};
    int sp[55][55] = {};
    int check[55][55] = {};
    int cnt[55][55] = {};
    while(!q.empty()) {
      int r,c,m,s,d;
      tie(r,c,m,s,d) = q.front();
      q.pop_front();
      int nx = r;
      int ny = c;
      for(int i = 0; i < s; i++) {
        nx += dx[d];
        ny += dy[d];
        if(nx < 1) {
          nx = n;
        }
        if(ny < 1) {
          ny = n;
        }
        if(nx > n) {
          nx = 1;
        }
        if(ny > n) {
          ny = 1;
        }
      }
      mass[nx][ny] += m;
      sp[nx][ny] += s;
      cnt[nx][ny]++;
      if(cnt[nx][ny] > 1) {
        if(dir[nx][ny] % 2 == 0) {
          if(d % 2 == 1) {
            check[nx][ny] = 1;
          }
        }
        else if(dir[nx][ny] % 2 == 1) {
          if(d % 2 == 0) {
            check[nx][ny] = 1;
          }
        }
      }
      dir[nx][ny] = d;
    }
    /*
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cout << mass[i][j] << " ";
      }
      cout << "\n";
    }
    cout << mass[1][3] << " " << check[1][3]<< " " << cnt[1][3] << "\n";
    */
    int sum = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(cnt[i][j] > 1) {
          mass[i][j] /= 5;
          sp[i][j] /= cnt[i][j];
          //cout << mass[i][j] << "dis" << "\n";
          if(mass[i][j] == 0) {
            continue;
          }
          if(check[i][j] == 1) {
            for(int w = 1; w <= 7; w+=2) {
              q.push_back(make_tuple(i,j,mass[i][j],sp[i][j],w));
              sum += mass[i][j];
            }
          }
          else if(check[i][j] == 0) {
            //cout << "what";
            //cout << mass[i][j] << "mass" << "\n";
            for(int w = 0; w <= 6; w+=2) {
              q.push_back(make_tuple(i,j,mass[i][j],sp[i][j],w));
              sum += mass[i][j];
              //cout << sum << "sum";
            }
          }
        }
        else if(cnt[i][j] == 1) {
          q.push_back(make_tuple(i,j,mass[i][j],sp[i][j],dir[i][j]));
          sum += mass[i][j];
          //cout << "check";
        }
      }
    }
    /*
    cout << "\n";
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cout << mass[i][j] << " ";
      }
      cout << "\n";
    }
    cout << sum << "\n";
    */
    ans = sum;
    k--;
  }
  cout << ans;
}
