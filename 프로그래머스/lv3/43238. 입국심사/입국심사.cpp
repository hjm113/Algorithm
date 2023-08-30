#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long num = 0;
vector<int> ins;
int solve(long long n) {
    long long sum = 0;
    for(int i = 0; i < ins.size(); i++) {
        sum += (n/ins[i]);
    }
    if(sum >= num) {
        return 1;
    }
    else {
        return 0;
    }
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long st = 1;
    long long en = 1000000000000000000;
    num = n;
    for(int i = 0; i < times.size(); i++) {
        ins.push_back(times[i]);
    }
    while(st < en) {
        long long mid = (st+en)/2;
        if(solve(mid) == 1) {
            en = mid;
        }
        else {
            st = mid+1;
        }
    }
    answer = st;
    return answer;
}