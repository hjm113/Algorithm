#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> adj[300005];
int ary[300005];
int dp[2][300005];
int lst[300005];
void dfs(int cur) {
    if(adj[cur].size() == 0) {
        return;
    }
    dp[0][cur] = lst[cur];
    int chk = 0;
    for(auto nxt : adj[cur]) {
        dfs(nxt);
        if(dp[0][nxt] == dp[1][nxt]) {
            chk = 1;
        }
        dp[0][cur] += dp[0][nxt];
        dp[1][cur] += dp[0][nxt];
    }
    if(chk == 1) {
        dp[0][cur] -= lst[cur];
    }
}
int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for(int i = 0; i < sales.size(); i++) {
        ary[i+1] = sales[i];
        lst[i+1] = sales[i];
        dp[1][i+1] = sales[i];
    }
    for(int i = 0; i < links.size(); i++) {
        int a = links[i][0];
        int b = links[i][1];
        adj[a].push_back(b);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
            lst[cur] = min(lst[cur],ary[nxt]);
            q.push(nxt);
        }
    }
    dfs(1);
    cout << dp[0][1] << " " << dp[1][1] << "asdfsdf\n";
    answer = min(dp[0][1],dp[1][1]);
    cout << dp[0][5] << " " << dp[1][5] << " " << lst[5];
    return answer;
}