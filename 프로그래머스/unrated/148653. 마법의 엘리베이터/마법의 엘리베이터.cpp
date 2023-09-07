#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    int idx = 1;
    int cnt = 0;
    while(storey > 0) {
        int digit = storey % 10;
        if(digit < 5) {
            storey -= digit*idx;
            cnt += digit;
        }
        else if(digit > 5){
            int a = idx*10 - digit;
            storey += a;
            cnt += a;
        }
        else {
            int fst = (storey % 100)/10;
            if(fst < 5) {
                storey -= digit*idx;
                cnt += digit;
            }
            else {
                int a = idx*10 - digit;
                storey += a;
                cnt += a;
            }
        }
        /*
        cout << cnt << "\n";
        cout << storey << "\n\n";
        */
        storey /= 10;
    }
    answer = cnt;
    return answer;
}