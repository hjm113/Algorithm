#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int dp[1005][1005];
int mx = 0;
int solution(vector<vector<int>> board) {
    int answer = 1234;
    int n = board.size();
    int m = board[0].size();
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(board[i][j] == 0) {
                continue;
            }
            board[i][j] = min({board[i][j-1]+1,board[i-1][j-1]+1,board[i-1][j]+1});
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mx = max(board[i][j],mx);
        }
    }
    answer = mx*mx;
    return answer;
}