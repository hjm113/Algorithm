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
int t;
int prime[10005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  prime[1] = 1;
  for(int i = 2; i*i < 10000; i++) {
    if(prime[i] == 1) {
      continue;
    }
    for(int j = i*i; j < 10000; j+= i) {
      prime[j] = 1;
    }
  }

  while(t--) {
    int n, k;
    cin >> n >> k;
    int vis[10005] = {};
    vis[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      int f = (cur/10)*10;
      for(int i = 0; i < 10; i++) {
        if(prime[f+i] == 1 || vis[f+i] > 0) {
          continue;
        }
        vis[f+i] = vis[cur] + 1;
        q.push(f+i);
      }
      int l = cur % 10;
      int s = (cur/100)*100+l;
      for(int i = 0; i < 100; i+=10) {
        if(prime[s+i] == 1 || vis[s+i] > 0) {
          continue;
        }
        vis[s+i] = vis[cur] + 1;
        q.push(s+i);
      }
      int ll = cur % 100;
      int ss = (cur/1000)*1000+ll;
      for(int i = 0; i < 1000; i+=100) {
        if(prime[ss+i] == 1 || vis[ss+i] > 0) {
          continue;
        }
        vis[ss+i] = vis[cur] + 1;
        q.push(ss+i);
      }
      int sss = cur % 1000;
      for(int i = 1000; i < 10000; i+=1000) {
        if(prime[sss+i] == 1 || vis[sss+i] > 0) {
          continue;
        }
        vis[sss+i] = vis[cur] + 1;
        q.push(sss+i);
      }
      
    }
    if(vis[k] == 0) {
      cout << "Impossible\n";
    }
    else {
      cout << vis[k]-1 << "\n";
    }
  }
}