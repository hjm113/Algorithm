#include <string>
#include <vector>
#include <cmath>
#include <iostream>
int disc[5] = {10,20,30,40};
using namespace std;
int ary[10];
vector<int> user[105];
vector<int> emo;
int mx = 0;
int mxx[105];
void dfs(int k, int n, int m) {
    if(k == n) {
        int cnt = 0;
        int left = 0;
        for(int i = 0; i < m; i++) {
            int dlim = user[i][0];
            int mlim = user[i][1];
            int money = 0;
            for(int j = 0; j < emo.size(); j++) {
                if(ary[j] >= dlim) {
                    money += emo[j]-(emo[j]*ary[j]/100);
                    
                }
            }
            if(money >= mlim) {
                cnt++;
            }
            else {
                left += money;
            }
        }
        if(mx <= cnt) {
            mx = cnt;
            //cout << cnt << " " << left << "\n";
            mxx[cnt] = max(mxx[cnt],left);
        }
        return;
    }
    for(int i = 0; i < 4; i ++) {
        ary[k] = disc[i];
        dfs(k+1,n,m);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int n = emoticons.size();
    for(int i = 0; i < n; i++) {
        emo.push_back(emoticons[i]);
    }
    for(int i = 0; i < users.size(); i++) {
        for(int j = 0; j < users[i].size(); j++) {
            user[i].push_back(users[i][j]);
        }
    }
    int m = users.size();
    dfs(0,n,m);
    answer.push_back(mx);
    answer.push_back(mxx[mx]);
    return answer;
}