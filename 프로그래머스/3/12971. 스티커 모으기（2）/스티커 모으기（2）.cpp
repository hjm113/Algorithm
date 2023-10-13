#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp1[100005][2];
int dp2[100005][2];
int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    if(n == 1) {
        answer = sticker[0];
        return answer;
    }
    dp1[0][0] = 0;
    dp1[0][1] = sticker[0];
    for(int i = 1; i < n-1; i++) {
        dp1[i][1] = dp1[i-1][0] + sticker[i];
        dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1]);
    }
    dp2[1][0] = 0;
    dp2[1][1] = sticker[1];
    for(int i = 2; i < n; i++) {
        dp2[i][1] = dp2[i-1][0] + sticker[i];
        dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]);
    }
    //cout << dp1[n-2][0] << " " << dp1[n-2][1] << "\n";
    //cout << dp2[n-1][0] << " " << dp2[n-1][1] << "\n";
    answer = max({dp1[n-2][0],dp1[n-2][1],dp2[n-1][0],dp2[n-1][1]});
    return answer;
}