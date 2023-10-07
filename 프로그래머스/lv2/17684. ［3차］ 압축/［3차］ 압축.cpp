#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string,int> mp;
vector<int> solution(string msg) {
    vector<int> answer;
    int cnt = 1;
    for(char c = 'A'; c <= 'Z'; c++) {
        string tmp = "";
        tmp += c;
        mp[tmp] = cnt;
        cnt++;
    }
    int pr = 0;
    for(int i = 0; i < msg.length(); i++) {
        string tmp = "";
        tmp += msg[i];
        int idx = i;
        while(idx < msg.length()) {
            pr = mp[tmp];
            idx++;
            tmp += msg[idx];
            if(mp[tmp] == 0) {
                mp[tmp] = cnt;
                cnt++;
                i = idx-1;
                break;
            }
        }
        answer.push_back(pr);
    }
    return answer;
}