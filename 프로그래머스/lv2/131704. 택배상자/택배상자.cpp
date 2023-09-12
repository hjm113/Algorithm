#include <string>
#include <vector>
#include <deque>
using namespace std;
deque<int> dq;
int solution(vector<int> order) {
    int answer = 0;
    int box = 0;
    int idx = 0;
    for(int i = 1; i <= order.size(); i++) {
        if(order[i] == order[idx]) {
            idx++;
            answer++;
        }
        else {
            dq.push_back(i);
        }
        while(!dq.empty() && dq.back() == order[idx]) {
            dq.pop_back();
            idx++;
            answer++;
        }
    }
    return answer;
}