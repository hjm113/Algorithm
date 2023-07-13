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
vector<int> adj[1005];
int deg[1005];
int n, m;
queue<int> q;
vector<string> ans1;
vector<string> ans2[1005];
map<string, int> mp;
vector<string> name;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    name.push_back(s);
  }
  sort(name.begin(),name.end());
  for(int i = 0; i < n; i++) {
    mp[name[i]] = i;
  }
  cin >> m;
  for(int i = 0; i < m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    deg[mp[s1]]++;
    adj[mp[s2]].push_back(mp[s1]);
  }
  for(int i = 0; i < n; i++) {
    sort(adj[i].begin(),adj[i].end());
    if(deg[i] == 0) {
      ans1.push_back(name[i]);
      q.push(i);
    }
  }
  cout << ans1.size() << "\n";
  for(auto ele : ans1) {
    cout << ele << " ";
  }
  cout << "\n";
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      deg[nxt]--;
      if(deg[nxt] == 0) {
        ans2[cur].push_back(name[nxt]);
        q.push(nxt);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << name[i] << " ";
    cout << ans2[i].size() << " ";
    for(auto ele : ans2[i]) {
      cout << ele << " ";
    }
    cout << "\n";
  }
}