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
int people[15];
int dist[15];
int mx = INT_MAX;
vector<int> area[15];
int n;

void func(int k) {
  if(k == n) {
    vector<int> a[15];
    vector<int> b[15];
    int checka[15] = {};
    int checkb[15] = {};
    int ap[15] = {};
    int bp[15] = {};
    int visa[15] = {};
    int visb[15] = {};
    int fst = 0;
    int snd = 0;
    int checkf = 0;
    int checks = 0;
    for(int i = 1; i <= k; i++) {
      if(dist[i] == 0) {
        fst = i;
        checkf = 1;
        checka[i] = 1;
        ap[i] = 1;
        for(int j = 0; j < area[i].size(); j++) {
          a[i].push_back(area[i][j]);
        }
      }
      if(dist[i] == 1){
        snd = i;
        checks = 1;
        checkb[i] = 1;
        bp[i] = 1;
        for(int j = 0; j < area[i].size(); j++) {
          b[i].push_back(area[i][j]);
        }
      }
    }
    if(checkf == 0 || checks == 0) {
      return;
    }
    queue<int> qa;
    visa[fst] = 1;
    qa.push(fst);
    checka[fst] = 0;
    while(!qa.empty()) {
      auto cur = qa.front();
      qa.pop();
      if(a[cur].size() == 0) {
        continue;
      }
      for(int dir = 0; dir < a[cur].size(); dir++) {
        if(visa[a[cur][dir]] == 0) {
          qa.push(a[cur][dir]);
          visa[a[cur][dir]] = 1;
          checka[a[cur][dir]] = 0;
        }
      }
    }
    queue<int> qb;
    visb[snd] = 1;
    qb.push(snd);
    checkb[snd] = 0;
    while(!qb.empty()) {
      auto cur = qb.front();
      qb.pop();
      if(b[cur].size() == 0) {
        continue;
      }
      for(int dir = 0; dir < b[cur].size(); dir++) {
        if(visb[b[cur][dir]] == 0) {
          qb.push(b[cur][dir]);
          visb[b[cur][dir]] = 1;
          checkb[b[cur][dir]] = 0;
        }
      }
    }
    for(int i = 1; i < 15; i++) {
      if(checka[i] == 1 || checkb[i] == 1) {
        return;
      }
    }
    int suma = 0;
    int sumb = 0;
    //cout << "\n";
    for(int i = 0; i < 15; i++) {
      if(ap[i] == 1) {
        //cout << i << " aaaa" << "\n";
        suma += people[i];
      }
      if(bp[i] == 1) {
        //cout << i << " bbbb"<< "\n";
        sumb += people[i];
      }
    }
    
    int ans = abs(suma - sumb);
    //cout << ans << "\n";;
    if(mx > ans) {
      mx = ans;
    }
    return;
  }
  for(int i = 0; i < 2; i++) {
    dist[k] = i;
    func(k+1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> people[i];
  }
  for(int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    for(int j = 0; j < num; j++) {
      int conn;
      cin >> conn;
      area[i].push_back(conn);
      area[conn].push_back(i);
    }
  }
  func(1);
  if(mx == INT_MAX) {
    cout << -1;
  }
  else {
    cout << mx;
  }
  
}

