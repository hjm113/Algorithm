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
#include <map>
using namespace std;
#define X first
#define Y second
typedef long long ll;
int n, m;
const int root = 1;
int unused = 2;
const int mx = 10000 * 500 + 5;
int nxt[mx][26];
int chk[mx];
int cnt = 0;
int c2i(char c) {
  return c - 'a';
}

void insert(string &s) {
  int cur = root;
  for(auto c : s) {
    if(nxt[cur][c2i(c)] == -1) {
      nxt[cur][c2i(c)] = unused++;
    }
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = 1;
}

int find(string &s) {
  int cur = root;
  for(auto c : s) {
    if(nxt[cur][c2i(c)] == -1) {
      return 0;
    }
    cur = nxt[cur][c2i(c)];
  }
  return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < mx; i++) {
    for(int j = 0; j < 26; j++) {
      nxt[i][j] = -1;
    }
  }
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s);
  }
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if(find(s) == 1) {
      cnt++;
    }
  }
  cout << cnt;
}
