#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int num[10];
int n = 0;
int m = 0;
int answer = 0;
vector<string> chk;
/*
void dfs(int k) {
    if(k == m+1) {
        return;
    }
    if(k > 0) {
        for(int j = 0; j < n; j++) {
            tmp[j] += relation[j][ary[k-1]];
        }
        int chk = 0;
        for(int j = 0; j < n; j++) {
            if(mp[tmp[j]] == 1) {
                chk = 1;
            }
            mp[tmp[j]] = 1;
        }
        if(chk == 0) {
            string ans = "";
            vector<int> gt;
            for(int i = 0; i < k; i++) {
                gt.push_back(ary[i]);
            }
            sort(gt.begin(),gt.end());
            for(int i = 0; i < k; i++) {
                ans += to_string(gt[i]);
                if(real[ans] == 1) {
                    return;
                }
            }
            for(int i = 0; i < k; i++) {
                cout << ary[i] << " ";
            }
            cout << "\n";
            real[ans] = 1;
            answer++;
            return;
        }
    }
    for(int i = 0; i < m; i++) {
        if(used[i] == 1) {
            continue;
        }
        string ori[25] = {};
        for(int j = 0; j < n; j++) {
            ori[j] = tmp[j];
        }
        used[i] = 1;
        ary[k] = i;
        dfs(k+1);
        for(int j = 0; j < n; j++) {
            tmp[j] = ori[j];
        }
        used[i] = 0;
    }
}
*/
int solution(vector<vector<string>> relation) {
    n = relation.size();
    m = relation[0].size();
    for(int i = 0; i < m; i++) {
        num[m-i-1] = 1;
        do {
            string tmp[25] = {};
            vector<int> ans;
            map<string, int> mp;
            for(int j = 0; j < m; j++) {
                if(num[j] == 1) {
                    ans.push_back(j);
                    for(int k = 0; k < n; k++) {
                        tmp[k] += relation[k][j];
                    }
                }
            }
            sort(ans.begin(),ans.end());
            string now = "";
            for(int j = 0; j < ans.size(); j++) {
                now += to_string(ans[j]);
            }
            int out = 0;
            for(int j = 0; j < chk.size(); j++) {
                int cnt = 0;
                for(int k = 0; k < chk[j].length(); k++) {
                    if(binary_search(now.begin(),now.end(),chk[j][k])) {
                        cnt++;
                    }
                }
                if(cnt == chk[j].length()) {
                    out = 1;
                }
            }
            if(out == 1) {
                continue;
            }
            int find = 0;
            for(int j = 0; j < n; j++) {
                if(mp[tmp[j]] == 1) {
                    find = 1;
                }
                mp[tmp[j]] = 1;
            }
            if(find == 0) {
                chk.push_back(now);
                //cout << now << "\n";
                answer++;
            }
        }while(next_permutation(num,num+m));
    }
    //dfs(0);
    return answer;
}