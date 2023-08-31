#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> win[105];
vector<int> lose[105];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); i++) {
        win[results[i][0]].push_back(results[i][1]);
        lose[results[i][1]].push_back(results[i][0]);
    }
    for(int i = 1; i <= n; i++) {
        queue<int> q;
        int vis[105] = {};
        vis[i] = 1;
        q.push(i);
        int cnt = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto nxt : win[cur]) {
                if(vis[nxt] > 0) {
                    continue;
                }
                cnt++;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
        int vis1[105] = {};
        vis1[i] = 1;
        q.push(i);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto nxt : lose[cur]) {
                if(vis1[nxt] > 0) {
                    continue;
                }
                cnt++;
                vis1[nxt] = 1;
                q.push(nxt);
            }
        }
        if(cnt == n-1) {
            answer++;
        }
    }
    return answer;
}