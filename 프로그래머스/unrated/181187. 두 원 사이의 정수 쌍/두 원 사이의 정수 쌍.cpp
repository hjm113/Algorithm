#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i = 1; i <= r2; i++) {
        int mx = 0;
        int mn = 0;
        mx = (int)floor(sqrt(pow(r2, 2) - pow(i, 2)));
        if(i >= r1) {
            mn = 1;
        }
        else {
            mn = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        }
        answer += mx-mn+1;
    }
    answer += (r2-r1+1);
    answer *= 4;
    return answer;
}