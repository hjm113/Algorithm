#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#define X first
#define Y second
using namespace std;
multiset<int> pq;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i = 0; i < operations.size(); i++) {
        char c = operations[i][0];
        string tmp = "";
        for(int j = 2; j < operations[i].length(); j++) {
            tmp += operations[i][j];
        }
        int a = stoi(tmp);
        if(c == 'I') {
            pq.insert(a);
        }
        if(c == 'D' && a == -1 && !pq.empty()) {
            pq.erase(pq.begin());
        }
        if(c == 'D' && a == 1 && !pq.empty()) {
            pq.erase(prev(pq.end()));
        }
    }
    if(pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*prev(pq.end()));
        answer.push_back(*pq.begin());
    }
    return answer;
}