#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> ans;
string solution(string s) {
    string tmp = "";
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            ans.push_back(stoi(tmp));
            tmp = "";
        }
        tmp += s[i];
        if(i == n-1) {
            ans.push_back(stoi(tmp));
        }
    }
    sort(ans.begin(),ans.end());
    string answer = "";
    answer += to_string(ans[0]);
    answer += " ";
    answer += to_string(ans[ans.size()-1]);
    return answer;
}