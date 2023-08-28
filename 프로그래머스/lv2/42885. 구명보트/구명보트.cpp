#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
deque <int> h;
int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    sort(people.begin(),people.end());
    for(int i = n-1; i >= 0; i--) {
        h.push_back(people[i]);
    }
    while(!h.empty()) {
        int a = h.front();
        h.pop_front();
        if(!h.empty()) {
            int b = h.back();
            if(a+b <= limit) {
                h.pop_back();
            }
        }
        answer++;
    }
    return answer;
}