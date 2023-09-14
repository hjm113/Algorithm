#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[555][555];
int mx = 2000000000;
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for(int i = 0; i <= 500; i++) {
        for(int j = 0; j <= 500; j++) {
            dp[i][j] = mx;
        }
    }
    problems.push_back({0,0,0,1,1});
    problems.push_back({0,0,1,0,1});
    int mxi = 0;
    int mxj = 0;
    for(int i = 0; i < problems.size(); i++) {
        int a = problems[i][0];
        int b = problems[i][1];
        if(a > mxi) {
            mxi = a;
        }
        if(b > mxj) {
            mxj = b;
        }
    }
    if(alp >= mxi && cop >= mxj) {
        return 0;
    }
    alp = min(alp,mxi);
    cop = min(cop,mxj);
    dp[alp][cop] = 0;
    for(int i = alp; i <= mxi; i++) {
        for(int j = cop; j <= mxj; j++) {
            for(int k = 0; k < problems.size(); k++) {
                int a = problems[k][0];
                int b = problems[k][1];
                int c = problems[k][2];
                int d = problems[k][3];
                int e = problems[k][4];
                if(i >= a && j >= b) {
                    dp[min(i+c,mxi)][min(j+d,mxj)] = min(dp[min(i+c,mxi)][min(j+d,mxj)],dp[i][j]+e);
                    //cout << dp[i+c][j+d] << " " << i+c << " " << j+d << " \n";
                }
            }
        }
    }
    answer = dp[mxi][mxj];
    return answer;
}