#include <string>
#include <vector>
#include <cmath> 
#include <iostream> 
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i <= d; i+=k) {
        float pos = floor(sqrt(pow(d,2)-pow(i,2)));
        int add = pos /k;
        add++;
        //cout << add << "\n";
        answer += add;
    }
    return answer;
}