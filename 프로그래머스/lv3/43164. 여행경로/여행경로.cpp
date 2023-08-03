#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> mp;
deque<string> des[10005]; 
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int cnt = 0;
    for(int i = 0; i < tickets.size(); i++) {
        if(mp.find(tickets[i][0]) == mp.end()) {
            mp[tickets[i][0]] = cnt;
            cnt++;
        }
        des[mp[tickets[i][0]]].push_back(tickets[i][1]);
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < des[i].size(); j++) {
            cout << des[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < 10001; i++) {
        sort(des[i].begin(),des[i].end());
    }
    string st = "ICN";
    answer.push_back(st);
    while(!des[mp[st]].empty()) {
        answer.push_back(des[mp[st]].front());
        string tmp = des[mp[st]].front();
        des[mp[st]].pop_front();
        st = tmp;
    }
    return answer;
}