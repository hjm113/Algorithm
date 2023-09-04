#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> ans;
int ary[1005];
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i = 0; i < book_time.size(); i++) {
        string a = book_time[i][0];
        string b = book_time[i][1];
        string tmp = "";
        int at = 0;
        for(int j = 0; j < a.length(); j++) {
            if(a[j] == ':') {
                at = stoi(tmp)*60;
                tmp = "";
                continue;
            }
            tmp += a[j];
            if(j == a.length() - 1) {
                at += stoi(tmp);
            }
        }
        int bt = 0;
        tmp = "";
        for(int j = 0; j < b.length(); j++) {
            if(b[j] == ':') {
                bt = stoi(tmp)*60;
                tmp = "";
                continue;
            }
            tmp += b[j];
            if(j == b.length() - 1) {
                bt += stoi(tmp);
            }
        }
        ans.push_back({at,bt});
    }
    sort(ans.begin(),ans.end());
    int cnt = 1;
    for(int i = 0; i < ans.size(); i++) {
        //cout << ans[i].X << " " << ans[i].Y << " asdf \n";
        int mx = 9000000;
        int idx = -1;
        for(int j = 0; j < cnt; j++) {
            if(ary[j] <= ans[i].X) {
                if(mx > ary[j]) {
                    idx = j;
                    mx = ary[j];
                }
            }
        }
        if(idx != -1) {
            ary[idx] = ans[i].Y+10;
            //cout << idx << " " << ans[i].Y << "\n";
        }
        else {
            ary[cnt] = ans[i].Y+10;
            //cout << cnt << " " << ans[i].Y << "\n";
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}