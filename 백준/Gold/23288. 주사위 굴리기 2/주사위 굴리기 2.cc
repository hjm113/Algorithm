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
int dice[2][4] = {{2,1,5,6},{4,1,3,6}};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m, k;
int board[25][25];

void rotate(int num, int d) {
  if(d == 0 || d == 3) {
    int tmp = dice[num][3];
    for(int i = 2; i >= 0; i--) {
      dice[num][i+1] = dice[num][i];
    }
    dice[num][0] = tmp;
    if(num == 1) {
      dice[0][1] = dice[1][1];
      dice[0][3] = dice[1][3];
    }
    else if(num == 0) {
      dice[1][1] = dice[0][1];
      dice[1][3] = dice[0][3];
    }
    
  }
  else if (d == 1 || d == 2) {
    int tmp = dice[num][0];
    for(int i = 1; i <= 3; i++) {
      dice[num][i-1] = dice[num][i];
    }
    dice[num][3] = tmp;
    if(num == 1) {
      dice[0][1] = dice[1][1];
      dice[0][3] = dice[1][3];
    }
    else if(num == 0) {
      dice[1][1] = dice[0][1];
      dice[1][3] = dice[0][3];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  int dir = 0;
  int posx = 0;
  int posy = 0;
  int ans = 0;
  while(k > 0) {
    int vis[25][25] = {};
    int ox = posx;
    int oy = posy;
    posx = ox + dx[dir];
    posy = oy + dy[dir];
    if(posx < 0 || posx >= n || posy < 0 || posy >= m) {
      dir = (dir+2) % 4;
      posx = ox + dx[dir];
      posy = oy + dy[dir];
    }
    
    if(dir == 0 || dir == 2) {
      rotate(1,dir);
    }
    else if(dir == 1 || dir == 3) {
      rotate(0,dir);
    }
    queue<pair<int,int>> q;
    vis[posx][posy] = 1;
    q.push({posx,posy});
    int sc = board[posx][posy];
    int cnt = 1;
    //cout << posx << " " << posy << "\n";
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int i = 0; i < 4; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        if(vis[nx][ny] > 0 || board[nx][ny] != sc) {
          continue;
        }
        q.push({nx,ny});
        vis[nx][ny] = 1;
        cnt++;
      }
    }
    //cout << sc << " " << cnt << "  scosdfsdf" << "\n";
    ans += (sc*cnt);
    /*
     cout << "\n";
    for(int i = 0; i < 4; i++) {
        cout << dice[1][i] << " ";
      }
    cout << "side " <<"\n";
    for(int i = 0; i < 4; i++) {
        cout << dice[0][i] << " ";
      }
     cout << "\n";
    */
    if(dir == 0 || dir == 2) {
      
     
      if(dice[1][3] < sc) {
        dir = (dir+1) % 4;
      }
      else if(dice[1][3] > sc) {
        if(dir == 0) {
          dir = 3;
        }
        else {
          dir = (dir-1) % 4;
        }
      }
    }
    else if(dir == 1 || dir == 3) {
      if(dice[0][3] < sc) {
        dir = (dir+1) % 4;
      }
      else if(dice[0][3] > sc) {
        if(dir == 0) {
          dir = 3;
        }
        else {
          dir = (dir-1) % 4;
        }
      }
    }
    k--;
  }
  cout << ans;
}

