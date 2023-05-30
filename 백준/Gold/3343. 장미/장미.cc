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

ll n, a, b, c, d;
ll ans = LLONG_MAX;

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a >> b >> c >> d;

  if (a * d > b * c) {
    swap(a, c);
    swap(b, d);
  }

  ll lst = lcm(a, c);

  for (ll i = 0; i < (lst / a); i++) {
    ll cost = i * b;
    if (n - i * a > 0) cost += (((n - i * a - 1) / c) + 1) * d;
    ans = min(ans, cost);
  }

  cout << ans;
}