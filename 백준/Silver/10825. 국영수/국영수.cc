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
tuple<string,int,int,int> ary[100005];
int n;
bool cmp(tuple<string,int,int,int> a, tuple<string,int,int,int> b) {
  int x, y, z;
  string name;
  int q, p, r;
  string onam;
  tie(name,x,y,z) = a;
  tie(onam,q,p,r) = b;
  if(x > q) {
    return true;
  }
  else if(x < q) {
    return false;
  }
  else if(x == q) {
    if(y < p) {
      return true;
    }
    else if(y > p) {
      return false;
    }
    else if(y == p) {
      if(z > r) {
        return true;
      }
      else if(z < r) {
        return false;
      }
      else if(z == r) {
        return name < onam;
      }
    }
  }
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b, c;
    string name;
    cin >> name >> a >> b >> c;
    ary[i] = make_tuple(name,a,b,c);
  }
  sort(ary,ary+n,cmp);
  for(int i = 0; i < n; i++) {
    int a, b, c;
    string name;
    tie(name,a,b,c) = ary[i];
    cout << name << "\n";
  }
}