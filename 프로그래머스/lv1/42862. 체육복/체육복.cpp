#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sto[35];
int check[35];
int given[35];
int cnt = 0;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i = 0; i < lost.size(); i++) {
        sto[lost[i]] = 1;
    }
    for(int i = 0; i < reserve.size(); i++) {
        if(sto[reserve[i]] == 1) {
            check[reserve[i]] = 1;
            cnt++;
        }
    }
    sort(reserve.begin(),reserve.end());
    for(int i = 0; i < reserve.size(); i++) {
        if(check[reserve[i]] == 1) {
            continue;
        }
        if(sto[reserve[i]-1] == 1 && check[reserve[i]-1] == 0) {
            sto[reserve[i]-1] = 0;
            cnt++;
            continue;
        }
        if(sto[reserve[i]+1] == 1 && check[reserve[i]+1] == 0) {
            sto[reserve[i]+1] = 0;
            cnt++;
        }
    }
    answer = n-lost.size()+cnt;
    return answer;
} 