#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length() - k;
    int st = 0;
    while(1) {
        int idx = 0;
        int mx = '!';
        for(int i = st; i <= number.length()-n; i++) {
            if(mx < number[i]) {
                mx = number[i];
                idx = i;
            }
        }
        n--;
        k--;
        st = idx + 1;
        answer += number[idx];
        if(n == 0) {
            break;
        }
    }
    return answer;
}