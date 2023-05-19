#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
#define X first
#define Y second
int n, m;
vector<pair<ll, ll>> vc;
bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
  if(a.X < b.X) {
    return true;
  }
  else if(a.X == b.X) {
    return a.Y > b.Y;
  }
  else {
    return false;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    a += 1000000000;
    b += 1000000000;
    if(a > b) {
      vc.push_back({b, a});
    }
    else {
      vc.push_back({a, b});
    }
    
  }
  sort(vc.begin(), vc.end(), cmp);
  /*
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << vc[i].X << " " << vc[i].Y << "\n";
  }
  cout << "\n";
  */
  ll s = vc[0].X;
  ll e = vc[0].Y;
  ll t = e;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(e >= vc[i].X) {
      if(t < vc[i].Y) {
        t = vc[i].Y;
      }
    }
    else {
      s = vc[i].X;
      e = vc[i].Y;
      t = e;
    }
    if(e < vc[i+1].X) {
      ans += (t-s);
      s = t;
      e = t;
    }
    if(i == n-1 && t > s) {
      ans += (t-s);
    }
    //cout << ans << "\n";
  }
  //cout << "\n";
  cout << ans;
}