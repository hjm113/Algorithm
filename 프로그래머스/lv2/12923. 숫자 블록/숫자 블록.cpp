#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int ary[5005];
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = 1; i <= 10000000; i++) {
        ll re = begin/i;
        if(begin % i != 0) {
            re++;
        }
        ll st = i*re;
        for(ll j = st; j <= end; j+=i) {
            if(j == i) {
                continue;
            }
            ary[j-begin] = i;
        }
    }
    for(ll i = 0; i <= end-begin; i++) {
        answer.push_back(ary[i]);
    }
    return answer;
}