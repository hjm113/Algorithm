#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
#define X first
#define Y second

bool cmp1(const string& a, const string& b) {
  if(a.length() < b.length()) {
    return true;
  }
  else if(a.length() > b.length()) {
    return false;
  }
  else if(a.length() == b.length()) {
    int suma = 0;
    int sumb = 0;
    for(int i = 0; i < a.length(); i++) {
      if(a[i] >= '0' && a[i] <= '9') {
        int num = a[i] - '0';
        suma += num;
      }
    }
    for(int i = 0; i < b.length(); i++) {
      if(b[i] >= '0' && b[i] <= '9') {
        int num = b[i] - '0';
        sumb += num;
      }
    }
    if(suma < sumb) {
      return true;
    }
    else if(suma > sumb) {
      return false;
    }
    else if(suma == sumb) {
      return a < b;
    }
  }
}

int n;
string str[55];
int main(void){
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    str[i] = s;
  }
  sort(str, str+n, cmp1);
  for(int i = 0; i < n; i++) {
    cout << str[i] << "\n";
  }
}