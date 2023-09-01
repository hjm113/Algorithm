#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    while(1) {
        int chk = -1;
        string tmp = "";
        for(int i = 0; i < s.length(); i++) {
            if(i != s.length()-1 && s[i] == s[i+1]) {
                i++;
                chk = 1;
                continue;
            }
            if(tmp.length() > 0) {
                if(tmp[tmp.length()-1] == s[i]) {
                    tmp.pop_back();
                    continue;
                }
                tmp += s[i];
            }
            else {
                tmp += s[i];
            }
        }
        //cout << tmp << "\n";
        s = tmp;
        if(tmp == "") {
            answer = 1;
            break;
        }
        if(chk == -1) {
            break;
        }
    }
    return answer;
}