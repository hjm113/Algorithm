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
int n, c;
long long order[1005];
long long ary[1005];
long long ori[1005];
int cnt[1005];
int main(void){
  ios::sync_with_stdio(0);
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> order[i];
    ary[i] = order[i];
  }
  sort(ary, ary+n);
  int check = 0;
  int count = -1;
  for(int i = 0; i < n; i++) {
    if(check != ary[i]) {
      check = ary[i];
      count++;
      ori[count] = ary[i];
      cnt[count]++;
    }
    else {
      cnt[count]++;
    }
  }
  int ans = 0;
  while(1) {
    int mx = 0;
    int idx = 0;
    for(int i = 0; i <= count; i++) {
      if(mx < cnt[i]) {
        mx = cnt[i];
        idx = i;
      }
      else if(mx == cnt[i]) {
        //cout << "check";
        int fst = 0;
        int snd = 0;
        for(int j = 0; j < n; j++) {
          if(order[j] == ori[i]) {
            fst = j;
            break;
          }
        }
        for(int j = 0; j < n; j++) {
          if(order[j] == ori[idx]) {
            snd = j;
            break;
          }
        }
        //cout << fst << "fst" << "\n";
        //cout << snd << "snd" << "\n";
        if(fst < snd) {
          idx = i;
        }
      }
    }
    ans += mx;
    cnt[idx] = -1;
    for(int i = 0; i < mx; i++) {
      cout << ori[idx] << " ";
    }
    if(ans == n) {
      break;
    }
  }
  
}