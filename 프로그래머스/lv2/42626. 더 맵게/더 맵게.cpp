#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    int cnt = 0;
    while(1) {
        if(pq.top() >= K) {
            answer = cnt;
            break;
        }
        if(pq.size() < 2) {
            answer = -1;
            break;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+(b*2));
        cnt++;
    }
    return answer;
}