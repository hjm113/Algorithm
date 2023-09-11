#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> ans;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    int val = -1;
    int cnt = 0;
    int chk = 0;
    for(int i = 0; i < tangerine.size(); i++) {
        if(chk == 0) {
            val = tangerine[i];
            chk++;
        }
        if(val != tangerine[i]) {
            ans.push_back(cnt);
            cnt = 0;
            val = tangerine[i];
        }
        cnt++;
        if(i == tangerine.size()-1) {
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(),ans.end(),greater());
    int sum = 0;
    /*
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    */
    for(int i = 0; i < ans.size(); i++) {
        sum += ans[i];
        if(sum >= k) {
            answer = i+1;
            break;
        }
    }
    return answer;
}