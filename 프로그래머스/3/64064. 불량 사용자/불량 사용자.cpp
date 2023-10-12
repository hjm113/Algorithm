#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
for(int j = 0; j < m; j++) {
    if(used[j] == 1) {
        continue;
    } 
    
}
*/
int num[10];
int ary[10];
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int n = user_id.size();
    int m = banned_id.size();
    for(int i = n-m; i < n; i++) {
        num[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        ary[i] = i;
    }
    do{
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            if(num[i] == 1) {
                ans.push_back(user_id[i]);
            }
        }
        sort(ans.begin(),ans.end());
        do{
            int chk = 0;
            for(int i = 0; i < m; i++) {
                if(banned_id[i].length() != ans[i].length()) {
                    chk = 1;
                    break;
                }
                int len = banned_id[i].length();
                int out = 0;
                for(int k = 0; k < len; k++) {
                    if(banned_id[i][k] == '*') {
                        continue;
                    }
                    if(banned_id[i][k] != ans[i][k]) {
                        chk = 1;
                        break;
                    }
                }
            }
            if(chk == 0) {
                answer++;
                break;
            }
        }while(next_permutation(ans.begin(),ans.end()));
    }while(next_permutation(num,num+n));
    return answer;
}