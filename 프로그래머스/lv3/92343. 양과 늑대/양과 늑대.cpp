#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> adj[20];
vector<int> info;
int cut[18][18][18];
int mx = 0;
int cnt = 0;
void dfs(int cur, int sums, int sumw, vector<int> chk , vector<int> vis) {
    vis[cur] = 1;
    if(mx < sums) {
        mx = sums;
    }
    for(auto nxt : adj[cur]) {
        if(vis[nxt] == 1) {
            continue;
        }
        vis[nxt] = 1;
        if(chk[nxt] == 1) {
            dfs(nxt, sums, sumw, chk, vis);
        }
        if(chk[nxt] == 0 && info[nxt] == 0) {
            sums++;
            chk[nxt] = 1;
            vector<int> tmp(17,0);
            dfs(nxt, sums, sumw, chk, tmp);
        }
        if(chk[nxt] == 0 && info[nxt] == 1) {
            if(sums <= sumw+1) {
                continue;
            }
            sumw++;
            chk[nxt] = 1;
            dfs(nxt, sums, sumw, chk, vis);
            chk[nxt] = 0;
            sumw--;
        }
    }
}

int solution(vector<int> inf, vector<vector<int>> edges) {
    int answer = 0;
    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < inf.size(); i++) {
        info.push_back(inf[i]);
    }
    vector<int> chk;
    vector<int> vis;
    for(int i = 0; i < 17; i++) {
        chk.push_back(0);
        vis.push_back(0);
    }
    chk[0] = 1;
    dfs(0, 1, 0, chk, vis);
    cout << mx;
    answer = mx;
    return answer;
}