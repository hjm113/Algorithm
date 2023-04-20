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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int board[20][20];
int tmpboard[20][20];
int num[20];
int pos[20];
int n,m,d;
int mx = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> d;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      tmpboard[i][j] = board[i][j];
    }
  }
  for(int i = m-3; i < m; i++) {
    num[i] = 1;
  }
  do{
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        board[i][j] = tmpboard[i][j];
      }
    }
    int count = 0;
    for(int i = 0; i < m; i++) {
      if(num[i] == 1) {
        pos[count] = i;
        count++;
      }
    }
    int cnt = 0;
    int die = 0;
    while(1) {
      cnt++;
      queue<pair<int,int>> q;
      vector<pair<int,int>> order;
      for(int i = 0; i < 3; i++) {
        int vis[20][20] = {};
        q.push({n,pos[i]});
        vis[n][pos[i]] = 1;
        int x = n;
        int y = n;
        int len = 1000;
        while(!q.empty()) {
          auto cur = q.front();
          q.pop();
          for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
              continue;
            }
            if(vis[nx][ny] > 0) {
              continue;
            }
            if(vis[cur.X][cur.Y] > d) {
              while(!q.empty()) {
                q.pop();
              }
              break;
            }
            if(board[nx][ny] == 1) {
              //cout << "check";
              if(len < vis[cur.X][cur.Y]) {
                while(!q.empty()) {
                  q.pop();
                }
                break;
              }
              else if(len == vis[cur.X][cur.Y]) {
                if(y > ny) {
                  x = nx;
                  y = ny;
                }
              }
              else if(len > vis[cur.X][cur.Y]) {
                x = nx;
                y = ny;
                len = vis[cur.X][cur.Y];
              }
              //cout << len << "wow";
            }
            q.push({nx,ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
          }
        }
        if(len < 1000) {
          order.push_back({x,y});
        }
        //cout << len << "len";
      }
      /*
      cout << "\n";
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          cout << board[i][j] << " ";
        }
        cout << "\n";
      }
      */
      for(int i = 0; i < order.size(); i++) {
        if(board[order[i].X][order[i].Y] == 1) {
          //cout << order[i].X << " " << order[i].Y << "\n";
          board[order[i].X][order[i].Y] = 0;
          die++;
        }
      }
      /*
      cout << "\n";
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          cout << board[i][j] << " ";
        }
        cout << "\n";
      }
      
      
      cout << "\n";
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          cout << board[i][j] << " ";
        }
        cout << "\n";
      }
      */
      for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
          board[i+1][j] = board[i][j];
        }
      }
      for(int j = 0; j < m; j++) {
        board[0][j] = 0;
      }
      
      if(cnt > n) {
        break;
      }
    } 
    if(mx < die) {
      mx = die;
    }
  }while(next_permutation(num,num+m));
  cout << mx;
}

