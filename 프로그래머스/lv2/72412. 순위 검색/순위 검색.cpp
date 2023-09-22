#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> ans[5][5][5][5];
map<string, int> mp;
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    mp["cpp"] = 1;
    mp["java"] = 2;
    mp["python"] = 3;
    mp["backend"] = 1;
    mp["frontend"] = 2;
    mp["junior"] = 1;
    mp["senior"] = 2;
    mp["chicken"] = 1;
    mp["pizza"] = 2;
    for(int i = 0; i < info.size(); i++) {
        string tmp = "";
        int sc = 0;
        vector<int> con;
        for(int j = 0; j < info[i].length(); j++) {
            if(info[i][j] == ' ') {
                con.push_back(mp[tmp]);
                tmp = "";
                continue;
            }
            tmp += info[i][j];
            if(j == info[i].length()-1) {
                sc = stoi(tmp);
            }
        }
        ans[0][0][0][0].push_back(sc);
        /*
        for(int i = 0; i < con.size(); i++) {
            cout << con[i] << " ";
        }
        cout << sc;
        cout << "\n";
        */
        int num[4] = {};
        for(int j = 0; j < 4; j++) {
            num[4-j-1] = 1;
            do {
                int order[4] = {};
                for(int i = 0; i < 4; i++) {
                    if(num[i] == 1) {
                        order[i] = con[i];
                    }
                }
                ans[order[0]][order[1]][order[2]][order[3]].push_back(sc);
            }while(next_permutation(num,num+4));
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                for(int w = 0; w < 5; w++) {
                    sort(ans[i][j][k][w].begin(),ans[i][j][k][w].end());
                }
            }
        }
    }
    for(int i = 0; i < query.size(); i++) {
        string tmp = "";
        vector<int> order;
        int cnt = 0;
        int sc = 0;
        for(int j = 0; j < query[i].length(); j++) {
            if(query[i][j] == ' ') {
                if(tmp == "and") {
                    tmp = "";
                    continue;
                }
                if(tmp == "-") {
                    order.push_back(0);
                }
                else {
                    order.push_back(mp[tmp]);
                }
                tmp = "";
                continue;
            }
            tmp += query[i][j];
            if(j == query[i].length()-1) {
                sc = stoi(tmp);
            }
        }
        int a = lower_bound(ans[order[0]][order[1]][order[2]][order[3]].begin(),ans[order[0]][order[1]][order[2]][order[3]].end(), sc) - ans[order[0]][order[1]][order[2]][order[3]].begin();
        answer.push_back(ans[order[0]][order[1]][order[2]][order[3]].size()-a);
        //cout << "\n";
        /*
        for(int j = 0; j < order.size(); j++) {
            cout << order[j] << " ";
        }
        cout << "\n";
        */
    }
    return answer;
}