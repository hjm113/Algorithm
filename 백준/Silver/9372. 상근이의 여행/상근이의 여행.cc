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
vector<pair<int,int>> adj[305];
int check[305];
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int ans = 0;
int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
    }
    cout << n -1 << "\n";
  }
}