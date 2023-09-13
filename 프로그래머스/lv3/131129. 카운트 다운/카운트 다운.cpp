#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
pair<int,int> dp[100005];
int mx = 2000000000;
vector<int> ans1;
vector<int> ans2;
vector<int> solution(int target) {
    vector<int> answer;
    for(int i = 1; i <= 20; i++) {
        ans1.push_back(i);
        ans2.push_back(i*2);
        ans2.push_back(i*3);
    }
    ans1.push_back(50);
    for(int i = 0; i < 100004; i++) {
        dp[i] = {mx,0};
    }
    for(int i = 0; i < ans2.size(); i++) {
        dp[ans2[i]] = {1,0};
    }
    for(int i = 0; i < ans1.size(); i++) {
        dp[ans1[i]] = {1,1};
    }
    for(int i = 0; i <= 100000; i++) {
        for(int j = 0; j < ans1.size(); j++) {
            if(i-ans1[j] >= 0) {
                if(dp[i].X >= dp[i-ans1[j]].X+1) {
                    dp[i] = {dp[i-ans1[j]].X+1,dp[i-ans1[j]].Y+1};
                }
            }
        }
        for(int j = 0; j < ans2.size(); j++) {
            if(i-ans2[j] >= 0) {
                if(dp[i].X > dp[i-ans2[j]].X+1) {
                    dp[i] = {dp[i-ans2[j]].X+1,dp[i-ans2[j]].Y};
                }
            }
        }
    }
    answer.push_back(dp[target].X);
    answer.push_back(dp[target].Y);
    return answer;
}