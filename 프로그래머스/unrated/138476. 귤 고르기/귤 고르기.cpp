#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> ans;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    int val = tangerine[0];
    int cnt = 1;
    for(int i = 1; i < tangerine.size(); i++) {
        if(val != tangerine[i]) {
            ans.push_back(cnt);
            cnt = 0;
            val = tangerine[i];
        }
        if(i == tangerine.size()-1) {
            cnt++;
            ans.push_back(cnt);
        }
        cnt++;
    }
    sort(ans.begin(),ans.end(),greater());
    int sum = 0;
    for(int i = 0; i < ans.size(); i++) {
        sum += ans[i];
        //cout << ans[i] << "\n";
        if(sum >= k) {
            answer = i+1;
            break;
        }
    }
    return answer;
}