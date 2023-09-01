#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int sum = 0;
    while(1) {
        count++;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                cnt++;
            }
            else {
                sum++;
            }
        }
        string tmp = "";
        while(cnt > 0) {
            tmp += to_string(cnt%2);
            cnt /= 2;
        }
        reverse(tmp.begin(),tmp.end());
        cout << tmp << "\n";
        s = tmp;
        if(tmp == "1") {
            break;
        }
    }
    answer.push_back(count);
    answer.push_back(sum);
    return answer;
}