#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <deque>
#define X first
#define Y second
using namespace std;
deque<tuple<int,int,string>> pla;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int n = plans.size();
    for(int i = 0; i < n; i++) {
        string a = plans[i][0];
        string b = plans[i][1];
        string c = plans[i][2];
        string tmp = "";
        int num = 0;
        for(int j = 0; j < b.length(); j++) {
            if(b[j] == ':') {
                num += stoi(tmp)*60;
                tmp = "";
                continue;
            }
            tmp += b[j];
            if(j == b.length()-1) {
                num += stoi(tmp);
            }
        }
        int ptime = stoi(c);
        pla.push_back({num,ptime,a});
    }
    sort(pla.begin(),pla.end());
    int t = 0;
    deque<pair<string,int>> wait;
    while(!pla.empty()) {
        int st,pl;
        string sub;
        tie(st,pl,sub) = pla.front();
        if(!wait.empty() && wait.front().Y == 0) {
            answer.push_back(wait.front().X);
            if(answer.size() == n) {
                break;
            }
            wait.pop_front();
        }
        if(t == st) {
            wait.push_front({sub,pl});
            pla.pop_front();
        }
        if(!wait.empty()) {
            wait[0].Y--;
        }
        t++;
    }
    while(!wait.empty()) {
        answer.push_back(wait.front().X);
        wait.pop_front();
    }
    return answer;
}