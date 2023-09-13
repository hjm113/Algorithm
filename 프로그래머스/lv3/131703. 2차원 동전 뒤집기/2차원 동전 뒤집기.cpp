#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int num[25];
int ary[15][15];
vector<int> change;
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = -1;
    int n = beginning.size();
    int m = beginning[0].size();
    int cnt = 0;
    while(cnt <= n+m) {
        num[n+m-cnt] = 1;
        int out = 0;
        do {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    ary[i][j] = beginning[i][j];
                }
            }
            for(int i = 0; i < n+m; i++) {
                if(num[i] == 1) {
                    change.push_back(i);
                }
            }
            int len = change.size();
            for(int i = 0; i < len; i++) {
                if(change[i] < n) {
                    for(int j = 0; j < m; j++) {
                        if(ary[change[i]][j] == 1) {
                            ary[change[i]][j] = 0;
                        }
                        else {
                            ary[change[i]][j] = 1;
                        }
                    }
                }
                else {
                    int col = change[i]%m;
                    for(int j = 0; j < n; j++) {
                        if(ary[j][col] == 1) {
                            ary[j][col] = 0;
                        }
                        else {
                            ary[j][col] = 1;
                        }
                    }
                }
            }
            change.clear();
            int chk = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(ary[i][j] != target[i][j]) {
                        chk = 1;
                        break;
                    }
                }
            }
            if(chk == 0) {
                out = 1;
                break;
            }
        }while(next_permutation(num,num+n+m));
        if(out == 1) {
            answer = cnt;
            break;
        }
        cnt++;
    }
    return answer;
}