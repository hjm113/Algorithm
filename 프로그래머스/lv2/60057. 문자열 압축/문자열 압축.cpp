#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mx = 2000000000;
int solution(string s) {
    int answer = 0;
    int n = s.length();
    string ans = "";
    for(int i = 1; i <= n/2+1; i++) {
        for(int j = 0; j < n; j+=i) {
            int idx = j;
            string tmp = s.substr(j,i);
            int cnt = 0;
            while(idx < n && s.substr(idx,i) == tmp) {
                idx += i;
                cnt++;
            }
            if(cnt > 1) {
                ans += to_string(cnt) + s.substr(j,i);
            }
            else {
                ans += s.substr(j,i);
            }
            j = idx-i;
        }
        if(mx > ans.length()) {
            mx = ans.length();
        }
        //cout << ans << "\n";
        ans = "";
    }
    answer = mx;
    return answer;
}