#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#define X first
#define Y second
using namespace std;
deque<pair<int,int>> dq;
int mx[100005];
int chk[100005];
vector<pair<int,int>> ans;
int solution(vector<vector<int>> scores) {
    int answer = 1;
    int n = scores.size();
    for(int i = 0; i < n; i++) {
        dq.push_back({scores[i][0],scores[i][1]});
    }
    for(int i = 0; i < n; i++) {
        mx[dq[i].X] = max(mx[dq[i].X],dq[i].Y);
    }
    int st = mx[100000];
    for(int i = 99999; i >= 0; i--) {
        if(st > mx[i]) {
            mx[i] = st;
        }
        else {
            st = mx[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(mx[dq[i].X+1] > dq[i].Y) {
            chk[i] = 1;
        }
    }
    if(chk[0] == 1) {
        answer = -1;
        return answer;
    }
    int out = 0;
    for(int i = 0; i < n; i++) {
        if(chk[i] == 1) {
            out++;
            continue;
        }
        ans.push_back({dq[i].X+dq[i].Y,i});
    }
    sort(ans.begin(),ans.end(),greater());
    int cnt = 1;
    int val = ans[0].X;
    int chk = 1;
    for(int i = 1; i < ans.size(); i++) {
        chk++;
        if(val != ans[i].X) {
            val = ans[i].X;
            cnt = chk;
        }
        if(ans[i].Y == 0) {
            answer = cnt;
            break;
        }
    }
    return answer;
}