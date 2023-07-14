#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int vis[205];
int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 1) {
            continue;
        }
        ans++;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int nxt = 0; nxt < computers[cur].size(); nxt++) {
                if(computers[cur][nxt] == 0) {
                    continue;
                }
                if(vis[nxt] == 1) {
                    continue;
                }
                q.push(nxt);
                vis[nxt] = 1;
            }
        }
    }
    return ans;
    
}