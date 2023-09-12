#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[100005];
vector<int> adj[100005];
queue<int> q;
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    for(int i = 0; i < 100004; i++) {
        vis[i] = -1;
    }
    q.push(destination);
    vis[destination] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
            if(vis[nxt] > -1) {
                continue;
            }
            vis[nxt] = vis[cur]+1;
            q.push(nxt);
        }
    }
    for(int i = 0; i < sources.size(); i++) {
        answer.push_back(vis[sources[i]]);
    }
    return answer;
}