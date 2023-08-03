#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> mp;
int used[10005][10005];
string ary[10005];
deque<string> des[10005]; 
vector<string> answer;
int cnt = 0;
void dfs(int k, string ap, int n) {
    if(k == n && cnt == 0) {
        cnt++;
        answer.push_back("ICN");
        for(int i = 0; i < n; i++) {
            answer.push_back(ary[i]);
        }
        return;
    }
    for(int i = 0; i < des[mp[ap]].size(); i++) {
        if(used[mp[ap]][i] == 0) {
            used[mp[ap]][i] = 1;
            ary[k] = des[mp[ap]][i];
            dfs(k+1,des[mp[ap]][i],n);
            used[mp[ap]][i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int cnt = 1;
    for(int i = 0; i < tickets.size(); i++) {
        if(mp.find(tickets[i][0]) == mp.end()) {
            mp[tickets[i][0]] = cnt;
            cnt++;
        }
        des[mp[tickets[i][0]]].push_back(tickets[i][1]);
    }
    for(int i = 0; i < 10001; i++) {
        sort(des[i].begin(),des[i].end());
    }
    dfs(0,"ICN",tickets.size());
    return answer;
}