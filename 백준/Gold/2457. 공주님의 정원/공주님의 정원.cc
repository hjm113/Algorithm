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
int n;
tuple<int,int,int,int> day[100005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y, z, r;
    cin >> x >> y >> z >> r;
    day[i] = make_tuple(x,y,z,r);
  }
  sort(day,day+n);
  int s = 0;
  int cnt = 1;
  tuple <int,int,int,int> ori;
  int check = 1;
  tuple <int,int,int,int> fi;
  int at, bt, ct, dt;
  tie(at,bt,ct,dt) = day[0];
  fi = make_tuple(at,bt,ct,dt);
  for(int i = 0; i < n; i++) {
    int x, y, z, r;
    tie(x,y,z,r) = day[i];
    int aw,bw,cw,dw;
    tie(aw,bw,cw,dw) = fi;
    if(x < 3) {
      check = 0;
      if(z > cw) {
        s = i;
        fi = make_tuple(x,y,z,r);
      }
      else if(z == cw && r > dw) {
        s = i;
        fi = make_tuple(x,y,z,r);
      }
    }
    else if(x == 3 && y == 1) {
      check = 0;
      if(z > cw) {
        s = i;
        fi = make_tuple(x,y,z,r);
      }
      else if(z == cw && r > dw) {
        s = i;
        fi = make_tuple(x,y,z,r);
      }
    }
  }
  if(check == 1) {
    cout << 0;
    return 0;
  }
  int ae,be,ce,de;
  tie(ae,be,ce,de) = fi;
  ori = make_tuple(ae,be,ce,de);
  if(ce > 11) {
    cout << 1;
    return 0;
  }
  /*
  cout << ae << be << ce << de;
  cout << "\n";
  for(int i = 0; i < n; i++) {
    int x, y, z, r;
    tie(x,y,z,r) = day[i];
    cout << x << " " << y << " " << z << " " << r << "\n";
  }
  cout << "\n";
  cout << s << "checkl";
  */
  tuple <int,int,int,int> tmp;
  tmp = make_tuple(ae,be,ce,de);
  for(int i = s+1; i < n; i++) {
    int x, y, z, r;
    tie(x,y,z,r) = day[i];
    int ox,oy,oz,orr;
    tie(ox,oy,oz,orr) = ori;
    int tx,ty,tz,tr;
    tie(tx,ty,tz,tr) = tmp;
    if(x < oz) {
      if(tz < z) {
        tmp = make_tuple(x,y,z,r);
      }
      else if(tz == z && tr <= r) {
        tmp = make_tuple(x,y,z,r);
      }
    }
    else if((x == oz && y <= orr)) {
      if(tz < z) {
        tmp = make_tuple(x,y,z,r);
      }
      else if(tz == z && tr <= r) {
        tmp = make_tuple(x,y,z,r);
      }
    }
    tie(tx,ty,tz,tr) = tmp;
    if(tz > 11) {
      cout << cnt+1;
      return 0;
    }
    tie(x,y,z,r) = day[i+1];
    if(x > oz) {
      cnt++;
      ori = make_tuple(tx,ty,tz,tr);
    }
    else if(x == oz && y > orr) {
      cnt++;
      ori = make_tuple(tx,ty,tz,tr);
    }
    
  }
  cout << 0;
} 