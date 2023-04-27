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
int tmp[110][110];
deque<int> water[110];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void flip(int h2, int len) {
  int copy[110][110] = {};
  for(int i = 0; i < h2; i++) {
    for(int j = 0; j < len; j++) {
      copy[i][len-j] = tmp[i][j];
    }
  }
  for(int i = 0; i < h2; i++) {
    for(int j = 0; j < len; j++) {
      tmp[i][j] = copy[i][j];
    }
  }
}
void adjust() {
  int sub[110][110] = {};
  for(int i = 0; i < n; i++) {
    if(water[i].size() == 0) {
      continue;
    }
    for(int j = 0; j < water[i].size(); j++) {
      int num = water[i][j];
      sub[i][j] += num;
      for(int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx < 0 || ny < 0 || ny >= water[i].size()) {
          continue;
        }
        if(water[nx].size() <= ny) {
          continue;
        }
        if(water[i][j] > water[nx][ny]) {
          int check = abs(num-water[nx][ny]) / 5;
          if(i == 0 && j == 2) {
            //cout << nx << ny << " " << check << "\n";
          }
          sub[nx][ny] += check;
          sub[i][j] -= check;
        }
      }
    }
  }
  /*
  cout << "\n";
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
          if(water[i].size() > 0) {
            cout << water[i][j] << " ";
          }
          else {
            cout << 0 << " ";
          }
          
        }
        cout << "\n";
      }
   cout << "\n";
      for(int i = 0; i < 10; i++) {
        cout << water[i].size();
        cout << "\n";
      }
      */
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < water[i].size(); j++) {
      if(sub[i][j] > 0) {
        water[i][j] = sub[i][j];
      }
    }
  }
}


void rotate(int x, int y) {
  int copy[110][110] = {};
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      copy[y-1-j][i] = tmp[i][j];
      tmp[i][j] = 0;
    }
  }
  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
      tmp[i][j] = copy[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    water[0].push_back(a);
  }
  int ans = 0;
  while(1) {
    ans++;
    int mn = 1000000;
    for(int i = 0; i < n; i++) {
      if(mn > water[0][i]) {
        mn = water[0][i];
      }
    }
    for(int i = 0; i < n; i++) {
      if(mn == water[0][i]) {
        water[0][i]++;
      }
    }
    int st = water[0][0];
    water[0].pop_front();
    water[1].push_front(st);
    /*
    cout << "\n";
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
          if(water[i].size() > 0) {
            cout << water[i][j] << " ";
          }
          else {
            cout << 0 << " ";
          }
          
        }
        cout << "\n";
      }
    */
    int cntx = 2;
    int cnty = 1;
    int cnt = 0;
    int h1 = 0;
    while(1) {
      if(water[0].size()-cnty < cntx) {
        break;
      }
      for(int i = 0; i < cntx; i++) {
        for(int j = 0; j < cnty; j++) {
          tmp[i][j] = water[i].front();
          water[i].pop_front();
        }
      }
      rotate(cntx, cnty);
      for(int i = 0; i < cnty; i++) {
        for(int j = cntx-1; j >= 0; j--) {
          water[i+1].push_front(tmp[i][j]);
          tmp[i][j] = 0;
        }
      }
      h1 = 1 + cnty;
      /*
       cout << "\n";
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
          if(water[i].size() > 0) {
            cout << water[i][j] << " ";
          }
          else {
            cout << 0 << " ";
          }
          
        }
        cout << "\n";
      }
      */
      if(cnt % 2 == 0) {
        cnty++;
      }
      else if(cnt % 2 == 1) {
        cntx++;
      }
      cnt++;
    }
    adjust();
    /*
     cout << "\n";
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
          if(water[i].size() > 0) {
            cout << water[i][j] << " ";
          }
          else {
            cout << 0 << " ";
          }
          
        }
        cout << "\n";
      }
    */
    //cout << h1 << "he";
    deque<int> sto;
    while(1) {
      int out = 0;
      for(int i = 0; i < h1; i++) {
        if(water[i].size() == 0) {
          out = 1;
          break;
        }
        sto.push_back(water[i].front());
        water[i].pop_front();
      }
      if(out == 1) {
        break;
      }
    }
    while(!sto.empty()) {
      water[0].push_front(sto.back());
      sto.pop_back();
    }
    /*
    cout << "\n";
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        if(water[i].size() > 0) {
          cout << water[i][j] << " ";
        }
        else {
          cout << 0 << " ";
        }
        
      }
      cout << "\n";
    }
    */
    int h2 = 1;
    int len = n/2;
    int count = 2;
    while(count > 0) {
      for(int i = 0; i < h2; i++) {
        for(int j = 0; j < len; j++) {
          tmp[i][j] = water[i].front();
          water[i].pop_front();
        }
      }
      int u = 0;
      for(int i = h2*2-1; i >= h2; i--) {
        for(int j = 0; j < len; j++) {
          water[i].push_front(tmp[u][j]);
          tmp[u][j] = 0;
        }
        u++;
      }
      count--;
      h2 *= 2;
      len /= 2;
    }
    adjust();
    //cout << h2 << "he";
    while(1) {
      int out = 0;
      for(int i = 0; i < h2; i++) {
        if(water[i].size() == 0) {
          out = 1;
          break;
        }
        sto.push_back(water[i].front());
        water[i].pop_front();
      }
      if(out == 1) {
        break;
      }
    }
    while(!sto.empty()) {
      water[0].push_front(sto.back());
      sto.pop_back();
    }
    int mx = 0;
    int min = 100000;
    for(int i = 0; i < n; i++) {
      if(mx < water[0][i]) {
        mx = water[0][i];
      }
      if(min > water[0][i]) {
        min = water[0][i];
      }
    }
    if(mx-min <= k) {
      break;
    }

  }
  cout << ans;
}