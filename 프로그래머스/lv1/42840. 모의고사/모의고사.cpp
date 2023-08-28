#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int s1[15] = {1,2,3,4,5};
int s2[15] = {2,1,2,3,2,4,2,5};
int s3[15] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int n = answers.size();
    for(int i = 0; i < n; i++) {
        //cout << i%9 << "\n";
        if(answers[i] == s1[i%5]) {
            cnt1++;
        }
        if(answers[i] == s2[i%8]) {
            cnt2++;
        }
        if(answers[i] == s3[i%10]) {
            cnt3++;
        }
    }
    int mx = max({cnt1,cnt2,cnt3});
    if(mx == cnt1) {
        answer.push_back(1);
    }
    if(mx == cnt2) {
        answer.push_back(2);
    }
    if(mx == cnt3) {
        answer.push_back(3);
    }
    //cout << cnt2;
    return answer;
}