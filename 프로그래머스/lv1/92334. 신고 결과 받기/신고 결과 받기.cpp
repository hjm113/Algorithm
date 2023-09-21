#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> mp;
int chk[1005][1005];
int re[1005];
vector<int> ans[1005];
int ary[1005];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(int i = 0; i < id_list.size(); i++) {
        mp[id_list[i]] = i;
    }
    for(int i = 0; i < report.size(); i++) {
        string tmp = "";
        string p1 = "";
        string p2 = "";
        for(int j = 0; j < report[i].length(); j++) {
            if(report[i][j] == ' ') {
                p1 = tmp;
                tmp = "";
                continue;
            }
            tmp += report[i][j];
        }
        p2 = tmp;
        if(chk[mp[p1]][mp[p2]] == 1) {
            continue;
        }
        ans[mp[p2]].push_back(mp[p1]);
        chk[mp[p1]][mp[p2]] = 1;
        re[mp[p2]]++;
    }
    for(int i = 0; i < id_list.size(); i++) {
        if(re[i] >= k) {
            for(int j = 0; j < ans[i].size(); j++) {
                ary[ans[i][j]]++;
            }
        }
    }
    for(int i = 0; i < id_list.size(); i++) {
        answer.push_back(ary[i]);
    }
    return answer;
}