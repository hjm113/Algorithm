#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> dq;
int ans = 0;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int st = 9 * 60;
    int en = st + (n-1)*t;
    for(int i = 0; i < timetable.size(); i++) {
        int a = stoi(timetable[i].substr(0,2))*60;
        int b = stoi(timetable[i].substr(3,2));
        dq.push_back(a+b);
    }
    sort(dq.begin(),dq.end());
    for(int i = st; i <= en; i+=t) {
        vector<int> wait;
        int chk = 0;
        while(!dq.empty()) {
            if(dq.front() <= i) {
                if(wait.size() == m-1) {
                    chk = 1;
                    ans = dq.front()-1;
                    dq.pop_front();
                    break;
                }
                wait.push_back(dq.front());
                dq.pop_front();
            }
            else {
                ans = i;
                break;
            }
        }
        if(chk == 0 && dq.empty()) {
            ans = i;
        }
        //cout << ans << "\n";
    }
    if(to_string(ans/60).length() == 1) {
        answer += '0' + to_string(ans/60) +':';
    }
    else {
        answer += to_string(ans/60) + ':';
    }
    if(to_string(ans%60).length() == 1) {
        answer += '0' + to_string(ans%60);
    }
    else {
        answer += to_string(ans%60);
    }
    return answer;
}