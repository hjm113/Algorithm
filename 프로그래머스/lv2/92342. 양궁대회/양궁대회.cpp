#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n = 0;
int sum = 0;
int ary[15];
int out = 11;
vector<int> ap;
int mx = 0;
int ans[15];
int emp;
void dfs(int k) {
    if(sum > n) {
        return;
    }
    if(k == out) {
        int suml = 0;
        int suma = 0;
        for(int i = 0; i < out; i++) {
            if(ary[i] == 0 && ap[i] == 0) {
                continue;
            }
            if(ary[i] > ap[i]) {
                suml += out-i-1;
            }
            else {
                suma += out-i-1;
            }
        }
        if(suml-suma == 0) {
            return;
        }
        if(mx < suml-suma) {
            mx = suml-suma;
            emp = 1;
            for(int i = 0; i < out; i++) {
                ans[i] = ary[i];
            }
        }
        else if(mx == suml-suma) {
            int chk = 0;
            for(int i = out-1; i >= 0; i--) {
                if(ans[i] < ary[i]) {
                    chk = 1;
                    break;
                }
                if(ans[i] > ary[i]) {
                    chk = 2;
                    break;
                }
            }
            if(chk == 1) {
                for(int i = 0; i < out; i++) {
                    ans[i] = ary[i];
                }
            }
        }
        return;
    }
    for(int i = 0; i <= n; i++) {
        sum += i;
        ary[k] = i;
        dfs(k+1);
        sum -= i;
    }
}
vector<int> solution(int m, vector<int> info) {
    vector<int> answer;
    n = m;
    for(int i = 0; i < info.size(); i++) {
        ap.push_back(info[i]);
    }
    dfs(0);
    for(int i = 0; i < 11; i++) {
        cout << ans[i] << " ";
    }
    if(emp == 0) {
        answer.push_back(-1);
    }
    else {
        for(int i = 0; i < 11; i++) {
            answer.push_back(ans[i]);
        }
    }
    return answer;
}