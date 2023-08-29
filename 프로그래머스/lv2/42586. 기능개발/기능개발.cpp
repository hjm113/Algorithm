#include <string>
#include <vector>
#include <deque>
#include <iostream>
#define X first
#define Y second
using namespace std;
int day = 0;
deque<pair<int,int>> dq;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0; i < progresses.size(); i++) {
        dq.push_back({progresses[i],i});
    }
    while(!dq.empty()) {
        int cnt = 0;
        while(1) {
            auto cur = dq.front();
            if(cur.X >= 100) {
                dq.pop_front();
                cnt++;
            }
            else {
                break;
            }
        }
        if(cnt > 0) {
            answer.push_back(cnt);
        }
        for(int i = 0; i < dq.size(); i++) {
            auto ele = dq[i];
            dq[i] = {ele.X+speeds[ele.Y],ele.Y};
        }
    }
    return answer;
}