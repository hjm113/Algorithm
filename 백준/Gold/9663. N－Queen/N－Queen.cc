#include <iostream>
#include <queue>
using namespace std;
int vis[100005];
int n;
int cnt = 0;
int used1[20];
int used2[50];
int used3[50];
void dfs(int k) {
  if(n == k) {
    cnt++;
    return;
  }
  for(int i = 0; i < n; i++) {
    if(used1[i] == 1 || used2[i+k] == 1 || used3[n+k-i] == 1) {
      continue;
    }
    used1[i] = 1;
    used2[k+i] = 1;
    used3[n+k-i] = 1;
    dfs(k+1);
    used1[i] = 0;
    used2[k+i] = 0;
    used3[n+k-i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dfs(0);
  cout << cnt;
}