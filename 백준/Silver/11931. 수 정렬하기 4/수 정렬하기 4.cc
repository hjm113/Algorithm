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

int n;
int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수


void merge(int st, int en) {
  int mid = (st+en)/2;
  int as = st;
  int bs = mid;
  for(int i = st; i < en; i++) {
    if(as == mid) {
      tmp[i] = arr[bs];
      bs++;
    }
    else if(bs == en) {
      tmp[i] = arr[as];
      as++;
    }
    else if(arr[as] >= arr[bs]) {
      tmp[i] = arr[as];
      as++;
    }
    else {
      tmp[i] = arr[bs];
      bs++;
    }
  }
  for(int i = st; i < en; i++) {
    arr[i] = tmp[i];
  }
}
// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(en-st <= 1) {
    return;
  }
  int mid = (st+en)/2;
  merge_sort(st,mid);
  merge_sort(mid,en);
  merge(st,en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  merge_sort(0, n);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << "\n";
  }
}