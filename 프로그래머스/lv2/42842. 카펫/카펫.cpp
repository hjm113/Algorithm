#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= yellow; i++) {
        if(yellow % i == 0) {
            int a = max(yellow/i,i);
            int b = min(yellow/i,i);
            if((a+2)*2+b*2 == brown) {
                answer.push_back(a+2);
                answer.push_back(b+2);
                break;
            }
        }
    }
    return answer;
}