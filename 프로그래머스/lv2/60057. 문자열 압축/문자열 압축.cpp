#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(string s) {
    int n = s.length();
    int answer = n;
    string ans = "";
    for(int i = 1; i <= n/2; i++) {
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
        if(answer > ans.length()) {
            answer = ans.length();
        }
        //cout << ans << "\n";
        ans = "";
    }
    return answer;
}