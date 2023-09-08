#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0;
    int len = enemy.size();
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        sum += enemy[i];
        pq.push(enemy[i]);
        if(sum > n) {
            if(cnt == k) {
                break;
            }
            sum -= pq.top();
            pq.pop();
            cnt++;
        }
        answer = i+1;
    }
    return answer;
}