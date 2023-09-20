#include <iostream>
#include <vector>
using namespace std;
int dp[100005][5];
int mx = 0;
int solution(vector<vector<int> > land) {
    int answer = 0;
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    for(int i = 1; i < land.size(); i++) {
        for(int j = 0; j < 4; j++) { 
            for(int k = 0; k < 4; k++) {
                if(j == k) {
                    continue;
                }
                dp[i][j] = max(dp[i][j],dp[i-1][k]+land[i][j]);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        if(mx < dp[land.size()-1][i]) {
            mx = dp[land.size()-1][i];
        }
    }
    answer = mx;
    return answer;
}