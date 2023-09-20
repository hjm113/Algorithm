#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int n = lottos.size();
    int cntco = 0;
    int cnto = 0;
    for(int i = 0; i < n; i++) {
        if(lottos[i] == 0) {
            cnto++;
            continue;
        }
        for(int j = 0; j < n; j++) {
            if(lottos[i] == win_nums[j]) {
                cntco++;
                break;
            }
        }
    }
    if(cntco+cnto == 6) {
        answer.push_back(1);
    }
    else if(cntco+cnto == 5) {
        answer.push_back(2);
    }
    else if(cntco+cnto == 4) {
        answer.push_back(3);
    }
    else if(cntco+cnto == 3) {
        answer.push_back(4);
    }
    else if(cntco+cnto == 2) {
        answer.push_back(5);
    }
    else {
        answer.push_back(6);
    }
    
    if(cntco == 6) {
        answer.push_back(1);
    }
    else if(cntco == 5) {
        answer.push_back(2);
    }
    else if(cntco == 4) {
        answer.push_back(3);
    }
    else if(cntco == 3) {
        answer.push_back(4);
    }
    else if(cntco == 2) {
        answer.push_back(5);
    }
    else {
        answer.push_back(6);
    }
    return answer;
}