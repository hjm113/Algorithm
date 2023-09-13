#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int vis[105];
vector<int> ans;
int solution(vector<int> cards) {
    int answer = 0;
    int st = 1;
    for(int i = 0; i < cards.size(); i++) {
        cards[i]--;
    }
    for(int i = 0; i < cards.size(); i++) {
        int st = i;
        if(vis[st] == 1) {
            continue;
        }
        int cnt = 0;
        while(vis[st] == 0) {
            vis[st] = 1;
            st = cards[st];
            cnt++;
        }
        ans.push_back(cnt);
    }
    ans.push_back(0);
    sort(ans.begin(),ans.end(),greater());
    answer = ans[0]*ans[1];
    return answer;
}