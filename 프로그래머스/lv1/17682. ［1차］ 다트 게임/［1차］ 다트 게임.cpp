#include <string>
#include <iostream>
using namespace std;

int solution(string dart) {
    int answer = 0;
    int pre = 0;
    int num = 0;
    for(int i = 0; i < dart.length(); i++) {
        if(dart[i] >= '0' && dart[i] <= '9') {
            pre = num;
            num = dart[i] - '0';
        }
        if(dart[i] == '1' && dart[i+1] == '0') {
            pre = num;
            num = 10;
            i++;
        }
        if(dart[i] == 'S') {
            answer += num;
        }
        if(dart[i] == 'D') {
            num *= num;
            answer += num;
        }
        if(dart[i] == 'T') {
            num *= (num*num);
            answer += num;
        }
        if(dart[i] == '*') {
            answer += pre;
            answer += num;
            num *= 2;
        }
        if(dart[i] == '#') {
            num *= -1;
            answer += num*2;
        }
        //cout << answer << "\n";
    }
    return answer;
}