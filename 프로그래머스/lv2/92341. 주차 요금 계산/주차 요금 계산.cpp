#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
using namespace std;
map<string, int> mp;
map<string, int> total;
set<string> s;
vector<string> ans;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i = 0; i < records.size(); i++) {
        int t = stoi(records[i].substr(0,2))*60 + stoi(records[i].substr(3,2));
        string num = records[i].substr(6,4);
        s.insert(num);
        string k = records[i].substr(11);
        //cout << t << " " << num << " " << k << "\n";
        if(k == "IN") {
            mp[num] = t;
        }
        if(k == "OUT") {
            int stay = t - mp[num];
            total[num] += stay;
            mp[num] = -1;
        }
    }
    int last = (23*60)+59;
    for(auto nxt : s) {
        if(mp[nxt] == -1) {
            continue;
        }
        int stay = last - mp[nxt];
        total[nxt] += stay;
    }
    for(auto nxt : s) {
        int cost = total[nxt];
        if(cost-fees[0] > 0) {
            int re = cost-fees[0];
            double co2 = ceil((double)re/fees[2]);
            answer.push_back(fees[1] + co2*fees[3]);
        }
        else {
            answer.push_back(fees[1]);
        }
    }
    return answer;
}