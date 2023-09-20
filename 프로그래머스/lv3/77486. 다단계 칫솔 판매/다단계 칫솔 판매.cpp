#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string,string> mp;
map<string, int> mon;
map<string, int> dfaul;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i = 0; i < enroll.size(); i++) {
        if(referral[i] == "-") {
            mp[enroll[i]] = "center";
        }
        else {
            mp[enroll[i]] = referral[i];
        }
    }
    for(int i = 0; i < seller.size(); i++) {
        string st = seller[i];
        int fst = amount[i]*100;
        mon[st] += (fst-fst/10);
        while(1) {
            if(fst/10 == 0) {
                break;
            }
            st = mp[st];
            int make = fst/10;
            if(st == "center") {
                mon[st] += make;
                break;
            }
            else {
                mon[st] += (make - make/10);
            }
            fst = make;
        }
    }
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(mon[enroll[i]]);
    }
    return answer;
}