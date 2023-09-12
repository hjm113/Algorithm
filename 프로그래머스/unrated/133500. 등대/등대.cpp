#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;
vector<int> adj[100005];
vector<pair<int,int>> ans;
int chk[100005];
int vis[100005];
int answer = 0;
void dfs(int cur) {
    vis[cur] = 1;
    for(auto nxt : adj[cur]) {
        if(vis[nxt] == 1) {
            continue;
        }
        dfs(nxt);
        if(chk[nxt] == 0 && chk[cur] == 0) {
            chk[cur] = 1;
            answer++;
        }
    }
}
int solution(int n, vector<vector<int>> lighthouse) {
    for(int i = 0; i < lighthouse.size(); i++) {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    return answer;
}