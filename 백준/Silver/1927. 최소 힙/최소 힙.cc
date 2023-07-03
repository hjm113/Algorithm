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
int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
int n;
void push(int x){
  sz++;
  heap[sz] = x;
  int pos = sz;
  while(pos > 1) {
    if(heap[pos] >= heap[pos/2]) {
      break;
    }
    int tmp = heap[pos/2];
    heap[pos/2] = heap[pos];
    heap[pos] = tmp;
    pos /= 2;
  }
}
int top(){
  return heap[1];
}
void pop(){
  int st = 1;
  heap[st] = heap[sz];
  sz--;
  while(st*2 <= sz) {
    int left = st*2;
    int right = st*2+1;
    int min = left;
    if(heap[right] < heap[min] && right <= sz) {
      min = right;
    }
    if(heap[min] >= heap[st]) {
      break;
    }
    int tmp = heap[st];
    heap[st] = heap[min];
    heap[min] = tmp;
    st = min;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if(num == 0) {
      if(sz == 0) {
        cout << 0 << "\n";
      }
      else {
        cout << top() << "\n";
        pop();
      }
    }
    else {
      push(num);
    }
    /*
    cout << "\n";
    for(int i = 1; i <= sz; i++) {
      cout << heap[i] << " ";
    }
    cout << "\n";
    */
  }
}