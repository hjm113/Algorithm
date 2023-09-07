#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005][55];
int mx = 2000000000;
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    temperature += 10;
    t1 += 10;
    t2 += 10;
    for(int i = 0; i < 1005; i++) {
        for(int j = 0; j < 55; j++) {
            dp[i][j] = mx;
        }
    }
    int chk = 0;
    for(int i = 1; i < onboard.size(); i++) {
        if(onboard[i] == 1) {
            chk = i;
        }
    }
    dp[0][temperature] = 0;
    for(int i = 1; i < onboard.size(); i++) {
        for(int j = 0; j <= 50; j++) {
            if(onboard[i] == 1) {
                if(j < t1) {
                    continue;
                }
                if(j > t2) {
                    continue;
                }
            }
            if(j < temperature) {
                if(j == 0) {
                    dp[i][j] = min(dp[i-1][j]+b,dp[i-1][j+1]+a);
                    continue;
                }
                dp[i][j] = min({dp[i-1][j]+b,dp[i-1][j+1]+a,dp[i-1][j-1]});
            }
            else if(j > temperature){
                if(j == 0) {
                    dp[i][j] = min(dp[i-1][j]+b,dp[i-1][j+1]);
                    continue;
                }
                dp[i][j] = min({dp[i-1][j]+b,dp[i-1][j+1],dp[i-1][j-1]+a});
            }
            else {
                if(j == 0) {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]);
                    continue;
                }
                dp[i][j] = min({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
            }
        }
    }
    //cout << t1 << " " << t2 << "\n";
    for(int i = t1; i <= t2; i++) {
        if(mx > dp[chk][i]) {
            mx = dp[chk][i];
        }
        //cout << i << " "<< dp[chk][i] << "\n";
    }
    int answer = 0;
    answer = mx;
    return answer;
}