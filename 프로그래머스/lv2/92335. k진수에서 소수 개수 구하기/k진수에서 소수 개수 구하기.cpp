#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long> ans;
int solution(int n, int k) {
    int answer = 0;
    string tmp = "";
    while(n > 0) {
        tmp += to_string(n%k);
        n /= k;
    }
    reverse(tmp.begin(),tmp.end());
    for(int i = 0; i < tmp.length(); i++) {
        string num = "";
        if(tmp[i] != '0') {
            num += tmp[i];
            int idx = i+1;
            while(idx < tmp.length()) {
                if(tmp[idx] == '0') {
                    break;
                }
                num += tmp[idx];
                idx++;
            }
            ans.push_back(stol(num));
            i = idx-1;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        int chk = 0;
        if(ans[i] == 1) {
            continue;
        }
        for(long long j = 2; j*j <= ans[i]; j++) {
            if(ans[i] % j == 0) {
                chk = 1;
            }
        }
        if(chk == 0) {
            answer++;
        }
    }
    return answer;
}