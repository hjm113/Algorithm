#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    int cnt = n-1;
    while(1) {
        int num[25]  = {};
        for(int i = cnt; i < n; i++) {
            num[i] = 1;
        }
        do{
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(num[i] == 0) {
                    sum += numbers[i];
                }
                else {
                    sum -= numbers[i];
                }
            }
            if(sum == target) {
                answer++;
            }
        }while(next_permutation(num,num+n));
        if(cnt == 0) {
            break;
        }
        cnt--;
    }
    return answer;
}