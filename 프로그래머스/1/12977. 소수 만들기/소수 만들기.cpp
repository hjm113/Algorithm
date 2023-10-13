#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int chk[60005];
int num[55];
int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 2; i*i <= 60000; i++) {
        if(chk[i] == 1) {
            continue;
        }
        for(int j = i*i; j <= 60000; j+= i) {
            chk[j] = 1;
        }
    }
    for(int i = nums.size()-3; i < nums.size(); i++) {
        num[i] = 1;
    }
    do{
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(num[i] == 1) {
                sum += nums[i];
            }
        }
        if(chk[sum] == 0) {
            answer++;
        }
    }while(next_permutation(num,num+nums.size()));
    /*
    for(int i = 2; i <= 6000; i++) {
        if(chk[i] == 0) {
            cout << i << "\n";
        }
    }
    */
    return answer;
}