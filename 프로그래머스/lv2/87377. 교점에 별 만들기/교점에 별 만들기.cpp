#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> ans;
char board[1105][1105];
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int n = line.size();
    for(int i = 0; i < 1100; i++) {
        for(int j = 0; j < 1100; j++) {
            board[i][j] = '.';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ll a = line[i][0];
            ll b = line[i][1];
            ll e = line[i][2];
            ll c = line[j][0];
            ll d = line[j][1];
            ll f = line[j][2];
            if(a*d-b*c == 0) {
                continue;
            }
            ll xn = b*f-e*d;
            ll xm = a*d-b*c;
            ll yn = e*c-a*f;
            ll ym = a*d-b*c;
            if(abs(xn) % abs(xm) == 0 && abs(yn) % abs(ym) == 0) {
                ans.push_back({yn/ym,xn/xm});
            }
        }
    }
    ll xmx = -(1ll<<63)+1;
    ll xmn = (1ll<<62)-1;
    ll ymx = -(1ll<<62)+1;
    ll ymn = (1ll<<62)-1;
    for(int i = 0; i < ans.size(); i++) {
        if(xmx < ans[i].X) {
            xmx = ans[i].X;
        }
        if(xmn > ans[i].X) {
            xmn = ans[i].X;
        }
        if(ymx < ans[i].Y) {
            ymx = ans[i].Y;
        }
        if(ymn > ans[i].Y) {
            ymn = ans[i].Y;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        auto cur = ans[i];
        board[cur.X-xmn][cur.Y-ymn] = '*';
    }
    ll st = xmx-xmn;
    ll en = ymx-ymn;
    for(ll i = st; i >= 0; i--) {
        string tmp = "";
        for(ll j = 0; j <= en; j++) {
            tmp += board[i][j];
        }
        answer.push_back(tmp);
    }
    return answer;
}