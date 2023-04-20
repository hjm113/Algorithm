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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n;
ll mx = INT_MIN;
vector<tuple<char,char,char>> tmp;
int fin = 0;
int ary[25];
void cal(vector<char> ch, vector<int> order) {
  int count = 0;
  int sum = 0;
  for(int i = 0; i < ch.size(); i++) {
    if(ch[i] == 'a' && i == 0) {
      sum += order[count];
      i+=3;
      count++;
    }
    else if(ch[i] == 'a') {
      if(ch[i-1] == '*') {
        sum *= order[count];
      }
      else if(ch[i-1] == '+') {
        sum += order[count];
      }
      else if(ch[i-1] == '-') {
        sum -= order[count];
      }
      count++;
      i+=3;
    }
    else if(i % 2 == 0 && i == 0) {
      int num = ch[i] - '0';
      sum += num;
    }
    else if(i % 2 == 0 && ch[i-1] == '*') {
      int num = ch[i] - '0';
      sum *= num;
    }
    else if(i % 2 == 0 && ch[i-1] == '-') {
      int num = ch[i] - '0';
      sum -= num;
    }
    else if(i % 2 == 0 && ch[i-1] == '+') {
      int num = ch[i] - '0';
      sum += num;
    }
  }
  if(sum > mx) {
    mx = sum;
  }
}

void func(int k, vector<char> board) {
  if(k == fin) {
    vector<int> num;
    for(int i = 0; i < k; i++) {
      
      if(ary[i] == 1) {
        char x, s, y;
        tie(x,s,y) = tmp[i];
        int num1 = x - '0';
        int num2 = y - '0';
        int numf = 0;
        if(s == '+') {
          numf = num1 + num2;
        }
        else if(s == '*') {
          numf = num1 * num2;
        }
        else if(s == '-') {
          numf = num1 - num2;
        }
        num.push_back(numf);
        board[i*2] = 'a';
        board[i*2+1] = 'a';
        board[i*2+2] = 'a';
      }
    }
    /*
    for(int i = 0; i < n; i++) {
      cout << board[i];
    }
    cout << "\n";
    */
    cal(board,num);
    return;
  }
  for(int i = 0; i <= 1; i++) {
    if(ary[k-1] == 1 && i == 1) {
      return;
    }
    else {
      ary[k] = i;
      func(k+1,board);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<char> board;
  cin >> n;
  fin = n / 2;
  for(int i = 0; i < n; i++) {
    char s;
    cin >> s;
    board.push_back(s);
  }
  int cnt = 0;
  int i = 0;
  while(i < n-2) {
    tmp.push_back(make_tuple(board[i],board[i+1],board[i+2]));
    i+=2;
  }
  func(0,board);
  cout << mx;
}
