#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
int solution(string name) {
    int n = name.length();
    for(int i = 0; i < n; i++) {
        answer += min(name[i]-'A','Z'-name[i]+1);
    }
    int move = n-1;
    for(int i = 0; i < n; i++) {
        int nxt = i+1;
        while(nxt < n && name[nxt] == 'A') {
            nxt++;
        }
        move = min(move,i+n-nxt+min(i,n-nxt));
    }
    answer += move;
    return answer;
}