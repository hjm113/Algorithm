#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int chk[5];
int mx = 2000000000;
int ary[15];
vector<string> mine;
void dfs(int k, int used, int u, int ans) {
    if(k == u+1) {
        //cout << ans << "\n";
        if(ans < mx) {
            mx = ans;
        }
        return;
    }
    if(used != -1) {
        for(int j = (k-1)*5; j < (k-1)*5+5; j++) {
            if(j >= mine.size()) {
                break;
            }
            if(used == 0) {
                ans+= 1;
            }
            if(used == 1) {
                if(mine[j] == "diamond") {
                    ans += 5;
                }
                else {
                    ans += 1;
                }
            }
            if(used == 2) {
                if(mine[j] == "diamond") {
                    ans += 25;
                }
                else if(mine[j] == "iron") {
                    ans += 5;
                }
                else {
                    ans += 1;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        if(chk[i] == 0) {
            if(k == u) {
                dfs(k+1,i,u,ans);
            }
            continue;
        }
        chk[i]--;
        dfs(k+1,i,u,ans);
        chk[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int n = minerals.size()/5;
    if(minerals.size() % 5 != 0) {
        n++;
    }
    int cnt = 0;
    for(int i = 0; i < minerals.size(); i++) {
        mine.push_back(minerals[i]);
    }
    for(int i = 0; i < picks.size(); i++) {
        chk[i] = picks[i];
        cnt += picks[i];
    }
    n = min(n,cnt);
    dfs(0,-1,n,0);
    answer = mx;
    return answer;
}