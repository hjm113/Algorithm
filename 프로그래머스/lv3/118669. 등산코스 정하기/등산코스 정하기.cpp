#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> adj[50005];
int vis[50005];
int chk[50005];
int out[50005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int mx = 10000001;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(int i = 0; i < paths.size(); i++) {
        int a = paths[i][0];
        int b = paths[i][1];
        int c = paths[i][2];
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    for(int i = 0; i < 50004; i++) {
        vis[i] = mx;
    }
    for(int i = 0; i < summits.size(); i++) {
        out[summits[i]] = 1;
    }
    for(int i = 0; i < gates.size(); i++) {
        chk[gates[i]] = 1;
    }
    for(int i = 0; i < gates.size(); i++) {
        int cur = gates[i];
        for(auto nxt : adj[cur]) {
            pq.push({nxt.X,nxt.Y});
        }
    }
    int cnt = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(chk[cur.Y] == 1) {
            continue;
        }
        if(vis[cur.Y] <= cur.X) {
            continue;
        }
        //cout << cur.X << " " << cur.Y << "\n";
        vis[cur.Y] = cur.X;
        if(out[cur.Y] == 1) {
            continue;
        }
        for(auto nxt : adj[cur.Y]) {
            int mn = max(vis[cur.Y],nxt.X);
            if(vis[nxt.Y] < mn) {
                continue;
            }
            pq.push({mn,nxt.Y});
        }
    }
    
    int idx = 0;
    /*
    for(int i = 1; i <= n; i++) {
        cout << vis[i] << " ";
    }
    */
    sort(summits.begin(),summits.end());
    for(int i = 0; i < summits.size(); i++) {
        if(mx > vis[summits[i]]) {
            mx = vis[summits[i]];
            idx = summits[i];
        }
    }
    answer.push_back(idx);
    answer.push_back(mx);
    return answer;
}