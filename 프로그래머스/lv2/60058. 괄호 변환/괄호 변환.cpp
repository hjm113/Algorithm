#include <string>
#include <vector>
#include <deque>
#include <iostream>
#define X first
#define Y second
using namespace std;
int chk(string s) {
    int n = s.length();
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            if(dq.size() == 0) {
                return 0;
            }
            if(dq.back() == '(') {
                dq.pop_back();
            }
        }
        else {
            dq.push_back('(');
        }
    }
    if(dq.size() > 0) {
        return 0;
    }
    else {
        return 1;
    }
}
string spl(string s) {
    if(s == "") {
        return "";
    }
    string u = "";
    string v = "";
    int cnt1 = 0;
    int cnt2 = 0;
    int out = 0;
    for(int i = 0; i < s.length(); i++) {
        if(out == 0) {
            if(s[i] == '(') {
            u += '(';
            cnt1++;
            }
            else {
                u += ')';
                cnt2++;
            }       
        }
        else {
            v += s[i];
        }
        if(cnt1 == cnt2) {
            out = 1;
        }
    }
    if(chk(u) == 1) {
        return u + spl(v);
    }
    else {
        string tmp = "";
        for(int i = 1; i < u.length()-1; i++) {
            if(u[i] == '(') {
                tmp += ")";
            }
            else {
                tmp += "(";
            }
        }
        string val = "(" + spl(v) + ")" + tmp;
        return val;
    }
}

string solution(string p) {
    string answer = "";
    answer = spl(p);
    return answer;
}