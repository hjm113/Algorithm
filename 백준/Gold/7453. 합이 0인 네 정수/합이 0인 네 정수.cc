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
ll a[4005];
ll b[4005];
ll c[4005];
ll d[4005];
int n;
vector <ll> fst;
vector <ll> snd;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      fst.push_back(a[i]+b[j]);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      snd.push_back(c[i]+d[j]);
    }
  }
  sort(fst.begin(),fst.end());
  sort(snd.begin(),snd.end());
  /*
  for(int i = 0; i < fst.size(); i++) {
    cout << fst[i] << " ";
  }
  cout << "\n";
  for(int i = 0; i < snd.size(); i++) {
    cout << snd[i] << " ";
  }
  cout << "\n";
  */
  ll ans = 0;
  
  for(int i = 0; i < fst.size(); i++) {
    ll ub = upper_bound(snd.begin(),snd.end(),-fst[i]) - snd.begin();
    ll lb = lower_bound(snd.begin(),snd.end(),-fst[i]) - snd.begin();
    if(ub-lb > 0) {
      //cout << fst[i] << "\n";
      ans += (ub-lb);
    }
  }
  cout << ans;
}