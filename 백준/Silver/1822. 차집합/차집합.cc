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
int arya[500005];
int aryb[500005];
vector<int> ans;
int na, nb;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> na >> nb;
  for(int i = 0; i < na; i++) {
    cin >> arya[i];
  }
  for(int i = 0; i < nb; i++) {
    cin >> aryb[i];
  }
  sort(arya,arya+na);
  sort(aryb,aryb+nb);
  for(int i = 0; i < na; i++) {
    if(!binary_search(aryb,aryb+nb,arya[i])) {
      ans.push_back(arya[i]);
    }
  }
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}