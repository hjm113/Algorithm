#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int chk[5];
int mx = 2000000000;
int ans = 0;
int ary[15];
vector<string> mine;
void dfs(int k, int u) {
    if(k == u) {
        int ans =0;
        for(int i = 0; i < u; i++) {
            for(int j = i*5; j < (i*5)+5; j++) {
                if(j >= mine.size()) {
                    break;
                }
                if(ary[i] == 0) {
                    ans+= 1;
                }
                if(ary[i] == 1) {
                    if(mine[j] == "diamond") {
                        ans += 5;
                    }
                    else {
                        ans += 1;
                    }
                }
                if(ary[i] == 2) {
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
        if(ans < mx) {
            mx = ans;
        }
        return;
    }
    /*
    */
    for(int i = 0; i < 3; i++) {
        if(chk[i] == 0) {
            continue;
        }
        chk[i]--;
        ary[k] = i;
        dfs(k+1,u);
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
    dfs(0,n);
    answer = mx;
    return answer;
}