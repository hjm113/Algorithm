#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <deque>
#define X first
#define Y second
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
deque <pair<int,int>> dq;
vector<int> cores;
long long solve(int h) {
    long long sum = 0;
    for(int i = 0; i < cores.size(); i++) {
        sum += (h/cores[i]+1);
    }
    return sum;
}

int solution(int n, vector<int> tmp) {
    int answer = 0;
    for(int i = 0; i < tmp.size(); i++) {
        cores.push_back(tmp[i]);
    }
    long long st = 0;
    long long en = 500000000;
    while(st < en) {
        long long mid = (st+en)/2;
        if(solve(mid) >= n) {
            en = mid;
        }
        else {
            st = mid+1;
        }
    }
    long long sum = -n;
    for(int i = 0; i < cores.size(); i++) {
        sum += (st/cores[i]+1);
    }
    for(int i = cores.size()-1; i >= 0; i--) {
        if(st % cores[i] == 0) {
            if(sum == 0) {
                answer = i+1;
                break;
            }
            sum--;
        }
    }
    return answer;
}