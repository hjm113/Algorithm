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
priority_queue< pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
vector<pair<ll,ll>> adj[100005];
ll dst[100005];
ll den[100005];
int pst[100005];
int pen[100005];
int n, m, a, b;
ll c;
ll mx = (1LL<<63)-1;
ll ans = (1LL<<63)-1;
vector<int> pos;

int solve(int st, int en, ll limit) {
  vector<ll> d(100005, mx);
  d[st] = 0;
  pq.push({0,st});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) {
      continue;
    }
    if(cur.Y == en) {
      return 0;
    }
    for(auto nxt : adj[cur.Y]) {
      if(nxt.X > limit) {
        continue;
      }
      if(nxt.X+cur.X > c) {
        continue;
      }
      if(d[nxt.Y] > nxt.X+cur.X) {
        d[nxt.Y] = nxt.X+cur.X;
        pq.push({nxt.X+cur.X,nxt.Y});
      }
    }
  }
  return 1;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> a >> b >> c;
  for(int i = 0; i < m; i++) {
    int st, en;
    ll mon;
    cin >> st >> en >> mon;
    adj[st].push_back({mon,en});
    adj[en].push_back({mon,st});
  }
  ll st = 0;
  ll en = 1000000001;
  while(st < en) {
    ll mid = (st+en)/2;
    if(solve(a,b,mid) == 0) {
      en = mid;
    }
    else {
      st = mid+1;
    }
  }
  if(st == 1000000001) {
    cout << -1;
    return 0;
  }
  cout << st;
}