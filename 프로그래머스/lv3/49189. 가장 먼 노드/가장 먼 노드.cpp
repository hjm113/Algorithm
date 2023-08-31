#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[20005];
queue<int> q;
int vis[20005];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    vis[1] = 1;
    int mx = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
            if(vis[nxt] > 0) {
                continue;
            }
            vis[nxt] = vis[cur] + 1;
            mx = vis[nxt];
            q.push(nxt);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == mx) {
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}