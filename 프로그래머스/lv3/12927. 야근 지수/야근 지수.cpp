#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    for(int i = 0; i < n; i++) {
        if(pq.empty()) {
            break;
        }
        if(pq.top() == 1) {
            pq.pop();
        }
        else {
            pq.push(pq.top()-1);
            pq.pop();
        }
    }
    while(!pq.empty()) {
        answer += (pq.top()*pq.top());
        pq.pop();
    }
    return answer;
}