#include <string>
#include <vector>
#include <deque>
#include <tuple>
#include <iostream>
using namespace std;
deque<tuple<int,int,int>> dq;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0;
    int p = 0;
    for(int i = n-1; i >= 0; i--) {
        d += deliveries[i];
        p += pickups[i];
        int cnt = 0;
        while(d > 0 || p > 0) {
            d -= cap;
            p -= cap;
            cnt++;
        }
        answer += (i+1)*2*cnt;
    }
    return answer;
}