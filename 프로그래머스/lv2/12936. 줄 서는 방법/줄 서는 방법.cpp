#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
ll ary[30];
int used[30];
vector<int> solution(int n, long long k) {
    vector<int> answer;
    ll sum = 1;
    for(int i = 1; i <= n; i++) {
        sum *= i;
        ary[i] = sum;
    }
    int cnt = n-1;
    while(cnt > 0) {
        int chk = k/ary[cnt];
        if(k % ary[cnt] != 0) {
            chk++;
        }
        int fst = 0;
        while(chk > 0) {
            fst++;
            if(used[fst] == 0) {
                chk--;
            }
        }
        answer.push_back(fst);
        used[fst] = 1;
        if(k % ary[cnt] != 0) {
            k %= ary[cnt];
        }
        else {
            k = ary[cnt];
        }
        cnt--;
    }
    for(int i = 1; i <= n; i++) {
        if(used[i] == 0) {
            answer.push_back(i);
            break;
        }
    }
    return answer;
}