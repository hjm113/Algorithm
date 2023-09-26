#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 2000000000;
    int len = weak.size();
    for(int i = 0; i < len; i++) {
        weak.push_back(weak[i]+n);
    }
    sort(dist.begin(),dist.end());
    do {
        for(int i = 0; i <= weak.size()-len; i++) {
            int st = weak[i];
            int en = weak[len-1+i];
            for(int j = 0; j < dist.size(); j++) {
                st += dist[j];
                if(st >= en) {
                    answer = min(answer,j+1);
                    break;
                }
                for(int k = i+1; k <= len-1+i; k++) {
                    if(st < weak[k]) {
                        st = weak[k];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(),dist.end()));
    if(answer == 2000000000) {
        answer = -1;
    }
    return answer;
}