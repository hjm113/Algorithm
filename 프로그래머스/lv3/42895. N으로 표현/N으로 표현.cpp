#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set<int> dp[10];
int solution(int N, int number) {
    int answer = -1;
    int num = N;
    int di = 10;
    for(int i = 1; i <= 8; i++) {
        dp[i].insert(num);
        num += (N*di);
        di *= 10;
    }
    for(int i = 2; i <= 8; i++) {
        for(int  j = 1; j < i; j++) {
            for(auto a : dp[j]) {
                for(auto b : dp[i-j]) {
                    dp[i].insert(a*b);
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    if(b != 0) {
                        dp[i].insert(a/b);
                    }
                }
            }
        }
    }
    for(int i = 1; i <= 8; i++) {
        if(dp[i].find(number) != dp[i].end()) {
            answer = i;
            break;
        }
    }
    return answer;
}