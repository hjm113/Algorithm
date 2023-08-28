#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;
priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
int chk[105];
vector<pair<int,int>> adj[105];
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i < costs.size(); i++) {
        adj[costs[i][0]].push_back({costs[i][1],costs[i][2]});
        adj[costs[i][1]].push_back({costs[i][0],costs[i][2]});
    }
    chk[0] = 1;
    for(auto nxt : adj[0]) {
        pq.push({nxt.Y,0,nxt.X});
    }
    int cnt = 0;
    while(cnt < n-1) {
        int a,b,c;
        tie(c,a,b) = pq.top();
        pq.pop();
        if(chk[b] == 1) {
            continue;
        }
        answer += c;
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(chk[nxt.X] == 1) {
                continue;
            }
            pq.push({nxt.Y,b,nxt.X});
        }
    }
    return answer;
}