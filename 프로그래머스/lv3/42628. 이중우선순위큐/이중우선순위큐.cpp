#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int arymx[1000005];
int arymn[1000005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pqmn;
priority_queue<pair<int,int>> pqmx;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i = 0; i < operations.size(); i++) {
        char c = operations[i][0];
        string tmp = "";
        for(int j = 2; j < operations[i].length(); j++) {
            tmp += operations[i][j];
        }
        int a = stoi(tmp);
        if(c == 'I') {
            pqmx.push({a,i});
            pqmn.push({a,i});
        }
        if(c == 'D' && a == 1) {
            while(!pqmx.empty()) {
                if(arymx[pqmx.top().Y] == 0) {
                    arymn[pqmx.top().Y] = 1;
                    pqmx.pop();
                    break;
                }
                pqmx.pop();
            }
        }
        if(c == 'D' && a == -1) {
            while(!pqmn.empty()) {
                if(arymn[pqmn.top().Y] == 0) {
                    arymx[pqmn.top().Y] = 1;
                    pqmn.pop();
                    break;
                }
                pqmn.pop();
            }
        }
    }
    int mx = 0;
    while(!pqmx.empty()) {
        if(arymx[pqmx.top().Y] == 0) {
            mx = pqmx.top().X;
            break;
        }
        pqmx.pop();
    }
    int mn = 0;
    while(!pqmn.empty()) {
        if(arymn[pqmn.top().Y] == 0) {
            mn = pqmn.top().X;
            break;
        }
        pqmn.pop();
    }
    cout << mx << " " << mn;
    answer.push_back(mx);
    answer.push_back(mn);
    return answer;
}