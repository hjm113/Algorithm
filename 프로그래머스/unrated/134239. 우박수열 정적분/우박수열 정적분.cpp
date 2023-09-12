#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> ans;
vector<double> area;
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int cnt = 0;
    while(k >= 1) {
        cnt++;
        ans.push_back(k);
        if(k == 1) {
            break;
        }
        if(k % 2 == 0) {
            k /= 2;
        }
        else {
            k *= 3;
            k++;
        }
    }
    int fst = ans[0];
    double sum = 0;
    area.push_back(0);
    for(int i = 1; i < ans.size(); i++) {
        int mn = min(fst,ans[i]);
        double down = mn;
        double up = 0;
        if(fst > mn) {
            int re = fst-mn;
            up = (double)re/2;
        }
        else {
            int re = ans[i]-mn;
            up = (double)re/2;
        }
        up += mn;
        cout << up << "\n";
        sum += up;
        area.push_back(sum);
        fst = ans[i];
    }
    /*
    for(int i = 0 ; i < area.size(); i++) {
        cout << area[i] << " ";
    }
    */
    cnt--;
    for(int i = 0; i < ranges.size(); i++) {
        int st = ranges[i][0];
        int en = ranges[i][1];
        if(cnt+en < st) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(area[cnt+en]-area[st]);
        }
    }
    return answer;
}