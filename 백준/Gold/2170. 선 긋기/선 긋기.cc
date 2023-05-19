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
  for(int i = 1; i < n; i++) {
    if(vc[i].X <= e && vc[i].Y >= e) {
      e = vc[i].Y;
    }
    else if(vc[i].Y > e){
      ans += (e-s);
      s = vc[i].X;
      e = vc[i].Y;
    }
    //cout << ans << "\n";
  }
  //cout << "\n";
  cout << ans + (e-s);
}