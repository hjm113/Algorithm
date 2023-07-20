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
using ll = long long;
#define X first
#define Y second
int dno[105][105];
double dyes[105][105];
int n, m, r, k;
vector<string> vis;
map<string, int> mp;
int mx = 500000000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r;
  int cnt = 1;
  for(int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if(mp[s] > 0) {
      continue;
    }
    mp[s] = cnt;
    cnt++;
  }
  n = cnt;
  cin >> m;
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    vis.push_back(s);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      dyes[i][j] = mx;
      dno[i][j] = mx;
    }
  }
  cin >> k;
  for(int i = 0; i < k; i++) {
    string type, s, e;
    double cost;
    cin >> type >> s >> e >> cost;
    if(dno[mp[s]][mp[e]] > cost) {
      dno[mp[s]][mp[e]] = cost;
    }
    if(dno[mp[e]][mp[s]] > cost) {
      dno[mp[e]][mp[s]] = cost;
    }
    
    if(type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
      if(dyes[mp[s]][mp[e]] > 0) {
        dyes[mp[s]][mp[e]] = 0;
      }
      if(dyes[mp[e]][mp[s]] > 0) {
        dyes[mp[e]][mp[s]] = 0;
      }
    }
    else if(type == "S-Train" || type == "V-Train") {
      if(dyes[mp[s]][mp[e]] > cost/2) {
        dyes[mp[s]][mp[e]] = cost/2;
      }
      if(dyes[mp[e]][mp[s]] > cost/2) {
        dyes[mp[e]][mp[s]] = cost/2;
      }
    }
    else {
      if(dyes[mp[s]][mp[e]] > cost) {
        dyes[mp[s]][mp[e]] = cost;
      }
      if(dyes[mp[e]][mp[s]] > cost) {
        dyes[mp[e]][mp[s]] = cost;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    dyes[i][i] = 0;
    dno[i][i] = 0;
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        dyes[i][j] = min(dyes[i][j],dyes[i][k]+dyes[k][j]);
        dno[i][j] = min(dno[i][j],dno[i][k]+dno[k][j]);
      }
    }
  }
  double sumyes = r;
  for(int i = 0; i < vis.size()-1; i++) {
    sumyes += dyes[mp[vis[i]]][mp[vis[i+1]]]; 
  }
  double sumno = 0;
  for(int i = 0; i < vis.size()-1; i++) {
    sumno += dno[mp[vis[i]]][mp[vis[i+1]]]; 
  }
  //cout << sumyes << " " << sumno;
  if(sumyes < sumno) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}