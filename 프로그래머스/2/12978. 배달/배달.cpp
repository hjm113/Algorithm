#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> adj[55];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[55];
int mx = 2000000000;
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    for(int i = 0; i < 55; i++) {
        dist[i] = mx;
    }
    dist[1] = 0;
    pq.push({dist[1],1});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.Y] != cur.X) {
            continue;
        }
        for(auto nxt : adj[cur.Y]) {
            if(dist[nxt.Y] > cur.X+nxt.X) {
                dist[nxt.Y] = cur.X+nxt.X;
                pq.push({cur.X+nxt.X,nxt.Y});
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K) {
            answer++;
        }
    }
    return answer;
}