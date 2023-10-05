#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> ans;
vector<string> ans2;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        int a = arr1[i] | arr2[i];
        string tmp = "";
        while(a > 0) {
            tmp += to_string(a%2);
            a /= 2;
        }
        while(tmp.length() < n) {
            tmp += "0";
        }
        reverse(tmp.begin(),tmp.end());
        string ans = "";
        for(int i = 0; i < tmp.length(); i++) {
            if(tmp[i] == '1') {
                ans += "#";
            }
            else {
                ans += " ";
            }
        }
        answer.push_back(ans);
    }
    
    return answer;
}