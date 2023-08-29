#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
char c[6] = {'A', 'E', 'I', 'O', 'U'};
int n = 0;
string tmp = "";
int cnt = 0;
map<string,int> mp;
void dfs(int k) {
    mp[tmp] = cnt;
    cnt++;
    if(k == 5) {
        return;
    }
    for(int i = 0; i < 5; i++) {
        string tt = tmp;
        tmp += c[i];
        dfs(k+1);
        tmp = tt;
    }
}

int solution(string word) {
    int answer = 0;
    n = word.length();
    dfs(0);
    answer = mp[word];
    return answer;
}