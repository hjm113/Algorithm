#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;
queue<int> q;
deque<int> dq;
int bri[10005];
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = truck_weights.size();
    for(int i = 0; i < n; i++) {
        q.push(truck_weights[i]);
    }
    n = bridge_length;
    int sum = 0;
    int cnt = 0;
    bri[n] = q.front();
    q.pop();
    answer++;
    while(!q.empty()) {
        /*
        for(int i = 1; i <= n; i++) {
            cout << bri[i] << " ";
        }
        */
        for(int i = 1; i < n; i++) {
            bri[i] = bri[i+1];
        }
        //cout << "\n";
        bri[n] = 0;
        answer++;
        int sum = 0;
        int num = 0;
        for(int i = 1; i <= n; i++) {
            sum += bri[i];
            if(bri[i] > 0) {
                num++;
            }
        }
        if(sum + q.front() <= weight && num < bridge_length) {
            bri[n] = q.front();
            q.pop();
        }
    }
    answer += bridge_length;
    return answer;
}