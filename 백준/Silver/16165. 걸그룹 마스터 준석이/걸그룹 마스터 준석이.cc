#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;
#define X first
#define Y second
int t, k;
unordered_map<string, string> m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> k;
  while(t--) {
    string gname;
    int n;
    cin >> gname;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string name;
      cin >> name;
      m[name] = gname;
    }
  }
  for(int i = 0; i < k; i++) {
    string fname;
    int quiz;
    cin >> fname;
    cin >> quiz;
    if(quiz == 1) {
      cout << m[fname] << "\n";;
    }
    else {
      vector<string> group;
      for(auto ele : m) {
        if(ele.Y == fname) {
          group.push_back(ele.X);
        }
      }
      sort(group.begin(),group.end());
      for(auto ele : group) {
        cout << ele << "\n";
      }
    }
  }
}
