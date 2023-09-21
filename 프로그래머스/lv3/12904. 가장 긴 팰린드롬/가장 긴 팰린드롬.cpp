#include <iostream>
#include <string>
using namespace std;
int solution(string s) {
    int answer = 0;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        int sum = 1;
        int st = i-1;
        int en = i+1;
        int cnt = 0;
        while(st >= 0 || en < n) {
            if(s[st] != s[en]) {
                break;
            }
            cnt++;
            st--;
            en++;
        }
        sum += cnt*2;
        if(answer < sum) {
            answer = sum;
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] != s[i+1]) {
            continue;
        }
        int sum = 2;
        int st = i-1;
        int en = i+2;
        int cnt = 0;
        while(st >= 0 || en < n) {
            if(s[st] != s[en]) {
                break;
            }
            cnt++;
            st--;
            en++;
        }
        sum += cnt*2;
        if(answer < sum) {
            answer = sum;
        }
    }
    return answer;
}