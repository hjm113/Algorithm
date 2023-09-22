#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n == 0) {
        answer.push_back(-1);
        return answer;
    }
    for(int i = 0; i < n; i++) {
        int chk = s/(n-i);
        answer.push_back(chk);
        s -= chk;
    }
    sort(answer.begin(),answer.end());
    return answer;
}