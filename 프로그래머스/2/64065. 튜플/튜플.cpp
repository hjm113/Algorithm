#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> res;
vector<int> fin[505];
int chk[100005];
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> ans;
    string tmp;
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == '}') {
            ans.push_back(stoi(tmp));
            tmp = "";
            i += 2;
            res.push_back(ans);
            ans.clear();
            continue;
        }
        if(s[i] == ',') {
            ans.push_back(stoi(tmp));
            tmp = "";
        }
        if(s[i] >= '0' && s[i] <= '9') {
            tmp += s[i];
        }
    }
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            fin[res[i].size()].push_back(res[i][j]);
        }
    }
    for(int i = 1; i < res.size()+1; i++) {
        for(int j = 0; j < fin[i].size(); j++) {
            if(chk[fin[i][j]] == 0) {
                answer.push_back(fin[i][j]);
                chk[fin[i][j]] = 1;
            }
        }
    }
    return answer;
}