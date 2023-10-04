#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#define X first
#define Y second
using namespace std;
deque<pair<int,int>> dq;
int chk[200005];
int solution(vector<int> food_times, long long k) {
    int answer = -1;
    for(int i = 0; i < food_times.size(); i++) {
        dq.push_back({food_times[i],i});
    }
    sort(dq.begin(),dq.end());
    long long left = 0;
    long long time = 0;
    long long idx = 0;
    int out = 0;
    while(!dq.empty()) {
        /*
        for(int i = 0 ; i < dq.size(); i++) {
            cout << dq[i].X << " ";
        }
        cout << "\n";
        */
        long long lst = (dq.front().X-left)*dq.size();
        time += lst;
        left = dq.front().X;
        //cout << time << "\n";
        if(time > k) {
            //cout << idx << "asdf\n";
            idx = k-(time-lst);
            idx %= dq.size();
            break;
        }
        while(left == dq.front().X) {
            chk[dq.front().Y] = 1;
            dq.pop_front();
            if(dq.empty()) {
                out = 1;
                break;
            }
        }
        if(out == 1) {
            answer = -1;
            return answer;
        }
    }
    long long cnt = 0;
    for(int i = 0; i < food_times.size(); i++) {
        if(chk[i] == 0) {
            cnt++;
        }
        if(cnt == idx+1) {
            answer = i+1;
            break;
        }
    }
    return answer;
}