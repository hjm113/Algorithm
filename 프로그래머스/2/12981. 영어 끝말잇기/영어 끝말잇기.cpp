#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
int cnt[15];
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int m = words.size();
    char lst = words[0][words[0].length()-1];
    for(int i = 0; i < m; i++) {
        int idx = (i%n)+1;
        cnt[idx]++;
        if(mp[words[i]] == 1 || words[i].length() == 1) {
            answer.push_back(idx);
            answer.push_back(cnt[idx]);
            break;
        }
        if(i != 0) {
            if(words[i][0] != lst) {
                answer.push_back(idx);
                answer.push_back(cnt[idx]);
                break;
            }
        }
        lst = words[i][words[i].length()-1];
        mp[words[i]] = 1;
    }
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}