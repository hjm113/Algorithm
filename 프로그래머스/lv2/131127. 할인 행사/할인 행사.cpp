#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> mp;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = number.size();
    for(int i = 0; i <= discount.size()-10; i++) {
        for(int j = 0; j < n; j++) {
            mp[want[j]] = number[j];
        }
        for(int j = i; j < i+10; j++) {
            mp[discount[j]]--;
        }
        int chk = 0;
        for(int j = 0; j < n; j++) {
            if(mp[want[j]] > 0) {
                chk = 1;
            }
        }
        if(chk == 0) {
            //cout << i << "\n";
            answer++;
        }
    }
    return answer;
}