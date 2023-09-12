#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mx = 0;
int ary[5000005];
int ans[5000005];
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    for(int i = 1; i <= e; i++) {
        for(int j = 1; j <= e; j++) {
            if(i*j > e) {
                break;
            }
            ary[i*j]++;
        }
    }
    mx = ary[e];
    ans[e] = e;
    int idx = e;
    for(int i = e-1; i >= 1; i--) {
        if(ary[i] >= mx) {
            idx = i;
            mx = ary[i];
        }
        ans[i] = idx;
    }
    for(int i = 0; i < starts.size(); i++) {
        answer.push_back(ans[starts[i]]);
    }
    return answer;
}