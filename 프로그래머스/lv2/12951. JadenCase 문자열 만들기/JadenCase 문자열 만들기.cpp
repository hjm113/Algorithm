#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            cnt = 0;
            continue;
        }
        if(i == 0 || cnt == 0) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                s[i] = (char)(s[i]-32);
            }
            cnt++;
        }
        else {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = (char)(32+s[i]);
            }
        }
        
    }
    answer = s;
    return answer;
}