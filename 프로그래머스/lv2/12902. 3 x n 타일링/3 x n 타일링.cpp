#include <string>
#include <vector>

using namespace std;
long long dp[5005];
long long mod = 1000000007;
int solution(int n) {
    int answer = 0;
    if(n % 2 == 1) {
        return 0;
    }
    dp[2] = 3;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i-2] * 3 + 2;
        for(int j = 2; j < i-2; j+=2) {
            dp[i] += dp[j]*2;
        }
        dp[i] %= mod;
    }
    answer = dp[n];
    return answer;
}