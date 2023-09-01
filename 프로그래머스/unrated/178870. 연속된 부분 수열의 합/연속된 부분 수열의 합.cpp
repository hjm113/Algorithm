#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mx = 1000005;
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    int en = -1;
    int x = 0;
    int y = 0;
    int tot = 0;
    for(int st = 0; st < n; st++) {
        if(st > 0) {
            tot -= sequence[st-1];
        }
        while(en < n && tot < k) {
            en++;
            tot += sequence[en];
        }
        //cout << tot << "\n";
        if(en == n) {
            break;
        }
        if(tot == k) {
            if(mx > en-st) {
                mx = en-st;
                x = st;
                y = en;
            }
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}