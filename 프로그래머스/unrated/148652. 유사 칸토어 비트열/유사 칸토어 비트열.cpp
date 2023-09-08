#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
vector<ll> ans[25];
vector<ll> kind[25];
int solution(int n, long long l, long long r) {
    int answer = 0;
    l--;
    r--;
    int pos = n;
    ans[pos].push_back(l);
    while(pos--) {
        l /= 5;
        ans[pos].push_back(l);
    }
    pos = n;
    ans[pos].push_back(r);
    while(pos--) {
        r /= 5;
        ans[pos].push_back(r);
    }
    int cnt = 1;
    //for(int i = 1; i <= n; i++) {
        //cout << ans[i][0] << " " << ans[i][1] << "\n";
    //}
    kind[0].push_back(1);
    kind[0].push_back(1);
    for(int i = 1; i <= n; i++) {
        if(kind[i-1][0] == 1) {
            int chk1 = ans[i][0] % 5;
            //cout << chk1 << "\n";
            if(chk1 != 2) {
                kind[i].push_back(1);
            }
            else {
                kind[i].push_back(0);
            }
        }
        else {
            kind[i].push_back(0);
        }
        if(kind[i-1][1] == 1) {
            int chk1 = ans[i][1] % 5;
            if(chk1 != 2) {
                kind[i].push_back(1);
            }
            else {
                kind[i].push_back(0);
            }
        }
        else {
            kind[i].push_back(0);
        }
    }
    for(int i = 1; i <= n; i++) {
        cnt *= 4;
        if(kind[i-1][0] == 1) {
            ll idx = ans[i][0] % 5;
            if(idx > 2) {
                cnt -= (idx-1);
            }
            else {
                cnt -= (idx);
            }
        }
        //cout << cnt << "\n";
        if(kind[i-1][1] == 1) {
            ll idx = ans[i][1] % 5;
            ll chk = 4-idx;
            if(chk > 2) {
                cnt -= (chk-1);
            }
            else {
                cnt -= (chk);
            }
        }
        //cout << cnt << "\n";
    }
    answer = cnt;
    return answer;
}