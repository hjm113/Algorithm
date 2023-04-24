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
int n;
int num[11];
int ary[11];
tuple<int,char> ing[11][5][5];
int check[11];
int rot[11];
int posi[11];
int mx = 0;
int cnt = 0;
tuple<int,char> ans[6][6] = {};
void revol(int st, int idx, int how) {
  tuple<int,char> tmp[5][5] = {};
  tuple<int,char> sub[5][5] = {};
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      int x;
      char y;
      tie(x,y) = ing[idx][i][j];
      sub[i][j] = make_tuple(x,y);
    }
  }
  for(int c = 0; c < how; c++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = sub[i][j];
        tmp[j][4-1-i] = {x,y};
      }
    }
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = tmp[i][j];
        sub[i][j] = {x,y};
      }
    }
  }
  if(st == 0) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = ans[i][j];
        int sx;
        char sy;
        tie(sx,sy) = sub[i][j];
        int add = x + sx;
        if(add < 0) {
          add = 0;
        }
        else if(add > 9) {
          add = 9;
        }
        if(sy != 'W') {
          ans[i][j] = make_tuple(add,sy);
        }
        else {
          ans[i][j] = make_tuple(add,y);
        }
      }
    }
  }
  else if(st == 1) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = ans[i][j+1];
        int sx;
        char sy;
        tie(sx,sy) = sub[i][j];
        int add = x + sx;
        
        if(add < 0) {
          add = 0;
        }
        else if(add > 9) {
          add = 9;
        }
        if(sy != 'W') {
          ans[i][j+1] = make_tuple(add,sy);
        }
        else {
          ans[i][j+1] = make_tuple(add,y);
        }
      }
    }
  }
  else if(st == 2) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = ans[i+1][j];
        int sx;
        char sy;
        tie(sx,sy) = sub[i][j];
        int add = x + sx;
        if(add < 0) {
          add = 0;
        }
        else if(add > 9) {
          add = 9;
        }
        if(sy != 'W') {
          ans[i+1][j] = make_tuple(add,sy);
        }
        else {
          ans[i+1][j] = make_tuple(add,y);
        }
      }
    }
  }
  else if(st == 3) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int x;
        char y;
        tie(x,y) = ans[i+1][j+1];
        int sx;
        char sy;
        tie(sx,sy) = sub[i][j];
        int add = x + sx;
        if(add < 0) {
          add = 0;
        }
        else if(add > 9) {
          add = 9;
        }
        if(sy != 'W') {
          ans[i+1][j+1] = make_tuple(add,sy);
        }
        else {
          ans[i+1][j+1] = make_tuple(add,y);
        }
      }
    }
  }
}
void pos(int k, int many[], int rota[]) {
  if(k == 3) {
    //cout << "\n";
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        ans[i][j] = make_tuple(0,'W');
      }
    }
    for(int i = 0; i < k; i++) {
      revol(posi[i], many[i], rota[i]);
      //cout << posi[i] << " " << many[i] << " " << rota[i] << "\n";
    }
    //cout << "\n";
    cnt++;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        int x;
        char y;
        tie(x,y) = ans[i][j];
        //cout << x << " ";
      }
     // cout << "\n";
    }
    if(cnt == 5) {
      //exit(0);
    }
    int sumr = 0;
    int sumg = 0;
    int sumb = 0;
    int sumy = 0;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        int x;
        char y;
        tie(x,y) = ans[i][j];
        if(y == 'R') {
          sumr += x;
        }
        else if(y == 'G') {
          sumg += x;
        }
        else if(y == 'B') {
          sumb += x;
        }
        else if(y == 'Y') {
          sumy += x;
        } 
      }
    }
    int fians = (sumr*7) + (sumb*5) + (sumg*3) + (sumy*2);
    if(mx < fians) {
      mx = fians;
    }
    return;
  }
  for(int i = 0; i < 4; i++) {
    posi[k] = i;
    pos(k+1,many,rota);
  }
}
void rotate(int k, int many[]) {
  if(k == 3) {
    pos(0,many,rot);
    return;
  }
  for(int i = 0; i < 4; i++) {
    rot[k] = i;
    rotate(k+1,many);
  }
}
void func(int k, int order[]) {
  if(k == 3) {
    rotate(0,ary);
    return;
  }
  int count = 0;
  while(1) {
    if(order[count] == 1) {
      if(check[count] == 0) {
        ary[k] = count;
        check[count] = 1;
        func(k+1,order);
        check[count] = 0;
      }
    }
    count++;
    if(count == 10) {
      break;
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        int sc;
        cin >> sc;
        ing[i][j][k] = make_tuple(sc,' ');
      }
    }
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        char ele;
        cin >> ele;
        int x;
        char y;
        tie(x,y) = ing[i][j][k];
        ing[i][j][k] = make_tuple(x,ele);
      }
    }
  }
  for(int i = n-3; i < n; i++) {
    num[i] = 1;
  }
  do{
    func(0, num);
  }while(next_permutation(num,num+n));
  cout << mx;
}

