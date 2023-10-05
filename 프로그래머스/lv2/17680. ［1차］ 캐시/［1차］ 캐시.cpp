#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
deque<string> dq;
int solution(int n, vector<string> cities) {
    int answer = 0;
    for(int i = 0; i < cities.size(); i++) {
        for(int j = 0; j < cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
        int chk = 0;
        int idx = 0;
        for(int j = 0; j < dq.size(); j++) {
            if(dq[j] == cities[i]) {
                chk = 1;
                idx = j;
                break;
            }
        }
        if(chk == 0) {
            answer += 5;
        }
        else {
            answer += 1;
        }
        if(n == 0) {
            continue;
        }
        if(chk == 1) {
            vector<string> tmp;
            for(int j = 0; j < idx; j++) {
                tmp.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
            dq.push_back(cities[i]);
            for(int j = tmp.size()-1; j >= 0; j--) {
                dq.push_front(tmp[j]);
            }
        }
        else {
            if(dq.size() < n) {
                dq.push_back(cities[i]);
        }
        else {
                dq.pop_front();
                dq.push_back(cities[i]);
            }
        }
        /*
        for(int j = 0; j < dq.size(); j++) {
            cout << dq[j] << " ";
        }
        cout << "\n";
        */
    }
    return answer;
}