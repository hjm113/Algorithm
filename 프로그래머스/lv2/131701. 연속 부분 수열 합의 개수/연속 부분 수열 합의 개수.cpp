#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> ans;
int chk[1500000];
int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n+i; j++) {
            int idx = j;
            idx %= n;
            sum += elements[idx];
            chk[sum] = 1;
        }
    }
    for(int i = 0; i < 1500000; i++) {
        if(chk[i] == 1) {
            answer++;
        }
    }
    return answer;
}