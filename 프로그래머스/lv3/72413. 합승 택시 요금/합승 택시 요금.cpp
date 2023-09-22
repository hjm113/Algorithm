#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int mx = 2000000000;
vector<pair<int,int>> adj[205];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = mx;
    for(int i = 0; i < fares.size(); i++) {
        int d = fares[i][0];
        int c = fares[i][1];
        int f = fares[i][2];
        adj[d].push_back({f,c});
        adj[c].push_back({f,d});
    }
    for(int i = 1; i <= n; i++) {
        int d[205] = {};
        for(int j = 0; j < 205; j++) {
            d[j] = mx;
        }
        d[i] = 0;
        pq.push({d[i],i});
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(d[cur.Y] != cur.X) {
                continue;
            }
            for(auto nxt : adj[cur.Y]) {
                if(d[nxt.Y] > cur.X+nxt.X) {
                    d[nxt.Y] = cur.X+nxt.X;
                    pq.push({cur.X+nxt.X,nxt.Y});
                }
            }
        }
        int sum = d[s]+d[a]+d[b];
        if(answer > sum) {
            answer = sum;
        }
    }
    return answer;
}