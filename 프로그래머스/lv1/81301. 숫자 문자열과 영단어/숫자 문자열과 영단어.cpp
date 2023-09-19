#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            tmp += s[i];
        }
        if(i+3 < s.length() && s.substr(i,4) == "zero") {
            tmp += '0';
            i += 3;
        }
        if(i+2 < s.length() && s.substr(i,3) == "one") {
            tmp += '1';
            i += 2;
        }
        if(i+2 < s.length() && s.substr(i,3) == "two") {
            tmp += '2';
            i += 2;
        }
        if(i+4 < s.length() && s.substr(i,5) == "three") {
            tmp += '3';
            i += 4;
        }
        if(i+3 < s.length() && s.substr(i,4) == "four") {
            tmp += '4';
            i += 3;
        }
        if(i+3 < s.length() && s.substr(i,4) == "five") {
            tmp += '5';
            i += 3;
        }
        if(i+2 < s.length() && s.substr(i,3) == "six") {
            tmp += '6';
            i += 2;
        }
        if(i+4 < s.length() && s.substr(i,5) == "seven") {
            tmp += '7';
            i += 4;
        }
        if(i+4 < s.length() && s.substr(i,5) == "eight") {
            tmp += '8';
            i += 4;
        }
        if(i+3 < s.length() && s.substr(i,4) == "nine") {
            tmp += '9';
            i += 3;
        }
    }
    answer += stoi(tmp);
    return answer;
}