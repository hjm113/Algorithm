#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int t[100005];
deque<pair<int,int>> lst;
deque<pair<int,int>> fst;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.Y < b.Y;
}

int solution(vector<string> lines) {
    int answer = 0;
    for(int i = 0; i < lines.size(); i++) {
        int h = stoi(lines[i].substr(11,2))*3600*1000;
        int m = stoi(lines[i].substr(14,2))*60*1000;
        double s = stod(lines[i].substr(17,6));
        int ss = s*1000;
        double tmp = stod(lines[i].substr(24,5));
        int elas = tmp*1000;
        //cout << h+m+ss << " " << elas << "\n";
        int en = h+m+ss+3000;
        int st = en-elas+1;
        lst.push_back({st,en});
        fst.push_back({st,en});
    }
    sort(lst.begin(),lst.end(),cmp);
    sort(fst.begin(),fst.end());
    int n = lst.size();
    int sum = 0;
    int j = 0;
    int k = 0;
    /*
    for(int i = 0; i < n; i++) {
        cout << fst[i].X << " " << fst[i].Y << "\n";
    }
    */
    for(int i = fst[0].X; i <= fst[n-1].Y; i++) {
        while(1) {
            if(j == n) {
                break;
            }
            auto cur = fst[j];
            if((i >= cur.Y) || (i+999 >= cur.X)) {
                sum++;
            }
            else {
                break;
            }
            j++;
        }
        
        while(1) {
            if(k == n) {
                break;
            }
            auto cur = lst[k];
            if(i > cur.Y) {
                sum--;
            }
            else {
                break;
            }
            k++;
        }
        if(answer < sum) {
            answer = sum;
            //cout << sum << " " << i << "\n";
        }
    }
    return answer;
}