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
using namespace std;
using ll = long long;
#define X first
#define Y second
vector<int> adj[101005];
int lc[100];
int rc[100];
int n;
void pre(int cur) {
  cout << char(cur+'A'-1);
  if(lc[cur] > 0) {
    pre(lc[cur]);
  }
  if(rc[cur] > 0) {
    pre(rc[cur]);
  }
} 
void in(int cur) {
  if(lc[cur] > 0) {
    in(lc[cur]);
  }
  cout << char(cur+'A'-1);
  if(rc[cur] > 0) {
    in(rc[cur]);
  }
} 
void post(int cur) {
  if(lc[cur] > 0) {
    post(lc[cur]);
  }
  if(rc[cur] > 0) {
    post(rc[cur]);
  }
  cout << char(cur+'A'-1);
} 

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    char cur, l, r;
    cin >> cur >> l >> r;
    lc[cur-'A'+1] = l-'A'+1;
    rc[cur-'A'+1] = r-'A'+1;
  }
  pre(1);
  cout << "\n";
  in(1);
  cout << "\n";
  post(1);
}