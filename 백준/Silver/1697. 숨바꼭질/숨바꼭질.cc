#include <iostream>
#include <queue>
using namespace std;
int vis[100005];
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  queue<int> q;
  vis[n] = 1;
  q.push(n);
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 3; i++) {
      if(i == 0) {
        int nxt = cur+1;
        if(nxt < 0 || nxt > 100000) {
          continue;
        }
        if(vis[nxt] > 0) {
          continue;
        }
        vis[nxt] = vis[cur]+1;
        q.push(nxt);
      }
      else if(i == 1) {
        int nxt = cur-1;
        if(nxt < 0 || nxt > 100000) {
          continue;
        }
        if(vis[nxt] > 0) {
          continue;
        }
        vis[nxt] = vis[cur]+1;
        q.push(nxt);
      }
      else {
        int nxt = cur*2;
        if(nxt < 0 || nxt > 100000) {
          continue;
        }
        if(vis[nxt] > 0) {
          continue;
        }
        vis[nxt] = vis[cur]+1;
        q.push(nxt);
      }
    }
  }
  cout << vis[k]-1;
}