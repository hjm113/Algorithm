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
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sdx[4] = {-1, 0, 1, 0};
int sdy[4] = {0, -1, 0, 1};
int smell[5][5];
vector<tuple<int,int,int>> fish;
vector<pair<int,int>> sto;
vector<int> board[5][5];
int sx;
int sy;
int m, s;
int ary[3];
int mov[3] = {9,9,9};
int msi = 0;
void sharkf(int k, int nsx, int nsy, int size, vector<vector<int>> amo) {
  if(k == 3) {
    
    if(size > msi) {
      //cout << "\n";
      for(int i = 0; i < k; i++) {
        mov[i] = ary[i];
        //cout << mov[i] << " ";
      }
      /*
      cout << "\n";
      cout << "\n";
      for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        cout << amo[i][j] << " ";
      }
      cout << "\n";
    }
      cout << "\n";
      cout << size;
      cout << "\n";
      */
      msi = size;
    }
    else if(size == msi) {
      int fst = 0;
      int snd = 0;
      int count = 100;
      for(int i = 0; i < k; i++) {
        fst += ary[i] * count;
        count %= 10;
      }
      count = 100;
      for(int i = 0; i < k; i++) {
        snd += mov[i] * count;
        count %= 10;
      }
      if(fst < snd) {
        for(int i = 0; i < k; i++) {
          mov[i] = ary[i];
        }
      }
    }
    return;
  }
  for(int i = 0; i < 4; i++) {
    int nx = nsx + sdx[i];
    int ny = nsy + sdy[i];
    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
      continue;
    }
    ary[k] = i;
    int tmp = amo[nx][ny];
    size += amo[nx][ny];
    amo[nx][ny] = 0;
    sharkf(k+1,nx,ny,size,amo);
    size -= tmp;
    amo[nx][ny] = tmp;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> s;
  for(int i = 0; i < m; i++) {
    int fx, fy, d;
    cin >> fx >> fy >> d;
    fx--;
    fy--;
    d--;
    fish.push_back(make_tuple(fx,fy,d));
  }
  cin >> sx >> sy;
  sx--;
  sy--;
  while(s > 0) {
    vector<tuple<int,int,int>> tmp;
    for(int i = 0; i < fish.size(); i++) {
      int fx, fy, d;
      tie(fx,fy,d) = fish[i];
      tmp.push_back(make_tuple(fx,fy,d));
    }
    vector<tuple<int,int,int>> fitmp;
    while(!fish.empty()) {
      int fx, fy, dir;
      tie(fx,fy,dir) = fish.back();
      fish.pop_back();
      int cnt = 0;
      while(1) {
        int nx = fx + dx[dir];
        int ny = fy + dy[dir];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
          dir = (dir+7) % 8;
        }
        else if(nx == sx && ny == sy) {
          dir = (dir+7) % 8;
        }
        else if(smell[nx][ny] > 0) {
          dir = (dir+7) % 8;
        }
        else {
          fitmp.push_back(make_tuple(nx,ny,dir));
          break;
        }
        cnt++;
        if(cnt == 8) {
          fitmp.push_back(make_tuple(fx,fy,dir));
          break;
        }
      } 
    }
    while(!fitmp.empty()) {
      int fx, fy, dir;
      tie(fx,fy,dir) = fitmp.back();
      fitmp.pop_back();
      board[fx][fy].push_back(dir);
    }
    vector<vector<int>> amo (4, vector<int> (4,0));
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        if(board[i][j].size() > 0) {
          amo[i][j] = board[i][j].size();
        }
      }
    }
    /*
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        cout << amo[i][j] << " ";
      }
      cout << "\n";
    }
     cout << "what";
    */
    msi = 0;
    for(int i = 0; i < 3; i++) {
      mov[i] = 9;
    }
    sharkf(0,sx,sy,0,amo);
    /*
     cout << "\n";
    for(int i = 0; i < 3; i++) {
      cout << mov[i] << " ";
    }
     cout << "\n";
    */
    for(int i = 0; i < 3; i++) {
      sx += sdx[mov[i]];
      sy += sdy[mov[i]];
      if(board[sx][sy].size() > 0) {
        while(!board[sx][sy].empty()) {
          board[sx][sy].pop_back();
        }
        smell[sx][sy] = 3;
      }
    }
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        if(smell[i][j] > 0) {
          smell[i][j]--;
        }
      }
    }
    while(!tmp.empty()) {
      int fx, fy, d;
      tie(fx,fy,d) = tmp.back();
      tmp.pop_back();
      board[fx][fy].push_back(d);
    }
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        while(!board[i][j].empty()) {
          fish.push_back(make_tuple(i,j,board[i][j].back()));
          board[i][j].pop_back();
        }
      }
    }
    s--;
  }
  cout << fish.size();
  /*
  cout << "\n";
  for(int i = 0; i < fish.size(); i++) {
    int fx, fy, d;
    tie(fx,fy,d) = fish[i];
    cout << fx << fy << " " << d << "\n";
  }
  cout << "\n";
  cout << sx << " " << sy;
  */
}