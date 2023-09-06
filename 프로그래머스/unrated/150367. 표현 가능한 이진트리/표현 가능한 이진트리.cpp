#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long ll;
queue<pair<int,int>> q;
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++) {
        ll num = numbers[i];
        string tmp = "";
        while(num > 0) {
            tmp += to_string(num%2);
            num /= 2;
        }
        reverse(tmp.begin(),tmp.end());
        int n = tmp.size();
        int st = 2;
        while(n > st-1) {
            st *= 2;
        }
        for(int i = 0; i < st-n-1; i++) {
            tmp = "0" + tmp;
        }
        int len = tmp.length()+1;
        q.push({len/2-1,len/4});
        int chk = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(tmp[cur.X] == '0') {
                if(tmp[cur.X-cur.Y] == '1' || tmp[cur.X+cur.Y] == '1') {
                    chk = 1;
                }
            }
            if(cur.Y > 1) {
                q.push({cur.X-cur.Y,cur.Y/2});
                q.push({cur.X+cur.Y,cur.Y/2});
            }
        }
        if(chk == 0) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}