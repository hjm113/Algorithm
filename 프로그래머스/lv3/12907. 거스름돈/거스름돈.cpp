#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100005];
int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;
    sort(money.begin(),money.end());
    for(int i = 0; i < money.size(); i++) {
        for(int j = 0; j <= n; j++) {
            if(j+money[i] > 100000) {
                continue;
            }
            dp[j+money[i]] += dp[j];
        }
    }
    answer = dp[n];
    return answer;
}