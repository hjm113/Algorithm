#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;
deque<pair<int,int>> adj;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> ans;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    for(int i = 0; i < jobs.size(); i++) {
        int a = jobs[i][0];
        int b = jobs[i][1];
        adj.push_back({a,b});
    }
    sort(adj.begin(),adj.end());
    int t = adj.front().X;
    pq.push({adj.front().Y,adj.front().X});
    adj.pop_front();
    while(!adj.empty()) {
        if(adj.front().X == t) {
            pq.push({adj.front().Y,adj.front().X});
            adj.pop_front();
        }
        else {
            break;
        }
    }
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        t += cur.X;
        ans.push_back(t-cur.Y);
        while(!adj.empty()) {
            if(adj.front().X <= t) {
                pq.push({adj.front().Y,adj.front().X});
                adj.pop_front();
            }
            else {
                break;
            }
        }
        if(pq.empty()) {
            if(!adj.empty()) {
                t = adj.front().X;
                pq.push({adj.front().Y,adj.front().X});
                adj.pop_front();
            }
            while(!adj.empty()) {
                if(adj.front().X == t) {
                    pq.push({adj.front().Y,adj.front().X});
                    adj.pop_front();
                }
                else {
                    break;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < ans.size(); i++) {
        //cout << ans[i] << " ";
        sum += ans[i];
    }
    answer = sum / ans.size();
    return answer;
}