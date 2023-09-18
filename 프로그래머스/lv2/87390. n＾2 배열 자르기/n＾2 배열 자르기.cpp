#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int sx = left/n;
    int ex = right/n;
    int st = left%n;
    int en = right%n;
    for(int i = sx; i <= ex; i++) {
        if(i == ex) {
            n = en+1;
        }
        for(int j = st; j < n; j++) {
            if(j+1 <= i+1) {
                answer.push_back(i+1);
            }
            else {
                answer.push_back(j+1);
            }
        }
        st = 0;
    }
    return answer;
}