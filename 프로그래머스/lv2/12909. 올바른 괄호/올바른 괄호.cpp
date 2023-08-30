#include<string>
#include <iostream>
#include <deque>
using namespace std;
deque<char> dq;
bool solution(string s)
{
    bool answer = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            dq.push_back('(');
        }
        if(s[i] == ')') {
            if(dq.size() > 0) {
                dq.pop_back();
            }
            else {
                answer = false;
                break;
            }
        }
    }
    if(dq.size() > 0) {
        answer = false;
    }
    return answer;
}