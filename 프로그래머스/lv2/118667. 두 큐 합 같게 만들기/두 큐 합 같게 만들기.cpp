#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q1;
queue<int> q2;
typedef long long ll;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i = 0; i < queue1.size(); i++) {
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    ll find = (sum1+sum2)/2;
    int cnt = 0;
    while(!q2.empty()) {
        if(sum1 == find) {
            answer = cnt;
            break;
        }
        if(sum1 > find) {
            sum1 -= q1.front();
            q1.pop();
        }
        else {
            q1.push(q2.front());
            sum1 += q2.front();
            q2.pop();
        }
        if(q2.empty()) {
            answer = -1;
        }
        cnt++;
    }
    return answer;
}