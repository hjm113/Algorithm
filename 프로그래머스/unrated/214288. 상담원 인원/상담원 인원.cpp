#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int sum = 0;
int chk = 0;
int can = 0;
vector<tuple<int,int,int>> ans;
int ary[10];
int mx = 2000000000;
void dfs(int k) {
    if(k == chk+1) {
        if(sum == can) {
            int cnt = 0;
            priority_queue<int, vector<int>, greater<int>> pq[10];
            for(int i = 0; i < ans.size(); i++) {
                int a,b,c;
                tie(a,b,c) = ans[i];
                if(pq[c].size() < ary[c]) {
                    pq[c].push(a+b);
                }
                else {
                    if(pq[c].top() > a) {
                        int re = pq[c].top();
                        cnt += (re - a);
                        pq[c].pop();
                        pq[c].push(re+b);
                    }
                    else {
                        pq[c].pop();
                        pq[c].push(a+b);
                    }
                    
                }
            }
            if(mx > cnt) {
                mx = cnt;
            }
        }
        return;
    }
    for(int i = 1; i <= can; i++) {
        sum += i;
        ary[k] = i;
        dfs(k+1);
        sum -= i;
    }
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    chk = k;
    can = n;
    for(int i = 0; i < reqs.size(); i++) {
        ans.push_back({reqs[i][0],reqs[i][1],reqs[i][2]});
    }
    dfs(1);
    answer = mx;
    return answer;
}