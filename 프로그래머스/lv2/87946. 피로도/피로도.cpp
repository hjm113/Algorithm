#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int num[10];
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    for(int i = 0; i < n; i++) {
        num[i] = i;
    }
    do{
        int ti = k;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            //cout << num[i] << " ";
            int st = dungeons[num[i]][0];
            int used = dungeons[num[i]][1];
            if(ti >= st) {
                ti -= used;
                cnt++;
            }
        }
        //cout << "\n";
        if(answer < cnt) {
            answer = cnt;
        }
    }while(next_permutation(num,num+n));
    return answer;
}