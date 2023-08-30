#include <string>
#include <vector>
#include <deque>
#include <iostream>
#define X first
#define Y second
using namespace std;
deque<pair<int,int>> dq;
int ary[100005];
int sc[100005];
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    prices.push_back(0);
    int n = prices.size();
    int ret = 0;
    for(int i = 0; i < n; i++) {
        int cnt = i;
        if(prices[i] == 0) {
            cnt = i-1;
        }
        if(dq.empty()) {
            dq.push_back({prices[i],i});
        }
        else {
            while(!dq.empty() && dq.back().X > prices[i]) {
                ary[dq.back().Y] = cnt - dq.back().Y;
                dq.pop_back();
            }
            dq.push_back({prices[i],i});
        }
    }
    for(int i = 0; i < n-1; i++) {
        answer.push_back(ary[i]);
    }
    return answer;
}