#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int ary[5][100005];
long long solution(vector<int> weights) {
    long long answer = 0;
    int n = weights.size();
    sort(weights.begin(),weights.end());
    for(int i = 2; i <= 4; i++) {
        for(int j = 0; j < weights.size(); j++) {
            ary[i][j] = weights[j]*i;
        }
    }
    for(int i = 0; i < n-1; i++) {
        int a = upper_bound(ary[2]+i+1,ary[2]+n,ary[2][i]) - lower_bound(ary[2]+i+1,ary[2]+n,ary[2][i]);
        answer += a;
    }
    for(int j = 2; j < 4; j++) {
        for(int k = j+1; k < 5; k++) {
            for(int i = 0; i < n; i++) {
                int a = upper_bound(ary[k],ary[k]+n,ary[j][i]) - lower_bound(ary[k],ary[k]+n,ary[j][i]); 
                answer += a;
                //cout << ary[j][i] << " " << a <<"\n";
            }
        }
    }
    return answer;
}