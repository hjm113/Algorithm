#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[510][510];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[1][1] = triangle[0][0];
    int n = triangle.size();
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max({dp[i][j],dp[i-1][j-1]+triangle[i-1][j-1],dp[i-1][j]+triangle[i-1][j-1]});
        }
    }
    for(int i = 1; i <= n; i++) {
        answer = max(answer,dp[n][i]);
    }
    return answer;
}