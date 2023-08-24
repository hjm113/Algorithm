#include <string>
#include <vector>
#include <iostream>;
using namespace std;
int dp[105][105];
int check[105][105];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    for(int i = 0 ; i < puddles.size(); i++) {
        check[puddles[i][1]][puddles[i][0]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(check[i][j] == 1) {
                continue;
            }
            dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
            dp[i][j] %= 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}