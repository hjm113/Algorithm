#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    for(int i = n; i >= 0; i--) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(citations[j] >= i) {
                cnt++;
            }
        }
        if(cnt >= i && n-cnt <= cnt) {
            answer = i;
            break;
        }
    }
    return answer;
}