#include <bits/stdc++.h>
using namespace std;

int compare(const void* a, const void* b) {
  int num1 = *(int*)a;
  int num2 = *(int*)b;
  if(num1 < num2) {
    return -1;
  }
  else if(num1 > num2) {
    return 1;
  }
  else {
    return 0;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sum = 0;
  int min = 200;
  int count = 0;
  for(int i = 0; i < 7; i++) {
    int num;
    cin >> num;
    if(num % 2 == 1) {
      count++;
      sum = sum + num;
      if(min > num) {
        min = num;
      }
    }
  }
  if(count == 0) {
    cout << -1;
  }
  else {
    cout << sum << "\n";
    cout << min;
  }
  
}