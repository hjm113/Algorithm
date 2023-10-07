#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mx = 0;
string solution(string m, vector<string> infos) {
    string answer = "(None)";
    for(int i = 0; i < infos.size(); i++) {
        int st = 60 * stoi(infos[i].substr(0,2)) + stoi(infos[i].substr(3,2));
        int en = 60 * stoi(infos[i].substr(6,2)) + stoi(infos[i].substr(9,2));
        int ptime = en-st;
        string name = "";
        int fst = 0;
        for(int j = 12; j < infos[i].length(); j++) {
            if(infos[i][j] == ',') {
                fst = j+1;
                break;
            }
            name += infos[i][j];
        }
        string mus = infos[i].substr(fst);
        int count = 0;
        for(int j = 0; j < mus.length(); j++) {
            if(mus[j] == '#') {
                count++;
            }
        }
        int len = mus.length()-count;
        int cnt = ptime/len;
        int rem = ptime%len;
        string tmp = "";
        for(int j = 0; j < cnt; j++) {
            tmp += mus;
        }
        int sta = 0;
        while(1) {
            if(sta == rem) {
                break;
            }
            tmp += mus[sta];
            if(mus[sta] == '#') {
                rem++;
            }
            sta++;
        }
        int chk = 0;
        //cout << tmp << "\n";
        for(int j = 0; j < tmp.length(); j++) {
            if(m == tmp.substr(j,m.length())) {
                if(tmp.length() > j+m.length() && tmp[j+m.length()] == '#') {
                    continue;
                }
                //cout << j << "\n";
                chk = 1;
            }
        }
        if(chk == 1) {
            if(mx < ptime) {
                mx = ptime;
                answer = name;
            }
        }
    }
    return answer;
}