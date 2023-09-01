#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> tar;
int solution(vector<vector<int>> targets) {
    int answer = 1;
    for(int i = 0; i < targets.size(); i++) {
        tar.push_back({targets[i][0],targets[i][1]});
    } 
    sort(tar.begin(),tar.end());
    int st = tar[0].X;
    int en = tar[0].Y;
    for(int i = 1; i < tar.size(); i++) {
        //cout << st << " " << en << "\n";
        if(en > tar[i].X) {
            if(en > tar[i].Y) {
                en = tar[i].Y;
            }
        }
        else {
            answer++;
            st = tar[i].X;
            en = tar[i].Y;
        }
    }
    return answer;
}