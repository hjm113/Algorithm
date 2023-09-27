#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;
vector<pair<string, int>> ans;
map<string,string> mp;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i = 0; i < record.size(); i++) {
        istringstream iss(record[i]);
        string order, id, name;
        iss >> order >> id >> name;
        //cout << name << "\n";
        if(order == "Enter") {
            ans.push_back({id,0});
            mp[id] = name;
        }
        else if(order == "Leave") {
            ans.push_back({id,1});
        }
        else {
            mp[id] = name;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].Y == 0) {
            answer.push_back(mp[ans[i].X]+"님이 들어왔습니다.");
        }
        else {
            answer.push_back(mp[ans[i].X]+"님이 나갔습니다.");
        }
    }
    return answer;
}